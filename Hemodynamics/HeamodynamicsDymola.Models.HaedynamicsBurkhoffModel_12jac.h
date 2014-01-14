/* Jacobians */
/* Jacobian Variables */
#if defined(_MSC_VER)
extern "C" {
#endif
  #define HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_INDEX_JAC_G 0
  int HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_functionJacG_column(void* data);
  int HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_initialAnalyticJacobianG(void* data);
#if defined(_MSC_VER)
}
#endif
/* G */
/* G sparse indexes */

#if defined(_MSC_VER)
extern "C" {
#endif
  #define HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_INDEX_JAC_A 1
  int HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_functionJacA_column(void* data);
  int HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_initialAnalyticJacobianA(void* data);
#if defined(_MSC_VER)
}
#endif
/* A */
#define $PMeasurementCentralVeins$PpressureFlowMeasurement$PSumPressure$pDERA$PMeasurementCentralVeins$PpressureFlowMeasurement$PSumPressure data->simulationInfo.analyticJacobians[1].seedVars[0]
#define $PMeasurementCentralVeins$PpressureFlowMeasurement$PSumPressure$pDERA$PMeasurementCentralVeins$PpressureFlowMeasurement$PSumPressure__varInfo dummyVAR_INFO
#define $PMeasurementCentralVeins$PpressureFlowMeasurement$PVolume$pDERA$PMeasurementCentralVeins$PpressureFlowMeasurement$PVolume data->simulationInfo.analyticJacobians[1].seedVars[1]
#define $PMeasurementCentralVeins$PpressureFlowMeasurement$PVolume$pDERA$PMeasurementCentralVeins$PpressureFlowMeasurement$PVolume__varInfo dummyVAR_INFO
#define $PMeasurementAorta$PpressureFlowMeasurement$PSumPressure$pDERA$PMeasurementAorta$PpressureFlowMeasurement$PSumPressure data->simulationInfo.analyticJacobians[1].seedVars[2]
#define $PMeasurementAorta$PpressureFlowMeasurement$PSumPressure$pDERA$PMeasurementAorta$PpressureFlowMeasurement$PSumPressure__varInfo dummyVAR_INFO
#define $PMeasurementAorta$PpressureFlowMeasurement$PVolume$pDERA$PMeasurementAorta$PpressureFlowMeasurement$PVolume data->simulationInfo.analyticJacobians[1].seedVars[3]
#define $PMeasurementAorta$PpressureFlowMeasurement$PVolume$pDERA$PMeasurementAorta$PpressureFlowMeasurement$PVolume__varInfo dummyVAR_INFO
#define $PMeasurementPulmonaryVeins$PpressureFlowMeasurement$PSumPressure$pDERA$PMeasurementPulmonaryVeins$PpressureFlowMeasurement$PSumPressure data->simulationInfo.analyticJacobians[1].seedVars[4]
#define $PMeasurementPulmonaryVeins$PpressureFlowMeasurement$PSumPressure$pDERA$PMeasurementPulmonaryVeins$PpressureFlowMeasurement$PSumPressure__varInfo dummyVAR_INFO
#define $PMeasurementPulmonaryVeins$PpressureFlowMeasurement$PVolume$pDERA$PMeasurementPulmonaryVeins$PpressureFlowMeasurement$PVolume data->simulationInfo.analyticJacobians[1].seedVars[5]
#define $PMeasurementPulmonaryVeins$PpressureFlowMeasurement$PVolume$pDERA$PMeasurementPulmonaryVeins$PpressureFlowMeasurement$PVolume__varInfo dummyVAR_INFO
#define $PMeasurementPulmonaryArtery$PpressureFlowMeasurement$PSumPressure$pDERA$PMeasurementPulmonaryArtery$PpressureFlowMeasurement$PSumPressure data->simulationInfo.analyticJacobians[1].seedVars[6]
#define $PMeasurementPulmonaryArtery$PpressureFlowMeasurement$PSumPressure$pDERA$PMeasurementPulmonaryArtery$PpressureFlowMeasurement$PSumPressure__varInfo dummyVAR_INFO
#define $PMeasurementPulmonaryArtery$PpressureFlowMeasurement$PVolume$pDERA$PMeasurementPulmonaryArtery$PpressureFlowMeasurement$PVolume data->simulationInfo.analyticJacobians[1].seedVars[7]
#define $PMeasurementPulmonaryArtery$PpressureFlowMeasurement$PVolume$pDERA$PMeasurementPulmonaryArtery$PpressureFlowMeasurement$PVolume__varInfo dummyVAR_INFO
#define $PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PVolume$pDERA$PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PVolume data->simulationInfo.analyticJacobians[1].seedVars[8]
#define $PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PVolume$pDERA$PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PVolume__varInfo dummyVAR_INFO
#define $PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PVolume$pDERA$PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PVolume data->simulationInfo.analyticJacobians[1].seedVars[9]
#define $PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PVolume$pDERA$PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PVolume__varInfo dummyVAR_INFO
#define $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PVolume$pDERA$PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PVolume data->simulationInfo.analyticJacobians[1].seedVars[10]
#define $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PVolume$pDERA$PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PVolume__varInfo dummyVAR_INFO
#define $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PVolume$pDERA$PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PVolume data->simulationInfo.analyticJacobians[1].seedVars[11]
#define $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PVolume$pDERA$PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PVolume__varInfo dummyVAR_INFO
#define $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PVolume$pDERA$PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PVolume data->simulationInfo.analyticJacobians[1].seedVars[12]
#define $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PVolume$pDERA$PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PVolume__varInfo dummyVAR_INFO
#define $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PVolume$pDERA$PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PVolume data->simulationInfo.analyticJacobians[1].seedVars[13]
#define $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PVolume$pDERA$PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PVolume__varInfo dummyVAR_INFO
#define $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PVolume$pDERA$PleftHeartBurkhofWithBusConnector$PLeftVentricle$PVolume data->simulationInfo.analyticJacobians[1].seedVars[14]
#define $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PVolume$pDERA$PleftHeartBurkhofWithBusConnector$PLeftVentricle$PVolume__varInfo dummyVAR_INFO
#define $PleftHeartBurkhofWithBusConnector$PLeftAtrium$PVolume$pDERA$PleftHeartBurkhofWithBusConnector$PLeftAtrium$PVolume data->simulationInfo.analyticJacobians[1].seedVars[15]
#define $PleftHeartBurkhofWithBusConnector$PLeftAtrium$PVolume$pDERA$PleftHeartBurkhofWithBusConnector$PLeftAtrium$PVolume__varInfo dummyVAR_INFO
#define $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PVolume$pDERA$PrightHeartBurkhoffWithBusConnector$PRightVentricle$PVolume data->simulationInfo.analyticJacobians[1].seedVars[16]
#define $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PVolume$pDERA$PrightHeartBurkhoffWithBusConnector$PRightVentricle$PVolume__varInfo dummyVAR_INFO
#define $PrightHeartBurkhoffWithBusConnector$PRightAtrium$PVolume$pDERA$PrightHeartBurkhoffWithBusConnector$PRightAtrium$PVolume data->simulationInfo.analyticJacobians[1].seedVars[17]
#define $PrightHeartBurkhoffWithBusConnector$PRightAtrium$PVolume$pDERA$PrightHeartBurkhoffWithBusConnector$PRightAtrium$PVolume__varInfo dummyVAR_INFO
/* A sparse indexes */
#define $PMeasurementCentralVeins$PpressureFlowMeasurement$PSumPressure$pDERA$indexdiff 0
#define $PMeasurementCentralVeins$PpressureFlowMeasurement$PVolume$pDERA$indexdiff 1
#define $PMeasurementAorta$PpressureFlowMeasurement$PSumPressure$pDERA$indexdiff 2
#define $PMeasurementAorta$PpressureFlowMeasurement$PVolume$pDERA$indexdiff 3
#define $PMeasurementPulmonaryVeins$PpressureFlowMeasurement$PSumPressure$pDERA$indexdiff 4
#define $PMeasurementPulmonaryVeins$PpressureFlowMeasurement$PVolume$pDERA$indexdiff 5
#define $PMeasurementPulmonaryArtery$PpressureFlowMeasurement$PSumPressure$pDERA$indexdiff 6
#define $PMeasurementPulmonaryArtery$PpressureFlowMeasurement$PVolume$pDERA$indexdiff 7
#define $PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PVolume$pDERA$indexdiff 8
#define $PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PVolume$pDERA$indexdiff 9
#define $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PVolume$pDERA$indexdiff 10
#define $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PVolume$pDERA$indexdiff 11
#define $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PVolume$pDERA$indexdiff 12
#define $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PVolume$pDERA$indexdiff 13
#define $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PVolume$pDERA$indexdiff 14
#define $PleftHeartBurkhofWithBusConnector$PLeftAtrium$PVolume$pDERA$indexdiff 15
#define $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PVolume$pDERA$indexdiff 16
#define $PrightHeartBurkhoffWithBusConnector$PRightAtrium$PVolume$pDERA$indexdiff 17
#define $PMeasurementCentralVeins$PpressureFlowMeasurement$PSumPressure$pDERA$indexdiffed 0
#define $PMeasurementCentralVeins$PpressureFlowMeasurement$PVolume$pDERA$indexdiffed 1
#define $PMeasurementAorta$PpressureFlowMeasurement$PSumPressure$pDERA$indexdiffed 2
#define $PMeasurementAorta$PpressureFlowMeasurement$PVolume$pDERA$indexdiffed 3
#define $PMeasurementPulmonaryVeins$PpressureFlowMeasurement$PSumPressure$pDERA$indexdiffed 4
#define $PMeasurementPulmonaryVeins$PpressureFlowMeasurement$PVolume$pDERA$indexdiffed 5
#define $PMeasurementPulmonaryArtery$PpressureFlowMeasurement$PSumPressure$pDERA$indexdiffed 6
#define $PMeasurementPulmonaryArtery$PpressureFlowMeasurement$PVolume$pDERA$indexdiffed 7
#define $PsystemicCirculationBurkhoffWithBusConnector$PSystemicVeins$PVolume$pDERA$indexdiffed 8
#define $PsystemicCirculationBurkhoffWithBusConnector$PSystemicArteries$PVolume$pDERA$indexdiffed 9
#define $PsystemicCirculationBurkhoffWithBusConnector$PAortaProximal$PVolume$pDERA$indexdiffed 10
#define $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryVeins$PVolume$pDERA$indexdiffed 11
#define $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArtery$PVolume$pDERA$indexdiffed 12
#define $PpulmonaryCirculationBurkhoffWithBusConnector$PPulmonaryArteryProximal$PVolume$pDERA$indexdiffed 13
#define $PleftHeartBurkhofWithBusConnector$PLeftVentricle$PVolume$pDERA$indexdiffed 14
#define $PleftHeartBurkhofWithBusConnector$PLeftAtrium$PVolume$pDERA$indexdiffed 15
#define $PrightHeartBurkhoffWithBusConnector$PRightVentricle$PVolume$pDERA$indexdiffed 16
#define $PrightHeartBurkhoffWithBusConnector$PRightAtrium$PVolume$pDERA$indexdiffed 17
#if defined(_MSC_VER)
extern "C" {
#endif
  #define HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_INDEX_JAC_B 2
  int HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_functionJacB_column(void* data);
  int HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_initialAnalyticJacobianB(void* data);
#if defined(_MSC_VER)
}
#endif
/* B */
/* B sparse indexes */

#if defined(_MSC_VER)
extern "C" {
#endif
  #define HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_INDEX_JAC_C 3
  int HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_functionJacC_column(void* data);
  int HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_initialAnalyticJacobianC(void* data);
#if defined(_MSC_VER)
}
#endif
/* C */
/* C sparse indexes */

#if defined(_MSC_VER)
extern "C" {
#endif
  #define HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_INDEX_JAC_D 4
  int HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_functionJacD_column(void* data);
  int HeamodynamicsDymola_Models_HaedynamicsBurkhoffModel_initialAnalyticJacobianD(void* data);
#if defined(_MSC_VER)
}
#endif
/* D */
/* D sparse indexes */


