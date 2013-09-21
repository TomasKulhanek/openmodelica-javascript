/* Simulation code for Modelica.Electrical.Analog.Examples.ChuaCircuit generated by the OpenModelica Compiler 1.9.0 beta4+dev (r17240). */
#define time data->localData[0]->timeValue

/* States */
#define _$PC2$Pv(i) data->localData[i]->realVars[0]
#define _$P$PRE$PC2$Pv(i) $P$PRE$PC2$Pv
#define $PC2$Pv _$PC2$Pv(0)
#define $P$PRE$PC2$Pv data->simulationInfo.realVarsPre[0]
#define $P$ATTRIBUTE$PC2$Pv data->modelData.realVarsData[0].attribute
#define $P$ATTRIBUTE$P$PRE$PC2$Pv $P$ATTRIBUTE$PC2$Pv
#define $PC2$Pv__varInfo data->modelData.realVarsData[0].info
#define $P$PRE$PC2$Pv__varInfo data->modelData.realVarsData[0].info
#define _$PC1$Pv(i) data->localData[i]->realVars[1]
#define _$P$PRE$PC1$Pv(i) $P$PRE$PC1$Pv
#define $PC1$Pv _$PC1$Pv(0)
#define $P$PRE$PC1$Pv data->simulationInfo.realVarsPre[1]
#define $P$ATTRIBUTE$PC1$Pv data->modelData.realVarsData[1].attribute
#define $P$ATTRIBUTE$P$PRE$PC1$Pv $P$ATTRIBUTE$PC1$Pv
#define $PC1$Pv__varInfo data->modelData.realVarsData[1].info
#define $P$PRE$PC1$Pv__varInfo data->modelData.realVarsData[1].info
#define _$PL$Pi(i) data->localData[i]->realVars[2]
#define _$P$PRE$PL$Pi(i) $P$PRE$PL$Pi
#define $PL$Pi _$PL$Pi(0)
#define $P$PRE$PL$Pi data->simulationInfo.realVarsPre[2]
#define $P$ATTRIBUTE$PL$Pi data->modelData.realVarsData[2].attribute
#define $P$ATTRIBUTE$P$PRE$PL$Pi $P$ATTRIBUTE$PL$Pi
#define $PL$Pi__varInfo data->modelData.realVarsData[2].info
#define $P$PRE$PL$Pi__varInfo data->modelData.realVarsData[2].info

/* StatesDerivatives */
#define _$P$DER$PC2$Pv(i) data->localData[i]->realVars[3]
#define _$P$PRE$P$DER$PC2$Pv(i) $P$PRE$P$DER$PC2$Pv
#define $P$DER$PC2$Pv _$P$DER$PC2$Pv(0)
#define $P$PRE$P$DER$PC2$Pv data->simulationInfo.realVarsPre[3]
#define $P$ATTRIBUTE$P$DER$PC2$Pv data->modelData.realVarsData[3].attribute
#define $P$ATTRIBUTE$P$PRE$P$DER$PC2$Pv $P$ATTRIBUTE$P$DER$PC2$Pv
#define $P$DER$PC2$Pv__varInfo data->modelData.realVarsData[3].info
#define $P$PRE$P$DER$PC2$Pv__varInfo data->modelData.realVarsData[3].info
#define _$P$DER$PC1$Pv(i) data->localData[i]->realVars[4]
#define _$P$PRE$P$DER$PC1$Pv(i) $P$PRE$P$DER$PC1$Pv
#define $P$DER$PC1$Pv _$P$DER$PC1$Pv(0)
#define $P$PRE$P$DER$PC1$Pv data->simulationInfo.realVarsPre[4]
#define $P$ATTRIBUTE$P$DER$PC1$Pv data->modelData.realVarsData[4].attribute
#define $P$ATTRIBUTE$P$PRE$P$DER$PC1$Pv $P$ATTRIBUTE$P$DER$PC1$Pv
#define $P$DER$PC1$Pv__varInfo data->modelData.realVarsData[4].info
#define $P$PRE$P$DER$PC1$Pv__varInfo data->modelData.realVarsData[4].info
#define _$P$DER$PL$Pi(i) data->localData[i]->realVars[5]
#define _$P$PRE$P$DER$PL$Pi(i) $P$PRE$P$DER$PL$Pi
#define $P$DER$PL$Pi _$P$DER$PL$Pi(0)
#define $P$PRE$P$DER$PL$Pi data->simulationInfo.realVarsPre[5]
#define $P$ATTRIBUTE$P$DER$PL$Pi data->modelData.realVarsData[5].attribute
#define $P$ATTRIBUTE$P$PRE$P$DER$PL$Pi $P$ATTRIBUTE$P$DER$PL$Pi
#define $P$DER$PL$Pi__varInfo data->modelData.realVarsData[5].info
#define $P$PRE$P$DER$PL$Pi__varInfo data->modelData.realVarsData[5].info

/* InlineSolver Vars */

/* Algebraic Vars */
#define _$PGnd$Pp$Pi(i) data->localData[i]->realVars[6]
#define _$P$PRE$PGnd$Pp$Pi(i) $P$PRE$PGnd$Pp$Pi
#define $PGnd$Pp$Pi _$PGnd$Pp$Pi(0)
#define $P$PRE$PGnd$Pp$Pi data->simulationInfo.realVarsPre[6]
#define $P$ATTRIBUTE$PGnd$Pp$Pi data->modelData.realVarsData[6].attribute
#define $P$ATTRIBUTE$P$PRE$PGnd$Pp$Pi $P$ATTRIBUTE$PGnd$Pp$Pi
#define $PGnd$Pp$Pi__varInfo data->modelData.realVarsData[6].info
#define $P$PRE$PGnd$Pp$Pi__varInfo data->modelData.realVarsData[6].info
#define _$PNr$Pi(i) data->localData[i]->realVars[7]
#define _$P$PRE$PNr$Pi(i) $P$PRE$PNr$Pi
#define $PNr$Pi _$PNr$Pi(0)
#define $P$PRE$PNr$Pi data->simulationInfo.realVarsPre[7]
#define $P$ATTRIBUTE$PNr$Pi data->modelData.realVarsData[7].attribute
#define $P$ATTRIBUTE$P$PRE$PNr$Pi $P$ATTRIBUTE$PNr$Pi
#define $PNr$Pi__varInfo data->modelData.realVarsData[7].info
#define $P$PRE$PNr$Pi__varInfo data->modelData.realVarsData[7].info
#define _$PC2$Pi(i) data->localData[i]->realVars[8]
#define _$P$PRE$PC2$Pi(i) $P$PRE$PC2$Pi
#define $PC2$Pi _$PC2$Pi(0)
#define $P$PRE$PC2$Pi data->simulationInfo.realVarsPre[8]
#define $P$ATTRIBUTE$PC2$Pi data->modelData.realVarsData[8].attribute
#define $P$ATTRIBUTE$P$PRE$PC2$Pi $P$ATTRIBUTE$PC2$Pi
#define $PC2$Pi__varInfo data->modelData.realVarsData[8].info
#define $P$PRE$PC2$Pi__varInfo data->modelData.realVarsData[8].info
#define _$PC1$Pi(i) data->localData[i]->realVars[9]
#define _$P$PRE$PC1$Pi(i) $P$PRE$PC1$Pi
#define $PC1$Pi _$PC1$Pi(0)
#define $P$PRE$PC1$Pi data->simulationInfo.realVarsPre[9]
#define $P$ATTRIBUTE$PC1$Pi data->modelData.realVarsData[9].attribute
#define $P$ATTRIBUTE$P$PRE$PC1$Pi $P$ATTRIBUTE$PC1$Pi
#define $PC1$Pi__varInfo data->modelData.realVarsData[9].info
#define $P$PRE$PC1$Pi__varInfo data->modelData.realVarsData[9].info
#define _$PG$PLossPower(i) data->localData[i]->realVars[10]
#define _$P$PRE$PG$PLossPower(i) $P$PRE$PG$PLossPower
#define $PG$PLossPower _$PG$PLossPower(0)
#define $P$PRE$PG$PLossPower data->simulationInfo.realVarsPre[10]
#define $P$ATTRIBUTE$PG$PLossPower data->modelData.realVarsData[10].attribute
#define $P$ATTRIBUTE$P$PRE$PG$PLossPower $P$ATTRIBUTE$PG$PLossPower
#define $PG$PLossPower__varInfo data->modelData.realVarsData[10].info
#define $P$PRE$PG$PLossPower__varInfo data->modelData.realVarsData[10].info
#define _$PG$Pi(i) data->localData[i]->realVars[11]
#define _$P$PRE$PG$Pi(i) $P$PRE$PG$Pi
#define $PG$Pi _$PG$Pi(0)
#define $P$PRE$PG$Pi data->simulationInfo.realVarsPre[11]
#define $P$ATTRIBUTE$PG$Pi data->modelData.realVarsData[11].attribute
#define $P$ATTRIBUTE$P$PRE$PG$Pi $P$ATTRIBUTE$PG$Pi
#define $PG$Pi__varInfo data->modelData.realVarsData[11].info
#define $P$PRE$PG$Pi__varInfo data->modelData.realVarsData[11].info
#define _$PG$Pv(i) data->localData[i]->realVars[12]
#define _$P$PRE$PG$Pv(i) $P$PRE$PG$Pv
#define $PG$Pv _$PG$Pv(0)
#define $P$PRE$PG$Pv data->simulationInfo.realVarsPre[12]
#define $P$ATTRIBUTE$PG$Pv data->modelData.realVarsData[12].attribute
#define $P$ATTRIBUTE$P$PRE$PG$Pv $P$ATTRIBUTE$PG$Pv
#define $PG$Pv__varInfo data->modelData.realVarsData[12].info
#define $P$PRE$PG$Pv__varInfo data->modelData.realVarsData[12].info
#define _$PRo$PLossPower(i) data->localData[i]->realVars[13]
#define _$P$PRE$PRo$PLossPower(i) $P$PRE$PRo$PLossPower
#define $PRo$PLossPower _$PRo$PLossPower(0)
#define $P$PRE$PRo$PLossPower data->simulationInfo.realVarsPre[13]
#define $P$ATTRIBUTE$PRo$PLossPower data->modelData.realVarsData[13].attribute
#define $P$ATTRIBUTE$P$PRE$PRo$PLossPower $P$ATTRIBUTE$PRo$PLossPower
#define $PRo$PLossPower__varInfo data->modelData.realVarsData[13].info
#define $P$PRE$PRo$PLossPower__varInfo data->modelData.realVarsData[13].info
#define _$PRo$Pv(i) data->localData[i]->realVars[14]
#define _$P$PRE$PRo$Pv(i) $P$PRE$PRo$Pv
#define $PRo$Pv _$PRo$Pv(0)
#define $P$PRE$PRo$Pv data->simulationInfo.realVarsPre[14]
#define $P$ATTRIBUTE$PRo$Pv data->modelData.realVarsData[14].attribute
#define $P$ATTRIBUTE$P$PRE$PRo$Pv $P$ATTRIBUTE$PRo$Pv
#define $PRo$Pv__varInfo data->modelData.realVarsData[14].info
#define $P$PRE$PRo$Pv__varInfo data->modelData.realVarsData[14].info
#define _$PL$Pv(i) data->localData[i]->realVars[15]
#define _$P$PRE$PL$Pv(i) $P$PRE$PL$Pv
#define $PL$Pv _$PL$Pv(0)
#define $P$PRE$PL$Pv data->simulationInfo.realVarsPre[15]
#define $P$ATTRIBUTE$PL$Pv data->modelData.realVarsData[15].attribute
#define $P$ATTRIBUTE$P$PRE$PL$Pv $P$ATTRIBUTE$PL$Pv
#define $PL$Pv__varInfo data->modelData.realVarsData[15].info
#define $P$PRE$PL$Pv__varInfo data->modelData.realVarsData[15].info
#define _$PG$PG_actual(i) data->localData[i]->realVars[16]
#define _$P$PRE$PG$PG_actual(i) $P$PRE$PG$PG_actual
#define $PG$PG_actual _$PG$PG_actual(0)
#define $P$PRE$PG$PG_actual data->simulationInfo.realVarsPre[16]
#define $P$ATTRIBUTE$PG$PG_actual data->modelData.realVarsData[16].attribute
#define $P$ATTRIBUTE$P$PRE$PG$PG_actual $P$ATTRIBUTE$PG$PG_actual
#define $PG$PG_actual__varInfo data->modelData.realVarsData[16].info
#define $P$PRE$PG$PG_actual__varInfo data->modelData.realVarsData[16].info
#define _$PRo$PR_actual(i) data->localData[i]->realVars[17]
#define _$P$PRE$PRo$PR_actual(i) $P$PRE$PRo$PR_actual
#define $PRo$PR_actual _$PRo$PR_actual(0)
#define $P$PRE$PRo$PR_actual data->simulationInfo.realVarsPre[17]
#define $P$ATTRIBUTE$PRo$PR_actual data->modelData.realVarsData[17].attribute
#define $P$ATTRIBUTE$P$PRE$PRo$PR_actual $P$ATTRIBUTE$PRo$PR_actual
#define $PRo$PR_actual__varInfo data->modelData.realVarsData[17].info
#define $P$PRE$PRo$PR_actual__varInfo data->modelData.realVarsData[17].info
#define _$PGnd$Pp$Pv(i) data->localData[i]->realVars[18]
#define _$P$PRE$PGnd$Pp$Pv(i) $P$PRE$PGnd$Pp$Pv
#define $PGnd$Pp$Pv _$PGnd$Pp$Pv(0)
#define $P$PRE$PGnd$Pp$Pv data->simulationInfo.realVarsPre[18]
#define $P$ATTRIBUTE$PGnd$Pp$Pv data->modelData.realVarsData[18].attribute
#define $P$ATTRIBUTE$P$PRE$PGnd$Pp$Pv $P$ATTRIBUTE$PGnd$Pp$Pv
#define $PGnd$Pp$Pv__varInfo data->modelData.realVarsData[18].info
#define $P$PRE$PGnd$Pp$Pv__varInfo data->modelData.realVarsData[18].info

/* Algebraic Parameter */
#define $PL$PL data->simulationInfo.realParameter[0]
#define _$PL$PL(i) $PL$PL
#define $P$ATTRIBUTE$PL$PL data->modelData.realParameterData[0].attribute
#define $P$ATTRIBUTE$P$PRE$PL$PL $P$ATTRIBUTE$PL$PL
#define $PL$PL__varInfo data->modelData.realParameterData[0].info
#define $PRo$PT data->simulationInfo.realParameter[1]
#define _$PRo$PT(i) $PRo$PT
#define $P$ATTRIBUTE$PRo$PT data->modelData.realParameterData[1].attribute
#define $P$ATTRIBUTE$P$PRE$PRo$PT $P$ATTRIBUTE$PRo$PT
#define $PRo$PT__varInfo data->modelData.realParameterData[1].info
#define $PRo$PR data->simulationInfo.realParameter[2]
#define _$PRo$PR(i) $PRo$PR
#define $P$ATTRIBUTE$PRo$PR data->modelData.realParameterData[2].attribute
#define $P$ATTRIBUTE$P$PRE$PRo$PR $P$ATTRIBUTE$PRo$PR
#define $PRo$PR__varInfo data->modelData.realParameterData[2].info
#define $PRo$PT_ref data->simulationInfo.realParameter[3]
#define _$PRo$PT_ref(i) $PRo$PT_ref
#define $P$ATTRIBUTE$PRo$PT_ref data->modelData.realParameterData[3].attribute
#define $P$ATTRIBUTE$P$PRE$PRo$PT_ref $P$ATTRIBUTE$PRo$PT_ref
#define $PRo$PT_ref__varInfo data->modelData.realParameterData[3].info
#define $PRo$Palpha data->simulationInfo.realParameter[4]
#define _$PRo$Palpha(i) $PRo$Palpha
#define $P$ATTRIBUTE$PRo$Palpha data->modelData.realParameterData[4].attribute
#define $P$ATTRIBUTE$P$PRE$PRo$Palpha $P$ATTRIBUTE$PRo$Palpha
#define $PRo$Palpha__varInfo data->modelData.realParameterData[4].info
#define $PG$PT data->simulationInfo.realParameter[5]
#define _$PG$PT(i) $PG$PT
#define $P$ATTRIBUTE$PG$PT data->modelData.realParameterData[5].attribute
#define $P$ATTRIBUTE$P$PRE$PG$PT $P$ATTRIBUTE$PG$PT
#define $PG$PT__varInfo data->modelData.realParameterData[5].info
#define $PG$PG data->simulationInfo.realParameter[6]
#define _$PG$PG(i) $PG$PG
#define $P$ATTRIBUTE$PG$PG data->modelData.realParameterData[6].attribute
#define $P$ATTRIBUTE$P$PRE$PG$PG $P$ATTRIBUTE$PG$PG
#define $PG$PG__varInfo data->modelData.realParameterData[6].info
#define $PG$PT_ref data->simulationInfo.realParameter[7]
#define _$PG$PT_ref(i) $PG$PT_ref
#define $P$ATTRIBUTE$PG$PT_ref data->modelData.realParameterData[7].attribute
#define $P$ATTRIBUTE$P$PRE$PG$PT_ref $P$ATTRIBUTE$PG$PT_ref
#define $PG$PT_ref__varInfo data->modelData.realParameterData[7].info
#define $PG$Palpha data->simulationInfo.realParameter[8]
#define _$PG$Palpha(i) $PG$Palpha
#define $P$ATTRIBUTE$PG$Palpha data->modelData.realParameterData[8].attribute
#define $P$ATTRIBUTE$P$PRE$PG$Palpha $P$ATTRIBUTE$PG$Palpha
#define $PG$Palpha__varInfo data->modelData.realParameterData[8].info
#define $PC1$PC data->simulationInfo.realParameter[9]
#define _$PC1$PC(i) $PC1$PC
#define $P$ATTRIBUTE$PC1$PC data->modelData.realParameterData[9].attribute
#define $P$ATTRIBUTE$P$PRE$PC1$PC $P$ATTRIBUTE$PC1$PC
#define $PC1$PC__varInfo data->modelData.realParameterData[9].info
#define $PC2$PC data->simulationInfo.realParameter[10]
#define _$PC2$PC(i) $PC2$PC
#define $P$ATTRIBUTE$PC2$PC data->modelData.realParameterData[10].attribute
#define $P$ATTRIBUTE$P$PRE$PC2$PC $P$ATTRIBUTE$PC2$PC
#define $PC2$PC__varInfo data->modelData.realParameterData[10].info
#define $PNr$PGa data->simulationInfo.realParameter[11]
#define _$PNr$PGa(i) $PNr$PGa
#define $P$ATTRIBUTE$PNr$PGa data->modelData.realParameterData[11].attribute
#define $P$ATTRIBUTE$P$PRE$PNr$PGa $P$ATTRIBUTE$PNr$PGa
#define $PNr$PGa__varInfo data->modelData.realParameterData[11].info
#define $PNr$PGb data->simulationInfo.realParameter[12]
#define _$PNr$PGb(i) $PNr$PGb
#define $P$ATTRIBUTE$PNr$PGb data->modelData.realParameterData[12].attribute
#define $P$ATTRIBUTE$P$PRE$PNr$PGb $P$ATTRIBUTE$PNr$PGb
#define $PNr$PGb__varInfo data->modelData.realParameterData[12].info
#define $PNr$PVe data->simulationInfo.realParameter[13]
#define _$PNr$PVe(i) $PNr$PVe
#define $P$ATTRIBUTE$PNr$PVe data->modelData.realParameterData[13].attribute
#define $P$ATTRIBUTE$P$PRE$PNr$PVe $P$ATTRIBUTE$PNr$PVe
#define $PNr$PVe__varInfo data->modelData.realParameterData[13].info

/* External Objects */

/* Algebraic Integer Vars */

/* Algebraic Integer Parameter */

/* Algebraic Boolean Vars */

/* Algebraic Boolean Parameters */
#define $PRo$PuseHeatPort data->simulationInfo.booleanParameter[0]
#define _$PRo$PuseHeatPort(i) $PRo$PuseHeatPort
#define $P$ATTRIBUTE$PRo$PuseHeatPort data->modelData.booleanParameterData[0].attribute
#define $P$ATTRIBUTE$P$PRE$PRo$PuseHeatPort $P$ATTRIBUTE$PRo$PuseHeatPort
#define $PRo$PuseHeatPort__varInfo data->modelData.booleanParameterData[0].info
#define $PG$PuseHeatPort data->simulationInfo.booleanParameter[1]
#define _$PG$PuseHeatPort(i) $PG$PuseHeatPort
#define $P$ATTRIBUTE$PG$PuseHeatPort data->modelData.booleanParameterData[1].attribute
#define $P$ATTRIBUTE$P$PRE$PG$PuseHeatPort $P$ATTRIBUTE$PG$PuseHeatPort
#define $PG$PuseHeatPort__varInfo data->modelData.booleanParameterData[1].info

/* Algebraic String Variables */

/* Algebraic String Parameter */

/* sample */

/* Jacobian Variables */
#if defined(_MSC_VER)
extern "C" {
#endif
  const int INDEX_JAC_G = 0;
  int functionJacG_column(void* data);
  int initialAnalyticJacobianG(void* data);
#if defined(_MSC_VER)
}
#endif
/* G */
/* G sparse indexes */

#if defined(_MSC_VER)
extern "C" {
#endif
  const int INDEX_JAC_A = 1;
  int functionJacA_column(void* data);
  int initialAnalyticJacobianA(void* data);
#if defined(_MSC_VER)
}
#endif
/* A */
#define $PC2$Pv$pDERA$PC2$Pv data->simulationInfo.analyticJacobians[1].seedVars[0]
#define $PC2$Pv$pDERA$PC2$Pv__varInfo dummyVAR_INFO
#define $PC1$Pv$pDERA$PC1$Pv data->simulationInfo.analyticJacobians[1].seedVars[1]
#define $PC1$Pv$pDERA$PC1$Pv__varInfo dummyVAR_INFO
#define $PL$Pi$pDERA$PL$Pi data->simulationInfo.analyticJacobians[1].seedVars[2]
#define $PL$Pi$pDERA$PL$Pi__varInfo dummyVAR_INFO
/* A sparse indexes */
#define $PC2$Pv$pDERA$indexdiff 0
#define $PC1$Pv$pDERA$indexdiff 1
#define $PL$Pi$pDERA$indexdiff 2
#define $PC2$Pv$pDERA$indexdiffed 0
#define $PC1$Pv$pDERA$indexdiffed 1
#define $PL$Pi$pDERA$indexdiffed 2
#if defined(_MSC_VER)
extern "C" {
#endif
  const int INDEX_JAC_B = 2;
  int functionJacB_column(void* data);
  int initialAnalyticJacobianB(void* data);
#if defined(_MSC_VER)
}
#endif
/* B */
/* B sparse indexes */

#if defined(_MSC_VER)
extern "C" {
#endif
  const int INDEX_JAC_C = 3;
  int functionJacC_column(void* data);
  int initialAnalyticJacobianC(void* data);
#if defined(_MSC_VER)
}
#endif
/* C */
/* C sparse indexes */

#if defined(_MSC_VER)
extern "C" {
#endif
  const int INDEX_JAC_D = 4;
  int functionJacD_column(void* data);
  int initialAnalyticJacobianD(void* data);
#if defined(_MSC_VER)
}
#endif
/* D */
/* D sparse indexes */


