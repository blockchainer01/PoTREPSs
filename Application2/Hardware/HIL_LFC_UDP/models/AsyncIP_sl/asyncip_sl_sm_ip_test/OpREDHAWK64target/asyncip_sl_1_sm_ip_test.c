/*
 * asyncip_sl_1_sm_ip_test.c
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

#include "asyncip_sl_1_sm_ip_test.h"
#include "asyncip_sl_1_sm_ip_test_private.h"

/* Named constants for MATLAB Function: '<S2>/Load increase' */
#define asyncip_sl_1_sm_ip_t_CALL_EVENT (-1)

/* Block signals (default storage) */
B_asyncip_sl_1_sm_ip_test_T asyncip_sl_1_sm_ip_test_B;

/* Continuous states */
X_asyncip_sl_1_sm_ip_test_T asyncip_sl_1_sm_ip_test_X;

/* Block states (default storage) */
DW_asyncip_sl_1_sm_ip_test_T asyncip_sl_1_sm_ip_test_DW;

/* Real-time model */
static RT_MODEL_asyncip_sl_1_sm_ip_test_T asyncip_sl_1_sm_ip_test_M_;
RT_MODEL_asyncip_sl_1_sm_ip_test_T *const asyncip_sl_1_sm_ip_test_M =
  &asyncip_sl_1_sm_ip_test_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  asyncip_sl_1_sm_ip_test_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  asyncip_sl_1_sm_ip_test_output();
  asyncip_sl_1_sm_ip_test_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  asyncip_sl_1_sm_ip_test_output();
  asyncip_sl_1_sm_ip_test_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  asyncip_sl_1_sm_ip_test_output();
  asyncip_sl_1_sm_ip_test_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void asyncip_sl_1_sm_ip_test_output(void)
{
  static const real_T b[3] = { 0.0, 0.0, 0.0 };

  static const real_T c[3] = { 2.0, 0.0, 0.0 };

  static const real_T d[3] = { 2.0, 2.0, 0.0 };

  static const real_T e[3] = { 2.0, 2.0, 2.0 };

  static const real_T f[3] = { 2.0, 2.0, 3.0 };

  cell_wrap_0_asyncip_sl_1_sm_i_T A_[9];
  cell_wrap_0_asyncip_sl_1_sm_i_T A[3];
  cell_wrap_1_asyncip_sl_1_sm_i_T B[3];
  cell_wrap_2_asyncip_sl_1_sm_i_T A_D[3];
  real_T dx[12];
  real_T x[12];
  real_T T[9];
  real_T w[6];
  real_T Inter[4];
  real_T bar_T[3];
  real_T u[3];
  real_T i;
  real_T j;
  int32_T b_i;
  int32_T b_j;
  static const real_T b_0[9] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int32_T c_0[2] = { 0, 1 };

  static const real_T d_0[3] = { 0.0, 0.0, 0.0 };

  static const real_T e_0[4] = { -0.62857142857142867, 0.2857142857142857, 0.0,
    -0.2857142857142857 };

  static const real_T f_0[4] = { 0.0, -0.02, 0.02, 0.0 };

  static const real_T g[4] = { -0.033333333333333333, 0.0, -0.05, 0.0 };

  static const real_T h[4] = { 0.0, 0.0, 0.05, 0.0 };

  static const real_T k[8] = { -0.2857142857142857, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const real_T l[16] = { -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0 };

  static const real_T m[16] = { -0.0, -0.0, -0.0, -7.54, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0 };

  static const real_T n[4] = { -0.75625000000000009, 0.25, 0.0, -0.25 };

  static const real_T o[4] = { 0.0, -0.1, 0.1, 0.0 };

  static const real_T p[4] = { -0.053333333333333337, 0.0, -0.08, 0.0 };

  static const real_T q[4] = { 0.0, 0.0, 0.08, 0.0 };

  static const real_T r[8] = { -0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T s[4] = { -0.70400000000000007, 0.26666666666666666, 0.0,
    -0.26666666666666666 };

  static const real_T t[4] = { 0.0, -0.033333333333333333, 0.033333333333333333,
    0.0 };

  static const real_T v[4] = { -0.041666666666666664, 0.0, -0.0625, 0.0 };

  static const real_T y[4] = { 0.0, 0.0, 0.0625, 0.0 };

  static const real_T ab[8] = { -0.26666666666666666, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const int32_T bb[4] = { 0, 1, 2, 3 };

  real_T A_0[4];
  real_T A_D_0[4];
  real_T A_D_1;
  real_T A_D_2;
  real_T Inter_0;
  real_T Inter_1;
  real_T tmp;
  real_T tmp_0;
  real_T u_0;
  int32_T i_0;
  int32_T i_1;
  int32_T i_2;
  int32_T i_3;
  int32_T i_4;
  int32_T i_5;
  int32_T i_6;
  int32_T j_0;
  if (rtmIsMajorTimeStep(asyncip_sl_1_sm_ip_test_M)) {
    /* set solver stop time */
    if (!(asyncip_sl_1_sm_ip_test_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&asyncip_sl_1_sm_ip_test_M->solverInfo,
                            ((asyncip_sl_1_sm_ip_test_M->Timing.clockTickH0 + 1)
        * asyncip_sl_1_sm_ip_test_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&asyncip_sl_1_sm_ip_test_M->solverInfo,
                            ((asyncip_sl_1_sm_ip_test_M->Timing.clockTick0 + 1) *
        asyncip_sl_1_sm_ip_test_M->Timing.stepSize0 +
        asyncip_sl_1_sm_ip_test_M->Timing.clockTickH0 *
        asyncip_sl_1_sm_ip_test_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(asyncip_sl_1_sm_ip_test_M)) {
    asyncip_sl_1_sm_ip_test_M->Timing.t[0] = rtsiGetT
      (&asyncip_sl_1_sm_ip_test_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(asyncip_sl_1_sm_ip_test_M)) {
    /* Memory: '<S1>/S-Function' */
    asyncip_sl_1_sm_ip_test_B.SFunction =
      asyncip_sl_1_sm_ip_test_DW.SFunction_PreviousInput;

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/S-Function1'
     */
    asyncip_sl_1_sm_ip_test_B.Sum = asyncip_sl_1_sm_ip_test_P.SFunction1_Value +
      asyncip_sl_1_sm_ip_test_B.SFunction;

    /* Stop: '<S1>/Stop Simulation' */
    if (asyncip_sl_1_sm_ip_test_B.Sum != 0.0) {
      rtmSetStopRequested(asyncip_sl_1_sm_ip_test_M, 1);
    }

    /* End of Stop: '<S1>/Stop Simulation' */

    /* Constant: '<S2>/Constant' */
    asyncip_sl_1_sm_ip_test_B.Constant =
      asyncip_sl_1_sm_ip_test_P.Constant_Value;
  }

  /* Integrator: '<S2>/Integrator' */
  asyncip_sl_1_sm_ip_test_B.Integrator[0] =
    asyncip_sl_1_sm_ip_test_X.Integrator_CSTATE[0];
  asyncip_sl_1_sm_ip_test_B.Integrator[1] =
    asyncip_sl_1_sm_ip_test_X.Integrator_CSTATE[1];
  asyncip_sl_1_sm_ip_test_B.Integrator[2] =
    asyncip_sl_1_sm_ip_test_X.Integrator_CSTATE[2];
  asyncip_sl_1_sm_ip_test_B.Integrator[3] =
    asyncip_sl_1_sm_ip_test_X.Integrator_CSTATE[3];

  /* Integrator: '<S2>/Integrator1' */
  asyncip_sl_1_sm_ip_test_B.Integrator1[0] =
    asyncip_sl_1_sm_ip_test_X.Integrator1_CSTATE[0];
  asyncip_sl_1_sm_ip_test_B.Integrator1[1] =
    asyncip_sl_1_sm_ip_test_X.Integrator1_CSTATE[1];
  asyncip_sl_1_sm_ip_test_B.Integrator1[2] =
    asyncip_sl_1_sm_ip_test_X.Integrator1_CSTATE[2];
  asyncip_sl_1_sm_ip_test_B.Integrator1[3] =
    asyncip_sl_1_sm_ip_test_X.Integrator1_CSTATE[3];
  if (rtmIsMajorTimeStep(asyncip_sl_1_sm_ip_test_M)) {
    /* ZeroOrderHold: '<S2>/Zero-Order Hold17' */
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold17[0] =
      asyncip_sl_1_sm_ip_test_B.Integrator[0];
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold17[1] =
      asyncip_sl_1_sm_ip_test_B.Integrator[1];
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold17[2] =
      asyncip_sl_1_sm_ip_test_B.Integrator[2];
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold17[3] =
      asyncip_sl_1_sm_ip_test_B.Integrator[3];
  }

  /* Integrator: '<S2>/Integrator2' */
  asyncip_sl_1_sm_ip_test_B.Integrator2[0] =
    asyncip_sl_1_sm_ip_test_X.Integrator2_CSTATE[0];
  asyncip_sl_1_sm_ip_test_B.Integrator2[1] =
    asyncip_sl_1_sm_ip_test_X.Integrator2_CSTATE[1];
  asyncip_sl_1_sm_ip_test_B.Integrator2[2] =
    asyncip_sl_1_sm_ip_test_X.Integrator2_CSTATE[2];
  asyncip_sl_1_sm_ip_test_B.Integrator2[3] =
    asyncip_sl_1_sm_ip_test_X.Integrator2_CSTATE[3];
  if (rtmIsMajorTimeStep(asyncip_sl_1_sm_ip_test_M)) {
    /* ZeroOrderHold: '<S2>/Zero-Order Hold1' */
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold1[0] =
      asyncip_sl_1_sm_ip_test_B.Integrator1[0];
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold1[1] =
      asyncip_sl_1_sm_ip_test_B.Integrator1[1];
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold1[2] =
      asyncip_sl_1_sm_ip_test_B.Integrator1[2];
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold1[3] =
      asyncip_sl_1_sm_ip_test_B.Integrator1[3];

    /* ZeroOrderHold: '<S2>/Zero-Order Hold2' */
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold2[0] =
      asyncip_sl_1_sm_ip_test_B.Integrator2[0];
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold2[1] =
      asyncip_sl_1_sm_ip_test_B.Integrator2[1];
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold2[2] =
      asyncip_sl_1_sm_ip_test_B.Integrator2[2];
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold2[3] =
      asyncip_sl_1_sm_ip_test_B.Integrator2[3];

    /* S-Function (sfun_send_async): '<S7>/S-Function2' */

    /* Level2 S-Function Block: '<S7>/S-Function2' (sfun_send_async) */
    {
      SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[0];
      sfcnOutputs(rts,0);
    }

    /* Constant: '<S2>/timeout' */
    asyncip_sl_1_sm_ip_test_B.timeout = asyncip_sl_1_sm_ip_test_P.timeout_Value;

    /* S-Function (sfun_recv_async): '<S5>/S-Function1' */

    /* Level2 S-Function Block: '<S5>/S-Function1' (sfun_recv_async) */
    {
      SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[1];
      sfcnOutputs(rts,0);
    }

    /* S-Function (OP_SEND): '<S9>/S-Function' */

    /* Level2 S-Function Block: '<S9>/S-Function' (OP_SEND) */
    {
      SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[2];
      sfcnOutputs(rts,0);
    }
  }

  /* Clock: '<S2>/Clock' */
  asyncip_sl_1_sm_ip_test_B.Clock = asyncip_sl_1_sm_ip_test_M->Timing.t[0];

  /* MATLAB Function: '<S2>/Load increase' */
  /* MATLAB Function 'sm_ip_test/Load increase': '<S3>:1' */
  /* '<S3>:1:2' */
  asyncip_sl_1_sm_ip_test_B.deltaPL[0] = 0.0;
  asyncip_sl_1_sm_ip_test_B.deltaPL[1] = 0.0;
  asyncip_sl_1_sm_ip_test_B.deltaPL[2] = 0.0;
  if (asyncip_sl_1_sm_ip_test_B.Clock < 5.0) {
    /* '<S3>:1:3' */
    /* '<S3>:1:4' */
    asyncip_sl_1_sm_ip_test_B.deltaPL[0] = b[0];
    asyncip_sl_1_sm_ip_test_B.deltaPL[1] = b[1];
    asyncip_sl_1_sm_ip_test_B.deltaPL[2] = b[2];
  } else if (asyncip_sl_1_sm_ip_test_B.Clock < 10.0) {
    /* '<S3>:1:5' */
    /* '<S3>:1:6' */
    asyncip_sl_1_sm_ip_test_B.deltaPL[0] = c[0];
    asyncip_sl_1_sm_ip_test_B.deltaPL[1] = c[1];
    asyncip_sl_1_sm_ip_test_B.deltaPL[2] = c[2];
  } else if (asyncip_sl_1_sm_ip_test_B.Clock < 15.0) {
    /* '<S3>:1:7' */
    /* '<S3>:1:8' */
    asyncip_sl_1_sm_ip_test_B.deltaPL[0] = d[0];
    asyncip_sl_1_sm_ip_test_B.deltaPL[1] = d[1];
    asyncip_sl_1_sm_ip_test_B.deltaPL[2] = d[2];
  } else if (asyncip_sl_1_sm_ip_test_B.Clock < 20.0) {
    /* '<S3>:1:9' */
    /* '<S3>:1:10' */
    asyncip_sl_1_sm_ip_test_B.deltaPL[0] = e[0];
    asyncip_sl_1_sm_ip_test_B.deltaPL[1] = e[1];
    asyncip_sl_1_sm_ip_test_B.deltaPL[2] = e[2];
  } else if (asyncip_sl_1_sm_ip_test_B.Clock < 200.0) {
    /* '<S3>:1:11' */
    /* '<S3>:1:12' */
    asyncip_sl_1_sm_ip_test_B.deltaPL[0] = f[0];
    asyncip_sl_1_sm_ip_test_B.deltaPL[1] = f[1];
    asyncip_sl_1_sm_ip_test_B.deltaPL[2] = f[2];
  }

  /* End of MATLAB Function: '<S2>/Load increase' */

  /* MATLAB Function: '<S2>/MATLAB Function1' */
  /* MATLAB Function 'sm_ip_test/MATLAB Function1': '<S4>:1' */
  /* '<S4>:1:10' */
  /* '<S4>:1:31' */
  /* '<S4>:1:18' */
  /* '<S4>:1:54' */
  /* '<S4>:1:62' */
  /* '<S4>:1:64' */
  /* '<S4>:1:4' */
  x[0] = asyncip_sl_1_sm_ip_test_B.Integrator[0];
  x[3] = asyncip_sl_1_sm_ip_test_B.Integrator[1];
  x[3 << 1] = asyncip_sl_1_sm_ip_test_B.Integrator[2];
  x[3 * 3] = asyncip_sl_1_sm_ip_test_B.Integrator[3];
  x[1] = asyncip_sl_1_sm_ip_test_B.Integrator1[0];
  x[1 + 3] = asyncip_sl_1_sm_ip_test_B.Integrator1[1];
  x[1 + (3 << 1)] = asyncip_sl_1_sm_ip_test_B.Integrator1[2];
  x[1 + 3 * 3] = asyncip_sl_1_sm_ip_test_B.Integrator1[3];
  x[2] = asyncip_sl_1_sm_ip_test_B.Integrator2[0];
  x[2 + 3] = asyncip_sl_1_sm_ip_test_B.Integrator2[1];
  x[2 + (3 << 1)] = asyncip_sl_1_sm_ip_test_B.Integrator2[2];
  x[2 + 3 * 3] = asyncip_sl_1_sm_ip_test_B.Integrator2[3];

  /* '<S4>:1:6' */
  u[0] = asyncip_sl_1_sm_ip_test_B.SFunction1_o3[0];
  u[1] = asyncip_sl_1_sm_ip_test_B.SFunction1_o3[1];
  u[2] = asyncip_sl_1_sm_ip_test_B.SFunction1_o3[2];

  /* '<S4>:1:10' */
  /* '<S4>:1:17' */
  /* '<S4>:1:18' */
  memcpy(&T[0], &b_0[0], 9U * sizeof(real_T));

  /* '<S4>:1:20' */
  T[3] = 7.54;

  /* '<S4>:1:21' */
  T[6] = 7.54;

  /* '<S4>:1:22' */
  T[1] = 7.54;

  /* '<S4>:1:23' */
  T[7] = 7.54;

  /* '<S4>:1:24' */
  T[2] = 7.54;

  /* '<S4>:1:25' */
  T[5] = 7.54;

  /* '<S4>:1:31' */
  /* '<S4>:1:27' */
  /* '<S4>:1:32' */
  i = 1.0;

  /* '<S4>:1:33' */
  i_0 = (int32_T)i - 1;
  w[c_0[0] + (i_0 << 1)] = asyncip_sl_1_sm_ip_test_B.deltaPL[(int32_T)i - 1];
  w[c_0[1] + (i_0 << 1)] = d_0[(int32_T)i - 1];

  /* '<S4>:1:32' */
  i = 1.0 + (real_T)1;

  /* '<S4>:1:33' */
  i_0 = (int32_T)i - 1;
  w[c_0[0] + (i_0 << 1)] = asyncip_sl_1_sm_ip_test_B.deltaPL[(int32_T)i - 1];
  w[c_0[1] + (i_0 << 1)] = d_0[(int32_T)i - 1];

  /* '<S4>:1:32' */
  i = 1.0 + (real_T)2;

  /* '<S4>:1:33' */
  i_0 = (int32_T)i - 1;
  w[c_0[0] + (i_0 << 1)] = asyncip_sl_1_sm_ip_test_B.deltaPL[(int32_T)i - 1];
  w[c_0[1] + (i_0 << 1)] = d_0[(int32_T)i - 1];

  /* '<S4>:1:36' */
  bar_T[0] = 0.0;
  bar_T[1] = 0.0;
  bar_T[2] = 0.0;

  /* '<S4>:1:38' */
  for (b_i = 0; b_i < 3; b_i = b_i + 1) {
    /* '<S4>:1:38' */
    i = 1.0 + (real_T)b_i;

    /* '<S4>:1:39' */
    /* '<S4>:1:40' */
    bar_T[(int32_T)i - 1] = bar_T[(int32_T)i - 1] + T[((int32_T)i - 1) + 3 * (1
      - 1)];

    /* '<S4>:1:39' */
    /* '<S4>:1:40' */
    bar_T[(int32_T)i - 1] = bar_T[(int32_T)i - 1] + T[((int32_T)i - 1) + 3 * ((1
      + 1) - 1)];

    /* '<S4>:1:39' */
    /* '<S4>:1:40' */
    bar_T[(int32_T)i - 1] = bar_T[(int32_T)i - 1] + T[((int32_T)i - 1) + 3 * ((2
      + 1) - 1)];
  }

  /* '<S4>:1:50' */
  A[0].f1[0] = e_0[0];
  A[0].f1[1 << 2] = e_0[1];
  A[0].f1[2 << 2] = e_0[2];
  A[0].f1[3 << 2] = e_0[3];
  A[0].f1[1] = f_0[0];
  A[0].f1[1 + (1 << 2)] = f_0[1];
  A[0].f1[1 + (2 << 2)] = f_0[2];
  A[0].f1[1 + (3 << 2)] = f_0[3];
  A[0].f1[2] = g[0];
  A[0].f1[2 + (1 << 2)] = g[1];
  A[0].f1[2 + (2 << 2)] = g[2];
  A[0].f1[2 + (3 << 2)] = g[3];
  A[0].f1[3] = bar_T[0];
  A[0].f1[7] = 0.0;
  A[0].f1[11] = 0.0;
  A[0].f1[15] = 0.0;

  /* '<S4>:1:51' */
  B[0].f1[0] = h[0];
  B[0].f1[1] = h[1];
  B[0].f1[2] = h[2];
  B[0].f1[3] = h[3];

  /* '<S4>:1:52' */
  memcpy(&A_D[0].f1[0], &k[0], 8U * sizeof(real_T));

  /* '<S4>:1:54' */
  memcpy(&A_[0].f1[0], &l[0], 16U * sizeof(real_T));

  /* '<S4>:1:54' */
  memcpy(&A_[3].f1[0], &m[0], 16U * sizeof(real_T));

  /* '<S4>:1:54' */
  memcpy(&A_[6].f1[0], &m[0], 16U * sizeof(real_T));

  /* '<S4>:1:50' */
  A[1].f1[0] = n[0];
  A[1].f1[1 << 2] = n[1];
  A[1].f1[2 << 2] = n[2];
  A[1].f1[3 << 2] = n[3];
  A[1].f1[1] = o[0];
  A[1].f1[1 + (1 << 2)] = o[1];
  A[1].f1[1 + (2 << 2)] = o[2];
  A[1].f1[1 + (3 << 2)] = o[3];
  A[1].f1[2] = p[0];
  A[1].f1[2 + (1 << 2)] = p[1];
  A[1].f1[2 + (2 << 2)] = p[2];
  A[1].f1[2 + (3 << 2)] = p[3];
  A[1].f1[3] = bar_T[1];
  A[1].f1[7] = 0.0;
  A[1].f1[11] = 0.0;
  A[1].f1[15] = 0.0;

  /* '<S4>:1:51' */
  B[1].f1[0] = q[0];
  B[1].f1[1] = q[1];
  B[1].f1[2] = q[2];
  B[1].f1[3] = q[3];

  /* '<S4>:1:52' */
  memcpy(&A_D[1].f1[0], &r[0], 8U * sizeof(real_T));

  /* '<S4>:1:54' */
  memcpy(&A_[1].f1[0], &m[0], 16U * sizeof(real_T));

  /* '<S4>:1:54' */
  memcpy(&A_[4].f1[0], &l[0], 16U * sizeof(real_T));

  /* '<S4>:1:54' */
  memcpy(&A_[7].f1[0], &m[0], 16U * sizeof(real_T));

  /* '<S4>:1:50' */
  A[2].f1[0] = s[0];
  A[2].f1[1 << 2] = s[1];
  A[2].f1[2 << 2] = s[2];
  A[2].f1[3 << 2] = s[3];
  A[2].f1[1] = t[0];
  A[2].f1[1 + (1 << 2)] = t[1];
  A[2].f1[1 + (2 << 2)] = t[2];
  A[2].f1[1 + (3 << 2)] = t[3];
  A[2].f1[2] = v[0];
  A[2].f1[2 + (1 << 2)] = v[1];
  A[2].f1[2 + (2 << 2)] = v[2];
  A[2].f1[2 + (3 << 2)] = v[3];
  A[2].f1[3] = bar_T[2];
  A[2].f1[7] = 0.0;
  A[2].f1[11] = 0.0;
  A[2].f1[15] = 0.0;

  /* '<S4>:1:51' */
  B[2].f1[0] = y[0];
  B[2].f1[1] = y[1];
  B[2].f1[2] = y[2];
  B[2].f1[3] = y[3];

  /* '<S4>:1:52' */
  memcpy(&A_D[2].f1[0], &ab[0], 8U * sizeof(real_T));

  /* '<S4>:1:54' */
  memcpy(&A_[2].f1[0], &m[0], 16U * sizeof(real_T));

  /* '<S4>:1:54' */
  memcpy(&A_[5].f1[0], &m[0], 16U * sizeof(real_T));

  /* '<S4>:1:54' */
  memcpy(&A_[8].f1[0], &l[0], 16U * sizeof(real_T));

  /* '<S4>:1:60' */
  /* '<S4>:1:5' */
  /* '<S4>:1:59' */
  for (b_i = 0; b_i < 3; b_i = b_i + 1) {
    /* '<S4>:1:59' */
    i = 1.0 + (real_T)b_i;

    /* '<S4>:1:60' */
    Inter[0] = 0.0;
    Inter[1] = 0.0;
    Inter[2] = 0.0;
    Inter[3] = 0.0;

    /* '<S4>:1:61' */
    for (b_j = 0; b_j < 3; b_j = b_j + 1) {
      /* '<S4>:1:61' */
      j = 1.0 + (real_T)b_j;

      /* '<S4>:1:62' */
      j_0 = (int32_T)j - 1;
      for (i_5 = 0; i_5 < 4; i_5 = i_5 + 1) {
        Inter_1 = Inter[i_5];
        Inter_0 = Inter_1;
        tmp_0 = 0.0;
        tmp_0 = tmp_0 + A_[((int32_T)i - 1) + 3 * ((int32_T)j - 1)].f1[i_5] *
          x[j_0 + 3 * bb[0]];
        tmp_0 = tmp_0 + A_[((int32_T)i - 1) + 3 * ((int32_T)j - 1)].f1[i_5 + (1 <<
          2)] * x[j_0 + 3 * bb[1]];
        tmp_0 = tmp_0 + A_[((int32_T)i - 1) + 3 * ((int32_T)j - 1)].f1[i_5 + (2 <<
          2)] * x[j_0 + 3 * bb[2]];
        tmp_0 = tmp_0 + A_[((int32_T)i - 1) + 3 * ((int32_T)j - 1)].f1[i_5 + (3 <<
          2)] * x[j_0 + 3 * bb[3]];
        Inter_0 = Inter_0 + tmp_0;
        Inter_1 = Inter_0;
        Inter[i_5] = Inter_1;
      }
    }

    /* '<S4>:1:64' */
    i_1 = (int32_T)i - 1;
    u_0 = u[(int32_T)i - 1];
    i_2 = (int32_T)i - 1;
    for (i_4 = 0; i_4 < 4; i_4 = i_4 + 1) {
      tmp = 0.0;
      tmp = tmp + A[(int32_T)i - 1].f1[i_4] * x[i_1 + 3 * bb[0]];
      tmp = tmp + A[(int32_T)i - 1].f1[i_4 + (1 << 2)] * x[i_1 + 3 * bb[1]];
      tmp = tmp + A[(int32_T)i - 1].f1[i_4 + (2 << 2)] * x[i_1 + 3 * bb[2]];
      tmp = tmp + A[(int32_T)i - 1].f1[i_4 + (3 << 2)] * x[i_1 + 3 * bb[3]];
      A_0[i_4] = (tmp + Inter[i_4]) + B[(int32_T)i - 1].f1[i_4] * u_0;
    }

    for (i_6 = 0; i_6 < 4; i_6 = i_6 + 1) {
      A_D_2 = 0.0;
      A_D_1 = A_D_2;
      A_D_1 = A_D_1 + A_D[(int32_T)i - 1].f1[i_6] * w[c_0[0] + (i_2 << 1)];
      A_D_2 = A_D_1;
      A_D_1 = A_D_2;
      A_D_1 = A_D_1 + A_D[(int32_T)i - 1].f1[i_6 + (1 << 2)] * w[c_0[1] + (i_2 <<
        1)];
      A_D_2 = A_D_1;
      A_D_0[i_6] = A_D_2;
    }

    i_3 = (int32_T)i - 1;
    dx[i_3 + 3 * bb[0]] = A_0[0] + A_D_0[0];
    dx[i_3 + 3 * bb[1]] = A_0[1] + A_D_0[1];
    dx[i_3 + 3 * bb[2]] = A_0[2] + A_D_0[2];
    dx[i_3 + 3 * bb[3]] = A_0[3] + A_D_0[3];
  }

  /* '<S4>:1:69' */
  asyncip_sl_1_sm_ip_test_B.dx1_1 = dx[0];

  /* '<S4>:1:70' */
  asyncip_sl_1_sm_ip_test_B.dx1_2 = dx[3];

  /* '<S4>:1:71' */
  asyncip_sl_1_sm_ip_test_B.dx1_3 = dx[6];

  /* '<S4>:1:72' */
  asyncip_sl_1_sm_ip_test_B.dx1_4 = dx[9];

  /* '<S4>:1:75' */
  asyncip_sl_1_sm_ip_test_B.dx2_1 = dx[1];

  /* '<S4>:1:76' */
  asyncip_sl_1_sm_ip_test_B.dx2_2 = dx[4];

  /* '<S4>:1:77' */
  asyncip_sl_1_sm_ip_test_B.dx2_3 = dx[7];

  /* '<S4>:1:78' */
  asyncip_sl_1_sm_ip_test_B.dx2_4 = dx[10];

  /* '<S4>:1:80' */
  asyncip_sl_1_sm_ip_test_B.dx3_1 = dx[2];

  /* '<S4>:1:81' */
  asyncip_sl_1_sm_ip_test_B.dx3_2 = dx[5];

  /* '<S4>:1:82' */
  asyncip_sl_1_sm_ip_test_B.dx3_3 = dx[8];

  /* '<S4>:1:83' */
  asyncip_sl_1_sm_ip_test_B.dx3_4 = dx[11];

  /* End of MATLAB Function: '<S2>/MATLAB Function1' */

  /* SignalConversion generated from: '<S2>/Integrator1' */
  asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrator[0] =
    asyncip_sl_1_sm_ip_test_B.dx2_1;
  asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrator[1] =
    asyncip_sl_1_sm_ip_test_B.dx2_2;
  asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrator[2] =
    asyncip_sl_1_sm_ip_test_B.dx2_3;
  asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrator[3] =
    asyncip_sl_1_sm_ip_test_B.dx2_4;

  /* SignalConversion generated from: '<S2>/Integrator2' */
  asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_n[0] =
    asyncip_sl_1_sm_ip_test_B.dx3_1;
  asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_n[1] =
    asyncip_sl_1_sm_ip_test_B.dx3_2;
  asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_n[2] =
    asyncip_sl_1_sm_ip_test_B.dx3_3;
  asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_n[3] =
    asyncip_sl_1_sm_ip_test_B.dx3_4;

  /* SignalConversion generated from: '<S2>/Integrator' */
  asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_p[0] =
    asyncip_sl_1_sm_ip_test_B.dx1_1;
  asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_p[1] =
    asyncip_sl_1_sm_ip_test_B.dx1_2;
  asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_p[2] =
    asyncip_sl_1_sm_ip_test_B.dx1_3;
  asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_p[3] =
    asyncip_sl_1_sm_ip_test_B.dx1_4;
  if (rtmIsMajorTimeStep(asyncip_sl_1_sm_ip_test_M)) {
    /* S-Function (sfun_gen_async_ctrl): '<S2>/OpIPSocketCtrl1' */

    /* Level2 S-Function Block: '<S2>/OpIPSocketCtrl1' (sfun_gen_async_ctrl) */
    {
      SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[3];
      sfcnOutputs(rts,0);
    }
  }
}

/* Model update function */
void asyncip_sl_1_sm_ip_test_update(void)
{
  if (rtmIsMajorTimeStep(asyncip_sl_1_sm_ip_test_M)) {
    /* Update for Memory: '<S1>/S-Function' */
    asyncip_sl_1_sm_ip_test_DW.SFunction_PreviousInput =
      asyncip_sl_1_sm_ip_test_B.Sum;
  }

  if (rtmIsMajorTimeStep(asyncip_sl_1_sm_ip_test_M)) {
    rt_ertODEUpdateContinuousStates(&asyncip_sl_1_sm_ip_test_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++asyncip_sl_1_sm_ip_test_M->Timing.clockTick0)) {
    ++asyncip_sl_1_sm_ip_test_M->Timing.clockTickH0;
  }

  asyncip_sl_1_sm_ip_test_M->Timing.t[0] = rtsiGetSolverStopTime
    (&asyncip_sl_1_sm_ip_test_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++asyncip_sl_1_sm_ip_test_M->Timing.clockTick1)) {
      ++asyncip_sl_1_sm_ip_test_M->Timing.clockTickH1;
    }

    asyncip_sl_1_sm_ip_test_M->Timing.t[1] =
      asyncip_sl_1_sm_ip_test_M->Timing.clockTick1 *
      asyncip_sl_1_sm_ip_test_M->Timing.stepSize1 +
      asyncip_sl_1_sm_ip_test_M->Timing.clockTickH1 *
      asyncip_sl_1_sm_ip_test_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void asyncip_sl_1_sm_ip_test_derivatives(void)
{
  XDot_asyncip_sl_1_sm_ip_test_T *_rtXdot;
  _rtXdot = ((XDot_asyncip_sl_1_sm_ip_test_T *)
             asyncip_sl_1_sm_ip_test_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] =
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_p[0];
  _rtXdot->Integrator_CSTATE[1] =
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_p[1];
  _rtXdot->Integrator_CSTATE[2] =
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_p[2];
  _rtXdot->Integrator_CSTATE[3] =
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_p[3];

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] =
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrator[0];
  _rtXdot->Integrator1_CSTATE[1] =
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrator[1];
  _rtXdot->Integrator1_CSTATE[2] =
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrator[2];
  _rtXdot->Integrator1_CSTATE[3] =
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrator[3];

  /* Derivatives for Integrator: '<S2>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] =
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_n[0];
  _rtXdot->Integrator2_CSTATE[1] =
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_n[1];
  _rtXdot->Integrator2_CSTATE[2] =
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_n[2];
  _rtXdot->Integrator2_CSTATE[3] =
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_n[3];
}

/* Model initialize function */
void asyncip_sl_1_sm_ip_test_initialize(void)
{
  /* Start for Constant: '<S2>/Constant' */
  asyncip_sl_1_sm_ip_test_B.Constant = asyncip_sl_1_sm_ip_test_P.Constant_Value;

  /* Start for Constant: '<S2>/timeout' */
  asyncip_sl_1_sm_ip_test_B.timeout = asyncip_sl_1_sm_ip_test_P.timeout_Value;

  /* user code (Initialize function Body) */

  /* System '<Root>' */

  /* Opal-RT Technologies */
  opalSizeDwork = sizeof(rtDWork);
  if (Opal_rtmGetNumBlockIO(pRtModel) != 0)
    opalSizeBlockIO = sizeof(rtB);
  else
    opalSizeBlockIO = 0;
  if (Opal_rtmGetNumBlockParams(pRtModel) != 0)
    opalSizeRTP = sizeof(rtP);
  else
    opalSizeRTP = 0;

  /* InitializeConditions for Memory: '<S1>/S-Function' */
  asyncip_sl_1_sm_ip_test_DW.SFunction_PreviousInput =
    asyncip_sl_1_sm_ip_test_P.SFunction_InitialCondition;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  asyncip_sl_1_sm_ip_test_X.Integrator_CSTATE[0] =
    asyncip_sl_1_sm_ip_test_P.Integrator_IC[0];
  asyncip_sl_1_sm_ip_test_X.Integrator_CSTATE[1] =
    asyncip_sl_1_sm_ip_test_P.Integrator_IC[1];
  asyncip_sl_1_sm_ip_test_X.Integrator_CSTATE[2] =
    asyncip_sl_1_sm_ip_test_P.Integrator_IC[2];
  asyncip_sl_1_sm_ip_test_X.Integrator_CSTATE[3] =
    asyncip_sl_1_sm_ip_test_P.Integrator_IC[3];

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  asyncip_sl_1_sm_ip_test_X.Integrator1_CSTATE[0] =
    asyncip_sl_1_sm_ip_test_P.Integrator1_IC[0];
  asyncip_sl_1_sm_ip_test_X.Integrator1_CSTATE[1] =
    asyncip_sl_1_sm_ip_test_P.Integrator1_IC[1];
  asyncip_sl_1_sm_ip_test_X.Integrator1_CSTATE[2] =
    asyncip_sl_1_sm_ip_test_P.Integrator1_IC[2];
  asyncip_sl_1_sm_ip_test_X.Integrator1_CSTATE[3] =
    asyncip_sl_1_sm_ip_test_P.Integrator1_IC[3];

  /* InitializeConditions for Integrator: '<S2>/Integrator2' */
  asyncip_sl_1_sm_ip_test_X.Integrator2_CSTATE[0] =
    asyncip_sl_1_sm_ip_test_P.Integrator2_IC[0];
  asyncip_sl_1_sm_ip_test_X.Integrator2_CSTATE[1] =
    asyncip_sl_1_sm_ip_test_P.Integrator2_IC[1];
  asyncip_sl_1_sm_ip_test_X.Integrator2_CSTATE[2] =
    asyncip_sl_1_sm_ip_test_P.Integrator2_IC[2];
  asyncip_sl_1_sm_ip_test_X.Integrator2_CSTATE[3] =
    asyncip_sl_1_sm_ip_test_P.Integrator2_IC[3];

  /* InitializeConditions for S-Function (sfun_send_async): '<S7>/S-Function2' */
  /* Level2 S-Function Block: '<S7>/S-Function2' (sfun_send_async) */
  {
    SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (sfun_recv_async): '<S5>/S-Function1' */
  /* Level2 S-Function Block: '<S5>/S-Function1' (sfun_recv_async) */
  {
    SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (OP_SEND): '<S9>/S-Function' */
  /* Level2 S-Function Block: '<S9>/S-Function' (OP_SEND) */
  {
    SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[2];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (sfun_gen_async_ctrl): '<S2>/OpIPSocketCtrl1' */
  /* Level2 S-Function Block: '<S2>/OpIPSocketCtrl1' (sfun_gen_async_ctrl) */
  {
    SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[3];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void asyncip_sl_1_sm_ip_test_terminate(void)
{
  /* Terminate for S-Function (sfun_send_async): '<S7>/S-Function2' */
  /* Level2 S-Function Block: '<S7>/S-Function2' (sfun_send_async) */
  {
    SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_recv_async): '<S5>/S-Function1' */
  /* Level2 S-Function Block: '<S5>/S-Function1' (sfun_recv_async) */
  {
    SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (OP_SEND): '<S9>/S-Function' */
  /* Level2 S-Function Block: '<S9>/S-Function' (OP_SEND) */
  {
    SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_gen_async_ctrl): '<S2>/OpIPSocketCtrl1' */
  /* Level2 S-Function Block: '<S2>/OpIPSocketCtrl1' (sfun_gen_async_ctrl) */
  {
    SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[3];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  asyncip_sl_1_sm_ip_test_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  asyncip_sl_1_sm_ip_test_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  asyncip_sl_1_sm_ip_test_initialize();
}

void MdlTerminate(void)
{
  asyncip_sl_1_sm_ip_test_terminate();
}

/* Registration function */
RT_MODEL_asyncip_sl_1_sm_ip_test_T *asyncip_sl_1_sm_ip_test(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)asyncip_sl_1_sm_ip_test_M, 0,
                sizeof(RT_MODEL_asyncip_sl_1_sm_ip_test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&asyncip_sl_1_sm_ip_test_M->solverInfo,
                          &asyncip_sl_1_sm_ip_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&asyncip_sl_1_sm_ip_test_M->solverInfo, &rtmGetTPtr
                (asyncip_sl_1_sm_ip_test_M));
    rtsiSetStepSizePtr(&asyncip_sl_1_sm_ip_test_M->solverInfo,
                       &asyncip_sl_1_sm_ip_test_M->Timing.stepSize0);
    rtsiSetdXPtr(&asyncip_sl_1_sm_ip_test_M->solverInfo,
                 &asyncip_sl_1_sm_ip_test_M->ModelData.derivs);
    rtsiSetContStatesPtr(&asyncip_sl_1_sm_ip_test_M->solverInfo, (real_T **)
                         &asyncip_sl_1_sm_ip_test_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&asyncip_sl_1_sm_ip_test_M->solverInfo,
      &asyncip_sl_1_sm_ip_test_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&asyncip_sl_1_sm_ip_test_M->solverInfo,
      &asyncip_sl_1_sm_ip_test_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&asyncip_sl_1_sm_ip_test_M->solverInfo,
      &asyncip_sl_1_sm_ip_test_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&asyncip_sl_1_sm_ip_test_M->solverInfo,
      &asyncip_sl_1_sm_ip_test_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&asyncip_sl_1_sm_ip_test_M->solverInfo,
                          (&rtmGetErrorStatus(asyncip_sl_1_sm_ip_test_M)));
    rtsiSetRTModelPtr(&asyncip_sl_1_sm_ip_test_M->solverInfo,
                      asyncip_sl_1_sm_ip_test_M);
  }

  rtsiSetSimTimeStep(&asyncip_sl_1_sm_ip_test_M->solverInfo, MAJOR_TIME_STEP);
  asyncip_sl_1_sm_ip_test_M->ModelData.intgData.y =
    asyncip_sl_1_sm_ip_test_M->ModelData.odeY;
  asyncip_sl_1_sm_ip_test_M->ModelData.intgData.f[0] =
    asyncip_sl_1_sm_ip_test_M->ModelData.odeF[0];
  asyncip_sl_1_sm_ip_test_M->ModelData.intgData.f[1] =
    asyncip_sl_1_sm_ip_test_M->ModelData.odeF[1];
  asyncip_sl_1_sm_ip_test_M->ModelData.intgData.f[2] =
    asyncip_sl_1_sm_ip_test_M->ModelData.odeF[2];
  asyncip_sl_1_sm_ip_test_M->ModelData.intgData.f[3] =
    asyncip_sl_1_sm_ip_test_M->ModelData.odeF[3];
  asyncip_sl_1_sm_ip_test_M->ModelData.contStates = ((real_T *)
    &asyncip_sl_1_sm_ip_test_X);
  rtsiSetSolverData(&asyncip_sl_1_sm_ip_test_M->solverInfo, (void *)
                    &asyncip_sl_1_sm_ip_test_M->ModelData.intgData);
  rtsiSetSolverName(&asyncip_sl_1_sm_ip_test_M->solverInfo,"ode4");
  asyncip_sl_1_sm_ip_test_M->solverInfoPtr =
    (&asyncip_sl_1_sm_ip_test_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = asyncip_sl_1_sm_ip_test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "asyncip_sl_1_sm_ip_test_M points to
       static memory which is guaranteed to be non-NULL" */
    asyncip_sl_1_sm_ip_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    asyncip_sl_1_sm_ip_test_M->Timing.sampleTimes =
      (&asyncip_sl_1_sm_ip_test_M->Timing.sampleTimesArray[0]);
    asyncip_sl_1_sm_ip_test_M->Timing.offsetTimes =
      (&asyncip_sl_1_sm_ip_test_M->Timing.offsetTimesArray[0]);

    /* task periods */
    asyncip_sl_1_sm_ip_test_M->Timing.sampleTimes[0] = (0.0);
    asyncip_sl_1_sm_ip_test_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    asyncip_sl_1_sm_ip_test_M->Timing.offsetTimes[0] = (0.0);
    asyncip_sl_1_sm_ip_test_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(asyncip_sl_1_sm_ip_test_M,
             &asyncip_sl_1_sm_ip_test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = asyncip_sl_1_sm_ip_test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    asyncip_sl_1_sm_ip_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(asyncip_sl_1_sm_ip_test_M, -1);
  asyncip_sl_1_sm_ip_test_M->Timing.stepSize0 = 0.01;
  asyncip_sl_1_sm_ip_test_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    asyncip_sl_1_sm_ip_test_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(asyncip_sl_1_sm_ip_test_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(asyncip_sl_1_sm_ip_test_M->rtwLogInfo, (NULL));
    rtliSetLogT(asyncip_sl_1_sm_ip_test_M->rtwLogInfo, "");
    rtliSetLogX(asyncip_sl_1_sm_ip_test_M->rtwLogInfo, "");
    rtliSetLogXFinal(asyncip_sl_1_sm_ip_test_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(asyncip_sl_1_sm_ip_test_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(asyncip_sl_1_sm_ip_test_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(asyncip_sl_1_sm_ip_test_M->rtwLogInfo, 0);
    rtliSetLogDecimation(asyncip_sl_1_sm_ip_test_M->rtwLogInfo, 1);
    rtliSetLogY(asyncip_sl_1_sm_ip_test_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(asyncip_sl_1_sm_ip_test_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(asyncip_sl_1_sm_ip_test_M->rtwLogInfo, (NULL));
  }

  asyncip_sl_1_sm_ip_test_M->solverInfoPtr =
    (&asyncip_sl_1_sm_ip_test_M->solverInfo);
  asyncip_sl_1_sm_ip_test_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&asyncip_sl_1_sm_ip_test_M->solverInfo, 0.01);
  rtsiSetSolverMode(&asyncip_sl_1_sm_ip_test_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  asyncip_sl_1_sm_ip_test_M->ModelData.blockIO = ((void *)
    &asyncip_sl_1_sm_ip_test_B);

  {
    asyncip_sl_1_sm_ip_test_B.SFunction = 0.0;
    asyncip_sl_1_sm_ip_test_B.Sum = 0.0;
    asyncip_sl_1_sm_ip_test_B.Constant = 0.0;
    asyncip_sl_1_sm_ip_test_B.Integrator[0] = 0.0;
    asyncip_sl_1_sm_ip_test_B.Integrator[1] = 0.0;
    asyncip_sl_1_sm_ip_test_B.Integrator[2] = 0.0;
    asyncip_sl_1_sm_ip_test_B.Integrator[3] = 0.0;
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold17[0] = 0.0;
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold17[1] = 0.0;
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold17[2] = 0.0;
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold17[3] = 0.0;
    asyncip_sl_1_sm_ip_test_B.Integrator1[0] = 0.0;
    asyncip_sl_1_sm_ip_test_B.Integrator1[1] = 0.0;
    asyncip_sl_1_sm_ip_test_B.Integrator1[2] = 0.0;
    asyncip_sl_1_sm_ip_test_B.Integrator1[3] = 0.0;
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold1[0] = 0.0;
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold1[1] = 0.0;
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold1[2] = 0.0;
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold1[3] = 0.0;
    asyncip_sl_1_sm_ip_test_B.Integrator2[0] = 0.0;
    asyncip_sl_1_sm_ip_test_B.Integrator2[1] = 0.0;
    asyncip_sl_1_sm_ip_test_B.Integrator2[2] = 0.0;
    asyncip_sl_1_sm_ip_test_B.Integrator2[3] = 0.0;
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold2[0] = 0.0;
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold2[1] = 0.0;
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold2[2] = 0.0;
    asyncip_sl_1_sm_ip_test_B.ZeroOrderHold2[3] = 0.0;
    asyncip_sl_1_sm_ip_test_B.SFunction2 = 0.0;
    asyncip_sl_1_sm_ip_test_B.timeout = 0.0;
    asyncip_sl_1_sm_ip_test_B.SFunction1_o1 = 0.0;
    asyncip_sl_1_sm_ip_test_B.SFunction1_o2 = 0.0;
    asyncip_sl_1_sm_ip_test_B.SFunction1_o3[0] = 0.0;
    asyncip_sl_1_sm_ip_test_B.SFunction1_o3[1] = 0.0;
    asyncip_sl_1_sm_ip_test_B.SFunction1_o3[2] = 0.0;
    asyncip_sl_1_sm_ip_test_B.Clock = 0.0;
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrator[0] = 0.0;
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrator[1] = 0.0;
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrator[2] = 0.0;
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrator[3] = 0.0;
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_n[0] = 0.0;
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_n[1] = 0.0;
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_n[2] = 0.0;
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_n[3] = 0.0;
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_p[0] = 0.0;
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_p[1] = 0.0;
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_p[2] = 0.0;
    asyncip_sl_1_sm_ip_test_B.TmpSignalConversionAtIntegrat_p[3] = 0.0;
    asyncip_sl_1_sm_ip_test_B.dx1_1 = 0.0;
    asyncip_sl_1_sm_ip_test_B.dx1_2 = 0.0;
    asyncip_sl_1_sm_ip_test_B.dx1_3 = 0.0;
    asyncip_sl_1_sm_ip_test_B.dx1_4 = 0.0;
    asyncip_sl_1_sm_ip_test_B.dx2_1 = 0.0;
    asyncip_sl_1_sm_ip_test_B.dx2_2 = 0.0;
    asyncip_sl_1_sm_ip_test_B.dx2_3 = 0.0;
    asyncip_sl_1_sm_ip_test_B.dx2_4 = 0.0;
    asyncip_sl_1_sm_ip_test_B.dx3_1 = 0.0;
    asyncip_sl_1_sm_ip_test_B.dx3_2 = 0.0;
    asyncip_sl_1_sm_ip_test_B.dx3_3 = 0.0;
    asyncip_sl_1_sm_ip_test_B.dx3_4 = 0.0;
    asyncip_sl_1_sm_ip_test_B.deltaPL[0] = 0.0;
    asyncip_sl_1_sm_ip_test_B.deltaPL[1] = 0.0;
    asyncip_sl_1_sm_ip_test_B.deltaPL[2] = 0.0;
  }

  /* parameters */
  asyncip_sl_1_sm_ip_test_M->ModelData.defaultParam = ((real_T *)
    &asyncip_sl_1_sm_ip_test_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &asyncip_sl_1_sm_ip_test_X;
    asyncip_sl_1_sm_ip_test_M->ModelData.contStates = (x);
    (void) memset((void *)&asyncip_sl_1_sm_ip_test_X, 0,
                  sizeof(X_asyncip_sl_1_sm_ip_test_T));
  }

  /* states (dwork) */
  asyncip_sl_1_sm_ip_test_M->ModelData.dwork = ((void *)
    &asyncip_sl_1_sm_ip_test_DW);
  (void) memset((void *)&asyncip_sl_1_sm_ip_test_DW, 0,
                sizeof(DW_asyncip_sl_1_sm_ip_test_T));
  asyncip_sl_1_sm_ip_test_DW.SFunction_PreviousInput = 0.0;

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.sfcnInfo;
    asyncip_sl_1_sm_ip_test_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (asyncip_sl_1_sm_ip_test_M)));
    asyncip_sl_1_sm_ip_test_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &asyncip_sl_1_sm_ip_test_M->Sizes.numSampTimes);
    asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (asyncip_sl_1_sm_ip_test_M)[0]);
    asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (asyncip_sl_1_sm_ip_test_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(asyncip_sl_1_sm_ip_test_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(asyncip_sl_1_sm_ip_test_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (asyncip_sl_1_sm_ip_test_M));
    rtssSetStepSizePtr(sfcnInfo, &asyncip_sl_1_sm_ip_test_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (asyncip_sl_1_sm_ip_test_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &asyncip_sl_1_sm_ip_test_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &asyncip_sl_1_sm_ip_test_M->ModelData.zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &asyncip_sl_1_sm_ip_test_M->ModelData.CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &asyncip_sl_1_sm_ip_test_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &asyncip_sl_1_sm_ip_test_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &asyncip_sl_1_sm_ip_test_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &asyncip_sl_1_sm_ip_test_M->solverInfoPtr);
  }

  asyncip_sl_1_sm_ip_test_M->Sizes.numSFcns = (4);

  /* register each child */
  {
    (void) memset((void *)
                  &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  4*sizeof(SimStruct));
    asyncip_sl_1_sm_ip_test_M->childSfunctions =
      (&asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    asyncip_sl_1_sm_ip_test_M->childSfunctions[0] =
      (&asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.childSFunctions[0]);
    asyncip_sl_1_sm_ip_test_M->childSfunctions[1] =
      (&asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.childSFunctions[1]);
    asyncip_sl_1_sm_ip_test_M->childSfunctions[2] =
      (&asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.childSFunctions[2]);
    asyncip_sl_1_sm_ip_test_M->childSfunctions[3] =
      (&asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.childSFunctions[3]);

    /* Level2 S-Function Block: asyncip_sl_1_sm_ip_test/<S7>/S-Function2 (sfun_send_async) */
    {
      SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, asyncip_sl_1_sm_ip_test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &asyncip_sl_1_sm_ip_test_M->
                         NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &asyncip_sl_1_sm_ip_test_B.Constant;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &asyncip_sl_1_sm_ip_test_B.ZeroOrderHold17[0];
          sfcnUPtrs[1] = &asyncip_sl_1_sm_ip_test_B.ZeroOrderHold17[1];
          sfcnUPtrs[2] = &asyncip_sl_1_sm_ip_test_B.ZeroOrderHold17[2];
          sfcnUPtrs[3] = &asyncip_sl_1_sm_ip_test_B.ZeroOrderHold17[3];
          sfcnUPtrs[4] = &asyncip_sl_1_sm_ip_test_B.ZeroOrderHold1[0];
          sfcnUPtrs[5] = &asyncip_sl_1_sm_ip_test_B.ZeroOrderHold1[1];
          sfcnUPtrs[6] = &asyncip_sl_1_sm_ip_test_B.ZeroOrderHold1[2];
          sfcnUPtrs[7] = &asyncip_sl_1_sm_ip_test_B.ZeroOrderHold1[3];
          sfcnUPtrs[8] = &asyncip_sl_1_sm_ip_test_B.ZeroOrderHold2[0];
          sfcnUPtrs[9] = &asyncip_sl_1_sm_ip_test_B.ZeroOrderHold2[1];
          sfcnUPtrs[10] = &asyncip_sl_1_sm_ip_test_B.ZeroOrderHold2[2];
          sfcnUPtrs[11] = &asyncip_sl_1_sm_ip_test_B.ZeroOrderHold2[3];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 12);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &asyncip_sl_1_sm_ip_test_B.SFunction2));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function2");
      ssSetPath(rts,
                "asyncip_sl_1_sm_ip_test/sm_ip_test/send message 1/S-Function2");
      ssSetRTModel(rts,asyncip_sl_1_sm_ip_test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 13);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction2_P13_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &asyncip_sl_1_sm_ip_test_DW.SFunction2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &asyncip_sl_1_sm_ip_test_DW.SFunction2_PWORK);
      }

      /* registration */
      sfun_send_async(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 1, 12);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: asyncip_sl_1_sm_ip_test/<S5>/S-Function1 (sfun_recv_async) */
    {
      SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, asyncip_sl_1_sm_ip_test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &asyncip_sl_1_sm_ip_test_M->
                         NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &asyncip_sl_1_sm_ip_test_B.timeout;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &asyncip_sl_1_sm_ip_test_B.SFunction1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &asyncip_sl_1_sm_ip_test_B.SFunction1_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 3);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            asyncip_sl_1_sm_ip_test_B.SFunction1_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "asyncip_sl_1_sm_ip_test/sm_ip_test/receive message 1/S-Function1");
      ssSetRTModel(rts,asyncip_sl_1_sm_ip_test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 14);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction1_P14_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &asyncip_sl_1_sm_ip_test_DW.SFunction1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &asyncip_sl_1_sm_ip_test_DW.SFunction1_PWORK);
      }

      /* registration */
      sfun_recv_async(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 2, 3);
      ssSetOutputPortDataType(rts, 2, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 2, 0);
      ssSetOutputPortFrameData(rts, 2, 0);
      ssSetOutputPortUnit(rts, 2, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 2, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: asyncip_sl_1_sm_ip_test/<S9>/S-Function (OP_SEND) */
    {
      SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, asyncip_sl_1_sm_ip_test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.methods4
                           [2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &asyncip_sl_1_sm_ip_test_M->
                         NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &asyncip_sl_1_sm_ip_test_B.SFunction2;
          sfcnUPtrs[1] = &asyncip_sl_1_sm_ip_test_B.SFunction1_o1;
          sfcnUPtrs[2] = &asyncip_sl_1_sm_ip_test_B.SFunction1_o2;
          sfcnUPtrs[3] = &asyncip_sl_1_sm_ip_test_B.SFunction1_o3[0];
          sfcnUPtrs[4] = &asyncip_sl_1_sm_ip_test_B.SFunction1_o3[1];
          sfcnUPtrs[5] = &asyncip_sl_1_sm_ip_test_B.SFunction1_o3[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 6);
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "asyncip_sl_1_sm_ip_test/sm_ip_test/rtlab_send_subsystem/Subsystem1/Send1/S-Function");
      ssSetRTModel(rts,asyncip_sl_1_sm_ip_test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.SFunction_P1_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &asyncip_sl_1_sm_ip_test_DW.SFunction_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &asyncip_sl_1_sm_ip_test_DW.SFunction_IWORK[0]);
      }

      /* registration */
      OP_SEND(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 6);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: asyncip_sl_1_sm_ip_test/<S2>/OpIPSocketCtrl1 (sfun_gen_async_ctrl) */
    {
      SimStruct *rts = asyncip_sl_1_sm_ip_test_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, asyncip_sl_1_sm_ip_test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.methods2
                           [3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.methods3
                           [3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.methods4
                           [3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &asyncip_sl_1_sm_ip_test_M->
                         NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* path info */
      ssSetModelName(rts, "OpIPSocketCtrl1");
      ssSetPath(rts, "asyncip_sl_1_sm_ip_test/sm_ip_test/OpIPSocketCtrl1");
      ssSetRTModel(rts,asyncip_sl_1_sm_ip_test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 27);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P24_Size);
        ssSetSFcnParam(rts, 24, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P25_Size);
        ssSetSFcnParam(rts, 25, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P26_Size);
        ssSetSFcnParam(rts, 26, (mxArray*)
                       asyncip_sl_1_sm_ip_test_P.OpIPSocketCtrl1_P27_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &asyncip_sl_1_sm_ip_test_DW.OpIPSocketCtrl1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &asyncip_sl_1_sm_ip_test_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &asyncip_sl_1_sm_ip_test_DW.OpIPSocketCtrl1_PWORK);
      }

      /* registration */
      sfun_gen_async_ctrl(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  asyncip_sl_1_sm_ip_test_M->Sizes.numContStates = (12);/* Number of continuous states */
  asyncip_sl_1_sm_ip_test_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  asyncip_sl_1_sm_ip_test_M->Sizes.numY = (0);/* Number of model outputs */
  asyncip_sl_1_sm_ip_test_M->Sizes.numU = (0);/* Number of model inputs */
  asyncip_sl_1_sm_ip_test_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  asyncip_sl_1_sm_ip_test_M->Sizes.numSampTimes = (2);/* Number of sample times */
  asyncip_sl_1_sm_ip_test_M->Sizes.numBlocks = (25);/* Number of blocks */
  asyncip_sl_1_sm_ip_test_M->Sizes.numBlockIO = (31);/* Number of block outputs */
  asyncip_sl_1_sm_ip_test_M->Sizes.numBlockPrms = (254);/* Sum of parameter "widths" */
  return asyncip_sl_1_sm_ip_test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
