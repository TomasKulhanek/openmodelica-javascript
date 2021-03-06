# Makefile generated by OpenModelica

# Simulations use -O3 by default
SIM_OR_DYNLOAD_OPT_LEVEL=
CC=emcc
CXX=emcc
LINK=emcc
EXEEXT=.js
DLLEXT=.so
CFLAGS_BASED_ON_INIT_FILE= 
CFLAGS=$(CFLAGS_BASED_ON_INIT_FILE) ${SIM_OR_DYNLOAD_OPT_LEVEL} -fPIC ${MODELICAUSERCFLAGS} 
CPPFLAGS=-I"/usr/include/omc" -I. -L"/usr/lib/omlibrary/Modelica 3.2.1/Electrical/Analog/Examples"  -DOPENMODELICA_XML_FROM_FILE_AT_RUNTIME
LDFLAGS= -L"./" -O2 -lexpat -lSimulationRuntimeC -lf2c -s TOTAL_MEMORY=536870912 -s MAX_SETJMPS=20000 -s OUTLINING_LIMIT=20000
PERL=perl
FILEPREFIX=Modelica.Electrical.Analog.Examples.ChuaCircuit
MAINFILE=$(FILEPREFIX).c
MAINOBJ=$(FILEPREFIX).o
GENERATEDFILES=$(MAINFILE) $(FILEPREFIX)_functions.c main.c $(FILEPREFIX)_functions.h $(FILEPREFIX)_records.c $(FILEPREFIX).makefile

# .PHONY: omc_main_target clean bundle

# This is to make sure that Modelica.Electrical.Analog.Examples.ChuaCircuit_records.c is always compiled.
# .PHONY: $(FILEPREFIX)_records.c

main_module: $(MAINOBJ) $(FILEPREFIX)_records.o $(FILEPREFIX)_functions.c $(FILEPREFIX)_functions.h
	$(CXX) -I. -o main_mod.js $(MAINOBJ) $(FILEPREFIX)_records.o $(CPPFLAGS) -L"/usr/lib/omlibrary/Modelica 3.2.1/Electrical/Analog/Examples"   $(CFLAGS) $(LDFLAGS)

Modelica.Electrical.Analog.Examples.ChuaCircuit.conv.c: $(FILEPREFIX).c
	$(PERL) /usr/share/omc/scripts/convert_lines.pl $< $@.tmp
	@mv $@.tmp $@
	$(PERL) /usr/share/omc/scripts/convert_lines.pl $(FILEPREFIX)_functions.c $@.tmp
	@mv $@.tmp $(FILEPREFIX)_functions.c

clean:
	@rm -f $(FILEPREFIX)_records.o $(MAINOBJ)

bundle:
	@tar -cvf $(FILEPREFIX)_Files.tar $(GENERATEDFILES)
