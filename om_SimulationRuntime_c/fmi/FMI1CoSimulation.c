/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE
 * OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3, ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "FMICommon.h"
#include "FMI1Common.h"

/*
 * FMI version 1.0 Co-Simulation functions
 */

void* FMI1CoSimulationConstructor_OMC(int fmi_log_level, char* working_directory, char* instanceName, int debugLogging, char* fmuLocation, char* mimeType,
    double timeout, int visible, int interactive, double tStart, int stopTimeDefined, double tStop)
{
  FMI1CoSimulation* FMI1CS = malloc(sizeof(FMI1CoSimulation));
  FMI1CS->FMILogLevel = fmi_log_level;
  /* JM callbacks */
  FMI1CS->JMCallbacks.malloc = malloc;
  FMI1CS->JMCallbacks.calloc = calloc;
  FMI1CS->JMCallbacks.realloc = realloc;
  FMI1CS->JMCallbacks.free = free;
  FMI1CS->JMCallbacks.logger = importlogger;
  FMI1CS->JMCallbacks.log_level = FMI1CS->FMILogLevel;
  FMI1CS->JMCallbacks.context = 0;
  FMI1CS->FMIImportContext = fmi_import_allocate_context(&FMI1CS->JMCallbacks);
  /* FMI callback functions */
  FMI1CS->FMICallbackFunctions.logger = fmi1logger;
  FMI1CS->FMICallbackFunctions.allocateMemory = calloc;
  FMI1CS->FMICallbackFunctions.freeMemory = free;
  /* parse the xml file */
  FMI1CS->FMIWorkingDirectory = (char*) malloc(strlen(working_directory)+1);
  strcpy(FMI1CS->FMIWorkingDirectory, working_directory);
  FMI1CS->FMIImportInstance = fmi1_import_parse_xml(FMI1CS->FMIImportContext, FMI1CS->FMIWorkingDirectory);
  if(!FMI1CS->FMIImportInstance) {
    fprintf(stderr, "Error parsing the XML file contained in %s\n", FMI1CS->FMIWorkingDirectory);
    return 0;
  }
  /* Load the binary (dll/so) */
  jm_status_enu_t status;
  status = fmi1_import_create_dllfmu(FMI1CS->FMIImportInstance, FMI1CS->FMICallbackFunctions, 0);
  if (status == jm_status_error) {
    fprintf(stderr, "Could not create the DLL loading mechanism(C-API).\n");
    return 0;
  }
  FMI1CS->FMIInstanceName = (char*) malloc(strlen(instanceName)+1);
  strcpy(FMI1CS->FMIInstanceName, instanceName);
  FMI1CS->FMIFmuLocation = (char*) malloc(strlen(fmuLocation)+1);
  strcpy(FMI1CS->FMIFmuLocation, fmuLocation);
  FMI1CS->FMIMimeType = (char*) malloc(strlen(mimeType)+1);
  strcpy(FMI1CS->FMIMimeType, mimeType);
  FMI1CS->FMITimeOut = timeout;
  FMI1CS->FMIVisible = visible;
  FMI1CS->FMIInteractive = interactive;
  fmi1_import_instantiate_slave(FMI1CS->FMIImportInstance, FMI1CS->FMIInstanceName, FMI1CS->FMIFmuLocation, FMI1CS->FMIMimeType, FMI1CS->FMITimeOut, FMI1CS->FMIVisible, FMI1CS->FMIInteractive);
  FMI1CS->FMIDebugLogging = debugLogging;
  fmi1_import_set_debug_logging(FMI1CS->FMIImportInstance, FMI1CS->FMIDebugLogging);
  FMI1CS->FMITStart = tStart;
  FMI1CS->FMIStopTimeDefined = stopTimeDefined;
  FMI1CS->FMITStop = tStop;
  fmi1_import_initialize_slave(FMI1CS->FMIImportInstance, FMI1CS->FMITStart, FMI1CS->FMIStopTimeDefined, FMI1CS->FMITStop);
  return FMI1CS;
}

void FMI1CoSimulationDestructor_OMC(void* in_fmi1cs)
{
  FMI1CoSimulation* FMI1CS = (FMI1CoSimulation*)in_fmi1cs;
  fmi1_import_terminate_slave(FMI1CS->FMIImportInstance);
  fmi1_import_free_slave_instance(FMI1CS->FMIImportInstance);
  fmi1_import_destroy_dllfmu(FMI1CS->FMIImportInstance);
  fmi1_import_free(FMI1CS->FMIImportInstance);
  fmi_import_free_context(FMI1CS->FMIImportContext);
  free(FMI1CS->FMIWorkingDirectory);
  free(FMI1CS->FMIInstanceName);
  free(FMI1CS->FMIFmuLocation);
  free(FMI1CS->FMIMimeType);
}

/*
 * Wrapper for the FMI function fmiDoStep.
 * Return value is dummy and is only used to run the equations in sequence.
 */
double fmi1DoStep_OMC(void* in_fmi1cs, double currentCommunicationPoint, double communicationStepSize, int newStep)
{
  FMI1CoSimulation* FMI1CS = (FMI1CoSimulation*)in_fmi1cs;
  fmi1_import_do_step(FMI1CS->FMIImportInstance, currentCommunicationPoint, communicationStepSize, newStep);
  return 0.0;
}

#ifdef __cplusplus
}
#endif
