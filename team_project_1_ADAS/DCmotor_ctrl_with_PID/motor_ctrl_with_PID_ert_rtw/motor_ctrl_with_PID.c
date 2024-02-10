/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_ctrl_with_PID.c
 *
 * Code generated for Simulink model 'motor_ctrl_with_PID'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Feb 10 22:03:59 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_ctrl_with_PID.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "motor_ctrl_with_PID_private.h"

/* Block signals (default storage) */
B_motor_ctrl_with_PID_T motor_ctrl_with_PID_B;

/* Block states (default storage) */
DW_motor_ctrl_with_PID_T motor_ctrl_with_PID_DW;

/* Real-time model */
static RT_MODEL_motor_ctrl_with_PID_T motor_ctrl_with_PID_M_;
RT_MODEL_motor_ctrl_with_PID_T *const motor_ctrl_with_PID_M =
  &motor_ctrl_with_PID_M_;
void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

int32_T MultiWord2sLong(const uint32_T u[])
{
  return (int32_T)u[0];
}

void sMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  int16_T i;
  int16_T i1;
  int16_T nb;
  int16_T nc;
  uint16_T nr;
  nb = (int16_T)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint16_T)nb << 5);
    if (nr > 0U) {
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      y[i] = (nc < n1 ? u1[nc] : ys) << (32U - nr) | u1i >> nr;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void sMultiWordShl(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  int16_T i;
  int16_T nb;
  int16_T nc;
  uint16_T nl;
  nb = (int16_T)(n2 >> 5);
  ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
  nc = nb > n ? n : nb;
  u1i = 0UL;
  for (i = 0; i < nc; i++) {
    y[i] = 0UL;
  }

  if (nb < n) {
    nl = n2 - ((uint16_T)nb << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      for (nc = 0; nc < nb; nc++) {
        yi = u1i >> (32U - nl);
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> (32U - nl) | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void sLong2MultiWord(int32_T u, uint32_T y[], int16_T n)
{
  uint32_T yi;
  int16_T i;
  y[0] = (uint32_T)u;
  yi = u < 0L ? MAX_uint32_T : 0UL;
  for (i = 1; i < n; i++) {
    y[i] = yi;
  }
}

void MultiWordSub(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int16_T n)
{
  uint32_T borrow = 0UL;
  uint32_T u1i;
  uint32_T yi;
  int16_T i;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i - u2[i]) - borrow;
    y[i] = yi;
    borrow = borrow != 0UL ? (uint32_T)(yi >= u1i) : (uint32_T)(yi > u1i);
  }
}

void sMultiWord2MultiWord(const uint32_T u1[], int16_T n1, uint32_T y[], int16_T
  n)
{
  uint32_T u1i;
  int16_T i;
  int16_T nm;
  nm = n1 < n ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    u1i = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
    for (i = nm; i < n; i++) {
      y[i] = u1i;
    }
  }
}

void sMultiWordDivFloor(const uint32_T u1[], int16_T n1, const uint32_T u2[],
  int16_T n2, uint32_T y1[], int16_T m1, uint32_T y2[], int16_T m2, uint32_T t1[],
  int16_T l1, uint32_T t2[], int16_T l2)
{
  boolean_T denNeg;
  boolean_T numNeg;
  numNeg = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  denNeg = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  if (numNeg) {
    MultiWordNeg(u1, t1, n1);
  } else {
    sMultiWord2MultiWord(u1, n1, t1, l1);
  }

  if (denNeg) {
    MultiWordNeg(u2, t2, n2);
  } else {
    sMultiWord2MultiWord(u2, n2, t2, l2);
  }

  if (uMultiWordDiv(t1, l1, t2, l2, y1, m1, y2, m2) < 0) {
    if (numNeg) {
      MultiWordSetSignedMin(y1, m1);
    } else {
      MultiWordSetSignedMax(y1, m1);
    }
  } else if ((boolean_T)(numNeg ^ denNeg)) {
    if (MultiWord2Bool(y2, m2)) {
      uMultiWordInc(y1, m1);
    }

    MultiWordNeg(y1, y1, m1);
  }
}

void MultiWordNeg(const uint32_T u1[], uint32_T y[], int16_T n)
{
  uint32_T carry = 1UL;
  uint32_T yi;
  int16_T i;
  for (i = 0; i < n; i++) {
    yi = ~u1[i] + carry;
    y[i] = yi;
    carry = (uint32_T)(yi < carry);
  }
}

void MultiWordSetSignedMin(uint32_T y[], int16_T n)
{
  int16_T i;
  int16_T n1;
  n1 = n - 1;
  for (i = 0; i < n1; i++) {
    y[i] = 0UL;
  }

  y[n - 1] = 2147483648UL;
}

void MultiWordSetSignedMax(uint32_T y[], int16_T n)
{
  int16_T i;
  int16_T n1;
  n1 = n - 1;
  for (i = 0; i < n1; i++) {
    y[i] = MAX_uint32_T;
  }

  y[n - 1] = 2147483647UL;
}

void uMultiWordInc(uint32_T y[], int16_T n)
{
  uint32_T carry = 1UL;
  uint32_T yi;
  int16_T i;
  for (i = 0; i < n; i++) {
    yi = y[i] + carry;
    y[i] = yi;
    carry = (uint32_T)(yi < carry);
  }
}

boolean_T MultiWord2Bool(const uint32_T u[], int16_T n)
{
  int16_T i;
  boolean_T y;
  y = false;
  i = 0;
  while ((i < n) && (!y)) {
    if (u[i] != 0UL) {
      y = true;
    }

    i++;
  }

  return y;
}

int16_T uMultiWordDiv(uint32_T a[], int16_T na, uint32_T b[], int16_T nb,
                      uint32_T q[], int16_T nq, uint32_T r[], int16_T nr)
{
  uint32_T ak;
  uint32_T bb;
  uint32_T bk;
  uint32_T mask;
  uint32_T t;
  int16_T ka;
  int16_T kr;
  int16_T na1;
  int16_T nb1;
  int16_T nza;
  int16_T nzb;
  int16_T tpi;
  int16_T y;
  uint16_T kba;
  uint16_T kbb;
  uint16_T nba;
  uint16_T nbb;
  uint16_T nbq;
  uint16_T tnb;
  nzb = nb;
  tpi = nb - 1;
  while ((nzb > 0) && (b[tpi] == 0UL)) {
    nzb--;
    tpi--;
  }

  if (nzb > 0) {
    nza = na;
    for (tpi = 0; tpi < nq; tpi++) {
      q[tpi] = 0UL;
    }

    tpi = na - 1;
    while ((nza > 0) && (a[tpi] == 0UL)) {
      nza--;
      tpi--;
    }

    if ((nza > 0) && (nza >= nzb)) {
      nb1 = nzb - 1;
      na1 = nza - 1;
      for (kr = 0; kr < nr; kr++) {
        r[kr] = 0UL;
      }

      /* Quick return if dividend and divisor fit into single word. */
      if (nza == 1) {
        ak = a[0];
        bk = b[0];
        bb = ak / bk;
        q[0] = bb;
        r[0] = ak - bb * bk;
        y = 7;
      } else {
        /* Remove leading zeros from both, dividend and divisor. */
        kbb = 1U;
        t = b[nzb - 1] >> 1U;
        while (t != 0UL) {
          kbb++;
          t >>= 1U;
        }

        kba = 1U;
        t = a[nza - 1] >> 1U;
        while (t != 0UL) {
          kba++;
          t >>= 1U;
        }

        /* Quick return if quotient is zero. */
        if ((nza > nzb) || (kba >= kbb)) {
          nba = ((uint16_T)(nza - 1) << 5) + kba;
          nbb = ((uint16_T)(nzb - 1) << 5) + kbb;

          /* Normalize b. */
          if (kbb != 32U) {
            bk = b[nzb - 1];
            for (kr = nzb - 1; kr > 0; kr--) {
              t = bk << (32U - kbb);
              bk = b[kr - 1];
              t |= bk >> kbb;
              b[kr] = t;
            }

            b[kr] = bk << (32U - kbb);
            mask = ~((1UL << (32U - kbb)) - 1UL);
          } else {
            mask = MAX_uint32_T;
          }

          /* Initialize quotient to zero. */
          tnb = 0U;
          y = 0;

          /* Until exit conditions have been met, do */
          do {
            /* Normalize a */
            if (kba != 32U) {
              tnb = (tnb - kba) + 32U;
              ak = a[na1];
              for (ka = na1; ka > 0; ka--) {
                t = ak << (32U - kba);
                ak = a[ka - 1];
                t |= ak >> kba;
                a[ka] = t;
              }

              a[ka] = ak << (32U - kba);
            }

            /* Compare b against the a. */
            ak = a[na1];
            bk = b[nzb - 1];
            if (((nzb - 1 == 0 ? mask : MAX_uint32_T) & ak) == bk) {
              tpi = 0;
              ka = na1;
              kr = nzb - 1;
              while ((tpi == 0) && (kr > 0)) {
                ka--;
                ak = a[ka];
                kr--;
                bk = b[kr];
                if (((kr == 0 ? mask : MAX_uint32_T) & ak) != bk) {
                  tpi = ak > bk ? 1 : -1;
                }
              }
            } else {
              tpi = ak > bk ? 1 : -1;
            }

            /* If the remainder in a is still greater or equal to b, subtract normalized divisor from a. */
            if ((tpi >= 0) || (nba > nbb)) {
              nbq = nba - nbb;

              /* If the remainder and the divisor are equal, set remainder to zero. */
              if (tpi == 0) {
                ka = na1;
                for (kr = nzb - 1; kr > 0; kr--) {
                  a[ka] = 0UL;
                  ka--;
                }

                a[ka] -= b[kr];
              } else {
                /* Otherwise, subtract the divisor from the remainder */
                if (tpi < 0) {
                  ak = a[na1];
                  kba = 31U;
                  for (ka = na1; ka > 0; ka--) {
                    t = ak << 1U;
                    ak = a[ka - 1];
                    t |= ak >> 31U;
                    a[ka] = t;
                  }

                  a[ka] = ak << 1U;
                  tnb++;
                  nbq--;
                }

                bb = 0UL;
                ka = (na1 - nzb) + 1;
                for (kr = 0; kr < nzb; kr++) {
                  t = a[ka];
                  ak = (t - b[kr]) - bb;
                  bb = bb != 0UL ? (uint32_T)(ak >= t) : (uint32_T)(ak > t);
                  a[ka] = ak;
                  ka++;
                }
              }

              /* Update the quotient. */
              tpi = (int16_T)(nbq >> 5);
              q[tpi] |= 1UL << (nbq - ((uint16_T)tpi << 5));

              /* Remove leading zeros from the remainder and check whether the exit conditions have been met. */
              tpi = na1;
              while ((nza > 0) && (a[tpi] == 0UL)) {
                nza--;
                tpi--;
              }

              if (nza >= nzb) {
                na1 = nza - 1;
                kba = 1U;
                t = a[nza - 1] >> 1U;
                while (t != 0UL) {
                  kba++;
                  t >>= 1U;
                }

                nba = (((uint16_T)(nza - 1) << 5) + kba) - tnb;
                if (nba < nbb) {
                  y = 2;
                }
              } else if (nza == 0) {
                y = 1;
              } else {
                na1 = nza - 1;
                y = 4;
              }
            } else {
              y = 3;
            }
          } while (y == 0);

          /* Return the remainder. */
          if (y == 1) {
            r[0] = a[0];
          } else {
            tpi = (int16_T)(tnb >> 5);
            kba = tnb - ((uint16_T)tpi << 5);
            if (kba == 0U) {
              ka = tpi;
              for (kr = 0; kr <= nb1; kr++) {
                r[kr] = a[ka];
                ka++;
              }
            } else {
              ak = a[tpi];
              kr = 0;
              for (ka = tpi + 1; ka <= na1; ka++) {
                t = ak >> kba;
                ak = a[ka];
                t |= ak << (32U - kba);
                r[kr] = t;
                kr++;
              }

              r[kr] = ak >> kba;
            }
          }

          /* Restore b. */
          if (kbb != 32U) {
            bk = b[0];
            for (kr = 0; kr < nb1; kr++) {
              t = bk >> (32U - kbb);
              bk = b[kr + 1];
              t |= bk << kbb;
              b[kr] = t;
            }

            b[kr] = bk >> (32U - kbb);
          }
        } else {
          for (kr = 0; kr < nr; kr++) {
            r[kr] = a[kr];
          }

          y = 6;
        }
      }
    } else {
      for (kr = 0; kr < nr; kr++) {
        r[kr] = a[kr];
      }

      y = 5;
    }
  } else {
    y = -1;
  }

  return y;
}

boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  return sMultiWordCmp(u1, u2, n) >= 0;
}

int16_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  uint32_T su1;
  uint32_T u2i;
  int16_T i;
  int16_T y;
  su1 = u1[n - 1] & 2147483648UL;
  if ((u2[n - 1] & 2147483648UL) != su1) {
    y = su1 != 0UL ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      u2i = u2[i];
      if (su1 != u2i) {
        y = su1 > u2i ? 1 : -1;
      }
    }
  }

  return y;
}

/* Model step function */
void motor_ctrl_with_PID_step(void)
{
  /* local block i/o variables */
  int32_T rtb_TSamp;

  {
    int128m_T tmp_2;
    int128m_T tmp_3;
    real_T tmp;
    uint32_T tmp_0;
    uint32_T tmp_1;
    static const int64m_T tmp_4 = { { 0UL, 0UL }/* chunks */
    };

    static const int64m_T tmp_5 = { { 25UL, 0UL }/* chunks */
    };

    /* Step: '<S1>/Step2' */
    if (motor_ctrl_with_PID_M->Timing.t[0] < motor_ctrl_with_PID_P.Step2_Time) {
      /* DataTypeConversion: '<S1>/Data Type Conversion' */
      tmp = floor(motor_ctrl_with_PID_P.Step2_Y0);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 256.0);
      }

      /* DataTypeConversion: '<S1>/Data Type Conversion' */
      motor_ctrl_with_PID_B.DataTypeConversion = (uint8_T)(tmp < 0.0 ? (int16_T)
        (uint8_T)-(int8_T)(uint8_T)-tmp : (int16_T)(uint8_T)tmp);
    } else {
      /* DataTypeConversion: '<S1>/Data Type Conversion' */
      tmp = floor(motor_ctrl_with_PID_P.Wref);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 256.0);
      }

      /* DataTypeConversion: '<S1>/Data Type Conversion' */
      motor_ctrl_with_PID_B.DataTypeConversion = (uint8_T)(tmp < 0.0 ? (int16_T)
        (uint8_T)-(int8_T)(uint8_T)-tmp : (int16_T)(uint8_T)tmp);
    }

    /* End of Step: '<S1>/Step2' */

    /* MATLABSystem: '<S1>/PWM' */
    motor_ctrl_with_PID_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (11UL);
    MW_PWM_SetDutyCycle(motor_ctrl_with_PID_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)motor_ctrl_with_PID_B.DataTypeConversion);

    /* MATLABSystem: '<S2>/Encoder' */
    if (motor_ctrl_with_PID_DW.obj.SampleTime !=
        motor_ctrl_with_PID_P.Encoder_SampleTime) {
      motor_ctrl_with_PID_DW.obj.SampleTime =
        motor_ctrl_with_PID_P.Encoder_SampleTime;
    }

    if (motor_ctrl_with_PID_DW.obj.TunablePropsChanged) {
      motor_ctrl_with_PID_DW.obj.TunablePropsChanged = false;
    }

    /* SampleTimeMath: '<S3>/TSamp' incorporates:
     *  MATLABSystem: '<S2>/Encoder'
     * *
     * About '<S3>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *  Multiplication by K = weightedTsampQuantized is being
     *  done implicitly by changing the scaling of the input signal.
     *  No work needs to be done here.  Downstream blocks may need
     *  to do work to handle the scaling of the output; this happens
     *  automatically.
     */
    MW_EncoderRead(motor_ctrl_with_PID_DW.obj.Index, &rtb_TSamp);

    /* Gain: '<S2>/Gain1' incorporates:
     *  SampleTimeMath: '<S3>/TSamp'
     *  Sum: '<S3>/Diff'
     *  UnitDelay: '<S3>/UD'
     *
     * About '<S3>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *  Multiplication by K = weightedTsampQuantized is being
     *  done implicitly by changing the scaling of the input signal.
     *  No work needs to be done here.  Downstream blocks may need
     *  to do work to handle the scaling of the output; this happens
     *  automatically.
     *
     * Block description for '<S3>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S3>/UD':
     *
     *  Store in Global RAM
     */
    tmp_0 = (uint32_T)motor_ctrl_with_PID_P.encoder_scale;
    tmp_1 = (uint32_T)(rtb_TSamp - motor_ctrl_with_PID_DW.UD_DSTATE);
    sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &motor_ctrl_with_PID_B.Gain1.chunks[0U],
                  2);

    /* Gain: '<S2>/Gain2' incorporates:
     *  Gain: '<S2>/Gain1'
     */
    sMultiWordMul(&motor_ctrl_with_PID_P.Gain2_Gain.chunks[0U], 2,
                  &motor_ctrl_with_PID_B.Gain1.chunks[0U], 2,
                  &motor_ctrl_with_PID_B.Gain2.chunks[0U], 4);

    /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
     *  Gain: '<S2>/Gain1'
     */
    sMultiWordMul(&motor_ctrl_with_PID_B.Gain1.chunks[0U], 2, &tmp_5.chunks[0U],
                  2, &tmp_3.chunks[0U], 4);
    sMultiWordShr(&tmp_3.chunks[0U], 4, 31U, &tmp_2.chunks[0U], 4);

    /* DataTypeConversion: '<S2>/Data Type Conversion1' */
    motor_ctrl_with_PID_B.DataTypeConversion1 = MultiWord2sLong(&tmp_2.chunks[0U]);

    /* DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
    motor_ctrl_with_PID_B.DiscreteTransferFcn = tmp_4;

    /* DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
    tmp_0 = (uint32_T)motor_ctrl_with_PID_P.num_Gd[1L];
    tmp_1 = (uint32_T)motor_ctrl_with_PID_DW.DiscreteTransferFcn_states;
    sMultiWordMul(&tmp_0, 1, &tmp_1, 1,
                  &motor_ctrl_with_PID_B.DiscreteTransferFcn.chunks[0U], 2);
  }

  {
    int64m_T denAccum;
    int64m_T denAccum_0;
    int64m_T tmp;
    int64m_T tmp_0;
    int64m_T tmp_4;
    int96m_T tmp_3;
    uint32_T tmp_1;
    uint32_T tmp_2;
    static const int64m_T tmp_5 = { { MAX_uint32_T, 2147483647UL }/* chunks */
    };

    static const int64m_T tmp_6 = { { 0UL, 0UL }/* chunks */
    };

    static const int64m_T tmp_7 = { { 0UL, 2147483648UL }/* chunks */
    };

    /* Update for UnitDelay: '<S3>/UD' incorporates:
     *  SampleTimeMath: '<S3>/TSamp'
     *
     * About '<S3>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *  Multiplication by K = weightedTsampQuantized is being
     *  done implicitly by changing the scaling of the input signal.
     *  No work needs to be done here.  Downstream blocks may need
     *  to do work to handle the scaling of the output; this happens
     *  automatically.
     *
     * Block description for '<S3>/UD':
     *
     *  Store in Global RAM
     */
    motor_ctrl_with_PID_DW.UD_DSTATE = rtb_TSamp;

    /* Update for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
    sLong2MultiWord(motor_ctrl_with_PID_B.DataTypeConversion1, &tmp_0.chunks[0U],
                    2);
    sMultiWordShl(&tmp_0.chunks[0U], 2, 30U, &denAccum.chunks[0U], 2);
    tmp_1 = (uint32_T)motor_ctrl_with_PID_P.den_Gd[1L];
    tmp_2 = (uint32_T)motor_ctrl_with_PID_DW.DiscreteTransferFcn_states;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_0.chunks[0U], 2);
    MultiWordSub(&denAccum.chunks[0U], &tmp_0.chunks[0U], &denAccum_0.chunks[0U],
                 2);
    if (motor_ctrl_with_PID_P.den_Gd[0] == 0L) {
      if (sMultiWordGe(&denAccum_0.chunks[0U], &tmp_6.chunks[0U], 2)) {
        tmp = tmp_5;
      } else {
        tmp = tmp_7;
      }
    } else {
      sMultiWord2MultiWord(&denAccum_0.chunks[0U], 2,
                           &motor_ctrl_with_PID_B.r2.chunks[0U], 3);
      sMultiWordShl(&motor_ctrl_with_PID_B.r2.chunks[0U], 3, 30U,
                    &motor_ctrl_with_PID_B.r1.chunks[0U], 3);
      sLong2MultiWord(motor_ctrl_with_PID_P.den_Gd[0],
                      &motor_ctrl_with_PID_B.r2.chunks[0U], 3);
      sMultiWordDivFloor(&motor_ctrl_with_PID_B.r1.chunks[0U], 3,
                         &motor_ctrl_with_PID_B.r2.chunks[0U], 3,
                         &motor_ctrl_with_PID_B.r.chunks[0U], 4,
                         &motor_ctrl_with_PID_B.r3.chunks[0U], 3,
                         &motor_ctrl_with_PID_B.r4.chunks[0U], 3, &tmp_3.chunks
                         [0U], 3);
      sMultiWord2MultiWord(&motor_ctrl_with_PID_B.r.chunks[0U], 4, &tmp.chunks
                           [0U], 2);
    }

    sMultiWordShr(&tmp.chunks[0U], 2, 30U, &tmp_4.chunks[0U], 2);
    motor_ctrl_with_PID_DW.DiscreteTransferFcn_states = MultiWord2sLong
      (&tmp_4.chunks[0U]);

    /* End of Update for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((motor_ctrl_with_PID_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((motor_ctrl_with_PID_M->Timing.clockTick1 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  motor_ctrl_with_PID_M->Timing.t[0] =
    ((time_T)(++motor_ctrl_with_PID_M->Timing.clockTick0)) *
    motor_ctrl_with_PID_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    motor_ctrl_with_PID_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void motor_ctrl_with_PID_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&motor_ctrl_with_PID_M->solverInfo,
                          &motor_ctrl_with_PID_M->Timing.simTimeStep);
    rtsiSetTPtr(&motor_ctrl_with_PID_M->solverInfo, &rtmGetTPtr
                (motor_ctrl_with_PID_M));
    rtsiSetStepSizePtr(&motor_ctrl_with_PID_M->solverInfo,
                       &motor_ctrl_with_PID_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&motor_ctrl_with_PID_M->solverInfo,
                          (&rtmGetErrorStatus(motor_ctrl_with_PID_M)));
    rtsiSetRTModelPtr(&motor_ctrl_with_PID_M->solverInfo, motor_ctrl_with_PID_M);
  }

  rtsiSetSimTimeStep(&motor_ctrl_with_PID_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&motor_ctrl_with_PID_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(motor_ctrl_with_PID_M, &motor_ctrl_with_PID_M->Timing.tArray[0]);
  rtmSetTFinal(motor_ctrl_with_PID_M, -1);
  motor_ctrl_with_PID_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  motor_ctrl_with_PID_M->Sizes.checksums[0] = (3542897183U);
  motor_ctrl_with_PID_M->Sizes.checksums[1] = (1685557345U);
  motor_ctrl_with_PID_M->Sizes.checksums[2] = (1412882960U);
  motor_ctrl_with_PID_M->Sizes.checksums[3] = (482913223U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    motor_ctrl_with_PID_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motor_ctrl_with_PID_M->extModeInfo,
      &motor_ctrl_with_PID_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motor_ctrl_with_PID_M->extModeInfo,
                        motor_ctrl_with_PID_M->Sizes.checksums);
    rteiSetTPtr(motor_ctrl_with_PID_M->extModeInfo, rtmGetTPtr
                (motor_ctrl_with_PID_M));
  }

  /* InitializeConditions for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  motor_ctrl_with_PID_DW.UD_DSTATE =
    motor_ctrl_with_PID_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
  motor_ctrl_with_PID_DW.DiscreteTransferFcn_states =
    motor_ctrl_with_PID_P.DiscreteTransferFcn_InitialStat;

  /* Start for MATLABSystem: '<S1>/PWM' */
  motor_ctrl_with_PID_DW.obj_o.matlabCodegenIsDeleted = false;
  motor_ctrl_with_PID_DW.obj_o.isInitialized = 1L;
  motor_ctrl_with_PID_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL,
    0.0, 0.0);
  motor_ctrl_with_PID_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Encoder' */
  motor_ctrl_with_PID_DW.obj.Index = 0U;
  motor_ctrl_with_PID_DW.obj.matlabCodegenIsDeleted = false;
  motor_ctrl_with_PID_DW.obj.SampleTime =
    motor_ctrl_with_PID_P.Encoder_SampleTime;
  motor_ctrl_with_PID_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &motor_ctrl_with_PID_DW.obj.Index);
  motor_ctrl_with_PID_DW.obj.isSetupComplete = true;
  motor_ctrl_with_PID_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S2>/Encoder' */
  MW_EncoderReset(motor_ctrl_with_PID_DW.obj.Index);
}

/* Model terminate function */
void motor_ctrl_with_PID_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/PWM' */
  if (!motor_ctrl_with_PID_DW.obj_o.matlabCodegenIsDeleted) {
    motor_ctrl_with_PID_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((motor_ctrl_with_PID_DW.obj_o.isInitialized == 1L) &&
        motor_ctrl_with_PID_DW.obj_o.isSetupComplete) {
      motor_ctrl_with_PID_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_SetDutyCycle
        (motor_ctrl_with_PID_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      motor_ctrl_with_PID_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_Close(motor_ctrl_with_PID_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
  /* Terminate for MATLABSystem: '<S2>/Encoder' */
  if (!motor_ctrl_with_PID_DW.obj.matlabCodegenIsDeleted) {
    motor_ctrl_with_PID_DW.obj.matlabCodegenIsDeleted = true;
    if ((motor_ctrl_with_PID_DW.obj.isInitialized == 1L) &&
        motor_ctrl_with_PID_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
