/* Update Bound StartValues/Parameters */
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



/*
 equation index: 465
 type: SIMPLE_ASSIGN
 systemicCirculationBurkhoffWithBusConnector._StressedVolume._u2 = systemicCirculationBurkhoffWithBusConnector.SystemicArteries.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_465(DATA *data)
{
  $PsystemicCirculationBurkhoffWithBusConnector$PStressedVolume$Pu2 = $PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PV0;
}
/*
 equation index: 466
 type: SIMPLE_ASSIGN
 systemicCirculationBurkhoffWithBusConnector._StressedVolume._u1 = systemicCirculationBurkhoffWithBusConnector.SystemicVeins.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_466(DATA *data)
{
  $PsystemicCirculationBurkhoffWithBusConnector$PStressedVolume$Pu1 = $PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PV0;
}
/*
 equation index: 467
 type: SIMPLE_ASSIGN
 systemicCirculationBurkhoffWithBusConnector._SystemicVeins._Volume = systemicCirculationBurkhoffWithBusConnector.SystemicVeins.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_467(DATA *data)
{
  $PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PVolume = $PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PV0;
}
/*
 equation index: 468
 type: SIMPLE_ASSIGN
 systemicCirculationBurkhoffWithBusConnector._SystemicArteries._Volume = systemicCirculationBurkhoffWithBusConnector.SystemicArteries.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_468(DATA *data)
{
  $PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PVolume = $PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PV0;
}
/*
 equation index: 469
 type: SIMPLE_ASSIGN
 systemicCirculationBurkhoffWithBusConnector._AortaProximal._StressedVolume = systemicCirculationBurkhoffWithBusConnector.AortaProximal.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_469(DATA *data)
{
  $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PStressedVolume = $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PV0;
}
/*
 equation index: 470
 type: SIMPLE_ASSIGN
 systemicCirculationBurkhoffWithBusConnector._AortaProximal._Volume = systemicCirculationBurkhoffWithBusConnector.AortaProximal.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_470(DATA *data)
{
  $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PVolume = $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PV0;
}
/*
 equation index: 471
 type: SIMPLE_ASSIGN
 pulmonaryCirculationBurkhoffWithBusConnector._PulmonaryVeins._StressedVolume = pulmonaryCirculationBurkhoffWithBusConnector.PulmonaryVeins.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_471(DATA *data)
{
  $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PStressedVolume = $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PV0;
}
/*
 equation index: 472
 type: SIMPLE_ASSIGN
 pulmonaryCirculationBurkhoffWithBusConnector._PulmonaryVeins._Volume = pulmonaryCirculationBurkhoffWithBusConnector.PulmonaryVeins.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_472(DATA *data)
{
  $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PVolume = $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PV0;
}
/*
 equation index: 473
 type: SIMPLE_ASSIGN
 pulmonaryCirculationBurkhoffWithBusConnector._PulmonaryArtery._StressedVolume = pulmonaryCirculationBurkhoffWithBusConnector.PulmonaryArtery.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_473(DATA *data)
{
  $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PStressedVolume = $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PV0;
}
/*
 equation index: 474
 type: SIMPLE_ASSIGN
 pulmonaryCirculationBurkhoffWithBusConnector._PulmonaryArtery._Volume = pulmonaryCirculationBurkhoffWithBusConnector.PulmonaryArtery.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_474(DATA *data)
{
  $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PVolume = $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PV0;
}
/*
 equation index: 475
 type: SIMPLE_ASSIGN
 pulmonaryCirculationBurkhoffWithBusConnector._PulmonaryArteryProximal._StressedVolume = pulmonaryCirculationBurkhoffWithBusConnector.PulmonaryArteryProximal.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_475(DATA *data)
{
  $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PStressedVolume = $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PV0;
}
/*
 equation index: 476
 type: SIMPLE_ASSIGN
 pulmonaryCirculationBurkhoffWithBusConnector._PulmonaryArteryProximal._Volume = pulmonaryCirculationBurkhoffWithBusConnector.PulmonaryArteryProximal.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_476(DATA *data)
{
  $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PVolume = $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PV0;
}
/*
 equation index: 477
 type: SIMPLE_ASSIGN
 leftHeartBurkhofWithBusConnector._AtrialElastance._Vs = leftHeartBurkhofWithBusConnector.LeftAtrium.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_477(DATA *data)
{
  $PleftHeartBurkhofWithBusConnector$PAtrialElastance$PVs = $PleftHeartBurkhofWithBusConnector$PLeftAtrium$PV0;
}
/*
 equation index: 478
 type: SIMPLE_ASSIGN
 leftHeartBurkhofWithBusConnector._LeftVentricle._StressedVolume = leftHeartBurkhofWithBusConnector.LeftVentricle.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_478(DATA *data)
{
  $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PStressedVolume = $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PV0;
}
/*
 equation index: 479
 type: SIMPLE_ASSIGN
 leftHeartBurkhofWithBusConnector._LeftVentricle._Volume = leftHeartBurkhofWithBusConnector.LeftVentricle.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_479(DATA *data)
{
  $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PVolume = $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PV0;
}
/*
 equation index: 480
 type: SIMPLE_ASSIGN
 leftHeartBurkhofWithBusConnector._LeftAtrium._Volume = leftHeartBurkhofWithBusConnector.LeftAtrium.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_480(DATA *data)
{
  $PleftHeartBurkhofWithBusConnector$PLeftAtrium$PVolume = $PleftHeartBurkhofWithBusConnector$PLeftAtrium$PV0;
}
/*
 equation index: 481
 type: SIMPLE_ASSIGN
 rightHeartBurkhoffWithBusConnector._AtrialElastance._Vs = rightHeartBurkhoffWithBusConnector.RightAtrium.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_481(DATA *data)
{
  $PrightHeartBurkhoffWithBusConnector$PAtrialElastance$PVs = $PrightHeartBurkhoffWithBusConnector$PRightAtrium$PV0;
}
/*
 equation index: 482
 type: SIMPLE_ASSIGN
 rightHeartBurkhoffWithBusConnector._RightVentricle._StressedVolume = rightHeartBurkhoffWithBusConnector.RightVentricle.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_482(DATA *data)
{
  $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PStressedVolume = $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PV0;
}
/*
 equation index: 483
 type: SIMPLE_ASSIGN
 rightHeartBurkhoffWithBusConnector._RightVentricle._Volume = rightHeartBurkhoffWithBusConnector.RightVentricle.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_483(DATA *data)
{
  $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PVolume = $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PV0;
}
/*
 equation index: 484
 type: SIMPLE_ASSIGN
 rightHeartBurkhoffWithBusConnector._RightAtrium._Volume = rightHeartBurkhoffWithBusConnector.RightAtrium.V0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_484(DATA *data)
{
  $PrightHeartBurkhoffWithBusConnector$PRightAtrium$PVolume = $PrightHeartBurkhoffWithBusConnector$PRightAtrium$PV0;
}
int HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_updateBoundStartValues(DATA *data)
{

  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_465(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_466(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_467(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_468(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_469(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_470(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_471(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_472(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_473(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_474(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_475(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_476(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_477(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_478(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_479(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_480(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_481(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_482(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_483(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_484(data);
  
  infoStreamPrint(LOG_INIT, 1, "updating start-values");
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PsystemicCirculationBurkhoffWithBusConnector$PStressedVolume$Pu2__varInfo.name, (modelica_real) $PsystemicCirculationBurkhoffWithBusConnector$PStressedVolume$Pu2);
    $P$ATTRIBUTE$PsystemicCirculationBurkhoffWithBusConnector$PStressedVolume$Pu2.start = $PsystemicCirculationBurkhoffWithBusConnector$PStressedVolume$Pu2;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PsystemicCirculationBurkhoffWithBusConnector$PStressedVolume$Pu1__varInfo.name, (modelica_real) $PsystemicCirculationBurkhoffWithBusConnector$PStressedVolume$Pu1);
    $P$ATTRIBUTE$PsystemicCirculationBurkhoffWithBusConnector$PStressedVolume$Pu1.start = $PsystemicCirculationBurkhoffWithBusConnector$PStressedVolume$Pu1;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PVolume__varInfo.name, (modelica_real) $PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PVolume);
    $P$ATTRIBUTE$PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PVolume.start = $PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PVolume__varInfo.name, (modelica_real) $PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PVolume);
    $P$ATTRIBUTE$PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PVolume.start = $PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PStressedVolume__varInfo.name, (modelica_real) $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PStressedVolume);
    $P$ATTRIBUTE$PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PStressedVolume.start = $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PStressedVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PVolume__varInfo.name, (modelica_real) $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PVolume);
    $P$ATTRIBUTE$PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PVolume.start = $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PStressedVolume__varInfo.name, (modelica_real) $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PStressedVolume);
    $P$ATTRIBUTE$PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PStressedVolume.start = $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PStressedVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PVolume__varInfo.name, (modelica_real) $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PVolume);
    $P$ATTRIBUTE$PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PVolume.start = $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PStressedVolume__varInfo.name, (modelica_real) $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PStressedVolume);
    $P$ATTRIBUTE$PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PStressedVolume.start = $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PStressedVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PVolume__varInfo.name, (modelica_real) $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PVolume);
    $P$ATTRIBUTE$PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PVolume.start = $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PStressedVolume__varInfo.name, (modelica_real) $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PStressedVolume);
    $P$ATTRIBUTE$PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PStressedVolume.start = $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PStressedVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PVolume__varInfo.name, (modelica_real) $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PVolume);
    $P$ATTRIBUTE$PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PVolume.start = $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PleftHeartBurkhofWithBusConnector$PAtrialElastance$PVs__varInfo.name, (modelica_real) $PleftHeartBurkhofWithBusConnector$PAtrialElastance$PVs);
    $P$ATTRIBUTE$PleftHeartBurkhofWithBusConnector$PAtrialElastance$PVs.start = $PleftHeartBurkhofWithBusConnector$PAtrialElastance$PVs;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PStressedVolume__varInfo.name, (modelica_real) $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PStressedVolume);
    $P$ATTRIBUTE$PleftHeartBurkhofWithBusConnector$PLeftVentricle$PStressedVolume.start = $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PStressedVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PVolume__varInfo.name, (modelica_real) $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PVolume);
    $P$ATTRIBUTE$PleftHeartBurkhofWithBusConnector$PLeftVentricle$PVolume.start = $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PleftHeartBurkhofWithBusConnector$PLeftAtrium$PVolume__varInfo.name, (modelica_real) $PleftHeartBurkhofWithBusConnector$PLeftAtrium$PVolume);
    $P$ATTRIBUTE$PleftHeartBurkhofWithBusConnector$PLeftAtrium$PVolume.start = $PleftHeartBurkhofWithBusConnector$PLeftAtrium$PVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PrightHeartBurkhoffWithBusConnector$PAtrialElastance$PVs__varInfo.name, (modelica_real) $PrightHeartBurkhoffWithBusConnector$PAtrialElastance$PVs);
    $P$ATTRIBUTE$PrightHeartBurkhoffWithBusConnector$PAtrialElastance$PVs.start = $PrightHeartBurkhoffWithBusConnector$PAtrialElastance$PVs;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PStressedVolume__varInfo.name, (modelica_real) $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PStressedVolume);
    $P$ATTRIBUTE$PrightHeartBurkhoffWithBusConnector$PRightVentricle$PStressedVolume.start = $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PStressedVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PVolume__varInfo.name, (modelica_real) $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PVolume);
    $P$ATTRIBUTE$PrightHeartBurkhoffWithBusConnector$PRightVentricle$PVolume.start = $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PVolume;
  infoStreamPrint(LOG_INIT, 0, "%s(start=%g)", $PrightHeartBurkhoffWithBusConnector$PRightAtrium$PVolume__varInfo.name, (modelica_real) $PrightHeartBurkhoffWithBusConnector$PRightAtrium$PVolume);
    $P$ATTRIBUTE$PrightHeartBurkhoffWithBusConnector$PRightAtrium$PVolume.start = $PrightHeartBurkhoffWithBusConnector$PRightAtrium$PVolume;
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  return 0;
}


/*
 equation index: 485
 type: SIMPLE_ASSIGN
 bloodVolumeWithBusConnector._desiredStressedVolume._y = modelInputsBlock1.TotalBloodVolume.k - modelInputsBlock1.TotalUnstressedVolume.k
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_485(DATA *data)
{
  $PbloodVolumeWithBusConnector$PdesiredStressedVolume$Py = ($PmodelInputsBlock1$PTotalBloodVolume$Pk - $PmodelInputsBlock1$PTotalUnstressedVolume$Pk);
}
/*
 equation index: 486
 type: SIMPLE_ASSIGN
 heartElasticitiesBurkhoffWithBusConnector._heartInterval1._AVDelaySec = 0.001 * modelInputsBlock1.AVDelay.k
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_486(DATA *data)
{
  $PheartElasticitiesBurkhoffWithBusConnector$PheartInterval1$PAVDelaySec = (0.001 * $PmodelInputsBlock1$PAVDelay$Pk);
}
/*
 equation index: 487
 type: SIMPLE_ASSIGN
 heartElasticitiesBurkhoffWithBusConnector._etTimingVentricular._Taums = modelInputsBlock1.TauVentricular.k / 1000.0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_487(DATA *data)
{
  $PheartElasticitiesBurkhoffWithBusConnector$PetTimingVentricular$PTaums = ($PmodelInputsBlock1$PTauVentricular$Pk / 1000.0);
}
/*
 equation index: 488
 type: SIMPLE_ASSIGN
 heartElasticitiesBurkhoffWithBusConnector._etTimingVentricular._Tmaxms = modelInputsBlock1.TmaxVentricular.k / 1000.0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_488(DATA *data)
{
  $PheartElasticitiesBurkhoffWithBusConnector$PetTimingVentricular$PTmaxms = ($PmodelInputsBlock1$PTmaxVentricular$Pk / 1000.0);
}
/*
 equation index: 489
 type: SIMPLE_ASSIGN
 heartElasticitiesBurkhoffWithBusConnector._etTimingAtrial._Taums = modelInputsBlock1.TauAtrial.k / 1000.0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_489(DATA *data)
{
  $PheartElasticitiesBurkhoffWithBusConnector$PetTimingAtrial$PTaums = ($PmodelInputsBlock1$PTauAtrial$Pk / 1000.0);
}
/*
 equation index: 490
 type: SIMPLE_ASSIGN
 heartElasticitiesBurkhoffWithBusConnector._etTimingAtrial._Tmaxms = modelInputsBlock1.TmaxAtrial.k / 1000.0
 */
void HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_490(DATA *data)
{
  $PheartElasticitiesBurkhoffWithBusConnector$PetTimingAtrial$PTmaxms = ($PmodelInputsBlock1$PTmaxAtrial$Pk / 1000.0);
}
int HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_updateBoundParameters(DATA *data)
{
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_485(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_486(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_487(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_488(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_489(data);
  HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_eqFunction_490(data);
  
  return 0;
}

