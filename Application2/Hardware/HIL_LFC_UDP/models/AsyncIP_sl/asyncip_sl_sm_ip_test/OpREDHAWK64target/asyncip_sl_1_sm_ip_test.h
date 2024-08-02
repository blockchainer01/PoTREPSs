/*
 * asyncip_sl_1_sm_ip_test.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "asyncip_sl_1_sm_ip_test".
 *
 * Model version              : 13.22
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Jun 20 21:08:01 2024
 *
 * Target selection: rtlab_rtmodel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_asyncip_sl_1_sm_ip_test_h_
#define RTW_HEADER_asyncip_sl_1_sm_ip_test_h_
#include <stddef.h>
#include <string.h>
#ifndef asyncip_sl_1_sm_ip_test_COMMON_INCLUDES_
#define asyncip_sl_1_sm_ip_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                            /* asyncip_sl_1_sm_ip_test_COMMON_INCLUDES_ */

#include "asyncip_sl_1_sm_ip_test_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->ModelData.CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->ModelData.CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define asyncip_sl_1_sm_ip_test_rtModel RT_MODEL_asyncip_sl_1_sm_ip_test_T

/* user code (top of header file) */
/* System '<Root>' */
/* Opal-RT Technologies */
extern int opalSizeDwork;
extern unsigned int opalSizeBlockIO;
extern unsigned int opalSizeRTP;
extern void * pRtModel;                //pointer on the RTmodel struc
int_T Opal_rtmGetNumBlockParams(void *ptr);
int_T Opal_rtmGetNumBlockIO(void *ptr);

/* Block signals (default storage) */
typedef struct {
  real_T SFunction;                    /* '<S1>/S-Function' (Output 1)  */
  real_T Sum;                          /* '<S1>/Sum' (Output 1)  */
  real_T Constant;                     /* '<S2>/Constant' (Output 1)  */
  real_T Integrator[4];                /* '<S2>/Integrator' (Output 1)  */
  real_T ZeroOrderHold17[4];          /* '<S2>/Zero-Order Hold17' (Output 1)  */
  real_T Integrator1[4];               /* '<S2>/Integrator1' (Output 1)  */
  real_T ZeroOrderHold1[4];            /* '<S2>/Zero-Order Hold1' (Output 1)  */
  real_T Integrator2[4];               /* '<S2>/Integrator2' (Output 1)  */
  real_T ZeroOrderHold2[4];            /* '<S2>/Zero-Order Hold2' (Output 1)  */
  real_T SFunction2;                   /* '<S7>/S-Function2' (Output 1)  */
  real_T timeout;                      /* '<S2>/timeout' (Output 1)  */
  real_T SFunction1_o1;                /* '<S5>/S-Function1' (Output 1)  */
  real_T SFunction1_o2;                /* '<S5>/S-Function1' (Output 2)  */
  real_T SFunction1_o3[3];             /* '<S5>/S-Function1' (Output 3)  */
  real_T Clock;                        /* '<S2>/Clock' (Output 1)  */
  real_T TmpSignalConversionAtIntegrator[4];
                           /* '<S2>/TmpSignal ConversionAtIntegrator1Inport1' */
  real_T TmpSignalConversionAtIntegrat_n[4];
                           /* '<S2>/TmpSignal ConversionAtIntegrator2Inport1' */
  real_T TmpSignalConversionAtIntegrat_p[4];
                            /* '<S2>/TmpSignal ConversionAtIntegratorInport1' */
  real_T dx1_1;                        /* '<S2>/MATLAB Function1' (Output 1)  */
  real_T dx1_2;                        /* '<S2>/MATLAB Function1' (Output 2)  */
  real_T dx1_3;                        /* '<S2>/MATLAB Function1' (Output 3)  */
  real_T dx1_4;                        /* '<S2>/MATLAB Function1' (Output 4)  */
  real_T dx2_1;                        /* '<S2>/MATLAB Function1' (Output 5)  */
  real_T dx2_2;                        /* '<S2>/MATLAB Function1' (Output 6)  */
  real_T dx2_3;                        /* '<S2>/MATLAB Function1' (Output 7)  */
  real_T dx2_4;                        /* '<S2>/MATLAB Function1' (Output 8)  */
  real_T dx3_1;                        /* '<S2>/MATLAB Function1' (Output 9)  */
  real_T dx3_2;                       /* '<S2>/MATLAB Function1' (Output 10)  */
  real_T dx3_3;                       /* '<S2>/MATLAB Function1' (Output 11)  */
  real_T dx3_4;                       /* '<S2>/MATLAB Function1' (Output 12)  */
  real_T deltaPL[3];                   /* '<S2>/Load increase' (Output 1)  */
} B_asyncip_sl_1_sm_ip_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SFunction_PreviousInput;      /* '<S1>/S-Function' (DWork 1)  */
  void *SFunction2_PWORK;              /* '<S7>/S-Function2' (DWork 1)  */
  void *SFunction1_PWORK;              /* '<S5>/S-Function1' (DWork 1)  */
  void *OpIPSocketCtrl1_PWORK;         /* '<S2>/OpIPSocketCtrl1' (DWork 1)  */
  int_T SFunction_IWORK[5];            /* '<S9>/S-Function' (DWork 1)  */
} DW_asyncip_sl_1_sm_ip_test_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<S2>/Integrator' */
  real_T Integrator1_CSTATE[4];        /* '<S2>/Integrator1' */
  real_T Integrator2_CSTATE[4];        /* '<S2>/Integrator2' */
} X_asyncip_sl_1_sm_ip_test_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<S2>/Integrator' */
  real_T Integrator1_CSTATE[4];        /* '<S2>/Integrator1' */
  real_T Integrator2_CSTATE[4];        /* '<S2>/Integrator2' */
} XDot_asyncip_sl_1_sm_ip_test_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[4];      /* '<S2>/Integrator' */
  boolean_T Integrator1_CSTATE[4];     /* '<S2>/Integrator1' */
  boolean_T Integrator2_CSTATE[4];     /* '<S2>/Integrator2' */
} XDis_asyncip_sl_1_sm_ip_test_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            asyncip_sl_1_sm_ip_test_B
#define BlockIO                        B_asyncip_sl_1_sm_ip_test_T
#define rtX                            asyncip_sl_1_sm_ip_test_X
#define ContinuousStates               X_asyncip_sl_1_sm_ip_test_T
#define rtXdot                         asyncip_sl_1_sm_ip_test_XDot
#define StateDerivatives               XDot_asyncip_sl_1_sm_ip_test_T
#define tXdis                          asyncip_sl_1_sm_ip_test_XDis
#define StateDisabled                  XDis_asyncip_sl_1_sm_ip_test_T
#define rtP                            asyncip_sl_1_sm_ip_test_P
#define Parameters                     P_asyncip_sl_1_sm_ip_test_T
#define rtDWork                        asyncip_sl_1_sm_ip_test_DW
#define D_Work                         DW_asyncip_sl_1_sm_ip_test_T

/* Parameters (default storage) */
struct P_asyncip_sl_1_sm_ip_test_T_ {
  real_T SFunction1_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/S-Function1' (Parameter: Value)
                                        */
  real_T SFunction_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S1>/S-Function' (Parameter: InitialCondition)
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S2>/Constant' (Parameter: Value)
                                        */
  real_T Integrator_IC[4];             /* Expression: zeros(4,1)
                                        * Referenced by: '<S2>/Integrator' (Parameter: InitialCondition)
                                        */
  real_T Integrator1_IC[4];            /* Expression: zeros(4,1)
                                        * Referenced by: '<S2>/Integrator1' (Parameter: InitialCondition)
                                        */
  real_T Integrator2_IC[4];            /* Expression: zeros(4,1)
                                        * Referenced by: '<S2>/Integrator2' (Parameter: InitialCondition)
                                        */
  real_T SFunction2_P1_Size[2];        /* Computed Parameter: SFunction2_P1_Size
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P1Size)
                                        */
  real_T SFunction2_P1;                /* Expression: ctl_id
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P1)
                                        */
  real_T SFunction2_P2_Size[2];        /* Computed Parameter: SFunction2_P2_Size
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P2Size)
                                        */
  real_T SFunction2_P2;                /* Expression: send_id
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P2)
                                        */
  real_T SFunction2_P3_Size[2];        /* Computed Parameter: SFunction2_P3_Size
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P3Size)
                                        */
  real_T SFunction2_P3;                /* Expression: mode
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P3)
                                        */
  real_T SFunction2_P4_Size[2];        /* Computed Parameter: SFunction2_P4_Size
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P4Size)
                                        */
  real_T SFunction2_P4;                /* Expression: fp1
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P4)
                                        */
  real_T SFunction2_P5_Size[2];        /* Computed Parameter: SFunction2_P5_Size
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P5Size)
                                        */
  real_T SFunction2_P5;                /* Expression: fp2
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P5)
                                        */
  real_T SFunction2_P6_Size[2];        /* Computed Parameter: SFunction2_P6_Size
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P6Size)
                                        */
  real_T SFunction2_P6;                /* Expression: fp3
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P6)
                                        */
  real_T SFunction2_P7_Size[2];        /* Computed Parameter: SFunction2_P7_Size
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P7Size)
                                        */
  real_T SFunction2_P7;                /* Expression: fp4
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P7)
                                        */
  real_T SFunction2_P8_Size[2];        /* Computed Parameter: SFunction2_P8_Size
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P8Size)
                                        */
  real_T SFunction2_P8;                /* Expression: fp5
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P8)
                                        */
  real_T SFunction2_P9_Size[2];        /* Computed Parameter: SFunction2_P9_Size
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P9Size)
                                        */
  real_T SFunction2_P9[7];             /* Computed Parameter: SFunction2_P9
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P9)
                                        */
  real_T SFunction2_P10_Size[2];      /* Computed Parameter: SFunction2_P10_Size
                                       * Referenced by: '<S7>/S-Function2' (Parameter: P10Size)
                                       */
  real_T SFunction2_P10[7];            /* Computed Parameter: SFunction2_P10
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P10)
                                        */
  real_T SFunction2_P11_Size[2];      /* Computed Parameter: SFunction2_P11_Size
                                       * Referenced by: '<S7>/S-Function2' (Parameter: P11Size)
                                       */
  real_T SFunction2_P11[7];            /* Computed Parameter: SFunction2_P11
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P11)
                                        */
  real_T SFunction2_P12_Size[2];      /* Computed Parameter: SFunction2_P12_Size
                                       * Referenced by: '<S7>/S-Function2' (Parameter: P12Size)
                                       */
  real_T SFunction2_P12[7];            /* Computed Parameter: SFunction2_P12
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P12)
                                        */
  real_T SFunction2_P13_Size[2];      /* Computed Parameter: SFunction2_P13_Size
                                       * Referenced by: '<S7>/S-Function2' (Parameter: P13Size)
                                       */
  real_T SFunction2_P13[7];            /* Computed Parameter: SFunction2_P13
                                        * Referenced by: '<S7>/S-Function2' (Parameter: P13)
                                        */
  real_T timeout_Value;                /* Expression: 2
                                        * Referenced by: '<S2>/timeout' (Parameter: Value)
                                        */
  real_T SFunction1_P1_Size[2];        /* Computed Parameter: SFunction1_P1_Size
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P1Size)
                                        */
  real_T SFunction1_P1;                /* Expression: ctl_id
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P1)
                                        */
  real_T SFunction1_P2_Size[2];        /* Computed Parameter: SFunction1_P2_Size
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P2Size)
                                        */
  real_T SFunction1_P2;                /* Expression: recv_id
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P2)
                                        */
  real_T SFunction1_P3_Size[2];        /* Computed Parameter: SFunction1_P3_Size
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P3Size)
                                        */
  real_T SFunction1_P3;                /* Expression: fp1
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P3)
                                        */
  real_T SFunction1_P4_Size[2];        /* Computed Parameter: SFunction1_P4_Size
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P4Size)
                                        */
  real_T SFunction1_P4;                /* Expression: fp2
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P4)
                                        */
  real_T SFunction1_P5_Size[2];        /* Computed Parameter: SFunction1_P5_Size
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P5Size)
                                        */
  real_T SFunction1_P5;                /* Expression: fp3
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P5)
                                        */
  real_T SFunction1_P6_Size[2];        /* Computed Parameter: SFunction1_P6_Size
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P6Size)
                                        */
  real_T SFunction1_P6;                /* Expression: fp4
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P6)
                                        */
  real_T SFunction1_P7_Size[2];        /* Computed Parameter: SFunction1_P7_Size
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P7Size)
                                        */
  real_T SFunction1_P7;                /* Expression: fp5
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P7)
                                        */
  real_T SFunction1_P8_Size[2];        /* Computed Parameter: SFunction1_P8_Size
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P8Size)
                                        */
  real_T SFunction1_P8[7];             /* Computed Parameter: SFunction1_P8
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P8)
                                        */
  real_T SFunction1_P9_Size[2];        /* Computed Parameter: SFunction1_P9_Size
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P9Size)
                                        */
  real_T SFunction1_P9[7];             /* Computed Parameter: SFunction1_P9
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P9)
                                        */
  real_T SFunction1_P10_Size[2];      /* Computed Parameter: SFunction1_P10_Size
                                       * Referenced by: '<S5>/S-Function1' (Parameter: P10Size)
                                       */
  real_T SFunction1_P10[7];            /* Computed Parameter: SFunction1_P10
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P10)
                                        */
  real_T SFunction1_P11_Size[2];      /* Computed Parameter: SFunction1_P11_Size
                                       * Referenced by: '<S5>/S-Function1' (Parameter: P11Size)
                                       */
  real_T SFunction1_P11[7];            /* Computed Parameter: SFunction1_P11
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P11)
                                        */
  real_T SFunction1_P12_Size[2];      /* Computed Parameter: SFunction1_P12_Size
                                       * Referenced by: '<S5>/S-Function1' (Parameter: P12Size)
                                       */
  real_T SFunction1_P12[7];            /* Computed Parameter: SFunction1_P12
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P12)
                                        */
  real_T SFunction1_P13_Size[2];      /* Computed Parameter: SFunction1_P13_Size
                                       * Referenced by: '<S5>/S-Function1' (Parameter: P13Size)
                                       */
  real_T SFunction1_P13;               /* Computed Parameter: SFunction1_P13
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P13)
                                        */
  real_T SFunction1_P14_Size[2];      /* Computed Parameter: SFunction1_P14_Size
                                       * Referenced by: '<S5>/S-Function1' (Parameter: P14Size)
                                       */
  real_T SFunction1_P14;               /* Computed Parameter: SFunction1_P14
                                        * Referenced by: '<S5>/S-Function1' (Parameter: P14)
                                        */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S9>/S-Function' (Parameter: P1Size)
                                        */
  real_T SFunction_P1;                 /* Expression: Acqu_group
                                        * Referenced by: '<S9>/S-Function' (Parameter: P1)
                                        */
  real_T OpIPSocketCtrl1_P1_Size[2];
                                  /* Computed Parameter: OpIPSocketCtrl1_P1_Size
                                   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P1Size)
                                   */
  real_T OpIPSocketCtrl1_P1;           /* Expression: ctl_id
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P1)
                                        */
  real_T OpIPSocketCtrl1_P2_Size[2];
                                  /* Computed Parameter: OpIPSocketCtrl1_P2_Size
                                   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P2Size)
                                   */
  real_T OpIPSocketCtrl1_P2;           /* Expression: proto
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P2)
                                        */
  real_T OpIPSocketCtrl1_P3_Size[2];
                                  /* Computed Parameter: OpIPSocketCtrl1_P3_Size
                                   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P3Size)
                                   */
  real_T OpIPSocketCtrl1_P3;           /* Expression: ip_port_remote
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P3)
                                        */
  real_T OpIPSocketCtrl1_P4_Size[2];
                                  /* Computed Parameter: OpIPSocketCtrl1_P4_Size
                                   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P4Size)
                                   */
  real_T OpIPSocketCtrl1_P4;           /* Expression: ip_port_local
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P4)
                                        */
  real_T OpIPSocketCtrl1_P5_Size[2];
                                  /* Computed Parameter: OpIPSocketCtrl1_P5_Size
                                   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P5Size)
                                   */
  real_T OpIPSocketCtrl1_P5;           /* Expression: 0
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P5)
                                        */
  real_T OpIPSocketCtrl1_P6_Size[2];
                                  /* Computed Parameter: OpIPSocketCtrl1_P6_Size
                                   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P6Size)
                                   */
  real_T OpIPSocketCtrl1_P6;           /* Expression: 0
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P6)
                                        */
  real_T OpIPSocketCtrl1_P7_Size[2];
                                  /* Computed Parameter: OpIPSocketCtrl1_P7_Size
                                   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P7Size)
                                   */
  real_T OpIPSocketCtrl1_P7;           /* Expression: 0
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P7)
                                        */
  real_T OpIPSocketCtrl1_P8_Size[2];
                                  /* Computed Parameter: OpIPSocketCtrl1_P8_Size
                                   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P8Size)
                                   */
  real_T OpIPSocketCtrl1_P8;           /* Expression: 0
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P8)
                                        */
  real_T OpIPSocketCtrl1_P9_Size[2];
                                  /* Computed Parameter: OpIPSocketCtrl1_P9_Size
                                   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P9Size)
                                   */
  real_T OpIPSocketCtrl1_P9;           /* Expression: 0
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P9)
                                        */
  real_T OpIPSocketCtrl1_P10_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P10_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P10Size)
                                  */
  real_T OpIPSocketCtrl1_P10;          /* Expression: 0
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P10)
                                        */
  real_T OpIPSocketCtrl1_P11_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P11_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P11Size)
                                  */
  real_T OpIPSocketCtrl1_P11;          /* Expression: 0
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P11)
                                        */
  real_T OpIPSocketCtrl1_P12_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P12_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P12Size)
                                  */
  real_T OpIPSocketCtrl1_P12;          /* Expression: 0
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P12)
                                        */
  real_T OpIPSocketCtrl1_P13_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P13_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P13Size)
                                  */
  real_T OpIPSocketCtrl1_P13;          /* Expression: 0
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P13)
                                        */
  real_T OpIPSocketCtrl1_P14_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P14_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P14Size)
                                  */
  real_T OpIPSocketCtrl1_P14[12];     /* Computed Parameter: OpIPSocketCtrl1_P14
                                       * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P14)
                                       */
  real_T OpIPSocketCtrl1_P15_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P15_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P15Size)
                                  */
  real_T OpIPSocketCtrl1_P15[7];      /* Computed Parameter: OpIPSocketCtrl1_P15
                                       * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P15)
                                       */
  real_T OpIPSocketCtrl1_P16_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P16_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P16Size)
                                  */
  real_T OpIPSocketCtrl1_P17_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P17_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P17Size)
                                  */
  real_T OpIPSocketCtrl1_P18_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P18_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P18Size)
                                  */
  real_T OpIPSocketCtrl1_P19_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P19_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P19Size)
                                  */
  real_T OpIPSocketCtrl1_P20_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P20_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P20Size)
                                  */
  real_T OpIPSocketCtrl1_P21_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P21_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P21Size)
                                  */
  real_T OpIPSocketCtrl1_P22_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P22_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P22Size)
                                  */
  real_T OpIPSocketCtrl1_P23_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P23_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P23Size)
                                  */
  real_T OpIPSocketCtrl1_P24_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P24_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P24Size)
                                  */
  real_T OpIPSocketCtrl1_P25_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P25_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P25Size)
                                  */
  real_T OpIPSocketCtrl1_P26_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P26_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P26Size)
                                  */
  real_T OpIPSocketCtrl1_P26[7];      /* Computed Parameter: OpIPSocketCtrl1_P26
                                       * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P26)
                                       */
  real_T OpIPSocketCtrl1_P27_Size[2];
                                 /* Computed Parameter: OpIPSocketCtrl1_P27_Size
                                  * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P27Size)
                                  */
  real_T OpIPSocketCtrl1_P27;          /* Expression: 0
                                        * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P27)
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_asyncip_sl_1_sm_ip_test_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[4];
    SimStruct *childSFunctionPtrs[4];
    struct _ssBlkInfo2 blkInfo2[4];
    struct _ssSFcnModelMethods2 methods2[4];
    struct _ssSFcnModelMethods3 methods3[4];
    struct _ssSFcnModelMethods4 methods4[4];
    struct _ssStatesInfo2 statesInfo2[4];
    ssPeriodicStatesInfo periodicStatesInfo[4];
    struct _ssPortInfo2 inputOutputPortInfo2[4];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[12];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[13];
      mxArray *params[13];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[3];
      struct _ssOutPortUnit outputPortUnits[3];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[3];
      uint_T attribs[14];
      mxArray *params[14];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[6];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[27];
      mxArray *params[27];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T CTOutputIncnstWithState;
    real_T odeY[12];
    real_T odeF[4][12];
    ODE4_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_asyncip_sl_1_sm_ip_test_T asyncip_sl_1_sm_ip_test_P;

/* Block signals (default storage) */
extern B_asyncip_sl_1_sm_ip_test_T asyncip_sl_1_sm_ip_test_B;

/* Continuous states (default storage) */
extern X_asyncip_sl_1_sm_ip_test_T asyncip_sl_1_sm_ip_test_X;

/* Block states (default storage) */
extern DW_asyncip_sl_1_sm_ip_test_T asyncip_sl_1_sm_ip_test_DW;

/* Model entry point functions */
extern void asyncip_sl_1_sm_ip_test_initialize(void);
extern void asyncip_sl_1_sm_ip_test_output(void);
extern void asyncip_sl_1_sm_ip_test_update(void);
extern void asyncip_sl_1_sm_ip_test_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern asyncip_sl_1_sm_ip_test_rtModel *asyncip_sl_1_sm_ip_test(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_asyncip_sl_1_sm_ip_test_T *const asyncip_sl_1_sm_ip_test_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'asyncip_sl_1_sm_ip_test'
 * '<S1>'   : 'asyncip_sl_1_sm_ip_test/OpCCode_do_not_touch'
 * '<S2>'   : 'asyncip_sl_1_sm_ip_test/sm_ip_test'
 * '<S3>'   : 'asyncip_sl_1_sm_ip_test/sm_ip_test/Load increase'
 * '<S4>'   : 'asyncip_sl_1_sm_ip_test/sm_ip_test/MATLAB Function1'
 * '<S5>'   : 'asyncip_sl_1_sm_ip_test/sm_ip_test/receive message 1'
 * '<S6>'   : 'asyncip_sl_1_sm_ip_test/sm_ip_test/rtlab_send_subsystem'
 * '<S7>'   : 'asyncip_sl_1_sm_ip_test/sm_ip_test/send message 1'
 * '<S8>'   : 'asyncip_sl_1_sm_ip_test/sm_ip_test/rtlab_send_subsystem/Subsystem1'
 * '<S9>'   : 'asyncip_sl_1_sm_ip_test/sm_ip_test/rtlab_send_subsystem/Subsystem1/Send1'
 */
#endif                               /* RTW_HEADER_asyncip_sl_1_sm_ip_test_h_ */
