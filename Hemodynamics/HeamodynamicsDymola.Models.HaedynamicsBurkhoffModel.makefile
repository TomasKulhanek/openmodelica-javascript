# Makefile generated by OpenModelica

# Simulations use -O3 by default
SIM_OR_DYNLOAD_OPT_LEVEL=
CC=gcc
CXX=g++
LINK=gcc -shared
EXEEXT=
DLLEXT=.so
CFLAGS_BASED_ON_INIT_FILE= 
CFLAGS=$(CFLAGS_BASED_ON_INIT_FILE) -fPIC -O0 -falign-functions -march=native ${MODELICAUSERCFLAGS}  
CPPFLAGS=-I"/usr/include/omc" -I.  -DOPENMODELICA_XML_FROM_FILE_AT_RUNTIME
LDFLAGS=-L"/home/tomaton/ownCloud/Hemodynamics" -L"/usr/lib/omc" -L"/usr/lib" -Wl,-rpath,"/usr/lib/omc" -Wl,-rpath,"/usr/lib"   -lSimulationRuntimeC -llapack -lblas -lm -lgc -lpthread -rdynamic
MAINFILE=HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel.c
MAINOBJ=HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel.o
CFILES=HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_functions.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_records.c \
HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_01exo.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_02nls.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_03lsy.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_04set.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_05evt.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_06inz.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_07dly.c \
HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_08bnd.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_09alg.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_10asr.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_11mix.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_12jac.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_13opt.c HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_14lnz.c
OFILES=$(CFILES:.c=.o)
GENERATEDFILES=$(MAINFILE) HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel.makefile HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_literals.h HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_functions.h $(CFILES)

.PHONY: omc_main_target clean bundle

# This is to make sure that HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_*.c are always compiled.
.PHONY: $(CFILES)

omc_main_target: $(MAINOBJ) HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_functions.h HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_literals.h $(OFILES)
	$(CC) -I. -o HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel$(EXEEXT) $(MAINOBJ) $(OFILES) $(CPPFLAGS) -L"/home/tomaton/ownCloud/Hemodynamics"   $(CFLAGS) $(LDFLAGS)

clean:
	@rm -f HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_records.o $(MAINOBJ)

bundle:
	@tar -cvf HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_Files.tar $(GENERATEDFILES)