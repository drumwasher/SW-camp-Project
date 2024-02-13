/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pr2_US_hap.c
 *
 * Code generated for Simulink model 'pr2_US_hap'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Feb 13 17:45:30 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pr2_US_hap.h"
#include "rtwtypes.h"
#include "pr2_US_hap_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "multiword_types.h"

/* Named constants for Chart: '<S3>/Chart' */
#define pr2_US_IN_drive_on_adas_on_LRUS (5UL)
#define pr2_US__IN_drive_on_adas_on_FUS (4UL)
#define pr2_US__IN_drive_on_adas_on_LUS (6UL)
#define pr2_US__IN_drive_on_adas_on_RUS (7UL)
#define pr2_US_hap_IN_drive_off        (1UL)
#define pr2_US_hap_IN_drive_on_adas_off (2UL)
#define pr2_US_hap_IN_drive_on_adas_on (3UL)

/* Named constants for Chart: '<S3>/Chart1' */
#define pr2_US_hap_IN_adas_off         (1UL)
#define pr2_US_hap_IN_adas_on          (2UL)
#define pr2_US_hap_IN_adas_on_BUS      (3UL)

/* Block signals (default storage) */
B_pr2_US_hap_T pr2_US_hap_B;

/* Continuous states */
X_pr2_US_hap_T pr2_US_hap_X;

/* Disabled State Vector */
XDis_pr2_US_hap_T pr2_US_hap_XDis;

/* Block states (default storage) */
DW_pr2_US_hap_T pr2_US_hap_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_pr2_US_hap_T pr2_US_hap_Y;

/* Real-time model */
static RT_MODEL_pr2_US_hap_T pr2_US_hap_M_;
RT_MODEL_pr2_US_hap_T *const pr2_US_hap_M = &pr2_US_hap_M_;
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

real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  uint32_T cb;
  uint32_T u1i;
  int16_T exp_0;
  int16_T i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648UL) != 0UL) {
    cb = 1UL;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
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

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt(SW1)' */
void MW_ISR_2(void)
{
  /* Call the system: <Root>/SW1 PUSH */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(pr2_US_hap_DW.SW1PUSH_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt(SW1)' */

    /* Output and update for function-call system: '<Root>/SW1 PUSH' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (pr2_US_hap_M->Timing.rtmDbBufWriteBuf2) {
     case 0:
      pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 1;
      break;

     case 1:
      pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 0;
      break;

     default:
      pr2_US_hap_M->Timing.rtmDbBufReadBuf2 =
        pr2_US_hap_M->Timing.rtmDbBufLastBufWr2;
      break;
    }

    pr2_US_hap_M->Timing.clockTick2 = pr2_US_hap_M->
      Timing.rtmDbBufClockTick2[pr2_US_hap_M->Timing.rtmDbBufReadBuf2];
    pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 0xFF;

    /* Sum: '<S1>/Add' incorporates:
     *  Constant: '<S1>/Constant'
     *  Delay: '<S1>/Delay'
     */
    pr2_US_hap_B.Add_h = pr2_US_hap_P.Constant_Value -
      pr2_US_hap_DW.Delay_DSTATE_a;

    /* Update for Delay: '<S1>/Delay' */
    pr2_US_hap_DW.Delay_DSTATE_a = pr2_US_hap_B.Add_h;
    pr2_US_hap_DW.SW1PUSH_SubsysRanBC = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt(SW1)' */

    /* RateTransition generated from: '<S3>/Chart' */
    switch (pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf = (int8_T)
        (pr2_US_hap_DW.TmpRTBAtChartInport1_last_buf_w == 0);
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf != 0) {
      pr2_US_hap_DW.TmpRTBAtChartInport1_Buffer1 = pr2_US_hap_B.Add_h;
    } else {
      pr2_US_hap_DW.TmpRTBAtChartInport1_Buffer0 = pr2_US_hap_B.Add_h;
    }

    pr2_US_hap_DW.TmpRTBAtChartInport1_last_buf_w =
      pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf;
    pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf = -1;

    /* End of RateTransition generated from: '<S3>/Chart' */

    /* RateTransition generated from: '<S3>/Display' */
    switch (pr2_US_hap_DW.TmpRTBAtDisplayInport1_read_buf) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtDisplayInport1_write_bu = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtDisplayInport1_write_bu = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtDisplayInport1_write_bu = (int8_T)
        (pr2_US_hap_DW.TmpRTBAtDisplayInport1_last_buf == 0);
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtDisplayInport1_write_bu != 0) {
      pr2_US_hap_DW.TmpRTBAtDisplayInport1_Buffer1 = pr2_US_hap_B.Add_h;
    } else {
      pr2_US_hap_DW.TmpRTBAtDisplayInport1_Buffer0 = pr2_US_hap_B.Add_h;
    }

    pr2_US_hap_DW.TmpRTBAtDisplayInport1_last_buf =
      pr2_US_hap_DW.TmpRTBAtDisplayInport1_write_bu;
    pr2_US_hap_DW.TmpRTBAtDisplayInport1_write_bu = -1;

    /* End of RateTransition generated from: '<S3>/Display' */

    /* RateTransition generated from: '<Root>/Display2' */
    switch (pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b = (int8_T)
        (pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_last_bu == 0);
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b != 0) {
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_Buffer1 = pr2_US_hap_B.Add_h;
    } else {
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_Buffer0 = pr2_US_hap_B.Add_h;
    }

    pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_last_bu =
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b;
    pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b = -1;

    /* End of RateTransition generated from: '<Root>/Display2' */
  }

  extmodeEvent(2,((pr2_US_hap_M->Timing.clockTick2) * 0.01));
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  pr2_US_hap_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  pr2_US_hap_step();
  pr2_US_hap_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  pr2_US_hap_step();
  pr2_US_hap_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* System initialize for function-call system: '<Root>/SW1 PUSH1' */
void pr2_US_hap_SW1PUSH1_Init(void)
{
  /* SystemInitialize for Sum: '<S2>/Add' incorporates:
   *  Outport: '<S2>/sw1'
   */
  pr2_US_hap_B.Add = pr2_US_hap_P.sw1_Y0_e;
}

/* Model step function */
void pr2_US_hap_step(void)
{
  /* local block i/o variables */
  int32_T rtb_TSamp;
  int32_T rtb_TSamp_f;
  if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&pr2_US_hap_M->solverInfo,
                          ((pr2_US_hap_M->Timing.clockTick0+1)*
      pr2_US_hap_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(pr2_US_hap_M)) {
    pr2_US_hap_M->Timing.t[0] = rtsiGetT(&pr2_US_hap_M->solverInfo);
  }

  {
    int64m_T tmp_3;
    real_T rtb_Add1;
    real_T rtb_Add1_m;
    real_T tmp_0;
    real_T *lastU;
    int32_T tmp;
    uint32_T tmp_1;
    uint32_T tmp_2;
    uint16_T b_varargout_1;
    static const int64m_T tmp_4 = { { 0UL, 0UL }/* chunks */
    };

    static const int64m_T tmp_5 = { { 25UL, 0UL }/* chunks */
    };

    /* Integrator: '<S10>/Integrator2' */
    pr2_US_hap_B.Derivative2 = pr2_US_hap_X.Integrator2_CSTATE;
    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* RateTransition generated from: '<S3>/Chart' */
      switch (pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf) {
       case 0:
        pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf = 1;
        break;

       case 1:
        pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf = 0;
        break;

       default:
        pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf =
          pr2_US_hap_DW.TmpRTBAtChartInport1_last_buf_w;
        break;
      }

      if (pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf != 0) {
        /* RateTransition generated from: '<S3>/Chart' */
        pr2_US_hap_B.TmpRTBAtChartInport1 =
          pr2_US_hap_DW.TmpRTBAtChartInport1_Buffer1;
      } else {
        /* RateTransition generated from: '<S3>/Chart' */
        pr2_US_hap_B.TmpRTBAtChartInport1 =
          pr2_US_hap_DW.TmpRTBAtChartInport1_Buffer0;
      }

      pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf = -1;

      /* End of RateTransition generated from: '<S3>/Chart' */

      /* Constant: '<Root>/Constant3' */
      pr2_US_hap_B.Constant3 = pr2_US_hap_P.f;

      /* Constant: '<Root>/Constant1' */
      pr2_US_hap_B.Constant1 = pr2_US_hap_P.r;
    }

    /* MATLABSystem: '<Root>/가변저항' */
    if (pr2_US_hap_DW.obj_n.SampleTime != pr2_US_hap_P._SampleTime) {
      pr2_US_hap_DW.obj_n.SampleTime = pr2_US_hap_P._SampleTime;
    }

    pr2_US_hap_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
      MW_AnalogIn_GetHandle(62UL);
    MW_AnalogInSingle_ReadResult
      (pr2_US_hap_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
       MW_ANALOGIN_UINT16);

    /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
     *  Gain: '<S3>/Gain'
     *  MATLABSystem: '<Root>/가변저항'
     * */
    pr2_US_hap_B.DataTypeConversion = (real_T)((uint32_T)pr2_US_hap_P.Gain_Gain *
      b_varargout_1) * 7.62939453125E-6;
    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* Chart: '<S3>/Chart' */
      if (pr2_US_hap_DW.is_active_c2_pr2_US_hap == 0U) {
        pr2_US_hap_DW.is_active_c2_pr2_US_hap = 1U;
        pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US_hap_IN_drive_off;
        pr2_US_hap_B.out1 = 0.0;
        pr2_US_hap_B.out2 = 0.0;
        pr2_US_hap_DW.steering = 0.02;
        pr2_US_hap_DW.default_i = 360.0;
      } else {
        switch (pr2_US_hap_DW.is_c2_pr2_US_hap) {
         case pr2_US_hap_IN_drive_off:
          if (pr2_US_hap_B.TmpRTBAtChartInport1 == 1.0) {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_off;
            pr2_US_hap_B.out1 = ((pr2_US_hap_B.DataTypeConversion - 128.0) / 6.4
                                 / 100.0 + 1.0) * pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = ((128.0 - pr2_US_hap_B.DataTypeConversion) / 6.4
                                 / 100.0 + 1.0) * pr2_US_hap_DW.default_i;
          } else {
            pr2_US_hap_B.out1 = 0.0;
            pr2_US_hap_B.out2 = 0.0;
            pr2_US_hap_DW.steering = 0.02;
            pr2_US_hap_DW.default_i = 360.0;
          }
          break;

         case pr2_US_hap_IN_drive_on_adas_off:
          if (pr2_US_hap_B.TmpRTBAtChartInport1 == 0.0) {
            pr2_US_hap_B.buzzer = 0.0;
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US_hap_IN_drive_off;
            pr2_US_hap_B.out1 = 0.0;
            pr2_US_hap_B.out2 = 0.0;
            pr2_US_hap_DW.steering = 0.02;
            pr2_US_hap_DW.default_i = 360.0;
          } else if (pr2_US_hap_B.Add == 1.0) {
            pr2_US_hap_B.buzzer = 0.0;
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_on;
            pr2_US_hap_B.out1 = pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = pr2_US_hap_DW.default_i;
          } else {
            pr2_US_hap_B.out1 = ((pr2_US_hap_B.DataTypeConversion - 128.0) / 6.4
                                 / 100.0 + 1.0) * pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = ((128.0 - pr2_US_hap_B.DataTypeConversion) / 6.4
                                 / 100.0 + 1.0) * pr2_US_hap_DW.default_i;
          }
          break;

         case pr2_US_hap_IN_drive_on_adas_on:
          if (pr2_US_hap_B.Add == 0.0) {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_off;
            pr2_US_hap_B.out1 = ((pr2_US_hap_B.DataTypeConversion - 128.0) / 6.4
                                 / 100.0 + 1.0) * pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = ((128.0 - pr2_US_hap_B.DataTypeConversion) / 6.4
                                 / 100.0 + 1.0) * pr2_US_hap_DW.default_i;
          } else if (pr2_US_hap_B.Constant3 <= 10.0) {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US__IN_drive_on_adas_on_FUS;
            pr2_US_hap_B.out1 = 0.0;
            pr2_US_hap_B.out2 = 0.0;
            pr2_US_hap_B.buzzer = 1.0;
          } else if (pr2_US_hap_B.Constant1 <= 10.0) {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US__IN_drive_on_adas_on_RUS;
            pr2_US_hap_B.out1 = (1.0 - (10.0 - pr2_US_hap_B.Constant1) *
                                 pr2_US_hap_DW.steering) *
              pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = ((10.0 - pr2_US_hap_B.Constant1) *
                                 pr2_US_hap_DW.steering + 1.0) *
              pr2_US_hap_DW.default_i;
          } else {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US__IN_drive_on_adas_on_LUS;
            pr2_US_hap_B.out1 = (10.0 * pr2_US_hap_DW.steering + 1.0) *
              pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = (1.0 - 10.0 * pr2_US_hap_DW.steering) *
              pr2_US_hap_DW.default_i;
          }
          break;

         case pr2_US__IN_drive_on_adas_on_FUS:
          if ((pr2_US_hap_B.Constant1 <= 10.0) && (pr2_US_hap_B.Constant3 > 10.0))
          {
            pr2_US_hap_B.buzzer = 0.0;
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US_IN_drive_on_adas_on_LRUS;
            pr2_US_hap_B.out1 = (1.0 - (0.0 - pr2_US_hap_B.Constant1) *
                                 pr2_US_hap_DW.steering) *
              pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = ((0.0 - pr2_US_hap_B.Constant1) *
                                 pr2_US_hap_DW.steering + 1.0) *
              pr2_US_hap_DW.default_i;
          } else if ((pr2_US_hap_B.Constant1 <= 10.0) && (pr2_US_hap_B.Constant3
                      > 10.0)) {
            pr2_US_hap_B.buzzer = 0.0;
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US__IN_drive_on_adas_on_RUS;
            pr2_US_hap_B.out1 = (1.0 - (10.0 - pr2_US_hap_B.Constant1) *
                                 pr2_US_hap_DW.steering) *
              pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = ((10.0 - pr2_US_hap_B.Constant1) *
                                 pr2_US_hap_DW.steering + 1.0) *
              pr2_US_hap_DW.default_i;
          } else if (pr2_US_hap_B.Constant3 > 10.0) {
            pr2_US_hap_B.buzzer = 0.0;
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US__IN_drive_on_adas_on_LUS;
            pr2_US_hap_B.out1 = (10.0 * pr2_US_hap_DW.steering + 1.0) *
              pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = (1.0 - 10.0 * pr2_US_hap_DW.steering) *
              pr2_US_hap_DW.default_i;
          } else if (pr2_US_hap_B.Add == 0.0) {
            pr2_US_hap_B.buzzer = 0.0;
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_off;
            pr2_US_hap_B.out1 = ((pr2_US_hap_B.DataTypeConversion - 128.0) / 6.4
                                 / 100.0 + 1.0) * pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = ((128.0 - pr2_US_hap_B.DataTypeConversion) / 6.4
                                 / 100.0 + 1.0) * pr2_US_hap_DW.default_i;
          } else {
            pr2_US_hap_B.out1 = 0.0;
            pr2_US_hap_B.out2 = 0.0;
            pr2_US_hap_B.buzzer = 1.0;
          }
          break;

         case pr2_US_IN_drive_on_adas_on_LRUS:
          if (pr2_US_hap_B.Constant3 <= 10.0) {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US__IN_drive_on_adas_on_FUS;
            pr2_US_hap_B.out1 = 0.0;
            pr2_US_hap_B.out2 = 0.0;
            pr2_US_hap_B.buzzer = 1.0;
          } else if (pr2_US_hap_B.Constant1 > 10.0) {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US__IN_drive_on_adas_on_LUS;
            pr2_US_hap_B.out1 = (10.0 * pr2_US_hap_DW.steering + 1.0) *
              pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = (1.0 - 10.0 * pr2_US_hap_DW.steering) *
              pr2_US_hap_DW.default_i;
          } else if (pr2_US_hap_B.Add == 0.0) {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_off;
            pr2_US_hap_B.out1 = ((pr2_US_hap_B.DataTypeConversion - 128.0) / 6.4
                                 / 100.0 + 1.0) * pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = ((128.0 - pr2_US_hap_B.DataTypeConversion) / 6.4
                                 / 100.0 + 1.0) * pr2_US_hap_DW.default_i;
          } else {
            pr2_US_hap_B.out1 = (1.0 - (0.0 - pr2_US_hap_B.Constant1) *
                                 pr2_US_hap_DW.steering) *
              pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = ((0.0 - pr2_US_hap_B.Constant1) *
                                 pr2_US_hap_DW.steering + 1.0) *
              pr2_US_hap_DW.default_i;
          }
          break;

         case pr2_US__IN_drive_on_adas_on_LUS:
          if (pr2_US_hap_B.Constant1 <= 10.0) {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US_IN_drive_on_adas_on_LRUS;
            pr2_US_hap_B.out1 = (1.0 - (0.0 - pr2_US_hap_B.Constant1) *
                                 pr2_US_hap_DW.steering) *
              pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = ((0.0 - pr2_US_hap_B.Constant1) *
                                 pr2_US_hap_DW.steering + 1.0) *
              pr2_US_hap_DW.default_i;
          } else if (pr2_US_hap_B.Constant3 <= 10.0) {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US__IN_drive_on_adas_on_FUS;
            pr2_US_hap_B.out1 = 0.0;
            pr2_US_hap_B.out2 = 0.0;
            pr2_US_hap_B.buzzer = 1.0;
          } else if (pr2_US_hap_B.Add == 0.0) {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_off;
            pr2_US_hap_B.out1 = ((pr2_US_hap_B.DataTypeConversion - 128.0) / 6.4
                                 / 100.0 + 1.0) * pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = ((128.0 - pr2_US_hap_B.DataTypeConversion) / 6.4
                                 / 100.0 + 1.0) * pr2_US_hap_DW.default_i;
          } else {
            pr2_US_hap_B.out1 = (10.0 * pr2_US_hap_DW.steering + 1.0) *
              pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = (1.0 - 10.0 * pr2_US_hap_DW.steering) *
              pr2_US_hap_DW.default_i;
          }
          break;

         default:
          /* case IN_drive_on_adas_on_RUS: */
          if (pr2_US_hap_B.Constant1 > 10.0) {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_on;
            pr2_US_hap_B.out1 = pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = pr2_US_hap_DW.default_i;
          } else if (pr2_US_hap_B.Constant3 <= 10.0) {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US__IN_drive_on_adas_on_FUS;
            pr2_US_hap_B.out1 = 0.0;
            pr2_US_hap_B.out2 = 0.0;
            pr2_US_hap_B.buzzer = 1.0;
          } else {
            pr2_US_hap_DW.is_c2_pr2_US_hap = pr2_US_IN_drive_on_adas_on_LRUS;
            pr2_US_hap_B.out1 = (1.0 - (0.0 - pr2_US_hap_B.Constant1) *
                                 pr2_US_hap_DW.steering) *
              pr2_US_hap_DW.default_i;
            pr2_US_hap_B.out2 = ((0.0 - pr2_US_hap_B.Constant1) *
                                 pr2_US_hap_DW.steering + 1.0) *
              pr2_US_hap_DW.default_i;
          }
          break;
        }
      }

      /* End of Chart: '<S3>/Chart' */

      /* Constant: '<Root>/Constant2' */
      pr2_US_hap_B.Constant2 = pr2_US_hap_P.b;

      /* Chart: '<S3>/Chart1' */
      if (pr2_US_hap_DW.is_active_c5_pr2_US_hap == 0U) {
        pr2_US_hap_DW.is_active_c5_pr2_US_hap = 1U;
        pr2_US_hap_DW.is_c5_pr2_US_hap = pr2_US_hap_IN_adas_off;
        pr2_US_hap_B.rout1 = pr2_US_hap_B.out1;
        pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
      } else {
        switch (pr2_US_hap_DW.is_c5_pr2_US_hap) {
         case pr2_US_hap_IN_adas_off:
          if (pr2_US_hap_B.Add == 1.0) {
            pr2_US_hap_DW.is_c5_pr2_US_hap = pr2_US_hap_IN_adas_on;
            pr2_US_hap_B.rout1 = pr2_US_hap_B.out1;
            pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
          } else {
            pr2_US_hap_B.rout1 = pr2_US_hap_B.out1;
            pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
          }
          break;

         case pr2_US_hap_IN_adas_on:
          if (pr2_US_hap_B.Add == 0.0) {
            pr2_US_hap_DW.is_c5_pr2_US_hap = pr2_US_hap_IN_adas_off;
            pr2_US_hap_B.rout1 = pr2_US_hap_B.out1;
            pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
          } else if (pr2_US_hap_B.Constant2 <= 10.0) {
            pr2_US_hap_DW.is_c5_pr2_US_hap = pr2_US_hap_IN_adas_on_BUS;
            pr2_US_hap_B.rout1 = pr2_US_hap_B.out1 * 1.2;
            pr2_US_hap_B.rout2 = pr2_US_hap_B.out2 * 1.2;
          } else {
            pr2_US_hap_B.rout1 = pr2_US_hap_B.out1;
            pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
          }
          break;

         default:
          /* case IN_adas_on_BUS: */
          if (pr2_US_hap_B.Constant2 > 10.0) {
            pr2_US_hap_DW.is_c5_pr2_US_hap = pr2_US_hap_IN_adas_on;
            pr2_US_hap_B.rout1 = pr2_US_hap_B.out1;
            pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
          } else if (pr2_US_hap_B.Add == 0.0) {
            pr2_US_hap_DW.is_c5_pr2_US_hap = pr2_US_hap_IN_adas_off;
            pr2_US_hap_B.rout1 = pr2_US_hap_B.out1;
            pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
          } else {
            pr2_US_hap_B.rout1 = pr2_US_hap_B.out1 * 1.2;
            pr2_US_hap_B.rout2 = pr2_US_hap_B.out2 * 1.2;
          }
          break;
        }
      }

      /* End of Chart: '<S3>/Chart1' */

      /* DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
      pr2_US_hap_B.DiscreteTransferFcn = tmp_4;

      /* DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
      tmp_1 = (uint32_T)pr2_US_hap_P.num_Gd[1L];
      tmp_2 = (uint32_T)pr2_US_hap_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp_1, 1, &tmp_2, 1,
                    &pr2_US_hap_B.DiscreteTransferFcn.chunks[0U], 2);

      /* Sum: '<S4>/Add1' incorporates:
       *  DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn'
       */
      rtb_Add1 = pr2_US_hap_B.rout1 - sMultiWord2Double
        (&pr2_US_hap_B.DiscreteTransferFcn.chunks[0U], 2, 0) *
        1.1641532182693481E-10;

      /* Gain: '<S10>/Gain2' */
      pr2_US_hap_B.Gain2_gz = pr2_US_hap_P.KP * rtb_Add1;

      /* Gain: '<S10>/Gain3' */
      pr2_US_hap_B.Gain3 = pr2_US_hap_P.KD * rtb_Add1;
    }

    /* Derivative: '<S10>/Derivative2' incorporates:
     *  Derivative: '<S14>/Derivative2'
     */
    tmp_0 = pr2_US_hap_M->Timing.t[0];
    if ((pr2_US_hap_DW.TimeStampA >= tmp_0) && (pr2_US_hap_DW.TimeStampB >=
         tmp_0)) {
      pr2_US_hap_B.Gain1_m = 0.0;
    } else {
      pr2_US_hap_B.Gain1_m = pr2_US_hap_DW.TimeStampA;
      lastU = &pr2_US_hap_DW.LastUAtTimeA;
      if (pr2_US_hap_DW.TimeStampA < pr2_US_hap_DW.TimeStampB) {
        if (pr2_US_hap_DW.TimeStampB < tmp_0) {
          pr2_US_hap_B.Gain1_m = pr2_US_hap_DW.TimeStampB;
          lastU = &pr2_US_hap_DW.LastUAtTimeB;
        }
      } else if (pr2_US_hap_DW.TimeStampA >= tmp_0) {
        pr2_US_hap_B.Gain1_m = pr2_US_hap_DW.TimeStampB;
        lastU = &pr2_US_hap_DW.LastUAtTimeB;
      }

      pr2_US_hap_B.Gain1_m = (pr2_US_hap_B.Gain3 - *lastU) / (tmp_0 -
        pr2_US_hap_B.Gain1_m);
    }

    /* End of Derivative: '<S10>/Derivative2' */

    /* Sum: '<S10>/Subtract2' */
    pr2_US_hap_B.Subtract2 = (pr2_US_hap_B.Derivative2 + pr2_US_hap_B.Gain2_gz)
      + pr2_US_hap_B.Gain1_m;

    /* Saturate: '<S4>/Saturation2' */
    if (pr2_US_hap_B.Subtract2 > pr2_US_hap_P.Saturation2_UpperSat) {
      /* Saturate: '<S4>/Saturation2' */
      pr2_US_hap_B.Saturation2 = pr2_US_hap_P.Saturation2_UpperSat;
    } else if (pr2_US_hap_B.Subtract2 < pr2_US_hap_P.Saturation2_LowerSat) {
      /* Saturate: '<S4>/Saturation2' */
      pr2_US_hap_B.Saturation2 = pr2_US_hap_P.Saturation2_LowerSat;
    } else {
      /* Saturate: '<S4>/Saturation2' */
      pr2_US_hap_B.Saturation2 = pr2_US_hap_B.Subtract2;
    }

    /* End of Saturate: '<S4>/Saturation2' */

    /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
     *  Gain: '<S9>/Gain1'
     */
    pr2_US_hap_B.Derivative2 = floor(255.0 / pr2_US_hap_P.Vlim *
      pr2_US_hap_B.Saturation2);
    if (rtIsNaN(pr2_US_hap_B.Derivative2) || rtIsInf(pr2_US_hap_B.Derivative2))
    {
      pr2_US_hap_B.Derivative2 = 0.0;
    } else {
      pr2_US_hap_B.Derivative2 = fmod(pr2_US_hap_B.Derivative2, 256.0);
    }

    /* DataTypeConversion: '<S9>/Data Type Conversion' */
    pr2_US_hap_B.DataTypeConversion_h = (uint8_T)(pr2_US_hap_B.Derivative2 < 0.0
      ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-pr2_US_hap_B.Derivative2 : (int16_T)
      (uint8_T)pr2_US_hap_B.Derivative2);

    /* DataTypeConversion: '<S9>/Data Type Conversion1' */
    pr2_US_hap_B.DataTypeConversion1 = pr2_US_hap_B.DataTypeConversion_h;
    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* SignalConversion generated from: '<S4>/Mux1' */
      pr2_US_hap_B.TmpSignalConversionAtTAQSigLogg[0] = 0.0;
      pr2_US_hap_B.TmpSignalConversionAtTAQSigLogg[1] =
        pr2_US_hap_B.DataTypeConversion1;

      /* DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn' */
      pr2_US_hap_B.DiscreteTransferFcn_c = tmp_4;

      /* DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn' */
      tmp_1 = (uint32_T)pr2_US_hap_P.num_Gd[1L];
      tmp_2 = (uint32_T)pr2_US_hap_DW.DiscreteTransferFcn_states_m;
      sMultiWordMul(&tmp_1, 1, &tmp_2, 1,
                    &pr2_US_hap_B.DiscreteTransferFcn_c.chunks[0U], 2);

      /* Sum: '<S5>/Add1' incorporates:
       *  DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn'
       */
      rtb_Add1_m = pr2_US_hap_B.rout2 - sMultiWord2Double
        (&pr2_US_hap_B.DiscreteTransferFcn_c.chunks[0U], 2, 0) *
        1.1641532182693481E-10;

      /* Gain: '<S14>/Gain2' */
      pr2_US_hap_B.Gain2_f = pr2_US_hap_P.KP * rtb_Add1_m;

      /* Gain: '<S14>/Gain3' */
      pr2_US_hap_B.Gain3_k = pr2_US_hap_P.KD * rtb_Add1_m;
    }

    /* Derivative: '<S14>/Derivative2' */
    if ((pr2_US_hap_DW.TimeStampA_g >= tmp_0) && (pr2_US_hap_DW.TimeStampB_c >=
         tmp_0)) {
      pr2_US_hap_B.Derivative2 = 0.0;
    } else {
      pr2_US_hap_B.Gain1_m = pr2_US_hap_DW.TimeStampA_g;
      lastU = &pr2_US_hap_DW.LastUAtTimeA_p;
      if (pr2_US_hap_DW.TimeStampA_g < pr2_US_hap_DW.TimeStampB_c) {
        if (pr2_US_hap_DW.TimeStampB_c < tmp_0) {
          pr2_US_hap_B.Gain1_m = pr2_US_hap_DW.TimeStampB_c;
          lastU = &pr2_US_hap_DW.LastUAtTimeB_n;
        }
      } else if (pr2_US_hap_DW.TimeStampA_g >= tmp_0) {
        pr2_US_hap_B.Gain1_m = pr2_US_hap_DW.TimeStampB_c;
        lastU = &pr2_US_hap_DW.LastUAtTimeB_n;
      }

      pr2_US_hap_B.Derivative2 = (pr2_US_hap_B.Gain3_k - *lastU) / (tmp_0 -
        pr2_US_hap_B.Gain1_m);
    }

    /* Sum: '<S14>/Subtract2' incorporates:
     *  Integrator: '<S14>/Integrator2'
     */
    pr2_US_hap_B.Subtract2_p = (pr2_US_hap_X.Integrator2_CSTATE_f +
      pr2_US_hap_B.Gain2_f) + pr2_US_hap_B.Derivative2;

    /* Saturate: '<S5>/Saturation2' */
    if (pr2_US_hap_B.Subtract2_p > pr2_US_hap_P.Saturation2_UpperSat_d) {
      /* Saturate: '<S5>/Saturation2' */
      pr2_US_hap_B.Saturation2_j = pr2_US_hap_P.Saturation2_UpperSat_d;
    } else if (pr2_US_hap_B.Subtract2_p < pr2_US_hap_P.Saturation2_LowerSat_i) {
      /* Saturate: '<S5>/Saturation2' */
      pr2_US_hap_B.Saturation2_j = pr2_US_hap_P.Saturation2_LowerSat_i;
    } else {
      /* Saturate: '<S5>/Saturation2' */
      pr2_US_hap_B.Saturation2_j = pr2_US_hap_B.Subtract2_p;
    }

    /* End of Saturate: '<S5>/Saturation2' */

    /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
     *  Gain: '<S13>/Gain1'
     */
    tmp_0 = floor(255.0 / pr2_US_hap_P.Vlim * pr2_US_hap_B.Saturation2_j);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 256.0);
    }

    /* DataTypeConversion: '<S13>/Data Type Conversion' */
    pr2_US_hap_B.DataTypeConversion_g = (uint8_T)(tmp_0 < 0.0 ? (int16_T)
      (uint8_T)-(int8_T)(uint8_T)-tmp_0 : (int16_T)(uint8_T)tmp_0);

    /* DataTypeConversion: '<S13>/Data Type Conversion1' */
    pr2_US_hap_B.DataTypeConversion1_e = pr2_US_hap_B.DataTypeConversion_g;
    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* SignalConversion generated from: '<S5>/Mux1' */
      pr2_US_hap_B.TmpSignalConversionAtTAQSigLo_e[0] = 0.0;
      pr2_US_hap_B.TmpSignalConversionAtTAQSigLo_e[1] =
        pr2_US_hap_B.DataTypeConversion1_e;
    }

    /* MATLABSystem: '<S13>/PWM' */
    pr2_US_hap_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
    MW_PWM_SetDutyCycle(pr2_US_hap_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                        pr2_US_hap_B.DataTypeConversion_g);
    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* Gain: '<S14>/Gain1' */
      pr2_US_hap_B.Gain1_g = pr2_US_hap_P.KI * rtb_Add1_m;
    }

    /* MATLABSystem: '<S9>/PWM' */
    pr2_US_hap_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
    MW_PWM_SetDutyCycle(pr2_US_hap_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                        pr2_US_hap_B.DataTypeConversion_h);
    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* Gain: '<S10>/Gain1' */
      pr2_US_hap_B.Gain1_p = pr2_US_hap_P.KI * rtb_Add1;

      /* Outport: '<Root>/buzzer' */
      pr2_US_hap_Y.buzzer = pr2_US_hap_B.buzzer;
    }

    /* MATLABSystem: '<S3>/PWM' */
    pr2_US_hap_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* Start for MATLABSystem: '<S3>/PWM' */
    if (pr2_US_hap_B.DataTypeConversion <= 255.0) {
      rtb_Add1 = pr2_US_hap_B.DataTypeConversion;
    } else {
      rtb_Add1 = 255.0;
    }

    if (!(rtb_Add1 >= 0.0)) {
      rtb_Add1 = 0.0;
    }

    /* MATLABSystem: '<S3>/PWM' */
    MW_PWM_SetDutyCycle(pr2_US_hap_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, rtb_Add1);

    /* MATLABSystem: '<S3>/PWM1' */
    pr2_US_hap_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Start for MATLABSystem: '<S3>/PWM1' */
    if (pr2_US_hap_B.DataTypeConversion <= 255.0) {
      rtb_Add1 = pr2_US_hap_B.DataTypeConversion;
    } else {
      rtb_Add1 = 255.0;
    }

    if (!(rtb_Add1 >= 0.0)) {
      rtb_Add1 = 0.0;
    }

    /* MATLABSystem: '<S3>/PWM1' */
    MW_PWM_SetDutyCycle(pr2_US_hap_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, rtb_Add1);

    /* MATLABSystem: '<S3>/PWM2' */
    pr2_US_hap_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);

    /* Start for MATLABSystem: '<S3>/PWM2' */
    if (pr2_US_hap_B.DataTypeConversion <= 255.0) {
      rtb_Add1 = pr2_US_hap_B.DataTypeConversion;
    } else {
      rtb_Add1 = 255.0;
    }

    if (!(rtb_Add1 >= 0.0)) {
      rtb_Add1 = 0.0;
    }

    /* MATLABSystem: '<S3>/PWM2' */
    MW_PWM_SetDutyCycle(pr2_US_hap_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, rtb_Add1);
    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* RateTransition generated from: '<Root>/Display2' */
      switch (pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b) {
       case 0:
        pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu = 1;
        break;

       case 1:
        pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu = 0;
        break;

       default:
        pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu =
          pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_last_bu;
        break;
      }

      if (pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu != 0) {
        /* RateTransition generated from: '<Root>/Display2' */
        pr2_US_hap_B.TmpRTBAtDisplay2Inport1 =
          pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_Buffer1;
      } else {
        /* RateTransition generated from: '<Root>/Display2' */
        pr2_US_hap_B.TmpRTBAtDisplay2Inport1 =
          pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_Buffer0;
      }

      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu = -1;

      /* End of RateTransition generated from: '<Root>/Display2' */

      /* RateTransition generated from: '<S3>/Display' */
      switch (pr2_US_hap_DW.TmpRTBAtDisplayInport1_write_bu) {
       case 0:
        pr2_US_hap_DW.TmpRTBAtDisplayInport1_read_buf = 1;
        break;

       case 1:
        pr2_US_hap_DW.TmpRTBAtDisplayInport1_read_buf = 0;
        break;

       default:
        pr2_US_hap_DW.TmpRTBAtDisplayInport1_read_buf =
          pr2_US_hap_DW.TmpRTBAtDisplayInport1_last_buf;
        break;
      }

      if (pr2_US_hap_DW.TmpRTBAtDisplayInport1_read_buf != 0) {
        /* RateTransition generated from: '<S3>/Display' */
        pr2_US_hap_B.TmpRTBAtDisplayInport1 =
          pr2_US_hap_DW.TmpRTBAtDisplayInport1_Buffer1;
      } else {
        /* RateTransition generated from: '<S3>/Display' */
        pr2_US_hap_B.TmpRTBAtDisplayInport1 =
          pr2_US_hap_DW.TmpRTBAtDisplayInport1_Buffer0;
      }

      pr2_US_hap_DW.TmpRTBAtDisplayInport1_read_buf = -1;

      /* End of RateTransition generated from: '<S3>/Display' */
    }

    /* MATLABSystem: '<S8>/Encoder' */
    if (pr2_US_hap_DW.obj_p.SampleTime != pr2_US_hap_P.Encoder_SampleTime) {
      pr2_US_hap_DW.obj_p.SampleTime = pr2_US_hap_P.Encoder_SampleTime;
    }

    if (pr2_US_hap_DW.obj_p.TunablePropsChanged) {
      pr2_US_hap_DW.obj_p.TunablePropsChanged = false;
    }

    MW_EncoderRead(pr2_US_hap_DW.obj_p.Index, &tmp);
    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* SampleTimeMath: '<S11>/TSamp' incorporates:
       *  MATLABSystem: '<S8>/Encoder'
       *
       * About '<S11>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       */
      rtb_TSamp = tmp;

      /* Gain: '<S8>/Gain1' incorporates:
       *  SampleTimeMath: '<S11>/TSamp'
       *  Sum: '<S11>/Diff'
       *  UnitDelay: '<S11>/UD'
       *
       * About '<S11>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S11>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S11>/UD':
       *
       *  Store in Global RAM
       */
      tmp_1 = (uint32_T)pr2_US_hap_P.encoder_scale;
      tmp_2 = (uint32_T)(rtb_TSamp - pr2_US_hap_DW.UD_DSTATE);
      sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &pr2_US_hap_B.Gain1.chunks[0U], 2);

      /* Gain: '<S8>/Gain2' incorporates:
       *  Gain: '<S8>/Gain1'
       */
      sMultiWordMul(&pr2_US_hap_P.Gain2_Gain.chunks[0U], 2,
                    &pr2_US_hap_B.Gain1.chunks[0U], 2,
                    &pr2_US_hap_B.Gain2.chunks[0U], 4);

      /* DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
       *  Gain: '<S8>/Gain1'
       */
      tmp_3 = pr2_US_hap_B.Gain1;
      sMultiWordMul(&pr2_US_hap_B.Gain1.chunks[0U], 2, &tmp_5.chunks[0U], 2,
                    &pr2_US_hap_B.r2.chunks[0U], 4);
      sMultiWordShr(&pr2_US_hap_B.r2.chunks[0U], 4, 31U,
                    &pr2_US_hap_B.r1.chunks[0U], 4);

      /* DataTypeConversion: '<S8>/Data Type Conversion1' */
      pr2_US_hap_B.DataTypeConversion1_d = MultiWord2sLong
        (&pr2_US_hap_B.r1.chunks[0U]);
    }

    /* MATLABSystem: '<S12>/Encoder' */
    if (pr2_US_hap_DW.obj.SampleTime != pr2_US_hap_P.Encoder_SampleTime_e) {
      pr2_US_hap_DW.obj.SampleTime = pr2_US_hap_P.Encoder_SampleTime_e;
    }

    if (pr2_US_hap_DW.obj.TunablePropsChanged) {
      pr2_US_hap_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(pr2_US_hap_DW.obj.Index, &tmp);
    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* SampleTimeMath: '<S15>/TSamp' incorporates:
       *  MATLABSystem: '<S12>/Encoder'
       *
       * About '<S15>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       */
      rtb_TSamp_f = tmp;

      /* Gain: '<S12>/Gain1' incorporates:
       *  SampleTimeMath: '<S15>/TSamp'
       *  Sum: '<S15>/Diff'
       *  UnitDelay: '<S15>/UD'
       *
       * About '<S15>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S15>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S15>/UD':
       *
       *  Store in Global RAM
       */
      tmp_1 = (uint32_T)pr2_US_hap_P.encoder_scale;
      tmp_2 = (uint32_T)(rtb_TSamp_f - pr2_US_hap_DW.UD_DSTATE_m);
      sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_3.chunks[0U], 2);

      /* Gain: '<S12>/Gain1' incorporates:
       *  Gain: '<S8>/Gain2'
       */
      pr2_US_hap_B.Gain1_a = tmp_3;

      /* Gain: '<S12>/Gain2' incorporates:
       *  Gain: '<S12>/Gain1'
       */
      sMultiWordMul(&pr2_US_hap_P.Gain2_Gain_d.chunks[0U], 2,
                    &pr2_US_hap_B.Gain1_a.chunks[0U], 2,
                    &pr2_US_hap_B.r2.chunks[0U], 4);

      /* Gain: '<S12>/Gain2' incorporates:
       *  DataTypeConversion: '<S8>/Data Type Conversion1'
       */
      pr2_US_hap_B.Gain2_g = pr2_US_hap_B.r2;

      /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
       *  Gain: '<S12>/Gain1'
       */
      sMultiWordMul(&pr2_US_hap_B.Gain1_a.chunks[0U], 2, &tmp_5.chunks[0U], 2,
                    &pr2_US_hap_B.r4.chunks[0U], 4);
      sMultiWordShr(&pr2_US_hap_B.r4.chunks[0U], 4, 31U,
                    &pr2_US_hap_B.r3.chunks[0U], 4);

      /* DataTypeConversion: '<S12>/Data Type Conversion1' */
      pr2_US_hap_B.DataTypeConversion1_a = MultiWord2sLong
        (&pr2_US_hap_B.r3.chunks[0U]);

      /* Constant: '<Root>/Constant' */
      pr2_US_hap_B.Constant = pr2_US_hap_P.l;
    }
  }

  if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
    int64m_T denAccum;
    int64m_T denAccum_0;
    int64m_T tmp_1;
    int64m_T tmp_2;
    int64m_T tmp_3;
    real_T *lastU;
    uint32_T tmp;
    uint32_T tmp_0;
    static const int64m_T tmp_4 = { { MAX_uint32_T, 2147483647UL }/* chunks */
    };

    static const int64m_T tmp_5 = { { 0UL, 0UL }/* chunks */
    };

    static const int64m_T tmp_6 = { { 0UL, 2147483648UL }/* chunks */
    };

    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* Update for DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
      sLong2MultiWord(pr2_US_hap_B.DataTypeConversion1_d,
                      &pr2_US_hap_B.r12.chunks[0U], 2);
      sMultiWordShl(&pr2_US_hap_B.r12.chunks[0U], 2, 30U,
                    &pr2_US_hap_B.denAccum.chunks[0U], 2);
      tmp = (uint32_T)pr2_US_hap_P.den_Gd[1L];
      tmp_0 = (uint32_T)pr2_US_hap_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp, 1, &tmp_0, 1, &pr2_US_hap_B.r12.chunks[0U], 2);
      MultiWordSub(&pr2_US_hap_B.denAccum.chunks[0U], &pr2_US_hap_B.r12.chunks
                   [0U], &denAccum.chunks[0U], 2);
      pr2_US_hap_B.denAccum = denAccum;
      if (pr2_US_hap_P.den_Gd[0] == 0L) {
        if (sMultiWordGe(&pr2_US_hap_B.denAccum.chunks[0U], &tmp_5.chunks[0U], 2))
        {
          pr2_US_hap_B.r11 = tmp_4;
        } else {
          pr2_US_hap_B.r11 = tmp_6;
        }
      } else {
        sMultiWord2MultiWord(&pr2_US_hap_B.denAccum.chunks[0U], 2,
                             &pr2_US_hap_B.r6.chunks[0U], 3);
        sMultiWordShl(&pr2_US_hap_B.r6.chunks[0U], 3, 30U,
                      &pr2_US_hap_B.r5.chunks[0U], 3);
        sLong2MultiWord(pr2_US_hap_P.den_Gd[0], &pr2_US_hap_B.r6.chunks[0U], 3);
        sMultiWordDivFloor(&pr2_US_hap_B.r5.chunks[0U], 3,
                           &pr2_US_hap_B.r6.chunks[0U], 3,
                           &pr2_US_hap_B.r.chunks[0U], 4,
                           &pr2_US_hap_B.r7.chunks[0U], 3,
                           &pr2_US_hap_B.r8.chunks[0U], 3,
                           &pr2_US_hap_B.r9.chunks[0U], 3);
        sMultiWord2MultiWord(&pr2_US_hap_B.r.chunks[0U], 4,
                             &pr2_US_hap_B.r11.chunks[0U], 2);
      }

      sMultiWordShr(&pr2_US_hap_B.r11.chunks[0U], 2, 30U, &tmp_1.chunks[0U], 2);
      pr2_US_hap_DW.DiscreteTransferFcn_states = MultiWord2sLong(&tmp_1.chunks
        [0U]);

      /* End of Update for DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
    }

    /* Update for Derivative: '<S10>/Derivative2' */
    if (pr2_US_hap_DW.TimeStampA == (rtInf)) {
      pr2_US_hap_DW.TimeStampA = pr2_US_hap_M->Timing.t[0];
      lastU = &pr2_US_hap_DW.LastUAtTimeA;
    } else if (pr2_US_hap_DW.TimeStampB == (rtInf)) {
      pr2_US_hap_DW.TimeStampB = pr2_US_hap_M->Timing.t[0];
      lastU = &pr2_US_hap_DW.LastUAtTimeB;
    } else if (pr2_US_hap_DW.TimeStampA < pr2_US_hap_DW.TimeStampB) {
      pr2_US_hap_DW.TimeStampA = pr2_US_hap_M->Timing.t[0];
      lastU = &pr2_US_hap_DW.LastUAtTimeA;
    } else {
      pr2_US_hap_DW.TimeStampB = pr2_US_hap_M->Timing.t[0];
      lastU = &pr2_US_hap_DW.LastUAtTimeB;
    }

    *lastU = pr2_US_hap_B.Gain3;

    /* End of Update for Derivative: '<S10>/Derivative2' */
    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* Update for DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn' */
      sLong2MultiWord(pr2_US_hap_B.DataTypeConversion1_a, &tmp_2.chunks[0U], 2);
      sMultiWordShl(&tmp_2.chunks[0U], 2, 30U, &pr2_US_hap_B.denAccum.chunks[0U],
                    2);
      tmp = (uint32_T)pr2_US_hap_P.den_Gd[1L];
      tmp_0 = (uint32_T)pr2_US_hap_DW.DiscreteTransferFcn_states_m;
      sMultiWordMul(&tmp, 1, &tmp_0, 1, &tmp_2.chunks[0U], 2);
      MultiWordSub(&pr2_US_hap_B.denAccum.chunks[0U], &tmp_2.chunks[0U],
                   &denAccum_0.chunks[0U], 2);
      if (pr2_US_hap_P.den_Gd[0] == 0L) {
        if (sMultiWordGe(&denAccum_0.chunks[0U], &tmp_5.chunks[0U], 2)) {
          pr2_US_hap_B.r10 = tmp_4;
        } else {
          pr2_US_hap_B.r10 = tmp_6;
        }
      } else {
        sMultiWord2MultiWord(&denAccum_0.chunks[0U], 2, &pr2_US_hap_B.r6.chunks
                             [0U], 3);
        sMultiWordShl(&pr2_US_hap_B.r6.chunks[0U], 3, 30U,
                      &pr2_US_hap_B.r5.chunks[0U], 3);
        sLong2MultiWord(pr2_US_hap_P.den_Gd[0], &pr2_US_hap_B.r6.chunks[0U], 3);
        sMultiWordDivFloor(&pr2_US_hap_B.r5.chunks[0U], 3,
                           &pr2_US_hap_B.r6.chunks[0U], 3,
                           &pr2_US_hap_B.r.chunks[0U], 4,
                           &pr2_US_hap_B.r7.chunks[0U], 3,
                           &pr2_US_hap_B.r8.chunks[0U], 3,
                           &pr2_US_hap_B.r9.chunks[0U], 3);
        sMultiWord2MultiWord(&pr2_US_hap_B.r.chunks[0U], 4,
                             &pr2_US_hap_B.r10.chunks[0U], 2);
      }

      sMultiWordShr(&pr2_US_hap_B.r10.chunks[0U], 2, 30U, &tmp_3.chunks[0U], 2);
      pr2_US_hap_DW.DiscreteTransferFcn_states_m = MultiWord2sLong
        (&tmp_3.chunks[0U]);

      /* End of Update for DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn' */
    }

    /* Update for Derivative: '<S14>/Derivative2' */
    if (pr2_US_hap_DW.TimeStampA_g == (rtInf)) {
      pr2_US_hap_DW.TimeStampA_g = pr2_US_hap_M->Timing.t[0];
      lastU = &pr2_US_hap_DW.LastUAtTimeA_p;
    } else if (pr2_US_hap_DW.TimeStampB_c == (rtInf)) {
      pr2_US_hap_DW.TimeStampB_c = pr2_US_hap_M->Timing.t[0];
      lastU = &pr2_US_hap_DW.LastUAtTimeB_n;
    } else if (pr2_US_hap_DW.TimeStampA_g < pr2_US_hap_DW.TimeStampB_c) {
      pr2_US_hap_DW.TimeStampA_g = pr2_US_hap_M->Timing.t[0];
      lastU = &pr2_US_hap_DW.LastUAtTimeA_p;
    } else {
      pr2_US_hap_DW.TimeStampB_c = pr2_US_hap_M->Timing.t[0];
      lastU = &pr2_US_hap_DW.LastUAtTimeB_n;
    }

    *lastU = pr2_US_hap_B.Gain3_k;

    /* End of Update for Derivative: '<S14>/Derivative2' */
    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* Update for UnitDelay: '<S11>/UD' incorporates:
       *  SampleTimeMath: '<S11>/TSamp'
       *
       * About '<S11>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S11>/UD':
       *
       *  Store in Global RAM
       */
      pr2_US_hap_DW.UD_DSTATE = rtb_TSamp;

      /* Update for UnitDelay: '<S15>/UD' incorporates:
       *  SampleTimeMath: '<S15>/TSamp'
       *
       * About '<S15>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S15>/UD':
       *
       *  Store in Global RAM
       */
      pr2_US_hap_DW.UD_DSTATE_m = rtb_TSamp_f;
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((pr2_US_hap_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((pr2_US_hap_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
    rt_ertODEUpdateContinuousStates(&pr2_US_hap_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++pr2_US_hap_M->Timing.clockTick0;
    pr2_US_hap_M->Timing.t[0] = rtsiGetSolverStopTime(&pr2_US_hap_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      pr2_US_hap_M->Timing.clockTick1++;
    }

    switch (pr2_US_hap_M->Timing.rtmDbBufReadBuf2) {
     case 0:
      pr2_US_hap_M->Timing.rtmDbBufWriteBuf2 = 1;
      break;

     case 1:
      pr2_US_hap_M->Timing.rtmDbBufWriteBuf2 = 0;
      break;

     default:
      pr2_US_hap_M->Timing.rtmDbBufWriteBuf2 =
        !pr2_US_hap_M->Timing.rtmDbBufLastBufWr2;
      break;
    }

    pr2_US_hap_M->Timing.rtmDbBufClockTick2
      [pr2_US_hap_M->Timing.rtmDbBufWriteBuf2] = pr2_US_hap_M->Timing.clockTick0;
    pr2_US_hap_M->Timing.rtmDbBufLastBufWr2 =
      pr2_US_hap_M->Timing.rtmDbBufWriteBuf2;
    pr2_US_hap_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void pr2_US_hap_derivatives(void)
{
  XDot_pr2_US_hap_T *_rtXdot;
  _rtXdot = ((XDot_pr2_US_hap_T *) pr2_US_hap_M->derivs);

  /* Derivatives for Integrator: '<S10>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = pr2_US_hap_B.Gain1_p;

  /* Derivatives for Integrator: '<S14>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_f = pr2_US_hap_B.Gain1_g;
}

/* Model initialize function */
void pr2_US_hap_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&pr2_US_hap_M->solverInfo,
                          &pr2_US_hap_M->Timing.simTimeStep);
    rtsiSetTPtr(&pr2_US_hap_M->solverInfo, &rtmGetTPtr(pr2_US_hap_M));
    rtsiSetStepSizePtr(&pr2_US_hap_M->solverInfo,
                       &pr2_US_hap_M->Timing.stepSize0);
    rtsiSetdXPtr(&pr2_US_hap_M->solverInfo, &pr2_US_hap_M->derivs);
    rtsiSetContStatesPtr(&pr2_US_hap_M->solverInfo, (real_T **)
                         &pr2_US_hap_M->contStates);
    rtsiSetNumContStatesPtr(&pr2_US_hap_M->solverInfo,
      &pr2_US_hap_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&pr2_US_hap_M->solverInfo,
      &pr2_US_hap_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&pr2_US_hap_M->solverInfo,
      &pr2_US_hap_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&pr2_US_hap_M->solverInfo,
      &pr2_US_hap_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&pr2_US_hap_M->solverInfo, (boolean_T**)
      &pr2_US_hap_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&pr2_US_hap_M->solverInfo, (&rtmGetErrorStatus
      (pr2_US_hap_M)));
    rtsiSetRTModelPtr(&pr2_US_hap_M->solverInfo, pr2_US_hap_M);
  }

  rtsiSetSimTimeStep(&pr2_US_hap_M->solverInfo, MAJOR_TIME_STEP);
  pr2_US_hap_M->intgData.y = pr2_US_hap_M->odeY;
  pr2_US_hap_M->intgData.f[0] = pr2_US_hap_M->odeF[0];
  pr2_US_hap_M->intgData.f[1] = pr2_US_hap_M->odeF[1];
  pr2_US_hap_M->intgData.f[2] = pr2_US_hap_M->odeF[2];
  pr2_US_hap_M->contStates = ((X_pr2_US_hap_T *) &pr2_US_hap_X);
  pr2_US_hap_M->contStateDisabled = ((XDis_pr2_US_hap_T *) &pr2_US_hap_XDis);
  pr2_US_hap_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&pr2_US_hap_M->solverInfo, (void *)&pr2_US_hap_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&pr2_US_hap_M->solverInfo, false);
  rtsiSetSolverName(&pr2_US_hap_M->solverInfo,"ode3");
  rtmSetTPtr(pr2_US_hap_M, &pr2_US_hap_M->Timing.tArray[0]);
  rtmSetTFinal(pr2_US_hap_M, -1);
  pr2_US_hap_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  pr2_US_hap_M->Sizes.checksums[0] = (3121233060U);
  pr2_US_hap_M->Sizes.checksums[1] = (2460855214U);
  pr2_US_hap_M->Sizes.checksums[2] = (1357738547U);
  pr2_US_hap_M->Sizes.checksums[3] = (2397395330U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    pr2_US_hap_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&pr2_US_hap_DW.SW1PUSH_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&pr2_US_hap_DW.SW1PUSH1_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pr2_US_hap_M->extModeInfo,
      &pr2_US_hap_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pr2_US_hap_M->extModeInfo, pr2_US_hap_M->Sizes.checksums);
    rteiSetTPtr(pr2_US_hap_M->extModeInfo, rtmGetTPtr(pr2_US_hap_M));
  }

  pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 0xFF;
  pr2_US_hap_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
  pr2_US_hap_M->Timing.rtmDbBufLastBufWr2 = 0;

  /* Start for Constant: '<Root>/Constant3' */
  pr2_US_hap_B.Constant3 = pr2_US_hap_P.f;

  /* Start for Constant: '<Root>/Constant1' */
  pr2_US_hap_B.Constant1 = pr2_US_hap_P.r;

  /* Start for Constant: '<Root>/Constant2' */
  pr2_US_hap_B.Constant2 = pr2_US_hap_P.b;

  /* InitializeConditions for Integrator: '<S10>/Integrator2' */
  pr2_US_hap_X.Integrator2_CSTATE = pr2_US_hap_P.Integrator2_IC;

  /* InitializeConditions for RateTransition generated from: '<S3>/Chart' */
  pr2_US_hap_DW.TmpRTBAtChartInport1_Buffer0 =
    pr2_US_hap_P.TmpRTBAtChartInport1_InitialCon;
  pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf = -1;
  pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf = -1;

  /* InitializeConditions for DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
  pr2_US_hap_DW.DiscreteTransferFcn_states =
    pr2_US_hap_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for Derivative: '<S10>/Derivative2' */
  pr2_US_hap_DW.TimeStampA = (rtInf);
  pr2_US_hap_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S14>/Integrator2' */
  pr2_US_hap_X.Integrator2_CSTATE_f = pr2_US_hap_P.Integrator2_IC_f;

  /* InitializeConditions for DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn' */
  pr2_US_hap_DW.DiscreteTransferFcn_states_m =
    pr2_US_hap_P.DiscreteTransferFcn_InitialSt_i;

  /* InitializeConditions for Derivative: '<S14>/Derivative2' */
  pr2_US_hap_DW.TimeStampA_g = (rtInf);
  pr2_US_hap_DW.TimeStampB_c = (rtInf);

  /* InitializeConditions for RateTransition generated from: '<Root>/Display2' */
  pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_Buffer0 =
    pr2_US_hap_P.TmpRTBAtDisplay2Inport1_Initial;
  pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b = -1;
  pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu = -1;

  /* InitializeConditions for RateTransition generated from: '<S3>/Display' */
  pr2_US_hap_DW.TmpRTBAtDisplayInport1_Buffer0 =
    pr2_US_hap_P.TmpRTBAtDisplayInport1_InitialC;
  pr2_US_hap_DW.TmpRTBAtDisplayInport1_write_bu = -1;
  pr2_US_hap_DW.TmpRTBAtDisplayInport1_read_buf = -1;

  /* InitializeConditions for UnitDelay: '<S11>/UD'
   *
   * Block description for '<S11>/UD':
   *
   *  Store in Global RAM
   */
  pr2_US_hap_DW.UD_DSTATE = pr2_US_hap_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S15>/UD'
   *
   * Block description for '<S15>/UD':
   *
   *  Store in Global RAM
   */
  pr2_US_hap_DW.UD_DSTATE_m = pr2_US_hap_P.DiscreteDerivative_ICPrevScal_g;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt(SW1)' incorporates:
   *  SubSystem: '<Root>/SW1 PUSH'
   */

  /* System initialize for function-call system: '<Root>/SW1 PUSH' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (pr2_US_hap_M->Timing.rtmDbBufWriteBuf2) {
   case 0:
    pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 1;
    break;

   case 1:
    pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 0;
    break;

   default:
    pr2_US_hap_M->Timing.rtmDbBufReadBuf2 =
      pr2_US_hap_M->Timing.rtmDbBufLastBufWr2;
    break;
  }

  pr2_US_hap_M->Timing.clockTick2 = pr2_US_hap_M->
    Timing.rtmDbBufClockTick2[pr2_US_hap_M->Timing.rtmDbBufReadBuf2];
  pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 0xFF;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  pr2_US_hap_DW.Delay_DSTATE_a = pr2_US_hap_P.Delay_InitialCondition;

  /* SystemInitialize for Sum: '<S1>/Add' incorporates:
   *  Outport: '<S1>/sw1'
   */
  pr2_US_hap_B.Add_h = pr2_US_hap_P.sw1_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, RISING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt(SW1)' */
  pr2_US_hap_SW1PUSH1_Init();

  /* Start for MATLABSystem: '<Root>/가변저항' */
  pr2_US_hap_DW.obj_n.matlabCodegenIsDeleted = false;
  pr2_US_hap_DW.obj_n.SampleTime = pr2_US_hap_P._SampleTime;
  pr2_US_hap_DW.obj_n.isInitialized = 1L;
  pr2_US_hap_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(62UL);
  pr2_US_hap_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S13>/PWM' */
  pr2_US_hap_DW.obj_d.matlabCodegenIsDeleted = false;
  pr2_US_hap_DW.obj_d.isInitialized = 1L;
  pr2_US_hap_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(3UL, 0.0, 0.0);
  pr2_US_hap_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/PWM' */
  pr2_US_hap_DW.obj_a.matlabCodegenIsDeleted = false;
  pr2_US_hap_DW.obj_a.isInitialized = 1L;
  pr2_US_hap_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  pr2_US_hap_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/PWM' */
  pr2_US_hap_DW.obj_l.matlabCodegenIsDeleted = false;
  pr2_US_hap_DW.obj_l.isInitialized = 1L;
  pr2_US_hap_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  pr2_US_hap_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/PWM1' */
  pr2_US_hap_DW.obj_g.matlabCodegenIsDeleted = false;
  pr2_US_hap_DW.obj_g.isInitialized = 1L;
  pr2_US_hap_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
  pr2_US_hap_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/PWM2' */
  pr2_US_hap_DW.obj_e.matlabCodegenIsDeleted = false;
  pr2_US_hap_DW.obj_e.isInitialized = 1L;
  pr2_US_hap_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
  pr2_US_hap_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Encoder' */
  pr2_US_hap_DW.obj_p.Index = 0U;
  pr2_US_hap_DW.obj_p.matlabCodegenIsDeleted = false;
  pr2_US_hap_DW.obj_p.SampleTime = pr2_US_hap_P.Encoder_SampleTime;
  pr2_US_hap_DW.obj_p.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &pr2_US_hap_DW.obj_p.Index);
  pr2_US_hap_DW.obj_p.isSetupComplete = true;
  pr2_US_hap_DW.obj_p.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S8>/Encoder' */
  MW_EncoderReset(pr2_US_hap_DW.obj_p.Index);

  /* Start for MATLABSystem: '<S12>/Encoder' */
  pr2_US_hap_DW.obj.Index = 0U;
  pr2_US_hap_DW.obj.matlabCodegenIsDeleted = false;
  pr2_US_hap_DW.obj.SampleTime = pr2_US_hap_P.Encoder_SampleTime_e;
  pr2_US_hap_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(20UL, 21UL, &pr2_US_hap_DW.obj.Index);
  pr2_US_hap_DW.obj.isSetupComplete = true;
  pr2_US_hap_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S12>/Encoder' */
  MW_EncoderReset(pr2_US_hap_DW.obj.Index);
  pr2_US_hap_SW1PUSH1_Init();
}

/* Model terminate function */
void pr2_US_hap_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/가변저항' */
  if (!pr2_US_hap_DW.obj_n.matlabCodegenIsDeleted) {
    pr2_US_hap_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((pr2_US_hap_DW.obj_n.isInitialized == 1L) &&
        pr2_US_hap_DW.obj_n.isSetupComplete) {
      pr2_US_hap_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close(pr2_US_hap_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/가변저항' */
  /* Terminate for MATLABSystem: '<S13>/PWM' */
  if (!pr2_US_hap_DW.obj_d.matlabCodegenIsDeleted) {
    pr2_US_hap_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((pr2_US_hap_DW.obj_d.isInitialized == 1L) &&
        pr2_US_hap_DW.obj_d.isSetupComplete) {
      pr2_US_hap_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
      MW_PWM_SetDutyCycle(pr2_US_hap_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      pr2_US_hap_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
      MW_PWM_Close(pr2_US_hap_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/PWM' */
  /* Terminate for MATLABSystem: '<S9>/PWM' */
  if (!pr2_US_hap_DW.obj_a.matlabCodegenIsDeleted) {
    pr2_US_hap_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((pr2_US_hap_DW.obj_a.isInitialized == 1L) &&
        pr2_US_hap_DW.obj_a.isSetupComplete) {
      pr2_US_hap_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(pr2_US_hap_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      pr2_US_hap_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(pr2_US_hap_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/PWM' */
  /* Terminate for MATLABSystem: '<S3>/PWM' */
  if (!pr2_US_hap_DW.obj_l.matlabCodegenIsDeleted) {
    pr2_US_hap_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((pr2_US_hap_DW.obj_l.isInitialized == 1L) &&
        pr2_US_hap_DW.obj_l.isSetupComplete) {
      pr2_US_hap_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(pr2_US_hap_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      pr2_US_hap_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(pr2_US_hap_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM' */

  /* Terminate for MATLABSystem: '<S3>/PWM1' */
  if (!pr2_US_hap_DW.obj_g.matlabCodegenIsDeleted) {
    pr2_US_hap_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((pr2_US_hap_DW.obj_g.isInitialized == 1L) &&
        pr2_US_hap_DW.obj_g.isSetupComplete) {
      pr2_US_hap_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(pr2_US_hap_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      pr2_US_hap_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(pr2_US_hap_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM1' */

  /* Terminate for MATLABSystem: '<S3>/PWM2' */
  if (!pr2_US_hap_DW.obj_e.matlabCodegenIsDeleted) {
    pr2_US_hap_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((pr2_US_hap_DW.obj_e.isInitialized == 1L) &&
        pr2_US_hap_DW.obj_e.isSetupComplete) {
      pr2_US_hap_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle(pr2_US_hap_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      pr2_US_hap_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(pr2_US_hap_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM2' */
  /* Terminate for MATLABSystem: '<S8>/Encoder' */
  if (!pr2_US_hap_DW.obj_p.matlabCodegenIsDeleted) {
    pr2_US_hap_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((pr2_US_hap_DW.obj_p.isInitialized == 1L) &&
        pr2_US_hap_DW.obj_p.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Encoder' */
  /* Terminate for MATLABSystem: '<S12>/Encoder' */
  if (!pr2_US_hap_DW.obj.matlabCodegenIsDeleted) {
    pr2_US_hap_DW.obj.matlabCodegenIsDeleted = true;
    if ((pr2_US_hap_DW.obj.isInitialized == 1L) &&
        pr2_US_hap_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S12>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
