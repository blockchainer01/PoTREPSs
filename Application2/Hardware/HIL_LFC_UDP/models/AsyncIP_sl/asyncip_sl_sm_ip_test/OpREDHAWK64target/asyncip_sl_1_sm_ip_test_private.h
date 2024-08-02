/*
 * asyncip_sl_1_sm_ip_test_private.h
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

#ifndef RTW_HEADER_asyncip_sl_1_sm_ip_test_private_h_
#define RTW_HEADER_asyncip_sl_1_sm_ip_test_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern void sfun_send_async(SimStruct *rts);
extern void sfun_recv_async(SimStruct *rts);
extern void OP_SEND(SimStruct *rts);
extern void sfun_gen_async_ctrl(SimStruct *rts);

/* private model entry point functions */
extern void asyncip_sl_1_sm_ip_test_derivatives(void);

#endif                       /* RTW_HEADER_asyncip_sl_1_sm_ip_test_private_h_ */
