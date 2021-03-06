/* daux.f -- translated by f2c (version 20061008).
   You must link the resulting object file with libf2c:
  on Microsoft Windows system, link with libf2c.lib;
  on Linux or Unix systems, link with .../path/to/libf2c.a -lm
  or, if you install libf2c.a in a standard place, with -lf2c -lm
  -- in that order, at the end of the command line, as in
    cc *.o -lf2c -lm
  Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

    http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

doublereal d1mach_(integer *idum)
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    static doublereal u, comp;

/* ----------------------------------------------------------------------- */
/* THIS ROUTINE COMPUTES THE UNIT ROUNDOFF OF THE MACHINE IN DOUBLE */
/* PRECISION.  THIS IS DEFINED AS THE SMALLEST POSITIVE MACHINE NUMBER */
/* U SUCH THAT  1.0D0 + U .NE. 1.0D0 (IN DOUBLE PRECISION). */
/* ----------------------------------------------------------------------- */
    u = 1.;
L10:
    u *= .5;
    comp = u + 1.;
    if(comp != 1.) {
  goto L10;
    }
    ret_val = u * 2.;
    return ret_val;
/* ----------------------- END OF FUNCTION D1MACH ------------------------ */
} /* d1mach_ */

/* Subroutine */ int xerrwv_(char *msg, integer *nmes, integer *nerr, integer
  *level, integer *ni, integer *i1, integer *i2, integer *nr,
  doublereal *r1, doublereal *r2, ftnlen msg_len)
{
    /* Format strings */
    static char fmt_10[] = "(1x,80a1)";
    static char fmt_20[] = "(6x,\002In above message,  I1 =\002,i10)";
    static char fmt_30[] = "(6x,\002In above message,  I1 =\002,i10,3x,\002I"
      "2 =\002,i10)";
    static char fmt_40[] = "(6x,\002In above message,  R1 =\002,e21.13)";
    static char fmt_50[] = "(6x,\002In above,  R1 =\002,e21.13,3x,\002R2 "
      "=\002,e21.13)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, lunit, mesflg;

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___7 = { 0, 0, 0, fmt_20, 0 };
    static cilist io___8 = { 0, 0, 0, fmt_30, 0 };
    static cilist io___9 = { 0, 0, 0, fmt_40, 0 };
    static cilist io___10 = { 0, 0, 0, fmt_50, 0 };


/* ----------------------------------------------------------------------- */
/* Subroutine XERRWV, as given here, constitutes a simplified version of */
/* the SLATEC error handling package. */
/* Written by A. C. Hindmarsh and P. N. Brown at LLNL. */
/* Modified 1/8/90 by Clement Ulrich at LLNL. */
/* Version of 8 January, 1990. */
/* This version is in double precision. */

/* All arguments are input arguments. */

/* MSG    = The message (character array). */
/* NMES   = The length of MSG (number of characters). */
/* NERR   = The error number (not used). */
/* LEVEL  = The error level.. */
/*          0 or 1 means recoverable (control returns to caller). */
/*          2 means fatal (run is aborted--see note below). */
/* NI     = Number of integers (0, 1, or 2) to be printed with message. */
/* I1,I2  = Integers to be printed, depending on NI. */
/* NR     = Number of reals (0, 1, or 2) to be printed with message. */
/* R1,R2  = Reals to be printed, depending on NR. */

/* Note..  this routine is compatible with ANSI-77; however the */
/* following assumptions may not be valid for some machines: */

/* 1. The argument MSG is assumed to be of type CHARACTER, and */
/*    the message is printed with a format of (1X,80A1). */
/* 2. The message is assumed to take only one line. */
/*    Multi-line messages are generated by repeated calls. */
/* 3. If LEVEL = 2, control passes to the statement STOP */
/*    to abort the run.  For a different run-abort command, */
/*    change the statement following statement 100 at the end. */
/* 4. R1 and R2 are assumed to be in double precision and are printed */
/*    in E21.13 format. */
/* 5. The logical unit number 6 is standard output. */
/*    For a different default logical unit number, change the assignment */
/*    statement for LUNIT below. */

/* ----------------------------------------------------------------------- */
/* Subroutines called by XERRWV.. None */
/* Function routines called by XERRWV.. None */
/* ----------------------------------------------------------------------- */


/* Define message print flag and logical unit number. ------------------- */
    /* Parameter adjustments */
    --msg;

    /* Function Body */
    mesflg = 1;
    lunit = 6;
    if(mesflg == 0) {
  goto L100;
    }
/* Write the message. --------------------------------------------------- */
    io___5.ciunit = lunit;
    s_wsfe(&io___5);
    i__1 = *nmes;
    for(i__ = 1; i__ <= i__1; ++i__) {
  do_fio(&c__1, msg + i__, (ftnlen)1);
    }
    e_wsfe();
    if(*ni == 1) {
  io___7.ciunit = lunit;
  s_wsfe(&io___7);
  do_fio(&c__1, (char *)&(*i1), (ftnlen)sizeof(integer));
  e_wsfe();
    }
    if(*ni == 2) {
  io___8.ciunit = lunit;
  s_wsfe(&io___8);
  do_fio(&c__1, (char *)&(*i1), (ftnlen)sizeof(integer));
  do_fio(&c__1, (char *)&(*i2), (ftnlen)sizeof(integer));
  e_wsfe();
    }
    if(*nr == 1) {
  io___9.ciunit = lunit;
  s_wsfe(&io___9);
  do_fio(&c__1, (char *)&(*r1), (ftnlen)sizeof(doublereal));
  e_wsfe();
    }
    if(*nr == 2) {
  io___10.ciunit = lunit;
  s_wsfe(&io___10);
  do_fio(&c__1, (char *)&(*r1), (ftnlen)sizeof(doublereal));
  do_fio(&c__1, (char *)&(*r2), (ftnlen)sizeof(doublereal));
  e_wsfe();
    }
/* Abort the run if LEVEL = 2. ------------------------------------------ */
L100:
    if(*level != 2) {
  return 0;
    }
    s_stop("", (ftnlen)0);
/* ----------------------- End of Subroutine XERRWV ---------------------- */
    return 0;
} /* xerrwv_ */

integer i1mach_(integer *i__)
{
    /* Initialized data */

    static integer sanity = 987;
    static struct {
  integer e_1[16];
  } equiv_0 = {{ 5, 6, 7, 6, 32, 4, 2, 31, 2147483647, 2, 24, -125, 128, 53, -1021, 1024 }};


    /* Format strings */
    static char fmt_1999[] = "(\002 I1MACH - I OUT OF BOUNDS\002,i10)";

    /* System generated locals */
    integer ret_val=0;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
#define imach ((integer *)&equiv_0)
#define output ((integer *)&equiv_0 + 3)

    /* Fortran I/O blocks */
    static cilist io___14 = { 0, 0, 0, fmt_1999, 0 };



/*  I/O UNIT NUMBERS. */

/*    I1MACH( 1) = THE STANDARD INPUT UNIT. */

/*    I1MACH( 2) = THE STANDARD OUTPUT UNIT. */

/*    I1MACH( 3) = THE STANDARD PUNCH UNIT. */

/*    I1MACH( 4) = THE STANDARD ERROR MESSAGE UNIT. */

/*  WORDS. */

/*    I1MACH( 5) = THE NUMBER OF BITS PER INTEGER STORAGE UNIT. */

/*    I1MACH( 6) = THE NUMBER OF CHARACTERS PER CHARACTER STORAGE UNIT. */
/*                 FOR FORTRAN 77, THIS IS ALWAYS 1.  FOR FORTRAN 66, */
/*                 CHARACTER STORAGE UNIT = INTEGER STORAGE UNIT. */

/*  INTEGERS. */

/*    ASSUME INTEGERS ARE REPRESENTED IN THE S-DIGIT, BASE-A FORM */

/*               SIGN ( X(S-1)*A**(S-1) + ... + X(1)*A + X(0) ) */

/*               WHERE 0 .LE. X(I) .LT. A FOR I=0,...,S-1. */

/*    I1MACH( 7) = A, THE BASE. */

/*    I1MACH( 8) = S, THE NUMBER OF BASE-A DIGITS. */

/*    I1MACH( 9) = A**S - 1, THE LARGEST MAGNITUDE. */

/*  FLOATING-POINT NUMBERS. */

/*    ASSUME FLOATING-POINT NUMBERS ARE REPRESENTED IN THE T-DIGIT, */
/*    BASE-B FORM */

/*               SIGN (B**E)*( (X(1)/B) + ... + (X(T)/B**T) ) */

/*               WHERE 0 .LE. X(I) .LT. B FOR I=1,...,T, */
/*               0 .LT. X(1), AND EMIN .LE. E .LE. EMAX. */

/*    I1MACH(10) = B, THE BASE. */

/*  SINGLE-PRECISION */

/*    I1MACH(11) = T, THE NUMBER OF BASE-B DIGITS. */

/*    I1MACH(12) = EMIN, THE SMALLEST EXPONENT E. */

/*    I1MACH(13) = EMAX, THE LARGEST EXPONENT E. */

/*  DOUBLE-PRECISION */

/*    I1MACH(14) = T, THE NUMBER OF BASE-B DIGITS. */

/*    I1MACH(15) = EMIN, THE SMALLEST EXPONENT E. */

/*    I1MACH(16) = EMAX, THE LARGEST EXPONENT E. */

/*  TO ALTER THIS FUNCTION FOR A PARTICULAR ENVIRONMENT, */
/*  THE DESIRED SET OF DATA STATEMENTS SHOULD BE ACTIVATED BY */
/*  REMOVING THE C FROM COLUMN 1.  ALSO, THE VALUES OF */
/*  I1MACH(1) - I1MACH(4) SHOULD BE CHECKED FOR CONSISTENCY */
/*  WITH THE LOCAL OPERATING SYSTEM.  FOR FORTRAN 77, YOU MAY WISH */
/*  TO ADJUST THE DATA STATEMENT SO IMACH(6) IS SET TO 1, AND */
/*  THEN TO COMMENT OUT THE EXECUTABLE TEST ON I .EQ. 6 BELOW. */
/*  ON RARE MACHINES A STATIC STATEMENT MAY NEED TO BE ADDED. */
/*  (BUT PROBABLY MORE SYSTEMS PROHIBIT IT THAN REQUIRE IT.) */

/*  FOR IEEE-ARITHMETIC MACHINES (BINARY STANDARD), THE FIRST */
/*  SET OF CONSTANTS BELOW SHOULD BE APPROPRIATE, EXCEPT PERHAPS */
/*  FOR IMACH(1) - IMACH(4). */



/*     MACHINE CONSTANTS FOR IEEE ARITHMETIC MACHINES, SUCH AS THE AT&T */
/*     3B SERIES, MOTOROLA 68000 BASED MACHINES (E.G. SUN 3 AND AT&T */
/*     PC 7300), AND 8087 BASED MICROS (E.G. IBM PC AND AT&T 6300). */


/*     MACHINE CONSTANTS FOR AMDAHL MACHINES. */

/*      DATA IMACH( 1) /   5 / */
/*      DATA IMACH( 2) /   6 / */
/*      DATA IMACH( 3) /   7 / */
/*      DATA IMACH( 4) /   6 / */
/*      DATA IMACH( 5) /  32 / */
/*      DATA IMACH( 6) /   4 / */
/*      DATA IMACH( 7) /   2 / */
/*      DATA IMACH( 8) /  31 / */
/*      DATA IMACH( 9) / 2147483647 / */
/*      DATA IMACH(10) /  16 / */
/*      DATA IMACH(11) /   6 / */
/*      DATA IMACH(12) / -64 / */
/*      DATA IMACH(13) /  63 / */
/*      DATA IMACH(14) /  14 / */
/*      DATA IMACH(15) / -64 / */
/*      DATA IMACH(16) /  63 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE BURROUGHS 1700 SYSTEM. */

/*      DATA IMACH( 1) /    7 / */
/*      DATA IMACH( 2) /    2 / */
/*      DATA IMACH( 3) /    2 / */
/*      DATA IMACH( 4) /    2 / */
/*      DATA IMACH( 5) /   36 / */
/*      DATA IMACH( 6) /    4 / */
/*      DATA IMACH( 7) /    2 / */
/*      DATA IMACH( 8) /   33 / */
/*      DATA IMACH( 9) / Z1FFFFFFFF / */
/*      DATA IMACH(10) /    2 / */
/*      DATA IMACH(11) /   24 / */
/*      DATA IMACH(12) / -256 / */
/*      DATA IMACH(13) /  255 / */
/*      DATA IMACH(14) /   60 / */
/*      DATA IMACH(15) / -256 / */
/*      DATA IMACH(16) /  255 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE BURROUGHS 5700 SYSTEM. */

/*      DATA IMACH( 1) /   5 / */
/*      DATA IMACH( 2) /   6 / */
/*      DATA IMACH( 3) /   7 / */
/*      DATA IMACH( 4) /   6 / */
/*      DATA IMACH( 5) /  48 / */
/*      DATA IMACH( 6) /   6 / */
/*      DATA IMACH( 7) /   2 / */
/*      DATA IMACH( 8) /  39 / */
/*      DATA IMACH( 9) / O0007777777777777 / */
/*      DATA IMACH(10) /   8 / */
/*      DATA IMACH(11) /  13 / */
/*      DATA IMACH(12) / -50 / */
/*      DATA IMACH(13) /  76 / */
/*      DATA IMACH(14) /  26 / */
/*      DATA IMACH(15) / -50 / */
/*      DATA IMACH(16) /  76 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE BURROUGHS 6700/7700 SYSTEMS. */

/*      DATA IMACH( 1) /   5 / */
/*      DATA IMACH( 2) /   6 / */
/*      DATA IMACH( 3) /   7 / */
/*      DATA IMACH( 4) /   6 / */
/*      DATA IMACH( 5) /  48 / */
/*      DATA IMACH( 6) /   6 / */
/*      DATA IMACH( 7) /   2 / */
/*      DATA IMACH( 8) /  39 / */
/*      DATA IMACH( 9) / O0007777777777777 / */
/*      DATA IMACH(10) /   8 / */
/*      DATA IMACH(11) /  13 / */
/*      DATA IMACH(12) / -50 / */
/*      DATA IMACH(13) /  76 / */
/*      DATA IMACH(14) /  26 / */
/*      DATA IMACH(15) / -32754 / */
/*      DATA IMACH(16) /  32780 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR FTN4 ON THE CDC 6000/7000 SERIES. */

/*      DATA IMACH( 1) /    5 / */
/*      DATA IMACH( 2) /    6 / */
/*      DATA IMACH( 3) /    7 / */
/*      DATA IMACH( 4) /    6 / */
/*      DATA IMACH( 5) /   60 / */
/*      DATA IMACH( 6) /   10 / */
/*      DATA IMACH( 7) /    2 / */
/*      DATA IMACH( 8) /   48 / */
/*      DATA IMACH( 9) / 00007777777777777777B / */
/*      DATA IMACH(10) /    2 / */
/*      DATA IMACH(11) /   47 / */
/*      DATA IMACH(12) / -929 / */
/*      DATA IMACH(13) / 1070 / */
/*      DATA IMACH(14) /   94 / */
/*      DATA IMACH(15) / -929 / */
/*      DATA IMACH(16) / 1069 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR FTN5 ON THE CDC 6000/7000 SERIES. */

/*      DATA IMACH( 1) /    5 / */
/*      DATA IMACH( 2) /    6 / */
/*      DATA IMACH( 3) /    7 / */
/*      DATA IMACH( 4) /    6 / */
/*      DATA IMACH( 5) /   60 / */
/*      DATA IMACH( 6) /   10 / */
/*      DATA IMACH( 7) /    2 / */
/*      DATA IMACH( 8) /   48 / */
/*      DATA IMACH( 9) / O"00007777777777777777" / */
/*      DATA IMACH(10) /    2 / */
/*      DATA IMACH(11) /   47 / */
/*      DATA IMACH(12) / -929 / */
/*      DATA IMACH(13) / 1070 / */
/*      DATA IMACH(14) /   94 / */
/*      DATA IMACH(15) / -929 / */
/*      DATA IMACH(16) / 1069 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR CONVEX C-1. */

/*      DATA IMACH( 1) /    5 / */
/*      DATA IMACH( 2) /    6 / */
/*      DATA IMACH( 3) /    7 / */
/*      DATA IMACH( 4) /    6 / */
/*      DATA IMACH( 5) /   32 / */
/*      DATA IMACH( 6) /    4 / */
/*      DATA IMACH( 7) /    2 / */
/*      DATA IMACH( 8) /   31 / */
/*      DATA IMACH( 9) / 2147483647 / */
/*      DATA IMACH(10) /    2 / */
/*      DATA IMACH(11) /   24 / */
/*      DATA IMACH(12) / -128 / */
/*      DATA IMACH(13) /  127 / */
/*      DATA IMACH(14) /   53 / */
/*      DATA IMACH(15) /-1024 / */
/*      DATA IMACH(16) / 1023 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE CRAY 1, XMP, 2, AND 3. */

/*      DATA IMACH( 1) /     5 / */
/*      DATA IMACH( 2) /     6 / */
/*      DATA IMACH( 3) /   102 / */
/*      DATA IMACH( 4) /     6 / */
/*      DATA IMACH( 5) /    64 / */
/*      DATA IMACH( 6) /     8 / */
/*      DATA IMACH( 7) /     2 / */
/*      DATA IMACH( 8) /    63 / */
/*      DATA IMACH( 9) /  777777777777777777777B / */
/*      DATA IMACH(10) /     2 / */
/*      DATA IMACH(11) /    47 / */
/*      DATA IMACH(12) / -8189 / */
/*      DATA IMACH(13) /  8190 / */
/*      DATA IMACH(14) /    94 / */
/*      DATA IMACH(15) / -8099 / */
/*      DATA IMACH(16) /  8190 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE DATA GENERAL ECLIPSE S/200. */

/*      DATA IMACH( 1) /   11 / */
/*      DATA IMACH( 2) /   12 / */
/*      DATA IMACH( 3) /    8 / */
/*      DATA IMACH( 4) /   10 / */
/*      DATA IMACH( 5) /   16 / */
/*      DATA IMACH( 6) /    2 / */
/*      DATA IMACH( 7) /    2 / */
/*      DATA IMACH( 8) /   15 / */
/*      DATA IMACH( 9) /32767 / */
/*      DATA IMACH(10) /   16 / */
/*      DATA IMACH(11) /    6 / */
/*      DATA IMACH(12) /  -64 / */
/*      DATA IMACH(13) /   63 / */
/*      DATA IMACH(14) /   14 / */
/*      DATA IMACH(15) /  -64 / */
/*      DATA IMACH(16) /   63 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE HARRIS SLASH 6 AND SLASH 7. */

/*      DATA IMACH( 1) /       5 / */
/*      DATA IMACH( 2) /       6 / */
/*      DATA IMACH( 3) /       0 / */
/*      DATA IMACH( 4) /       6 / */
/*      DATA IMACH( 5) /      24 / */
/*      DATA IMACH( 6) /       3 / */
/*      DATA IMACH( 7) /       2 / */
/*      DATA IMACH( 8) /      23 / */
/*      DATA IMACH( 9) / 8388607 / */
/*      DATA IMACH(10) /       2 / */
/*      DATA IMACH(11) /      23 / */
/*      DATA IMACH(12) /    -127 / */
/*      DATA IMACH(13) /     127 / */
/*      DATA IMACH(14) /      38 / */
/*      DATA IMACH(15) /    -127 / */
/*      DATA IMACH(16) /     127 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE HONEYWELL DPS 8/70 SERIES. */

/*      DATA IMACH( 1) /    5 / */
/*      DATA IMACH( 2) /    6 / */
/*      DATA IMACH( 3) /   43 / */
/*      DATA IMACH( 4) /    6 / */
/*      DATA IMACH( 5) /   36 / */
/*      DATA IMACH( 6) /    4 / */
/*      DATA IMACH( 7) /    2 / */
/*      DATA IMACH( 8) /   35 / */
/*      DATA IMACH( 9) / O377777777777 / */
/*      DATA IMACH(10) /    2 / */
/*      DATA IMACH(11) /   27 / */
/*      DATA IMACH(12) / -127 / */
/*      DATA IMACH(13) /  127 / */
/*      DATA IMACH(14) /   63 / */
/*      DATA IMACH(15) / -127 / */
/*      DATA IMACH(16) /  127 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE IBM 360/370 SERIES, */
/*     THE XEROX SIGMA 5/7/9 AND THE SEL SYSTEMS 85/86. */

/*      DATA IMACH( 1) /   5 / */
/*      DATA IMACH( 2) /   6 / */
/*      DATA IMACH( 3) /   7 / */
/*      DATA IMACH( 4) /   6 / */
/*      DATA IMACH( 5) /  32 / */
/*      DATA IMACH( 6) /   4 / */
/*      DATA IMACH( 7) /   2 / */
/*      DATA IMACH( 8) /  31 / */
/*      DATA IMACH( 9) / Z7FFFFFFF / */
/*      DATA IMACH(10) /  16 / */
/*      DATA IMACH(11) /   6 / */
/*      DATA IMACH(12) / -64 / */
/*      DATA IMACH(13) /  63 / */
/*      DATA IMACH(14) /  14 / */
/*      DATA IMACH(15) / -64 / */
/*      DATA IMACH(16) /  63 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE INTERDATA 8/32 */
/*     WITH THE UNIX SYSTEM FORTRAN 77 COMPILER. */

/*     FOR THE INTERDATA FORTRAN VII COMPILER REPLACE */
/*     THE Z'S SPECIFYING HEX CONSTANTS WITH Y'S. */

/*      DATA IMACH( 1) /   5 / */
/*      DATA IMACH( 2) /   6 / */
/*      DATA IMACH( 3) /   6 / */
/*      DATA IMACH( 4) /   6 / */
/*      DATA IMACH( 5) /  32 / */
/*      DATA IMACH( 6) /   4 / */
/*      DATA IMACH( 7) /   2 / */
/*      DATA IMACH( 8) /  31 / */
/*      DATA IMACH( 9) / Z'7FFFFFFF' / */
/*      DATA IMACH(10) /  16 / */
/*      DATA IMACH(11) /   6 / */
/*      DATA IMACH(12) / -64 / */
/*      DATA IMACH(13) /  62 / */
/*      DATA IMACH(14) /  14 / */
/*      DATA IMACH(15) / -64 / */
/*      DATA IMACH(16) /  62 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE PDP-10 (KA PROCESSOR). */

/*      DATA IMACH( 1) /    5 / */
/*      DATA IMACH( 2) /    6 / */
/*      DATA IMACH( 3) /    7 / */
/*      DATA IMACH( 4) /    6 / */
/*      DATA IMACH( 5) /   36 / */
/*      DATA IMACH( 6) /    5 / */
/*      DATA IMACH( 7) /    2 / */
/*      DATA IMACH( 8) /   35 / */
/*      DATA IMACH( 9) / "377777777777 / */
/*      DATA IMACH(10) /    2 / */
/*      DATA IMACH(11) /   27 / */
/*      DATA IMACH(12) / -128 / */
/*      DATA IMACH(13) /  127 / */
/*      DATA IMACH(14) /   54 / */
/*      DATA IMACH(15) / -101 / */
/*      DATA IMACH(16) /  127 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE PDP-10 (KI PROCESSOR). */

/*      DATA IMACH( 1) /    5 / */
/*      DATA IMACH( 2) /    6 / */
/*      DATA IMACH( 3) /    7 / */
/*      DATA IMACH( 4) /    6 / */
/*      DATA IMACH( 5) /   36 / */
/*      DATA IMACH( 6) /    5 / */
/*      DATA IMACH( 7) /    2 / */
/*      DATA IMACH( 8) /   35 / */
/*      DATA IMACH( 9) / "377777777777 / */
/*      DATA IMACH(10) /    2 / */
/*      DATA IMACH(11) /   27 / */
/*      DATA IMACH(12) / -128 / */
/*      DATA IMACH(13) /  127 / */
/*      DATA IMACH(14) /   62 / */
/*      DATA IMACH(15) / -128 / */
/*      DATA IMACH(16) /  127 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR PDP-11 FORTRANS SUPPORTING */
/*     32-BIT INTEGER ARITHMETIC. */

/*      DATA IMACH( 1) /    5 / */
/*      DATA IMACH( 2) /    6 / */
/*      DATA IMACH( 3) /    7 / */
/*      DATA IMACH( 4) /    6 / */
/*      DATA IMACH( 5) /   32 / */
/*      DATA IMACH( 6) /    4 / */
/*      DATA IMACH( 7) /    2 / */
/*      DATA IMACH( 8) /   31 / */
/*      DATA IMACH( 9) / 2147483647 / */
/*      DATA IMACH(10) /    2 / */
/*      DATA IMACH(11) /   24 / */
/*      DATA IMACH(12) / -127 / */
/*      DATA IMACH(13) /  127 / */
/*      DATA IMACH(14) /   56 / */
/*      DATA IMACH(15) / -127 / */
/*      DATA IMACH(16) /  127 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR PDP-11 FORTRANS SUPPORTING */
/*     16-BIT INTEGER ARITHMETIC. */

/*      DATA IMACH( 1) /    5 / */
/*      DATA IMACH( 2) /    6 / */
/*      DATA IMACH( 3) /    7 / */
/*      DATA IMACH( 4) /    6 / */
/*      DATA IMACH( 5) /   16 / */
/*      DATA IMACH( 6) /    2 / */
/*      DATA IMACH( 7) /    2 / */
/*      DATA IMACH( 8) /   15 / */
/*      DATA IMACH( 9) / 32767 / */
/*      DATA IMACH(10) /    2 / */
/*      DATA IMACH(11) /   24 / */
/*      DATA IMACH(12) / -127 / */
/*      DATA IMACH(13) /  127 / */
/*      DATA IMACH(14) /   56 / */
/*      DATA IMACH(15) / -127 / */
/*      DATA IMACH(16) /  127 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE PRIME 50 SERIES SYSTEMS */
/*     WTIH 32-BIT INTEGERS AND 64V MODE INSTRUCTIONS, */
/*     SUPPLIED BY IGOR BRAY. */

/*      DATA IMACH( 1) /            1 / */
/*      DATA IMACH( 2) /            1 / */
/*      DATA IMACH( 3) /            2 / */
/*      DATA IMACH( 4) /            1 / */
/*      DATA IMACH( 5) /           32 / */
/*      DATA IMACH( 6) /            4 / */
/*      DATA IMACH( 7) /            2 / */
/*      DATA IMACH( 8) /           31 / */
/*      DATA IMACH( 9) / :17777777777 / */
/*      DATA IMACH(10) /            2 / */
/*      DATA IMACH(11) /           23 / */
/*      DATA IMACH(12) /         -127 / */
/*      DATA IMACH(13) /         +127 / */
/*      DATA IMACH(14) /           47 / */
/*      DATA IMACH(15) /       -32895 / */
/*      DATA IMACH(16) /       +32637 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE SEQUENT BALANCE 8000. */

/*      DATA IMACH( 1) /     0 / */
/*      DATA IMACH( 2) /     0 / */
/*      DATA IMACH( 3) /     7 / */
/*      DATA IMACH( 4) /     0 / */
/*      DATA IMACH( 5) /    32 / */
/*      DATA IMACH( 6) /     1 / */
/*      DATA IMACH( 7) /     2 / */
/*      DATA IMACH( 8) /    31 / */
/*      DATA IMACH( 9) /  2147483647 / */
/*      DATA IMACH(10) /     2 / */
/*      DATA IMACH(11) /    24 / */
/*      DATA IMACH(12) /  -125 / */
/*      DATA IMACH(13) /   128 / */
/*      DATA IMACH(14) /    53 / */
/*      DATA IMACH(15) / -1021 / */
/*      DATA IMACH(16) /  1024 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR THE UNIVAC 1100 SERIES. */

/*     NOTE THAT THE PUNCH UNIT, I1MACH(3), HAS BEEN SET TO 7 */
/*     WHICH IS APPROPRIATE FOR THE UNIVAC-FOR SYSTEM. */
/*     IF YOU HAVE THE UNIVAC-FTN SYSTEM, SET IT TO 1. */

/*      DATA IMACH( 1) /    5 / */
/*      DATA IMACH( 2) /    6 / */
/*      DATA IMACH( 3) /    7 / */
/*      DATA IMACH( 4) /    6 / */
/*      DATA IMACH( 5) /   36 / */
/*      DATA IMACH( 6) /    6 / */
/*      DATA IMACH( 7) /    2 / */
/*      DATA IMACH( 8) /   35 / */
/*      DATA IMACH( 9) / O377777777777 / */
/*      DATA IMACH(10) /    2 / */
/*      DATA IMACH(11) /   27 / */
/*      DATA IMACH(12) / -128 / */
/*      DATA IMACH(13) /  127 / */
/*      DATA IMACH(14) /   60 / */
/*      DATA IMACH(15) /-1024 / */
/*      DATA IMACH(16) / 1023 /, SANITY/987/ */

/*     MACHINE CONSTANTS FOR VAX. */

/*      DATA IMACH( 1) /    5 / */
/*      DATA IMACH( 2) /    6 / */
/*      DATA IMACH( 3) /    7 / */
/*      DATA IMACH( 4) /    6 / */
/*      DATA IMACH( 5) /   32 / */
/*      DATA IMACH( 6) /    4 / */
/*      DATA IMACH( 7) /    2 / */
/*      DATA IMACH( 8) /   31 / */
/*      DATA IMACH( 9) / 2147483647 / */
/*      DATA IMACH(10) /    2 / */
/*      DATA IMACH(11) /   24 / */
/*      DATA IMACH(12) / -127 / */
/*      DATA IMACH(13) /  127 / */
/*      DATA IMACH(14) /   56 / */
/*      DATA IMACH(15) / -127 / */
/*      DATA IMACH(16) /  127 /, SANITY/987/ */

/*  ***  ISSUE STOP 777 IF ALL DATA STATEMENTS ARE COMMENTED... */
    if(sanity != 987) {
  s_stop("777", (ftnlen)3);
    }
    if(*i__ < 1 || *i__ > 16) {
  goto L10;
    }

    ret_val = imach[*i__ - 1];
/* /6S */
/* /7S */
    if(*i__ == 6) {
  ret_val = 1;
    }
/* / */
    return ret_val;
L10:
    io___14.ciunit = *output;
    s_wsfe(&io___14);
    do_fio(&c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);
    return ret_val;
} /* i1mach_ */

#undef output
#undef imach


