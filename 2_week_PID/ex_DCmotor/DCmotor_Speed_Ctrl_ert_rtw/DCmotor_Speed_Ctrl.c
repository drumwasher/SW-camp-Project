/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DCmotor_Speed_Ctrl.c
 *
 * Code generated for Simulink model 'DCmotor_Speed_Ctrl'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Feb 10 22:59:09 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DCmotor_Speed_Ctrl.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "multiword_types.h"
#include "rtwtypes.h"
#include "DCmotor_Speed_Ctrl_private.h"

/* Block signals (default storage) */
B_DCmotor_Speed_Ctrl_T DCmotor_Speed_Ctrl_B;

/* Continuous states */
X_DCmotor_Speed_Ctrl_T DCmotor_Speed_Ctrl_X;

/* Disabled State Vector */
XDis_DCmotor_Speed_Ctrl_T DCmotor_Speed_Ctrl_XDis;

/* Block states (default storage) */
DW_DCmotor_Speed_Ctrl_T DCmotor_Speed_Ctrl_DW;

/* Real-time model */
static RT_MODEL_DCmotor_Speed_Ctrl_T DCmotor_Speed_Ctrl_M_;
RT_MODEL_DCmotor_Speed_Ctrl_T *const DCmotor_Speed_Ctrl_M =
  &DCmotor_Speed_Ctrl_M_;
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
  DCmotor_Speed_Ctrl_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  DCmotor_Speed_Ctrl_step();
  DCmotor_Speed_Ctrl_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  DCmotor_Speed_Ctrl_step();
  DCmotor_Speed_Ctrl_derivatives();

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

/* Model step function */
void DCmotor_Speed_Ctrl_step(void)
{
  /* local block i/o variables */
  int32_T rtb_TSamp;
  if (rtmIsMajorTimeStep(DCmotor_Speed_Ctrl_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&DCmotor_Speed_Ctrl_M->solverInfo,
                          ((DCmotor_Speed_Ctrl_M->Timing.clockTick0+1)*
      DCmotor_Speed_Ctrl_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(DCmotor_Speed_Ctrl_M)) {
    DCmotor_Speed_Ctrl_M->Timing.t[0] = rtsiGetT
      (&DCmotor_Speed_Ctrl_M->solverInfo);
  }

  {
    int128m_T tmp_1;
    int128m_T tmp_2;
    real_T u0;
    uint32_T tmp;
    uint32_T tmp_0;
    static const int64m_T tmp_3 = { { 0UL, 0UL }/* chunks */
    };

    static const int64m_T tmp_4 = { { 25UL, 0UL }/* chunks */
    };

    /* Step: '<Root>/Wref1' */
    if (DCmotor_Speed_Ctrl_M->Timing.t[0] < DCmotor_Speed_Ctrl_P.Wref1_Time) {
      /* Step: '<Root>/Wref1' */
      DCmotor_Speed_Ctrl_B.Wref = DCmotor_Speed_Ctrl_P.Wref1_Y0;
    } else {
      /* Step: '<Root>/Wref1' */
      DCmotor_Speed_Ctrl_B.Wref = DCmotor_Speed_Ctrl_P.Wref;
    }

    /* End of Step: '<Root>/Wref1' */
    if (rtmIsMajorTimeStep(DCmotor_Speed_Ctrl_M)) {
      /* DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
      DCmotor_Speed_Ctrl_B.Wrads = tmp_3;

      /* DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
      tmp = (uint32_T)DCmotor_Speed_Ctrl_P.num_Gd[1L];
      tmp_0 = (uint32_T)DCmotor_Speed_Ctrl_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp, 1, &tmp_0, 1, &DCmotor_Speed_Ctrl_B.Wrads.chunks[0U],
                    2);
    }

    /* Sum: '<Root>/Add3' incorporates:
     *  DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn'
     */
    DCmotor_Speed_Ctrl_B.Add3 = DCmotor_Speed_Ctrl_B.Wref - sMultiWord2Double
      (&DCmotor_Speed_Ctrl_B.Wrads.chunks[0U], 2, 0) * 1.1641532182693481E-10;

    /* MATLABSystem: '<S1>/PWM' */
    DCmotor_Speed_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (11UL);

    /* Sum: '<Root>/Add4' incorporates:
     *  Gain: '<Root>/Gain2'
     *  TransferFcn: '<Root>/Transfer Fcn1'
     */
    u0 = DCmotor_Speed_Ctrl_P.TransferFcn1_C *
      DCmotor_Speed_Ctrl_X.TransferFcn1_CSTATE + DCmotor_Speed_Ctrl_P.Kp *
      DCmotor_Speed_Ctrl_B.Add3;

    /* Saturate: '<S1>/Saturation1' */
    if (u0 > DCmotor_Speed_Ctrl_P.Vlim) {
      u0 = DCmotor_Speed_Ctrl_P.Vlim;
    } else if (u0 < DCmotor_Speed_Ctrl_P.Saturation1_LowerSat) {
      u0 = DCmotor_Speed_Ctrl_P.Saturation1_LowerSat;
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Gain: '<S1>/Gain'
     *  Saturate: '<S1>/Saturation1'
     */
    u0 = floor(255.0 / DCmotor_Speed_Ctrl_P.Vlim * u0);
    if (rtIsNaN(u0) || rtIsInf(u0)) {
      u0 = 0.0;
    } else {
      u0 = fmod(u0, 256.0);
    }

    /* MATLABSystem: '<S1>/PWM' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    MW_PWM_SetDutyCycle(DCmotor_Speed_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)(u0 < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)
      -u0 : (int16_T)(uint8_T)u0));
    if (rtmIsMajorTimeStep(DCmotor_Speed_Ctrl_M)) {
      /* MATLABSystem: '<S2>/Encoder1' */
      if (DCmotor_Speed_Ctrl_DW.obj.SampleTime != DCmotor_Speed_Ctrl_P.Ts) {
        DCmotor_Speed_Ctrl_DW.obj.SampleTime = DCmotor_Speed_Ctrl_P.Ts;
      }

      if (DCmotor_Speed_Ctrl_DW.obj.TunablePropsChanged) {
        DCmotor_Speed_Ctrl_DW.obj.TunablePropsChanged = false;
      }

      /* SampleTimeMath: '<S3>/TSamp' incorporates:
       *  MATLABSystem: '<S2>/Encoder1'
       * *
       * About '<S3>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       */
      MW_EncoderRead(DCmotor_Speed_Ctrl_DW.obj.Index, &rtb_TSamp);

      /* Gain: '<S2>/mtr_rad//s' incorporates:
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
      tmp = (uint32_T)DCmotor_Speed_Ctrl_P.encoder_scale;
      tmp_0 = (uint32_T)(rtb_TSamp - DCmotor_Speed_Ctrl_DW.UD_DSTATE);
      sMultiWordMul(&tmp, 1, &tmp_0, 1, &DCmotor_Speed_Ctrl_B.mtr_rads.chunks[0U],
                    2);

      /* Gain: '<S2>/RPM' incorporates:
       *  Gain: '<S2>/mtr_rad//s'
       */
      sMultiWordMul(&DCmotor_Speed_Ctrl_P.RPM_Gain.chunks[0U], 2,
                    &DCmotor_Speed_Ctrl_B.mtr_rads.chunks[0U], 2,
                    &DCmotor_Speed_Ctrl_B.RPM.chunks[0U], 4);

      /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
       *  Gain: '<S2>/mtr_rad//s'
       */
      sMultiWordMul(&DCmotor_Speed_Ctrl_B.mtr_rads.chunks[0U], 2, &tmp_4.chunks
                    [0U], 2, &tmp_2.chunks[0U], 4);
      sMultiWordShr(&tmp_2.chunks[0U], 4, 31U, &tmp_1.chunks[0U], 4);

      /* DataTypeConversion: '<S2>/Data Type Conversion1' */
      DCmotor_Speed_Ctrl_B.DataTypeConversion1 = MultiWord2sLong(&tmp_1.chunks
        [0U]);
    }
  }

  if (rtmIsMajorTimeStep(DCmotor_Speed_Ctrl_M)) {
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

    if (rtmIsMajorTimeStep(DCmotor_Speed_Ctrl_M)) {
      /* Update for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
      sLong2MultiWord(DCmotor_Speed_Ctrl_B.DataTypeConversion1, &tmp_0.chunks[0U],
                      2);
      sMultiWordShl(&tmp_0.chunks[0U], 2, 30U, &denAccum.chunks[0U], 2);
      tmp_1 = (uint32_T)DCmotor_Speed_Ctrl_P.den_Gd[1L];
      tmp_2 = (uint32_T)DCmotor_Speed_Ctrl_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_0.chunks[0U], 2);
      MultiWordSub(&denAccum.chunks[0U], &tmp_0.chunks[0U], &denAccum_0.chunks
                   [0U], 2);
      if (DCmotor_Speed_Ctrl_P.den_Gd[0] == 0L) {
        if (sMultiWordGe(&denAccum_0.chunks[0U], &tmp_6.chunks[0U], 2)) {
          tmp = tmp_5;
        } else {
          tmp = tmp_7;
        }
      } else {
        sMultiWord2MultiWord(&denAccum_0.chunks[0U], 2,
                             &DCmotor_Speed_Ctrl_B.r2.chunks[0U], 3);
        sMultiWordShl(&DCmotor_Speed_Ctrl_B.r2.chunks[0U], 3, 30U,
                      &DCmotor_Speed_Ctrl_B.r1.chunks[0U], 3);
        sLong2MultiWord(DCmotor_Speed_Ctrl_P.den_Gd[0],
                        &DCmotor_Speed_Ctrl_B.r2.chunks[0U], 3);
        sMultiWordDivFloor(&DCmotor_Speed_Ctrl_B.r1.chunks[0U], 3,
                           &DCmotor_Speed_Ctrl_B.r2.chunks[0U], 3,
                           &DCmotor_Speed_Ctrl_B.r.chunks[0U], 4,
                           &DCmotor_Speed_Ctrl_B.r3.chunks[0U], 3,
                           &DCmotor_Speed_Ctrl_B.r4.chunks[0U], 3,
                           &tmp_3.chunks[0U], 3);
        sMultiWord2MultiWord(&DCmotor_Speed_Ctrl_B.r.chunks[0U], 4, &tmp.chunks
                             [0U], 2);
      }

      sMultiWordShr(&tmp.chunks[0U], 2, 30U, &tmp_4.chunks[0U], 2);
      DCmotor_Speed_Ctrl_DW.DiscreteTransferFcn_states = MultiWord2sLong
        (&tmp_4.chunks[0U]);

      /* End of Update for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */

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
      DCmotor_Speed_Ctrl_DW.UD_DSTATE = rtb_TSamp;
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((DCmotor_Speed_Ctrl_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(DCmotor_Speed_Ctrl_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((DCmotor_Speed_Ctrl_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(DCmotor_Speed_Ctrl_M)) {
    rt_ertODEUpdateContinuousStates(&DCmotor_Speed_Ctrl_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++DCmotor_Speed_Ctrl_M->Timing.clockTick0;
    DCmotor_Speed_Ctrl_M->Timing.t[0] = rtsiGetSolverStopTime
      (&DCmotor_Speed_Ctrl_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      DCmotor_Speed_Ctrl_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void DCmotor_Speed_Ctrl_derivatives(void)
{
  XDot_DCmotor_Speed_Ctrl_T *_rtXdot;
  _rtXdot = ((XDot_DCmotor_Speed_Ctrl_T *) DCmotor_Speed_Ctrl_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = DCmotor_Speed_Ctrl_P.TransferFcn1_A *
    DCmotor_Speed_Ctrl_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += DCmotor_Speed_Ctrl_B.Add3;
}

/* Model initialize function */
void DCmotor_Speed_Ctrl_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DCmotor_Speed_Ctrl_M->solverInfo,
                          &DCmotor_Speed_Ctrl_M->Timing.simTimeStep);
    rtsiSetTPtr(&DCmotor_Speed_Ctrl_M->solverInfo, &rtmGetTPtr
                (DCmotor_Speed_Ctrl_M));
    rtsiSetStepSizePtr(&DCmotor_Speed_Ctrl_M->solverInfo,
                       &DCmotor_Speed_Ctrl_M->Timing.stepSize0);
    rtsiSetdXPtr(&DCmotor_Speed_Ctrl_M->solverInfo,
                 &DCmotor_Speed_Ctrl_M->derivs);
    rtsiSetContStatesPtr(&DCmotor_Speed_Ctrl_M->solverInfo, (real_T **)
                         &DCmotor_Speed_Ctrl_M->contStates);
    rtsiSetNumContStatesPtr(&DCmotor_Speed_Ctrl_M->solverInfo,
      &DCmotor_Speed_Ctrl_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&DCmotor_Speed_Ctrl_M->solverInfo,
      &DCmotor_Speed_Ctrl_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&DCmotor_Speed_Ctrl_M->solverInfo,
      &DCmotor_Speed_Ctrl_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&DCmotor_Speed_Ctrl_M->solverInfo,
      &DCmotor_Speed_Ctrl_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&DCmotor_Speed_Ctrl_M->solverInfo, (boolean_T**)
      &DCmotor_Speed_Ctrl_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&DCmotor_Speed_Ctrl_M->solverInfo, (&rtmGetErrorStatus
      (DCmotor_Speed_Ctrl_M)));
    rtsiSetRTModelPtr(&DCmotor_Speed_Ctrl_M->solverInfo, DCmotor_Speed_Ctrl_M);
  }

  rtsiSetSimTimeStep(&DCmotor_Speed_Ctrl_M->solverInfo, MAJOR_TIME_STEP);
  DCmotor_Speed_Ctrl_M->intgData.y = DCmotor_Speed_Ctrl_M->odeY;
  DCmotor_Speed_Ctrl_M->intgData.f[0] = DCmotor_Speed_Ctrl_M->odeF[0];
  DCmotor_Speed_Ctrl_M->intgData.f[1] = DCmotor_Speed_Ctrl_M->odeF[1];
  DCmotor_Speed_Ctrl_M->intgData.f[2] = DCmotor_Speed_Ctrl_M->odeF[2];
  DCmotor_Speed_Ctrl_M->contStates = ((X_DCmotor_Speed_Ctrl_T *)
    &DCmotor_Speed_Ctrl_X);
  DCmotor_Speed_Ctrl_M->contStateDisabled = ((XDis_DCmotor_Speed_Ctrl_T *)
    &DCmotor_Speed_Ctrl_XDis);
  DCmotor_Speed_Ctrl_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&DCmotor_Speed_Ctrl_M->solverInfo, (void *)
                    &DCmotor_Speed_Ctrl_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&DCmotor_Speed_Ctrl_M->solverInfo, false);
  rtsiSetSolverName(&DCmotor_Speed_Ctrl_M->solverInfo,"ode3");
  rtmSetTPtr(DCmotor_Speed_Ctrl_M, &DCmotor_Speed_Ctrl_M->Timing.tArray[0]);
  rtmSetTFinal(DCmotor_Speed_Ctrl_M, -1);
  DCmotor_Speed_Ctrl_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  DCmotor_Speed_Ctrl_M->Sizes.checksums[0] = (3669627768U);
  DCmotor_Speed_Ctrl_M->Sizes.checksums[1] = (2760325395U);
  DCmotor_Speed_Ctrl_M->Sizes.checksums[2] = (1150269548U);
  DCmotor_Speed_Ctrl_M->Sizes.checksums[3] = (1861193591U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    DCmotor_Speed_Ctrl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DCmotor_Speed_Ctrl_M->extModeInfo,
      &DCmotor_Speed_Ctrl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DCmotor_Speed_Ctrl_M->extModeInfo,
                        DCmotor_Speed_Ctrl_M->Sizes.checksums);
    rteiSetTPtr(DCmotor_Speed_Ctrl_M->extModeInfo, rtmGetTPtr
                (DCmotor_Speed_Ctrl_M));
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  DCmotor_Speed_Ctrl_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
  DCmotor_Speed_Ctrl_DW.DiscreteTransferFcn_states =
    DCmotor_Speed_Ctrl_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  DCmotor_Speed_Ctrl_DW.UD_DSTATE =
    DCmotor_Speed_Ctrl_P.DiscreteDerivative_ICPrevScaled;

  /* Start for MATLABSystem: '<S1>/PWM' */
  DCmotor_Speed_Ctrl_DW.obj_m.matlabCodegenIsDeleted = false;
  DCmotor_Speed_Ctrl_DW.obj_m.isInitialized = 1L;
  DCmotor_Speed_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  DCmotor_Speed_Ctrl_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Encoder1' */
  DCmotor_Speed_Ctrl_DW.obj.Index = 0U;
  DCmotor_Speed_Ctrl_DW.obj.matlabCodegenIsDeleted = false;
  DCmotor_Speed_Ctrl_DW.obj.SampleTime = DCmotor_Speed_Ctrl_P.Ts;
  DCmotor_Speed_Ctrl_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &DCmotor_Speed_Ctrl_DW.obj.Index);
  DCmotor_Speed_Ctrl_DW.obj.isSetupComplete = true;
  DCmotor_Speed_Ctrl_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S2>/Encoder1' */
  MW_EncoderReset(DCmotor_Speed_Ctrl_DW.obj.Index);
}

/* Model terminate function */
void DCmotor_Speed_Ctrl_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/PWM' */
  if (!DCmotor_Speed_Ctrl_DW.obj_m.matlabCodegenIsDeleted) {
    DCmotor_Speed_Ctrl_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((DCmotor_Speed_Ctrl_DW.obj_m.isInitialized == 1L) &&
        DCmotor_Speed_Ctrl_DW.obj_m.isSetupComplete) {
      DCmotor_Speed_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_SetDutyCycle(DCmotor_Speed_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      DCmotor_Speed_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_Close(DCmotor_Speed_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
  /* Terminate for MATLABSystem: '<S2>/Encoder1' */
  if (!DCmotor_Speed_Ctrl_DW.obj.matlabCodegenIsDeleted) {
    DCmotor_Speed_Ctrl_DW.obj.matlabCodegenIsDeleted = true;
    if ((DCmotor_Speed_Ctrl_DW.obj.isInitialized == 1L) &&
        DCmotor_Speed_Ctrl_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Encoder1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
