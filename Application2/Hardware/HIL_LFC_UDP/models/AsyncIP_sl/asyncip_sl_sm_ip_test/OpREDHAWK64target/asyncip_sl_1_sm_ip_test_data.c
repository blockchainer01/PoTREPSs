/*
 * asyncip_sl_1_sm_ip_test_data.c
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

/* Block parameters (default storage) */
P_asyncip_sl_1_sm_ip_test_T asyncip_sl_1_sm_ip_test_P = {
  /* Expression: 0
   * Referenced by: '<S1>/S-Function1' (Parameter: Value)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/S-Function' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant' (Parameter: Value)
   */
  1.0,

  /* Expression: zeros(4,1)
   * Referenced by: '<S2>/Integrator' (Parameter: InitialCondition)
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: zeros(4,1)
   * Referenced by: '<S2>/Integrator1' (Parameter: InitialCondition)
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: zeros(4,1)
   * Referenced by: '<S2>/Integrator2' (Parameter: InitialCondition)
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: SFunction2_P1_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P1Size)
   */
  { 1.0, 1.0 },

  /* Expression: ctl_id
   * Referenced by: '<S7>/S-Function2' (Parameter: P1)
   */
  1.0,

  /* Computed Parameter: SFunction2_P2_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P2Size)
   */
  { 1.0, 1.0 },

  /* Expression: send_id
   * Referenced by: '<S7>/S-Function2' (Parameter: P2)
   */
  1.0,

  /* Computed Parameter: SFunction2_P3_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P3Size)
   */
  { 1.0, 1.0 },

  /* Expression: mode
   * Referenced by: '<S7>/S-Function2' (Parameter: P3)
   */
  3.0,

  /* Computed Parameter: SFunction2_P4_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P4Size)
   */
  { 1.0, 1.0 },

  /* Expression: fp1
   * Referenced by: '<S7>/S-Function2' (Parameter: P4)
   */
  1.0,

  /* Computed Parameter: SFunction2_P5_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P5Size)
   */
  { 1.0, 1.0 },

  /* Expression: fp2
   * Referenced by: '<S7>/S-Function2' (Parameter: P5)
   */
  2.0,

  /* Computed Parameter: SFunction2_P6_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P6Size)
   */
  { 1.0, 1.0 },

  /* Expression: fp3
   * Referenced by: '<S7>/S-Function2' (Parameter: P6)
   */
  3.0,

  /* Computed Parameter: SFunction2_P7_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P7Size)
   */
  { 1.0, 1.0 },

  /* Expression: fp4
   * Referenced by: '<S7>/S-Function2' (Parameter: P7)
   */
  4.0,

  /* Computed Parameter: SFunction2_P8_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P8Size)
   */
  { 1.0, 1.0 },

  /* Expression: fp5
   * Referenced by: '<S7>/S-Function2' (Parameter: P8)
   */
  5.0,

  /* Computed Parameter: SFunction2_P9_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P9Size)
   */
  { 1.0, 7.0 },

  /* Computed Parameter: SFunction2_P9
   * Referenced by: '<S7>/S-Function2' (Parameter: P9)
   */
  { 115.0, 116.0, 114.0, 105.0, 110.0, 103.0, 49.0 },

  /* Computed Parameter: SFunction2_P10_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P10Size)
   */
  { 1.0, 7.0 },

  /* Computed Parameter: SFunction2_P10
   * Referenced by: '<S7>/S-Function2' (Parameter: P10)
   */
  { 115.0, 116.0, 114.0, 105.0, 110.0, 103.0, 50.0 },

  /* Computed Parameter: SFunction2_P11_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P11Size)
   */
  { 1.0, 7.0 },

  /* Computed Parameter: SFunction2_P11
   * Referenced by: '<S7>/S-Function2' (Parameter: P11)
   */
  { 115.0, 116.0, 114.0, 105.0, 110.0, 103.0, 51.0 },

  /* Computed Parameter: SFunction2_P12_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P12Size)
   */
  { 1.0, 7.0 },

  /* Computed Parameter: SFunction2_P12
   * Referenced by: '<S7>/S-Function2' (Parameter: P12)
   */
  { 115.0, 116.0, 114.0, 105.0, 110.0, 103.0, 52.0 },

  /* Computed Parameter: SFunction2_P13_Size
   * Referenced by: '<S7>/S-Function2' (Parameter: P13Size)
   */
  { 1.0, 7.0 },

  /* Computed Parameter: SFunction2_P13
   * Referenced by: '<S7>/S-Function2' (Parameter: P13)
   */
  { 115.0, 116.0, 114.0, 105.0, 110.0, 103.0, 53.0 },

  /* Expression: 2
   * Referenced by: '<S2>/timeout' (Parameter: Value)
   */
  2.0,

  /* Computed Parameter: SFunction1_P1_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P1Size)
   */
  { 1.0, 1.0 },

  /* Expression: ctl_id
   * Referenced by: '<S5>/S-Function1' (Parameter: P1)
   */
  1.0,

  /* Computed Parameter: SFunction1_P2_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P2Size)
   */
  { 1.0, 1.0 },

  /* Expression: recv_id
   * Referenced by: '<S5>/S-Function1' (Parameter: P2)
   */
  1.0,

  /* Computed Parameter: SFunction1_P3_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P3Size)
   */
  { 1.0, 1.0 },

  /* Expression: fp1
   * Referenced by: '<S5>/S-Function1' (Parameter: P3)
   */
  1.0,

  /* Computed Parameter: SFunction1_P4_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P4Size)
   */
  { 1.0, 1.0 },

  /* Expression: fp2
   * Referenced by: '<S5>/S-Function1' (Parameter: P4)
   */
  2.0,

  /* Computed Parameter: SFunction1_P5_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P5Size)
   */
  { 1.0, 1.0 },

  /* Expression: fp3
   * Referenced by: '<S5>/S-Function1' (Parameter: P5)
   */
  3.0,

  /* Computed Parameter: SFunction1_P6_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P6Size)
   */
  { 1.0, 1.0 },

  /* Expression: fp4
   * Referenced by: '<S5>/S-Function1' (Parameter: P6)
   */
  4.0,

  /* Computed Parameter: SFunction1_P7_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P7Size)
   */
  { 1.0, 1.0 },

  /* Expression: fp5
   * Referenced by: '<S5>/S-Function1' (Parameter: P7)
   */
  5.0,

  /* Computed Parameter: SFunction1_P8_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P8Size)
   */
  { 1.0, 7.0 },

  /* Computed Parameter: SFunction1_P8
   * Referenced by: '<S5>/S-Function1' (Parameter: P8)
   */
  { 115.0, 116.0, 114.0, 105.0, 110.0, 103.0, 49.0 },

  /* Computed Parameter: SFunction1_P9_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P9Size)
   */
  { 1.0, 7.0 },

  /* Computed Parameter: SFunction1_P9
   * Referenced by: '<S5>/S-Function1' (Parameter: P9)
   */
  { 115.0, 116.0, 114.0, 105.0, 110.0, 103.0, 50.0 },

  /* Computed Parameter: SFunction1_P10_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P10Size)
   */
  { 1.0, 7.0 },

  /* Computed Parameter: SFunction1_P10
   * Referenced by: '<S5>/S-Function1' (Parameter: P10)
   */
  { 115.0, 116.0, 114.0, 105.0, 110.0, 103.0, 51.0 },

  /* Computed Parameter: SFunction1_P11_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P11Size)
   */
  { 1.0, 7.0 },

  /* Computed Parameter: SFunction1_P11
   * Referenced by: '<S5>/S-Function1' (Parameter: P11)
   */
  { 115.0, 116.0, 114.0, 105.0, 110.0, 103.0, 52.0 },

  /* Computed Parameter: SFunction1_P12_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P12Size)
   */
  { 1.0, 7.0 },

  /* Computed Parameter: SFunction1_P12
   * Referenced by: '<S5>/S-Function1' (Parameter: P12)
   */
  { 115.0, 116.0, 114.0, 105.0, 110.0, 103.0, 53.0 },

  /* Computed Parameter: SFunction1_P13_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P13Size)
   */
  { 1.0, 1.0 },

  /* Computed Parameter: SFunction1_P13
   * Referenced by: '<S5>/S-Function1' (Parameter: P13)
   */
  54.0,

  /* Computed Parameter: SFunction1_P14_Size
   * Referenced by: '<S5>/S-Function1' (Parameter: P14Size)
   */
  { 1.0, 1.0 },

  /* Computed Parameter: SFunction1_P14
   * Referenced by: '<S5>/S-Function1' (Parameter: P14)
   */
  55.0,

  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S9>/S-Function' (Parameter: P1Size)
   */
  { 1.0, 1.0 },

  /* Expression: Acqu_group
   * Referenced by: '<S9>/S-Function' (Parameter: P1)
   */
  1.0,

  /* Computed Parameter: OpIPSocketCtrl1_P1_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P1Size)
   */
  { 1.0, 1.0 },

  /* Expression: ctl_id
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P1)
   */
  1.0,

  /* Computed Parameter: OpIPSocketCtrl1_P2_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P2Size)
   */
  { 1.0, 1.0 },

  /* Expression: proto
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P2)
   */
  1.0,

  /* Computed Parameter: OpIPSocketCtrl1_P3_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P3Size)
   */
  { 1.0, 1.0 },

  /* Expression: ip_port_remote
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P3)
   */
  8080.0,

  /* Computed Parameter: OpIPSocketCtrl1_P4_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P4Size)
   */
  { 1.0, 1.0 },

  /* Expression: ip_port_local
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P4)
   */
  8080.0,

  /* Computed Parameter: OpIPSocketCtrl1_P5_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P5Size)
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P5)
   */
  0.0,

  /* Computed Parameter: OpIPSocketCtrl1_P6_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P6Size)
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P6)
   */
  0.0,

  /* Computed Parameter: OpIPSocketCtrl1_P7_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P7Size)
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P7)
   */
  0.0,

  /* Computed Parameter: OpIPSocketCtrl1_P8_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P8Size)
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P8)
   */
  0.0,

  /* Computed Parameter: OpIPSocketCtrl1_P9_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P9Size)
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P9)
   */
  0.0,

  /* Computed Parameter: OpIPSocketCtrl1_P10_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P10Size)
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P10)
   */
  0.0,

  /* Computed Parameter: OpIPSocketCtrl1_P11_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P11Size)
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P11)
   */
  0.0,

  /* Computed Parameter: OpIPSocketCtrl1_P12_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P12Size)
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P12)
   */
  0.0,

  /* Computed Parameter: OpIPSocketCtrl1_P13_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P13Size)
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P13)
   */
  0.0,

  /* Computed Parameter: OpIPSocketCtrl1_P14_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P14Size)
   */
  { 1.0, 12.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P14
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P14)
   */
  { 49.0, 48.0, 46.0, 54.0, 52.0, 46.0, 49.0, 49.0, 55.0, 46.0, 55.0, 48.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P15_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P15Size)
   */
  { 1.0, 7.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P15
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P15)
   */
  { 48.0, 46.0, 48.0, 46.0, 48.0, 46.0, 48.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P16_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P16Size)
   */
  { 0.0, 0.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P17_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P17Size)
   */
  { 0.0, 0.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P18_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P18Size)
   */
  { 0.0, 0.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P19_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P19Size)
   */
  { 0.0, 0.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P20_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P20Size)
   */
  { 0.0, 0.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P21_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P21Size)
   */
  { 0.0, 0.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P22_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P22Size)
   */
  { 0.0, 0.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P23_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P23Size)
   */
  { 0.0, 0.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P24_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P24Size)
   */
  { 0.0, 0.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P25_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P25Size)
   */
  { 0.0, 0.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P26_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P26Size)
   */
  { 1.0, 7.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P26
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P26)
   */
  { 65.0, 115.0, 121.0, 110.0, 99.0, 73.0, 80.0 },

  /* Computed Parameter: OpIPSocketCtrl1_P27_Size
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P27Size)
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S2>/OpIPSocketCtrl1' (Parameter: P27)
   */
  0.0
};
