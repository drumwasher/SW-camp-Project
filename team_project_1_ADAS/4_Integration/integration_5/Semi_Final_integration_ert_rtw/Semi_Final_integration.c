/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Semi_Final_integration.c
 *
 * Code generated for Simulink model 'Semi_Final_integration'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb 15 09:25:14 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Semi_Final_integration.h"
#include "rtwtypes.h"
#include "Semi_Final_integration_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "multiword_types.h"
#include <float.h>

/* Block signals (default storage) */
B_Semi_Final_integration_T Semi_Final_integration_B;

/* Continuous states */
X_Semi_Final_integration_T Semi_Final_integration_X;

/* Disabled State Vector */
XDis_Semi_Final_integration_T Semi_Final_integration_XDis;

/* Block states (default storage) */
DW_Semi_Final_integration_T Semi_Final_integration_DW;

/* Real-time model */
static RT_MODEL_Semi_Final_integrati_T Semi_Final_integration_M_;
RT_MODEL_Semi_Final_integrati_T *const Semi_Final_integration_M =
  &Semi_Final_integration_M_;
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

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt2' */
void MW_ISR_2(void)
{
  /* Call the system: <S18>/SW1 */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_a);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRan_fq);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_c);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_c);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.SW1_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt2' */

    /* Output and update for function-call system: '<S18>/SW1' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (Semi_Final_integration_M->Timing.rtmDbBufWriteBuf4) {
     case 0:
      Semi_Final_integration_M->Timing.rtmDbBufReadBuf4 = 1;
      break;

     case 1:
      Semi_Final_integration_M->Timing.rtmDbBufReadBuf4 = 0;
      break;

     default:
      Semi_Final_integration_M->Timing.rtmDbBufReadBuf4 =
        Semi_Final_integration_M->Timing.rtmDbBufLastBufWr4;
      break;
    }

    Semi_Final_integration_M->Timing.clockTick4 =
      Semi_Final_integration_M->
      Timing.rtmDbBufClockTick4
      [Semi_Final_integration_M->Timing.rtmDbBufReadBuf4];
    Semi_Final_integration_M->Timing.rtmDbBufReadBuf4 = 0xFF;

    /* If: '<S21>/If' incorporates:
     *  Delay: '<S21>/Delay'
     */
    if (Semi_Final_integration_DW.Delay_DSTATE_p == 0.0) {
      /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* Merge: '<S21>/Merge' incorporates:
       *  Constant: '<S21>/Constant2'
       *  SignalConversion generated from: '<S22>/In1'
       */
      Semi_Final_integration_B.Merge_e =
        Semi_Final_integration_P.Constant2_Value;

      /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* Update for If: '<S21>/If' */
      Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_a = 4;

      /* End of Update for SubSystem: '<S21>/If Action Subsystem' */
    } else if (Semi_Final_integration_DW.Delay_DSTATE_p == 1.0) {
      /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      /* If: '<S23>/If1' */
      if ((Semi_Final_integration_B.Delay_f == 0.0) &&
          (Semi_Final_integration_B.Delay == 0.0)) {
        /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S25>/Action Port'
         */
        /* Merge: '<S21>/Merge' incorporates:
         *  Constant: '<S23>/Constant'
         *  SignalConversion generated from: '<S25>/In1'
         */
        Semi_Final_integration_B.Merge_e =
          Semi_Final_integration_P.Constant_Value;

        /* End of Outputs for SubSystem: '<S23>/If Action Subsystem1' */

        /* Update for IfAction SubSystem: '<S23>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S25>/Action Port'
         */
        /* Update for If: '<S23>/If1' */
        Semi_Final_integration_DW.IfActionSubsystem1_SubsysRan_fq = 4;

        /* End of Update for SubSystem: '<S23>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem' incorporates:
         *  ActionPort: '<S24>/Action Port'
         */
        /* Merge: '<S21>/Merge' incorporates:
         *  Constant: '<S23>/Constant1'
         *  SignalConversion generated from: '<S24>/In1'
         */
        Semi_Final_integration_B.Merge_e =
          Semi_Final_integration_P.Constant1_Value;

        /* End of Outputs for SubSystem: '<S23>/If Action Subsystem' */

        /* Update for IfAction SubSystem: '<S23>/If Action Subsystem' incorporates:
         *  ActionPort: '<S24>/Action Port'
         */
        /* Update for If: '<S23>/If1' */
        Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_c = 4;

        /* End of Update for SubSystem: '<S23>/If Action Subsystem' */
      }

      /* End of If: '<S23>/If1' */
      /* End of Outputs for SubSystem: '<S21>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S21>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      /* Update for If: '<S21>/If' */
      Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_c = 4;

      /* End of Update for SubSystem: '<S21>/If Action Subsystem1' */
    }

    /* End of If: '<S21>/If' */

    /* Update for Delay: '<S21>/Delay' */
    Semi_Final_integration_DW.Delay_DSTATE_p = Semi_Final_integration_B.Merge_e;
    Semi_Final_integration_DW.SW1_SubsysRanBC = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt2' */
  }

  extmodeEvent(4,((Semi_Final_integration_M->Timing.clockTick4) * 0.01));
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
  (Semi_Final_integration_M->Timing.TaskCounters.TID[2])++;
  if ((Semi_Final_integration_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    Semi_Final_integration_M->Timing.TaskCounters.TID[2] = 0;
  }

  (Semi_Final_integration_M->Timing.TaskCounters.TID[3])++;
  if ((Semi_Final_integration_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.2s, 0.0s] */
    Semi_Final_integration_M->Timing.TaskCounters.TID[3] = 0;
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
  Semi_Final_integration_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Semi_Final_integration_step();
  Semi_Final_integration_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Semi_Final_integration_step();
  Semi_Final_integration_derivatives();

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
 *    '<S2>/If Action Subsystem1'
 *    '<S2>/If Action Subsystem3'
 *    '<S7>/If Action Subsystem1'
 */
void Semi_Final_i_IfActionSubsystem1(real_T *rty_Out1,
  P_IfActionSubsystem1_Semi_Fin_T *localP)
{
  /* SignalConversion generated from: '<S15>/Out1' incorporates:
   *  Constant: '<S15>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S46>/If Action Subsystem'
 *    '<S46>/If Action Subsystem2'
 */
void Semi_Final_in_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1, real_T
  *rty_Out2)
{
  /* SignalConversion generated from: '<S47>/Out1' incorporates:
   *  SignalConversion generated from: '<S47>/In1'
   */
  *rty_Out1 = rtu_In1;

  /* SignalConversion generated from: '<S47>/Out2' incorporates:
   *  SignalConversion generated from: '<S47>/In1'
   */
  *rty_Out2 = rtu_In1;
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
void Semi_Final_integration_step(void)
{
  /* local block i/o variables */
  int32_T rtb_TSamp;
  int32_T rtb_TSamp_g;
  if (rtmIsMajorTimeStep(Semi_Final_integration_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Semi_Final_integration_M->solverInfo,
                          ((Semi_Final_integration_M->Timing.clockTick0+1)*
      Semi_Final_integration_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Semi_Final_integration_M)) {
    Semi_Final_integration_M->Timing.t[0] = rtsiGetT
      (&Semi_Final_integration_M->solverInfo);
  }

  {
    uint64m_T tmp_1;
    real_T rtb_Merge9;
    real_T rtb_Merge_b;
    real_T *lastU;
    uint32_T tmp;
    uint32_T tmp_0;
    uint16_T b_varargout_1;
    int8_T rtAction;
    uint8_T tmp_2;
    static const int64m_T tmp_3 = { { 0UL, 0UL }/* chunks */
    };

    static const int64m_T tmp_4 = { { 25UL, 0UL }/* chunks */
    };

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRan_kd);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem3_SubsysRanB_o);

    /* Reset subsysRan breadcrumbs */
    srClearBC
      (Semi_Final_integration_DW.IfActionSubsystem1_m.IfActionSubsystem1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_j);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_p);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_e);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem9_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem10_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_f);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_f);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem2_SubsysRanB_g);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem3_SubsysRanB_a);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRan_ef);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_k);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem3_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem11_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_o);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_k);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_m);

    /* Reset subsysRan breadcrumbs */
    srClearBC
      (Semi_Final_integration_DW.IfActionSubsystem_p.IfActionSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_e);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanBC);
    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[2] == 0) {
      /* MATLABSystem: '<Root>/Digital Input1' */
      if (Semi_Final_integration_DW.obj_c.SampleTime !=
          Semi_Final_integration_P.DigitalInput1_SampleTime) {
        Semi_Final_integration_DW.obj_c.SampleTime =
          Semi_Final_integration_P.DigitalInput1_SampleTime;
      }

      /* MATLABSystem: '<Root>/Digital Input1' */
      Semi_Final_integration_B.DigitalInput1 = readDigitalPin(36);
    }

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
      /* RateTransition: '<S18>/Rate Transition' */
      Semi_Final_integration_B.RateTransition = Semi_Final_integration_B.Merge_e;
    }

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[3] == 0) {
      /* If: '<S12>/If' */
      rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
        if (!Semi_Final_integration_B.DigitalInput1) {
          rtAction = 0;
        }

        Semi_Final_integration_DW.If_ActiveSubsystem = rtAction;
      } else {
        rtAction = Semi_Final_integration_DW.If_ActiveSubsystem;
      }

      if (rtAction == 0) {
        /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
         *  ActionPort: '<S42>/Action Port'
         */
        /* If: '<S42>/If' */
        if (Semi_Final_integration_B.RateTransition == 1.0) {
          /* Outputs for IfAction SubSystem: '<S42>/If Action Subsystem' incorporates:
           *  ActionPort: '<S44>/Action Port'
           */
          /* SignalConversion generated from: '<S44>/In1' incorporates:
           *  Constant: '<S42>/Constant'
           */
          Semi_Final_integration_B.Plus =
            Semi_Final_integration_P.Constant_Value_a;

          /* End of Outputs for SubSystem: '<S42>/If Action Subsystem' */

          /* Update for IfAction SubSystem: '<S42>/If Action Subsystem' incorporates:
           *  ActionPort: '<S44>/Action Port'
           */
          /* Update for If: '<S42>/If' */
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_o);

          /* End of Update for SubSystem: '<S42>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S42>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S45>/Action Port'
           */
          /* SignalConversion generated from: '<S45>/In1' incorporates:
           *  Constant: '<S42>/Constant2'
           */
          Semi_Final_integration_B.Plus =
            Semi_Final_integration_P.Constant2_Value_f;

          /* End of Outputs for SubSystem: '<S42>/If Action Subsystem1' */

          /* Update for IfAction SubSystem: '<S42>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S45>/Action Port'
           */
          /* Update for If: '<S42>/If' */
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_k);

          /* End of Update for SubSystem: '<S42>/If Action Subsystem1' */
        }

        /* End of If: '<S42>/If' */

        /* Math: '<S42>/Mod' incorporates:
         *  Constant: '<S42>/Constant1'
         *  Delay: '<S42>/Delay'
         *  Sum: '<S42>/Plus'
         */
        Semi_Final_integration_B.Mod = rt_modd_snf(Semi_Final_integration_B.Plus
          + Semi_Final_integration_DW.Delay_DSTATE_g,
          Semi_Final_integration_P.Constant1_Value_c);

        /* Update for Delay: '<S42>/Delay' */
        Semi_Final_integration_DW.Delay_DSTATE_g = Semi_Final_integration_B.Mod;
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_m);
        }

        /* End of Outputs for SubSystem: '<S12>/If Action Subsystem' */
      }

      /* End of If: '<S12>/If' */
    }

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
      /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
      Semi_Final_integration_B.Add5 =
        (Semi_Final_integration_DW.clockTickCounter <
         Semi_Final_integration_P.PulseGenerator_Duty_f) &&
        (Semi_Final_integration_DW.clockTickCounter >= 0L) ?
        Semi_Final_integration_P.PulseGenerator_Amp_j : 0.0;
      if (Semi_Final_integration_DW.clockTickCounter >=
          Semi_Final_integration_P.PulseGenerator_Period_c - 1.0) {
        Semi_Final_integration_DW.clockTickCounter = 0L;
      } else {
        Semi_Final_integration_DW.clockTickCounter++;
      }

      /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

      /* Product: '<S1>/Product' */
      Semi_Final_integration_B.Product_m =
        Semi_Final_integration_B.RateTransition * Semi_Final_integration_B.Add5;

      /* Product: '<S1>/Product1' incorporates:
       *  Constant: '<S1>/Constant'
       */
      Semi_Final_integration_B.Product1_c =
        Semi_Final_integration_P.Constant_Value_hz *
        Semi_Final_integration_B.RateTransition;
    }

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[2] == 0) {
      /* MATLABSystem: '<Root>/Digital Input2' */
      if (Semi_Final_integration_DW.obj_p.SampleTime !=
          Semi_Final_integration_P.DigitalInput2_SampleTime) {
        Semi_Final_integration_DW.obj_p.SampleTime =
          Semi_Final_integration_P.DigitalInput2_SampleTime;
      }

      /* MATLABSystem: '<Root>/Digital Input2' */
      Semi_Final_integration_B.DigitalInput2 = readDigitalPin(31);
    }

    /* RateTransition: '<S3>/Rate Transition2' */
    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
      /* RateTransition: '<S3>/Rate Transition2' */
      Semi_Final_integration_B.RateTransition2 =
        Semi_Final_integration_B.DigitalInput2;
    }

    /* End of RateTransition: '<S3>/Rate Transition2' */
    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[3] == 0) {
      /* If: '<S17>/If' */
      rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
        if (!Semi_Final_integration_B.RateTransition2) {
          rtAction = 0;
        }

        Semi_Final_integration_DW.If_ActiveSubsystem_c = rtAction;
      } else {
        rtAction = Semi_Final_integration_DW.If_ActiveSubsystem_c;
      }

      if (rtAction == 0) {
        /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S20>/Action Port'
         */
        /* Sum: '<S20>/Sum' incorporates:
         *  Constant: '<S20>/Constant2'
         *  Delay: '<S20>/Delay1'
         */
        Semi_Final_integration_DW.Delay1_DSTATE +=
          Semi_Final_integration_P.Constant2_Value_i;

        /* Math: '<S20>/Mod1' incorporates:
         *  Constant: '<S20>/Constant3'
         *  Delay: '<S20>/Delay1'
         */
        Semi_Final_integration_B.Mod1 = rt_modd_snf
          (Semi_Final_integration_DW.Delay1_DSTATE,
           Semi_Final_integration_P.Constant3_Value);
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_j);
        }

        /* End of Outputs for SubSystem: '<S17>/If Action Subsystem1' */
      }

      /* End of If: '<S17>/If' */
    }

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
      /* If: '<S3>/If' */
      rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
        if (Semi_Final_integration_B.RateTransition == 1.0) {
          rtAction = 0;
        }

        Semi_Final_integration_DW.If_ActiveSubsystem_d = rtAction;
      } else {
        rtAction = Semi_Final_integration_DW.If_ActiveSubsystem_d;
      }

      if (rtAction == 0) {
        /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
         *  ActionPort: '<S19>/Action Port'
         */
        /* SignalConversion generated from: '<S19>/sw2' */
        Semi_Final_integration_B.sw2 = Semi_Final_integration_B.Mod1;
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_p);
        }

        /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */
      }

      /* End of If: '<S3>/If' */

      /* If: '<S1>/If1' */
      if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
        Semi_Final_integration_DW.If1_ActiveSubsystem = (int8_T)
          !(Semi_Final_integration_B.sw2 == 1.0);
      }

      if (Semi_Final_integration_DW.If1_ActiveSubsystem == 0) {
        /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S13>/Action Port'
         */
        /* SignalConversion generated from: '<S13>/Input' */
        rtb_Merge_b = Semi_Final_integration_B.Product1_c;
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRan_kd);
        }

        /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S14>/Action Port'
         */
        /* SignalConversion generated from: '<S14>/Input' */
        rtb_Merge_b = Semi_Final_integration_B.Product_m;
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem3_SubsysRanB_o);
        }

        /* End of Outputs for SubSystem: '<S1>/If Action Subsystem3' */
      }

      /* End of If: '<S1>/If1' */

      /* Constant: '<Root>/Constant7' */
      Semi_Final_integration_B.Constant7 = Semi_Final_integration_P.b;

      /* Constant: '<Root>/Constant8' */
      Semi_Final_integration_B.Constant8 = Semi_Final_integration_P.r;

      /* Constant: '<Root>/Constant6' */
      Semi_Final_integration_B.Constant6 = Semi_Final_integration_P.l;

      /* Constant: '<Root>/Constant4' */
      Semi_Final_integration_B.Constant4 = Semi_Final_integration_P.f;

      /* MATLABSystem: '<Root>/가변저항' */
      if (Semi_Final_integration_DW.obj_h.SampleTime !=
          Semi_Final_integration_P._SampleTime) {
        Semi_Final_integration_DW.obj_h.SampleTime =
          Semi_Final_integration_P._SampleTime;
      }

      Semi_Final_integration_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(62UL);
      MW_AnalogInSingle_ReadResult
        (Semi_Final_integration_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
         &b_varargout_1, MW_ANALOGIN_UINT16);

      /* If: '<S29>/If3' */
      if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
        if (Semi_Final_integration_B.RateTransition == 0.0) {
          Semi_Final_integration_DW.If3_ActiveSubsystem = 0;
        } else if (Semi_Final_integration_B.sw2 == 0.0) {
          Semi_Final_integration_DW.If3_ActiveSubsystem = 1;
        } else {
          Semi_Final_integration_DW.If3_ActiveSubsystem = 2;
        }
      }

      switch (Semi_Final_integration_DW.If3_ActiveSubsystem) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem9' incorporates:
         *  ActionPort: '<S32>/Action Port'
         */
        /* Merge: '<S31>/Merge' incorporates:
         *  Constant: '<S32>/Constant'
         *  Merge: '<S29>/Merge7'
         *  SignalConversion generated from: '<S32>/Out1'
         */
        Semi_Final_integration_B.Merge7 =
          Semi_Final_integration_P.Constant_Value_h;

        /* Merge: '<S31>/Merge1' incorporates:
         *  Constant: '<S32>/Constant'
         *  Merge: '<S29>/Merge8'
         *  SignalConversion generated from: '<S32>/Out2'
         */
        Semi_Final_integration_B.Merge8 =
          Semi_Final_integration_P.Constant_Value_h;

        /* SignalConversion generated from: '<S32>/Out3' incorporates:
         *  Constant: '<S32>/Constant'
         */
        rtb_Merge9 = Semi_Final_integration_P.Constant_Value_h;
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem9_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S29>/If Action Subsystem9' */
        break;

       case 1:
        /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
         *  Gain: '<S8>/Gain4'
         *  MATLABSystem: '<Root>/가변저항'
         * */
        rtb_Merge9 = (real_T)((uint32_T)Semi_Final_integration_P.Gain4_Gain *
                              b_varargout_1) * 7.62939453125E-6;

        /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem10' incorporates:
         *  ActionPort: '<S30>/Action Port'
         */
        /* Merge: '<S31>/Merge' incorporates:
         *  Constant: '<S30>/Constant'
         *  Constant: '<S30>/Constant1'
         *  Constant: '<S30>/Constant2'
         *  Constant: '<S30>/Constant4'
         *  Constant: '<S30>/Constant5'
         *  DataTypeConversion: '<S8>/Data Type Conversion'
         *  Merge: '<S29>/Merge7'
         *  Product: '<S30>/Divide'
         *  Product: '<S30>/Divide1'
         *  Product: '<S30>/Product'
         *  Sum: '<S30>/Minus'
         *  Sum: '<S30>/Sum'
         */
        Semi_Final_integration_B.Merge7 = ((rtb_Merge9 -
          Semi_Final_integration_P.Constant2_Value_p) /
          Semi_Final_integration_P.Constant5_Value /
          Semi_Final_integration_P.Constant1_Value_e +
          Semi_Final_integration_P.Constant4_Value) *
          Semi_Final_integration_P.default1;

        /* Merge: '<S31>/Merge1' incorporates:
         *  Constant: '<S30>/Constant3'
         *  Constant: '<S30>/Constant6'
         *  Constant: '<S30>/Constant7'
         *  Constant: '<S30>/Constant8'
         *  Constant: '<S30>/Constant9'
         *  Merge: '<S29>/Merge8'
         *  Product: '<S30>/Divide2'
         *  Product: '<S30>/Divide3'
         *  Product: '<S30>/Product1'
         *  Sum: '<S30>/Minus1'
         *  Sum: '<S30>/Sum1'
         */
        Semi_Final_integration_B.Merge8 =
          ((Semi_Final_integration_P.Constant7_Value - rtb_Merge9) /
           Semi_Final_integration_P.Constant9_Value /
           Semi_Final_integration_P.Constant6_Value +
           Semi_Final_integration_P.Constant8_Value) *
          Semi_Final_integration_P.default1;

        /* SignalConversion generated from: '<S30>/Out3' incorporates:
         *  Constant: '<S30>/Constant10'
         */
        rtb_Merge9 = Semi_Final_integration_P.Constant10_Value;
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem10_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S29>/If Action Subsystem10' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem11' incorporates:
         *  ActionPort: '<S31>/Action Port'
         */
        /* If: '<S31>/If' */
        if (Semi_Final_integration_B.Constant4 > 10.0) {
          /* Outputs for IfAction SubSystem: '<S31>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S34>/Action Port'
           */
          /* SignalConversion generated from: '<S34>/Out3' incorporates:
           *  Constant: '<S34>/Constant'
           */
          rtb_Merge9 = Semi_Final_integration_P.Constant_Value_n;

          /* If: '<S34>/If' */
          if ((Semi_Final_integration_B.Constant6 < 10.0) &&
              (Semi_Final_integration_B.Constant8 < 10.0)) {
            /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem' incorporates:
             *  ActionPort: '<S37>/Action Port'
             */
            /* Product: '<S37>/Product' incorporates:
             *  Constant: '<S37>/Constant1'
             *  Sum: '<S37>/Subtract'
             */
            Semi_Final_integration_B.Add5 = (Semi_Final_integration_B.Constant6
              - Semi_Final_integration_B.Constant8) *
              Semi_Final_integration_P.steering;

            /* Merge: '<S31>/Merge' incorporates:
             *  Constant: '<S37>/Constant'
             *  Constant: '<S37>/Constant2'
             *  Product: '<S37>/Product1'
             *  Sum: '<S37>/Subtract1'
             */
            Semi_Final_integration_B.Merge7 =
              (Semi_Final_integration_P.Constant2_Value_a -
               Semi_Final_integration_B.Add5) *
              Semi_Final_integration_P.default1;

            /* Merge: '<S31>/Merge1' incorporates:
             *  Constant: '<S37>/Constant2'
             *  Constant: '<S37>/Constant3'
             *  Product: '<S37>/Product3'
             *  Sum: '<S37>/Subtract3'
             */
            Semi_Final_integration_B.Merge8 =
              (Semi_Final_integration_P.Constant2_Value_a +
               Semi_Final_integration_B.Add5) *
              Semi_Final_integration_P.default1;

            /* End of Outputs for SubSystem: '<S34>/If Action Subsystem' */

            /* Update for IfAction SubSystem: '<S34>/If Action Subsystem' incorporates:
             *  ActionPort: '<S37>/Action Port'
             */
            /* Update for If: '<S34>/If' */
            srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_f);

            /* End of Update for SubSystem: '<S34>/If Action Subsystem' */
          } else if (Semi_Final_integration_B.Constant6 < 10.0) {
            /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S38>/Action Port'
             */
            /* Sum: '<S38>/Subtract' incorporates:
             *  Constant: '<S38>/Constant4'
             */
            Semi_Final_integration_B.Subtract =
              Semi_Final_integration_P.Constant4_Value_b -
              Semi_Final_integration_B.Constant6;

            /* Product: '<S38>/Product' incorporates:
             *  Constant: '<S38>/Constant1'
             */
            Semi_Final_integration_B.Product = Semi_Final_integration_P.steering
              * Semi_Final_integration_B.Subtract;

            /* Merge: '<S31>/Merge1' incorporates:
             *  Constant: '<S38>/Constant'
             *  Constant: '<S38>/Constant2'
             *  Product: '<S38>/Product3'
             *  Sum: '<S38>/Subtract3'
             */
            Semi_Final_integration_B.Merge8 =
              (Semi_Final_integration_P.Constant2_Value_o -
               Semi_Final_integration_B.Product) *
              Semi_Final_integration_P.default1;

            /* Sum: '<S38>/Subtract1' incorporates:
             *  Constant: '<S38>/Constant2'
             */
            Semi_Final_integration_B.Subtract1 =
              Semi_Final_integration_P.Constant2_Value_o +
              Semi_Final_integration_B.Product;

            /* Product: '<S38>/Product1' incorporates:
             *  Constant: '<S38>/Constant'
             */
            Semi_Final_integration_B.Product1 =
              Semi_Final_integration_P.default1 *
              Semi_Final_integration_B.Subtract1;

            /* Merge: '<S31>/Merge' incorporates:
             *  SignalConversion generated from: '<S38>/Out2'
             */
            Semi_Final_integration_B.Merge7 = Semi_Final_integration_B.Product1;

            /* Update for IfAction SubSystem: '<S34>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S38>/Action Port'
             */
            /* Update for If: '<S34>/If' */
            srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_f);

            /* End of Update for SubSystem: '<S34>/If Action Subsystem1' */
          } else if (Semi_Final_integration_B.Constant8 < 10.0) {
            /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S39>/Action Port'
             */
            /* Product: '<S39>/Product' incorporates:
             *  Constant: '<S39>/Constant1'
             *  Constant: '<S39>/Constant4'
             *  Sum: '<S39>/Subtract'
             */
            Semi_Final_integration_B.Add5 =
              (Semi_Final_integration_P.Constant4_Value_k -
               Semi_Final_integration_B.Constant8) *
              Semi_Final_integration_P.steering;

            /* Merge: '<S31>/Merge' incorporates:
             *  Constant: '<S39>/Constant'
             *  Constant: '<S39>/Constant2'
             *  Product: '<S39>/Product1'
             *  Sum: '<S39>/Subtract1'
             */
            Semi_Final_integration_B.Merge7 =
              (Semi_Final_integration_P.Constant2_Value_pl -
               Semi_Final_integration_B.Add5) *
              Semi_Final_integration_P.default1;

            /* Merge: '<S31>/Merge1' incorporates:
             *  Constant: '<S39>/Constant'
             *  Constant: '<S39>/Constant2'
             *  Product: '<S39>/Product3'
             *  Sum: '<S39>/Subtract3'
             */
            Semi_Final_integration_B.Merge8 =
              (Semi_Final_integration_P.Constant2_Value_pl +
               Semi_Final_integration_B.Add5) *
              Semi_Final_integration_P.default1;

            /* End of Outputs for SubSystem: '<S34>/If Action Subsystem2' */

            /* Update for IfAction SubSystem: '<S34>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S39>/Action Port'
             */
            /* Update for If: '<S34>/If' */
            srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem2_SubsysRanB_g);

            /* End of Update for SubSystem: '<S34>/If Action Subsystem2' */
          } else {
            /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem3' incorporates:
             *  ActionPort: '<S40>/Action Port'
             */
            /* Merge: '<S31>/Merge' incorporates:
             *  Constant: '<S40>/Constant'
             *  SignalConversion generated from: '<S40>/Out1'
             */
            Semi_Final_integration_B.Merge7 = Semi_Final_integration_P.default1;

            /* Merge: '<S31>/Merge1' incorporates:
             *  Constant: '<S40>/Constant1'
             *  SignalConversion generated from: '<S40>/Out2'
             */
            Semi_Final_integration_B.Merge8 = Semi_Final_integration_P.default1;

            /* End of Outputs for SubSystem: '<S34>/If Action Subsystem3' */

            /* Update for IfAction SubSystem: '<S34>/If Action Subsystem3' incorporates:
             *  ActionPort: '<S40>/Action Port'
             */
            /* Update for If: '<S34>/If' */
            srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem3_SubsysRanB_a);

            /* End of Update for SubSystem: '<S34>/If Action Subsystem3' */
          }

          /* End of If: '<S34>/If' */
          /* End of Outputs for SubSystem: '<S31>/If Action Subsystem1' */

          /* Update for IfAction SubSystem: '<S31>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S34>/Action Port'
           */
          /* Update for If: '<S31>/If' */
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRan_ef);

          /* End of Update for SubSystem: '<S31>/If Action Subsystem1' */
        } else {
          /* Outputs for IfAction SubSystem: '<S31>/If Action Subsystem' incorporates:
           *  ActionPort: '<S33>/Action Port'
           */
          /* Merge: '<S31>/Merge' incorporates:
           *  Constant: '<S33>/Constant'
           *  SignalConversion generated from: '<S33>/Out1'
           */
          Semi_Final_integration_B.Merge7 =
            Semi_Final_integration_P.Constant_Value_p;

          /* Merge: '<S31>/Merge1' incorporates:
           *  Constant: '<S33>/Constant1'
           *  SignalConversion generated from: '<S33>/Out2'
           */
          Semi_Final_integration_B.Merge8 =
            Semi_Final_integration_P.Constant1_Value_f;

          /* SignalConversion generated from: '<S33>/Out3' incorporates:
           *  Constant: '<S33>/Constant2'
           */
          rtb_Merge9 = Semi_Final_integration_P.Constant2_Value_k;

          /* End of Outputs for SubSystem: '<S31>/If Action Subsystem' */

          /* Update for IfAction SubSystem: '<S31>/If Action Subsystem' incorporates:
           *  ActionPort: '<S33>/Action Port'
           */
          /* Update for If: '<S31>/If' */
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_k);

          /* End of Update for SubSystem: '<S31>/If Action Subsystem' */
        }

        /* End of If: '<S31>/If' */

        /* If: '<S31>/If1' */
        if (Semi_Final_integration_B.Constant7 > 10.0) {
          /* Update for IfAction SubSystem: '<S31>/If Action Subsystem2' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          /* Update for If: '<S31>/If1' */
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem2_SubsysRanBC);

          /* End of Update for SubSystem: '<S31>/If Action Subsystem2' */
        } else {
          /* Outputs for IfAction SubSystem: '<S31>/If Action Subsystem3' incorporates:
           *  ActionPort: '<S36>/Action Port'
           */
          /* Merge: '<S31>/Merge' incorporates:
           *  Gain: '<S36>/Gain'
           *  Merge: '<S29>/Merge7'
           */
          Semi_Final_integration_B.Merge7 *= Semi_Final_integration_P.Gain_Gain;

          /* Merge: '<S31>/Merge1' incorporates:
           *  Gain: '<S36>/Gain1'
           *  Merge: '<S29>/Merge8'
           */
          Semi_Final_integration_B.Merge8 *= Semi_Final_integration_P.Gain1_Gain;

          /* End of Outputs for SubSystem: '<S31>/If Action Subsystem3' */

          /* Update for IfAction SubSystem: '<S31>/If Action Subsystem3' incorporates:
           *  ActionPort: '<S36>/Action Port'
           */
          /* Update for If: '<S31>/If1' */
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem3_SubsysRanBC);

          /* End of Update for SubSystem: '<S31>/If Action Subsystem3' */
        }

        /* End of If: '<S31>/If1' */
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem11_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S29>/If Action Subsystem11' */
        break;
      }

      /* End of If: '<S29>/If3' */
      /* Delay: '<Root>/Delay' */
      Semi_Final_integration_B.Delay = Semi_Final_integration_DW.Delay_DSTATE;

      /* Delay: '<S3>/Delay' */
      Semi_Final_integration_B.Delay_f =
        Semi_Final_integration_DW.Delay_DSTATE_e;

      /* DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn' */
      Semi_Final_integration_B.DiscreteTransferFcn = tmp_3;

      /* DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn' */
      tmp = (uint32_T)Semi_Final_integration_P.num_Gd[1L];
      tmp_0 = (uint32_T)Semi_Final_integration_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp, 1, &tmp_0, 1,
                    &Semi_Final_integration_B.DiscreteTransferFcn.chunks[0U], 2);

      /* Sum: '<Root>/Add3' incorporates:
       *  DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn'
       */
      Semi_Final_integration_B.Add5 = sMultiWord2Double
        (&Semi_Final_integration_B.DiscreteTransferFcn.chunks[0U], 2, 0) *
        1.1641532182693481E-10 + Semi_Final_integration_B.Merge7;

      /* Gain: '<S11>/Gain2' */
      Semi_Final_integration_B.Gain2_k = Semi_Final_integration_P.KP *
        Semi_Final_integration_B.Add5;

      /* Gain: '<S11>/Gain3' */
      Semi_Final_integration_B.Gain3 = Semi_Final_integration_P.KD *
        Semi_Final_integration_B.Add5;
    }

    /* Derivative: '<S11>/Derivative2' incorporates:
     *  Derivative: '<S6>/Derivative2'
     */
    Semi_Final_integration_B.Product_m = Semi_Final_integration_M->Timing.t[0];
    if ((Semi_Final_integration_DW.TimeStampA >=
         Semi_Final_integration_B.Product_m) &&
        (Semi_Final_integration_DW.TimeStampB >=
         Semi_Final_integration_B.Product_m)) {
      Semi_Final_integration_B.Product1_c = 0.0;
    } else {
      Semi_Final_integration_B.Product1_c = Semi_Final_integration_DW.TimeStampA;
      lastU = &Semi_Final_integration_DW.LastUAtTimeA;
      if (Semi_Final_integration_DW.TimeStampA <
          Semi_Final_integration_DW.TimeStampB) {
        if (Semi_Final_integration_DW.TimeStampB <
            Semi_Final_integration_B.Product_m) {
          Semi_Final_integration_B.Product1_c =
            Semi_Final_integration_DW.TimeStampB;
          lastU = &Semi_Final_integration_DW.LastUAtTimeB;
        }
      } else if (Semi_Final_integration_DW.TimeStampA >=
                 Semi_Final_integration_B.Product_m) {
        Semi_Final_integration_B.Product1_c =
          Semi_Final_integration_DW.TimeStampB;
        lastU = &Semi_Final_integration_DW.LastUAtTimeB;
      }

      Semi_Final_integration_B.Product1_c = (Semi_Final_integration_B.Gain3 -
        *lastU) / (Semi_Final_integration_B.Product_m -
                   Semi_Final_integration_B.Product1_c);
    }

    /* End of Derivative: '<S11>/Derivative2' */

    /* Sum: '<S11>/Subtract2' incorporates:
     *  Integrator: '<S11>/Integrator2'
     */
    Semi_Final_integration_B.Subtract2 =
      (Semi_Final_integration_X.Integrator2_CSTATE +
       Semi_Final_integration_B.Gain2_k) + Semi_Final_integration_B.Product1_c;
    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* Saturate: '<Root>/Saturation1' */
    if (Semi_Final_integration_B.Subtract2 >
        Semi_Final_integration_P.Saturation1_UpperSat) {
      /* Saturate: '<Root>/Saturation1' */
      Semi_Final_integration_B.Saturation1 =
        Semi_Final_integration_P.Saturation1_UpperSat;
    } else if (Semi_Final_integration_B.Subtract2 <
               Semi_Final_integration_P.Saturation1_LowerSat) {
      /* Saturate: '<Root>/Saturation1' */
      Semi_Final_integration_B.Saturation1 =
        Semi_Final_integration_P.Saturation1_LowerSat;
    } else {
      /* Saturate: '<Root>/Saturation1' */
      Semi_Final_integration_B.Saturation1 = Semi_Final_integration_B.Subtract2;
    }

    /* End of Saturate: '<Root>/Saturation1' */

    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant16'
     */
    if (Semi_Final_integration_B.Saturation1 >
        Semi_Final_integration_P.Switch1_Threshold) {
      Semi_Final_integration_B.Product1_c = Semi_Final_integration_B.Saturation1;
    } else {
      Semi_Final_integration_B.Product1_c =
        Semi_Final_integration_P.Constant16_Value;
    }

    /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
     *  Gain: '<S10>/Gain1'
     *  Switch: '<Root>/Switch1'
     */
    Semi_Final_integration_B.Product1_c = floor(255.0 /
      Semi_Final_integration_P.Vlim * Semi_Final_integration_B.Product1_c);
    if (rtIsNaN(Semi_Final_integration_B.Product1_c) || rtIsInf
        (Semi_Final_integration_B.Product1_c)) {
      Semi_Final_integration_B.Product1_c = 0.0;
    } else {
      Semi_Final_integration_B.Product1_c = fmod
        (Semi_Final_integration_B.Product1_c, 256.0);
    }

    /* DataTypeConversion: '<S10>/Data Type Conversion' */
    Semi_Final_integration_B.DataTypeConversion = (uint8_T)
      (Semi_Final_integration_B.Product1_c < 0.0 ? (int16_T)(uint8_T)-(int8_T)
       (uint8_T)-Semi_Final_integration_B.Product1_c : (int16_T)(uint8_T)
       Semi_Final_integration_B.Product1_c);

    /* DataTypeConversion: '<S10>/Data Type Conversion1' */
    Semi_Final_integration_B.DataTypeConversion1 =
      Semi_Final_integration_B.DataTypeConversion;
    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* MATLABSystem: '<S10>/PWM' */
    Semi_Final_integration_DW.obj_pk.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(11UL);
    MW_PWM_SetDutyCycle
      (Semi_Final_integration_DW.obj_pk.PWMDriverObj.MW_PWM_HANDLE, (real_T)
       Semi_Final_integration_B.DataTypeConversion);
    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S11>/Gain1' */
      Semi_Final_integration_B.Gain1_e = Semi_Final_integration_P.KI *
        Semi_Final_integration_B.Add5;

      /* DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn' */
      Semi_Final_integration_B.DiscreteTransferFcn_l = tmp_3;

      /* DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn' */
      tmp = (uint32_T)Semi_Final_integration_P.num_Gd[1L];
      tmp_0 = (uint32_T)Semi_Final_integration_DW.DiscreteTransferFcn_states_g;
      sMultiWordMul(&tmp, 1, &tmp_0, 1,
                    &Semi_Final_integration_B.DiscreteTransferFcn_l.chunks[0U],
                    2);

      /* Sum: '<Root>/Add5' incorporates:
       *  DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn'
       */
      Semi_Final_integration_B.Add5 = Semi_Final_integration_B.Merge8 -
        sMultiWord2Double
        (&Semi_Final_integration_B.DiscreteTransferFcn_l.chunks[0U], 2, 0) *
        1.1641532182693481E-10;

      /* Gain: '<S6>/Gain2' */
      Semi_Final_integration_B.Gain2_n = Semi_Final_integration_P.KP *
        Semi_Final_integration_B.Add5;

      /* Gain: '<S6>/Gain3' */
      Semi_Final_integration_B.Gain3_g = Semi_Final_integration_P.KD *
        Semi_Final_integration_B.Add5;
    }

    /* Derivative: '<S6>/Derivative2' */
    if ((Semi_Final_integration_DW.TimeStampA_c >=
         Semi_Final_integration_B.Product_m) &&
        (Semi_Final_integration_DW.TimeStampB_g >=
         Semi_Final_integration_B.Product_m)) {
      Semi_Final_integration_B.Product_m = 0.0;
    } else {
      Semi_Final_integration_B.Product1_c =
        Semi_Final_integration_DW.TimeStampA_c;
      lastU = &Semi_Final_integration_DW.LastUAtTimeA_b;
      if (Semi_Final_integration_DW.TimeStampA_c <
          Semi_Final_integration_DW.TimeStampB_g) {
        if (Semi_Final_integration_DW.TimeStampB_g <
            Semi_Final_integration_B.Product_m) {
          Semi_Final_integration_B.Product1_c =
            Semi_Final_integration_DW.TimeStampB_g;
          lastU = &Semi_Final_integration_DW.LastUAtTimeB_p;
        }
      } else if (Semi_Final_integration_DW.TimeStampA_c >=
                 Semi_Final_integration_B.Product_m) {
        Semi_Final_integration_B.Product1_c =
          Semi_Final_integration_DW.TimeStampB_g;
        lastU = &Semi_Final_integration_DW.LastUAtTimeB_p;
      }

      Semi_Final_integration_B.Product_m = (Semi_Final_integration_B.Gain3_g -
        *lastU) / (Semi_Final_integration_B.Product_m -
                   Semi_Final_integration_B.Product1_c);
    }

    /* Sum: '<S6>/Subtract2' incorporates:
     *  Integrator: '<S6>/Integrator2'
     */
    Semi_Final_integration_B.Subtract2_c =
      (Semi_Final_integration_X.Integrator2_CSTATE_i +
       Semi_Final_integration_B.Gain2_n) + Semi_Final_integration_B.Product_m;
    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* Saturate: '<Root>/Saturation2' */
    if (Semi_Final_integration_B.Subtract2_c >
        Semi_Final_integration_P.Saturation2_UpperSat) {
      /* Saturate: '<Root>/Saturation2' */
      Semi_Final_integration_B.Saturation2 =
        Semi_Final_integration_P.Saturation2_UpperSat;
    } else if (Semi_Final_integration_B.Subtract2_c <
               Semi_Final_integration_P.Saturation2_LowerSat) {
      /* Saturate: '<Root>/Saturation2' */
      Semi_Final_integration_B.Saturation2 =
        Semi_Final_integration_P.Saturation2_LowerSat;
    } else {
      /* Saturate: '<Root>/Saturation2' */
      Semi_Final_integration_B.Saturation2 =
        Semi_Final_integration_B.Subtract2_c;
    }

    /* End of Saturate: '<Root>/Saturation2' */

    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant9'
     */
    if (Semi_Final_integration_B.Saturation2 >
        Semi_Final_integration_P.Switch_Threshold) {
      Semi_Final_integration_B.Product_m = Semi_Final_integration_B.Saturation2;
    } else {
      Semi_Final_integration_B.Product_m =
        Semi_Final_integration_P.Constant9_Value_i;
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  Gain: '<S5>/Gain1'
     *  Switch: '<Root>/Switch'
     */
    Semi_Final_integration_B.Product_m = floor(255.0 /
      Semi_Final_integration_P.Vlim * Semi_Final_integration_B.Product_m);
    if (rtIsNaN(Semi_Final_integration_B.Product_m) || rtIsInf
        (Semi_Final_integration_B.Product_m)) {
      Semi_Final_integration_B.Product_m = 0.0;
    } else {
      Semi_Final_integration_B.Product_m = fmod
        (Semi_Final_integration_B.Product_m, 256.0);
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    Semi_Final_integration_B.DataTypeConversion_g = (uint8_T)
      (Semi_Final_integration_B.Product_m < 0.0 ? (int16_T)(uint8_T)-(int8_T)
       (uint8_T)-Semi_Final_integration_B.Product_m : (int16_T)(uint8_T)
       Semi_Final_integration_B.Product_m);

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    Semi_Final_integration_B.DataTypeConversion1_n =
      Semi_Final_integration_B.DataTypeConversion_g;
    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* MATLABSystem: '<S5>/PWM' */
    Semi_Final_integration_DW.obj_ey.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(3UL);
    MW_PWM_SetDutyCycle
      (Semi_Final_integration_DW.obj_ey.PWMDriverObj.MW_PWM_HANDLE, (real_T)
       Semi_Final_integration_B.DataTypeConversion_g);
    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S6>/Gain1' */
      Semi_Final_integration_B.Gain1_j = Semi_Final_integration_P.KI *
        Semi_Final_integration_B.Add5;

      /* MATLABSystem: '<Root>/Analog Input1' */
      if (Semi_Final_integration_DW.obj_j.SampleTime !=
          Semi_Final_integration_P.AnalogInput1_SampleTime) {
        Semi_Final_integration_DW.obj_j.SampleTime =
          Semi_Final_integration_P.AnalogInput1_SampleTime;
      }

      Semi_Final_integration_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(55UL);
      MW_AnalogInSingle_ReadResult
        (Semi_Final_integration_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
         &b_varargout_1, MW_ANALOGIN_UINT16);

      /* Gain: '<S46>/Gain' incorporates:
       *  Gain: '<Root>/Gain12'
       *  MATLABSystem: '<Root>/Analog Input1'
       * */
      tmp_0 = (uint32_T)Semi_Final_integration_P.Gain12_Gain * b_varargout_1;
      uMultiWordMul(&Semi_Final_integration_P.Gain_Gain_l, 1, &tmp_0, 1,
                    &Semi_Final_integration_B.Gain.chunks[0U], 2);

      /* DiscretePulseGenerator: '<S46>/Pulse Generator' */
      Semi_Final_integration_B.Add5 =
        (Semi_Final_integration_DW.clockTickCounter_m <
         Semi_Final_integration_P.PulseGenerator_Duty_p) &&
        (Semi_Final_integration_DW.clockTickCounter_m >= 0L) ?
        Semi_Final_integration_P.PulseGenerator_Amp_g : 0.0;
      if (Semi_Final_integration_DW.clockTickCounter_m >=
          Semi_Final_integration_P.PulseGenerator_Period_d - 1.0) {
        Semi_Final_integration_DW.clockTickCounter_m = 0L;
      } else {
        Semi_Final_integration_DW.clockTickCounter_m++;
      }

      /* End of DiscretePulseGenerator: '<S46>/Pulse Generator' */

      /* RateTransition: '<S12>/Rate Transition' */
      Semi_Final_integration_B.RateTransition_l = Semi_Final_integration_B.Mod;

      /* If: '<S46>/If' incorporates:
       *  Constant: '<S46>/Constant'
       *  Constant: '<S46>/Constant1'
       */
      rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
        if (Semi_Final_integration_B.RateTransition_l == 0.0) {
          rtAction = 0;
        } else if (Semi_Final_integration_B.RateTransition_l == 1.0) {
          rtAction = 1;
        } else if (Semi_Final_integration_B.RateTransition_l == 2.0) {
          rtAction = 2;
        }

        Semi_Final_integration_DW.If_ActiveSubsystem_p = rtAction;
      } else {
        rtAction = Semi_Final_integration_DW.If_ActiveSubsystem_p;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
         *  ActionPort: '<S47>/Action Port'
         */
        Semi_Final_in_IfActionSubsystem
          (Semi_Final_integration_P.Constant1_Value_k,
           &Semi_Final_integration_B.Merge, &Semi_Final_integration_B.Merge1);
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC
            (Semi_Final_integration_DW.IfActionSubsystem_p.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S46>/If Action Subsystem' */
        break;

       case 1:
        /* DataTypeConversion: '<S46>/Data Type Conversion' incorporates:
         *  Gain: '<S46>/Gain'
         */
        uMultiWordShr(&Semi_Final_integration_B.Gain.chunks[0U], 2, 42U,
                      &tmp_1.chunks[0U], 2);

        /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S48>/Action Port'
         */
        /* If: '<S48>/If' incorporates:
         *  DataTypeConversion: '<S46>/Data Type Conversion'
         */
        if ((uint8_T)MultiWord2uLong(&tmp_1.chunks[0U]) <= 34) {
          /* Outputs for IfAction SubSystem: '<S48>/If Action Subsystem' incorporates:
           *  ActionPort: '<S50>/Action Port'
           */
          /* Merge: '<S46>/Merge' incorporates:
           *  Constant: '<S48>/Constant'
           *  SignalConversion generated from: '<S50>/In1'
           */
          Semi_Final_integration_B.Merge =
            Semi_Final_integration_P.Constant_Value_g;

          /* End of Outputs for SubSystem: '<S48>/If Action Subsystem' */

          /* Update for IfAction SubSystem: '<S48>/If Action Subsystem' incorporates:
           *  ActionPort: '<S50>/Action Port'
           */
          /* Update for If: '<S48>/If' */
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC);

          /* End of Update for SubSystem: '<S48>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S48>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S51>/Action Port'
           */
          /* Merge: '<S46>/Merge' incorporates:
           *  Constant: '<S48>/Constant1'
           *  SignalConversion generated from: '<S51>/In1'
           */
          Semi_Final_integration_B.Merge =
            Semi_Final_integration_P.Constant1_Value_ei;

          /* End of Outputs for SubSystem: '<S48>/If Action Subsystem1' */

          /* Update for IfAction SubSystem: '<S48>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S51>/Action Port'
           */
          /* Update for If: '<S48>/If' */
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_e);

          /* End of Update for SubSystem: '<S48>/If Action Subsystem1' */
        }

        /* End of If: '<S48>/If' */

        /* Merge: '<S46>/Merge1' incorporates:
         *  SignalConversion generated from: '<S48>/In1'
         */
        Semi_Final_integration_B.Merge1 = Semi_Final_integration_B.Add5;
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S46>/If Action Subsystem1' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S49>/Action Port'
         */
        Semi_Final_in_IfActionSubsystem
          (Semi_Final_integration_P.Constant_Value_pa,
           &Semi_Final_integration_B.Merge, &Semi_Final_integration_B.Merge1);
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC
            (Semi_Final_integration_DW.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S46>/If Action Subsystem2' */
        break;
      }

      /* End of If: '<S46>/If' */
      /* MATLABSystem: '<S46>/Digital Output' */
      Semi_Final_integration_B.Product_m = rt_roundd_snf
        (Semi_Final_integration_B.Merge);
      if (Semi_Final_integration_B.Product_m < 256.0) {
        if (Semi_Final_integration_B.Product_m >= 0.0) {
          tmp_2 = (uint8_T)Semi_Final_integration_B.Product_m;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint8_T;
      }

      writeDigitalPin(44, tmp_2);

      /* End of MATLABSystem: '<S46>/Digital Output' */

      /* MATLABSystem: '<S46>/Digital Output1' */
      Semi_Final_integration_B.Product_m = rt_roundd_snf
        (Semi_Final_integration_B.Merge1);
      if (Semi_Final_integration_B.Product_m < 256.0) {
        if (Semi_Final_integration_B.Product_m >= 0.0) {
          tmp_2 = (uint8_T)Semi_Final_integration_B.Product_m;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint8_T;
      }

      writeDigitalPin(45, tmp_2);

      /* End of MATLABSystem: '<S46>/Digital Output1' */
      /* If: '<S7>/If' */
      if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
        Semi_Final_integration_DW.If_ActiveSubsystem_b = (int8_T)!(rtb_Merge9 ==
          1.0);
      }

      if (Semi_Final_integration_DW.If_ActiveSubsystem_b == 0) {
        /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* Merge: '<S7>/Merge' incorporates:
         *  DiscretePulseGenerator: '<S27>/Pulse Generator'
         */
        rtb_Merge9 = (Semi_Final_integration_DW.clockTickCounter_h <
                      Semi_Final_integration_P.PulseGenerator_Duty) &&
          (Semi_Final_integration_DW.clockTickCounter_h >= 0L) ?
          Semi_Final_integration_P.PulseGenerator_Amp : 0.0;

        /* DiscretePulseGenerator: '<S27>/Pulse Generator' */
        if (Semi_Final_integration_DW.clockTickCounter_h >=
            Semi_Final_integration_P.PulseGenerator_Period - 1.0) {
          Semi_Final_integration_DW.clockTickCounter_h = 0L;
        } else {
          Semi_Final_integration_DW.clockTickCounter_h++;
        }

        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC(Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_e);
        }

        /* End of Outputs for SubSystem: '<S7>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        Semi_Final_i_IfActionSubsystem1(&rtb_Merge9,
          &Semi_Final_integration_P.IfActionSubsystem1_a);
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC
            (Semi_Final_integration_DW.IfActionSubsystem1_a.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S7>/If Action Subsystem1' */
      }

      /* End of If: '<S7>/If' */

      /* MATLABSystem: '<S7>/PWM' */
      Semi_Final_integration_DW.obj_a5.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);

      /* Start for MATLABSystem: '<S7>/PWM' */
      if (!(rtb_Merge9 <= 255.0)) {
        rtb_Merge9 = 255.0;
      }

      if (!(rtb_Merge9 >= 0.0)) {
        rtb_Merge9 = 0.0;
      }

      /* MATLABSystem: '<S7>/PWM' */
      MW_PWM_SetDutyCycle
        (Semi_Final_integration_DW.obj_a5.PWMDriverObj.MW_PWM_HANDLE, rtb_Merge9);

      /* MATLABSystem: '<S1>/Digital Output' */
      Semi_Final_integration_B.Product_m = rt_roundd_snf(rtb_Merge_b);
      if (Semi_Final_integration_B.Product_m < 256.0) {
        if (Semi_Final_integration_B.Product_m >= 0.0) {
          tmp_2 = (uint8_T)Semi_Final_integration_B.Product_m;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint8_T;
      }

      writeDigitalPin(43, tmp_2);

      /* End of MATLABSystem: '<S1>/Digital Output' */
    }

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[3] == 0) {
    }

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
      /* If: '<S2>/If1' */
      if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
        Semi_Final_integration_DW.If1_ActiveSubsystem_i = (int8_T)
          !(Semi_Final_integration_B.RateTransition == 1.0);
      }

      if (Semi_Final_integration_DW.If1_ActiveSubsystem_i == 0) {
        /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S15>/Action Port'
         */
        Semi_Final_i_IfActionSubsystem1(&rtb_Merge_b,
          &Semi_Final_integration_P.IfActionSubsystem1_m);
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC
            (Semi_Final_integration_DW.IfActionSubsystem1_m.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S16>/Action Port'
         */
        Semi_Final_i_IfActionSubsystem1(&rtb_Merge_b,
          &Semi_Final_integration_P.IfActionSubsystem3_m);
        if (rtsiIsModeUpdateTimeStep(&Semi_Final_integration_M->solverInfo)) {
          srUpdateBC
            (Semi_Final_integration_DW.IfActionSubsystem3_m.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
      }

      /* End of If: '<S2>/If1' */

      /* MATLABSystem: '<S2>/Digital Output' */
      Semi_Final_integration_B.Product_m = rt_roundd_snf(rtb_Merge_b);
      if (Semi_Final_integration_B.Product_m < 256.0) {
        if (Semi_Final_integration_B.Product_m >= 0.0) {
          tmp_2 = (uint8_T)Semi_Final_integration_B.Product_m;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint8_T;
      }

      writeDigitalPin(42, tmp_2);

      /* End of MATLABSystem: '<S2>/Digital Output' */
      /* MATLABSystem: '<S9>/Encoder' */
      if (Semi_Final_integration_DW.obj.SampleTime !=
          Semi_Final_integration_P.Encoder_SampleTime_a) {
        Semi_Final_integration_DW.obj.SampleTime =
          Semi_Final_integration_P.Encoder_SampleTime_a;
      }

      if (Semi_Final_integration_DW.obj.TunablePropsChanged) {
        Semi_Final_integration_DW.obj.TunablePropsChanged = false;
      }

      /* SampleTimeMath: '<S41>/TSamp' incorporates:
       *  MATLABSystem: '<S9>/Encoder'
       * *
       * About '<S41>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       */
      MW_EncoderRead(Semi_Final_integration_DW.obj.Index, &rtb_TSamp);

      /* Gain: '<S9>/Gain1' incorporates:
       *  Gain: '<S4>/Gain1'
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
      tmp = (uint32_T)Semi_Final_integration_P.encoder_scale;
      tmp_0 = (uint32_T)(rtb_TSamp - Semi_Final_integration_DW.UD_DSTATE);
      sMultiWordMul(&tmp, 1, &tmp_0, 1, &Semi_Final_integration_B.Gain1.chunks
                    [0U], 2);

      /* Gain: '<S9>/Gain2' incorporates:
       *  Gain: '<S9>/Gain1'
       */
      sMultiWordMul(&Semi_Final_integration_P.Gain2_Gain.chunks[0U], 2,
                    &Semi_Final_integration_B.Gain1.chunks[0U], 2,
                    &Semi_Final_integration_B.Gain2.chunks[0U], 4);

      /* Gain: '<S4>/Gain1' incorporates:
       *  DataTypeConversion: '<S9>/Data Type Conversion1'
       *  Gain: '<S9>/Gain1'
       */
      Semi_Final_integration_B.Gain1_h = Semi_Final_integration_B.Gain1;

      /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
       *  Gain: '<S9>/Gain1'
       */
      sMultiWordMul(&Semi_Final_integration_B.Gain1.chunks[0U], 2,
                    &tmp_4.chunks[0U], 2, &Semi_Final_integration_B.r2.chunks[0U],
                    4);
      sMultiWordShr(&Semi_Final_integration_B.r2.chunks[0U], 4, 31U,
                    &Semi_Final_integration_B.r1.chunks[0U], 4);

      /* DataTypeConversion: '<S9>/Data Type Conversion1' */
      Semi_Final_integration_B.DataTypeConversion1_m = MultiWord2sLong
        (&Semi_Final_integration_B.r1.chunks[0U]);

      /* MATLABSystem: '<S4>/Encoder' */
      if (Semi_Final_integration_DW.obj_d.SampleTime !=
          Semi_Final_integration_P.Encoder_SampleTime) {
        Semi_Final_integration_DW.obj_d.SampleTime =
          Semi_Final_integration_P.Encoder_SampleTime;
      }

      if (Semi_Final_integration_DW.obj_d.TunablePropsChanged) {
        Semi_Final_integration_DW.obj_d.TunablePropsChanged = false;
      }

      /* SampleTimeMath: '<S26>/TSamp' incorporates:
       *  MATLABSystem: '<S4>/Encoder'
       * *
       * About '<S26>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       */
      MW_EncoderRead(Semi_Final_integration_DW.obj_d.Index, &rtb_TSamp_g);

      /* Gain: '<S4>/Gain1' incorporates:
       *  SampleTimeMath: '<S26>/TSamp'
       *  Sum: '<S26>/Diff'
       *  UnitDelay: '<S26>/UD'
       *
       * About '<S26>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S26>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S26>/UD':
       *
       *  Store in Global RAM
       */
      tmp_0 = (uint32_T)(rtb_TSamp_g - Semi_Final_integration_DW.UD_DSTATE_f);
      sMultiWordMul(&tmp, 1, &tmp_0, 1,
                    &Semi_Final_integration_B.Gain1_h.chunks[0U], 2);

      /* Gain: '<S4>/Gain2' incorporates:
       *  Gain: '<S4>/Gain1'
       */
      sMultiWordMul(&Semi_Final_integration_P.Gain2_Gain_g.chunks[0U], 2,
                    &Semi_Final_integration_B.Gain1_h.chunks[0U], 2,
                    &Semi_Final_integration_B.r2.chunks[0U], 4);

      /* Gain: '<S4>/Gain2' incorporates:
       *  DataTypeConversion: '<S9>/Data Type Conversion1'
       */
      Semi_Final_integration_B.Gain2_j = Semi_Final_integration_B.r2;

      /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
       *  Gain: '<S4>/Gain1'
       */
      sMultiWordMul(&Semi_Final_integration_B.Gain1_h.chunks[0U], 2,
                    &tmp_4.chunks[0U], 2, &Semi_Final_integration_B.r4.chunks[0U],
                    4);
      sMultiWordShr(&Semi_Final_integration_B.r4.chunks[0U], 4, 31U,
                    &Semi_Final_integration_B.r3.chunks[0U], 4);

      /* DataTypeConversion: '<S4>/Data Type Conversion1' */
      Semi_Final_integration_B.DataTypeConversion1_l = MultiWord2sLong
        (&Semi_Final_integration_B.r3.chunks[0U]);

      /* MATLABSystem: '<Root>/Digital Output' incorporates:
       *  Constant: '<Root>/Constant13'
       */
      Semi_Final_integration_B.Product_m = rt_roundd_snf
        (Semi_Final_integration_P.Constant13_Value);
      if (Semi_Final_integration_B.Product_m < 256.0) {
        if (Semi_Final_integration_B.Product_m >= 0.0) {
          tmp_2 = (uint8_T)Semi_Final_integration_B.Product_m;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint8_T;
      }

      writeDigitalPin(13, tmp_2);

      /* End of MATLABSystem: '<Root>/Digital Output' */
    }
  }

  if (rtmIsMajorTimeStep(Semi_Final_integration_M)) {
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

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for Delay: '<Root>/Delay' */
      Semi_Final_integration_DW.Delay_DSTATE =
        Semi_Final_integration_B.RateTransition_l;

      /* Update for Delay: '<S3>/Delay' */
      Semi_Final_integration_DW.Delay_DSTATE_e = Semi_Final_integration_B.sw2;

      /* Update for DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn' */
      sLong2MultiWord(Semi_Final_integration_B.DataTypeConversion1_m,
                      &Semi_Final_integration_B.r12.chunks[0U], 2);
      sMultiWordShl(&Semi_Final_integration_B.r12.chunks[0U], 2, 30U,
                    &Semi_Final_integration_B.denAccum.chunks[0U], 2);
      tmp = (uint32_T)Semi_Final_integration_P.den_Gd[1L];
      tmp_0 = (uint32_T)Semi_Final_integration_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp, 1, &tmp_0, 1, &Semi_Final_integration_B.r12.chunks[0U],
                    2);
      MultiWordSub(&Semi_Final_integration_B.denAccum.chunks[0U],
                   &Semi_Final_integration_B.r12.chunks[0U], &denAccum.chunks[0U],
                   2);
      Semi_Final_integration_B.denAccum = denAccum;
      if (Semi_Final_integration_P.den_Gd[0] == 0L) {
        if (sMultiWordGe(&Semi_Final_integration_B.denAccum.chunks[0U],
                         &tmp_5.chunks[0U], 2)) {
          Semi_Final_integration_B.r11 = tmp_4;
        } else {
          Semi_Final_integration_B.r11 = tmp_6;
        }
      } else {
        sMultiWord2MultiWord(&Semi_Final_integration_B.denAccum.chunks[0U], 2,
                             &Semi_Final_integration_B.r6.chunks[0U], 3);
        sMultiWordShl(&Semi_Final_integration_B.r6.chunks[0U], 3, 30U,
                      &Semi_Final_integration_B.r5.chunks[0U], 3);
        sLong2MultiWord(Semi_Final_integration_P.den_Gd[0],
                        &Semi_Final_integration_B.r6.chunks[0U], 3);
        sMultiWordDivFloor(&Semi_Final_integration_B.r5.chunks[0U], 3,
                           &Semi_Final_integration_B.r6.chunks[0U], 3,
                           &Semi_Final_integration_B.r.chunks[0U], 4,
                           &Semi_Final_integration_B.r7.chunks[0U], 3,
                           &Semi_Final_integration_B.r8.chunks[0U], 3,
                           &Semi_Final_integration_B.r9.chunks[0U], 3);
        sMultiWord2MultiWord(&Semi_Final_integration_B.r.chunks[0U], 4,
                             &Semi_Final_integration_B.r11.chunks[0U], 2);
      }

      sMultiWordShr(&Semi_Final_integration_B.r11.chunks[0U], 2, 30U,
                    &tmp_1.chunks[0U], 2);
      Semi_Final_integration_DW.DiscreteTransferFcn_states = MultiWord2sLong
        (&tmp_1.chunks[0U]);

      /* End of Update for DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn' */
    }

    /* Update for Derivative: '<S11>/Derivative2' */
    if (Semi_Final_integration_DW.TimeStampA == (rtInf)) {
      Semi_Final_integration_DW.TimeStampA = Semi_Final_integration_M->Timing.t
        [0];
      lastU = &Semi_Final_integration_DW.LastUAtTimeA;
    } else if (Semi_Final_integration_DW.TimeStampB == (rtInf)) {
      Semi_Final_integration_DW.TimeStampB = Semi_Final_integration_M->Timing.t
        [0];
      lastU = &Semi_Final_integration_DW.LastUAtTimeB;
    } else if (Semi_Final_integration_DW.TimeStampA <
               Semi_Final_integration_DW.TimeStampB) {
      Semi_Final_integration_DW.TimeStampA = Semi_Final_integration_M->Timing.t
        [0];
      lastU = &Semi_Final_integration_DW.LastUAtTimeA;
    } else {
      Semi_Final_integration_DW.TimeStampB = Semi_Final_integration_M->Timing.t
        [0];
      lastU = &Semi_Final_integration_DW.LastUAtTimeB;
    }

    *lastU = Semi_Final_integration_B.Gain3;

    /* End of Update for Derivative: '<S11>/Derivative2' */
    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn' */
      sLong2MultiWord(Semi_Final_integration_B.DataTypeConversion1_l,
                      &tmp_2.chunks[0U], 2);
      sMultiWordShl(&tmp_2.chunks[0U], 2, 30U,
                    &Semi_Final_integration_B.denAccum.chunks[0U], 2);
      tmp = (uint32_T)Semi_Final_integration_P.den_Gd[1L];
      tmp_0 = (uint32_T)Semi_Final_integration_DW.DiscreteTransferFcn_states_g;
      sMultiWordMul(&tmp, 1, &tmp_0, 1, &tmp_2.chunks[0U], 2);
      MultiWordSub(&Semi_Final_integration_B.denAccum.chunks[0U], &tmp_2.chunks
                   [0U], &denAccum_0.chunks[0U], 2);
      if (Semi_Final_integration_P.den_Gd[0] == 0L) {
        if (sMultiWordGe(&denAccum_0.chunks[0U], &tmp_5.chunks[0U], 2)) {
          Semi_Final_integration_B.r10 = tmp_4;
        } else {
          Semi_Final_integration_B.r10 = tmp_6;
        }
      } else {
        sMultiWord2MultiWord(&denAccum_0.chunks[0U], 2,
                             &Semi_Final_integration_B.r6.chunks[0U], 3);
        sMultiWordShl(&Semi_Final_integration_B.r6.chunks[0U], 3, 30U,
                      &Semi_Final_integration_B.r5.chunks[0U], 3);
        sLong2MultiWord(Semi_Final_integration_P.den_Gd[0],
                        &Semi_Final_integration_B.r6.chunks[0U], 3);
        sMultiWordDivFloor(&Semi_Final_integration_B.r5.chunks[0U], 3,
                           &Semi_Final_integration_B.r6.chunks[0U], 3,
                           &Semi_Final_integration_B.r.chunks[0U], 4,
                           &Semi_Final_integration_B.r7.chunks[0U], 3,
                           &Semi_Final_integration_B.r8.chunks[0U], 3,
                           &Semi_Final_integration_B.r9.chunks[0U], 3);
        sMultiWord2MultiWord(&Semi_Final_integration_B.r.chunks[0U], 4,
                             &Semi_Final_integration_B.r10.chunks[0U], 2);
      }

      sMultiWordShr(&Semi_Final_integration_B.r10.chunks[0U], 2, 30U,
                    &tmp_3.chunks[0U], 2);
      Semi_Final_integration_DW.DiscreteTransferFcn_states_g = MultiWord2sLong
        (&tmp_3.chunks[0U]);

      /* End of Update for DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn' */
    }

    /* Update for Derivative: '<S6>/Derivative2' */
    if (Semi_Final_integration_DW.TimeStampA_c == (rtInf)) {
      Semi_Final_integration_DW.TimeStampA_c =
        Semi_Final_integration_M->Timing.t[0];
      lastU = &Semi_Final_integration_DW.LastUAtTimeA_b;
    } else if (Semi_Final_integration_DW.TimeStampB_g == (rtInf)) {
      Semi_Final_integration_DW.TimeStampB_g =
        Semi_Final_integration_M->Timing.t[0];
      lastU = &Semi_Final_integration_DW.LastUAtTimeB_p;
    } else if (Semi_Final_integration_DW.TimeStampA_c <
               Semi_Final_integration_DW.TimeStampB_g) {
      Semi_Final_integration_DW.TimeStampA_c =
        Semi_Final_integration_M->Timing.t[0];
      lastU = &Semi_Final_integration_DW.LastUAtTimeA_b;
    } else {
      Semi_Final_integration_DW.TimeStampB_g =
        Semi_Final_integration_M->Timing.t[0];
      lastU = &Semi_Final_integration_DW.LastUAtTimeB_p;
    }

    *lastU = Semi_Final_integration_B.Gain3_g;

    /* End of Update for Derivative: '<S6>/Derivative2' */
    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {
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
      Semi_Final_integration_DW.UD_DSTATE = rtb_TSamp;

      /* Update for UnitDelay: '<S26>/UD' incorporates:
       *  SampleTimeMath: '<S26>/TSamp'
       *
       * About '<S26>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S26>/UD':
       *
       *  Store in Global RAM
       */
      Semi_Final_integration_DW.UD_DSTATE_f = rtb_TSamp_g;
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((Semi_Final_integration_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((Semi_Final_integration_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.1s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((Semi_Final_integration_M->Timing.clockTick2 * 10) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(2,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[3] == 0) {/* Sample time: [0.2s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((Semi_Final_integration_M->Timing.clockTick3 * 20) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(3,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Semi_Final_integration_M)) {
    rt_ertODEUpdateContinuousStates(&Semi_Final_integration_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Semi_Final_integration_M->Timing.clockTick0;
    Semi_Final_integration_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Semi_Final_integration_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Semi_Final_integration_M->Timing.clockTick1++;
    }

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick2" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick2" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Semi_Final_integration_M->Timing.clockTick2++;
    }

    if (rtmIsMajorTimeStep(Semi_Final_integration_M) &&
        Semi_Final_integration_M->Timing.TaskCounters.TID[3] == 0) {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick3" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick3" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Semi_Final_integration_M->Timing.clockTick3++;
    }

    switch (Semi_Final_integration_M->Timing.rtmDbBufReadBuf4) {
     case 0:
      Semi_Final_integration_M->Timing.rtmDbBufWriteBuf4 = 1;
      break;

     case 1:
      Semi_Final_integration_M->Timing.rtmDbBufWriteBuf4 = 0;
      break;

     default:
      Semi_Final_integration_M->Timing.rtmDbBufWriteBuf4 =
        !Semi_Final_integration_M->Timing.rtmDbBufLastBufWr4;
      break;
    }

    Semi_Final_integration_M->Timing.rtmDbBufClockTick4
      [Semi_Final_integration_M->Timing.rtmDbBufWriteBuf4] =
      Semi_Final_integration_M->Timing.clockTick0;
    Semi_Final_integration_M->Timing.rtmDbBufLastBufWr4 =
      Semi_Final_integration_M->Timing.rtmDbBufWriteBuf4;
    Semi_Final_integration_M->Timing.rtmDbBufWriteBuf4 = 0xFF;
    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Semi_Final_integration_derivatives(void)
{
  XDot_Semi_Final_integration_T *_rtXdot;
  _rtXdot = ((XDot_Semi_Final_integration_T *) Semi_Final_integration_M->derivs);

  /* Derivatives for Integrator: '<S11>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Semi_Final_integration_B.Gain1_e;

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_i = Semi_Final_integration_B.Gain1_j;
}

/* Model initialize function */
void Semi_Final_integration_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Semi_Final_integration_M->solverInfo,
                          &Semi_Final_integration_M->Timing.simTimeStep);
    rtsiSetTPtr(&Semi_Final_integration_M->solverInfo, &rtmGetTPtr
                (Semi_Final_integration_M));
    rtsiSetStepSizePtr(&Semi_Final_integration_M->solverInfo,
                       &Semi_Final_integration_M->Timing.stepSize0);
    rtsiSetdXPtr(&Semi_Final_integration_M->solverInfo,
                 &Semi_Final_integration_M->derivs);
    rtsiSetContStatesPtr(&Semi_Final_integration_M->solverInfo, (real_T **)
                         &Semi_Final_integration_M->contStates);
    rtsiSetNumContStatesPtr(&Semi_Final_integration_M->solverInfo,
      &Semi_Final_integration_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Semi_Final_integration_M->solverInfo,
      &Semi_Final_integration_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Semi_Final_integration_M->solverInfo,
      &Semi_Final_integration_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Semi_Final_integration_M->solverInfo,
      &Semi_Final_integration_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&Semi_Final_integration_M->solverInfo,
      (boolean_T**) &Semi_Final_integration_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&Semi_Final_integration_M->solverInfo,
                          (&rtmGetErrorStatus(Semi_Final_integration_M)));
    rtsiSetRTModelPtr(&Semi_Final_integration_M->solverInfo,
                      Semi_Final_integration_M);
  }

  rtsiSetSimTimeStep(&Semi_Final_integration_M->solverInfo, MAJOR_TIME_STEP);
  Semi_Final_integration_M->intgData.y = Semi_Final_integration_M->odeY;
  Semi_Final_integration_M->intgData.f[0] = Semi_Final_integration_M->odeF[0];
  Semi_Final_integration_M->intgData.f[1] = Semi_Final_integration_M->odeF[1];
  Semi_Final_integration_M->intgData.f[2] = Semi_Final_integration_M->odeF[2];
  Semi_Final_integration_M->contStates = ((X_Semi_Final_integration_T *)
    &Semi_Final_integration_X);
  Semi_Final_integration_M->contStateDisabled = ((XDis_Semi_Final_integration_T *)
    &Semi_Final_integration_XDis);
  Semi_Final_integration_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&Semi_Final_integration_M->solverInfo, (void *)
                    &Semi_Final_integration_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Semi_Final_integration_M->solverInfo,
    false);
  rtsiSetSolverName(&Semi_Final_integration_M->solverInfo,"ode3");
  rtmSetTPtr(Semi_Final_integration_M, &Semi_Final_integration_M->Timing.tArray
             [0]);
  rtmSetTFinal(Semi_Final_integration_M, -1);
  Semi_Final_integration_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Semi_Final_integration_M->Sizes.checksums[0] = (3364778273U);
  Semi_Final_integration_M->Sizes.checksums[1] = (1970380331U);
  Semi_Final_integration_M->Sizes.checksums[2] = (2317386754U);
  Semi_Final_integration_M->Sizes.checksums[3] = (1510426622U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[47];
    Semi_Final_integration_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem1_SubsysRan_kd;
    systemRan[7] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem3_SubsysRanB_o;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem1_m.IfActionSubsystem1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem3_m.IfActionSubsystem1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_p;
    systemRan[12] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_j;
    systemRan[13] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_a;
    systemRan[14] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_c;
    systemRan[15] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem1_SubsysRan_fq;
    systemRan[16] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_c;
    systemRan[17] = (sysRanDType *)&Semi_Final_integration_DW.SW1_SubsysRanBC;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_e;
    systemRan[21] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem1_a.IfActionSubsystem1_SubsysRanBC;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem10_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_k;
    systemRan[25] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_f;
    systemRan[26] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_f;
    systemRan[27] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem2_SubsysRanB_g;
    systemRan[28] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem3_SubsysRanB_a;
    systemRan[29] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem1_SubsysRan_ef;
    systemRan[30] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem3_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem11_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem9_SubsysRanBC;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_o;
    systemRan[37] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_k;
    systemRan[38] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC_m;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem_p.IfActionSubsystem_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanB_e;
    systemRan[44] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[45] = (sysRanDType *)
      &Semi_Final_integration_DW.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[46] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Semi_Final_integration_M->extModeInfo,
      &Semi_Final_integration_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Semi_Final_integration_M->extModeInfo,
                        Semi_Final_integration_M->Sizes.checksums);
    rteiSetTPtr(Semi_Final_integration_M->extModeInfo, rtmGetTPtr
                (Semi_Final_integration_M));
  }

  Semi_Final_integration_M->Timing.rtmDbBufReadBuf4 = 0xFF;
  Semi_Final_integration_M->Timing.rtmDbBufWriteBuf4 = 0xFF;
  Semi_Final_integration_M->Timing.rtmDbBufLastBufWr4 = 0;

  /* Start for If: '<S12>/If' */
  Semi_Final_integration_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<S17>/If' */
  Semi_Final_integration_DW.If_ActiveSubsystem_c = -1;

  /* Start for If: '<S3>/If' */
  Semi_Final_integration_DW.If_ActiveSubsystem_d = -1;

  /* Start for If: '<S1>/If1' */
  Semi_Final_integration_DW.If1_ActiveSubsystem = -1;

  /* Start for If: '<S29>/If3' */
  Semi_Final_integration_DW.If3_ActiveSubsystem = -1;

  /* Start for If: '<S46>/If' */
  Semi_Final_integration_DW.If_ActiveSubsystem_p = -1;

  /* Start for If: '<S7>/If' */
  Semi_Final_integration_DW.If_ActiveSubsystem_b = -1;

  /* Start for If: '<S2>/If1' */
  Semi_Final_integration_DW.If1_ActiveSubsystem_i = -1;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  Semi_Final_integration_DW.Delay_DSTATE =
    Semi_Final_integration_P.Delay_InitialCondition_k;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  Semi_Final_integration_DW.Delay_DSTATE_e =
    Semi_Final_integration_P.Delay_InitialCondition_f;

  /* InitializeConditions for Integrator: '<S11>/Integrator2' */
  Semi_Final_integration_X.Integrator2_CSTATE =
    Semi_Final_integration_P.Integrator2_IC;

  /* InitializeConditions for DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn' */
  Semi_Final_integration_DW.DiscreteTransferFcn_states =
    Semi_Final_integration_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for Derivative: '<S11>/Derivative2' */
  Semi_Final_integration_DW.TimeStampA = (rtInf);
  Semi_Final_integration_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S6>/Integrator2' */
  Semi_Final_integration_X.Integrator2_CSTATE_i =
    Semi_Final_integration_P.Integrator2_IC_g;

  /* InitializeConditions for DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn' */
  Semi_Final_integration_DW.DiscreteTransferFcn_states_g =
    Semi_Final_integration_P.DiscreteTransferFcn_InitialSt_p;

  /* InitializeConditions for Derivative: '<S6>/Derivative2' */
  Semi_Final_integration_DW.TimeStampA_c = (rtInf);
  Semi_Final_integration_DW.TimeStampB_g = (rtInf);

  /* InitializeConditions for UnitDelay: '<S41>/UD'
   *
   * Block description for '<S41>/UD':
   *
   *  Store in Global RAM
   */
  Semi_Final_integration_DW.UD_DSTATE =
    Semi_Final_integration_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S26>/UD'
   *
   * Block description for '<S26>/UD':
   *
   *  Store in Global RAM
   */
  Semi_Final_integration_DW.UD_DSTATE_f =
    Semi_Final_integration_P.DiscreteDerivative_ICPrevScal_m;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt2' incorporates:
   *  SubSystem: '<S18>/SW1'
   */
  /* System initialize for function-call system: '<S18>/SW1' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (Semi_Final_integration_M->Timing.rtmDbBufWriteBuf4) {
   case 0:
    Semi_Final_integration_M->Timing.rtmDbBufReadBuf4 = 1;
    break;

   case 1:
    Semi_Final_integration_M->Timing.rtmDbBufReadBuf4 = 0;
    break;

   default:
    Semi_Final_integration_M->Timing.rtmDbBufReadBuf4 =
      Semi_Final_integration_M->Timing.rtmDbBufLastBufWr4;
    break;
  }

  Semi_Final_integration_M->Timing.clockTick4 =
    Semi_Final_integration_M->Timing.rtmDbBufClockTick4
    [Semi_Final_integration_M->Timing.rtmDbBufReadBuf4];
  Semi_Final_integration_M->Timing.rtmDbBufReadBuf4 = 0xFF;

  /* InitializeConditions for Delay: '<S21>/Delay' */
  Semi_Final_integration_DW.Delay_DSTATE_p =
    Semi_Final_integration_P.Delay_InitialCondition;

  /* SystemInitialize for Merge: '<S21>/Merge' */
  Semi_Final_integration_B.Merge_e =
    Semi_Final_integration_P.Merge_InitialOutput;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, RISING);

  /* SystemInitialize for IfAction SubSystem: '<S12>/If Action Subsystem' */
  /* InitializeConditions for Delay: '<S42>/Delay' */
  Semi_Final_integration_DW.Delay_DSTATE_g =
    Semi_Final_integration_P.Delay_InitialCondition_o;

  /* SystemInitialize for Math: '<S42>/Mod' incorporates:
   *  Outport: '<S42>/Out1'
   */
  Semi_Final_integration_B.Mod = Semi_Final_integration_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S12>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/If Action Subsystem1' */
  /* InitializeConditions for Delay: '<S20>/Delay1' */
  Semi_Final_integration_DW.Delay1_DSTATE =
    Semi_Final_integration_P.Delay1_InitialCondition;

  /* SystemInitialize for Math: '<S20>/Mod1' incorporates:
   *  Outport: '<S20>/sw2'
   */
  Semi_Final_integration_B.Mod1 = Semi_Final_integration_P.sw2_Y0;

  /* End of SystemInitialize for SubSystem: '<S17>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/If Action Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S19>/sw2' incorporates:
   *  Outport: '<S19>/ADAS_state'
   */
  Semi_Final_integration_B.sw2 = Semi_Final_integration_P.ADAS_state_Y0;

  /* End of SystemInitialize for SubSystem: '<S17>/If Action Subsystem' */
  /* SystemInitialize for Merge: '<S46>/Merge' */
  Semi_Final_integration_B.Merge =
    Semi_Final_integration_P.Merge_InitialOutput_b;

  /* SystemInitialize for Merge: '<S46>/Merge1' */
  Semi_Final_integration_B.Merge1 =
    Semi_Final_integration_P.Merge1_InitialOutput;

  /* Start for MATLABSystem: '<Root>/Digital Input1' */
  Semi_Final_integration_DW.obj_c.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_c.SampleTime =
    Semi_Final_integration_P.DigitalInput1_SampleTime;
  Semi_Final_integration_DW.obj_c.isInitialized = 1L;
  digitalIOSetup(36, 0);
  Semi_Final_integration_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input2' */
  Semi_Final_integration_DW.obj_p.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_p.SampleTime =
    Semi_Final_integration_P.DigitalInput2_SampleTime;
  Semi_Final_integration_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(31, 0);
  Semi_Final_integration_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/가변저항' */
  Semi_Final_integration_DW.obj_h.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_h.SampleTime =
    Semi_Final_integration_P._SampleTime;
  Semi_Final_integration_DW.obj_h.isInitialized = 1L;
  Semi_Final_integration_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(62UL);
  Semi_Final_integration_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S10>/PWM' */
  Semi_Final_integration_DW.obj_pk.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_pk.isInitialized = 1L;
  Semi_Final_integration_DW.obj_pk.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL,
    0.0, 0.0);
  Semi_Final_integration_DW.obj_pk.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/PWM' */
  Semi_Final_integration_DW.obj_ey.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_ey.isInitialized = 1L;
  Semi_Final_integration_DW.obj_ey.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(3UL,
    0.0, 0.0);
  Semi_Final_integration_DW.obj_ey.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  Semi_Final_integration_DW.obj_j.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_j.SampleTime =
    Semi_Final_integration_P.AnalogInput1_SampleTime;
  Semi_Final_integration_DW.obj_j.isInitialized = 1L;
  Semi_Final_integration_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(55UL);
  Semi_Final_integration_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S46>/Digital Output' */
  Semi_Final_integration_DW.obj_cz.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_cz.isInitialized = 1L;
  digitalIOSetup(44, 1);
  Semi_Final_integration_DW.obj_cz.isSetupComplete = true;

  /* Start for MATLABSystem: '<S46>/Digital Output1' */
  Semi_Final_integration_DW.obj_a.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_a.isInitialized = 1L;
  digitalIOSetup(45, 1);
  Semi_Final_integration_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/PWM' */
  Semi_Final_integration_DW.obj_a5.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_a5.isInitialized = 1L;
  Semi_Final_integration_DW.obj_a5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL,
    0.0, 0.0);
  Semi_Final_integration_DW.obj_a5.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Digital Output' */
  Semi_Final_integration_DW.obj_k.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_k.isInitialized = 1L;
  digitalIOSetup(43, 1);
  Semi_Final_integration_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output' */
  Semi_Final_integration_DW.obj_e.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(42, 1);
  Semi_Final_integration_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/Encoder' */
  Semi_Final_integration_DW.obj.Index = 0U;
  Semi_Final_integration_DW.obj.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj.SampleTime =
    Semi_Final_integration_P.Encoder_SampleTime_a;
  Semi_Final_integration_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &Semi_Final_integration_DW.obj.Index);
  Semi_Final_integration_DW.obj.isSetupComplete = true;
  Semi_Final_integration_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S9>/Encoder' */
  MW_EncoderReset(Semi_Final_integration_DW.obj.Index);

  /* Start for MATLABSystem: '<S4>/Encoder' */
  Semi_Final_integration_DW.obj_d.Index = 0U;
  Semi_Final_integration_DW.obj_d.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_d.SampleTime =
    Semi_Final_integration_P.Encoder_SampleTime;
  Semi_Final_integration_DW.obj_d.isInitialized = 1L;
  MW_EncoderSetup(20UL, 21UL, &Semi_Final_integration_DW.obj_d.Index);
  Semi_Final_integration_DW.obj_d.isSetupComplete = true;
  Semi_Final_integration_DW.obj_d.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S4>/Encoder' */
  MW_EncoderReset(Semi_Final_integration_DW.obj_d.Index);

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  Semi_Final_integration_DW.obj_j4.matlabCodegenIsDeleted = false;
  Semi_Final_integration_DW.obj_j4.isInitialized = 1L;
  digitalIOSetup(13, 1);
  Semi_Final_integration_DW.obj_j4.isSetupComplete = true;
}

/* Model terminate function */
void Semi_Final_integration_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  if (!Semi_Final_integration_DW.obj_c.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input1' */
  /* Terminate for MATLABSystem: '<Root>/Digital Input2' */
  if (!Semi_Final_integration_DW.obj_p.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input2' */

  /* Terminate for MATLABSystem: '<Root>/가변저항' */
  if (!Semi_Final_integration_DW.obj_h.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Semi_Final_integration_DW.obj_h.isInitialized == 1L) &&
        Semi_Final_integration_DW.obj_h.isSetupComplete) {
      Semi_Final_integration_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close
        (Semi_Final_integration_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/가변저항' */
  /* Terminate for MATLABSystem: '<S10>/PWM' */
  if (!Semi_Final_integration_DW.obj_pk.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_pk.matlabCodegenIsDeleted = true;
    if ((Semi_Final_integration_DW.obj_pk.isInitialized == 1L) &&
        Semi_Final_integration_DW.obj_pk.isSetupComplete) {
      Semi_Final_integration_DW.obj_pk.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle
        (Semi_Final_integration_DW.obj_pk.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Semi_Final_integration_DW.obj_pk.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_Close(Semi_Final_integration_DW.obj_pk.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/PWM' */
  /* Terminate for MATLABSystem: '<S5>/PWM' */
  if (!Semi_Final_integration_DW.obj_ey.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_ey.matlabCodegenIsDeleted = true;
    if ((Semi_Final_integration_DW.obj_ey.isInitialized == 1L) &&
        Semi_Final_integration_DW.obj_ey.isSetupComplete) {
      Semi_Final_integration_DW.obj_ey.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(3UL);
      MW_PWM_SetDutyCycle
        (Semi_Final_integration_DW.obj_ey.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Semi_Final_integration_DW.obj_ey.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(3UL);
      MW_PWM_Close(Semi_Final_integration_DW.obj_ey.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!Semi_Final_integration_DW.obj_j.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Semi_Final_integration_DW.obj_j.isInitialized == 1L) &&
        Semi_Final_integration_DW.obj_j.isSetupComplete) {
      Semi_Final_integration_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(55UL);
      MW_AnalogIn_Close
        (Semi_Final_integration_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */
  /* Terminate for MATLABSystem: '<S46>/Digital Output' */
  if (!Semi_Final_integration_DW.obj_cz.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_cz.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S46>/Digital Output' */

  /* Terminate for MATLABSystem: '<S46>/Digital Output1' */
  if (!Semi_Final_integration_DW.obj_a.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S46>/Digital Output1' */
  /* Terminate for MATLABSystem: '<S7>/PWM' */
  if (!Semi_Final_integration_DW.obj_a5.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_a5.matlabCodegenIsDeleted = true;
    if ((Semi_Final_integration_DW.obj_a5.isInitialized == 1L) &&
        Semi_Final_integration_DW.obj_a5.isSetupComplete) {
      Semi_Final_integration_DW.obj_a5.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle
        (Semi_Final_integration_DW.obj_a5.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Semi_Final_integration_DW.obj_a5.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_Close(Semi_Final_integration_DW.obj_a5.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/PWM' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!Semi_Final_integration_DW.obj_k.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */
  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  if (!Semi_Final_integration_DW.obj_e.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output' */
  /* Terminate for MATLABSystem: '<S9>/Encoder' */
  if (!Semi_Final_integration_DW.obj.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj.matlabCodegenIsDeleted = true;
    if ((Semi_Final_integration_DW.obj.isInitialized == 1L) &&
        Semi_Final_integration_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/Encoder' */
  /* Terminate for MATLABSystem: '<S4>/Encoder' */
  if (!Semi_Final_integration_DW.obj_d.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Semi_Final_integration_DW.obj_d.isInitialized == 1L) &&
        Semi_Final_integration_DW.obj_d.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!Semi_Final_integration_DW.obj_j4.matlabCodegenIsDeleted) {
    Semi_Final_integration_DW.obj_j4.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
