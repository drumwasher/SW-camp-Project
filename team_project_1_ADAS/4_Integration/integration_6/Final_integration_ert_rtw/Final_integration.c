/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_integration.c
 *
 * Code generated for Simulink model 'Final_integration'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb 15 09:43:46 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Final_integration.h"
#include "rtwtypes.h"
#include "Final_integration_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "multiword_types.h"
#include <float.h>

/* Block signals (default storage) */
B_Final_integration_T Final_integration_B;

/* Continuous states */
X_Final_integration_T Final_integration_X;

/* Disabled State Vector */
XDis_Final_integration_T Final_integration_XDis;

/* Block states (default storage) */
DW_Final_integration_T Final_integration_DW;

/* Real-time model */
static RT_MODEL_Final_integration_T Final_integration_M_;
RT_MODEL_Final_integration_T *const Final_integration_M = &Final_integration_M_;
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

uint32_T MultiWord2uLong(const uint32_T u[])
{
  return u[0];
}

void uMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  uint32_T u1i;
  uint32_T yi;
  int16_T i;
  int16_T i1;
  int16_T nb;
  int16_T nc;
  uint16_T nr;
  nb = (int16_T)(n2 >> 5);
  i = 0;
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

      yi = u1i >> nr;
      if (nc < n1) {
        yi |= u1[nc] << (32U - nr);
      }

      y[i] = yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = 0UL;
    i++;
  }
}

void uMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
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

/* Callback for Hardware Interrupt Block: '<Root>/Drive Mode Switch' */
void MW_ISR_2(void)
{
  /* Call the system: <S16>/SW1 */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem_SubsysRanB_al);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem1_SubsysRan_l2);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_g);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem1_SubsysRanB_a);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.SW1_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<Root>/Drive Mode Switch' */

    /* Output and update for function-call system: '<S16>/SW1' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (Final_integration_M->Timing.rtmDbBufWriteBuf3) {
     case 0:
      Final_integration_M->Timing.rtmDbBufReadBuf3 = 1;
      break;

     case 1:
      Final_integration_M->Timing.rtmDbBufReadBuf3 = 0;
      break;

     default:
      Final_integration_M->Timing.rtmDbBufReadBuf3 =
        Final_integration_M->Timing.rtmDbBufLastBufWr3;
      break;
    }

    Final_integration_M->Timing.clockTick3 =
      Final_integration_M->Timing.rtmDbBufClockTick3
      [Final_integration_M->Timing.rtmDbBufReadBuf3];
    Final_integration_M->Timing.rtmDbBufReadBuf3 = 0xFF;

    /* If: '<S19>/If' incorporates:
     *  Delay: '<S19>/Delay'
     */
    if (Final_integration_DW.Delay_DSTATE_p == 0.0) {
      /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* Merge: '<S19>/Merge' incorporates:
       *  Constant: '<S19>/Constant2'
       *  SignalConversion generated from: '<S20>/In1'
       */
      Final_integration_B.Merge_h = Final_integration_P.Constant2_Value;

      /* End of Outputs for SubSystem: '<S19>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* Update for If: '<S19>/If' */
      Final_integration_DW.IfActionSubsystem_SubsysRanB_al = 4;

      /* End of Update for SubSystem: '<S19>/If Action Subsystem' */
    } else if (Final_integration_DW.Delay_DSTATE_p == 1.0) {
      /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* If: '<S21>/If1' */
      if ((Final_integration_B.Delay_j == 0.0) && (Final_integration_B.Delay ==
           0.0)) {
        /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S23>/Action Port'
         */
        /* Merge: '<S19>/Merge' incorporates:
         *  Constant: '<S21>/Constant'
         *  SignalConversion generated from: '<S23>/In1'
         */
        Final_integration_B.Merge_h = Final_integration_P.Constant_Value;

        /* End of Outputs for SubSystem: '<S21>/If Action Subsystem1' */

        /* Update for IfAction SubSystem: '<S21>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S23>/Action Port'
         */
        /* Update for If: '<S21>/If1' */
        Final_integration_DW.IfActionSubsystem1_SubsysRan_l2 = 4;

        /* End of Update for SubSystem: '<S21>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
         *  ActionPort: '<S22>/Action Port'
         */
        /* Merge: '<S19>/Merge' incorporates:
         *  Constant: '<S21>/Constant1'
         *  SignalConversion generated from: '<S22>/In1'
         */
        Final_integration_B.Merge_h = Final_integration_P.Constant1_Value;

        /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */

        /* Update for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
         *  ActionPort: '<S22>/Action Port'
         */
        /* Update for If: '<S21>/If1' */
        Final_integration_DW.IfActionSubsystem_SubsysRanBC_g = 4;

        /* End of Update for SubSystem: '<S21>/If Action Subsystem' */
      }

      /* End of If: '<S21>/If1' */
      /* End of Outputs for SubSystem: '<S19>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S19>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* Update for If: '<S19>/If' */
      Final_integration_DW.IfActionSubsystem1_SubsysRanB_a = 4;

      /* End of Update for SubSystem: '<S19>/If Action Subsystem1' */
    }

    /* End of If: '<S19>/If' */

    /* Update for Delay: '<S19>/Delay' */
    Final_integration_DW.Delay_DSTATE_p = Final_integration_B.Merge_h;
    Final_integration_DW.SW1_SubsysRanBC = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/Drive Mode Switch' */
  }

  extmodeEvent(3,((Final_integration_M->Timing.clockTick3) * 0.01));
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Final_integration_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(Final_integration_M, 2));
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

  /* tid 1 shares data with slower tid rate: 2 */
  if (Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
    Final_integration_M->Timing.RateInteraction.TID1_2 =
      (Final_integration_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Final_integration_M->Timing.TaskCounters.TID[2])++;
  if ((Final_integration_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.2s, 0.0s] */
    Final_integration_M->Timing.TaskCounters.TID[2] = 0;
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
  Final_integration_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Final_integration_step0();
  Final_integration_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Final_integration_step0();
  Final_integration_derivatives();

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

/*
 * Output and update for action system:
 *    '<S10>/If Action Subsystem1'
 *    '<S10>/If Action Subsystem3'
 *    '<S7>/If Action Subsystem1'
 */
void Final_in_IfActionSubsystem1(real_T *rty_Out1,
  P_IfActionSubsystem1_Final_in_T *localP)
{
  /* SignalConversion generated from: '<S13>/Out1' incorporates:
   *  Constant: '<S13>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S50>/If Action Subsystem'
 *    '<S50>/If Action Subsystem2'
 */
void Final_int_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1, real_T
  *rty_Out2)
{
  /* SignalConversion generated from: '<S51>/Out1' incorporates:
   *  SignalConversion generated from: '<S51>/In1'
   */
  *rty_Out1 = rtu_In1;

  /* SignalConversion generated from: '<S51>/Out2' incorporates:
   *  SignalConversion generated from: '<S51>/In1'
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
void Final_integration_step0(void)     /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  int32_T rtb_TSamp;
  int32_T rtb_TSamp_l;
  if (rtmIsMajorTimeStep(Final_integration_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Final_integration_M->solverInfo,
                          ((Final_integration_M->Timing.clockTick0+1)*
      Final_integration_M->Timing.stepSize0));

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Final_integration_M)) {
    Final_integration_M->Timing.t[0] = rtsiGetT(&Final_integration_M->solverInfo);
  }

  {
    int128m_T tmp_0;
    uint64m_T tmp_1;
    uint64m_T tmp_2;
    real_T rtb_Product_g;
    uint32_T rtb_Gain_l;
    uint32_T tmp;
    uint32_T tmp_4;
    uint16_T b_varargout_1;
    int8_T rtAction;
    uint8_T tmp_3;
    static const int64m_T tmp_5 = { { 0UL, 0UL }/* chunks */
    };

    static const int64m_T tmp_6 = { { 25UL, 0UL }/* chunks */
    };

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem1_SubsysRanB_e);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem3_SubsysRanB_n);

    /* Reset subsysRan breadcrumbs */
    srClearBC
      (Final_integration_DW.IfActionSubsystem1_k.IfActionSubsystem1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_n);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem9_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem10_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_f);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem1_SubsysRanB_d);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem2_SubsysRanB_l);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem3_SubsysRanB_p);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem1_SubsysRanB_p);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_c);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem3_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem11_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_j);

    /* Reset subsysRan breadcrumbs */
    srClearBC
      (Final_integration_DW.IfActionSubsystem_a.IfActionSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem1_SubsysRanB_l);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_DW.IfActionSubsystem1_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<Root>/Drive Mode Switch' */
    if (rtmIsMajorTimeStep(Final_integration_M)) {
      /* RateTransition: '<S16>/Rate Transition' */
      Final_integration_B.RateTransition = Final_integration_B.Merge_h;

      /* If: '<S3>/If' */
      rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
        if (Final_integration_B.RateTransition == 1.0) {
          rtAction = 0;
        }

        Final_integration_DW.If_ActiveSubsystem = rtAction;
      } else {
        rtAction = Final_integration_DW.If_ActiveSubsystem;
      }

      if (rtAction == 0) {
        /* Outputs for IfAction SubSystem: '<S15>/If Action Subsystem' incorporates:
         *  ActionPort: '<S17>/Action Port'
         */
        /* SignalConversion generated from: '<S17>/sw2' */
        Final_integration_B.sw2 = Final_integration_B.Mod1;
        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_n);
        }

        /* End of Outputs for SubSystem: '<S15>/If Action Subsystem' */
      }

      /* End of If: '<S3>/If' */

      /* Constant: '<Root>/전방 장애물 거리' */
      Final_integration_B.u = Final_integration_P.f;

      /* Constant: '<Root>/좌측 장애물 거리' */
      Final_integration_B.u_f = Final_integration_P.l;

      /* Constant: '<Root>/우측 장애물 거리' */
      Final_integration_B.u_d = Final_integration_P.r;

      /* Constant: '<Root>/후방 장애물 거리' */
      Final_integration_B.u_i = Final_integration_P.b;

      /* MATLABSystem: '<Root>/가변저항' */
      if (Final_integration_DW.obj_f.SampleTime !=
          Final_integration_P._SampleTime) {
        Final_integration_DW.obj_f.SampleTime = Final_integration_P._SampleTime;
      }

      Final_integration_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(62UL);
      MW_AnalogInSingle_ReadResult
        (Final_integration_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
         &b_varargout_1, MW_ANALOGIN_UINT16);

      /* If: '<S32>/If3' */
      if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
        if (Final_integration_B.RateTransition == 0.0) {
          Final_integration_DW.If3_ActiveSubsystem = 0;
        } else if (Final_integration_B.sw2 == 0.0) {
          Final_integration_DW.If3_ActiveSubsystem = 1;
        } else {
          Final_integration_DW.If3_ActiveSubsystem = 2;
        }
      }

      switch (Final_integration_DW.If3_ActiveSubsystem) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem9' incorporates:
         *  ActionPort: '<S35>/Action Port'
         */
        /* Merge: '<S34>/Merge' incorporates:
         *  Constant: '<S35>/Constant'
         *  Merge: '<S32>/Merge7'
         *  SignalConversion generated from: '<S35>/Out1'
         */
        Final_integration_B.Merge7 = Final_integration_P.Constant_Value_m;

        /* Merge: '<S34>/Merge1' incorporates:
         *  Constant: '<S35>/Constant'
         *  Merge: '<S32>/Merge8'
         *  SignalConversion generated from: '<S35>/Out2'
         */
        Final_integration_B.Merge8 = Final_integration_P.Constant_Value_m;

        /* Merge: '<S32>/Merge9' incorporates:
         *  Constant: '<S35>/Constant'
         *  SignalConversion generated from: '<S35>/Out3'
         */
        Final_integration_B.Merge9 = Final_integration_P.Constant_Value_m;
        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC(Final_integration_DW.IfActionSubsystem9_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S32>/If Action Subsystem9' */
        break;

       case 1:
        /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
         *  Gain: '<S6>/Gain4'
         *  MATLABSystem: '<Root>/가변저항'
         * */
        rtb_Product_g = (real_T)((uint32_T)Final_integration_P.Gain4_Gain *
          b_varargout_1) * 7.62939453125E-6;

        /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem10' incorporates:
         *  ActionPort: '<S33>/Action Port'
         */
        /* Merge: '<S34>/Merge' incorporates:
         *  Constant: '<S33>/Constant'
         *  Constant: '<S33>/Constant1'
         *  Constant: '<S33>/Constant2'
         *  Constant: '<S33>/Constant4'
         *  Constant: '<S33>/Constant5'
         *  DataTypeConversion: '<S6>/Data Type Conversion'
         *  Merge: '<S32>/Merge7'
         *  Product: '<S33>/Divide'
         *  Product: '<S33>/Divide1'
         *  Product: '<S33>/Product'
         *  Sum: '<S33>/Minus'
         *  Sum: '<S33>/Sum'
         */
        Final_integration_B.Merge7 = ((rtb_Product_g -
          Final_integration_P.Constant2_Value_go) /
          Final_integration_P.Constant5_Value /
          Final_integration_P.Constant1_Value_f +
          Final_integration_P.Constant4_Value) * Final_integration_P.default1;

        /* Merge: '<S34>/Merge1' incorporates:
         *  Constant: '<S33>/Constant3'
         *  Constant: '<S33>/Constant6'
         *  Constant: '<S33>/Constant7'
         *  Constant: '<S33>/Constant8'
         *  Constant: '<S33>/Constant9'
         *  Merge: '<S32>/Merge8'
         *  Product: '<S33>/Divide2'
         *  Product: '<S33>/Divide3'
         *  Product: '<S33>/Product1'
         *  Sum: '<S33>/Minus1'
         *  Sum: '<S33>/Sum1'
         */
        Final_integration_B.Merge8 = ((Final_integration_P.Constant7_Value -
          rtb_Product_g) / Final_integration_P.Constant9_Value /
          Final_integration_P.Constant6_Value +
          Final_integration_P.Constant8_Value) * Final_integration_P.default1;

        /* Merge: '<S32>/Merge9' incorporates:
         *  Constant: '<S33>/Constant10'
         *  SignalConversion generated from: '<S33>/Out3'
         */
        Final_integration_B.Merge9 = Final_integration_P.Constant10_Value;
        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC(Final_integration_DW.IfActionSubsystem10_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S32>/If Action Subsystem10' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem11' incorporates:
         *  ActionPort: '<S34>/Action Port'
         */
        /* If: '<S34>/If' */
        if (Final_integration_B.u > 10.0) {
          /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S37>/Action Port'
           */
          /* Merge: '<S32>/Merge9' incorporates:
           *  Constant: '<S37>/Constant'
           *  SignalConversion generated from: '<S37>/Out3'
           */
          Final_integration_B.Merge9 = Final_integration_P.Constant_Value_o;

          /* If: '<S37>/If' */
          if ((Final_integration_B.u_f < 10.0) && (Final_integration_B.u_d <
               10.0)) {
            /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem' incorporates:
             *  ActionPort: '<S40>/Action Port'
             */
            /* Product: '<S40>/Product' incorporates:
             *  Constant: '<S40>/Constant1'
             *  Sum: '<S40>/Subtract'
             */
            rtb_Product_g = (Final_integration_B.u_f - Final_integration_B.u_d) *
              Final_integration_P.steering;

            /* Merge: '<S34>/Merge' incorporates:
             *  Constant: '<S40>/Constant'
             *  Constant: '<S40>/Constant2'
             *  Product: '<S40>/Product1'
             *  Sum: '<S40>/Subtract1'
             */
            Final_integration_B.Merge7 = (Final_integration_P.Constant2_Value_j
              - rtb_Product_g) * Final_integration_P.default1;

            /* Merge: '<S34>/Merge1' incorporates:
             *  Constant: '<S40>/Constant2'
             *  Constant: '<S40>/Constant3'
             *  Product: '<S40>/Product3'
             *  Sum: '<S40>/Subtract3'
             */
            Final_integration_B.Merge8 = (Final_integration_P.Constant2_Value_j
              + rtb_Product_g) * Final_integration_P.default1;

            /* End of Outputs for SubSystem: '<S37>/If Action Subsystem' */

            /* Update for IfAction SubSystem: '<S37>/If Action Subsystem' incorporates:
             *  ActionPort: '<S40>/Action Port'
             */
            /* Update for If: '<S37>/If' */
            srUpdateBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_f);

            /* End of Update for SubSystem: '<S37>/If Action Subsystem' */
          } else if (Final_integration_B.u_f < 10.0) {
            /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S41>/Action Port'
             */
            /* Sum: '<S41>/Subtract' incorporates:
             *  Constant: '<S41>/Constant4'
             */
            Final_integration_B.Subtract = Final_integration_P.Constant4_Value_d
              - Final_integration_B.u_f;

            /* Product: '<S41>/Product' incorporates:
             *  Constant: '<S41>/Constant1'
             */
            Final_integration_B.Product = Final_integration_P.steering *
              Final_integration_B.Subtract;

            /* Merge: '<S34>/Merge1' incorporates:
             *  Constant: '<S41>/Constant'
             *  Constant: '<S41>/Constant2'
             *  Product: '<S41>/Product3'
             *  Sum: '<S41>/Subtract3'
             */
            Final_integration_B.Merge8 = (Final_integration_P.Constant2_Value_n
              - Final_integration_B.Product) * Final_integration_P.default1;

            /* Sum: '<S41>/Subtract1' incorporates:
             *  Constant: '<S41>/Constant2'
             */
            Final_integration_B.Subtract1 =
              Final_integration_P.Constant2_Value_n +
              Final_integration_B.Product;

            /* Product: '<S41>/Product1' incorporates:
             *  Constant: '<S41>/Constant'
             */
            Final_integration_B.Product1 = Final_integration_P.default1 *
              Final_integration_B.Subtract1;

            /* Merge: '<S34>/Merge' incorporates:
             *  SignalConversion generated from: '<S41>/Out2'
             */
            Final_integration_B.Merge7 = Final_integration_B.Product1;

            /* Update for IfAction SubSystem: '<S37>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S41>/Action Port'
             */
            /* Update for If: '<S37>/If' */
            srUpdateBC(Final_integration_DW.IfActionSubsystem1_SubsysRanB_d);

            /* End of Update for SubSystem: '<S37>/If Action Subsystem1' */
          } else if (Final_integration_B.u_d < 10.0) {
            /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S42>/Action Port'
             */
            /* Product: '<S42>/Product' incorporates:
             *  Constant: '<S42>/Constant1'
             *  Constant: '<S42>/Constant4'
             *  Sum: '<S42>/Subtract'
             */
            rtb_Product_g = (Final_integration_P.Constant4_Value_m -
                             Final_integration_B.u_d) *
              Final_integration_P.steering;

            /* Merge: '<S34>/Merge' incorporates:
             *  Constant: '<S42>/Constant'
             *  Constant: '<S42>/Constant2'
             *  Product: '<S42>/Product1'
             *  Sum: '<S42>/Subtract1'
             */
            Final_integration_B.Merge7 = (Final_integration_P.Constant2_Value_gd
              - rtb_Product_g) * Final_integration_P.default1;

            /* Merge: '<S34>/Merge1' incorporates:
             *  Constant: '<S42>/Constant'
             *  Constant: '<S42>/Constant2'
             *  Product: '<S42>/Product3'
             *  Sum: '<S42>/Subtract3'
             */
            Final_integration_B.Merge8 = (Final_integration_P.Constant2_Value_gd
              + rtb_Product_g) * Final_integration_P.default1;

            /* End of Outputs for SubSystem: '<S37>/If Action Subsystem2' */

            /* Update for IfAction SubSystem: '<S37>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S42>/Action Port'
             */
            /* Update for If: '<S37>/If' */
            srUpdateBC(Final_integration_DW.IfActionSubsystem2_SubsysRanB_l);

            /* End of Update for SubSystem: '<S37>/If Action Subsystem2' */
          } else {
            /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem3' incorporates:
             *  ActionPort: '<S43>/Action Port'
             */
            /* Merge: '<S34>/Merge' incorporates:
             *  Constant: '<S43>/Constant'
             *  SignalConversion generated from: '<S43>/Out1'
             */
            Final_integration_B.Merge7 = Final_integration_P.default1;

            /* Merge: '<S34>/Merge1' incorporates:
             *  Constant: '<S43>/Constant1'
             *  SignalConversion generated from: '<S43>/Out2'
             */
            Final_integration_B.Merge8 = Final_integration_P.default1;

            /* End of Outputs for SubSystem: '<S37>/If Action Subsystem3' */

            /* Update for IfAction SubSystem: '<S37>/If Action Subsystem3' incorporates:
             *  ActionPort: '<S43>/Action Port'
             */
            /* Update for If: '<S37>/If' */
            srUpdateBC(Final_integration_DW.IfActionSubsystem3_SubsysRanB_p);

            /* End of Update for SubSystem: '<S37>/If Action Subsystem3' */
          }

          /* End of If: '<S37>/If' */
          /* End of Outputs for SubSystem: '<S34>/If Action Subsystem1' */

          /* Update for IfAction SubSystem: '<S34>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S37>/Action Port'
           */
          /* Update for If: '<S34>/If' */
          srUpdateBC(Final_integration_DW.IfActionSubsystem1_SubsysRanB_p);

          /* End of Update for SubSystem: '<S34>/If Action Subsystem1' */
        } else {
          /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem' incorporates:
           *  ActionPort: '<S36>/Action Port'
           */
          /* Merge: '<S34>/Merge' incorporates:
           *  Constant: '<S36>/Constant'
           *  SignalConversion generated from: '<S36>/Out1'
           */
          Final_integration_B.Merge7 = Final_integration_P.Constant_Value_mr;

          /* Merge: '<S34>/Merge1' incorporates:
           *  Constant: '<S36>/Constant1'
           *  SignalConversion generated from: '<S36>/Out2'
           */
          Final_integration_B.Merge8 = Final_integration_P.Constant1_Value_f5;

          /* Merge: '<S32>/Merge9' incorporates:
           *  Constant: '<S36>/Constant2'
           *  SignalConversion generated from: '<S36>/Out3'
           */
          Final_integration_B.Merge9 = Final_integration_P.Constant2_Value_p;

          /* End of Outputs for SubSystem: '<S34>/If Action Subsystem' */

          /* Update for IfAction SubSystem: '<S34>/If Action Subsystem' incorporates:
           *  ActionPort: '<S36>/Action Port'
           */
          /* Update for If: '<S34>/If' */
          srUpdateBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_c);

          /* End of Update for SubSystem: '<S34>/If Action Subsystem' */
        }

        /* End of If: '<S34>/If' */

        /* If: '<S34>/If1' */
        if (Final_integration_B.u_i > 10.0) {
          /* Update for IfAction SubSystem: '<S34>/If Action Subsystem2' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          /* Update for If: '<S34>/If1' */
          srUpdateBC(Final_integration_DW.IfActionSubsystem2_SubsysRanBC);

          /* End of Update for SubSystem: '<S34>/If Action Subsystem2' */
        } else {
          /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem3' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          /* Merge: '<S34>/Merge' incorporates:
           *  Gain: '<S39>/Gain'
           *  Merge: '<S32>/Merge7'
           */
          Final_integration_B.Merge7 *= Final_integration_P.Gain_Gain;

          /* Merge: '<S34>/Merge1' incorporates:
           *  Gain: '<S39>/Gain1'
           *  Merge: '<S32>/Merge8'
           */
          Final_integration_B.Merge8 *= Final_integration_P.Gain1_Gain;

          /* End of Outputs for SubSystem: '<S34>/If Action Subsystem3' */

          /* Update for IfAction SubSystem: '<S34>/If Action Subsystem3' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          /* Update for If: '<S34>/If1' */
          srUpdateBC(Final_integration_DW.IfActionSubsystem3_SubsysRanBC);

          /* End of Update for SubSystem: '<S34>/If Action Subsystem3' */
        }

        /* End of If: '<S34>/If1' */
        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC(Final_integration_DW.IfActionSubsystem11_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S32>/If Action Subsystem11' */
        break;
      }

      /* End of If: '<S32>/If3' */

      /* Gain: '<S28>/Gain1' incorporates:
       *  Gain: '<S24>/Gain2'
       */
      Final_integration_B.Gain1_f = Final_integration_P.Gain2_Gain;

      /* MATLABSystem: '<S24>/Encoder' */
      if (Final_integration_DW.obj_a.SampleTime !=
          Final_integration_P.Encoder_SampleTime) {
        Final_integration_DW.obj_a.SampleTime =
          Final_integration_P.Encoder_SampleTime;
      }

      if (Final_integration_DW.obj_a.TunablePropsChanged) {
        Final_integration_DW.obj_a.TunablePropsChanged = false;
      }

      /* SampleTimeMath: '<S27>/TSamp' incorporates:
       *  MATLABSystem: '<S24>/Encoder'
       * *
       * About '<S27>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       */
      MW_EncoderRead(Final_integration_DW.obj_a.Index, &rtb_TSamp);

      /* Gain: '<S24>/Gain1' incorporates:
       *  Gain: '<S28>/Gain1'
       *  SampleTimeMath: '<S27>/TSamp'
       *  Sum: '<S27>/Diff'
       *  UnitDelay: '<S27>/UD'
       *
       * About '<S27>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S27>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S27>/UD':
       *
       *  Store in Global RAM
       */
      tmp_4 = (uint32_T)Final_integration_P.encoder_scale;
      tmp = (uint32_T)(rtb_TSamp - Final_integration_DW.UD_DSTATE);
      sMultiWordMul(&tmp_4, 1, &tmp, 1, &Final_integration_B.Gain1.chunks[0U], 2);

      /* Gain: '<S24>/Gain2' incorporates:
       *  Gain: '<S24>/Gain1'
       */
      sMultiWordMul(&Final_integration_P.Gain2_Gain.chunks[0U], 2,
                    &Final_integration_B.Gain1.chunks[0U], 2,
                    &Final_integration_B.Gain2.chunks[0U], 4);

      /* RateTransition: '<S8>/Rate Transition' incorporates:
       *  Delay: '<S46>/Delay'
       */
      Final_integration_B.RateTransition_d = Final_integration_DW.Delay_DSTATE_e;

      /* MATLABSystem: '<S28>/Encoder' */
      if (Final_integration_DW.obj.SampleTime !=
          Final_integration_P.Encoder_SampleTime_f) {
        Final_integration_DW.obj.SampleTime =
          Final_integration_P.Encoder_SampleTime_f;
      }

      if (Final_integration_DW.obj.TunablePropsChanged) {
        Final_integration_DW.obj.TunablePropsChanged = false;
      }

      /* SampleTimeMath: '<S31>/TSamp' incorporates:
       *  MATLABSystem: '<S28>/Encoder'
       * *
       * About '<S31>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       */
      MW_EncoderRead(Final_integration_DW.obj.Index, &rtb_TSamp_l);

      /* Gain: '<S28>/Gain1' incorporates:
       *  SampleTimeMath: '<S31>/TSamp'
       *  Sum: '<S31>/Diff'
       *  UnitDelay: '<S31>/UD'
       *
       * About '<S31>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S31>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S31>/UD':
       *
       *  Store in Global RAM
       */
      tmp = (uint32_T)(rtb_TSamp_l - Final_integration_DW.UD_DSTATE_k);
      sMultiWordMul(&tmp_4, 1, &tmp, 1, &Final_integration_B.Gain1_f.chunks[0U],
                    2);

      /* Gain: '<S28>/Gain2' incorporates:
       *  Gain: '<S28>/Gain1'
       */
      sMultiWordMul(&Final_integration_P.Gain2_Gain_c.chunks[0U], 2,
                    &Final_integration_B.Gain1_f.chunks[0U], 2,
                    &Final_integration_B.Gain2_k.chunks[0U], 4);

      /* MATLABSystem: '<Root>/Adas Mode Switch' */
      if (Final_integration_DW.obj_m.SampleTime !=
          Final_integration_P.AdasModeSwitch_SampleTime) {
        Final_integration_DW.obj_m.SampleTime =
          Final_integration_P.AdasModeSwitch_SampleTime;
      }

      /* MATLABSystem: '<Root>/Adas Mode Switch' */
      Final_integration_B.AdasModeSwitch = readDigitalPin(31);

      /* DiscretePulseGenerator: '<S9>/Pulse Generator' */
      rtb_Product_g = (Final_integration_DW.clockTickCounter <
                       Final_integration_P.PulseGenerator_Duty_p) &&
        (Final_integration_DW.clockTickCounter >= 0L) ?
        Final_integration_P.PulseGenerator_Amp_k : 0.0;
      if (Final_integration_DW.clockTickCounter >=
          Final_integration_P.PulseGenerator_Period_l - 1.0) {
        Final_integration_DW.clockTickCounter = 0L;
      } else {
        Final_integration_DW.clockTickCounter++;
      }

      /* End of DiscretePulseGenerator: '<S9>/Pulse Generator' */

      /* If: '<S9>/If1' */
      if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
        Final_integration_DW.If1_ActiveSubsystem = (int8_T)
          !(Final_integration_B.sw2 == 1.0);
      }

      if (Final_integration_DW.If1_ActiveSubsystem == 0) {
        /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S11>/Action Port'
         */
        /* SignalConversion generated from: '<S11>/Input' incorporates:
         *  Constant: '<S9>/Constant'
         *  Product: '<S9>/Product1'
         */
        rtb_Product_g = Final_integration_P.Constant_Value_b *
          Final_integration_B.RateTransition;
        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC(Final_integration_DW.IfActionSubsystem1_SubsysRanB_e);
        }

        /* End of Outputs for SubSystem: '<S9>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S12>/Action Port'
         */
        /* SignalConversion generated from: '<S12>/Input' incorporates:
         *  Product: '<S9>/Product'
         */
        rtb_Product_g *= Final_integration_B.RateTransition;
        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC(Final_integration_DW.IfActionSubsystem3_SubsysRanB_n);
        }

        /* End of Outputs for SubSystem: '<S9>/If Action Subsystem3' */
      }

      /* End of If: '<S9>/If1' */

      /* MATLABSystem: '<S9>/Digital Output' */
      rtb_Product_g = rt_roundd_snf(rtb_Product_g);
      if (rtb_Product_g < 256.0) {
        if (rtb_Product_g >= 0.0) {
          tmp_3 = (uint8_T)rtb_Product_g;
        } else {
          tmp_3 = 0U;
        }
      } else {
        tmp_3 = MAX_uint8_T;
      }

      writeDigitalPin(43, tmp_3);

      /* End of MATLABSystem: '<S9>/Digital Output' */

      /* If: '<S10>/If1' */
      if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
        Final_integration_DW.If1_ActiveSubsystem_c = (int8_T)
          !(Final_integration_B.RateTransition == 1.0);
      }

      if (Final_integration_DW.If1_ActiveSubsystem_c == 0) {
        /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S13>/Action Port'
         */
        Final_in_IfActionSubsystem1(&rtb_Product_g,
          &Final_integration_P.IfActionSubsystem1_k);
        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC
            (Final_integration_DW.IfActionSubsystem1_k.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S10>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S14>/Action Port'
         */
        Final_in_IfActionSubsystem1(&rtb_Product_g,
          &Final_integration_P.IfActionSubsystem3_h);
        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC
            (Final_integration_DW.IfActionSubsystem3_h.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S10>/If Action Subsystem3' */
      }

      /* End of If: '<S10>/If1' */

      /* MATLABSystem: '<S10>/Digital Output' */
      rtb_Product_g = rt_roundd_snf(rtb_Product_g);
      if (rtb_Product_g < 256.0) {
        if (rtb_Product_g >= 0.0) {
          tmp_3 = (uint8_T)rtb_Product_g;
        } else {
          tmp_3 = 0U;
        }
      } else {
        tmp_3 = MAX_uint8_T;
      }

      writeDigitalPin(42, tmp_3);

      /* End of MATLABSystem: '<S10>/Digital Output' */

      /* If: '<S7>/If' */
      if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
        Final_integration_DW.If_ActiveSubsystem_g = (int8_T)
          !(Final_integration_B.Merge9 == 1.0);
      }

      if (Final_integration_DW.If_ActiveSubsystem_g == 0) {
        /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem' incorporates:
         *  ActionPort: '<S44>/Action Port'
         */
        /* Merge: '<S7>/Merge' incorporates:
         *  DiscretePulseGenerator: '<S44>/Pulse Generator'
         */
        rtb_Product_g = (Final_integration_DW.clockTickCounter_j <
                         Final_integration_P.PulseGenerator_Duty) &&
          (Final_integration_DW.clockTickCounter_j >= 0L) ?
          Final_integration_P.PulseGenerator_Amp : 0.0;

        /* DiscretePulseGenerator: '<S44>/Pulse Generator' */
        if (Final_integration_DW.clockTickCounter_j >=
            Final_integration_P.PulseGenerator_Period - 1.0) {
          Final_integration_DW.clockTickCounter_j = 0L;
        } else {
          Final_integration_DW.clockTickCounter_j++;
        }

        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_j);
        }

        /* End of Outputs for SubSystem: '<S7>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S45>/Action Port'
         */
        Final_in_IfActionSubsystem1(&rtb_Product_g,
          &Final_integration_P.IfActionSubsystem1_g);
        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC
            (Final_integration_DW.IfActionSubsystem1_g.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S7>/If Action Subsystem1' */
      }

      /* End of If: '<S7>/If' */

      /* MATLABSystem: '<S7>/PWM' */
      Final_integration_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);

      /* Start for MATLABSystem: '<S7>/PWM' */
      if (!(rtb_Product_g <= 255.0)) {
        rtb_Product_g = 255.0;
      }

      if (!(rtb_Product_g >= 0.0)) {
        rtb_Product_g = 0.0;
      }

      /* MATLABSystem: '<S7>/PWM' */
      MW_PWM_SetDutyCycle(Final_integration_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE,
                          rtb_Product_g);

      /* Delay: '<S1>/Delay' */
      Final_integration_B.Delay = Final_integration_DW.Delay_DSTATE;

      /* MATLABSystem: '<Root>/조도센서 Input' */
      if (Final_integration_DW.obj_ld.SampleTime !=
          Final_integration_P.Input_SampleTime) {
        Final_integration_DW.obj_ld.SampleTime =
          Final_integration_P.Input_SampleTime;
      }

      Final_integration_DW.obj_ld.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(55UL);
      MW_AnalogInSingle_ReadResult
        (Final_integration_DW.obj_ld.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
         &b_varargout_1, MW_ANALOGIN_UINT16);

      /* Gain: '<S1>/Gain' incorporates:
       *  MATLABSystem: '<Root>/조도센서 Input'
       * */
      rtb_Gain_l = (uint32_T)Final_integration_P.Gain_Gain_o * b_varargout_1;

      /* Delay: '<S3>/Delay' */
      Final_integration_B.Delay_j = Final_integration_DW.Delay_DSTATE_m;

      /* DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn' */
      Final_integration_B.DiscreteTransferFcn = tmp_5;

      /* DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn' */
      tmp_4 = (uint32_T)Final_integration_P.num_Gd[1L];
      tmp = (uint32_T)Final_integration_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp_4, 1, &tmp, 1,
                    &Final_integration_B.DiscreteTransferFcn.chunks[0U], 2);

      /* Sum: '<S4>/Add3' incorporates:
       *  DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn'
       */
      Final_integration_B.Add3 = sMultiWord2Double
        (&Final_integration_B.DiscreteTransferFcn.chunks[0U], 2, 0) *
        1.1641532182693481E-10 + Final_integration_B.Merge7;

      /* Gain: '<S26>/Gain4' */
      Final_integration_B.Gain4 = Final_integration_P.KP *
        Final_integration_B.Add3;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/Drive Mode Switch' */

    /* Sum: '<S26>/Add4' incorporates:
     *  TransferFcn: '<S26>/Transfer Fcn1'
     */
    Final_integration_B.Add4 = Final_integration_P.TransferFcn1_C *
      Final_integration_X.TransferFcn1_CSTATE + Final_integration_B.Gain4;

    /* Saturate: '<S4>/Saturation1' */
    if (Final_integration_B.Add4 > Final_integration_P.Saturation1_UpperSat) {
      /* Saturate: '<S4>/Saturation1' */
      Final_integration_B.Saturation1 = Final_integration_P.Saturation1_UpperSat;
    } else if (Final_integration_B.Add4 <
               Final_integration_P.Saturation1_LowerSat) {
      /* Saturate: '<S4>/Saturation1' */
      Final_integration_B.Saturation1 = Final_integration_P.Saturation1_LowerSat;
    } else {
      /* Saturate: '<S4>/Saturation1' */
      Final_integration_B.Saturation1 = Final_integration_B.Add4;
    }

    /* End of Saturate: '<S4>/Saturation1' */

    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant9'
     */
    if (Final_integration_B.Saturation1 > Final_integration_P.Switch_Threshold)
    {
      rtb_Product_g = Final_integration_B.Saturation1;
    } else {
      rtb_Product_g = Final_integration_P.Constant9_Value_g;
    }

    /* DataTypeConversion: '<S25>/Data Type Conversion' incorporates:
     *  Gain: '<S25>/Gain1'
     *  Switch: '<S4>/Switch'
     */
    rtb_Product_g = floor(255.0 / Final_integration_P.Vlim * rtb_Product_g);
    if (rtIsNaN(rtb_Product_g) || rtIsInf(rtb_Product_g)) {
      rtb_Product_g = 0.0;
    } else {
      rtb_Product_g = fmod(rtb_Product_g, 256.0);
    }

    /* DataTypeConversion: '<S25>/Data Type Conversion' */
    Final_integration_B.DataTypeConversion = (uint8_T)(rtb_Product_g < 0.0 ?
      (int16_T)(uint8_T)-(int8_T)(uint8_T)-rtb_Product_g : (int16_T)(uint8_T)
      rtb_Product_g);

    /* DataTypeConversion: '<S25>/Data Type Conversion1' */
    Final_integration_B.DataTypeConversion1 =
      Final_integration_B.DataTypeConversion;
    if (rtmIsMajorTimeStep(Final_integration_M)) {
      /* DataTypeConversion: '<S24>/Data Type Conversion1' incorporates:
       *  Gain: '<S24>/Gain1'
       */
      sMultiWordMul(&Final_integration_B.Gain1.chunks[0U], 2, &tmp_6.chunks[0U],
                    2, &Final_integration_B.r2.chunks[0U], 4);
      sMultiWordShr(&Final_integration_B.r2.chunks[0U], 4, 31U,
                    &Final_integration_B.r1.chunks[0U], 4);

      /* DataTypeConversion: '<S24>/Data Type Conversion1' */
      Final_integration_B.DataTypeConversion1_i = MultiWord2sLong
        (&Final_integration_B.r1.chunks[0U]);
    }

    /* MATLABSystem: '<S25>/PWM' */
    Final_integration_DW.obj_ma.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (11UL);
    MW_PWM_SetDutyCycle(Final_integration_DW.obj_ma.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)Final_integration_B.DataTypeConversion);
    if (rtmIsMajorTimeStep(Final_integration_M)) {
      /* MATLABSystem: '<S4>/Digital Output' incorporates:
       *  Constant: '<S4>/Constant'
       */
      rtb_Product_g = rt_roundd_snf(Final_integration_P.Constant_Value_oh);
      if (rtb_Product_g < 256.0) {
        if (rtb_Product_g >= 0.0) {
          tmp_3 = (uint8_T)rtb_Product_g;
        } else {
          tmp_3 = 0U;
        }
      } else {
        tmp_3 = MAX_uint8_T;
      }

      writeDigitalPin(13, tmp_3);

      /* End of MATLABSystem: '<S4>/Digital Output' */

      /* DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn' */
      Final_integration_B.DiscreteTransferFcn_d = tmp_5;

      /* DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn' */
      tmp_4 = (uint32_T)Final_integration_P.num_Gd[1L];
      tmp = (uint32_T)Final_integration_DW.DiscreteTransferFcn_states_l;
      sMultiWordMul(&tmp_4, 1, &tmp, 1,
                    &Final_integration_B.DiscreteTransferFcn_d.chunks[0U], 2);

      /* Sum: '<S5>/Add5' incorporates:
       *  DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn'
       */
      Final_integration_B.Add5 = Final_integration_B.Merge8 - sMultiWord2Double(
        &Final_integration_B.DiscreteTransferFcn_d.chunks[0U], 2, 0) *
        1.1641532182693481E-10;

      /* Gain: '<S30>/Gain4' */
      Final_integration_B.Gain4_n = Final_integration_P.KP *
        Final_integration_B.Add5;
    }

    /* Sum: '<S30>/Add4' incorporates:
     *  TransferFcn: '<S30>/Transfer Fcn1'
     */
    Final_integration_B.Add4_g = Final_integration_P.TransferFcn1_C_o *
      Final_integration_X.TransferFcn1_CSTATE_j + Final_integration_B.Gain4_n;

    /* Saturate: '<S5>/Saturation2' */
    if (Final_integration_B.Add4_g > Final_integration_P.Saturation2_UpperSat) {
      /* Saturate: '<S5>/Saturation2' */
      Final_integration_B.Saturation2 = Final_integration_P.Saturation2_UpperSat;
    } else if (Final_integration_B.Add4_g <
               Final_integration_P.Saturation2_LowerSat) {
      /* Saturate: '<S5>/Saturation2' */
      Final_integration_B.Saturation2 = Final_integration_P.Saturation2_LowerSat;
    } else {
      /* Saturate: '<S5>/Saturation2' */
      Final_integration_B.Saturation2 = Final_integration_B.Add4_g;
    }

    /* End of Saturate: '<S5>/Saturation2' */

    /* Switch: '<S5>/Switch1' incorporates:
     *  Constant: '<S5>/Constant16'
     */
    if (Final_integration_B.Saturation2 > Final_integration_P.Switch1_Threshold)
    {
      rtb_Product_g = Final_integration_B.Saturation2;
    } else {
      rtb_Product_g = Final_integration_P.Constant16_Value;
    }

    /* DataTypeConversion: '<S29>/Data Type Conversion' incorporates:
     *  Gain: '<S29>/Gain1'
     *  Switch: '<S5>/Switch1'
     */
    rtb_Product_g = floor(255.0 / Final_integration_P.Vlim * rtb_Product_g);
    if (rtIsNaN(rtb_Product_g) || rtIsInf(rtb_Product_g)) {
      rtb_Product_g = 0.0;
    } else {
      rtb_Product_g = fmod(rtb_Product_g, 256.0);
    }

    /* DataTypeConversion: '<S29>/Data Type Conversion' */
    Final_integration_B.DataTypeConversion_c = (uint8_T)(rtb_Product_g < 0.0 ?
      (int16_T)(uint8_T)-(int8_T)(uint8_T)-rtb_Product_g : (int16_T)(uint8_T)
      rtb_Product_g);

    /* DataTypeConversion: '<S29>/Data Type Conversion1' */
    Final_integration_B.DataTypeConversion1_c =
      Final_integration_B.DataTypeConversion_c;
    if (rtmIsMajorTimeStep(Final_integration_M)) {
      /* DataTypeConversion: '<S28>/Data Type Conversion1' incorporates:
       *  Gain: '<S28>/Gain1'
       */
      sMultiWordMul(&Final_integration_B.Gain1_f.chunks[0U], 2, &tmp_6.chunks[0U],
                    2, &tmp_0.chunks[0U], 4);
      sMultiWordShr(&tmp_0.chunks[0U], 4, 31U, &Final_integration_B.r2.chunks[0U],
                    4);

      /* DataTypeConversion: '<S28>/Data Type Conversion1' */
      Final_integration_B.DataTypeConversion1_e = MultiWord2sLong
        (&Final_integration_B.r2.chunks[0U]);
    }

    /* MATLABSystem: '<S29>/PWM' */
    Final_integration_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
    MW_PWM_SetDutyCycle(Final_integration_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)Final_integration_B.DataTypeConversion_c);
    if (rtmIsMajorTimeStep(Final_integration_M)) {
      /* DiscretePulseGenerator: '<S50>/Pulse Generator' */
      rtb_Product_g = (Final_integration_DW.clockTickCounter_k <
                       Final_integration_P.PulseGenerator_Duty_l) &&
        (Final_integration_DW.clockTickCounter_k >= 0L) ?
        Final_integration_P.PulseGenerator_Amp_f : 0.0;
      if (Final_integration_DW.clockTickCounter_k >=
          Final_integration_P.PulseGenerator_Period_e - 1.0) {
        Final_integration_DW.clockTickCounter_k = 0L;
      } else {
        Final_integration_DW.clockTickCounter_k++;
      }

      /* End of DiscretePulseGenerator: '<S50>/Pulse Generator' */

      /* If: '<S50>/If' incorporates:
       *  Constant: '<S50>/Constant'
       *  Constant: '<S50>/Constant1'
       */
      rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
        if (Final_integration_B.RateTransition_d == 0.0) {
          rtAction = 0;
        } else if (Final_integration_B.RateTransition_d == 1.0) {
          rtAction = 1;
        } else if (Final_integration_B.RateTransition_d == 2.0) {
          rtAction = 2;
        }

        Final_integration_DW.If_ActiveSubsystem_b = rtAction;
      } else {
        rtAction = Final_integration_DW.If_ActiveSubsystem_b;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem' incorporates:
         *  ActionPort: '<S51>/Action Port'
         */
        Final_int_IfActionSubsystem(Final_integration_P.Constant1_Value_m,
          &Final_integration_B.Merge, &Final_integration_B.Merge1);
        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC
            (Final_integration_DW.IfActionSubsystem_a.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S50>/If Action Subsystem' */
        break;

       case 1:
        /* Gain: '<S50>/Gain' incorporates:
         *  Gain: '<S1>/Gain'
         */
        uMultiWordMul(&Final_integration_P.Gain_Gain_c, 1, &rtb_Gain_l, 1,
                      &tmp_2.chunks[0U], 2);

        /* DataTypeConversion: '<S50>/Data Type Conversion' */
        uMultiWordShr(&tmp_2.chunks[0U], 2, 42U, &tmp_1.chunks[0U], 2);

        /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S52>/Action Port'
         */
        /* If: '<S52>/If' incorporates:
         *  DataTypeConversion: '<S50>/Data Type Conversion'
         */
        if ((uint8_T)MultiWord2uLong(&tmp_1.chunks[0U]) <= 34) {
          /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem' incorporates:
           *  ActionPort: '<S54>/Action Port'
           */
          /* Merge: '<S50>/Merge' incorporates:
           *  Constant: '<S52>/Constant'
           *  SignalConversion generated from: '<S54>/In1'
           */
          Final_integration_B.Merge = Final_integration_P.Constant_Value_e;

          /* End of Outputs for SubSystem: '<S52>/If Action Subsystem' */

          /* Update for IfAction SubSystem: '<S52>/If Action Subsystem' incorporates:
           *  ActionPort: '<S54>/Action Port'
           */
          /* Update for If: '<S52>/If' */
          srUpdateBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC);

          /* End of Update for SubSystem: '<S52>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          /* Merge: '<S50>/Merge' incorporates:
           *  Constant: '<S52>/Constant1'
           *  SignalConversion generated from: '<S55>/In1'
           */
          Final_integration_B.Merge = Final_integration_P.Constant1_Value_l;

          /* End of Outputs for SubSystem: '<S52>/If Action Subsystem1' */

          /* Update for IfAction SubSystem: '<S52>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          /* Update for If: '<S52>/If' */
          srUpdateBC(Final_integration_DW.IfActionSubsystem1_SubsysRanB_l);

          /* End of Update for SubSystem: '<S52>/If Action Subsystem1' */
        }

        /* End of If: '<S52>/If' */

        /* Merge: '<S50>/Merge1' incorporates:
         *  SignalConversion generated from: '<S52>/In1'
         */
        Final_integration_B.Merge1 = rtb_Product_g;
        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC(Final_integration_DW.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S50>/If Action Subsystem1' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S53>/Action Port'
         */
        Final_int_IfActionSubsystem(Final_integration_P.Constant_Value_m4,
          &Final_integration_B.Merge, &Final_integration_B.Merge1);
        if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
          srUpdateBC
            (Final_integration_DW.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S50>/If Action Subsystem2' */
        break;
      }

      /* End of If: '<S50>/If' */

      /* MATLABSystem: '<S50>/Digital Output' */
      rtb_Product_g = rt_roundd_snf(Final_integration_B.Merge);
      if (rtb_Product_g < 256.0) {
        if (rtb_Product_g >= 0.0) {
          tmp_3 = (uint8_T)rtb_Product_g;
        } else {
          tmp_3 = 0U;
        }
      } else {
        tmp_3 = MAX_uint8_T;
      }

      writeDigitalPin(44, tmp_3);

      /* End of MATLABSystem: '<S50>/Digital Output' */

      /* MATLABSystem: '<S50>/Digital Output1' */
      rtb_Product_g = rt_roundd_snf(Final_integration_B.Merge1);
      if (rtb_Product_g < 256.0) {
        if (rtb_Product_g >= 0.0) {
          tmp_3 = (uint8_T)rtb_Product_g;
        } else {
          tmp_3 = 0U;
        }
      } else {
        tmp_3 = MAX_uint8_T;
      }

      writeDigitalPin(45, tmp_3);

      /* End of MATLABSystem: '<S50>/Digital Output1' */

      /* RateTransition generated from: '<S8>/If Action Subsystem' */
      if (Final_integration_M->Timing.RateInteraction.TID1_2) {
        Final_integration_DW.TmpRTBAtIfActionSubsystemInport =
          Final_integration_B.RateTransition;
      }

      /* End of RateTransition generated from: '<S8>/If Action Subsystem' */

      /* MATLABSystem: '<Root>/조도센서 Switch' */
      if (Final_integration_DW.obj_l.SampleTime !=
          Final_integration_P.Switch_SampleTime) {
        Final_integration_DW.obj_l.SampleTime =
          Final_integration_P.Switch_SampleTime;
      }

      /* MATLABSystem: '<Root>/조도센서 Switch' */
      Final_integration_B.Switch = readDigitalPin(36);
    }
  }

  if (rtmIsMajorTimeStep(Final_integration_M)) {
    int64m_T denAccum;
    int64m_T denAccum_0;
    int64m_T tmp;
    int64m_T tmp_1;
    int64m_T tmp_2;
    int64m_T tmp_3;
    uint32_T tmp_0;
    uint32_T tmp_4;
    static const int64m_T tmp_5 = { { MAX_uint32_T, 2147483647UL }/* chunks */
    };

    static const int64m_T tmp_6 = { { 0UL, 0UL }/* chunks */
    };

    static const int64m_T tmp_7 = { { 0UL, 2147483648UL }/* chunks */
    };

    if (rtmIsMajorTimeStep(Final_integration_M)) {
      /* Update for UnitDelay: '<S27>/UD' incorporates:
       *  SampleTimeMath: '<S27>/TSamp'
       *
       * About '<S27>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S27>/UD':
       *
       *  Store in Global RAM
       */
      Final_integration_DW.UD_DSTATE = rtb_TSamp;

      /* Update for UnitDelay: '<S31>/UD' incorporates:
       *  SampleTimeMath: '<S31>/TSamp'
       *
       * About '<S31>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S31>/UD':
       *
       *  Store in Global RAM
       */
      Final_integration_DW.UD_DSTATE_k = rtb_TSamp_l;

      /* Update for Delay: '<S1>/Delay' */
      Final_integration_DW.Delay_DSTATE = Final_integration_B.RateTransition_d;

      /* Update for Delay: '<S3>/Delay' */
      Final_integration_DW.Delay_DSTATE_m = Final_integration_B.sw2;

      /* Update for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn' incorporates:
       *  DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn'
       */
      sLong2MultiWord(Final_integration_B.DataTypeConversion1_i, &tmp.chunks[0U],
                      2);
      sMultiWordShl(&tmp.chunks[0U], 2, 30U,
                    &Final_integration_B.denAccum.chunks[0U], 2);
      tmp_4 = (uint32_T)Final_integration_P.den_Gd[1L];
      tmp_0 = (uint32_T)Final_integration_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp_4, 1, &tmp_0, 1, &tmp.chunks[0U], 2);
      MultiWordSub(&Final_integration_B.denAccum.chunks[0U], &tmp.chunks[0U],
                   &denAccum.chunks[0U], 2);
      Final_integration_B.denAccum = denAccum;
      if (Final_integration_P.den_Gd[0] == 0L) {
        if (sMultiWordGe(&Final_integration_B.denAccum.chunks[0U],
                         &tmp_6.chunks[0U], 2)) {
          Final_integration_B.r9 = tmp_5;
        } else {
          Final_integration_B.r9 = tmp_7;
        }
      } else {
        sMultiWord2MultiWord(&Final_integration_B.denAccum.chunks[0U], 2,
                             &Final_integration_B.r4.chunks[0U], 3);
        sMultiWordShl(&Final_integration_B.r4.chunks[0U], 3, 30U,
                      &Final_integration_B.r3.chunks[0U], 3);
        sLong2MultiWord(Final_integration_P.den_Gd[0],
                        &Final_integration_B.r4.chunks[0U], 3);
        sMultiWordDivFloor(&Final_integration_B.r3.chunks[0U], 3,
                           &Final_integration_B.r4.chunks[0U], 3,
                           &Final_integration_B.r.chunks[0U], 4,
                           &Final_integration_B.r5.chunks[0U], 3,
                           &Final_integration_B.r6.chunks[0U], 3,
                           &Final_integration_B.r7.chunks[0U], 3);
        sMultiWord2MultiWord(&Final_integration_B.r.chunks[0U], 4,
                             &Final_integration_B.r9.chunks[0U], 2);
      }

      sMultiWordShr(&Final_integration_B.r9.chunks[0U], 2, 30U, &tmp_1.chunks[0U],
                    2);
      Final_integration_DW.DiscreteTransferFcn_states = MultiWord2sLong
        (&tmp_1.chunks[0U]);

      /* End of Update for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn' */

      /* Update for DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn' */
      sLong2MultiWord(Final_integration_B.DataTypeConversion1_e, &tmp_2.chunks
                      [0U], 2);
      sMultiWordShl(&tmp_2.chunks[0U], 2, 30U,
                    &Final_integration_B.denAccum.chunks[0U], 2);
      tmp_0 = (uint32_T)Final_integration_DW.DiscreteTransferFcn_states_l;
      sMultiWordMul(&tmp_4, 1, &tmp_0, 1, &tmp_2.chunks[0U], 2);
      MultiWordSub(&Final_integration_B.denAccum.chunks[0U], &tmp_2.chunks[0U],
                   &denAccum_0.chunks[0U], 2);
      if (Final_integration_P.den_Gd[0] == 0L) {
        if (sMultiWordGe(&denAccum_0.chunks[0U], &tmp_6.chunks[0U], 2)) {
          Final_integration_B.r8 = tmp_5;
        } else {
          Final_integration_B.r8 = tmp_7;
        }
      } else {
        sMultiWord2MultiWord(&denAccum_0.chunks[0U], 2,
                             &Final_integration_B.r4.chunks[0U], 3);
        sMultiWordShl(&Final_integration_B.r4.chunks[0U], 3, 30U,
                      &Final_integration_B.r3.chunks[0U], 3);
        sLong2MultiWord(Final_integration_P.den_Gd[0],
                        &Final_integration_B.r4.chunks[0U], 3);
        sMultiWordDivFloor(&Final_integration_B.r3.chunks[0U], 3,
                           &Final_integration_B.r4.chunks[0U], 3,
                           &Final_integration_B.r.chunks[0U], 4,
                           &Final_integration_B.r5.chunks[0U], 3,
                           &Final_integration_B.r6.chunks[0U], 3,
                           &Final_integration_B.r7.chunks[0U], 3);
        sMultiWord2MultiWord(&Final_integration_B.r.chunks[0U], 4,
                             &Final_integration_B.r8.chunks[0U], 2);
      }

      sMultiWordShr(&Final_integration_B.r8.chunks[0U], 2, 30U, &tmp_3.chunks[0U],
                    2);
      Final_integration_DW.DiscreteTransferFcn_states_l = MultiWord2sLong
        (&tmp_3.chunks[0U]);
    }

    {
      extmodeErrorCode_T returnCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentSimTime = (extmodeSimulationTime_T)
        ((Final_integration_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      returnCode = extmodeEvent(1,currentSimTime);
      if (returnCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Final_integration_M)) {
    rt_ertODEUpdateContinuousStates(&Final_integration_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Final_integration_M->Timing.clockTick0;
    Final_integration_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Final_integration_M->solverInfo);
    switch (Final_integration_M->Timing.rtmDbBufReadBuf3) {
     case 0:
      Final_integration_M->Timing.rtmDbBufWriteBuf3 = 1;
      break;

     case 1:
      Final_integration_M->Timing.rtmDbBufWriteBuf3 = 0;
      break;

     default:
      Final_integration_M->Timing.rtmDbBufWriteBuf3 =
        !Final_integration_M->Timing.rtmDbBufLastBufWr3;
      break;
    }

    Final_integration_M->Timing.rtmDbBufClockTick3
      [Final_integration_M->Timing.rtmDbBufWriteBuf3] =
      Final_integration_M->Timing.clockTick0;
    Final_integration_M->Timing.rtmDbBufLastBufWr3 =
      Final_integration_M->Timing.rtmDbBufWriteBuf3;
    Final_integration_M->Timing.rtmDbBufWriteBuf3 = 0xFF;

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Final_integration_M->Timing.clockTick1++;
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Final_integration_derivatives(void)
{
  XDot_Final_integration_T *_rtXdot;
  _rtXdot = ((XDot_Final_integration_T *) Final_integration_M->derivs);

  /* Derivatives for TransferFcn: '<S26>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = Final_integration_P.TransferFcn1_A *
    Final_integration_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += Final_integration_B.Add3;

  /* Derivatives for TransferFcn: '<S30>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_j = Final_integration_P.TransferFcn1_A_o *
    Final_integration_X.TransferFcn1_CSTATE_j;
  _rtXdot->TransferFcn1_CSTATE_j += Final_integration_B.Add5;
}

/* Model step function for TID2 */
void Final_integration_step2(void)     /* Sample time: [0.2s, 0.0s] */
{
  real_T rtb_Plus;
  int8_T rtAction;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_DW.IfActionSubsystem1_SubsysRan_dx);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_a);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_DW.IfActionSubsystem1_SubsysRanB_m);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_m);

  /* If: '<S15>/If' */
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
    if (!Final_integration_B.AdasModeSwitch) {
      rtAction = 0;
    }

    Final_integration_DW.If_ActiveSubsystem_a = rtAction;
  } else {
    rtAction = Final_integration_DW.If_ActiveSubsystem_a;
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S15>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Sum: '<S18>/Sum' incorporates:
     *  Constant: '<S18>/Constant2'
     *  Delay: '<S18>/Delay1'
     */
    Final_integration_DW.Delay1_DSTATE += Final_integration_P.Constant2_Value_g;

    /* Math: '<S18>/Mod1' incorporates:
     *  Constant: '<S18>/Constant3'
     *  Delay: '<S18>/Delay1'
     */
    Final_integration_B.Mod1 = rt_modd_snf(Final_integration_DW.Delay1_DSTATE,
      Final_integration_P.Constant3_Value);
    if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
      srUpdateBC(Final_integration_DW.IfActionSubsystem1_SubsysRan_dx);
    }

    /* End of Outputs for SubSystem: '<S15>/If Action Subsystem1' */
  }

  /* End of If: '<S15>/If' */

  /* If: '<S8>/If' */
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
    if (!Final_integration_B.Switch) {
      rtAction = 0;
    }

    Final_integration_DW.If_ActiveSubsystem_p = rtAction;
  } else {
    rtAction = Final_integration_DW.If_ActiveSubsystem_p;
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S8>/If Action Subsystem' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    /* If: '<S46>/If' incorporates:
     *  RateTransition generated from: '<S8>/If Action Subsystem'
     */
    if (Final_integration_DW.TmpRTBAtIfActionSubsystemInport == 1.0) {
      /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      /* SignalConversion generated from: '<S48>/In1' incorporates:
       *  Constant: '<S46>/Constant'
       */
      rtb_Plus = Final_integration_P.Constant_Value_ou;

      /* End of Outputs for SubSystem: '<S46>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      /* Update for If: '<S46>/If' */
      srUpdateBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_a);

      /* End of Update for SubSystem: '<S46>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S49>/Action Port'
       */
      /* SignalConversion generated from: '<S49>/In1' incorporates:
       *  Constant: '<S46>/Constant2'
       */
      rtb_Plus = Final_integration_P.Constant2_Value_i;

      /* End of Outputs for SubSystem: '<S46>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S49>/Action Port'
       */
      /* Update for If: '<S46>/If' */
      srUpdateBC(Final_integration_DW.IfActionSubsystem1_SubsysRanB_m);

      /* End of Update for SubSystem: '<S46>/If Action Subsystem1' */
    }

    /* End of If: '<S46>/If' */

    /* Math: '<S46>/Mod' incorporates:
     *  Constant: '<S46>/Constant1'
     *  Delay: '<S46>/Delay'
     *  Sum: '<S46>/Plus'
     */
    Final_integration_DW.Delay_DSTATE_e = rt_modd_snf(rtb_Plus +
      Final_integration_DW.Delay_DSTATE_e, Final_integration_P.Constant1_Value_c);
    if (rtsiIsModeUpdateTimeStep(&Final_integration_M->solverInfo)) {
      srUpdateBC(Final_integration_DW.IfActionSubsystem_SubsysRanBC_m);
    }

    /* End of Outputs for SubSystem: '<S8>/If Action Subsystem' */
  }

  /* End of If: '<S8>/If' */

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Final_integration_M->Timing.clockTick2++;
}

/* Model initialize function */
void Final_integration_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Final_integration_M->solverInfo,
                          &Final_integration_M->Timing.simTimeStep);
    rtsiSetTPtr(&Final_integration_M->solverInfo, &rtmGetTPtr
                (Final_integration_M));
    rtsiSetStepSizePtr(&Final_integration_M->solverInfo,
                       &Final_integration_M->Timing.stepSize0);
    rtsiSetdXPtr(&Final_integration_M->solverInfo, &Final_integration_M->derivs);
    rtsiSetContStatesPtr(&Final_integration_M->solverInfo, (real_T **)
                         &Final_integration_M->contStates);
    rtsiSetNumContStatesPtr(&Final_integration_M->solverInfo,
      &Final_integration_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Final_integration_M->solverInfo,
      &Final_integration_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Final_integration_M->solverInfo,
      &Final_integration_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Final_integration_M->solverInfo,
      &Final_integration_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&Final_integration_M->solverInfo, (boolean_T**)
      &Final_integration_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&Final_integration_M->solverInfo, (&rtmGetErrorStatus
      (Final_integration_M)));
    rtsiSetRTModelPtr(&Final_integration_M->solverInfo, Final_integration_M);
  }

  rtsiSetSimTimeStep(&Final_integration_M->solverInfo, MAJOR_TIME_STEP);
  Final_integration_M->intgData.y = Final_integration_M->odeY;
  Final_integration_M->intgData.f[0] = Final_integration_M->odeF[0];
  Final_integration_M->intgData.f[1] = Final_integration_M->odeF[1];
  Final_integration_M->intgData.f[2] = Final_integration_M->odeF[2];
  Final_integration_M->contStates = ((X_Final_integration_T *)
    &Final_integration_X);
  Final_integration_M->contStateDisabled = ((XDis_Final_integration_T *)
    &Final_integration_XDis);
  Final_integration_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&Final_integration_M->solverInfo, (void *)
                    &Final_integration_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Final_integration_M->solverInfo, false);
  rtsiSetSolverName(&Final_integration_M->solverInfo,"ode3");
  rtmSetTPtr(Final_integration_M, &Final_integration_M->Timing.tArray[0]);
  rtmSetTFinal(Final_integration_M, -1);
  Final_integration_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Final_integration_M->Sizes.checksums[0] = (1458370950U);
  Final_integration_M->Sizes.checksums[1] = (1018908455U);
  Final_integration_M->Sizes.checksums[2] = (123397335U);
  Final_integration_M->Sizes.checksums[3] = (3963255086U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[47];
    Final_integration_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem1_SubsysRanB_e;
    systemRan[4] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem3_SubsysRanB_n;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem1_k.IfActionSubsystem1_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem3_h.IfActionSubsystem1_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem_SubsysRanBC_n;
    systemRan[9] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem1_SubsysRan_dx;
    systemRan[10] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem_SubsysRanB_al;
    systemRan[11] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem_SubsysRanBC_g;
    systemRan[12] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem1_SubsysRan_l2;
    systemRan[13] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem1_SubsysRanB_a;
    systemRan[14] = (sysRanDType *)&Final_integration_DW.SW1_SubsysRanBC;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem10_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem_SubsysRanBC_c;
    systemRan[22] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem_SubsysRanBC_f;
    systemRan[23] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem1_SubsysRanB_d;
    systemRan[24] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem2_SubsysRanB_l;
    systemRan[25] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem3_SubsysRanB_p;
    systemRan[26] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem1_SubsysRanB_p;
    systemRan[27] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem3_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem11_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem9_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem_SubsysRanBC_j;
    systemRan[32] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem1_g.IfActionSubsystem1_SubsysRanBC;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem_SubsysRanBC_a;
    systemRan[35] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem1_SubsysRanB_m;
    systemRan[36] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem_SubsysRanBC_m;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem_a.IfActionSubsystem_SubsysRanBC;
    systemRan[40] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[41] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem1_SubsysRanB_l;
    systemRan[42] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &Final_integration_DW.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Final_integration_M->extModeInfo,
      &Final_integration_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Final_integration_M->extModeInfo,
                        Final_integration_M->Sizes.checksums);
    rteiSetTPtr(Final_integration_M->extModeInfo, rtmGetTPtr(Final_integration_M));
  }

  Final_integration_M->Timing.rtmDbBufReadBuf3 = 0xFF;
  Final_integration_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
  Final_integration_M->Timing.rtmDbBufLastBufWr3 = 0;

  /* Start for If: '<S3>/If' */
  Final_integration_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<S32>/If3' */
  Final_integration_DW.If3_ActiveSubsystem = -1;

  /* Start for If: '<S9>/If1' */
  Final_integration_DW.If1_ActiveSubsystem = -1;

  /* Start for If: '<S10>/If1' */
  Final_integration_DW.If1_ActiveSubsystem_c = -1;

  /* Start for If: '<S7>/If' */
  Final_integration_DW.If_ActiveSubsystem_g = -1;

  /* Start for If: '<S50>/If' */
  Final_integration_DW.If_ActiveSubsystem_b = -1;

  /* Start for If: '<S15>/If' */
  Final_integration_DW.If_ActiveSubsystem_a = -1;

  /* Start for If: '<S8>/If' */
  Final_integration_DW.If_ActiveSubsystem_p = -1;

  /* InitializeConditions for UnitDelay: '<S27>/UD'
   *
   * Block description for '<S27>/UD':
   *
   *  Store in Global RAM
   */
  Final_integration_DW.UD_DSTATE =
    Final_integration_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S31>/UD'
   *
   * Block description for '<S31>/UD':
   *
   *  Store in Global RAM
   */
  Final_integration_DW.UD_DSTATE_k =
    Final_integration_P.DiscreteDerivative_ICPrevScal_j;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  Final_integration_DW.Delay_DSTATE =
    Final_integration_P.Delay_InitialCondition_k;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  Final_integration_DW.Delay_DSTATE_m =
    Final_integration_P.Delay_InitialCondition_g;

  /* InitializeConditions for TransferFcn: '<S26>/Transfer Fcn1' */
  Final_integration_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn' */
  Final_integration_DW.DiscreteTransferFcn_states =
    Final_integration_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for TransferFcn: '<S30>/Transfer Fcn1' */
  Final_integration_X.TransferFcn1_CSTATE_j = 0.0;

  /* InitializeConditions for DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn' */
  Final_integration_DW.DiscreteTransferFcn_states_l =
    Final_integration_P.DiscreteTransferFcn_InitialSt_b;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/Drive Mode Switch' incorporates:
   *  SubSystem: '<S16>/SW1'
   */
  /* System initialize for function-call system: '<S16>/SW1' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (Final_integration_M->Timing.rtmDbBufWriteBuf3) {
   case 0:
    Final_integration_M->Timing.rtmDbBufReadBuf3 = 1;
    break;

   case 1:
    Final_integration_M->Timing.rtmDbBufReadBuf3 = 0;
    break;

   default:
    Final_integration_M->Timing.rtmDbBufReadBuf3 =
      Final_integration_M->Timing.rtmDbBufLastBufWr3;
    break;
  }

  Final_integration_M->Timing.clockTick3 =
    Final_integration_M->Timing.rtmDbBufClockTick3
    [Final_integration_M->Timing.rtmDbBufReadBuf3];
  Final_integration_M->Timing.rtmDbBufReadBuf3 = 0xFF;

  /* InitializeConditions for Delay: '<S19>/Delay' */
  Final_integration_DW.Delay_DSTATE_p =
    Final_integration_P.Delay_InitialCondition;

  /* SystemInitialize for Merge: '<S19>/Merge' */
  Final_integration_B.Merge_h = Final_integration_P.Merge_InitialOutput;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, RISING);

  /* SystemInitialize for IfAction SubSystem: '<S15>/If Action Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S17>/sw2' incorporates:
   *  Outport: '<S17>/ADAS_state'
   */
  Final_integration_B.sw2 = Final_integration_P.ADAS_state_Y0;

  /* End of SystemInitialize for SubSystem: '<S15>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S15>/If Action Subsystem1' */
  /* InitializeConditions for Delay: '<S18>/Delay1' */
  Final_integration_DW.Delay1_DSTATE =
    Final_integration_P.Delay1_InitialCondition;

  /* SystemInitialize for Math: '<S18>/Mod1' incorporates:
   *  Outport: '<S18>/sw2'
   */
  Final_integration_B.Mod1 = Final_integration_P.sw2_Y0;

  /* End of SystemInitialize for SubSystem: '<S15>/If Action Subsystem1' */
  /* SystemInitialize for IfAction SubSystem: '<S8>/If Action Subsystem' */
  /* SystemInitialize for Outport: '<S46>/light_mode' incorporates:
   *  Delay: '<S46>/Delay'
   *  Math: '<S46>/Mod'
   */
  Final_integration_DW.Delay_DSTATE_e = Final_integration_P.light_mode_Y0;

  /* End of SystemInitialize for SubSystem: '<S8>/If Action Subsystem' */

  /* SystemInitialize for Merge: '<S50>/Merge' */
  Final_integration_B.Merge = Final_integration_P.Merge_InitialOutput_f;

  /* SystemInitialize for Merge: '<S50>/Merge1' */
  Final_integration_B.Merge1 = Final_integration_P.Merge1_InitialOutput;

  /* Start for MATLABSystem: '<Root>/가변저항' */
  Final_integration_DW.obj_f.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_f.SampleTime = Final_integration_P._SampleTime;
  Final_integration_DW.obj_f.isInitialized = 1L;
  Final_integration_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(62UL);
  Final_integration_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S24>/Encoder' */
  Final_integration_DW.obj_a.Index = 0U;
  Final_integration_DW.obj_a.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_a.SampleTime = Final_integration_P.Encoder_SampleTime;
  Final_integration_DW.obj_a.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &Final_integration_DW.obj_a.Index);
  Final_integration_DW.obj_a.isSetupComplete = true;
  Final_integration_DW.obj_a.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S24>/Encoder' */
  MW_EncoderReset(Final_integration_DW.obj_a.Index);

  /* Start for MATLABSystem: '<S28>/Encoder' */
  Final_integration_DW.obj.Index = 0U;
  Final_integration_DW.obj.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj.SampleTime = Final_integration_P.Encoder_SampleTime_f;
  Final_integration_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(20UL, 21UL, &Final_integration_DW.obj.Index);
  Final_integration_DW.obj.isSetupComplete = true;
  Final_integration_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S28>/Encoder' */
  MW_EncoderReset(Final_integration_DW.obj.Index);

  /* Start for MATLABSystem: '<Root>/Adas Mode Switch' */
  Final_integration_DW.obj_m.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_m.SampleTime =
    Final_integration_P.AdasModeSwitch_SampleTime;
  Final_integration_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(31, 0);
  Final_integration_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/Digital Output' */
  Final_integration_DW.obj_g.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(43, 1);
  Final_integration_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S10>/Digital Output' */
  Final_integration_DW.obj_n.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(42, 1);
  Final_integration_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/PWM' */
  Final_integration_DW.obj_o.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_o.isInitialized = 1L;
  Final_integration_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0,
    0.0);
  Final_integration_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/조도센서 Input' */
  Final_integration_DW.obj_ld.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_ld.SampleTime = Final_integration_P.Input_SampleTime;
  Final_integration_DW.obj_ld.isInitialized = 1L;
  Final_integration_DW.obj_ld.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(55UL);
  Final_integration_DW.obj_ld.isSetupComplete = true;

  /* Start for MATLABSystem: '<S25>/PWM' */
  Final_integration_DW.obj_ma.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_ma.isInitialized = 1L;
  Final_integration_DW.obj_ma.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  Final_integration_DW.obj_ma.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output' */
  Final_integration_DW.obj_k.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_k.isInitialized = 1L;
  digitalIOSetup(13, 1);
  Final_integration_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S29>/PWM' */
  Final_integration_DW.obj_i.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_i.isInitialized = 1L;
  Final_integration_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(3UL, 0.0,
    0.0);
  Final_integration_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S50>/Digital Output' */
  Final_integration_DW.obj_cq.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_cq.isInitialized = 1L;
  digitalIOSetup(44, 1);
  Final_integration_DW.obj_cq.isSetupComplete = true;

  /* Start for MATLABSystem: '<S50>/Digital Output1' */
  Final_integration_DW.obj_c.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_c.isInitialized = 1L;
  digitalIOSetup(45, 1);
  Final_integration_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/조도센서 Switch' */
  Final_integration_DW.obj_l.matlabCodegenIsDeleted = false;
  Final_integration_DW.obj_l.SampleTime = Final_integration_P.Switch_SampleTime;
  Final_integration_DW.obj_l.isInitialized = 1L;
  digitalIOSetup(36, 0);
  Final_integration_DW.obj_l.isSetupComplete = true;
}

/* Model terminate function */
void Final_integration_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/가변저항' */
  if (!Final_integration_DW.obj_f.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Final_integration_DW.obj_f.isInitialized == 1L) &&
        Final_integration_DW.obj_f.isSetupComplete) {
      Final_integration_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close
        (Final_integration_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/가변저항' */
  /* Terminate for MATLABSystem: '<S24>/Encoder' */
  if (!Final_integration_DW.obj_a.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Final_integration_DW.obj_a.isInitialized == 1L) &&
        Final_integration_DW.obj_a.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S24>/Encoder' */

  /* Terminate for MATLABSystem: '<S28>/Encoder' */
  if (!Final_integration_DW.obj.matlabCodegenIsDeleted) {
    Final_integration_DW.obj.matlabCodegenIsDeleted = true;
    if ((Final_integration_DW.obj.isInitialized == 1L) &&
        Final_integration_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S28>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Adas Mode Switch' */
  if (!Final_integration_DW.obj_m.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Adas Mode Switch' */

  /* Terminate for MATLABSystem: '<S9>/Digital Output' */
  if (!Final_integration_DW.obj_g.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/Digital Output' */

  /* Terminate for MATLABSystem: '<S10>/Digital Output' */
  if (!Final_integration_DW.obj_n.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S10>/Digital Output' */

  /* Terminate for MATLABSystem: '<S7>/PWM' */
  if (!Final_integration_DW.obj_o.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Final_integration_DW.obj_o.isInitialized == 1L) &&
        Final_integration_DW.obj_o.isSetupComplete) {
      Final_integration_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);
      MW_PWM_SetDutyCycle(Final_integration_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      Final_integration_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);
      MW_PWM_Close(Final_integration_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/조도센서 Input' */
  if (!Final_integration_DW.obj_ld.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_ld.matlabCodegenIsDeleted = true;
    if ((Final_integration_DW.obj_ld.isInitialized == 1L) &&
        Final_integration_DW.obj_ld.isSetupComplete) {
      Final_integration_DW.obj_ld.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(55UL);
      MW_AnalogIn_Close
        (Final_integration_DW.obj_ld.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/조도센서 Input' */
  /* Terminate for MATLABSystem: '<S25>/PWM' */
  if (!Final_integration_DW.obj_ma.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_ma.matlabCodegenIsDeleted = true;
    if ((Final_integration_DW.obj_ma.isInitialized == 1L) &&
        Final_integration_DW.obj_ma.isSetupComplete) {
      Final_integration_DW.obj_ma.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_SetDutyCycle(Final_integration_DW.obj_ma.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      Final_integration_DW.obj_ma.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_Close(Final_integration_DW.obj_ma.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S25>/PWM' */
  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!Final_integration_DW.obj_k.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */
  /* Terminate for MATLABSystem: '<S29>/PWM' */
  if (!Final_integration_DW.obj_i.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Final_integration_DW.obj_i.isInitialized == 1L) &&
        Final_integration_DW.obj_i.isSetupComplete) {
      Final_integration_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (3UL);
      MW_PWM_SetDutyCycle(Final_integration_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      Final_integration_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (3UL);
      MW_PWM_Close(Final_integration_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S29>/PWM' */
  /* Terminate for MATLABSystem: '<S50>/Digital Output' */
  if (!Final_integration_DW.obj_cq.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_cq.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S50>/Digital Output' */

  /* Terminate for MATLABSystem: '<S50>/Digital Output1' */
  if (!Final_integration_DW.obj_c.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S50>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/조도센서 Switch' */
  if (!Final_integration_DW.obj_l.matlabCodegenIsDeleted) {
    Final_integration_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/조도센서 Switch' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
