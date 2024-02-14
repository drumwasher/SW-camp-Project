/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: integration_2.c
 *
 * Code generated for Simulink model 'integration_2'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Feb 14 09:58:12 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "integration_2.h"
#include "rtwtypes.h"
#include "integration_2_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "multiword_types.h"
#include <float.h>

/* Named constants for Chart: '<S16>/Chart' */
#define integration_2_IN_adas_off      (1UL)
#define integration_2_IN_adas_on       (2UL)

/* Named constants for Chart: '<S15>/Chart' */
#define integration_2_IN_Drive_off     (1UL)
#define integration_2_IN_Drive_on      (2UL)

/* Named constants for Chart: '<S43>/Chart1' */
#define integration_2_IN_light_auto    (1UL)
#define integration_2_IN_light_off     (2UL)
#define integration_2_IN_light_on      (3UL)

/* Block signals (default storage) */
B_integration_2_T integration_2_B;

/* Continuous states */
X_integration_2_T integration_2_X;

/* Disabled State Vector */
XDis_integration_2_T integration_2_XDis;

/* Block states (default storage) */
DW_integration_2_T integration_2_DW;

/* Real-time model */
static RT_MODEL_integration_2_T integration_2_M_;
RT_MODEL_integration_2_T *const integration_2_M = &integration_2_M_;
static void rate_scheduler(void);
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

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt' */
void MW_ISR_2(void)
{
  /* Call the system: <S15>/SW1 */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.SW1_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<S15>/SW1' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (integration_2_M->Timing.rtmDbBufWriteBuf4) {
     case 0:
      integration_2_M->Timing.rtmDbBufReadBuf4 = 1;
      break;

     case 1:
      integration_2_M->Timing.rtmDbBufReadBuf4 = 0;
      break;

     default:
      integration_2_M->Timing.rtmDbBufReadBuf4 =
        integration_2_M->Timing.rtmDbBufLastBufWr4;
      break;
    }

    integration_2_M->Timing.clockTick4 =
      integration_2_M->Timing.rtmDbBufClockTick4
      [integration_2_M->Timing.rtmDbBufReadBuf4];
    integration_2_M->Timing.rtmDbBufReadBuf4 = 0xFF;

    /* Sum: '<S20>/Sum' incorporates:
     *  Constant: '<S20>/Constant'
     *  Delay: '<S20>/Delay'
     */
    integration_2_DW.Delay_DSTATE_p += integration_2_P.Constant_Value;

    /* Math: '<S20>/Mod' incorporates:
     *  Constant: '<S20>/Constant1'
     */
    integration_2_B.Mod_b = rt_modd_snf(integration_2_DW.Delay_DSTATE_p,
      integration_2_P.Constant1_Value);
    integration_2_DW.SW1_SubsysRanBC = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
  }

  extmodeEvent(4,((integration_2_M->Timing.clockTick4) * 0.01));
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (integration_2_M->Timing.TaskCounters.TID[2])++;
  if ((integration_2_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    integration_2_M->Timing.TaskCounters.TID[2] = 0;
  }

  (integration_2_M->Timing.TaskCounters.TID[3])++;
  if ((integration_2_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.2s, 0.0s] */
    integration_2_M->Timing.TaskCounters.TID[3] = 0;
  }
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
  integration_2_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  integration_2_step();
  integration_2_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  integration_2_step();
  integration_2_derivatives();

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

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/*
 * Output and update for action system:
 *    '<S4>/If Action Subsystem1'
 *    '<S4>/If Action Subsystem3'
 */
void integration__IfActionSubsystem1(real_T *rty_Out1,
  P_IfActionSubsystem1_integrat_T *localP)
{
  /* SignalConversion generated from: '<S12>/Out1' incorporates:
   *  Constant: '<S12>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S21>/If Action Subsystem1'
 *    '<S25>/If Action Subsystem'
 */
void integratio_IfActionSubsystem1_l(RT_MODEL_integration_2_T * const
  integration_2_M, real_T *rty_Out1, real_T *rty_Out2,
  P_IfActionSubsystem1_integr_d_T *localP)
{
  if (rtmIsMajorTimeStep(integration_2_M) &&
      integration_2_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S23>/Out1' incorporates:
     *  Constant: '<S23>/Constant'
     */
    *rty_Out1 = localP->Constant_Value;

    /* SignalConversion generated from: '<S23>/Out2' incorporates:
     *  Constant: '<S23>/Constant1'
     */
    *rty_Out2 = localP->Constant1_Value;
  }
}

/*
 * Output and update for action system:
 *    '<S45>/If Action Subsystem'
 *    '<S45>/If Action Subsystem2'
 */
void integration_2_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1, real_T
  *rty_Out2)
{
  /* SignalConversion generated from: '<S46>/Out1' incorporates:
   *  SignalConversion generated from: '<S46>/In1'
   */
  *rty_Out1 = rtu_In1;

  /* SignalConversion generated from: '<S46>/Out2' incorporates:
   *  SignalConversion generated from: '<S46>/In1'
   */
  *rty_Out2 = rtu_In1;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void integration_2_step(void)
{
  /* local block i/o variables */
  int32_T rtb_TSamp;
  int32_T rtb_TSamp_f;
  if (rtmIsMajorTimeStep(integration_2_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&integration_2_M->solverInfo,
                          ((integration_2_M->Timing.clockTick0+1)*
      integration_2_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(integration_2_M)) {
    integration_2_M->Timing.t[0] = rtsiGetT(&integration_2_M->solverInfo);
  }

  {
    int64m_T tmp_1;
    real_T rtb_Merge_o;
    real_T *lastU;
    int32_T tmp;
    uint32_T duration;
    uint32_T rtb_Gain4;
    uint32_T tmp_0;
    uint16_T b_varargout_1;
    int8_T rtAction;
    uint8_T tmp_2;
    static const int64m_T tmp_3 = { { 0UL, 0UL }/* chunks */
    };

    static const int64m_T tmp_4 = { { 25UL, 0UL }/* chunks */
    };

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem6_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem7_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem1_SubsysRanB_h);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem3_SubsysRan_df);

    /* Reset subsysRan breadcrumbs */
    srClearBC
      (integration_2_DW.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem1_SubsysRanB_k);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem_SubsysRanB_ng);

    /* Reset subsysRan breadcrumbs */
    srClearBC
      (integration_2_DW.IfActionSubsystem1_l.IfActionSubsystem1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem_SubsysRanBC_l);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem2_SubsysRanB_p);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem_SubsysRanBC_n);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem1_SubsysRanB_i);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem2_SubsysRanB_f);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem3_SubsysRanB_d);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem1_SubsysRanB_e);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem3_SubsysRanB_g);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem3_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem_SubsysRanBC_i);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem_c.IfActionSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem1_SubsysRanB_g);

    /* Reset subsysRan breadcrumbs */
    srClearBC(integration_2_DW.IfActionSubsystem1_SubsysRanBC);

    /* Integrator: '<S36>/Integrator2' */
    integration_2_B.Derivative2 = integration_2_X.Integrator2_CSTATE;
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* RateTransition: '<S15>/Rate Transition' */
      integration_2_B.RateTransition = integration_2_B.Mod_b;

      /* Delay: '<Root>/Delay' */
      integration_2_B.Delay = integration_2_DW.Delay_DSTATE;

      /* Delay: '<S5>/Delay' */
      integration_2_B.Delay_h = integration_2_DW.Delay_DSTATE_e;

      /* Chart: '<S15>/Chart' */
      if (integration_2_DW.is_active_c3_integration_2 == 0U) {
        integration_2_DW.is_active_c3_integration_2 = 1U;
        integration_2_DW.is_c3_integration_2 = integration_2_IN_Drive_off;
        integration_2_B.drive_mode = 0.0;
        integration_2_DW.state_1_e = integration_2_B.RateTransition;
      } else if (integration_2_DW.is_c3_integration_2 ==
                 integration_2_IN_Drive_off) {
        if (integration_2_DW.state_1_e != integration_2_B.RateTransition) {
          integration_2_DW.is_c3_integration_2 = integration_2_IN_Drive_on;
          integration_2_B.drive_mode = 1.0;
          integration_2_DW.state_1_e = integration_2_B.RateTransition;
          integration_2_DW.ADAS_state = integration_2_B.Delay_h;
          integration_2_DW.Light_state = integration_2_B.Delay;
        } else {
          integration_2_B.drive_mode = 0.0;
          integration_2_DW.state_1_e = integration_2_B.RateTransition;
        }

        /* case IN_Drive_on: */
      } else if ((integration_2_DW.state_1_e != integration_2_B.RateTransition) &&
                 (integration_2_DW.ADAS_state == 0.0) &&
                 (integration_2_DW.Light_state == 0.0)) {
        integration_2_DW.is_c3_integration_2 = integration_2_IN_Drive_off;
        integration_2_B.drive_mode = 0.0;
        integration_2_DW.state_1_e = integration_2_B.RateTransition;
      } else {
        integration_2_B.drive_mode = 1.0;
        integration_2_DW.state_1_e = integration_2_B.RateTransition;
        integration_2_DW.ADAS_state = integration_2_B.Delay_h;
        integration_2_DW.Light_state = integration_2_B.Delay;
      }

      /* End of Chart: '<S15>/Chart' */
    }

    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[2] == 0) {
      /* MATLABSystem: '<Root>/Digital Input1' */
      if (integration_2_DW.obj_i.SampleTime !=
          integration_2_P.DigitalInput1_SampleTime) {
        integration_2_DW.obj_i.SampleTime =
          integration_2_P.DigitalInput1_SampleTime;
      }

      /* MATLABSystem: '<Root>/Digital Input1' */
      integration_2_B.DigitalInput1 = readDigitalPin(31);
    }

    /* RateTransition: '<S14>/Rate Transition2' */
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* RateTransition: '<S14>/Rate Transition2' */
      integration_2_B.RateTransition2 = integration_2_B.DigitalInput1;
    }

    /* End of RateTransition: '<S14>/Rate Transition2' */

    /* If: '<S14>/If' */
    rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
      if (!integration_2_B.RateTransition2) {
        rtAction = 0;
      }

      integration_2_DW.If_ActiveSubsystem = rtAction;
    } else {
      rtAction = integration_2_DW.If_ActiveSubsystem;
    }

    if (rtAction == 0) {
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      if (rtmIsMajorTimeStep(integration_2_M) &&
          integration_2_M->Timing.TaskCounters.TID[1] == 0) {
        /* Sum: '<S17>/Sum' incorporates:
         *  Constant: '<S17>/Constant'
         *  Delay: '<S17>/Delay'
         */
        integration_2_DW.Delay_DSTATE_d += integration_2_P.Constant_Value_h;

        /* Math: '<S17>/Mod' incorporates:
         *  Constant: '<S17>/Constant1'
         *  Delay: '<S17>/Delay'
         */
        integration_2_B.Mod_a = rt_modd_snf(integration_2_DW.Delay_DSTATE_d,
          integration_2_P.Constant1_Value_g);
      }

      if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        srUpdateBC(integration_2_DW.IfActionSubsystem1_SubsysRanB_k);
      }

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem1' */
    }

    /* End of If: '<S14>/If' */

    /* If: '<S5>/If' */
    rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
      if (integration_2_B.drive_mode == 1.0) {
        rtAction = 0;
      }

      integration_2_DW.If_ActiveSubsystem_p = rtAction;
    } else {
      rtAction = integration_2_DW.If_ActiveSubsystem_p;
    }

    if (rtAction == 0) {
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      if (rtmIsMajorTimeStep(integration_2_M) &&
          integration_2_M->Timing.TaskCounters.TID[1] == 0) {
        /* Chart: '<S16>/Chart' */
        if (integration_2_DW.is_active_c1_integration_2 == 0U) {
          integration_2_DW.is_active_c1_integration_2 = 1U;
          integration_2_DW.is_c1_integration_2 = integration_2_IN_adas_off;
          integration_2_B.ADAS_state = integration_2_B.Mod_a;
          integration_2_DW.state_2 = integration_2_B.Mod_a;
        } else if (integration_2_DW.is_c1_integration_2 ==
                   integration_2_IN_adas_off) {
          if (integration_2_DW.state_2 != integration_2_B.Mod_a) {
            integration_2_DW.is_c1_integration_2 = integration_2_IN_adas_on;
            integration_2_B.ADAS_state = integration_2_B.Mod_a;
            integration_2_DW.state_2 = integration_2_B.Mod_a;
          } else {
            integration_2_B.ADAS_state = integration_2_B.Mod_a;
            integration_2_DW.state_2 = integration_2_B.Mod_a;
          }

          /* case IN_adas_on: */
        } else if (integration_2_DW.state_2 != integration_2_B.Mod_a) {
          integration_2_DW.is_c1_integration_2 = integration_2_IN_adas_off;
          integration_2_B.ADAS_state = integration_2_B.Mod_a;
          integration_2_DW.state_2 = integration_2_B.Mod_a;
        } else {
          integration_2_B.ADAS_state = integration_2_B.Mod_a;
          integration_2_DW.state_2 = integration_2_B.Mod_a;
        }

        /* End of Chart: '<S16>/Chart' */
      }

      if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        srUpdateBC(integration_2_DW.IfActionSubsystem_SubsysRanB_ng);
      }

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem' */
    }

    /* End of If: '<S5>/If' */

    /* If: '<S21>/If' */
    if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
      integration_2_DW.If_ActiveSubsystem_h = (int8_T)
        !(integration_2_B.drive_mode == 0.0);
    }

    if (integration_2_DW.If_ActiveSubsystem_h == 0) {
      /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      integratio_IfActionSubsystem1_l(integration_2_M, &integration_2_B.Merge,
        &integration_2_B.Merge1, &integration_2_P.IfActionSubsystem1_l);
      if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        srUpdateBC
          (integration_2_DW.IfActionSubsystem1_l.IfActionSubsystem1_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S21>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* SignalConversion generated from: '<S22>/In1' */
      integration_2_B.In1 = integration_2_B.ADAS_state;
      if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        srUpdateBC(integration_2_DW.IfActionSubsystem_SubsysRanBC_l);
      }

      /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */
    }

    /* End of If: '<S21>/If' */
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<Root>/Constant2' */
      integration_2_B.Constant2 = integration_2_P.l;

      /* Constant: '<Root>/Constant6' */
      integration_2_B.Constant6 = integration_2_P.r;

      /* Constant: '<Root>/Constant3' */
      integration_2_B.Constant3 = integration_2_P.b;
    }

    /* MATLABSystem: '<Root>/가변저항' */
    if (integration_2_DW.obj_k.SampleTime != integration_2_P._SampleTime) {
      integration_2_DW.obj_k.SampleTime = integration_2_P._SampleTime;
    }

    integration_2_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
      MW_AnalogIn_GetHandle(62UL);
    MW_AnalogInSingle_ReadResult
      (integration_2_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
       &b_varargout_1, MW_ANALOGIN_UINT16);

    /* Gain: '<S6>/Gain4' incorporates:
     *  MATLABSystem: '<Root>/가변저항'
     * */
    rtb_Gain4 = (uint32_T)integration_2_P.Gain4_Gain * b_varargout_1;
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* MATLABSystem: '<Root>/전방 초음파1' */
      if (integration_2_DW.obj_lf.TunablePropsChanged) {
        integration_2_DW.obj_lf.TunablePropsChanged = false;
      }

      MW_UltrasonicRead(&duration, 1, 46, 47, 10);

      /* Gain: '<Root>/Gain2' incorporates:
       *  MATLABSystem: '<Root>/전방 초음파1'
       * */
      integration_2_B.Add5 = (real_T)duration * 0.000343 / 2.0 *
        integration_2_P.Gain2_Gain;

      /* Saturate: '<Root>/Saturation' */
      if (integration_2_B.Add5 > integration_2_P.Saturation_UpperSat) {
        /* Saturate: '<Root>/Saturation' */
        integration_2_B.Merge3 = integration_2_P.Saturation_UpperSat;
      } else if (integration_2_B.Add5 < integration_2_P.Saturation_LowerSat) {
        /* Saturate: '<Root>/Saturation' */
        integration_2_B.Merge3 = integration_2_P.Saturation_LowerSat;
      } else {
        /* Saturate: '<Root>/Saturation' */
        integration_2_B.Merge3 = integration_2_B.Add5;
      }

      /* End of Saturate: '<Root>/Saturation' */

      /* If: '<Root>/If3' incorporates:
       *  Delay: '<Root>/Delay1'
       *  Sum: '<Root>/Sum'
       */
      if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        integration_2_DW.If3_ActiveSubsystem = (int8_T)!(integration_2_B.Merge3
          - integration_2_DW.Delay1_DSTATE > 25.0);
      }

      if (integration_2_DW.If3_ActiveSubsystem == 0) {
        /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem6' incorporates:
         *  ActionPort: '<S1>/Action Port'
         */
        /* Saturate: '<Root>/Saturation' incorporates:
         *  Delay: '<Root>/Delay1'
         *  Merge: '<Root>/Merge3'
         *  SignalConversion generated from: '<S1>/In1'
         */
        integration_2_B.Merge3 = integration_2_DW.Delay1_DSTATE;
        if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
          srUpdateBC(integration_2_DW.IfActionSubsystem6_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<Root>/If Action Subsystem6' */

        /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem7' incorporates:
         *  ActionPort: '<S2>/Action Port'
         */
      } else if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        srUpdateBC(integration_2_DW.IfActionSubsystem7_SubsysRanBC);

        /* End of Outputs for SubSystem: '<Root>/If Action Subsystem7' */
      }

      /* End of If: '<Root>/If3' */
    }

    /* If: '<S21>/If1' incorporates:
     *  If: '<S25>/If'
     */
    if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
      integration_2_DW.If1_ActiveSubsystem = (int8_T)!(integration_2_B.In1 ==
        0.0);
    }

    if (integration_2_DW.If1_ActiveSubsystem == 0) {
      /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
       *  Gain: '<S6>/Gain4'
       */
      integration_2_B.Product_p = (real_T)rtb_Gain4 * 7.62939453125E-6;

      /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      /* Merge: '<S21>/Merge' incorporates:
       *  Constant: '<S24>/Constant'
       *  Constant: '<S24>/Constant1'
       *  Constant: '<S24>/Constant2'
       *  Constant: '<S24>/Constant4'
       *  Constant: '<S24>/Constant5'
       *  DataTypeConversion: '<S6>/Data Type Conversion'
       *  Product: '<S24>/Divide'
       *  Product: '<S24>/Divide1'
       *  Product: '<S24>/Product'
       *  Sum: '<S24>/Minus'
       *  Sum: '<S24>/Sum'
       */
      integration_2_B.Merge = ((integration_2_B.Product_p -
        integration_2_P.Constant2_Value) / integration_2_P.Constant5_Value /
        integration_2_P.Constant1_Value_o + integration_2_P.Constant4_Value) *
        integration_2_P.Constant_Value_l;

      /* Merge: '<S21>/Merge1' incorporates:
       *  Constant: '<S24>/Constant3'
       *  Constant: '<S24>/Constant6'
       *  Constant: '<S24>/Constant7'
       *  Constant: '<S24>/Constant8'
       *  Constant: '<S24>/Constant9'
       *  Product: '<S24>/Divide2'
       *  Product: '<S24>/Divide3'
       *  Product: '<S24>/Product1'
       *  Sum: '<S24>/Minus1'
       *  Sum: '<S24>/Sum1'
       */
      integration_2_B.Merge1 = ((integration_2_P.Constant7_Value -
        integration_2_B.Product_p) / integration_2_P.Constant9_Value /
        integration_2_P.Constant6_Value + integration_2_P.Constant8_Value) *
        integration_2_P.Constant3_Value;
      if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        srUpdateBC(integration_2_DW.IfActionSubsystem2_SubsysRanB_p);
      }

      /* End of Outputs for SubSystem: '<S21>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        /* If: '<S25>/If' */
        integration_2_DW.If_ActiveSubsystem_f = (int8_T)!(integration_2_B.Merge3
          > 10.0);
      }

      /* If: '<S25>/If' */
      if (integration_2_DW.If_ActiveSubsystem_f == 0) {
        /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        if (rtmIsMajorTimeStep(integration_2_M) &&
            integration_2_M->Timing.TaskCounters.TID[1] == 0) {
          /* If: '<S27>/If' */
          if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
            if ((integration_2_B.Constant2 < 10.0) && (integration_2_B.Constant6
                 < 10.0)) {
              /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem' incorporates:
               *  ActionPort: '<S30>/Action Port'
               */
              /* Product: '<S30>/Product' incorporates:
               *  Constant: '<S30>/Constant1'
               *  Sum: '<S30>/Subtract'
               */
              integration_2_B.Product_p = (integration_2_B.Constant2 -
                integration_2_B.Constant6) * integration_2_P.steering;

              /* Merge: '<S25>/Merge' incorporates:
               *  Constant: '<S30>/Constant'
               *  Constant: '<S30>/Constant2'
               *  Product: '<S30>/Product1'
               *  Sum: '<S30>/Subtract1'
               */
              integration_2_B.Merge_b = (integration_2_P.Constant2_Value_i -
                integration_2_B.Product_p) * integration_2_P.default1;

              /* Merge: '<S25>/Merge1' incorporates:
               *  Constant: '<S30>/Constant2'
               *  Constant: '<S30>/Constant3'
               *  Product: '<S30>/Product3'
               *  Sum: '<S30>/Subtract3'
               */
              integration_2_B.Merge1_m = (integration_2_P.Constant2_Value_i +
                integration_2_B.Product_p) * integration_2_P.default1;

              /* End of Outputs for SubSystem: '<S27>/If Action Subsystem' */

              /* Update for IfAction SubSystem: '<S27>/If Action Subsystem' incorporates:
               *  ActionPort: '<S30>/Action Port'
               */
              /* Update for If: '<S27>/If' */
              if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
                srUpdateBC(integration_2_DW.IfActionSubsystem_SubsysRanBC_n);
              }

              /* End of Update for SubSystem: '<S27>/If Action Subsystem' */
            } else if (integration_2_B.Constant2 < 10.0) {
              /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S31>/Action Port'
               */
              /* Sum: '<S31>/Subtract' incorporates:
               *  Constant: '<S31>/Constant4'
               */
              integration_2_B.Subtract = integration_2_P.Constant4_Value_f -
                integration_2_B.Constant2;

              /* Product: '<S31>/Product' incorporates:
               *  Constant: '<S31>/Constant1'
               */
              integration_2_B.Product = integration_2_P.steering *
                integration_2_B.Subtract;

              /* Merge: '<S25>/Merge1' incorporates:
               *  Constant: '<S31>/Constant'
               *  Constant: '<S31>/Constant2'
               *  Product: '<S31>/Product3'
               *  Sum: '<S31>/Subtract3'
               */
              integration_2_B.Merge1_m = (integration_2_P.Constant2_Value_b -
                integration_2_B.Product) * integration_2_P.default1;

              /* Sum: '<S31>/Subtract1' incorporates:
               *  Constant: '<S31>/Constant2'
               */
              integration_2_B.Subtract1 = integration_2_P.Constant2_Value_b +
                integration_2_B.Product;

              /* Product: '<S31>/Product1' incorporates:
               *  Constant: '<S31>/Constant'
               */
              integration_2_B.Product1 = integration_2_P.default1 *
                integration_2_B.Subtract1;

              /* Merge: '<S25>/Merge' incorporates:
               *  SignalConversion generated from: '<S31>/Out2'
               */
              integration_2_B.Merge_b = integration_2_B.Product1;

              /* Update for IfAction SubSystem: '<S27>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S31>/Action Port'
               */
              /* Update for If: '<S27>/If' */
              if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
                srUpdateBC(integration_2_DW.IfActionSubsystem1_SubsysRanB_i);
              }

              /* End of Update for SubSystem: '<S27>/If Action Subsystem1' */
            } else if (integration_2_B.Constant6 < 10.0) {
              /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S32>/Action Port'
               */
              /* Product: '<S32>/Product' incorporates:
               *  Constant: '<S32>/Constant1'
               *  Constant: '<S32>/Constant4'
               *  Sum: '<S32>/Subtract'
               */
              integration_2_B.Product_p = (integration_2_P.Constant4_Value_p -
                integration_2_B.Constant6) * integration_2_P.steering;

              /* Merge: '<S25>/Merge' incorporates:
               *  Constant: '<S32>/Constant'
               *  Constant: '<S32>/Constant2'
               *  Product: '<S32>/Product1'
               *  Sum: '<S32>/Subtract1'
               */
              integration_2_B.Merge_b = (integration_2_P.Constant2_Value_im -
                integration_2_B.Product_p) * integration_2_P.default1;

              /* Merge: '<S25>/Merge1' incorporates:
               *  Constant: '<S32>/Constant'
               *  Constant: '<S32>/Constant2'
               *  Product: '<S32>/Product3'
               *  Sum: '<S32>/Subtract3'
               */
              integration_2_B.Merge1_m = (integration_2_P.Constant2_Value_im +
                integration_2_B.Product_p) * integration_2_P.default1;

              /* End of Outputs for SubSystem: '<S27>/If Action Subsystem2' */

              /* Update for IfAction SubSystem: '<S27>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S32>/Action Port'
               */
              /* Update for If: '<S27>/If' */
              if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
                srUpdateBC(integration_2_DW.IfActionSubsystem2_SubsysRanB_f);
              }

              /* End of Update for SubSystem: '<S27>/If Action Subsystem2' */
            } else {
              /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem3' incorporates:
               *  ActionPort: '<S33>/Action Port'
               */
              /* Merge: '<S25>/Merge' incorporates:
               *  Constant: '<S33>/Constant'
               *  SignalConversion generated from: '<S33>/Out1'
               */
              integration_2_B.Merge_b = integration_2_P.Constant_Value_f;

              /* Merge: '<S25>/Merge1' incorporates:
               *  Constant: '<S33>/Constant1'
               *  SignalConversion generated from: '<S33>/Out2'
               */
              integration_2_B.Merge1_m = integration_2_P.Constant1_Value_j;

              /* End of Outputs for SubSystem: '<S27>/If Action Subsystem3' */

              /* Update for IfAction SubSystem: '<S27>/If Action Subsystem3' incorporates:
               *  ActionPort: '<S33>/Action Port'
               */
              /* Update for If: '<S27>/If' */
              if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
                srUpdateBC(integration_2_DW.IfActionSubsystem3_SubsysRanB_d);
              }

              /* End of Update for SubSystem: '<S27>/If Action Subsystem3' */
            }
          }

          /* End of If: '<S27>/If' */
        }

        if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
          srUpdateBC(integration_2_DW.IfActionSubsystem1_SubsysRanB_e);
        }

        /* End of Outputs for SubSystem: '<S25>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        integratio_IfActionSubsystem1_l(integration_2_M,
          &integration_2_B.Merge_b, &integration_2_B.Merge1_m,
          &integration_2_P.IfActionSubsystem_n);
        if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
          srUpdateBC
            (integration_2_DW.IfActionSubsystem_n.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S25>/If Action Subsystem' */
      }

      if (rtmIsMajorTimeStep(integration_2_M) &&
          integration_2_M->Timing.TaskCounters.TID[1] == 0) {
        /* If: '<S25>/If1' */
        if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
          if (integration_2_B.Constant3 > 10.0) {
            /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S28>/Action Port'
             */
            /* Merge: '<S21>/Merge' incorporates:
             *  SignalConversion generated from: '<S28>/In1'
             */
            integration_2_B.Merge = integration_2_B.Merge_b;

            /* Merge: '<S21>/Merge1' incorporates:
             *  SignalConversion generated from: '<S28>/In2'
             */
            integration_2_B.Merge1 = integration_2_B.Merge1_m;

            /* End of Outputs for SubSystem: '<S25>/If Action Subsystem2' */

            /* Update for IfAction SubSystem: '<S25>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S28>/Action Port'
             */
            /* Update for If: '<S25>/If1' */
            if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
              srUpdateBC(integration_2_DW.IfActionSubsystem2_SubsysRanBC);
            }

            /* End of Update for SubSystem: '<S25>/If Action Subsystem2' */
          } else {
            /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem3' incorporates:
             *  ActionPort: '<S29>/Action Port'
             */
            /* Merge: '<S21>/Merge' incorporates:
             *  Gain: '<S29>/Gain'
             */
            integration_2_B.Merge = integration_2_P.Gain_Gain *
              integration_2_B.Merge_b;

            /* Merge: '<S21>/Merge1' incorporates:
             *  Gain: '<S29>/Gain1'
             */
            integration_2_B.Merge1 = integration_2_P.Gain1_Gain *
              integration_2_B.Merge1_m;

            /* End of Outputs for SubSystem: '<S25>/If Action Subsystem3' */

            /* Update for IfAction SubSystem: '<S25>/If Action Subsystem3' incorporates:
             *  ActionPort: '<S29>/Action Port'
             */
            /* Update for If: '<S25>/If1' */
            if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
              srUpdateBC(integration_2_DW.IfActionSubsystem3_SubsysRanB_g);
            }

            /* End of Update for SubSystem: '<S25>/If Action Subsystem3' */
          }
        }

        /* End of If: '<S25>/If1' */
      }

      if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        srUpdateBC(integration_2_DW.IfActionSubsystem3_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S21>/If Action Subsystem3' */
    }

    /* End of If: '<S21>/If1' */
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* DiscreteTransferFcn: '<S34>/Discrete Transfer Fcn' */
      integration_2_B.DiscreteTransferFcn = tmp_3;

      /* DiscreteTransferFcn: '<S34>/Discrete Transfer Fcn' */
      duration = (uint32_T)integration_2_P.num_Gd[1L];
      tmp_0 = (uint32_T)integration_2_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&duration, 1, &tmp_0, 1,
                    &integration_2_B.DiscreteTransferFcn.chunks[0U], 2);

      /* Sum: '<S7>/Add5' incorporates:
       *  DiscreteTransferFcn: '<S34>/Discrete Transfer Fcn'
       */
      integration_2_B.Add5 = integration_2_B.Merge1 - sMultiWord2Double
        (&integration_2_B.DiscreteTransferFcn.chunks[0U], 2, 0) *
        1.1641532182693481E-10;

      /* Gain: '<S36>/Gain2' */
      integration_2_B.Gain2_gz = integration_2_P.KP * integration_2_B.Add5;

      /* Gain: '<S36>/Gain3' */
      integration_2_B.Gain3 = integration_2_P.KD * integration_2_B.Add5;
    }

    /* Derivative: '<S36>/Derivative2' incorporates:
     *  Derivative: '<S40>/Derivative2'
     */
    integration_2_B.Product_p = integration_2_M->Timing.t[0];
    if ((integration_2_DW.TimeStampA >= integration_2_B.Product_p) &&
        (integration_2_DW.TimeStampB >= integration_2_B.Product_p)) {
      integration_2_B.Gain1_m = 0.0;
    } else {
      integration_2_B.Gain1_m = integration_2_DW.TimeStampA;
      lastU = &integration_2_DW.LastUAtTimeA;
      if (integration_2_DW.TimeStampA < integration_2_DW.TimeStampB) {
        if (integration_2_DW.TimeStampB < integration_2_B.Product_p) {
          integration_2_B.Gain1_m = integration_2_DW.TimeStampB;
          lastU = &integration_2_DW.LastUAtTimeB;
        }
      } else if (integration_2_DW.TimeStampA >= integration_2_B.Product_p) {
        integration_2_B.Gain1_m = integration_2_DW.TimeStampB;
        lastU = &integration_2_DW.LastUAtTimeB;
      }

      integration_2_B.Gain1_m = (integration_2_B.Gain3 - *lastU) /
        (integration_2_B.Product_p - integration_2_B.Gain1_m);
    }

    /* End of Derivative: '<S36>/Derivative2' */

    /* Sum: '<S36>/Subtract2' */
    integration_2_B.Subtract2 = (integration_2_B.Derivative2 +
      integration_2_B.Gain2_gz) + integration_2_B.Gain1_m;

    /* Saturate: '<S7>/Saturation2' */
    if (integration_2_B.Subtract2 > integration_2_P.Saturation2_UpperSat) {
      /* Saturate: '<S7>/Saturation2' */
      integration_2_B.Saturation2 = integration_2_P.Saturation2_UpperSat;
    } else if (integration_2_B.Subtract2 < integration_2_P.Saturation2_LowerSat)
    {
      /* Saturate: '<S7>/Saturation2' */
      integration_2_B.Saturation2 = integration_2_P.Saturation2_LowerSat;
    } else {
      /* Saturate: '<S7>/Saturation2' */
      integration_2_B.Saturation2 = integration_2_B.Subtract2;
    }

    /* End of Saturate: '<S7>/Saturation2' */

    /* DataTypeConversion: '<S35>/Data Type Conversion' incorporates:
     *  Gain: '<S35>/Gain1'
     */
    integration_2_B.Derivative2 = floor(255.0 / integration_2_P.Vlim *
      integration_2_B.Saturation2);
    if (rtIsNaN(integration_2_B.Derivative2) || rtIsInf
        (integration_2_B.Derivative2)) {
      integration_2_B.Derivative2 = 0.0;
    } else {
      integration_2_B.Derivative2 = fmod(integration_2_B.Derivative2, 256.0);
    }

    /* DataTypeConversion: '<S35>/Data Type Conversion' */
    integration_2_B.DataTypeConversion = (uint8_T)(integration_2_B.Derivative2 <
      0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-integration_2_B.Derivative2 :
      (int16_T)(uint8_T)integration_2_B.Derivative2);

    /* DataTypeConversion: '<S35>/Data Type Conversion1' */
    integration_2_B.DataTypeConversion1 = integration_2_B.DataTypeConversion;
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S7>/Mux3' */
      integration_2_B.TmpSignalConversionAtTAQSigLogg[0] = 0.0;
      integration_2_B.TmpSignalConversionAtTAQSigLogg[1] =
        integration_2_B.DataTypeConversion1;

      /* DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' */
      integration_2_B.DiscreteTransferFcn_c = tmp_3;

      /* DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' */
      duration = (uint32_T)integration_2_P.num_Gd[1L];
      tmp_0 = (uint32_T)integration_2_DW.DiscreteTransferFcn_states_m;
      sMultiWordMul(&duration, 1, &tmp_0, 1,
                    &integration_2_B.DiscreteTransferFcn_c.chunks[0U], 2);

      /* Sum: '<S8>/Add3' incorporates:
       *  DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn'
       */
      integration_2_B.PulseGenerator_e = integration_2_B.Merge -
        sMultiWord2Double(&integration_2_B.DiscreteTransferFcn_c.chunks[0U], 2,
                          0) * 1.1641532182693481E-10;

      /* Gain: '<S40>/Gain2' */
      integration_2_B.Gain2_f = integration_2_P.KP *
        integration_2_B.PulseGenerator_e;

      /* Gain: '<S40>/Gain3' */
      integration_2_B.Gain3_k = integration_2_P.KD *
        integration_2_B.PulseGenerator_e;
    }

    /* Derivative: '<S40>/Derivative2' */
    if ((integration_2_DW.TimeStampA_g >= integration_2_B.Product_p) &&
        (integration_2_DW.TimeStampB_c >= integration_2_B.Product_p)) {
      integration_2_B.Derivative2 = 0.0;
    } else {
      integration_2_B.Gain1_m = integration_2_DW.TimeStampA_g;
      lastU = &integration_2_DW.LastUAtTimeA_p;
      if (integration_2_DW.TimeStampA_g < integration_2_DW.TimeStampB_c) {
        if (integration_2_DW.TimeStampB_c < integration_2_B.Product_p) {
          integration_2_B.Gain1_m = integration_2_DW.TimeStampB_c;
          lastU = &integration_2_DW.LastUAtTimeB_n;
        }
      } else if (integration_2_DW.TimeStampA_g >= integration_2_B.Product_p) {
        integration_2_B.Gain1_m = integration_2_DW.TimeStampB_c;
        lastU = &integration_2_DW.LastUAtTimeB_n;
      }

      integration_2_B.Derivative2 = (integration_2_B.Gain3_k - *lastU) /
        (integration_2_B.Product_p - integration_2_B.Gain1_m);
    }

    /* Sum: '<S40>/Subtract2' incorporates:
     *  Integrator: '<S40>/Integrator2'
     */
    integration_2_B.Subtract2_p = (integration_2_X.Integrator2_CSTATE_f +
      integration_2_B.Gain2_f) + integration_2_B.Derivative2;

    /* Saturate: '<S8>/Saturation1' */
    if (integration_2_B.Subtract2_p > integration_2_P.Saturation1_UpperSat) {
      /* Saturate: '<S8>/Saturation1' */
      integration_2_B.Saturation1 = integration_2_P.Saturation1_UpperSat;
    } else if (integration_2_B.Subtract2_p <
               integration_2_P.Saturation1_LowerSat) {
      /* Saturate: '<S8>/Saturation1' */
      integration_2_B.Saturation1 = integration_2_P.Saturation1_LowerSat;
    } else {
      /* Saturate: '<S8>/Saturation1' */
      integration_2_B.Saturation1 = integration_2_B.Subtract2_p;
    }

    /* End of Saturate: '<S8>/Saturation1' */

    /* DataTypeConversion: '<S39>/Data Type Conversion' incorporates:
     *  Gain: '<S39>/Gain1'
     */
    integration_2_B.Product_p = floor(255.0 / integration_2_P.Vlim *
      integration_2_B.Saturation1);
    if (rtIsNaN(integration_2_B.Product_p) || rtIsInf(integration_2_B.Product_p))
    {
      integration_2_B.Product_p = 0.0;
    } else {
      integration_2_B.Product_p = fmod(integration_2_B.Product_p, 256.0);
    }

    /* DataTypeConversion: '<S39>/Data Type Conversion' */
    integration_2_B.DataTypeConversion_g = (uint8_T)(integration_2_B.Product_p <
      0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-integration_2_B.Product_p :
      (int16_T)(uint8_T)integration_2_B.Product_p);

    /* DataTypeConversion: '<S39>/Data Type Conversion1' */
    integration_2_B.DataTypeConversion1_e = integration_2_B.DataTypeConversion_g;
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S8>/Mux2' */
      integration_2_B.TmpSignalConversionAtTAQSigLo_j[0] = 0.0;
      integration_2_B.TmpSignalConversionAtTAQSigLo_j[1] =
        integration_2_B.DataTypeConversion1_e;
    }

    /* MATLABSystem: '<S39>/PWM' */
    integration_2_DW.obj_dm.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
    MW_PWM_SetDutyCycle(integration_2_DW.obj_dm.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)integration_2_B.DataTypeConversion_g);
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S40>/Gain1' */
      integration_2_B.Gain1_g = integration_2_P.KI *
        integration_2_B.PulseGenerator_e;
    }

    /* MATLABSystem: '<S35>/PWM' */
    integration_2_DW.obj_ar.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
    MW_PWM_SetDutyCycle(integration_2_DW.obj_ar.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)integration_2_B.DataTypeConversion);
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S36>/Gain1' */
      integration_2_B.Gain1_p = integration_2_P.KI * integration_2_B.Add5;
    }

    /* MATLABSystem: '<S6>/PWM' */
    integration_2_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
     *  Gain: '<S6>/Gain4'
     */
    integration_2_B.Add5 = (real_T)rtb_Gain4 * 7.62939453125E-6;

    /* Start for MATLABSystem: '<S6>/PWM' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     */
    if (integration_2_B.Add5 <= 255.0) {
      integration_2_B.Product_p = integration_2_B.Add5;
    } else {
      integration_2_B.Product_p = 255.0;
    }

    /* MATLABSystem: '<S6>/PWM' */
    MW_PWM_SetDutyCycle(integration_2_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                        integration_2_B.Product_p);

    /* MATLABSystem: '<S6>/PWM1' */
    integration_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Start for MATLABSystem: '<S6>/PWM1' */
    if (integration_2_B.Add5 <= 255.0) {
      integration_2_B.Product_p = integration_2_B.Add5;
    } else {
      integration_2_B.Product_p = 255.0;
    }

    /* MATLABSystem: '<S6>/PWM1' */
    MW_PWM_SetDutyCycle(integration_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
                        integration_2_B.Product_p);

    /* MATLABSystem: '<S6>/PWM2' */
    integration_2_DW.obj_av.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);

    /* Start for MATLABSystem: '<S6>/PWM2' */
    if (!(integration_2_B.Add5 <= 255.0)) {
      integration_2_B.Add5 = 255.0;
    }

    /* MATLABSystem: '<S6>/PWM2' */
    MW_PWM_SetDutyCycle(integration_2_DW.obj_av.PWMDriverObj.MW_PWM_HANDLE,
                        integration_2_B.Add5);
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* DiscretePulseGenerator: '<S3>/Pulse Generator' */
      integration_2_B.PulseGenerator_e = (integration_2_DW.clockTickCounter <
        integration_2_P.PulseGenerator_Duty) &&
        (integration_2_DW.clockTickCounter >= 0L) ?
        integration_2_P.PulseGenerator_Amp : 0.0;
      if (integration_2_DW.clockTickCounter >=
          integration_2_P.PulseGenerator_Period - 1.0) {
        integration_2_DW.clockTickCounter = 0L;
      } else {
        integration_2_DW.clockTickCounter++;
      }

      /* End of DiscretePulseGenerator: '<S3>/Pulse Generator' */

      /* If: '<S3>/If1' */
      if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        integration_2_DW.If1_ActiveSubsystem_b = (int8_T)
          !(integration_2_B.ADAS_state == 1.0);
      }

      if (integration_2_DW.If1_ActiveSubsystem_b == 0) {
        /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S10>/Action Port'
         */
        /* SignalConversion generated from: '<S10>/Input' incorporates:
         *  Constant: '<S3>/Constant'
         *  Product: '<S3>/Product1'
         */
        rtb_Merge_o = integration_2_P.Constant_Value_hx *
          integration_2_B.drive_mode;
        if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
          srUpdateBC(integration_2_DW.IfActionSubsystem1_SubsysRanB_h);
        }

        /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S11>/Action Port'
         */
        /* SignalConversion generated from: '<S11>/Input' incorporates:
         *  Product: '<S3>/Product'
         */
        rtb_Merge_o = integration_2_B.drive_mode *
          integration_2_B.PulseGenerator_e;
        if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
          srUpdateBC(integration_2_DW.IfActionSubsystem3_SubsysRan_df);
        }

        /* End of Outputs for SubSystem: '<S3>/If Action Subsystem3' */
      }

      /* End of If: '<S3>/If1' */
    }

    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[2] == 0) {
      /* MATLABSystem: '<Root>/Digital Input' */
      if (integration_2_DW.obj_h.SampleTime !=
          integration_2_P.DigitalInput_SampleTime) {
        integration_2_DW.obj_h.SampleTime =
          integration_2_P.DigitalInput_SampleTime;
      }

      /* MATLABSystem: '<Root>/Digital Input' */
      integration_2_B.DigitalInput = readDigitalPin(36);
    }

    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[3] == 0) {
      /* If: '<S9>/If' */
      rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        if (!integration_2_B.DigitalInput) {
          rtAction = 0;
        }

        integration_2_DW.If_ActiveSubsystem_l = rtAction;
      } else {
        rtAction = integration_2_DW.If_ActiveSubsystem_l;
      }

      if (rtAction == 0) {
        /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem' incorporates:
         *  ActionPort: '<S42>/Action Port'
         */
        /* Sum: '<S42>/Plus' incorporates:
         *  Constant: '<S42>/Constant'
         *  Delay: '<S42>/Delay'
         */
        integration_2_DW.Delay_DSTATE_j += integration_2_P.Constant_Value_fm;

        /* Math: '<S42>/Mod' incorporates:
         *  Constant: '<S42>/Constant1'
         *  Delay: '<S42>/Delay'
         */
        integration_2_B.Mod = rt_modd_snf(integration_2_DW.Delay_DSTATE_j,
          integration_2_P.Constant1_Value_c);

        /* Update for Delay: '<S42>/Delay' */
        integration_2_DW.Delay_DSTATE_j = integration_2_B.Mod;
        if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
          srUpdateBC(integration_2_DW.IfActionSubsystem_SubsysRanBC_i);
        }

        /* End of Outputs for SubSystem: '<S9>/If Action Subsystem' */
      }

      /* End of If: '<S9>/If' */
    }

    /* RateTransition: '<S9>/Rate Transition' */
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* RateTransition: '<S9>/Rate Transition' */
      integration_2_B.RateTransition_p = integration_2_B.Mod;

      /* Chart: '<S43>/Chart1' */
      if (integration_2_DW.is_active_c4_integration_2 == 0U) {
        integration_2_DW.is_active_c4_integration_2 = 1U;
        integration_2_DW.is_c4_integration_2 = integration_2_IN_light_off;
        integration_2_B.light_mode = 0.0;
        integration_2_DW.state_1 = integration_2_B.RateTransition_p;
      } else {
        switch (integration_2_DW.is_c4_integration_2) {
         case integration_2_IN_light_auto:
          if ((integration_2_DW.state_1 != integration_2_B.RateTransition_p) &&
              (integration_2_B.drive_mode == 1.0)) {
            integration_2_DW.is_c4_integration_2 = integration_2_IN_light_on;
            integration_2_B.light_mode = 2.0;
            integration_2_DW.state_1 = integration_2_B.RateTransition_p;
          } else {
            integration_2_B.light_mode = 1.0;
            integration_2_DW.state_1 = integration_2_B.RateTransition_p;
          }
          break;

         case integration_2_IN_light_off:
          if ((integration_2_DW.state_1 != integration_2_B.RateTransition_p) &&
              (integration_2_B.drive_mode == 1.0)) {
            integration_2_DW.is_c4_integration_2 = integration_2_IN_light_auto;
            integration_2_B.light_mode = 1.0;
            integration_2_DW.state_1 = integration_2_B.RateTransition_p;
          } else {
            integration_2_B.light_mode = 0.0;
            integration_2_DW.state_1 = integration_2_B.RateTransition_p;
          }
          break;

         default:
          /* case IN_light_on: */
          if ((integration_2_DW.state_1 != integration_2_B.RateTransition_p) &&
              (integration_2_B.drive_mode == 1.0)) {
            integration_2_DW.is_c4_integration_2 = integration_2_IN_light_off;
            integration_2_B.light_mode = 0.0;
            integration_2_DW.state_1 = integration_2_B.RateTransition_p;
          } else {
            integration_2_B.light_mode = 2.0;
            integration_2_DW.state_1 = integration_2_B.RateTransition_p;
          }
          break;
        }
      }

      /* End of Chart: '<S43>/Chart1' */
      /* MATLABSystem: '<Root>/Analog Input1' */
      if (integration_2_DW.obj_d.SampleTime !=
          integration_2_P.AnalogInput1_SampleTime) {
        integration_2_DW.obj_d.SampleTime =
          integration_2_P.AnalogInput1_SampleTime;
      }

      integration_2_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(55UL);
      MW_AnalogInSingle_ReadResult
        (integration_2_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
         &b_varargout_1, MW_ANALOGIN_UINT16);

      /* DiscretePulseGenerator: '<S45>/Pulse Generator' */
      integration_2_B.Add5 = (integration_2_DW.clockTickCounter_l <
        integration_2_P.PulseGenerator_Duty_n) &&
        (integration_2_DW.clockTickCounter_l >= 0L) ?
        integration_2_P.PulseGenerator_Amp_a : 0.0;
      if (integration_2_DW.clockTickCounter_l >=
          integration_2_P.PulseGenerator_Period_p - 1.0) {
        integration_2_DW.clockTickCounter_l = 0L;
      } else {
        integration_2_DW.clockTickCounter_l++;
      }

      /* End of DiscretePulseGenerator: '<S45>/Pulse Generator' */

      /* If: '<S45>/If' incorporates:
       *  Constant: '<S45>/Constant'
       *  Constant: '<S45>/Constant1'
       */
      rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        if (integration_2_B.light_mode == 0.0) {
          rtAction = 0;
        } else if (integration_2_B.light_mode == 1.0) {
          rtAction = 1;
        } else if (integration_2_B.light_mode == 2.0) {
          rtAction = 2;
        }

        integration_2_DW.If_ActiveSubsystem_ho = rtAction;
      } else {
        rtAction = integration_2_DW.If_ActiveSubsystem_ho;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem' incorporates:
         *  ActionPort: '<S46>/Action Port'
         */
        integration_2_IfActionSubsystem(integration_2_P.Constant1_Value_m,
          &integration_2_B.Merge_a, &integration_2_B.Merge1_k);
        if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
          srUpdateBC
            (integration_2_DW.IfActionSubsystem_c.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S45>/If Action Subsystem' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S47>/Action Port'
         */
        /* If: '<S47>/If' incorporates:
         *  DataTypeConversion: '<S45>/Data Type Conversion'
         *  Gain: '<S45>/Gain'
         *  MATLABSystem: '<Root>/Analog Input1'
         * */
        if ((uint8_T)(((uint32_T)integration_2_P.Gain_Gain_e * b_varargout_1) >>
                      17) <= 150) {
          /* Outputs for IfAction SubSystem: '<S47>/If Action Subsystem' incorporates:
           *  ActionPort: '<S49>/Action Port'
           */
          /* Merge: '<S45>/Merge' incorporates:
           *  Constant: '<S47>/Constant'
           *  SignalConversion generated from: '<S49>/In1'
           */
          integration_2_B.Merge_a = integration_2_P.Constant_Value_k;

          /* End of Outputs for SubSystem: '<S47>/If Action Subsystem' */

          /* Update for IfAction SubSystem: '<S47>/If Action Subsystem' incorporates:
           *  ActionPort: '<S49>/Action Port'
           */
          /* Update for If: '<S47>/If' */
          srUpdateBC(integration_2_DW.IfActionSubsystem_SubsysRanBC);

          /* End of Update for SubSystem: '<S47>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S47>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S50>/Action Port'
           */
          /* Merge: '<S45>/Merge' incorporates:
           *  Constant: '<S47>/Constant1'
           *  SignalConversion generated from: '<S50>/In1'
           */
          integration_2_B.Merge_a = integration_2_P.Constant1_Value_f;

          /* End of Outputs for SubSystem: '<S47>/If Action Subsystem1' */

          /* Update for IfAction SubSystem: '<S47>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S50>/Action Port'
           */
          /* Update for If: '<S47>/If' */
          srUpdateBC(integration_2_DW.IfActionSubsystem1_SubsysRanB_g);

          /* End of Update for SubSystem: '<S47>/If Action Subsystem1' */
        }

        /* End of If: '<S47>/If' */

        /* Merge: '<S45>/Merge1' incorporates:
         *  SignalConversion generated from: '<S47>/In1'
         */
        integration_2_B.Merge1_k = integration_2_B.Add5;
        if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
          srUpdateBC(integration_2_DW.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S45>/If Action Subsystem1' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S48>/Action Port'
         */
        integration_2_IfActionSubsystem(integration_2_P.Constant_Value_n,
          &integration_2_B.Merge_a, &integration_2_B.Merge1_k);
        if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
          srUpdateBC
            (integration_2_DW.IfActionSubsystem2_p.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S45>/If Action Subsystem2' */
        break;
      }

      /* End of If: '<S45>/If' */

      /* If: '<S4>/If1' */
      if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
        integration_2_DW.If1_ActiveSubsystem_d = (int8_T)
          !(integration_2_B.drive_mode == 1.0);
      }

      if (integration_2_DW.If1_ActiveSubsystem_d == 0) {
        /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S12>/Action Port'
         */
        integration__IfActionSubsystem1(&integration_2_B.Add5,
          &integration_2_P.IfActionSubsystem1_e);
        if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
          srUpdateBC
            (integration_2_DW.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S13>/Action Port'
         */
        integration__IfActionSubsystem1(&integration_2_B.Add5,
          &integration_2_P.IfActionSubsystem3_c);
        if (rtsiIsModeUpdateTimeStep(&integration_2_M->solverInfo)) {
          srUpdateBC
            (integration_2_DW.IfActionSubsystem3_c.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S4>/If Action Subsystem3' */
      }

      /* End of If: '<S4>/If1' */
      /* MATLABSystem: '<S4>/Digital Output' */
      integration_2_B.Product_p = rt_roundd_snf(integration_2_B.Add5);
      if (integration_2_B.Product_p < 256.0) {
        if (integration_2_B.Product_p >= 0.0) {
          tmp_2 = (uint8_T)integration_2_B.Product_p;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint8_T;
      }

      writeDigitalPin(42, tmp_2);

      /* End of MATLABSystem: '<S4>/Digital Output' */

      /* MATLABSystem: '<S45>/Digital Output' */
      integration_2_B.Product_p = rt_roundd_snf(integration_2_B.Merge_a);
      if (integration_2_B.Product_p < 256.0) {
        if (integration_2_B.Product_p >= 0.0) {
          tmp_2 = (uint8_T)integration_2_B.Product_p;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint8_T;
      }

      writeDigitalPin(44, tmp_2);

      /* End of MATLABSystem: '<S45>/Digital Output' */

      /* MATLABSystem: '<S45>/Digital Output1' */
      integration_2_B.Product_p = rt_roundd_snf(integration_2_B.Merge1_k);
      if (integration_2_B.Product_p < 256.0) {
        if (integration_2_B.Product_p >= 0.0) {
          tmp_2 = (uint8_T)integration_2_B.Product_p;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint8_T;
      }

      writeDigitalPin(45, tmp_2);

      /* End of MATLABSystem: '<S45>/Digital Output1' */
    }

    /* End of RateTransition: '<S9>/Rate Transition' */
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[3] == 0) {
    }

    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* MATLABSystem: '<S3>/Digital Output' */
      integration_2_B.Product_p = rt_roundd_snf(rtb_Merge_o);
      if (integration_2_B.Product_p < 256.0) {
        if (integration_2_B.Product_p >= 0.0) {
          tmp_2 = (uint8_T)integration_2_B.Product_p;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint8_T;
      }

      writeDigitalPin(43, tmp_2);

      /* End of MATLABSystem: '<S3>/Digital Output' */
      /* MATLABSystem: '<Root>/PWM1' */
      integration_2_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

      /* Start for MATLABSystem: '<Root>/PWM1' incorporates:
       *  Constant: '<S6>/Constant'
       */
      if (integration_2_P.Constant_Value_kp <= 255.0) {
        rtb_Merge_o = integration_2_P.Constant_Value_kp;
      } else {
        rtb_Merge_o = 255.0;
      }

      if (!(rtb_Merge_o >= 0.0)) {
        rtb_Merge_o = 0.0;
      }

      /* MATLABSystem: '<Root>/PWM1' */
      MW_PWM_SetDutyCycle(integration_2_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE,
                          rtb_Merge_o);
    }

    /* MATLABSystem: '<S34>/Encoder' */
    if (integration_2_DW.obj_p.SampleTime != integration_2_P.Encoder_SampleTime)
    {
      integration_2_DW.obj_p.SampleTime = integration_2_P.Encoder_SampleTime;
    }

    if (integration_2_DW.obj_p.TunablePropsChanged) {
      integration_2_DW.obj_p.TunablePropsChanged = false;
    }

    MW_EncoderRead(integration_2_DW.obj_p.Index, &tmp);
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* SampleTimeMath: '<S37>/TSamp' incorporates:
       *  MATLABSystem: '<S34>/Encoder'
       *
       * About '<S37>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       */
      rtb_TSamp = tmp;

      /* Gain: '<S34>/Gain1' incorporates:
       *  SampleTimeMath: '<S37>/TSamp'
       *  Sum: '<S37>/Diff'
       *  UnitDelay: '<S37>/UD'
       *
       * About '<S37>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S37>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S37>/UD':
       *
       *  Store in Global RAM
       */
      duration = (uint32_T)integration_2_P.encoder_scale;
      tmp_0 = (uint32_T)(rtb_TSamp - integration_2_DW.UD_DSTATE);
      sMultiWordMul(&duration, 1, &tmp_0, 1, &integration_2_B.Gain1.chunks[0U],
                    2);

      /* Gain: '<S34>/Gain2' incorporates:
       *  Gain: '<S34>/Gain1'
       */
      sMultiWordMul(&integration_2_P.Gain2_Gain_n.chunks[0U], 2,
                    &integration_2_B.Gain1.chunks[0U], 2,
                    &integration_2_B.Gain2.chunks[0U], 4);

      /* DataTypeConversion: '<S34>/Data Type Conversion1' incorporates:
       *  Gain: '<S34>/Gain1'
       */
      tmp_1 = integration_2_B.Gain1;
      sMultiWordMul(&integration_2_B.Gain1.chunks[0U], 2, &tmp_4.chunks[0U], 2,
                    &integration_2_B.r2.chunks[0U], 4);
      sMultiWordShr(&integration_2_B.r2.chunks[0U], 4, 31U,
                    &integration_2_B.r1.chunks[0U], 4);

      /* DataTypeConversion: '<S34>/Data Type Conversion1' */
      integration_2_B.DataTypeConversion1_d = MultiWord2sLong
        (&integration_2_B.r1.chunks[0U]);
    }

    /* MATLABSystem: '<S38>/Encoder' */
    if (integration_2_DW.obj.SampleTime != integration_2_P.Encoder_SampleTime_e)
    {
      integration_2_DW.obj.SampleTime = integration_2_P.Encoder_SampleTime_e;
    }

    if (integration_2_DW.obj.TunablePropsChanged) {
      integration_2_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(integration_2_DW.obj.Index, &tmp);
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* SampleTimeMath: '<S41>/TSamp' incorporates:
       *  MATLABSystem: '<S38>/Encoder'
       *
       * About '<S41>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       */
      rtb_TSamp_f = tmp;

      /* Gain: '<S38>/Gain1' incorporates:
       *  SampleTimeMath: '<S41>/TSamp'
       *  Sum: '<S41>/Diff'
       *  UnitDelay: '<S41>/UD'
       *
       * About '<S41>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S41>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S41>/UD':
       *
       *  Store in Global RAM
       */
      duration = (uint32_T)integration_2_P.encoder_scale;
      tmp_0 = (uint32_T)(rtb_TSamp_f - integration_2_DW.UD_DSTATE_m);
      sMultiWordMul(&duration, 1, &tmp_0, 1, &tmp_1.chunks[0U], 2);

      /* Gain: '<S38>/Gain1' incorporates:
       *  Gain: '<S34>/Gain2'
       */
      integration_2_B.Gain1_a = tmp_1;

      /* Gain: '<S38>/Gain2' incorporates:
       *  Gain: '<S38>/Gain1'
       */
      sMultiWordMul(&integration_2_P.Gain2_Gain_d.chunks[0U], 2,
                    &integration_2_B.Gain1_a.chunks[0U], 2,
                    &integration_2_B.r2.chunks[0U], 4);

      /* Gain: '<S38>/Gain2' incorporates:
       *  DataTypeConversion: '<S34>/Data Type Conversion1'
       */
      integration_2_B.Gain2_g = integration_2_B.r2;

      /* DataTypeConversion: '<S38>/Data Type Conversion1' incorporates:
       *  Gain: '<S38>/Gain1'
       */
      sMultiWordMul(&integration_2_B.Gain1_a.chunks[0U], 2, &tmp_4.chunks[0U], 2,
                    &integration_2_B.r4.chunks[0U], 4);
      sMultiWordShr(&integration_2_B.r4.chunks[0U], 4, 31U,
                    &integration_2_B.r3.chunks[0U], 4);

      /* DataTypeConversion: '<S38>/Data Type Conversion1' */
      integration_2_B.DataTypeConversion1_a = MultiWord2sLong
        (&integration_2_B.r3.chunks[0U]);
    }
  }

  if (rtmIsMajorTimeStep(integration_2_M)) {
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

    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for Delay: '<Root>/Delay' */
      integration_2_DW.Delay_DSTATE = integration_2_B.light_mode;

      /* Update for Delay: '<S5>/Delay' */
      integration_2_DW.Delay_DSTATE_e = integration_2_B.ADAS_state;

      /* Update for Delay: '<Root>/Delay1' */
      integration_2_DW.Delay1_DSTATE = integration_2_B.Merge3;

      /* Update for DiscreteTransferFcn: '<S34>/Discrete Transfer Fcn' */
      sLong2MultiWord(integration_2_B.DataTypeConversion1_d,
                      &integration_2_B.r12.chunks[0U], 2);
      sMultiWordShl(&integration_2_B.r12.chunks[0U], 2, 30U,
                    &integration_2_B.denAccum.chunks[0U], 2);
      tmp = (uint32_T)integration_2_P.den_Gd[1L];
      tmp_0 = (uint32_T)integration_2_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp, 1, &tmp_0, 1, &integration_2_B.r12.chunks[0U], 2);
      MultiWordSub(&integration_2_B.denAccum.chunks[0U],
                   &integration_2_B.r12.chunks[0U], &denAccum.chunks[0U], 2);
      integration_2_B.denAccum = denAccum;
      if (integration_2_P.den_Gd[0] == 0L) {
        if (sMultiWordGe(&integration_2_B.denAccum.chunks[0U], &tmp_5.chunks[0U],
                         2)) {
          integration_2_B.r11 = tmp_4;
        } else {
          integration_2_B.r11 = tmp_6;
        }
      } else {
        sMultiWord2MultiWord(&integration_2_B.denAccum.chunks[0U], 2,
                             &integration_2_B.r6.chunks[0U], 3);
        sMultiWordShl(&integration_2_B.r6.chunks[0U], 3, 30U,
                      &integration_2_B.r5.chunks[0U], 3);
        sLong2MultiWord(integration_2_P.den_Gd[0], &integration_2_B.r6.chunks[0U],
                        3);
        sMultiWordDivFloor(&integration_2_B.r5.chunks[0U], 3,
                           &integration_2_B.r6.chunks[0U], 3,
                           &integration_2_B.r.chunks[0U], 4,
                           &integration_2_B.r7.chunks[0U], 3,
                           &integration_2_B.r8.chunks[0U], 3,
                           &integration_2_B.r9.chunks[0U], 3);
        sMultiWord2MultiWord(&integration_2_B.r.chunks[0U], 4,
                             &integration_2_B.r11.chunks[0U], 2);
      }

      sMultiWordShr(&integration_2_B.r11.chunks[0U], 2, 30U, &tmp_1.chunks[0U],
                    2);
      integration_2_DW.DiscreteTransferFcn_states = MultiWord2sLong
        (&tmp_1.chunks[0U]);

      /* End of Update for DiscreteTransferFcn: '<S34>/Discrete Transfer Fcn' */
    }

    /* Update for Derivative: '<S36>/Derivative2' */
    if (integration_2_DW.TimeStampA == (rtInf)) {
      integration_2_DW.TimeStampA = integration_2_M->Timing.t[0];
      lastU = &integration_2_DW.LastUAtTimeA;
    } else if (integration_2_DW.TimeStampB == (rtInf)) {
      integration_2_DW.TimeStampB = integration_2_M->Timing.t[0];
      lastU = &integration_2_DW.LastUAtTimeB;
    } else if (integration_2_DW.TimeStampA < integration_2_DW.TimeStampB) {
      integration_2_DW.TimeStampA = integration_2_M->Timing.t[0];
      lastU = &integration_2_DW.LastUAtTimeA;
    } else {
      integration_2_DW.TimeStampB = integration_2_M->Timing.t[0];
      lastU = &integration_2_DW.LastUAtTimeB;
    }

    *lastU = integration_2_B.Gain3;

    /* End of Update for Derivative: '<S36>/Derivative2' */
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' */
      sLong2MultiWord(integration_2_B.DataTypeConversion1_a, &tmp_2.chunks[0U],
                      2);
      sMultiWordShl(&tmp_2.chunks[0U], 2, 30U, &integration_2_B.denAccum.chunks
                    [0U], 2);
      tmp = (uint32_T)integration_2_P.den_Gd[1L];
      tmp_0 = (uint32_T)integration_2_DW.DiscreteTransferFcn_states_m;
      sMultiWordMul(&tmp, 1, &tmp_0, 1, &tmp_2.chunks[0U], 2);
      MultiWordSub(&integration_2_B.denAccum.chunks[0U], &tmp_2.chunks[0U],
                   &denAccum_0.chunks[0U], 2);
      if (integration_2_P.den_Gd[0] == 0L) {
        if (sMultiWordGe(&denAccum_0.chunks[0U], &tmp_5.chunks[0U], 2)) {
          integration_2_B.r10 = tmp_4;
        } else {
          integration_2_B.r10 = tmp_6;
        }
      } else {
        sMultiWord2MultiWord(&denAccum_0.chunks[0U], 2,
                             &integration_2_B.r6.chunks[0U], 3);
        sMultiWordShl(&integration_2_B.r6.chunks[0U], 3, 30U,
                      &integration_2_B.r5.chunks[0U], 3);
        sLong2MultiWord(integration_2_P.den_Gd[0], &integration_2_B.r6.chunks[0U],
                        3);
        sMultiWordDivFloor(&integration_2_B.r5.chunks[0U], 3,
                           &integration_2_B.r6.chunks[0U], 3,
                           &integration_2_B.r.chunks[0U], 4,
                           &integration_2_B.r7.chunks[0U], 3,
                           &integration_2_B.r8.chunks[0U], 3,
                           &integration_2_B.r9.chunks[0U], 3);
        sMultiWord2MultiWord(&integration_2_B.r.chunks[0U], 4,
                             &integration_2_B.r10.chunks[0U], 2);
      }

      sMultiWordShr(&integration_2_B.r10.chunks[0U], 2, 30U, &tmp_3.chunks[0U],
                    2);
      integration_2_DW.DiscreteTransferFcn_states_m = MultiWord2sLong
        (&tmp_3.chunks[0U]);

      /* End of Update for DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' */
    }

    /* Update for Derivative: '<S40>/Derivative2' */
    if (integration_2_DW.TimeStampA_g == (rtInf)) {
      integration_2_DW.TimeStampA_g = integration_2_M->Timing.t[0];
      lastU = &integration_2_DW.LastUAtTimeA_p;
    } else if (integration_2_DW.TimeStampB_c == (rtInf)) {
      integration_2_DW.TimeStampB_c = integration_2_M->Timing.t[0];
      lastU = &integration_2_DW.LastUAtTimeB_n;
    } else if (integration_2_DW.TimeStampA_g < integration_2_DW.TimeStampB_c) {
      integration_2_DW.TimeStampA_g = integration_2_M->Timing.t[0];
      lastU = &integration_2_DW.LastUAtTimeA_p;
    } else {
      integration_2_DW.TimeStampB_c = integration_2_M->Timing.t[0];
      lastU = &integration_2_DW.LastUAtTimeB_n;
    }

    *lastU = integration_2_B.Gain3_k;

    /* End of Update for Derivative: '<S40>/Derivative2' */
    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for UnitDelay: '<S37>/UD' incorporates:
       *  SampleTimeMath: '<S37>/TSamp'
       *
       * About '<S37>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S37>/UD':
       *
       *  Store in Global RAM
       */
      integration_2_DW.UD_DSTATE = rtb_TSamp;

      /* Update for UnitDelay: '<S41>/UD' incorporates:
       *  SampleTimeMath: '<S41>/TSamp'
       *
       * About '<S41>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S41>/UD':
       *
       *  Store in Global RAM
       */
      integration_2_DW.UD_DSTATE_m = rtb_TSamp_f;
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((integration_2_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((integration_2_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.1s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((integration_2_M->Timing.clockTick2 * 10) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(2,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[3] == 0) {/* Sample time: [0.2s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((integration_2_M->Timing.clockTick3 * 20) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(3,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(integration_2_M)) {
    rt_ertODEUpdateContinuousStates(&integration_2_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++integration_2_M->Timing.clockTick0;
    integration_2_M->Timing.t[0] = rtsiGetSolverStopTime
      (&integration_2_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      integration_2_M->Timing.clockTick1++;
    }

    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick2" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick2" ensures timer will not overflow during the
       * application lifespan selected.
       */
      integration_2_M->Timing.clockTick2++;
    }

    if (rtmIsMajorTimeStep(integration_2_M) &&
        integration_2_M->Timing.TaskCounters.TID[3] == 0) {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick3" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick3" ensures timer will not overflow during the
       * application lifespan selected.
       */
      integration_2_M->Timing.clockTick3++;
    }

    switch (integration_2_M->Timing.rtmDbBufReadBuf4) {
     case 0:
      integration_2_M->Timing.rtmDbBufWriteBuf4 = 1;
      break;

     case 1:
      integration_2_M->Timing.rtmDbBufWriteBuf4 = 0;
      break;

     default:
      integration_2_M->Timing.rtmDbBufWriteBuf4 =
        !integration_2_M->Timing.rtmDbBufLastBufWr4;
      break;
    }

    integration_2_M->Timing.rtmDbBufClockTick4
      [integration_2_M->Timing.rtmDbBufWriteBuf4] =
      integration_2_M->Timing.clockTick0;
    integration_2_M->Timing.rtmDbBufLastBufWr4 =
      integration_2_M->Timing.rtmDbBufWriteBuf4;
    integration_2_M->Timing.rtmDbBufWriteBuf4 = 0xFF;
    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void integration_2_derivatives(void)
{
  XDot_integration_2_T *_rtXdot;
  _rtXdot = ((XDot_integration_2_T *) integration_2_M->derivs);

  /* Derivatives for Integrator: '<S36>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = integration_2_B.Gain1_p;

  /* Derivatives for Integrator: '<S40>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_f = integration_2_B.Gain1_g;
}

/* Model initialize function */
void integration_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&integration_2_M->solverInfo,
                          &integration_2_M->Timing.simTimeStep);
    rtsiSetTPtr(&integration_2_M->solverInfo, &rtmGetTPtr(integration_2_M));
    rtsiSetStepSizePtr(&integration_2_M->solverInfo,
                       &integration_2_M->Timing.stepSize0);
    rtsiSetdXPtr(&integration_2_M->solverInfo, &integration_2_M->derivs);
    rtsiSetContStatesPtr(&integration_2_M->solverInfo, (real_T **)
                         &integration_2_M->contStates);
    rtsiSetNumContStatesPtr(&integration_2_M->solverInfo,
      &integration_2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&integration_2_M->solverInfo,
      &integration_2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&integration_2_M->solverInfo,
      &integration_2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&integration_2_M->solverInfo,
      &integration_2_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&integration_2_M->solverInfo, (boolean_T**)
      &integration_2_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&integration_2_M->solverInfo, (&rtmGetErrorStatus
      (integration_2_M)));
    rtsiSetRTModelPtr(&integration_2_M->solverInfo, integration_2_M);
  }

  rtsiSetSimTimeStep(&integration_2_M->solverInfo, MAJOR_TIME_STEP);
  integration_2_M->intgData.y = integration_2_M->odeY;
  integration_2_M->intgData.f[0] = integration_2_M->odeF[0];
  integration_2_M->intgData.f[1] = integration_2_M->odeF[1];
  integration_2_M->intgData.f[2] = integration_2_M->odeF[2];
  integration_2_M->contStates = ((X_integration_2_T *) &integration_2_X);
  integration_2_M->contStateDisabled = ((XDis_integration_2_T *)
    &integration_2_XDis);
  integration_2_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&integration_2_M->solverInfo, (void *)
                    &integration_2_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&integration_2_M->solverInfo, false);
  rtsiSetSolverName(&integration_2_M->solverInfo,"ode3");
  rtmSetTPtr(integration_2_M, &integration_2_M->Timing.tArray[0]);
  rtmSetTFinal(integration_2_M, -1);
  integration_2_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  integration_2_M->Sizes.checksums[0] = (3529669270U);
  integration_2_M->Sizes.checksums[1] = (248840468U);
  integration_2_M->Sizes.checksums[2] = (840564174U);
  integration_2_M->Sizes.checksums[3] = (1499591654U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[48];
    integration_2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem6_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem7_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem1_SubsysRanB_h;
    systemRan[8] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem3_SubsysRan_df;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem3_c.IfActionSubsystem1_SubsysRanBC;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem_SubsysRanB_ng;
    systemRan[14] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem_SubsysRanB_ng;
    systemRan[15] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem1_SubsysRanB_k;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = (sysRanDType *)&integration_2_DW.SW1_SubsysRanBC;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem_SubsysRanBC_l;
    systemRan[22] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem1_l.IfActionSubsystem1_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem2_SubsysRanB_p;
    systemRan[24] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem_n.IfActionSubsystem1_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem_SubsysRanBC_n;
    systemRan[26] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem1_SubsysRanB_i;
    systemRan[27] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem2_SubsysRanB_f;
    systemRan[28] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem3_SubsysRanB_d;
    systemRan[29] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem1_SubsysRanB_e;
    systemRan[30] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem3_SubsysRanB_g;
    systemRan[32] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem3_SubsysRanBC;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem_SubsysRanBC_i;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem_c.IfActionSubsystem_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem1_SubsysRanB_g;
    systemRan[44] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[45] = (sysRanDType *)
      &integration_2_DW.IfActionSubsystem2_p.IfActionSubsystem_SubsysRanBC;
    systemRan[46] = &rtAlwaysEnabled;
    systemRan[47] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(integration_2_M->extModeInfo,
      &integration_2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(integration_2_M->extModeInfo,
                        integration_2_M->Sizes.checksums);
    rteiSetTPtr(integration_2_M->extModeInfo, rtmGetTPtr(integration_2_M));
  }

  integration_2_M->Timing.rtmDbBufReadBuf4 = 0xFF;
  integration_2_M->Timing.rtmDbBufWriteBuf4 = 0xFF;
  integration_2_M->Timing.rtmDbBufLastBufWr4 = 0;

  /* Start for If: '<S14>/If' */
  integration_2_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<S5>/If' */
  integration_2_DW.If_ActiveSubsystem_p = -1;

  /* Start for If: '<S21>/If' */
  integration_2_DW.If_ActiveSubsystem_h = -1;

  /* Start for If: '<Root>/If3' */
  integration_2_DW.If3_ActiveSubsystem = -1;

  /* Start for If: '<S21>/If1' */
  integration_2_DW.If1_ActiveSubsystem = -1;

  /* Start for If: '<S3>/If1' */
  integration_2_DW.If1_ActiveSubsystem_b = -1;

  /* Start for If: '<S9>/If' */
  integration_2_DW.If_ActiveSubsystem_l = -1;

  /* Start for If: '<S45>/If' */
  integration_2_DW.If_ActiveSubsystem_ho = -1;

  /* Start for If: '<S4>/If1' */
  integration_2_DW.If1_ActiveSubsystem_d = -1;

  /* InitializeConditions for Integrator: '<S36>/Integrator2' */
  integration_2_X.Integrator2_CSTATE = integration_2_P.Integrator2_IC;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  integration_2_DW.Delay_DSTATE = integration_2_P.Delay_InitialCondition_fz;

  /* InitializeConditions for Delay: '<S5>/Delay' */
  integration_2_DW.Delay_DSTATE_e = integration_2_P.Delay_InitialCondition_h;

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  integration_2_DW.Delay1_DSTATE = integration_2_P.Delay1_InitialCondition;

  /* InitializeConditions for DiscreteTransferFcn: '<S34>/Discrete Transfer Fcn' */
  integration_2_DW.DiscreteTransferFcn_states =
    integration_2_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for Derivative: '<S36>/Derivative2' */
  integration_2_DW.TimeStampA = (rtInf);
  integration_2_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S40>/Integrator2' */
  integration_2_X.Integrator2_CSTATE_f = integration_2_P.Integrator2_IC_f;

  /* InitializeConditions for DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' */
  integration_2_DW.DiscreteTransferFcn_states_m =
    integration_2_P.DiscreteTransferFcn_InitialSt_i;

  /* InitializeConditions for Derivative: '<S40>/Derivative2' */
  integration_2_DW.TimeStampA_g = (rtInf);
  integration_2_DW.TimeStampB_c = (rtInf);

  /* InitializeConditions for UnitDelay: '<S37>/UD'
   *
   * Block description for '<S37>/UD':
   *
   *  Store in Global RAM
   */
  integration_2_DW.UD_DSTATE = integration_2_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S41>/UD'
   *
   * Block description for '<S41>/UD':
   *
   *  Store in Global RAM
   */
  integration_2_DW.UD_DSTATE_m = integration_2_P.DiscreteDerivative_ICPrevScal_g;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<S15>/SW1'
   */
  /* System initialize for function-call system: '<S15>/SW1' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (integration_2_M->Timing.rtmDbBufWriteBuf4) {
   case 0:
    integration_2_M->Timing.rtmDbBufReadBuf4 = 1;
    break;

   case 1:
    integration_2_M->Timing.rtmDbBufReadBuf4 = 0;
    break;

   default:
    integration_2_M->Timing.rtmDbBufReadBuf4 =
      integration_2_M->Timing.rtmDbBufLastBufWr4;
    break;
  }

  integration_2_M->Timing.clockTick4 =
    integration_2_M->Timing.rtmDbBufClockTick4
    [integration_2_M->Timing.rtmDbBufReadBuf4];
  integration_2_M->Timing.rtmDbBufReadBuf4 = 0xFF;

  /* InitializeConditions for Sum: '<S20>/Sum' incorporates:
   *  Delay: '<S20>/Delay'
   */
  integration_2_DW.Delay_DSTATE_p = integration_2_P.Delay_InitialCondition;

  /* SystemInitialize for Math: '<S20>/Mod' incorporates:
   *  Outport: '<S20>/Output'
   */
  integration_2_B.Mod_b = integration_2_P.Output_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, RISING);

  /* SystemInitialize for IfAction SubSystem: '<S14>/If Action Subsystem1' */
  /* InitializeConditions for Delay: '<S17>/Delay' */
  integration_2_DW.Delay_DSTATE_d = integration_2_P.Delay_InitialCondition_f;

  /* SystemInitialize for Math: '<S17>/Mod' incorporates:
   *  Outport: '<S17>/sw2'
   */
  integration_2_B.Mod_a = integration_2_P.sw2_Y0;

  /* End of SystemInitialize for SubSystem: '<S14>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/If Action Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S22>/In1' incorporates:
   *  Outport: '<S22>/Out1'
   */
  integration_2_B.In1 = integration_2_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S21>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/If Action Subsystem3' */
  /* Start for If: '<S25>/If' */
  integration_2_DW.If_ActiveSubsystem_f = -1;

  /* SystemInitialize for Merge: '<S21>/Merge1' */
  integration_2_B.Merge1 = integration_2_P.Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S21>/Merge' */
  integration_2_B.Merge = integration_2_P.Merge_InitialOutput;

  /* SystemInitialize for IfAction SubSystem: '<S9>/If Action Subsystem' */
  /* InitializeConditions for Delay: '<S42>/Delay' */
  integration_2_DW.Delay_DSTATE_j = integration_2_P.Delay_InitialCondition_p;

  /* SystemInitialize for Math: '<S42>/Mod' incorporates:
   *  Outport: '<S42>/Out1'
   */
  integration_2_B.Mod = integration_2_P.Out1_Y0_c;

  /* End of SystemInitialize for SubSystem: '<S9>/If Action Subsystem' */

  /* SystemInitialize for Merge: '<S45>/Merge' */
  integration_2_B.Merge_a = integration_2_P.Merge_InitialOutput_m;

  /* SystemInitialize for Merge: '<S45>/Merge1' */
  integration_2_B.Merge1_k = integration_2_P.Merge1_InitialOutput_g;

  /* Start for MATLABSystem: '<Root>/Digital Input1' */
  integration_2_DW.obj_i.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_i.SampleTime = integration_2_P.DigitalInput1_SampleTime;
  integration_2_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(31, 0);
  integration_2_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/가변저항' */
  integration_2_DW.obj_k.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_k.SampleTime = integration_2_P._SampleTime;
  integration_2_DW.obj_k.isInitialized = 1L;
  integration_2_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(62UL);
  integration_2_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/전방 초음파1' */
  integration_2_DW.obj_lf.isInitialized = 1L;
  MW_UltrasonicSetup(46, 47);
  integration_2_DW.obj_lf.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<S39>/PWM' */
  integration_2_DW.obj_dm.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_dm.isInitialized = 1L;
  integration_2_DW.obj_dm.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  integration_2_DW.obj_dm.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/PWM' */
  integration_2_DW.obj_ar.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_ar.isInitialized = 1L;
  integration_2_DW.obj_ar.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(3UL, 0.0, 0.0);
  integration_2_DW.obj_ar.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/PWM' */
  integration_2_DW.obj_j.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_j.isInitialized = 1L;
  integration_2_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  integration_2_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/PWM1' */
  integration_2_DW.obj_l.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_l.isInitialized = 1L;
  integration_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
  integration_2_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/PWM2' */
  integration_2_DW.obj_av.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_av.isInitialized = 1L;
  integration_2_DW.obj_av.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
  integration_2_DW.obj_av.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  integration_2_DW.obj_h.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_h.SampleTime = integration_2_P.DigitalInput_SampleTime;
  integration_2_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(36, 0);
  integration_2_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  integration_2_DW.obj_d.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_d.SampleTime = integration_2_P.AnalogInput1_SampleTime;
  integration_2_DW.obj_d.isInitialized = 1L;
  integration_2_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(55UL);
  integration_2_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output' */
  integration_2_DW.obj_e.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(42, 1);
  integration_2_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S45>/Digital Output' */
  integration_2_DW.obj_b.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_b.isInitialized = 1L;
  digitalIOSetup(44, 1);
  integration_2_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S45>/Digital Output1' */
  integration_2_DW.obj_a.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_a.isInitialized = 1L;
  digitalIOSetup(45, 1);
  integration_2_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Digital Output' */
  integration_2_DW.obj_bz.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_bz.isInitialized = 1L;
  digitalIOSetup(43, 1);
  integration_2_DW.obj_bz.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM1' */
  integration_2_DW.obj_i2.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_i2.isInitialized = 1L;
  integration_2_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  integration_2_DW.obj_i2.isSetupComplete = true;

  /* Start for MATLABSystem: '<S34>/Encoder' */
  integration_2_DW.obj_p.Index = 0U;
  integration_2_DW.obj_p.matlabCodegenIsDeleted = false;
  integration_2_DW.obj_p.SampleTime = integration_2_P.Encoder_SampleTime;
  integration_2_DW.obj_p.isInitialized = 1L;
  MW_EncoderSetup(20UL, 21UL, &integration_2_DW.obj_p.Index);
  integration_2_DW.obj_p.isSetupComplete = true;
  integration_2_DW.obj_p.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S34>/Encoder' */
  MW_EncoderReset(integration_2_DW.obj_p.Index);

  /* Start for MATLABSystem: '<S38>/Encoder' */
  integration_2_DW.obj.Index = 0U;
  integration_2_DW.obj.matlabCodegenIsDeleted = false;
  integration_2_DW.obj.SampleTime = integration_2_P.Encoder_SampleTime_e;
  integration_2_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &integration_2_DW.obj.Index);
  integration_2_DW.obj.isSetupComplete = true;
  integration_2_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S38>/Encoder' */
  MW_EncoderReset(integration_2_DW.obj.Index);
}

/* Model terminate function */
void integration_2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  if (!integration_2_DW.obj_i.matlabCodegenIsDeleted) {
    integration_2_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input1' */

  /* Terminate for MATLABSystem: '<Root>/가변저항' */
  if (!integration_2_DW.obj_k.matlabCodegenIsDeleted) {
    integration_2_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((integration_2_DW.obj_k.isInitialized == 1L) &&
        integration_2_DW.obj_k.isSetupComplete) {
      integration_2_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close
        (integration_2_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/가변저항' */
  /* Terminate for MATLABSystem: '<S39>/PWM' */
  if (!integration_2_DW.obj_dm.matlabCodegenIsDeleted) {
    integration_2_DW.obj_dm.matlabCodegenIsDeleted = true;
    if ((integration_2_DW.obj_dm.isInitialized == 1L) &&
        integration_2_DW.obj_dm.isSetupComplete) {
      integration_2_DW.obj_dm.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(integration_2_DW.obj_dm.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      integration_2_DW.obj_dm.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(integration_2_DW.obj_dm.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S39>/PWM' */
  /* Terminate for MATLABSystem: '<S35>/PWM' */
  if (!integration_2_DW.obj_ar.matlabCodegenIsDeleted) {
    integration_2_DW.obj_ar.matlabCodegenIsDeleted = true;
    if ((integration_2_DW.obj_ar.isInitialized == 1L) &&
        integration_2_DW.obj_ar.isSetupComplete) {
      integration_2_DW.obj_ar.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
      MW_PWM_SetDutyCycle(integration_2_DW.obj_ar.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      integration_2_DW.obj_ar.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
      MW_PWM_Close(integration_2_DW.obj_ar.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/PWM' */
  /* Terminate for MATLABSystem: '<S6>/PWM' */
  if (!integration_2_DW.obj_j.matlabCodegenIsDeleted) {
    integration_2_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((integration_2_DW.obj_j.isInitialized == 1L) &&
        integration_2_DW.obj_j.isSetupComplete) {
      integration_2_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(integration_2_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      integration_2_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(integration_2_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM' */

  /* Terminate for MATLABSystem: '<S6>/PWM1' */
  if (!integration_2_DW.obj_l.matlabCodegenIsDeleted) {
    integration_2_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((integration_2_DW.obj_l.isInitialized == 1L) &&
        integration_2_DW.obj_l.isSetupComplete) {
      integration_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(integration_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      integration_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(integration_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM1' */

  /* Terminate for MATLABSystem: '<S6>/PWM2' */
  if (!integration_2_DW.obj_av.matlabCodegenIsDeleted) {
    integration_2_DW.obj_av.matlabCodegenIsDeleted = true;
    if ((integration_2_DW.obj_av.isInitialized == 1L) &&
        integration_2_DW.obj_av.isSetupComplete) {
      integration_2_DW.obj_av.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle(integration_2_DW.obj_av.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      integration_2_DW.obj_av.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(integration_2_DW.obj_av.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM2' */
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!integration_2_DW.obj_h.matlabCodegenIsDeleted) {
    integration_2_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!integration_2_DW.obj_d.matlabCodegenIsDeleted) {
    integration_2_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((integration_2_DW.obj_d.isInitialized == 1L) &&
        integration_2_DW.obj_d.isSetupComplete) {
      integration_2_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(55UL);
      MW_AnalogIn_Close
        (integration_2_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */
  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!integration_2_DW.obj_e.matlabCodegenIsDeleted) {
    integration_2_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */

  /* Terminate for MATLABSystem: '<S45>/Digital Output' */
  if (!integration_2_DW.obj_b.matlabCodegenIsDeleted) {
    integration_2_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S45>/Digital Output' */

  /* Terminate for MATLABSystem: '<S45>/Digital Output1' */
  if (!integration_2_DW.obj_a.matlabCodegenIsDeleted) {
    integration_2_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S45>/Digital Output1' */
  /* Terminate for MATLABSystem: '<S3>/Digital Output' */
  if (!integration_2_DW.obj_bz.matlabCodegenIsDeleted) {
    integration_2_DW.obj_bz.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output' */
  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  if (!integration_2_DW.obj_i2.matlabCodegenIsDeleted) {
    integration_2_DW.obj_i2.matlabCodegenIsDeleted = true;
    if ((integration_2_DW.obj_i2.isInitialized == 1L) &&
        integration_2_DW.obj_i2.isSetupComplete) {
      integration_2_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(integration_2_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      integration_2_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(integration_2_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */

  /* Terminate for MATLABSystem: '<S34>/Encoder' */
  if (!integration_2_DW.obj_p.matlabCodegenIsDeleted) {
    integration_2_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((integration_2_DW.obj_p.isInitialized == 1L) &&
        integration_2_DW.obj_p.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S34>/Encoder' */
  /* Terminate for MATLABSystem: '<S38>/Encoder' */
  if (!integration_2_DW.obj.matlabCodegenIsDeleted) {
    integration_2_DW.obj.matlabCodegenIsDeleted = true;
    if ((integration_2_DW.obj.isInitialized == 1L) &&
        integration_2_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
