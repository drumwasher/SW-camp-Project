/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: team_project_state_and_cds_adj_integration.c
 *
 * Code generated for Simulink model 'team_project_state_and_cds_adj_integration'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Feb 13 17:19:22 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "team_project_state_and_cds_adj_integration.h"
#include "rtwtypes.h"
#include "team_project_state_and_cds_adj_integration_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "multiword_types.h"
#include <float.h>

/* Named constants for Chart: '<S6>/Chart' */
#define team_project_state__IN_adas_off (1UL)
#define team_project_state_a_IN_adas_on (2UL)

/* Named constants for Chart: '<S5>/Chart' */
#define team_project_state_IN_Drive_off (1UL)
#define team_project_state__IN_Drive_on (2UL)

/* Named constants for Chart: '<S2>/Chart' */
#define team_p_IN_drive_on_adas_on_LRUS (5UL)
#define team_pr_IN_drive_on_adas_on_FUS (4UL)
#define team_pr_IN_drive_on_adas_on_LUS (6UL)
#define team_pr_IN_drive_on_adas_on_RUS (7UL)
#define team_proje_IN_drive_on_adas_off (2UL)
#define team_projec_IN_drive_on_adas_on (3UL)
#define team_project_state_IN_drive_off (1UL)

/* Named constants for Chart: '<S2>/Chart1' */
#define team_project_sta_IN_adas_on_BUS (3UL)

/* Block signals (default storage) */
B_team_project_state_and_cds__T team_project_state_and_cds_ad_B;

/* Continuous states */
X_team_project_state_and_cds__T team_project_state_and_cds_ad_X;

/* Disabled State Vector */
XDis_team_project_state_and_c_T team_project_state_and_cds_XDis;

/* Block states (default storage) */
DW_team_project_state_and_cds_T team_project_state_and_cds_a_DW;

/* Real-time model */
static RT_MODEL_team_project_state_a_T team_project_state_and_cds_a_M_;
RT_MODEL_team_project_state_a_T *const team_project_state_and_cds_a_M =
  &team_project_state_and_cds_a_M_;
static void rate_monotonic_scheduler(void);
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
  /* Call the system: <S5>/SW1 */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(team_project_state_and_cds_a_DW.SW1_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<S5>/SW1' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (team_project_state_and_cds_a_M->Timing.rtmDbBufWriteBuf4) {
     case 0:
      team_project_state_and_cds_a_M->Timing.rtmDbBufReadBuf4 = 1;
      break;

     case 1:
      team_project_state_and_cds_a_M->Timing.rtmDbBufReadBuf4 = 0;
      break;

     default:
      team_project_state_and_cds_a_M->Timing.rtmDbBufReadBuf4 =
        team_project_state_and_cds_a_M->Timing.rtmDbBufLastBufWr4;
      break;
    }

    team_project_state_and_cds_a_M->Timing.clockTick4 =
      team_project_state_and_cds_a_M->
      Timing.rtmDbBufClockTick4
      [team_project_state_and_cds_a_M->Timing.rtmDbBufReadBuf4];
    team_project_state_and_cds_a_M->Timing.rtmDbBufReadBuf4 = 0xFF;

    /* Sum: '<S10>/Sum' incorporates:
     *  Constant: '<S10>/Constant'
     *  Delay: '<S10>/Delay'
     */
    team_project_state_and_cds_a_DW.Delay_DSTATE_p +=
      team_project_state_and_cds_ad_P.Constant_Value;

    /* Math: '<S10>/Mod' incorporates:
     *  Constant: '<S10>/Constant1'
     */
    team_project_state_and_cds_ad_B.Mod = rt_modd_snf
      (team_project_state_and_cds_a_DW.Delay_DSTATE_p,
       team_project_state_and_cds_ad_P.Constant1_Value);
    team_project_state_and_cds_a_DW.SW1_SubsysRanBC = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
  }

  extmodeEvent(4,((team_project_state_and_cds_a_M->Timing.clockTick4) * 0.01));
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void team_project_state_and_cds_adj_integration_SetEventsForThisBaseStep
  (boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(team_project_state_and_cds_a_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(team_project_state_and_cds_a_M, 3));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 3 */
  if (team_project_state_and_cds_a_M->Timing.TaskCounters.TID[1] == 0) {
    team_project_state_and_cds_a_M->Timing.RateInteraction.TID1_3 =
      (team_project_state_and_cds_a_M->Timing.TaskCounters.TID[3] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (team_project_state_and_cds_a_M->Timing.TaskCounters.TID[2])++;
  if ((team_project_state_and_cds_a_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    team_project_state_and_cds_a_M->Timing.TaskCounters.TID[2] = 0;
  }

  (team_project_state_and_cds_a_M->Timing.TaskCounters.TID[3])++;
  if ((team_project_state_and_cds_a_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.2s, 0.0s] */
    team_project_state_and_cds_a_M->Timing.TaskCounters.TID[3] = 0;
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
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  team_project_state_and_cds_adj_integration_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  team_project_state_and_cds_adj_integration_step0();
  team_project_state_and_cds_adj_integration_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  team_project_state_and_cds_adj_integration_step0();
  team_project_state_and_cds_adj_integration_derivatives();

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

/* Model step function for TID0 */
void team_project_state_and_cds_adj_integration_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  int32_T rtb_TSamp;
  if (rtmIsMajorTimeStep(team_project_state_and_cds_a_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&team_project_state_and_cds_a_M->solverInfo,
                          ((team_project_state_and_cds_a_M->Timing.clockTick0+1)*
      team_project_state_and_cds_a_M->Timing.stepSize0));

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(team_project_state_and_cds_a_M)) {
    team_project_state_and_cds_a_M->Timing.t[0] = rtsiGetT
      (&team_project_state_and_cds_a_M->solverInfo);
  }

  {
    int128m_T tmp_3;
    real_T rtb_Add1;
    real_T tmp_0;
    int32_T tmp;
    uint32_T tmp_1;
    uint32_T tmp_2;
    uint16_T b_varargout_1;
    int8_T rtAction;
    static const int64m_T tmp_4 = { { 0UL, 0UL }/* chunks */
    };

    static const int64m_T tmp_5 = { { 25UL, 0UL }/* chunks */
    };

    /* Reset subsysRan breadcrumbs */
    srClearBC(team_project_state_and_cds_a_DW.IfActionSubsystem_SubsysRanBC);
    if (rtmIsMajorTimeStep(team_project_state_and_cds_a_M)) {
      /* MATLABSystem: '<Root>/Analog Input1' */
      if (team_project_state_and_cds_a_DW.obj_d.SampleTime !=
          team_project_state_and_cds_ad_P.AnalogInput1_SampleTime) {
        team_project_state_and_cds_a_DW.obj_d.SampleTime =
          team_project_state_and_cds_ad_P.AnalogInput1_SampleTime;
      }

      team_project_state_and_cds_a_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(55UL);
      MW_AnalogInSingle_ReadResult
        (team_project_state_and_cds_a_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
         &b_varargout_1, MW_ANALOGIN_UINT16);

      /* End of MATLABSystem: '<Root>/Analog Input1' */

      /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
      if (rtmIsMajorTimeStep(team_project_state_and_cds_a_M)) {
      }

      /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

      /* RateTransition: '<S5>/Rate Transition' */
      team_project_state_and_cds_ad_B.RateTransition =
        team_project_state_and_cds_ad_B.Mod;

      /* Delay: '<Root>/Delay' */
      team_project_state_and_cds_ad_B.Delay =
        team_project_state_and_cds_a_DW.Delay_DSTATE;

      /* Delay: '<S1>/Delay' */
      team_project_state_and_cds_ad_B.Delay_h =
        team_project_state_and_cds_a_DW.Delay_DSTATE_e;

      /* Chart: '<S5>/Chart' */
      if (team_project_state_and_cds_a_DW.is_active_c3_team_project_state == 0U)
      {
        team_project_state_and_cds_a_DW.is_active_c3_team_project_state = 1U;
        team_project_state_and_cds_a_DW.is_c3_team_project_state_and_cd =
          team_project_state_IN_Drive_off;
        team_project_state_and_cds_ad_B.drive_mode = 0.0;
        team_project_state_and_cds_a_DW.state_1 =
          team_project_state_and_cds_ad_B.RateTransition;
      } else if (team_project_state_and_cds_a_DW.is_c3_team_project_state_and_cd
                 == team_project_state_IN_Drive_off) {
        if (team_project_state_and_cds_a_DW.state_1 !=
            team_project_state_and_cds_ad_B.RateTransition) {
          team_project_state_and_cds_a_DW.is_c3_team_project_state_and_cd =
            team_project_state__IN_Drive_on;
          team_project_state_and_cds_ad_B.drive_mode = 1.0;
          team_project_state_and_cds_a_DW.state_1 =
            team_project_state_and_cds_ad_B.RateTransition;
          team_project_state_and_cds_a_DW.ADAS_state =
            team_project_state_and_cds_ad_B.Delay_h;
          team_project_state_and_cds_a_DW.Light_state =
            team_project_state_and_cds_ad_B.Delay;
        } else {
          team_project_state_and_cds_ad_B.drive_mode = 0.0;
          team_project_state_and_cds_a_DW.state_1 =
            team_project_state_and_cds_ad_B.RateTransition;
        }

        /* case IN_Drive_on: */
      } else if ((team_project_state_and_cds_a_DW.state_1 !=
                  team_project_state_and_cds_ad_B.RateTransition) &&
                 (team_project_state_and_cds_a_DW.ADAS_state == 0.0) &&
                 (team_project_state_and_cds_a_DW.Light_state == 0.0)) {
        team_project_state_and_cds_a_DW.is_c3_team_project_state_and_cd =
          team_project_state_IN_Drive_off;
        team_project_state_and_cds_ad_B.drive_mode = 0.0;
        team_project_state_and_cds_a_DW.state_1 =
          team_project_state_and_cds_ad_B.RateTransition;
      } else {
        team_project_state_and_cds_ad_B.drive_mode = 1.0;
        team_project_state_and_cds_a_DW.state_1 =
          team_project_state_and_cds_ad_B.RateTransition;
        team_project_state_and_cds_a_DW.ADAS_state =
          team_project_state_and_cds_ad_B.Delay_h;
        team_project_state_and_cds_a_DW.Light_state =
          team_project_state_and_cds_ad_B.Delay;
      }

      /* End of Chart: '<S5>/Chart' */

      /* RateTransition generated from: '<S4>/If Action Subsystem1' */
      if (team_project_state_and_cds_a_M->Timing.RateInteraction.TID1_3) {
        /* RateTransition generated from: '<S4>/If Action Subsystem1' */
        team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo =
          team_project_state_and_cds_a_DW.TmpRTBAtIfActionSubsystem1Outpo;
      }

      /* End of RateTransition generated from: '<S4>/If Action Subsystem1' */

      /* If: '<S1>/If' */
      rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&team_project_state_and_cds_a_M->solverInfo))
      {
        if (team_project_state_and_cds_ad_B.drive_mode == 1.0) {
          rtAction = 0;
        }

        team_project_state_and_cds_a_DW.If_ActiveSubsystem = rtAction;
      } else {
        rtAction = team_project_state_and_cds_a_DW.If_ActiveSubsystem;
      }

      if (rtAction == 0) {
        /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
         *  ActionPort: '<S6>/Action Port'
         */
        /* Chart: '<S6>/Chart' */
        if (team_project_state_and_cds_a_DW.is_active_c1_team_project_state ==
            0U) {
          team_project_state_and_cds_a_DW.is_active_c1_team_project_state = 1U;
          team_project_state_and_cds_a_DW.is_c1_team_project_state_and_cd =
            team_project_state__IN_adas_off;
          team_project_state_and_cds_ad_B.ADAS_state =
            team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo;
          team_project_state_and_cds_a_DW.state_2 =
            team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo;
        } else if
            (team_project_state_and_cds_a_DW.is_c1_team_project_state_and_cd ==
             team_project_state__IN_adas_off) {
          if (team_project_state_and_cds_a_DW.state_2 !=
              team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo) {
            team_project_state_and_cds_a_DW.is_c1_team_project_state_and_cd =
              team_project_state_a_IN_adas_on;
            team_project_state_and_cds_ad_B.ADAS_state =
              team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo;
            team_project_state_and_cds_a_DW.state_2 =
              team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo;
          } else {
            team_project_state_and_cds_ad_B.ADAS_state =
              team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo;
            team_project_state_and_cds_a_DW.state_2 =
              team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo;
          }

          /* case IN_adas_on: */
        } else if (team_project_state_and_cds_a_DW.state_2 !=
                   team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo)
        {
          team_project_state_and_cds_a_DW.is_c1_team_project_state_and_cd =
            team_project_state__IN_adas_off;
          team_project_state_and_cds_ad_B.ADAS_state =
            team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo;
          team_project_state_and_cds_a_DW.state_2 =
            team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo;
        } else {
          team_project_state_and_cds_ad_B.ADAS_state =
            team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo;
          team_project_state_and_cds_a_DW.state_2 =
            team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo;
        }

        /* End of Chart: '<S6>/Chart' */
        if (rtsiIsModeUpdateTimeStep(&team_project_state_and_cds_a_M->solverInfo))
        {
          srUpdateBC
            (team_project_state_and_cds_a_DW.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
      }

      /* End of If: '<S1>/If' */

      /* Constant: '<Root>/Constant' */
      team_project_state_and_cds_ad_B.Constant =
        team_project_state_and_cds_ad_P.f;

      /* Constant: '<Root>/Constant3' */
      team_project_state_and_cds_ad_B.Constant3 =
        team_project_state_and_cds_ad_P.l;

      /* Constant: '<Root>/Constant1' */
      team_project_state_and_cds_ad_B.Constant1 =
        team_project_state_and_cds_ad_P.r;
    }

    /* MATLABSystem: '<Root>/��������' */
    if (team_project_state_and_cds_a_DW.obj_k.SampleTime !=
        team_project_state_and_cds_ad_P._SampleTime) {
      team_project_state_and_cds_a_DW.obj_k.SampleTime =
        team_project_state_and_cds_ad_P._SampleTime;
    }

    team_project_state_and_cds_a_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
      MW_AnalogIn_GetHandle(62UL);
    MW_AnalogInSingle_ReadResult
      (team_project_state_and_cds_a_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
       &b_varargout_1, MW_ANALOGIN_UINT16);

    /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
     *  Gain: '<S2>/Gain'
     *  MATLABSystem: '<Root>/��������'
     * */
    team_project_state_and_cds_ad_B.DataTypeConversion = (real_T)((uint32_T)
      team_project_state_and_cds_ad_P.Gain_Gain * b_varargout_1) *
      7.62939453125E-6;
    if (rtmIsMajorTimeStep(team_project_state_and_cds_a_M)) {
      /* Chart: '<S2>/Chart' */
      if (team_project_state_and_cds_a_DW.is_active_c2_team_project_state == 0U)
      {
        team_project_state_and_cds_a_DW.is_active_c2_team_project_state = 1U;
        team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
          team_project_state_IN_drive_off;
        team_project_state_and_cds_ad_B.out1 = 0.0;
        team_project_state_and_cds_ad_B.out2 = 0.0;
        team_project_state_and_cds_a_DW.steering = 0.02;
        team_project_state_and_cds_a_DW.default_g = 360.0;
      } else {
        switch (team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd)
        {
         case team_project_state_IN_drive_off:
          if (team_project_state_and_cds_ad_B.drive_mode == 1.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_proje_IN_drive_on_adas_off;
            team_project_state_and_cds_ad_B.out1 =
              ((team_project_state_and_cds_ad_B.DataTypeConversion - 128.0) /
               6.4 / 100.0 + 1.0) * team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = ((128.0 -
              team_project_state_and_cds_ad_B.DataTypeConversion) / 6.4 / 100.0
              + 1.0) * team_project_state_and_cds_a_DW.default_g;
          } else {
            team_project_state_and_cds_ad_B.out1 = 0.0;
            team_project_state_and_cds_ad_B.out2 = 0.0;
            team_project_state_and_cds_a_DW.steering = 0.02;
            team_project_state_and_cds_a_DW.default_g = 360.0;
          }
          break;

         case team_proje_IN_drive_on_adas_off:
          if (team_project_state_and_cds_ad_B.drive_mode == 0.0) {
            team_project_state_and_cds_ad_B.buzzer = 0.0;
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_project_state_IN_drive_off;
            team_project_state_and_cds_ad_B.out1 = 0.0;
            team_project_state_and_cds_ad_B.out2 = 0.0;
            team_project_state_and_cds_a_DW.steering = 0.02;
            team_project_state_and_cds_a_DW.default_g = 360.0;
          } else if (team_project_state_and_cds_ad_B.ADAS_state == 1.0) {
            team_project_state_and_cds_ad_B.buzzer = 0.0;
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_projec_IN_drive_on_adas_on;
            team_project_state_and_cds_ad_B.out1 =
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 =
              team_project_state_and_cds_a_DW.default_g;
          } else {
            team_project_state_and_cds_ad_B.out1 =
              ((team_project_state_and_cds_ad_B.DataTypeConversion - 128.0) /
               6.4 / 100.0 + 1.0) * team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = ((128.0 -
              team_project_state_and_cds_ad_B.DataTypeConversion) / 6.4 / 100.0
              + 1.0) * team_project_state_and_cds_a_DW.default_g;
          }
          break;

         case team_projec_IN_drive_on_adas_on:
          if (team_project_state_and_cds_ad_B.ADAS_state == 0.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_proje_IN_drive_on_adas_off;
            team_project_state_and_cds_ad_B.out1 =
              ((team_project_state_and_cds_ad_B.DataTypeConversion - 128.0) /
               6.4 / 100.0 + 1.0) * team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = ((128.0 -
              team_project_state_and_cds_ad_B.DataTypeConversion) / 6.4 / 100.0
              + 1.0) * team_project_state_and_cds_a_DW.default_g;
          } else if (team_project_state_and_cds_ad_B.Constant <= 10.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_pr_IN_drive_on_adas_on_FUS;
            team_project_state_and_cds_ad_B.out1 = 0.0;
            team_project_state_and_cds_ad_B.out2 = 0.0;
            team_project_state_and_cds_ad_B.buzzer = 1.0;
          } else if (team_project_state_and_cds_ad_B.Constant1 <= 10.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_pr_IN_drive_on_adas_on_RUS;
            team_project_state_and_cds_ad_B.out1 = (1.0 - (10.0 -
              team_project_state_and_cds_ad_B.Constant1) *
              team_project_state_and_cds_a_DW.steering) *
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = ((10.0 -
              team_project_state_and_cds_ad_B.Constant1) *
              team_project_state_and_cds_a_DW.steering + 1.0) *
              team_project_state_and_cds_a_DW.default_g;
          } else if (team_project_state_and_cds_ad_B.Constant3 <= 10.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_pr_IN_drive_on_adas_on_LUS;
            team_project_state_and_cds_ad_B.out1 = ((10.0 -
              team_project_state_and_cds_ad_B.Constant3) *
              team_project_state_and_cds_a_DW.steering + 1.0) *
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = (1.0 - (10.0 -
              team_project_state_and_cds_ad_B.Constant3) *
              team_project_state_and_cds_a_DW.steering) *
              team_project_state_and_cds_a_DW.default_g;
          } else {
            team_project_state_and_cds_ad_B.out1 =
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 =
              team_project_state_and_cds_a_DW.default_g;
          }
          break;

         case team_pr_IN_drive_on_adas_on_FUS:
          if ((team_project_state_and_cds_ad_B.Constant3 > 10.0) &&
              (team_project_state_and_cds_ad_B.Constant1 > 10.0) &&
              (team_project_state_and_cds_ad_B.Constant > 10.0)) {
            team_project_state_and_cds_ad_B.buzzer = 0.0;
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_projec_IN_drive_on_adas_on;
            team_project_state_and_cds_ad_B.out1 =
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 =
              team_project_state_and_cds_a_DW.default_g;
          } else if ((team_project_state_and_cds_ad_B.Constant3 <= 10.0) &&
                     (team_project_state_and_cds_ad_B.Constant1 <= 10.0) &&
                     (team_project_state_and_cds_ad_B.Constant > 10.0)) {
            team_project_state_and_cds_ad_B.buzzer = 0.0;
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_p_IN_drive_on_adas_on_LRUS;
            rtb_Add1 = team_project_state_and_cds_ad_B.Constant3 -
              team_project_state_and_cds_ad_B.Constant1;
            team_project_state_and_cds_ad_B.out1 = (1.0 - rtb_Add1 *
              team_project_state_and_cds_a_DW.steering) *
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = (rtb_Add1 *
              team_project_state_and_cds_a_DW.steering + 1.0) *
              team_project_state_and_cds_a_DW.default_g;
          } else if ((team_project_state_and_cds_ad_B.Constant1 <= 10.0) &&
                     (team_project_state_and_cds_ad_B.Constant > 10.0)) {
            team_project_state_and_cds_ad_B.buzzer = 0.0;
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_pr_IN_drive_on_adas_on_RUS;
            team_project_state_and_cds_ad_B.out1 = (1.0 - (10.0 -
              team_project_state_and_cds_ad_B.Constant1) *
              team_project_state_and_cds_a_DW.steering) *
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = ((10.0 -
              team_project_state_and_cds_ad_B.Constant1) *
              team_project_state_and_cds_a_DW.steering + 1.0) *
              team_project_state_and_cds_a_DW.default_g;
          } else if ((team_project_state_and_cds_ad_B.Constant3 <= 10.0) &&
                     (team_project_state_and_cds_ad_B.Constant > 10.0)) {
            team_project_state_and_cds_ad_B.buzzer = 0.0;
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_pr_IN_drive_on_adas_on_LUS;
            team_project_state_and_cds_ad_B.out1 = ((10.0 -
              team_project_state_and_cds_ad_B.Constant3) *
              team_project_state_and_cds_a_DW.steering + 1.0) *
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = (1.0 - (10.0 -
              team_project_state_and_cds_ad_B.Constant3) *
              team_project_state_and_cds_a_DW.steering) *
              team_project_state_and_cds_a_DW.default_g;
          } else if (team_project_state_and_cds_ad_B.ADAS_state == 0.0) {
            team_project_state_and_cds_ad_B.buzzer = 0.0;
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_proje_IN_drive_on_adas_off;
            team_project_state_and_cds_ad_B.out1 =
              ((team_project_state_and_cds_ad_B.DataTypeConversion - 128.0) /
               6.4 / 100.0 + 1.0) * team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = ((128.0 -
              team_project_state_and_cds_ad_B.DataTypeConversion) / 6.4 / 100.0
              + 1.0) * team_project_state_and_cds_a_DW.default_g;
          } else {
            team_project_state_and_cds_ad_B.out1 = 0.0;
            team_project_state_and_cds_ad_B.out2 = 0.0;
            team_project_state_and_cds_ad_B.buzzer = 1.0;
          }
          break;

         case team_p_IN_drive_on_adas_on_LRUS:
          if (team_project_state_and_cds_ad_B.Constant <= 10.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_pr_IN_drive_on_adas_on_FUS;
            team_project_state_and_cds_ad_B.out1 = 0.0;
            team_project_state_and_cds_ad_B.out2 = 0.0;
            team_project_state_and_cds_ad_B.buzzer = 1.0;
          } else if (team_project_state_and_cds_ad_B.Constant1 > 10.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_pr_IN_drive_on_adas_on_LUS;
            team_project_state_and_cds_ad_B.out1 = ((10.0 -
              team_project_state_and_cds_ad_B.Constant3) *
              team_project_state_and_cds_a_DW.steering + 1.0) *
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = (1.0 - (10.0 -
              team_project_state_and_cds_ad_B.Constant3) *
              team_project_state_and_cds_a_DW.steering) *
              team_project_state_and_cds_a_DW.default_g;
          } else if (team_project_state_and_cds_ad_B.Constant3 > 10.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_pr_IN_drive_on_adas_on_RUS;
            team_project_state_and_cds_ad_B.out1 = (1.0 - (10.0 -
              team_project_state_and_cds_ad_B.Constant1) *
              team_project_state_and_cds_a_DW.steering) *
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = ((10.0 -
              team_project_state_and_cds_ad_B.Constant1) *
              team_project_state_and_cds_a_DW.steering + 1.0) *
              team_project_state_and_cds_a_DW.default_g;
          } else if (team_project_state_and_cds_ad_B.ADAS_state == 0.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_proje_IN_drive_on_adas_off;
            team_project_state_and_cds_ad_B.out1 =
              ((team_project_state_and_cds_ad_B.DataTypeConversion - 128.0) /
               6.4 / 100.0 + 1.0) * team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = ((128.0 -
              team_project_state_and_cds_ad_B.DataTypeConversion) / 6.4 / 100.0
              + 1.0) * team_project_state_and_cds_a_DW.default_g;
          } else {
            team_project_state_and_cds_ad_B.out1 = (1.0 -
              (team_project_state_and_cds_ad_B.Constant3 -
               team_project_state_and_cds_ad_B.Constant1) *
              team_project_state_and_cds_a_DW.steering) *
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 =
              ((team_project_state_and_cds_ad_B.Constant3 -
                team_project_state_and_cds_ad_B.Constant1) *
               team_project_state_and_cds_a_DW.steering + 1.0) *
              team_project_state_and_cds_a_DW.default_g;
          }
          break;

         case team_pr_IN_drive_on_adas_on_LUS:
          if (team_project_state_and_cds_ad_B.Constant3 > 10.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_projec_IN_drive_on_adas_on;
            team_project_state_and_cds_ad_B.out1 =
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 =
              team_project_state_and_cds_a_DW.default_g;
          } else if (team_project_state_and_cds_ad_B.Constant1 <= 10.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_p_IN_drive_on_adas_on_LRUS;
            team_project_state_and_cds_ad_B.out1 = (1.0 -
              (team_project_state_and_cds_ad_B.Constant3 -
               team_project_state_and_cds_ad_B.Constant1) *
              team_project_state_and_cds_a_DW.steering) *
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 =
              ((team_project_state_and_cds_ad_B.Constant3 -
                team_project_state_and_cds_ad_B.Constant1) *
               team_project_state_and_cds_a_DW.steering + 1.0) *
              team_project_state_and_cds_a_DW.default_g;
          } else if (team_project_state_and_cds_ad_B.Constant <= 10.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_pr_IN_drive_on_adas_on_FUS;
            team_project_state_and_cds_ad_B.out1 = 0.0;
            team_project_state_and_cds_ad_B.out2 = 0.0;
            team_project_state_and_cds_ad_B.buzzer = 1.0;
          } else if (team_project_state_and_cds_ad_B.ADAS_state == 0.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_proje_IN_drive_on_adas_off;
            team_project_state_and_cds_ad_B.out1 =
              ((team_project_state_and_cds_ad_B.DataTypeConversion - 128.0) /
               6.4 / 100.0 + 1.0) * team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = ((128.0 -
              team_project_state_and_cds_ad_B.DataTypeConversion) / 6.4 / 100.0
              + 1.0) * team_project_state_and_cds_a_DW.default_g;
          } else {
            team_project_state_and_cds_ad_B.out1 = ((10.0 -
              team_project_state_and_cds_ad_B.Constant3) *
              team_project_state_and_cds_a_DW.steering + 1.0) *
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = (1.0 - (10.0 -
              team_project_state_and_cds_ad_B.Constant3) *
              team_project_state_and_cds_a_DW.steering) *
              team_project_state_and_cds_a_DW.default_g;
          }
          break;

         default:
          /* case IN_drive_on_adas_on_RUS: */
          if (team_project_state_and_cds_ad_B.Constant1 > 10.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_projec_IN_drive_on_adas_on;
            team_project_state_and_cds_ad_B.out1 =
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 =
              team_project_state_and_cds_a_DW.default_g;
          } else if (team_project_state_and_cds_ad_B.Constant <= 10.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_pr_IN_drive_on_adas_on_FUS;
            team_project_state_and_cds_ad_B.out1 = 0.0;
            team_project_state_and_cds_ad_B.out2 = 0.0;
            team_project_state_and_cds_ad_B.buzzer = 1.0;
          } else if (team_project_state_and_cds_ad_B.Constant3 <= 10.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_p_IN_drive_on_adas_on_LRUS;
            team_project_state_and_cds_ad_B.out1 = (1.0 -
              (team_project_state_and_cds_ad_B.Constant3 -
               team_project_state_and_cds_ad_B.Constant1) *
              team_project_state_and_cds_a_DW.steering) *
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 =
              ((team_project_state_and_cds_ad_B.Constant3 -
                team_project_state_and_cds_ad_B.Constant1) *
               team_project_state_and_cds_a_DW.steering + 1.0) *
              team_project_state_and_cds_a_DW.default_g;
          } else if (team_project_state_and_cds_ad_B.ADAS_state == 0.0) {
            team_project_state_and_cds_a_DW.is_c2_team_project_state_and_cd =
              team_proje_IN_drive_on_adas_off;
            team_project_state_and_cds_ad_B.out1 =
              ((team_project_state_and_cds_ad_B.DataTypeConversion - 128.0) /
               6.4 / 100.0 + 1.0) * team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = ((128.0 -
              team_project_state_and_cds_ad_B.DataTypeConversion) / 6.4 / 100.0
              + 1.0) * team_project_state_and_cds_a_DW.default_g;
          } else {
            team_project_state_and_cds_ad_B.out1 = (1.0 - (10.0 -
              team_project_state_and_cds_ad_B.Constant1) *
              team_project_state_and_cds_a_DW.steering) *
              team_project_state_and_cds_a_DW.default_g;
            team_project_state_and_cds_ad_B.out2 = ((10.0 -
              team_project_state_and_cds_ad_B.Constant1) *
              team_project_state_and_cds_a_DW.steering + 1.0) *
              team_project_state_and_cds_a_DW.default_g;
          }
          break;
        }
      }

      /* End of Chart: '<S2>/Chart' */

      /* Constant: '<Root>/Constant2' */
      team_project_state_and_cds_ad_B.Constant2 =
        team_project_state_and_cds_ad_P.b;

      /* Chart: '<S2>/Chart1' */
      if (team_project_state_and_cds_a_DW.is_active_c5_team_project_state == 0U)
      {
        team_project_state_and_cds_a_DW.is_active_c5_team_project_state = 1U;
        team_project_state_and_cds_a_DW.is_c5_team_project_state_and_cd =
          team_project_state__IN_adas_off;
        team_project_state_and_cds_ad_B.rout1 =
          team_project_state_and_cds_ad_B.out1;
      } else {
        switch (team_project_state_and_cds_a_DW.is_c5_team_project_state_and_cd)
        {
         case team_project_state__IN_adas_off:
          if (team_project_state_and_cds_ad_B.ADAS_state == 1.0) {
            team_project_state_and_cds_a_DW.is_c5_team_project_state_and_cd =
              team_project_state_a_IN_adas_on;
            team_project_state_and_cds_ad_B.rout1 =
              team_project_state_and_cds_ad_B.out1;
          } else {
            team_project_state_and_cds_ad_B.rout1 =
              team_project_state_and_cds_ad_B.out1;
          }
          break;

         case team_project_state_a_IN_adas_on:
          if (team_project_state_and_cds_ad_B.ADAS_state == 0.0) {
            team_project_state_and_cds_a_DW.is_c5_team_project_state_and_cd =
              team_project_state__IN_adas_off;
            team_project_state_and_cds_ad_B.rout1 =
              team_project_state_and_cds_ad_B.out1;
          } else if (team_project_state_and_cds_ad_B.Constant2 <= 10.0) {
            team_project_state_and_cds_a_DW.is_c5_team_project_state_and_cd =
              team_project_sta_IN_adas_on_BUS;
            team_project_state_and_cds_ad_B.rout1 =
              team_project_state_and_cds_ad_B.out1 * 1.2;
          } else {
            team_project_state_and_cds_ad_B.rout1 =
              team_project_state_and_cds_ad_B.out1;
          }
          break;

         default:
          /* case IN_adas_on_BUS: */
          if (team_project_state_and_cds_ad_B.Constant2 > 10.0) {
            team_project_state_and_cds_a_DW.is_c5_team_project_state_and_cd =
              team_project_state_a_IN_adas_on;
            team_project_state_and_cds_ad_B.rout1 =
              team_project_state_and_cds_ad_B.out1;
          } else if (team_project_state_and_cds_ad_B.ADAS_state == 0.0) {
            team_project_state_and_cds_a_DW.is_c5_team_project_state_and_cd =
              team_project_state__IN_adas_off;
            team_project_state_and_cds_ad_B.rout1 =
              team_project_state_and_cds_ad_B.out1;
          } else {
            team_project_state_and_cds_ad_B.rout1 =
              team_project_state_and_cds_ad_B.out1 * 1.2;
          }
          break;
        }
      }

      /* End of Chart: '<S2>/Chart1' */

      /* MATLABSystem: '<Root>/PWM1' */
      team_project_state_and_cds_a_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);

      /* Start for MATLABSystem: '<Root>/PWM1' */
      if (team_project_state_and_cds_ad_B.buzzer <= 255.0) {
        rtb_Add1 = team_project_state_and_cds_ad_B.buzzer;
      } else {
        rtb_Add1 = 255.0;
      }

      if (!(rtb_Add1 >= 0.0)) {
        rtb_Add1 = 0.0;
      }

      /* MATLABSystem: '<Root>/PWM1' */
      MW_PWM_SetDutyCycle
        (team_project_state_and_cds_a_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE,
         rtb_Add1);

      /* DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn' */
      team_project_state_and_cds_ad_B.DiscreteTransferFcn = tmp_4;

      /* DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn' */
      tmp_1 = (uint32_T)team_project_state_and_cds_ad_P.num_Gd[1L];
      tmp_2 = (uint32_T)
        team_project_state_and_cds_a_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp_1, 1, &tmp_2, 1,
                    &team_project_state_and_cds_ad_B.DiscreteTransferFcn.chunks
                    [0U], 2);

      /* Sum: '<S3>/Add1' incorporates:
       *  DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn'
       */
      rtb_Add1 = team_project_state_and_cds_ad_B.rout1 - sMultiWord2Double
        (&team_project_state_and_cds_ad_B.DiscreteTransferFcn.chunks[0U], 2, 0) *
        1.1641532182693481E-10;

      /* Gain: '<S15>/Gain2' */
      team_project_state_and_cds_ad_B.Gain2_i =
        team_project_state_and_cds_ad_P.KP * rtb_Add1;
    }

    /* Sum: '<S15>/Subtract2' incorporates:
     *  Integrator: '<S15>/Integrator2'
     */
    team_project_state_and_cds_ad_B.Subtract2 =
      team_project_state_and_cds_ad_X.Integrator2_CSTATE +
      team_project_state_and_cds_ad_B.Gain2_i;

    /* Saturate: '<S3>/Saturation1' */
    if (team_project_state_and_cds_ad_B.Subtract2 >
        team_project_state_and_cds_ad_P.Saturation1_UpperSat) {
      /* Saturate: '<S3>/Saturation1' */
      team_project_state_and_cds_ad_B.Saturation1 =
        team_project_state_and_cds_ad_P.Saturation1_UpperSat;
    } else if (team_project_state_and_cds_ad_B.Subtract2 <
               team_project_state_and_cds_ad_P.Saturation1_LowerSat) {
      /* Saturate: '<S3>/Saturation1' */
      team_project_state_and_cds_ad_B.Saturation1 =
        team_project_state_and_cds_ad_P.Saturation1_LowerSat;
    } else {
      /* Saturate: '<S3>/Saturation1' */
      team_project_state_and_cds_ad_B.Saturation1 =
        team_project_state_and_cds_ad_B.Subtract2;
    }

    /* End of Saturate: '<S3>/Saturation1' */

    /* DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
     *  Gain: '<S14>/Gain1'
     */
    tmp_0 = floor(255.0 / team_project_state_and_cds_ad_P.Vlim *
                  team_project_state_and_cds_ad_B.Saturation1);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 256.0);
    }

    /* DataTypeConversion: '<S14>/Data Type Conversion' */
    team_project_state_and_cds_ad_B.DataTypeConversion_i = (uint8_T)(tmp_0 < 0.0
      ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-tmp_0 : (int16_T)(uint8_T)tmp_0);

    /* DataTypeConversion: '<S14>/Data Type Conversion1' */
    team_project_state_and_cds_ad_B.DataTypeConversion1 =
      team_project_state_and_cds_ad_B.DataTypeConversion_i;

    /* MATLABSystem: '<S13>/Encoder' */
    if (team_project_state_and_cds_a_DW.obj.SampleTime !=
        team_project_state_and_cds_ad_P.Encoder_SampleTime) {
      team_project_state_and_cds_a_DW.obj.SampleTime =
        team_project_state_and_cds_ad_P.Encoder_SampleTime;
    }

    if (team_project_state_and_cds_a_DW.obj.TunablePropsChanged) {
      team_project_state_and_cds_a_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(team_project_state_and_cds_a_DW.obj.Index, &tmp);
    if (rtmIsMajorTimeStep(team_project_state_and_cds_a_M)) {
      /* SampleTimeMath: '<S16>/TSamp' incorporates:
       *  MATLABSystem: '<S13>/Encoder'
       *
       * About '<S16>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       */
      rtb_TSamp = tmp;

      /* Gain: '<S13>/Gain1' incorporates:
       *  SampleTimeMath: '<S16>/TSamp'
       *  Sum: '<S16>/Diff'
       *  UnitDelay: '<S16>/UD'
       *
       * About '<S16>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S16>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S16>/UD':
       *
       *  Store in Global RAM
       */
      tmp_1 = (uint32_T)team_project_state_and_cds_ad_P.encoder_scale;
      tmp_2 = (uint32_T)(rtb_TSamp - team_project_state_and_cds_a_DW.UD_DSTATE);
      sMultiWordMul(&tmp_1, 1, &tmp_2, 1,
                    &team_project_state_and_cds_ad_B.Gain1.chunks[0U], 2);

      /* Gain: '<S13>/Gain2' incorporates:
       *  Gain: '<S13>/Gain1'
       */
      sMultiWordMul(&team_project_state_and_cds_ad_P.Gain2_Gain.chunks[0U], 2,
                    &team_project_state_and_cds_ad_B.Gain1.chunks[0U], 2,
                    &team_project_state_and_cds_ad_B.Gain2.chunks[0U], 4);

      /* SignalConversion generated from: '<S3>/Mux1' */
      team_project_state_and_cds_ad_B.TmpSignalConversionAtTAQSigLogg[0] =
        team_project_state_and_cds_ad_B.rout1;
      team_project_state_and_cds_ad_B.TmpSignalConversionAtTAQSigLogg[1] =
        team_project_state_and_cds_ad_B.DataTypeConversion1;

      /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
       *  Gain: '<S13>/Gain1'
       */
      sMultiWordMul(&team_project_state_and_cds_ad_B.Gain1.chunks[0U], 2,
                    &tmp_5.chunks[0U], 2, &tmp_3.chunks[0U], 4);
      sMultiWordShr(&tmp_3.chunks[0U], 4, 31U,
                    &team_project_state_and_cds_ad_B.r1.chunks[0U], 4);

      /* DataTypeConversion: '<S13>/Data Type Conversion1' */
      team_project_state_and_cds_ad_B.DataTypeConversion1_l = MultiWord2sLong
        (&team_project_state_and_cds_ad_B.r1.chunks[0U]);
    }

    /* MATLABSystem: '<S14>/PWM' */
    team_project_state_and_cds_a_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(3UL);
    MW_PWM_SetDutyCycle
      (team_project_state_and_cds_a_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, (real_T)
       team_project_state_and_cds_ad_B.DataTypeConversion_i);
    if (rtmIsMajorTimeStep(team_project_state_and_cds_a_M)) {
      /* Gain: '<S15>/Gain1' */
      team_project_state_and_cds_ad_B.Gain1_c =
        team_project_state_and_cds_ad_P.KI * rtb_Add1;
    }

    /* MATLABSystem: '<S2>/PWM' */
    team_project_state_and_cds_a_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(9UL);

    /* Start for MATLABSystem: '<S2>/PWM' */
    if (team_project_state_and_cds_ad_B.DataTypeConversion <= 255.0) {
      rtb_Add1 = team_project_state_and_cds_ad_B.DataTypeConversion;
    } else {
      rtb_Add1 = 255.0;
    }

    if (!(rtb_Add1 >= 0.0)) {
      rtb_Add1 = 0.0;
    }

    /* MATLABSystem: '<S2>/PWM' */
    MW_PWM_SetDutyCycle
      (team_project_state_and_cds_a_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Add1);

    /* MATLABSystem: '<S2>/PWM1' */
    team_project_state_and_cds_a_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(10UL);

    /* Start for MATLABSystem: '<S2>/PWM1' */
    if (team_project_state_and_cds_ad_B.DataTypeConversion <= 255.0) {
      rtb_Add1 = team_project_state_and_cds_ad_B.DataTypeConversion;
    } else {
      rtb_Add1 = 255.0;
    }

    if (!(rtb_Add1 >= 0.0)) {
      rtb_Add1 = 0.0;
    }

    /* MATLABSystem: '<S2>/PWM1' */
    MW_PWM_SetDutyCycle
      (team_project_state_and_cds_a_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Add1);

    /* MATLABSystem: '<S2>/PWM2' */
    team_project_state_and_cds_a_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(4UL);

    /* Start for MATLABSystem: '<S2>/PWM2' */
    if (team_project_state_and_cds_ad_B.DataTypeConversion <= 255.0) {
      rtb_Add1 = team_project_state_and_cds_ad_B.DataTypeConversion;
    } else {
      rtb_Add1 = 255.0;
    }

    if (!(rtb_Add1 >= 0.0)) {
      rtb_Add1 = 0.0;
    }

    /* MATLABSystem: '<S2>/PWM2' */
    MW_PWM_SetDutyCycle
      (team_project_state_and_cds_a_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Add1);
    if (rtmIsMajorTimeStep(team_project_state_and_cds_a_M)) {
    }
  }

  if (rtmIsMajorTimeStep(team_project_state_and_cds_a_M)) {
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

    if (rtmIsMajorTimeStep(team_project_state_and_cds_a_M)) {
      /* Update for Delay: '<Root>/Delay' */
      team_project_state_and_cds_a_DW.Delay_DSTATE = 0.0;

      /* Update for Delay: '<S1>/Delay' */
      team_project_state_and_cds_a_DW.Delay_DSTATE_e =
        team_project_state_and_cds_ad_B.ADAS_state;

      /* Update for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn' */
      sLong2MultiWord(team_project_state_and_cds_ad_B.DataTypeConversion1_l,
                      &tmp_0.chunks[0U], 2);
      sMultiWordShl(&tmp_0.chunks[0U], 2, 30U, &denAccum.chunks[0U], 2);
      tmp_1 = (uint32_T)team_project_state_and_cds_ad_P.den_Gd[1L];
      tmp_2 = (uint32_T)
        team_project_state_and_cds_a_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_0.chunks[0U], 2);
      MultiWordSub(&denAccum.chunks[0U], &tmp_0.chunks[0U], &denAccum_0.chunks
                   [0U], 2);
      if (team_project_state_and_cds_ad_P.den_Gd[0] == 0L) {
        if (sMultiWordGe(&denAccum_0.chunks[0U], &tmp_6.chunks[0U], 2)) {
          tmp = tmp_5;
        } else {
          tmp = tmp_7;
        }
      } else {
        sMultiWord2MultiWord(&denAccum_0.chunks[0U], 2,
                             &team_project_state_and_cds_ad_B.r3.chunks[0U], 3);
        sMultiWordShl(&team_project_state_and_cds_ad_B.r3.chunks[0U], 3, 30U,
                      &team_project_state_and_cds_ad_B.r2.chunks[0U], 3);
        sLong2MultiWord(team_project_state_and_cds_ad_P.den_Gd[0],
                        &team_project_state_and_cds_ad_B.r3.chunks[0U], 3);
        sMultiWordDivFloor(&team_project_state_and_cds_ad_B.r2.chunks[0U], 3,
                           &team_project_state_and_cds_ad_B.r3.chunks[0U], 3,
                           &team_project_state_and_cds_ad_B.r.chunks[0U], 4,
                           &team_project_state_and_cds_ad_B.r4.chunks[0U], 3,
                           &team_project_state_and_cds_ad_B.r5.chunks[0U], 3,
                           &tmp_3.chunks[0U], 3);
        sMultiWord2MultiWord(&team_project_state_and_cds_ad_B.r.chunks[0U], 4,
                             &tmp.chunks[0U], 2);
      }

      sMultiWordShr(&tmp.chunks[0U], 2, 30U, &tmp_4.chunks[0U], 2);
      team_project_state_and_cds_a_DW.DiscreteTransferFcn_states =
        MultiWord2sLong(&tmp_4.chunks[0U]);

      /* End of Update for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn' */

      /* Update for UnitDelay: '<S16>/UD' incorporates:
       *  SampleTimeMath: '<S16>/TSamp'
       *
       * About '<S16>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S16>/UD':
       *
       *  Store in Global RAM
       */
      team_project_state_and_cds_a_DW.UD_DSTATE = rtb_TSamp;
    }

    {
      extmodeErrorCode_T returnCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentSimTime = (extmodeSimulationTime_T)
        ((team_project_state_and_cds_a_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      returnCode = extmodeEvent(1,currentSimTime);
      if (returnCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(team_project_state_and_cds_a_M)) {
    rt_ertODEUpdateContinuousStates(&team_project_state_and_cds_a_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++team_project_state_and_cds_a_M->Timing.clockTick0;
    team_project_state_and_cds_a_M->Timing.t[0] = rtsiGetSolverStopTime
      (&team_project_state_and_cds_a_M->solverInfo);
    switch (team_project_state_and_cds_a_M->Timing.rtmDbBufReadBuf4) {
     case 0:
      team_project_state_and_cds_a_M->Timing.rtmDbBufWriteBuf4 = 1;
      break;

     case 1:
      team_project_state_and_cds_a_M->Timing.rtmDbBufWriteBuf4 = 0;
      break;

     default:
      team_project_state_and_cds_a_M->Timing.rtmDbBufWriteBuf4 =
        !team_project_state_and_cds_a_M->Timing.rtmDbBufLastBufWr4;
      break;
    }

    team_project_state_and_cds_a_M->
      Timing.rtmDbBufClockTick4
      [team_project_state_and_cds_a_M->Timing.rtmDbBufWriteBuf4] =
      team_project_state_and_cds_a_M->Timing.clockTick0;
    team_project_state_and_cds_a_M->Timing.rtmDbBufLastBufWr4 =
      team_project_state_and_cds_a_M->Timing.rtmDbBufWriteBuf4;
    team_project_state_and_cds_a_M->Timing.rtmDbBufWriteBuf4 = 0xFF;

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    team_project_state_and_cds_a_M->Timing.clockTick1++;
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void team_project_state_and_cds_adj_integration_derivatives(void)
{
  XDot_team_project_state_and_c_T *_rtXdot;
  _rtXdot = ((XDot_team_project_state_and_c_T *)
             team_project_state_and_cds_a_M->derivs);

  /* Derivatives for Integrator: '<S15>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = team_project_state_and_cds_ad_B.Gain1_c;
}

/* Model step function for TID2 */
void team_project_state_and_cds_adj_integration_step2(void) /* Sample time: [0.1s, 0.0s] */
{
  /* MATLABSystem: '<Root>/Digital Input1' */
  if (team_project_state_and_cds_a_DW.obj_i.SampleTime !=
      team_project_state_and_cds_ad_P.DigitalInput1_SampleTime) {
    team_project_state_and_cds_a_DW.obj_i.SampleTime =
      team_project_state_and_cds_ad_P.DigitalInput1_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Input1' */
  team_project_state_and_cds_ad_B.DigitalInput1 = readDigitalPin(31);

  /* MATLABSystem: '<Root>/Digital Input' */
  if (team_project_state_and_cds_a_DW.obj_h.SampleTime !=
      team_project_state_and_cds_ad_P.DigitalInput_SampleTime) {
    team_project_state_and_cds_a_DW.obj_h.SampleTime =
      team_project_state_and_cds_ad_P.DigitalInput_SampleTime;
  }

  readDigitalPin(36);

  /* End of MATLABSystem: '<Root>/Digital Input' */

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  team_project_state_and_cds_a_M->Timing.clockTick2++;
}

/* Model step function for TID3 */
void team_project_state_and_cds_adj_integration_step3(void) /* Sample time: [0.2s, 0.0s] */
{
  int8_T rtAction;

  /* Reset subsysRan breadcrumbs */
  srClearBC(team_project_state_and_cds_a_DW.IfActionSubsystem1_SubsysRanBC);

  /* If: '<S4>/If' */
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&team_project_state_and_cds_a_M->solverInfo)) {
    if (!team_project_state_and_cds_ad_B.DigitalInput1) {
      rtAction = 0;
    }

    team_project_state_and_cds_a_DW.If_ActiveSubsystem_n = rtAction;
  } else {
    rtAction = team_project_state_and_cds_a_DW.If_ActiveSubsystem_n;
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Sum: '<S7>/Sum' incorporates:
     *  Constant: '<S7>/Constant2'
     *  Delay: '<S7>/Delay1'
     */
    team_project_state_and_cds_a_DW.Delay1_DSTATE +=
      team_project_state_and_cds_ad_P.Constant2_Value;

    /* Math: '<S7>/Mod1' incorporates:
     *  Constant: '<S7>/Constant3'
     *  Delay: '<S7>/Delay1'
     */
    team_project_state_and_cds_ad_B.Mod1 = rt_modd_snf
      (team_project_state_and_cds_a_DW.Delay1_DSTATE,
       team_project_state_and_cds_ad_P.Constant3_Value);
    if (rtsiIsModeUpdateTimeStep(&team_project_state_and_cds_a_M->solverInfo)) {
      srUpdateBC(team_project_state_and_cds_a_DW.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
  }

  /* End of If: '<S4>/If' */

  /* RateTransition generated from: '<S4>/If Action Subsystem1' */
  team_project_state_and_cds_a_DW.TmpRTBAtIfActionSubsystem1Outpo =
    team_project_state_and_cds_ad_B.Mod1;

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick3" ensures timer will not overflow during the
   * application lifespan selected.
   */
  team_project_state_and_cds_a_M->Timing.clockTick3++;
}

/* Model initialize function */
void team_project_state_and_cds_adj_integration_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&team_project_state_and_cds_a_M->solverInfo,
                          &team_project_state_and_cds_a_M->Timing.simTimeStep);
    rtsiSetTPtr(&team_project_state_and_cds_a_M->solverInfo, &rtmGetTPtr
                (team_project_state_and_cds_a_M));
    rtsiSetStepSizePtr(&team_project_state_and_cds_a_M->solverInfo,
                       &team_project_state_and_cds_a_M->Timing.stepSize0);
    rtsiSetdXPtr(&team_project_state_and_cds_a_M->solverInfo,
                 &team_project_state_and_cds_a_M->derivs);
    rtsiSetContStatesPtr(&team_project_state_and_cds_a_M->solverInfo, (real_T **)
                         &team_project_state_and_cds_a_M->contStates);
    rtsiSetNumContStatesPtr(&team_project_state_and_cds_a_M->solverInfo,
      &team_project_state_and_cds_a_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&team_project_state_and_cds_a_M->solverInfo,
      &team_project_state_and_cds_a_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&team_project_state_and_cds_a_M->solverInfo,
       &team_project_state_and_cds_a_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&team_project_state_and_cds_a_M->solverInfo,
       &team_project_state_and_cds_a_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&team_project_state_and_cds_a_M->solverInfo,
      (boolean_T**) &team_project_state_and_cds_a_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&team_project_state_and_cds_a_M->solverInfo,
                          (&rtmGetErrorStatus(team_project_state_and_cds_a_M)));
    rtsiSetRTModelPtr(&team_project_state_and_cds_a_M->solverInfo,
                      team_project_state_and_cds_a_M);
  }

  rtsiSetSimTimeStep(&team_project_state_and_cds_a_M->solverInfo,
                     MAJOR_TIME_STEP);
  team_project_state_and_cds_a_M->intgData.y =
    team_project_state_and_cds_a_M->odeY;
  team_project_state_and_cds_a_M->intgData.f[0] =
    team_project_state_and_cds_a_M->odeF[0];
  team_project_state_and_cds_a_M->intgData.f[1] =
    team_project_state_and_cds_a_M->odeF[1];
  team_project_state_and_cds_a_M->intgData.f[2] =
    team_project_state_and_cds_a_M->odeF[2];
  team_project_state_and_cds_a_M->contStates = ((X_team_project_state_and_cds__T
    *) &team_project_state_and_cds_ad_X);
  team_project_state_and_cds_a_M->contStateDisabled =
    ((XDis_team_project_state_and_c_T *) &team_project_state_and_cds_XDis);
  team_project_state_and_cds_a_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&team_project_state_and_cds_a_M->solverInfo, (void *)
                    &team_project_state_and_cds_a_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange
    (&team_project_state_and_cds_a_M->solverInfo, false);
  rtsiSetSolverName(&team_project_state_and_cds_a_M->solverInfo,"ode3");
  rtmSetTPtr(team_project_state_and_cds_a_M,
             &team_project_state_and_cds_a_M->Timing.tArray[0]);
  rtmSetTFinal(team_project_state_and_cds_a_M, -1);
  team_project_state_and_cds_a_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  team_project_state_and_cds_a_M->Sizes.checksums[0] = (3641312543U);
  team_project_state_and_cds_a_M->Sizes.checksums[1] = (4092385276U);
  team_project_state_and_cds_a_M->Sizes.checksums[2] = (3644949378U);
  team_project_state_and_cds_a_M->Sizes.checksums[3] = (511702079U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[18];
    team_project_state_and_cds_a_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &team_project_state_and_cds_a_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &team_project_state_and_cds_a_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &team_project_state_and_cds_a_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)
      &team_project_state_and_cds_a_DW.SW1_SubsysRanBC;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(team_project_state_and_cds_a_M->extModeInfo,
      &team_project_state_and_cds_a_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(team_project_state_and_cds_a_M->extModeInfo,
                        team_project_state_and_cds_a_M->Sizes.checksums);
    rteiSetTPtr(team_project_state_and_cds_a_M->extModeInfo, rtmGetTPtr
                (team_project_state_and_cds_a_M));
  }

  team_project_state_and_cds_a_M->Timing.rtmDbBufReadBuf4 = 0xFF;
  team_project_state_and_cds_a_M->Timing.rtmDbBufWriteBuf4 = 0xFF;
  team_project_state_and_cds_a_M->Timing.rtmDbBufLastBufWr4 = 0;

  /* Start for RateTransition generated from: '<S4>/If Action Subsystem1' */
  team_project_state_and_cds_ad_B.TmpRTBAtIfActionSubsystem1Outpo =
    team_project_state_and_cds_ad_P.TmpRTBAtIfActionSubsystem1Outpo;

  /* Start for If: '<S1>/If' */
  team_project_state_and_cds_a_DW.If_ActiveSubsystem = -1;

  /* Start for Constant: '<Root>/Constant' */
  team_project_state_and_cds_ad_B.Constant = team_project_state_and_cds_ad_P.f;

  /* Start for Constant: '<Root>/Constant3' */
  team_project_state_and_cds_ad_B.Constant3 = team_project_state_and_cds_ad_P.l;

  /* Start for Constant: '<Root>/Constant1' */
  team_project_state_and_cds_ad_B.Constant1 = team_project_state_and_cds_ad_P.r;

  /* Start for Constant: '<Root>/Constant2' */
  team_project_state_and_cds_ad_B.Constant2 = team_project_state_and_cds_ad_P.b;

  /* Start for If: '<S4>/If' */
  team_project_state_and_cds_a_DW.If_ActiveSubsystem_n = -1;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  team_project_state_and_cds_a_DW.Delay_DSTATE =
    team_project_state_and_cds_ad_P.Delay_InitialCondition_f;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  team_project_state_and_cds_a_DW.Delay_DSTATE_e =
    team_project_state_and_cds_ad_P.Delay_InitialCondition_h;

  /* InitializeConditions for RateTransition generated from: '<S4>/If Action Subsystem1' */
  team_project_state_and_cds_a_DW.TmpRTBAtIfActionSubsystem1Outpo =
    team_project_state_and_cds_ad_P.TmpRTBAtIfActionSubsystem1Outpo;

  /* InitializeConditions for Integrator: '<S15>/Integrator2' */
  team_project_state_and_cds_ad_X.Integrator2_CSTATE =
    team_project_state_and_cds_ad_P.Integrator2_IC;

  /* InitializeConditions for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn' */
  team_project_state_and_cds_a_DW.DiscreteTransferFcn_states =
    team_project_state_and_cds_ad_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for UnitDelay: '<S16>/UD'
   *
   * Block description for '<S16>/UD':
   *
   *  Store in Global RAM
   */
  team_project_state_and_cds_a_DW.UD_DSTATE =
    team_project_state_and_cds_ad_P.DiscreteDerivative_ICPrevScaled;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<S5>/SW1'
   */

  /* System initialize for function-call system: '<S5>/SW1' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (team_project_state_and_cds_a_M->Timing.rtmDbBufWriteBuf4) {
   case 0:
    team_project_state_and_cds_a_M->Timing.rtmDbBufReadBuf4 = 1;
    break;

   case 1:
    team_project_state_and_cds_a_M->Timing.rtmDbBufReadBuf4 = 0;
    break;

   default:
    team_project_state_and_cds_a_M->Timing.rtmDbBufReadBuf4 =
      team_project_state_and_cds_a_M->Timing.rtmDbBufLastBufWr4;
    break;
  }

  team_project_state_and_cds_a_M->Timing.clockTick4 =
    team_project_state_and_cds_a_M->
    Timing.rtmDbBufClockTick4
    [team_project_state_and_cds_a_M->Timing.rtmDbBufReadBuf4];
  team_project_state_and_cds_a_M->Timing.rtmDbBufReadBuf4 = 0xFF;

  /* InitializeConditions for Sum: '<S10>/Sum' incorporates:
   *  Delay: '<S10>/Delay'
   */
  team_project_state_and_cds_a_DW.Delay_DSTATE_p =
    team_project_state_and_cds_ad_P.Delay_InitialCondition;

  /* SystemInitialize for Math: '<S10>/Mod' incorporates:
   *  Outport: '<S10>/Output'
   */
  team_project_state_and_cds_ad_B.Mod =
    team_project_state_and_cds_ad_P.Output_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, RISING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

  /* SystemInitialize for IfAction SubSystem: '<S4>/If Action Subsystem1' */
  /* InitializeConditions for Delay: '<S7>/Delay1' */
  team_project_state_and_cds_a_DW.Delay1_DSTATE =
    team_project_state_and_cds_ad_P.Delay1_InitialCondition;

  /* SystemInitialize for Math: '<S7>/Mod1' incorporates:
   *  Outport: '<S7>/sw2'
   */
  team_project_state_and_cds_ad_B.Mod1 = team_project_state_and_cds_ad_P.sw2_Y0;

  /* End of SystemInitialize for SubSystem: '<S4>/If Action Subsystem1' */

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  team_project_state_and_cds_a_DW.obj_d.matlabCodegenIsDeleted = false;
  team_project_state_and_cds_a_DW.obj_d.SampleTime =
    team_project_state_and_cds_ad_P.AnalogInput1_SampleTime;
  team_project_state_and_cds_a_DW.obj_d.isInitialized = 1L;
  team_project_state_and_cds_a_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(55UL);
  team_project_state_and_cds_a_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/��������' */
  team_project_state_and_cds_a_DW.obj_k.matlabCodegenIsDeleted = false;
  team_project_state_and_cds_a_DW.obj_k.SampleTime =
    team_project_state_and_cds_ad_P._SampleTime;
  team_project_state_and_cds_a_DW.obj_k.isInitialized = 1L;
  team_project_state_and_cds_a_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(62UL);
  team_project_state_and_cds_a_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM1' */
  team_project_state_and_cds_a_DW.obj_i2.matlabCodegenIsDeleted = false;
  team_project_state_and_cds_a_DW.obj_i2.isInitialized = 1L;
  team_project_state_and_cds_a_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_Open(5UL, 0.0, 0.0);
  team_project_state_and_cds_a_DW.obj_i2.isSetupComplete = true;

  /* Start for MATLABSystem: '<S13>/Encoder' */
  team_project_state_and_cds_a_DW.obj.Index = 0U;
  team_project_state_and_cds_a_DW.obj.matlabCodegenIsDeleted = false;
  team_project_state_and_cds_a_DW.obj.SampleTime =
    team_project_state_and_cds_ad_P.Encoder_SampleTime;
  team_project_state_and_cds_a_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(20UL, 21UL, &team_project_state_and_cds_a_DW.obj.Index);
  team_project_state_and_cds_a_DW.obj.isSetupComplete = true;
  team_project_state_and_cds_a_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S13>/Encoder' */
  MW_EncoderReset(team_project_state_and_cds_a_DW.obj.Index);

  /* Start for MATLABSystem: '<S14>/PWM' */
  team_project_state_and_cds_a_DW.obj_f.matlabCodegenIsDeleted = false;
  team_project_state_and_cds_a_DW.obj_f.isInitialized = 1L;
  team_project_state_and_cds_a_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (3UL, 0.0, 0.0);
  team_project_state_and_cds_a_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM' */
  team_project_state_and_cds_a_DW.obj_j.matlabCodegenIsDeleted = false;
  team_project_state_and_cds_a_DW.obj_j.isInitialized = 1L;
  team_project_state_and_cds_a_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (9UL, 0.0, 0.0);
  team_project_state_and_cds_a_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM1' */
  team_project_state_and_cds_a_DW.obj_l.matlabCodegenIsDeleted = false;
  team_project_state_and_cds_a_DW.obj_l.isInitialized = 1L;
  team_project_state_and_cds_a_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (10UL, 0.0, 0.0);
  team_project_state_and_cds_a_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM2' */
  team_project_state_and_cds_a_DW.obj_a.matlabCodegenIsDeleted = false;
  team_project_state_and_cds_a_DW.obj_a.isInitialized = 1L;
  team_project_state_and_cds_a_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (4UL, 0.0, 0.0);
  team_project_state_and_cds_a_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input1' */
  team_project_state_and_cds_a_DW.obj_i.matlabCodegenIsDeleted = false;
  team_project_state_and_cds_a_DW.obj_i.SampleTime =
    team_project_state_and_cds_ad_P.DigitalInput1_SampleTime;
  team_project_state_and_cds_a_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(31, 0);
  team_project_state_and_cds_a_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  team_project_state_and_cds_a_DW.obj_h.matlabCodegenIsDeleted = false;
  team_project_state_and_cds_a_DW.obj_h.SampleTime =
    team_project_state_and_cds_ad_P.DigitalInput_SampleTime;
  team_project_state_and_cds_a_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(36, 0);
  team_project_state_and_cds_a_DW.obj_h.isSetupComplete = true;
}

/* Model terminate function */
void team_project_state_and_cds_adj_integration_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!team_project_state_and_cds_a_DW.obj_d.matlabCodegenIsDeleted) {
    team_project_state_and_cds_a_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((team_project_state_and_cds_a_DW.obj_d.isInitialized == 1L) &&
        team_project_state_and_cds_a_DW.obj_d.isSetupComplete) {
      team_project_state_and_cds_a_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(55UL);
      MW_AnalogIn_Close
        (team_project_state_and_cds_a_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */
  /* Terminate for MATLABSystem: '<Root>/��������' */
  if (!team_project_state_and_cds_a_DW.obj_k.matlabCodegenIsDeleted) {
    team_project_state_and_cds_a_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((team_project_state_and_cds_a_DW.obj_k.isInitialized == 1L) &&
        team_project_state_and_cds_a_DW.obj_k.isSetupComplete) {
      team_project_state_and_cds_a_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close
        (team_project_state_and_cds_a_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/��������' */

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  if (!team_project_state_and_cds_a_DW.obj_i2.matlabCodegenIsDeleted) {
    team_project_state_and_cds_a_DW.obj_i2.matlabCodegenIsDeleted = true;
    if ((team_project_state_and_cds_a_DW.obj_i2.isInitialized == 1L) &&
        team_project_state_and_cds_a_DW.obj_i2.isSetupComplete) {
      team_project_state_and_cds_a_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle
        (team_project_state_and_cds_a_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      team_project_state_and_cds_a_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_Close
        (team_project_state_and_cds_a_DW.obj_i2.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */

  /* Terminate for MATLABSystem: '<S13>/Encoder' */
  if (!team_project_state_and_cds_a_DW.obj.matlabCodegenIsDeleted) {
    team_project_state_and_cds_a_DW.obj.matlabCodegenIsDeleted = true;
    if ((team_project_state_and_cds_a_DW.obj.isInitialized == 1L) &&
        team_project_state_and_cds_a_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/Encoder' */
  /* Terminate for MATLABSystem: '<S14>/PWM' */
  if (!team_project_state_and_cds_a_DW.obj_f.matlabCodegenIsDeleted) {
    team_project_state_and_cds_a_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((team_project_state_and_cds_a_DW.obj_f.isInitialized == 1L) &&
        team_project_state_and_cds_a_DW.obj_f.isSetupComplete) {
      team_project_state_and_cds_a_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(3UL);
      MW_PWM_SetDutyCycle
        (team_project_state_and_cds_a_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      team_project_state_and_cds_a_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(3UL);
      MW_PWM_Close
        (team_project_state_and_cds_a_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S14>/PWM' */
  /* Terminate for MATLABSystem: '<S2>/PWM' */
  if (!team_project_state_and_cds_a_DW.obj_j.matlabCodegenIsDeleted) {
    team_project_state_and_cds_a_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((team_project_state_and_cds_a_DW.obj_j.isInitialized == 1L) &&
        team_project_state_and_cds_a_DW.obj_j.isSetupComplete) {
      team_project_state_and_cds_a_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle
        (team_project_state_and_cds_a_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      team_project_state_and_cds_a_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_Close
        (team_project_state_and_cds_a_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM' */

  /* Terminate for MATLABSystem: '<S2>/PWM1' */
  if (!team_project_state_and_cds_a_DW.obj_l.matlabCodegenIsDeleted) {
    team_project_state_and_cds_a_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((team_project_state_and_cds_a_DW.obj_l.isInitialized == 1L) &&
        team_project_state_and_cds_a_DW.obj_l.isSetupComplete) {
      team_project_state_and_cds_a_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle
        (team_project_state_and_cds_a_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      team_project_state_and_cds_a_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(10UL);
      MW_PWM_Close
        (team_project_state_and_cds_a_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM1' */

  /* Terminate for MATLABSystem: '<S2>/PWM2' */
  if (!team_project_state_and_cds_a_DW.obj_a.matlabCodegenIsDeleted) {
    team_project_state_and_cds_a_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((team_project_state_and_cds_a_DW.obj_a.isInitialized == 1L) &&
        team_project_state_and_cds_a_DW.obj_a.isSetupComplete) {
      team_project_state_and_cds_a_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle
        (team_project_state_and_cds_a_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      team_project_state_and_cds_a_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(4UL);
      MW_PWM_Close
        (team_project_state_and_cds_a_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM2' */
  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  if (!team_project_state_and_cds_a_DW.obj_i.matlabCodegenIsDeleted) {
    team_project_state_and_cds_a_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!team_project_state_and_cds_a_DW.obj_h.matlabCodegenIsDeleted) {
    team_project_state_and_cds_a_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */