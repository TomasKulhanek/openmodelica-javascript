/* Mixed Systems */
/* Simulation code for HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel generated by the OpenModelica Compiler 1.9.1+dev (r18602) (RML version). */

#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "simulation_info_xml.h"
#include "simulation_runtime.h"
#include "omc_error.h"
#include "model_help.h"
#include "delay.h"
#include "linearSystem.h"
#include "nonlinearSystem.h"
#include "mixedSystem.h"

#include <assert.h>
#include <string.h>

#include "HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_functions.h"
#include "HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_model.h"
#include "HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_literals.h"



#if defined(HPCOM) && !defined(_OPENMP)
  #error "HPCOM requires OpenMP or the results are wrong"
#endif
#if defined(_OPENMP)
  #include <omp.h>
#else
  /* dummy omp defines */
  #define omp_get_max_threads() 1
#endif

#define threadData data->threadData

#include "HeamodynamicsDymola.Models.HaedynamicsBurkhoffModel_11mix.h"
/* initial mixed systems */
void updateContinuousPart44(void *inData)
{
  DATA* data = (DATA*) inData;
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_42(data);
  data->simulationInfo.mixedSystemData[0].continuous_solution = data->simulationInfo.linearSystemData[0].solved;
}

void updateIterationExpMixedSystem44(void *inData)
{
  DATA* data = (DATA*) inData;
  modelica_boolean tmp0;

  RELATIONHYSTERESIS(tmp0, $PrightHeartBurkhoffWithBusConnector$PtricuspidValve$PpassableVariable, 0.0, 6, Greater);
  $PrightHeartBurkhoffWithBusConnector$PtricuspidValve$Popen = tmp0;
}

void updateContinuousPart64(void *inData)
{
  DATA* data = (DATA*) inData;
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_62(data);
  data->simulationInfo.mixedSystemData[1].continuous_solution = data->simulationInfo.linearSystemData[1].solved;
}

void updateIterationExpMixedSystem64(void *inData)
{
  DATA* data = (DATA*) inData;
  modelica_boolean tmp1;

  RELATIONHYSTERESIS(tmp1, $PleftHeartBurkhofWithBusConnector$PMitralValve$PpassableVariable, 0.0, 11, Greater);
  $PleftHeartBurkhofWithBusConnector$PMitralValve$Popen = tmp1;
}
/* inline mixed systems */
/* parameter mixed systems */
/* model mixed systems */
void updateContinuousPart373(void *inData)
{
  DATA* data = (DATA*) inData;
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_371(data);
  data->simulationInfo.mixedSystemData[2].continuous_solution = data->simulationInfo.linearSystemData[2].solved;
}

void updateIterationExpMixedSystem373(void *inData)
{
  DATA* data = (DATA*) inData;
  modelica_boolean tmp2;

  RELATIONHYSTERESIS(tmp2, $PrightHeartBurkhoffWithBusConnector$PtricuspidValve$PpassableVariable, 0.0, 6, Greater);
  $PrightHeartBurkhoffWithBusConnector$PtricuspidValve$Popen = tmp2;
}

void updateContinuousPart417(void *inData)
{
  DATA* data = (DATA*) inData;
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_415(data);
  data->simulationInfo.mixedSystemData[3].continuous_solution = data->simulationInfo.linearSystemData[3].solved;
}

void updateIterationExpMixedSystem417(void *inData)
{
  DATA* data = (DATA*) inData;
  modelica_boolean tmp3;

  RELATIONHYSTERESIS(tmp3, $PleftHeartBurkhofWithBusConnector$PMitralValve$PpassableVariable, 0.0, 11, Greater);
  $PleftHeartBurkhofWithBusConnector$PMitralValve$Popen = tmp3;
}
/* jacobians mixed systems */

