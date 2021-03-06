/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF THE BSD NEW LICENSE OR THE
 * GPL VERSION 3 LICENSE OR THE OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3,
 * ACCORDING TO RECIPIENTS CHOICE.
 * 
 * The OpenModelica software and the OSMC (Open Source Modelica Consortium)
 * Public License (OSMC-PL) are obtained from OSMC, either from the above
 * address, from the URLs: http://www.openmodelica.org or
 * http://www.ida.liu.se/projects/OpenModelica, and in the OpenModelica
 * distribution. GNU version 3 is obtained from:
 * http://www.gnu.org/copyleft/gpl.html. The New BSD License is obtained from:
 * http://www.opensource.org/licenses/BSD-3-Clause.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, EXCEPT AS
 * EXPRESSLY SET FORTH IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE
 * CONDITIONS OF OSMC-PL.
 *
 */

#include "openmodelica.h"
#include "meta_modelica.h"
#include "meta_modelica_builtin.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pthread_key_t mmc_jumper;

/*
void* mmc_mk_rcon(double d)
{
    void *p = mmc_alloc_words(MMC_SIZE_DBL/MMC_SIZE_INT+1);
    ((mmc_uint_t*)p)[0] = MMC_REALHDR;
    *((double*)((mmc_uint_t*)p+1)) = d;
    p = MMC_TAGPTR(p);
#ifdef MMC_MK_DEBUG
    fprintf(stderr, "REAL size: %u\n", MMC_SIZE_DBL/MMC_SIZE_INT+1); fflush(NULL);
#endif
    return p;
}
*/
void* mmc_mk_rcon(double d)
{
    struct mmc_real *p = (struct mmc_real*)mmc_alloc_words(MMC_SIZE_DBL/MMC_SIZE_INT + 1);
    mmc_prim_set_real(p, d);
    p->header = MMC_REALHDR;
#ifdef MMC_MK_DEBUG
    fprintf(stderr, "REAL size: %u\n", MMC_SIZE_DBL/MMC_SIZE_INT+1); fflush(NULL);
#endif
    return MMC_TAGPTR(p);
}

void *mmc_mk_box_arr(int slots, unsigned ctor, void** args)
{
    int i;
    struct mmc_struct *p = (struct mmc_struct*)mmc_alloc_words(slots + 1);
    p->header = MMC_STRUCTHDR(slots, ctor);
    for (i=0; i<slots; i++) {
      p->data[i] = (void*) args[i];
    }
#ifdef MMC_MK_DEBUG
    fprintf(stderr, "STRUCT slots%d ctor %u\n", slots, ctor); fflush(NULL);
#endif
    return MMC_TAGPTR(p);
}

void *mmc_mk_box_no_assign(int slots, unsigned ctor)
{
    struct mmc_struct *p = (struct mmc_struct*)mmc_alloc_words(slots+1);
    p->header = MMC_STRUCTHDR(slots, ctor);
#ifdef MMC_MK_DEBUG
    fprintf(stderr, "STRUCT NO ASSIGN slots%d ctor %u\n", slots, ctor); fflush(NULL);
#endif
    return MMC_TAGPTR(p);
}

char* mmc_mk_scon_len_ret_ptr(size_t nbytes)
{
    unsigned header = MMC_STRINGHDR(nbytes);
    unsigned nwords = MMC_HDRSLOTS(header) + 1;
    struct mmc_string *p;
    void *res;
    p = (struct mmc_string *) mmc_alloc_words(nwords);
    p->header = header;
    res = MMC_TAGPTR(p);
    return MMC_STRINGDATA(res);
}

modelica_boolean valueEq(modelica_metatype lhs, modelica_metatype rhs)
{
  mmc_uint_t h_lhs;
  mmc_uint_t h_rhs;
  int numslots;
  unsigned ctor;
  int i;
  void *lhs_data, *rhs_data;
  struct record_description *lhs_desc,*rhs_desc;

  if (lhs == rhs) {
    return 1;
  }

  if ((0 == ((mmc_sint_t)lhs & 1)) && (0 == ((mmc_sint_t)rhs & 1))) {
    return lhs == rhs;
  }

  h_lhs = MMC_GETHDR(lhs);
  h_rhs = MMC_GETHDR(rhs);

  if (h_lhs != h_rhs)
    return 0;

  if (h_lhs == MMC_NILHDR) {
    return 1;
  }

  if (h_lhs == MMC_REALHDR) {
    double d1,d2;
    d1 = mmc_prim_get_real(lhs);
    d2 = mmc_prim_get_real(rhs);
    return d1 == d2;
  }
  if (MMC_HDRISSTRING(h_lhs)) {
    return 0 == strcmp(MMC_STRINGDATA(lhs),MMC_STRINGDATA(rhs));
  }

  numslots = MMC_HDRSLOTS(h_lhs);
  ctor = 255 & (h_lhs >> 2);

  if (numslots>0 && ctor > 1) { /* RECORD */
    lhs_desc = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(lhs),1));
    rhs_desc = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(rhs),1));
    /* Slow; not needed
    if (0 != strcmp(lhs_desc->name,rhs_desc->name))
      return 0;
    */
    for (i=2; i<=numslots; i++) {
      lhs_data = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(lhs),i));
      rhs_data = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(rhs),i));
      if (0 == valueEq(lhs_data,rhs_data))
        return 0;
    }
    return 1;
  }

  if (numslots>0 && ctor == 0) { /* TUPLE */
    for (i=0; i<numslots; i++) {
      void *tlhs, *trhs;
      tlhs = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(lhs),i+1));
      trhs = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(rhs),i+1));
      if (0 == valueEq(tlhs,trhs)) {
        return 0;
      }
    }
    return 1;
  }

  if (numslots==0 && ctor==1) /* NONE() */ {
    return 1;
  }

  if (numslots==1 && ctor==1) /* SOME(x) */ {
    return valueEq(MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(lhs),1)),MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(rhs),1)));
  }

  if (numslots==2 && ctor==1) { /* CONS-PAIR */
    while (!MMC_NILTEST(lhs) && !MMC_NILTEST(rhs)) {
      if (!valueEq(MMC_CAR(lhs),MMC_CAR(rhs)))
        return 0;
      lhs = MMC_CDR(lhs);
      rhs = MMC_CDR(rhs);
    }
    return MMC_NILTEST(lhs) == MMC_NILTEST(rhs);
  }

  if (numslots==0 && ctor == MMC_ARRAY_TAG) /* zero size array??!! */ {
    return 1;
  }


  fprintf(stderr, "%s:%d: %d slots; ctor %d - FAILED to detect the type\n", __FILE__, __LINE__, numslots, ctor);
  EXIT(1);
}

void debug__print(void* prefix, void* any)
{
  fprintf(stderr, "%s%s", MMC_STRINGDATA(prefix), anyString(any));
}

static char *anyStringBuf = 0;
int anyStringBufSize = 0;

inline static void checkAnyStringBufSize(int ix, int szNewObject)
{
  if (anyStringBufSize-ix < szNewObject+1) {
    anyStringBuf = realloc(anyStringBuf, anyStringBufSize*2 + szNewObject);
    assert(anyStringBuf != NULL);
    anyStringBufSize = anyStringBufSize*2 + szNewObject;
  }
}

void initializeStringBuffer(void)
{
  if (anyStringBufSize == 0) {
    anyStringBuf = malloc(8192);
    anyStringBufSize = 8192;
  }
  *anyStringBuf = '\0';
}

inline static int anyStringWork(void* any, int ix)
{
  mmc_uint_t hdr;
  int numslots;
  unsigned ctor;
  int i;
  void *data;
  struct record_description *desc;
  /* char buf[34] = {0}; */

  if (MMC_IS_IMMEDIATE(any)) {
    checkAnyStringBufSize(ix,40);
    ix += sprintf(anyStringBuf+ix, "%ld", (signed long) MMC_UNTAGFIXNUM(any));
    return ix;
  }

  if (MMC_HDR_IS_FORWARD(MMC_GETHDR(any))) {
    checkAnyStringBufSize(ix,40);
    ix += sprintf(anyStringBuf+ix, "Forward");
    return ix;
  }

  hdr = MMC_HDR_UNMARK(MMC_GETHDR(any));

  if (hdr == MMC_NILHDR) {
    checkAnyStringBufSize(ix,2);
    ix += sprintf(anyStringBuf+ix, "{NIL}");
    return ix;
  }

  if (hdr == MMC_REALHDR) {
    checkAnyStringBufSize(ix,40);
    ix += sprintf(anyStringBuf+ix, "%.7g", (double) mmc_prim_get_real(any));
    return ix;
  }
  if (MMC_HDRISSTRING(hdr)) {
    MMC_CHECK_STRING(any);
    checkAnyStringBufSize(ix,strlen(MMC_STRINGDATA(any))+4);
    ix += sprintf(anyStringBuf+ix, "%s", MMC_STRINGDATA(any));
    return ix;
  }

  numslots = MMC_HDRSLOTS(hdr);
  ctor = MMC_HDRCTOR(hdr);

  /* Ugly hack to "detect" function pointers. If these parameters are outside
   * these bounds, then we probably have a function pointer. This is just to
   * keep the debugger from crashing. */
  if (numslots < 0 || numslots > 1024 || ctor > 255) {
    checkAnyStringBufSize(ix, 2);
    ix += sprintf(anyStringBuf+ix, "0");
    return ix;
  }

  if (numslots>0 && ctor == MMC_FREE_OBJECT_CTOR) { /* FREE OBJECT! */
    checkAnyStringBufSize(ix,100);
    ix += sprintf(anyStringBuf+ix, "FREE(%u)", numslots);
    return ix;
  }
  if (numslots>=0 && ctor == MMC_ARRAY_TAG) { /* MetaModelica-style array */
    checkAnyStringBufSize(ix,40);
    ix += sprintf(anyStringBuf+ix, "MetaArray(");
    for (i=1; i<=numslots; i++) {
      data = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),i));
      ix = anyStringWork(data, ix);
      if (i!=numslots) {
        checkAnyStringBufSize(ix,3);
        ix += sprintf(anyStringBuf+ix, ", ");
      }
    }
    checkAnyStringBufSize(ix,2);
    ix += sprintf(anyStringBuf+ix, ")");
    return ix;
  }
  if (numslots>0 && ctor > 1) { /* RECORD */
    desc = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),1));
    checkAnyStringBufSize(ix,strlen(desc->name)+2);
    ix += sprintf(anyStringBuf+ix, "%s(", desc->name);
    for (i=2; i<=numslots; i++) {
      data = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),i));
      checkAnyStringBufSize(ix,strlen(desc->fieldNames[i-2])+3);
      ix += sprintf(anyStringBuf+ix, "%s = ", desc->fieldNames[i-2]);
      ix = anyStringWork(data,ix);
      if (i!=numslots) {
        checkAnyStringBufSize(ix,3);
        ix += sprintf(anyStringBuf+ix, ", ");
      }
    }
    checkAnyStringBufSize(ix,2);
    ix += sprintf(anyStringBuf+ix, ")");
    return ix;
  }

  if (numslots>0 && ctor == 0) { /* TUPLE */
    checkAnyStringBufSize(ix,2);
    ix += sprintf(anyStringBuf+ix, "(");
    for (i=0; i<numslots; i++) {
      ix = anyStringWork(MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),i+1)),ix);
      if (i!=numslots-1) {
        checkAnyStringBufSize(ix,3);
        ix += sprintf(anyStringBuf+ix, ", ");
      }
    }
    checkAnyStringBufSize(ix,2);
    ix += sprintf(anyStringBuf+ix, ")");
    return ix;
  }

  if (numslots==0 && ctor==1) /* NONE() */ {
    checkAnyStringBufSize(ix,7);
    ix += sprintf(anyStringBuf+ix, "NONE()");
    return ix;
  }

  if (numslots==1 && ctor==1) /* SOME(x) */ {
    checkAnyStringBufSize(ix,6);
    ix += sprintf(anyStringBuf+ix, "SOME(");
    ix = anyStringWork(MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),1)),ix);
    checkAnyStringBufSize(ix,2);
    ix += sprintf(anyStringBuf+ix, ")");
    return ix;
  }

  if (numslots==2 && ctor==1) { /* CONS-PAIR */
    checkAnyStringBufSize(ix,2);
    ix += sprintf(anyStringBuf+ix, "{");
    ix = anyStringWork(MMC_CAR(any),ix);
    any = MMC_CDR(any);
    while (!MMC_NILTEST(any)) {
      checkAnyStringBufSize(ix,3);
      ix += sprintf(anyStringBuf+ix, ", ");
      ix = anyStringWork(MMC_CAR(any),ix);
      any = MMC_CDR(any);
    }
    checkAnyStringBufSize(ix,2);
    ix += sprintf(anyStringBuf+ix, "}");
    return ix;
  }

  fprintf(stderr, "%s:%d: %d slots; ctor %d - FAILED to detect the type\n", __FILE__, __LINE__, numslots, ctor);
  /* fprintf(stderr, "object: %032s||", ltoa((int)hdr, buf, 2)); */
  checkAnyStringBufSize(ix,5);
  ix += sprintf(anyStringBuf+ix, "UNK(");
  for (i=1; i<=numslots; i++)
  {
    ix = anyStringWork(MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),i)),ix);
    data = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),i));
    /* fprintf(stderr, "%032s|", ltoa((int)data, buf, 2)); */
  }
  checkAnyStringBufSize(ix,2);
  ix += sprintf(anyStringBuf+ix, ")");
  fprintf(stderr, "\n"); fflush(NULL);
  /* EXIT(1); */
  return ix;
}

char* anyString(void* any)
{
  initializeStringBuffer();
  anyStringWork(any,0);
  return anyStringBuf;
}

void* mmc_anyString(void* any)
{
  initializeStringBuffer();
  anyStringWork(any,0);
  return mmc_mk_scon(anyStringBuf);
}

void printAny(void* any)
{
  initializeStringBuffer();
  anyStringWork(any,0);
  fputs(anyStringBuf, stderr);
}

static int globalId;

inline static int anyStringWorkCode(void* any, int ix, int id)
{
  mmc_uint_t hdr;
  int numslots;
  unsigned ctor;
  int i;
  void *data;
  struct record_description *desc;
  int base_id;
  /* char buf[34] = {0}; */

  if (MMC_IS_IMMEDIATE(any)) {
    checkAnyStringBufSize(ix,400);
    ix += sprintf(anyStringBuf+ix, "#define omc_tmp%d ((void*)%ld)\n", id, (signed long) any);
    return ix;
  }

  if (MMC_HDR_IS_FORWARD(MMC_GETHDR(any))) {
    assert(0);
  }

  hdr = MMC_HDR_UNMARK(MMC_GETHDR(any));

  if (hdr == MMC_NILHDR) {
    checkAnyStringBufSize(ix,400);
    ix += sprintf(anyStringBuf+ix, "#define omc_tmp%d (MMC_REFSTRUCTLIT(mmc_nil))\n", id);
    return ix;
  }

  if (hdr == MMC_REALHDR) {
    checkAnyStringBufSize(ix,500);
    ix += sprintf(anyStringBuf+ix, "static const MMC_DEFREALLIT(omc_tmp%d_data,%g);\n#define omc_tmp%d MMC_REFREALLIT(omc_tmp%d_data)\n", id, (double) mmc_prim_get_real(any), id, id);
    return ix;
  }
  if (MMC_HDRISSTRING(hdr)) {
    int unescapedLength;
    char *str;
    MMC_CHECK_STRING(any);
    unescapedLength = strlen(MMC_STRINGDATA(any));
    str = omc__escapedString(MMC_STRINGDATA(any), 1);
    checkAnyStringBufSize(ix,unescapedLength+800);
    ix += sprintf(anyStringBuf+ix, "#define omc_tmp%d_data \"%s\"\n", id, str ? str : MMC_STRINGDATA(any));
    ix += sprintf(anyStringBuf+ix, "static const size_t omc_tmp%d_strlen = %d;\n", id, unescapedLength);
    ix += sprintf(anyStringBuf+ix, "static const MMC_DEFSTRINGLIT(omc_tmp%d_data2,%d,omc_tmp%d_data);\n", id, unescapedLength, id);
    ix += sprintf(anyStringBuf+ix, "#define omc_tmp%d MMC_REFSTRINGLIT(omc_tmp%d_data2)\n", id, id);
    if (str) free(str);
    return ix;
  }

  numslots = MMC_HDRSLOTS(hdr);
  ctor = MMC_HDRCTOR(hdr);

  /* Ugly hack to "detect" function pointers. If these parameters are outside
   * these bounds, then we probably have a function pointer. This is just to
   * keep the debugger from crashing. */
  if (numslots < 0 || numslots > 1024 || ctor > 255) {
    checkAnyStringBufSize(ix, 100);
    assert(0);
    return ix;
  }

  if (numslots>0 && ctor == MMC_FREE_OBJECT_CTOR) { /* FREE OBJECT! */
    assert(0);
    return ix;
  }
  if (numslots>=0 && ctor == MMC_ARRAY_TAG) { /* MetaModelica-style array */
    assert(0);
    return ix;
  }
  if (numslots>0 && ctor > 1) { /* RECORD */
    int base_id = globalId;
    globalId += numslots-1;
    desc = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),1));
    for (i=2; i<=numslots; i++) {
      data = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),i));
      ix = anyStringWorkCode(data,ix,base_id+i-1);
    }
    checkAnyStringBufSize(ix,numslots*100+400);
    ix += sprintf(anyStringBuf+ix, "static const MMC_DEFSTRUCTLIT(omc_tmp%d_data,%d,%d) {&%s__desc", id, numslots, ctor, desc->path);
    for (i=2; i<=numslots; i++) {
      ix += sprintf(anyStringBuf+ix, ",omc_tmp%d", base_id+i-1);
    }
    ix += sprintf(anyStringBuf+ix, "}};\n");
    ix += sprintf(anyStringBuf+ix, "#define omc_tmp%d MMC_REFSTRUCTLIT(omc_tmp%d_data)\n", id, id);
    return ix;
  }

  base_id = globalId;
  globalId += numslots;
  for (i=1; i<=numslots; i++) {
    data = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),i));
    ix = anyStringWorkCode(data,ix,base_id+i);
  }
  checkAnyStringBufSize(ix,numslots*100+400);
  ix += sprintf(anyStringBuf+ix, "static const MMC_DEFSTRUCTLIT(omc_tmp%d_data,%d,%d) {", id, numslots, ctor);
  for (i=1; i<=numslots; i++) {
    ix += sprintf(anyStringBuf+ix, "%somc_tmp%d", i==1 ? "" : ",", base_id+i);
  }
  ix += sprintf(anyStringBuf+ix, "}};\n");
  ix += sprintf(anyStringBuf+ix, "#define omc_tmp%d MMC_REFSTRUCTLIT(omc_tmp%d_data)\n", id, id);
  return ix;
}

void* mmc_anyStringCode(void* any)
{
  initializeStringBuffer();
  globalId = 0;
  anyStringWorkCode(any,0,globalId++);
  return mmc_mk_scon(anyStringBuf);
}

const char* anyStringCode(void* any)
{
  initializeStringBuffer();
  globalId = 0;
  anyStringWorkCode(any,0,globalId++);
  fprintf(stderr, "%s", anyStringBuf);
  return anyStringBuf;
}

void printTypeOfAny(void* any) /* for debugging */
{
  mmc_uint_t hdr;
  int numslots;
  unsigned ctor;
  int i;
  void *data;
  struct record_description *desc;

  if ((0 == ((mmc_sint_t)any & 1))) {
    fprintf(stderr, "Integer");
    return;
  }

  hdr = MMC_GETHDR(any);

  if (MMC_HDR_IS_FORWARD(hdr)) {
    fprintf(stderr, "Forward");
    return;
  }

  if (hdr == MMC_NILHDR) {
    fprintf(stderr, "list<Any>");
    return;
  }

  if (hdr == MMC_REALHDR) {
    fprintf(stderr, "Real");
    return;
  }

  if (MMC_HDRISSTRING(hdr)) {
    fprintf(stderr, "String");
    return;
  }

  numslots = MMC_HDRSLOTS(hdr);
  ctor = 255 & (hdr >> 2);

  if (numslots>0 && ctor == MMC_ARRAY_TAG) { /* MetaModelica-style array */
    fprintf(stderr, "meta_array<");
    data = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),1));
    printTypeOfAny(data);
    fprintf(stderr, ">");
    return;
  }
  /* empty array??!! */
  if (numslots == 0 && ctor == MMC_ARRAY_TAG) { /* MetaModelica-style array */
    fprintf(stderr, "meta_array<>");
    return;
  }

  if (numslots>0 && ctor > 1) { /* RECORD */
    desc = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),1));
    fprintf(stderr, "%s(", desc->name);
    for (i=2; i<=numslots; i++) {
      data = MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),i));
      fprintf(stderr, "%s = ", desc->fieldNames[i-2]);
      printTypeOfAny(data);
      if (i!=numslots)
        fprintf(stderr, ", ");
    }
    fprintf(stderr, ")");
    return;
  }

  if (numslots>0 && ctor == 0) { /* TUPLE */
    fprintf(stderr, "tuple<");
    printTypeOfAny(MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),1)));
    fprintf(stderr, ">");
    return;
  }

  if (numslots==0 && ctor==1) /* NONE() */ {
    fprintf(stderr, "Option<Any>");
    return;
  }

  if (numslots==1 && ctor==1) /* SOME(x) */ {
    fprintf(stderr, "Option<");
    printTypeOfAny(MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),1)));
    fprintf(stderr, ">");
    return;
  }

  if (numslots==2 && ctor==1) { /* CONS-PAIR */
    fprintf(stderr, "list<");
    printTypeOfAny(MMC_CAR(any));
    fprintf(stderr, ">");
    return;
  }

  fprintf(stderr, "%s:%d: %d slots; ctor %d - FAILED to detect the type\n", __FILE__, __LINE__, numslots, ctor);
  EXIT(1);
}

inline static int getTypeOfAnyWork(void* any, int ix)  /* for debugging */
{
  mmc_uint_t hdr;
  int numslots;
  unsigned ctor;
  int i;
  struct record_description *desc;

  if (any == NULL) {
    checkAnyStringBufSize(ix,21);
    ix += sprintf(anyStringBuf+ix, "%s", "replaceable type Any");
    return ix;
  }

  if ((0 == ((mmc_sint_t)any & 1))) {
    checkAnyStringBufSize(ix,8);
    ix += sprintf(anyStringBuf+ix, "%s", "Integer");
    return ix;
  }

  hdr = MMC_GETHDR(any);

  if (hdr == MMC_NILHDR) {
    checkAnyStringBufSize(ix,10);
    ix += sprintf(anyStringBuf+ix, "%s", "list<Any>");
    return ix;
  }

  if (hdr == MMC_REALHDR) {
    checkAnyStringBufSize(ix,5);
    ix += sprintf(anyStringBuf+ix, "%s", "Real");
    return ix;
  }

  if (MMC_HDRISSTRING(hdr)) {
    checkAnyStringBufSize(ix,7);
    ix += sprintf(anyStringBuf+ix, "%s", "String");
    return ix;
  }

  numslots = MMC_HDRSLOTS(hdr);
  ctor = 255 & (hdr >> 2);

  /* Ugly hack to "detect" function pointers. If these parameters are outside
   * these bounds, then we probably have a function pointer. This is just to
   * keep the debugger from crashing. */
  if (numslots < 0 || numslots > 1024 || ctor > 255) {
    checkAnyStringBufSize(ix, 8);
    ix += sprintf(anyStringBuf+ix, "%s", "Integer");
    return ix;
  }

  if (numslots>0 && ctor == MMC_ARRAY_TAG) {
    checkAnyStringBufSize(ix,7);
    ix += sprintf(anyStringBuf+ix, "Array<");
    ix = getTypeOfAnyWork(MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),1)), ix);
    checkAnyStringBufSize(ix,2);
    ix += sprintf(anyStringBuf+ix, ">");
    return ix;
  }

  if (numslots>0 && ctor > 1) { /* RECORD */
    desc = MMC_CAR(any);
    checkAnyStringBufSize(ix,strlen(desc->name)+8);
    ix += sprintf(anyStringBuf+ix, "record<%s>", desc->name);
    return ix;
  }

  if (numslots>0 && ctor == 0) { /* TUPLE */
    checkAnyStringBufSize(ix,7);
    ix += sprintf(anyStringBuf+ix, "tuple<");
    for (i=0; i<numslots; i++) {
      ix = getTypeOfAnyWork(MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),i+1)), ix);
      if (i!=numslots-1) {
        checkAnyStringBufSize(ix,3);
        ix += sprintf(anyStringBuf+ix, ", ");
      }
    }
    checkAnyStringBufSize(ix,2);
    ix += sprintf(anyStringBuf+ix, ">");
    return ix;
  }

  if (numslots==0 && ctor==1) /* NONE() */ {
    checkAnyStringBufSize(ix,12);
    ix += sprintf(anyStringBuf+ix, "Option<Any>");
    return ix;
  }

  if (numslots==1 && ctor==1) /* SOME(x) */ {
    checkAnyStringBufSize(ix,8);
    ix += sprintf(anyStringBuf+ix, "Option<");
    for (i=0; i<numslots; i++) {
      ix = getTypeOfAnyWork(MMC_FETCH(MMC_OFFSET(MMC_UNTAGPTR(any),i+1)), ix);
      if (i!=numslots-1) {
        checkAnyStringBufSize(ix,3);
        ix += sprintf(anyStringBuf+ix, ", ");
      }
    }
    checkAnyStringBufSize(ix,2);
    ix += sprintf(anyStringBuf+ix, ">");
    return ix;
  }

  if (numslots==2 && ctor==1) { /* CONS-PAIR */
    checkAnyStringBufSize(ix,6);
    ix += sprintf(anyStringBuf+ix, "list<");
    ix = getTypeOfAnyWork(MMC_CAR(any), ix);
    checkAnyStringBufSize(ix,2);
    ix += sprintf(anyStringBuf+ix, ">");
    return ix;
  }

  ix = sprintf(anyStringBuf+ix, "%s:%d: %d slots; ctor %d - FAILED to detect the type\n", __FILE__, __LINE__, numslots, ctor);
  return ix;
}

char* getTypeOfAny(void* any) /* for debugging */
{
  initializeStringBuffer();
  getTypeOfAnyWork(any,0);
  return anyStringBuf;
}

/*
 * Used by MDT for debugging.
 * Returns the name of the particular field of the Record.
 * */
char* getRecordElementName(void* any, int element) {
  struct record_description *desc;

  initializeStringBuffer();

  desc = MMC_CAR(any);
  checkAnyStringBufSize(0,strlen(desc->fieldNames[element]));
  sprintf(anyStringBuf, "%s", desc->fieldNames[element]);
  return anyStringBuf;
}

/*
 * Used by MDT for debugging just return whether Option type contain something or not.
 * */
int isOptionNone(void* any)
{
  return MMC_OPTIONNONE(any);
}

/*
 * The gdb often use the buffer based stdout.
 * So printf does not print straight away on the console.
 * changing it to NULL fix the problem.
 * */
void changeStdStreamBuffer(void) {
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);
}

unsigned long mmc_prim_hash(void *p)
{
  unsigned long hash = 0;
  void **pp = NULL;
  mmc_uint_t phdr = 0;
  mmc_uint_t slots = 0;

  mmc_prim_hash_tail_recur:
  if ((0 == ((mmc_sint_t)p & 1)))
  {
    return hash + (unsigned long)MMC_UNTAGFIXNUM(p);
  }

  phdr = MMC_GETHDR(p);
  hash += (unsigned long)phdr;

  if( phdr == MMC_REALHDR )
  {
    return hash + (unsigned long)mmc_unbox_real(p);
  }

  if( MMC_HDRISSTRING(phdr) )
  {
    return hash + (unsigned long)stringHashDjb2(p);
  }

  if( MMC_HDRISSTRUCT(phdr) )
  {
    slots = MMC_HDRSLOTS(phdr);
    pp = MMC_STRUCTDATA(p);
    hash += MMC_HDRCTOR(phdr);
    if (slots == 0)
      return hash;

    while ( --slots > 0)
    {
       hash += mmc_prim_hash(*pp++);
    }
    p = *pp;
    goto mmc_prim_hash_tail_recur;
  }
  return hash;
}

modelica_integer valueHashMod(void *p, modelica_integer mod)
{
  modelica_integer res = mmc_prim_hash(p) % (unsigned long) mod;
  return res;
}

void* boxptr_valueHashMod(void *p, void *mod)
{
  return mmc_mk_icon(mmc_prim_hash(p) % (unsigned long) mmc_unbox_integer(mod));
}

pthread_once_t mmc_init_once = PTHREAD_ONCE_INIT;
void mmc_init()
{
  pthread_key_create(&mmc_jumper,NULL);
  init_metamodelica_segv_handler();
  mmc_GC_init(mmc_GC_settings_default);
  MMC_INIT_STACK_OVERFLOW();
}
