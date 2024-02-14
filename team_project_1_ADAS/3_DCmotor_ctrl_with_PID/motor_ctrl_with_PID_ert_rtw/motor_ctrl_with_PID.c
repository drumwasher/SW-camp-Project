/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_ctrl_with_PID.c
 *
 * Code generated for Simulink model 'motor_ctrl_with_PID'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Feb 14 11:57:36 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_ctrl_with_PID.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "multiword_types.h"
#include "motor_ctrl_with_PID_private.h"

/* Named constants for Chart: '<S4>/Chart' */
#define motor__IN_drive_on_adas_on_LRUS (5UL)
#define motor_c_IN_drive_on_adas_on_FUS (4UL)
#define motor_c_IN_drive_on_adas_on_LUS (6UL)
#define motor_c_IN_drive_on_adas_on_RUS (7UL)
#define motor_ctrl_IN_drive_on_adas_off (2UL)
#define motor_ctrl__IN_drive_on_adas_on (3UL)
#define motor_ctrl_with_PI_IN_drive_off (1UL)

/* Named constants for Chart: '<S4>/Chart1' */
#define motor_ctrl_with_PID_IN_adas_off (1UL)
#define motor_ctrl_with_PID_IN_adas_on (2UL)
#define motor_ctrl_with__IN_adas_on_BUS (3UL)

/* Block signals (default storage) */
B_motor_ctrl_with_PID_T motor_ctrl_with_PID_B;

/* Continuous states */
X_motor_ctrl_with_PID_T motor_ctrl_with_PID_X;

/* Disabled State Vector */
XDis_motor_ctrl_with_PID_T motor_ctrl_with_PID_XDis;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  motor_ctrl_with_PID_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  motor_ctrl_with_PID_step();
  motor_ctrl_with_PID_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  motor_ctrl_with_PID_step();
  motor_ctrl_with_PID_derivatives();

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
void motor_ctrl_with_PID_step(void)
{
  /* local block i/o variables */
  int32_T rtb_TSamp;
  int32_T rtb_TSamp_g;
  if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&motor_ctrl_with_PID_M->solverInfo,
                          ((motor_ctrl_with_PID_M->Timing.clockTick0+1)*
      motor_ctrl_with_PID_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(motor_ctrl_with_PID_M)) {
    motor_ctrl_with_PID_M->Timing.t[0] = rtsiGetT
      (&motor_ctrl_with_PID_M->solverInfo);
  }

  {
    int64m_T tmp_2;
    real_T rtb_Add5;
    real_T rtb_Derivative2;
    real_T rtb_Gain1;
    real_T *lastU;
    int32_T tmp;
    uint32_T tmp_0;
    uint32_T tmp_1;
    uint16_T b_varargout_1;
    static const int64m_T tmp_3 = { { 0UL, 0UL }/* chunks */
    };

    static const int64m_T tmp_4 = { { 25UL, 0UL }/* chunks */
    };

    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
      /* Constant: '<Root>/Constant7' */
      motor_ctrl_with_PID_B.Constant7 = motor_ctrl_with_PID_P.b;

      /* Constant: '<Root>/Constant8' */
      motor_ctrl_with_PID_B.Constant8 = motor_ctrl_with_PID_P.r;

      /* Constant: '<Root>/Constant4' */
      motor_ctrl_with_PID_B.Constant4 = motor_ctrl_with_PID_P.f;

      /* Constant: '<Root>/Constant10' */
      motor_ctrl_with_PID_B.Constant10 = motor_ctrl_with_PID_P.Constant10_Value;

      /* Constant: '<Root>/Constant9' */
      motor_ctrl_with_PID_B.Constant9 = motor_ctrl_with_PID_P.Constant9_Value;
    }

    /* MATLABSystem: '<Root>/가변저항' */
    if (motor_ctrl_with_PID_DW.obj_h.SampleTime !=
        motor_ctrl_with_PID_P._SampleTime) {
      motor_ctrl_with_PID_DW.obj_h.SampleTime =
        motor_ctrl_with_PID_P._SampleTime;
    }

    motor_ctrl_with_PID_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
      MW_AnalogIn_GetHandle(62UL);
    MW_AnalogInSingle_ReadResult
      (motor_ctrl_with_PID_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
       &b_varargout_1, MW_ANALOGIN_UINT16);

    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Gain: '<S4>/Gain'
     *  MATLABSystem: '<Root>/가변저항'
     * */
    motor_ctrl_with_PID_B.DataTypeConversion = (real_T)((uint32_T)
      motor_ctrl_with_PID_P.Gain_Gain * b_varargout_1) * 7.62939453125E-6;
    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
      /* Chart: '<S4>/Chart' */
      if (motor_ctrl_with_PID_DW.is_active_c2_motor_ctrl_with_PI == 0U) {
        motor_ctrl_with_PID_DW.is_active_c2_motor_ctrl_with_PI = 1U;
        motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
          motor_ctrl_with_PI_IN_drive_off;
        motor_ctrl_with_PID_B.out1 = 0.0;
        motor_ctrl_with_PID_B.out2 = 0.0;
        motor_ctrl_with_PID_DW.steering = 0.02;
        motor_ctrl_with_PID_DW.default_n = 360.0;
      } else {
        switch (motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID) {
         case motor_ctrl_with_PI_IN_drive_off:
          if (motor_ctrl_with_PID_B.Constant9 == 1.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_ctrl_IN_drive_on_adas_off;
            motor_ctrl_with_PID_B.out1 =
              ((motor_ctrl_with_PID_B.DataTypeConversion - 128.0) / 6.4 / 100.0
               + 1.0) * motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = ((128.0 -
              motor_ctrl_with_PID_B.DataTypeConversion) / 6.4 / 100.0 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          } else {
            motor_ctrl_with_PID_B.out1 = 0.0;
            motor_ctrl_with_PID_B.out2 = 0.0;
            motor_ctrl_with_PID_DW.steering = 0.02;
            motor_ctrl_with_PID_DW.default_n = 360.0;
          }
          break;

         case motor_ctrl_IN_drive_on_adas_off:
          if (motor_ctrl_with_PID_B.Constant9 == 0.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_ctrl_with_PI_IN_drive_off;
            motor_ctrl_with_PID_B.out1 = 0.0;
            motor_ctrl_with_PID_B.out2 = 0.0;
            motor_ctrl_with_PID_DW.steering = 0.02;
            motor_ctrl_with_PID_DW.default_n = 360.0;
          } else if (motor_ctrl_with_PID_B.Constant10 == 1.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_ctrl__IN_drive_on_adas_on;
            motor_ctrl_with_PID_B.out1 = motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = motor_ctrl_with_PID_DW.default_n;
          } else {
            motor_ctrl_with_PID_B.out1 =
              ((motor_ctrl_with_PID_B.DataTypeConversion - 128.0) / 6.4 / 100.0
               + 1.0) * motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = ((128.0 -
              motor_ctrl_with_PID_B.DataTypeConversion) / 6.4 / 100.0 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          }
          break;

         case motor_ctrl__IN_drive_on_adas_on:
          if (motor_ctrl_with_PID_B.Constant10 == 0.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_ctrl_IN_drive_on_adas_off;
            motor_ctrl_with_PID_B.out1 =
              ((motor_ctrl_with_PID_B.DataTypeConversion - 128.0) / 6.4 / 100.0
               + 1.0) * motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = ((128.0 -
              motor_ctrl_with_PID_B.DataTypeConversion) / 6.4 / 100.0 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          } else if (motor_ctrl_with_PID_B.Constant4 <= 10.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_c_IN_drive_on_adas_on_FUS;
            motor_ctrl_with_PID_B.out1 = 0.0;
            motor_ctrl_with_PID_B.out2 = 0.0;
          } else if (motor_ctrl_with_PID_B.Constant7 <= 10.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_c_IN_drive_on_adas_on_RUS;
            rtb_Add5 = (10.0 - motor_ctrl_with_PID_B.Constant7) *
              motor_ctrl_with_PID_DW.steering;
            motor_ctrl_with_PID_B.out1 = (1.0 - rtb_Add5) *
              motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = (rtb_Add5 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          } else if (motor_ctrl_with_PID_B.Constant8 <= 10.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_c_IN_drive_on_adas_on_LUS;
            rtb_Add5 = (10.0 - motor_ctrl_with_PID_B.Constant8) *
              motor_ctrl_with_PID_DW.steering;
            motor_ctrl_with_PID_B.out1 = (rtb_Add5 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = (1.0 - rtb_Add5) *
              motor_ctrl_with_PID_DW.default_n;
          } else {
            motor_ctrl_with_PID_B.out1 = motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = motor_ctrl_with_PID_DW.default_n;
          }
          break;

         case motor_c_IN_drive_on_adas_on_FUS:
          if ((motor_ctrl_with_PID_B.Constant8 > 10.0) &&
              (motor_ctrl_with_PID_B.Constant7 > 10.0) &&
              (motor_ctrl_with_PID_B.Constant4 > 10.0)) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_ctrl__IN_drive_on_adas_on;
            motor_ctrl_with_PID_B.out1 = motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = motor_ctrl_with_PID_DW.default_n;
          } else if ((motor_ctrl_with_PID_B.Constant8 <= 10.0) &&
                     (motor_ctrl_with_PID_B.Constant7 <= 10.0) &&
                     (motor_ctrl_with_PID_B.Constant4 > 10.0)) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor__IN_drive_on_adas_on_LRUS;
            rtb_Add5 = (motor_ctrl_with_PID_B.Constant8 -
                        motor_ctrl_with_PID_B.Constant7) *
              motor_ctrl_with_PID_DW.steering;
            motor_ctrl_with_PID_B.out1 = (1.0 - rtb_Add5) *
              motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = (rtb_Add5 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          } else if ((motor_ctrl_with_PID_B.Constant7 <= 10.0) &&
                     (motor_ctrl_with_PID_B.Constant4 > 10.0)) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_c_IN_drive_on_adas_on_RUS;
            rtb_Add5 = (10.0 - motor_ctrl_with_PID_B.Constant7) *
              motor_ctrl_with_PID_DW.steering;
            motor_ctrl_with_PID_B.out1 = (1.0 - rtb_Add5) *
              motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = (rtb_Add5 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          } else if ((motor_ctrl_with_PID_B.Constant8 <= 10.0) &&
                     (motor_ctrl_with_PID_B.Constant4 > 10.0)) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_c_IN_drive_on_adas_on_LUS;
            rtb_Add5 = (10.0 - motor_ctrl_with_PID_B.Constant8) *
              motor_ctrl_with_PID_DW.steering;
            motor_ctrl_with_PID_B.out1 = (rtb_Add5 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = (1.0 - rtb_Add5) *
              motor_ctrl_with_PID_DW.default_n;
          } else if (motor_ctrl_with_PID_B.Constant10 == 0.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_ctrl_IN_drive_on_adas_off;
            motor_ctrl_with_PID_B.out1 =
              ((motor_ctrl_with_PID_B.DataTypeConversion - 128.0) / 6.4 / 100.0
               + 1.0) * motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = ((128.0 -
              motor_ctrl_with_PID_B.DataTypeConversion) / 6.4 / 100.0 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          } else {
            motor_ctrl_with_PID_B.out1 = 0.0;
            motor_ctrl_with_PID_B.out2 = 0.0;
          }
          break;

         case motor__IN_drive_on_adas_on_LRUS:
          if (motor_ctrl_with_PID_B.Constant4 <= 10.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_c_IN_drive_on_adas_on_FUS;
            motor_ctrl_with_PID_B.out1 = 0.0;
            motor_ctrl_with_PID_B.out2 = 0.0;
          } else if (motor_ctrl_with_PID_B.Constant7 > 10.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_c_IN_drive_on_adas_on_LUS;
            rtb_Add5 = (10.0 - motor_ctrl_with_PID_B.Constant8) *
              motor_ctrl_with_PID_DW.steering;
            motor_ctrl_with_PID_B.out1 = (rtb_Add5 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = (1.0 - rtb_Add5) *
              motor_ctrl_with_PID_DW.default_n;
          } else if (motor_ctrl_with_PID_B.Constant8 > 10.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_c_IN_drive_on_adas_on_RUS;
            rtb_Add5 = (10.0 - motor_ctrl_with_PID_B.Constant7) *
              motor_ctrl_with_PID_DW.steering;
            motor_ctrl_with_PID_B.out1 = (1.0 - rtb_Add5) *
              motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = (rtb_Add5 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          } else if (motor_ctrl_with_PID_B.Constant10 == 0.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_ctrl_IN_drive_on_adas_off;
            motor_ctrl_with_PID_B.out1 =
              ((motor_ctrl_with_PID_B.DataTypeConversion - 128.0) / 6.4 / 100.0
               + 1.0) * motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = ((128.0 -
              motor_ctrl_with_PID_B.DataTypeConversion) / 6.4 / 100.0 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          } else {
            rtb_Add5 = (motor_ctrl_with_PID_B.Constant8 -
                        motor_ctrl_with_PID_B.Constant7) *
              motor_ctrl_with_PID_DW.steering;
            motor_ctrl_with_PID_B.out1 = (1.0 - rtb_Add5) *
              motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = (rtb_Add5 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          }
          break;

         case motor_c_IN_drive_on_adas_on_LUS:
          if (motor_ctrl_with_PID_B.Constant8 > 10.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_ctrl__IN_drive_on_adas_on;
            motor_ctrl_with_PID_B.out1 = motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = motor_ctrl_with_PID_DW.default_n;
          } else if (motor_ctrl_with_PID_B.Constant7 <= 10.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor__IN_drive_on_adas_on_LRUS;
            rtb_Add5 = (motor_ctrl_with_PID_B.Constant8 -
                        motor_ctrl_with_PID_B.Constant7) *
              motor_ctrl_with_PID_DW.steering;
            motor_ctrl_with_PID_B.out1 = (1.0 - rtb_Add5) *
              motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = (rtb_Add5 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          } else if (motor_ctrl_with_PID_B.Constant4 <= 10.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_c_IN_drive_on_adas_on_FUS;
            motor_ctrl_with_PID_B.out1 = 0.0;
            motor_ctrl_with_PID_B.out2 = 0.0;
          } else if (motor_ctrl_with_PID_B.Constant10 == 0.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_ctrl_IN_drive_on_adas_off;
            motor_ctrl_with_PID_B.out1 =
              ((motor_ctrl_with_PID_B.DataTypeConversion - 128.0) / 6.4 / 100.0
               + 1.0) * motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = ((128.0 -
              motor_ctrl_with_PID_B.DataTypeConversion) / 6.4 / 100.0 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          } else {
            rtb_Add5 = (10.0 - motor_ctrl_with_PID_B.Constant8) *
              motor_ctrl_with_PID_DW.steering;
            motor_ctrl_with_PID_B.out1 = (rtb_Add5 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = (1.0 - rtb_Add5) *
              motor_ctrl_with_PID_DW.default_n;
          }
          break;

         default:
          /* case IN_drive_on_adas_on_RUS: */
          if (motor_ctrl_with_PID_B.Constant7 > 10.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_ctrl__IN_drive_on_adas_on;
            motor_ctrl_with_PID_B.out1 = motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = motor_ctrl_with_PID_DW.default_n;
          } else if (motor_ctrl_with_PID_B.Constant4 <= 10.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_c_IN_drive_on_adas_on_FUS;
            motor_ctrl_with_PID_B.out1 = 0.0;
            motor_ctrl_with_PID_B.out2 = 0.0;
          } else if (motor_ctrl_with_PID_B.Constant8 <= 10.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor__IN_drive_on_adas_on_LRUS;
            rtb_Add5 = (motor_ctrl_with_PID_B.Constant8 -
                        motor_ctrl_with_PID_B.Constant7) *
              motor_ctrl_with_PID_DW.steering;
            motor_ctrl_with_PID_B.out1 = (1.0 - rtb_Add5) *
              motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = (rtb_Add5 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          } else if (motor_ctrl_with_PID_B.Constant10 == 0.0) {
            motor_ctrl_with_PID_DW.is_c2_motor_ctrl_with_PID =
              motor_ctrl_IN_drive_on_adas_off;
            motor_ctrl_with_PID_B.out1 =
              ((motor_ctrl_with_PID_B.DataTypeConversion - 128.0) / 6.4 / 100.0
               + 1.0) * motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = ((128.0 -
              motor_ctrl_with_PID_B.DataTypeConversion) / 6.4 / 100.0 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          } else {
            rtb_Add5 = (10.0 - motor_ctrl_with_PID_B.Constant7) *
              motor_ctrl_with_PID_DW.steering;
            motor_ctrl_with_PID_B.out1 = (1.0 - rtb_Add5) *
              motor_ctrl_with_PID_DW.default_n;
            motor_ctrl_with_PID_B.out2 = (rtb_Add5 + 1.0) *
              motor_ctrl_with_PID_DW.default_n;
          }
          break;
        }
      }

      /* End of Chart: '<S4>/Chart' */

      /* Constant: '<Root>/Constant6' */
      motor_ctrl_with_PID_B.Constant6 = motor_ctrl_with_PID_P.l;

      /* Chart: '<S4>/Chart1' */
      if (motor_ctrl_with_PID_DW.is_active_c5_motor_ctrl_with_PI == 0U) {
        motor_ctrl_with_PID_DW.is_active_c5_motor_ctrl_with_PI = 1U;
        motor_ctrl_with_PID_DW.is_c5_motor_ctrl_with_PID =
          motor_ctrl_with_PID_IN_adas_off;
        motor_ctrl_with_PID_B.rout1 = motor_ctrl_with_PID_B.out1;
        motor_ctrl_with_PID_B.rout2 = motor_ctrl_with_PID_B.out2;
      } else {
        switch (motor_ctrl_with_PID_DW.is_c5_motor_ctrl_with_PID) {
         case motor_ctrl_with_PID_IN_adas_off:
          if (motor_ctrl_with_PID_B.Constant10 == 1.0) {
            motor_ctrl_with_PID_DW.is_c5_motor_ctrl_with_PID =
              motor_ctrl_with_PID_IN_adas_on;
            motor_ctrl_with_PID_B.rout1 = motor_ctrl_with_PID_B.out1;
            motor_ctrl_with_PID_B.rout2 = motor_ctrl_with_PID_B.out2;
          } else {
            motor_ctrl_with_PID_B.rout1 = motor_ctrl_with_PID_B.out1;
            motor_ctrl_with_PID_B.rout2 = motor_ctrl_with_PID_B.out2;
          }
          break;

         case motor_ctrl_with_PID_IN_adas_on:
          if (motor_ctrl_with_PID_B.Constant10 == 0.0) {
            motor_ctrl_with_PID_DW.is_c5_motor_ctrl_with_PID =
              motor_ctrl_with_PID_IN_adas_off;
            motor_ctrl_with_PID_B.rout1 = motor_ctrl_with_PID_B.out1;
            motor_ctrl_with_PID_B.rout2 = motor_ctrl_with_PID_B.out2;
          } else if (motor_ctrl_with_PID_B.Constant6 <= 10.0) {
            motor_ctrl_with_PID_DW.is_c5_motor_ctrl_with_PID =
              motor_ctrl_with__IN_adas_on_BUS;
            motor_ctrl_with_PID_B.rout1 = motor_ctrl_with_PID_B.out1 * 1.2;
            motor_ctrl_with_PID_B.rout2 = motor_ctrl_with_PID_B.out2 * 1.2;
          } else {
            motor_ctrl_with_PID_B.rout1 = motor_ctrl_with_PID_B.out1;
            motor_ctrl_with_PID_B.rout2 = motor_ctrl_with_PID_B.out2;
          }
          break;

         default:
          /* case IN_adas_on_BUS: */
          if (motor_ctrl_with_PID_B.Constant6 > 10.0) {
            motor_ctrl_with_PID_DW.is_c5_motor_ctrl_with_PID =
              motor_ctrl_with_PID_IN_adas_on;
            motor_ctrl_with_PID_B.rout1 = motor_ctrl_with_PID_B.out1;
            motor_ctrl_with_PID_B.rout2 = motor_ctrl_with_PID_B.out2;
          } else if (motor_ctrl_with_PID_B.Constant10 == 0.0) {
            motor_ctrl_with_PID_DW.is_c5_motor_ctrl_with_PID =
              motor_ctrl_with_PID_IN_adas_off;
            motor_ctrl_with_PID_B.rout1 = motor_ctrl_with_PID_B.out1;
            motor_ctrl_with_PID_B.rout2 = motor_ctrl_with_PID_B.out2;
          } else {
            motor_ctrl_with_PID_B.rout1 = motor_ctrl_with_PID_B.out1 * 1.2;
            motor_ctrl_with_PID_B.rout2 = motor_ctrl_with_PID_B.out2 * 1.2;
          }
          break;
        }
      }

      /* End of Chart: '<S4>/Chart1' */

      /* DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn' */
      motor_ctrl_with_PID_B.DiscreteTransferFcn = tmp_3;

      /* DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn' */
      tmp_0 = (uint32_T)motor_ctrl_with_PID_P.num_Gd[1L];
      tmp_1 = (uint32_T)motor_ctrl_with_PID_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp_0, 1, &tmp_1, 1,
                    &motor_ctrl_with_PID_B.DiscreteTransferFcn.chunks[0U], 2);

      /* Sum: '<Root>/Add3' incorporates:
       *  DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn'
       */
      rtb_Add5 = motor_ctrl_with_PID_B.rout1 - sMultiWord2Double
        (&motor_ctrl_with_PID_B.DiscreteTransferFcn.chunks[0U], 2, 0) *
        1.1641532182693481E-10;

      /* Gain: '<S7>/Gain2' */
      motor_ctrl_with_PID_B.Gain2_k = motor_ctrl_with_PID_P.KP * rtb_Add5;

      /* Gain: '<S7>/Gain3' */
      motor_ctrl_with_PID_B.Gain3 = motor_ctrl_with_PID_P.KD * rtb_Add5;
    }

    /* Derivative: '<S7>/Derivative2' incorporates:
     *  Derivative: '<S3>/Derivative2'
     */
    rtb_Derivative2 = motor_ctrl_with_PID_M->Timing.t[0];
    if ((motor_ctrl_with_PID_DW.TimeStampA >= rtb_Derivative2) &&
        (motor_ctrl_with_PID_DW.TimeStampB >= rtb_Derivative2)) {
      rtb_Gain1 = 0.0;
    } else {
      rtb_Gain1 = motor_ctrl_with_PID_DW.TimeStampA;
      lastU = &motor_ctrl_with_PID_DW.LastUAtTimeA;
      if (motor_ctrl_with_PID_DW.TimeStampA < motor_ctrl_with_PID_DW.TimeStampB)
      {
        if (motor_ctrl_with_PID_DW.TimeStampB < rtb_Derivative2) {
          rtb_Gain1 = motor_ctrl_with_PID_DW.TimeStampB;
          lastU = &motor_ctrl_with_PID_DW.LastUAtTimeB;
        }
      } else if (motor_ctrl_with_PID_DW.TimeStampA >= rtb_Derivative2) {
        rtb_Gain1 = motor_ctrl_with_PID_DW.TimeStampB;
        lastU = &motor_ctrl_with_PID_DW.LastUAtTimeB;
      }

      rtb_Gain1 = (motor_ctrl_with_PID_B.Gain3 - *lastU) / (rtb_Derivative2 -
        rtb_Gain1);
    }

    /* End of Derivative: '<S7>/Derivative2' */

    /* Sum: '<S7>/Subtract2' incorporates:
     *  Integrator: '<S7>/Integrator2'
     */
    motor_ctrl_with_PID_B.Subtract2 = (motor_ctrl_with_PID_X.Integrator2_CSTATE
      + motor_ctrl_with_PID_B.Gain2_k) + rtb_Gain1;
    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
    }

    /* Saturate: '<Root>/Saturation1' */
    if (motor_ctrl_with_PID_B.Subtract2 >
        motor_ctrl_with_PID_P.Saturation1_UpperSat) {
      /* Saturate: '<Root>/Saturation1' */
      motor_ctrl_with_PID_B.Saturation1 =
        motor_ctrl_with_PID_P.Saturation1_UpperSat;
    } else if (motor_ctrl_with_PID_B.Subtract2 <
               motor_ctrl_with_PID_P.Saturation1_LowerSat) {
      /* Saturate: '<Root>/Saturation1' */
      motor_ctrl_with_PID_B.Saturation1 =
        motor_ctrl_with_PID_P.Saturation1_LowerSat;
    } else {
      /* Saturate: '<Root>/Saturation1' */
      motor_ctrl_with_PID_B.Saturation1 = motor_ctrl_with_PID_B.Subtract2;
    }

    /* End of Saturate: '<Root>/Saturation1' */

    /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
     *  Gain: '<S6>/Gain1'
     */
    rtb_Gain1 = floor(255.0 / motor_ctrl_with_PID_P.Vlim *
                      motor_ctrl_with_PID_B.Saturation1);
    if (rtIsNaN(rtb_Gain1) || rtIsInf(rtb_Gain1)) {
      rtb_Gain1 = 0.0;
    } else {
      rtb_Gain1 = fmod(rtb_Gain1, 256.0);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    motor_ctrl_with_PID_B.DataTypeConversion_h = (uint8_T)(rtb_Gain1 < 0.0 ?
      (int16_T)(uint8_T)-(int8_T)(uint8_T)-rtb_Gain1 : (int16_T)(uint8_T)
      rtb_Gain1);

    /* DataTypeConversion: '<S6>/Data Type Conversion1' */
    motor_ctrl_with_PID_B.DataTypeConversion1 =
      motor_ctrl_with_PID_B.DataTypeConversion_h;
    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
    }

    /* MATLABSystem: '<S6>/PWM' */
    motor_ctrl_with_PID_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (11UL);
    MW_PWM_SetDutyCycle(motor_ctrl_with_PID_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)motor_ctrl_with_PID_B.DataTypeConversion_h);
    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
      /* Gain: '<S7>/Gain1' */
      motor_ctrl_with_PID_B.Gain1_e = motor_ctrl_with_PID_P.KI * rtb_Add5;

      /* DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
      motor_ctrl_with_PID_B.DiscreteTransferFcn_l = tmp_3;

      /* DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
      tmp_0 = (uint32_T)motor_ctrl_with_PID_P.num_Gd[1L];
      tmp_1 = (uint32_T)motor_ctrl_with_PID_DW.DiscreteTransferFcn_states_g;
      sMultiWordMul(&tmp_0, 1, &tmp_1, 1,
                    &motor_ctrl_with_PID_B.DiscreteTransferFcn_l.chunks[0U], 2);

      /* Sum: '<Root>/Add5' incorporates:
       *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn'
       */
      rtb_Add5 = motor_ctrl_with_PID_B.rout2 - sMultiWord2Double
        (&motor_ctrl_with_PID_B.DiscreteTransferFcn_l.chunks[0U], 2, 0) *
        1.1641532182693481E-10;

      /* Gain: '<S3>/Gain2' */
      motor_ctrl_with_PID_B.Gain2_n = motor_ctrl_with_PID_P.KP * rtb_Add5;

      /* Gain: '<S3>/Gain3' */
      motor_ctrl_with_PID_B.Gain3_g = motor_ctrl_with_PID_P.KD * rtb_Add5;
    }

    /* Derivative: '<S3>/Derivative2' */
    if ((motor_ctrl_with_PID_DW.TimeStampA_c >= rtb_Derivative2) &&
        (motor_ctrl_with_PID_DW.TimeStampB_g >= rtb_Derivative2)) {
      rtb_Derivative2 = 0.0;
    } else {
      rtb_Gain1 = motor_ctrl_with_PID_DW.TimeStampA_c;
      lastU = &motor_ctrl_with_PID_DW.LastUAtTimeA_b;
      if (motor_ctrl_with_PID_DW.TimeStampA_c <
          motor_ctrl_with_PID_DW.TimeStampB_g) {
        if (motor_ctrl_with_PID_DW.TimeStampB_g < rtb_Derivative2) {
          rtb_Gain1 = motor_ctrl_with_PID_DW.TimeStampB_g;
          lastU = &motor_ctrl_with_PID_DW.LastUAtTimeB_p;
        }
      } else if (motor_ctrl_with_PID_DW.TimeStampA_c >= rtb_Derivative2) {
        rtb_Gain1 = motor_ctrl_with_PID_DW.TimeStampB_g;
        lastU = &motor_ctrl_with_PID_DW.LastUAtTimeB_p;
      }

      rtb_Derivative2 = (motor_ctrl_with_PID_B.Gain3_g - *lastU) /
        (rtb_Derivative2 - rtb_Gain1);
    }

    /* Sum: '<S3>/Subtract2' incorporates:
     *  Integrator: '<S3>/Integrator2'
     */
    motor_ctrl_with_PID_B.Subtract2_c =
      (motor_ctrl_with_PID_X.Integrator2_CSTATE_i +
       motor_ctrl_with_PID_B.Gain2_n) + rtb_Derivative2;
    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
    }

    /* Saturate: '<Root>/Saturation2' */
    if (motor_ctrl_with_PID_B.Subtract2_c >
        motor_ctrl_with_PID_P.Saturation2_UpperSat) {
      /* Saturate: '<Root>/Saturation2' */
      motor_ctrl_with_PID_B.Saturation2 =
        motor_ctrl_with_PID_P.Saturation2_UpperSat;
    } else if (motor_ctrl_with_PID_B.Subtract2_c <
               motor_ctrl_with_PID_P.Saturation2_LowerSat) {
      /* Saturate: '<Root>/Saturation2' */
      motor_ctrl_with_PID_B.Saturation2 =
        motor_ctrl_with_PID_P.Saturation2_LowerSat;
    } else {
      /* Saturate: '<Root>/Saturation2' */
      motor_ctrl_with_PID_B.Saturation2 = motor_ctrl_with_PID_B.Subtract2_c;
    }

    /* End of Saturate: '<Root>/Saturation2' */

    /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
     *  Gain: '<S2>/Gain1'
     */
    rtb_Derivative2 = floor(255.0 / motor_ctrl_with_PID_P.Vlim *
      motor_ctrl_with_PID_B.Saturation2);
    if (rtIsNaN(rtb_Derivative2) || rtIsInf(rtb_Derivative2)) {
      rtb_Derivative2 = 0.0;
    } else {
      rtb_Derivative2 = fmod(rtb_Derivative2, 256.0);
    }

    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    motor_ctrl_with_PID_B.DataTypeConversion_g = (uint8_T)(rtb_Derivative2 < 0.0
      ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-rtb_Derivative2 : (int16_T)(uint8_T)
      rtb_Derivative2);

    /* DataTypeConversion: '<S2>/Data Type Conversion1' */
    motor_ctrl_with_PID_B.DataTypeConversion1_n =
      motor_ctrl_with_PID_B.DataTypeConversion_g;
    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
    }

    /* MATLABSystem: '<S2>/PWM' */
    motor_ctrl_with_PID_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (3UL);
    MW_PWM_SetDutyCycle(motor_ctrl_with_PID_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)motor_ctrl_with_PID_B.DataTypeConversion_g);
    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
      /* Gain: '<S3>/Gain1' */
      motor_ctrl_with_PID_B.Gain1_j = motor_ctrl_with_PID_P.KI * rtb_Add5;
    }

    /* MATLABSystem: '<S5>/Encoder' */
    if (motor_ctrl_with_PID_DW.obj.SampleTime !=
        motor_ctrl_with_PID_P.Encoder_SampleTime_a) {
      motor_ctrl_with_PID_DW.obj.SampleTime =
        motor_ctrl_with_PID_P.Encoder_SampleTime_a;
    }

    if (motor_ctrl_with_PID_DW.obj.TunablePropsChanged) {
      motor_ctrl_with_PID_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(motor_ctrl_with_PID_DW.obj.Index, &tmp);
    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
      /* SampleTimeMath: '<S11>/TSamp' incorporates:
       *  MATLABSystem: '<S5>/Encoder'
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

      /* Gain: '<S5>/Gain1' incorporates:
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
      tmp_0 = (uint32_T)motor_ctrl_with_PID_P.encoder_scale;
      tmp_1 = (uint32_T)(rtb_TSamp - motor_ctrl_with_PID_DW.UD_DSTATE);
      sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &motor_ctrl_with_PID_B.Gain1.chunks[0U],
                    2);

      /* Gain: '<S5>/Gain2' incorporates:
       *  Gain: '<S5>/Gain1'
       */
      sMultiWordMul(&motor_ctrl_with_PID_P.Gain2_Gain.chunks[0U], 2,
                    &motor_ctrl_with_PID_B.Gain1.chunks[0U], 2,
                    &motor_ctrl_with_PID_B.Gain2.chunks[0U], 4);

      /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
       *  Gain: '<S5>/Gain1'
       */
      tmp_2 = motor_ctrl_with_PID_B.Gain1;
      sMultiWordMul(&motor_ctrl_with_PID_B.Gain1.chunks[0U], 2, &tmp_4.chunks[0U],
                    2, &motor_ctrl_with_PID_B.r2.chunks[0U], 4);
      sMultiWordShr(&motor_ctrl_with_PID_B.r2.chunks[0U], 4, 31U,
                    &motor_ctrl_with_PID_B.r1.chunks[0U], 4);

      /* DataTypeConversion: '<S5>/Data Type Conversion1' */
      motor_ctrl_with_PID_B.DataTypeConversion1_m = MultiWord2sLong
        (&motor_ctrl_with_PID_B.r1.chunks[0U]);
    }

    /* MATLABSystem: '<S1>/Encoder' */
    if (motor_ctrl_with_PID_DW.obj_d.SampleTime !=
        motor_ctrl_with_PID_P.Encoder_SampleTime) {
      motor_ctrl_with_PID_DW.obj_d.SampleTime =
        motor_ctrl_with_PID_P.Encoder_SampleTime;
    }

    if (motor_ctrl_with_PID_DW.obj_d.TunablePropsChanged) {
      motor_ctrl_with_PID_DW.obj_d.TunablePropsChanged = false;
    }

    MW_EncoderRead(motor_ctrl_with_PID_DW.obj_d.Index, &tmp);
    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
      /* SampleTimeMath: '<S8>/TSamp' incorporates:
       *  MATLABSystem: '<S1>/Encoder'
       *
       * About '<S8>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       */
      rtb_TSamp_g = tmp;

      /* Gain: '<S1>/Gain1' incorporates:
       *  SampleTimeMath: '<S8>/TSamp'
       *  Sum: '<S8>/Diff'
       *  UnitDelay: '<S8>/UD'
       *
       * About '<S8>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S8>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S8>/UD':
       *
       *  Store in Global RAM
       */
      tmp_0 = (uint32_T)motor_ctrl_with_PID_P.encoder_scale;
      tmp_1 = (uint32_T)(rtb_TSamp_g - motor_ctrl_with_PID_DW.UD_DSTATE_f);
      sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp_2.chunks[0U], 2);

      /* Gain: '<S1>/Gain1' incorporates:
       *  Gain: '<S5>/Gain2'
       */
      motor_ctrl_with_PID_B.Gain1_h = tmp_2;

      /* Gain: '<S1>/Gain2' incorporates:
       *  Gain: '<S1>/Gain1'
       */
      sMultiWordMul(&motor_ctrl_with_PID_P.Gain2_Gain_g.chunks[0U], 2,
                    &motor_ctrl_with_PID_B.Gain1_h.chunks[0U], 2,
                    &motor_ctrl_with_PID_B.r2.chunks[0U], 4);

      /* Gain: '<S1>/Gain2' incorporates:
       *  DataTypeConversion: '<S5>/Data Type Conversion1'
       */
      motor_ctrl_with_PID_B.Gain2_j = motor_ctrl_with_PID_B.r2;

      /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
       *  Gain: '<S1>/Gain1'
       */
      sMultiWordMul(&motor_ctrl_with_PID_B.Gain1_h.chunks[0U], 2, &tmp_4.chunks
                    [0U], 2, &motor_ctrl_with_PID_B.r4.chunks[0U], 4);
      sMultiWordShr(&motor_ctrl_with_PID_B.r4.chunks[0U], 4, 31U,
                    &motor_ctrl_with_PID_B.r3.chunks[0U], 4);

      /* DataTypeConversion: '<S1>/Data Type Conversion1' */
      motor_ctrl_with_PID_B.DataTypeConversion1_l = MultiWord2sLong
        (&motor_ctrl_with_PID_B.r3.chunks[0U]);
    }
  }

  if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
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

    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
      /* Update for DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn' */
      sLong2MultiWord(motor_ctrl_with_PID_B.DataTypeConversion1_m,
                      &motor_ctrl_with_PID_B.r12.chunks[0U], 2);
      sMultiWordShl(&motor_ctrl_with_PID_B.r12.chunks[0U], 2, 30U,
                    &motor_ctrl_with_PID_B.denAccum.chunks[0U], 2);
      tmp = (uint32_T)motor_ctrl_with_PID_P.den_Gd[1L];
      tmp_0 = (uint32_T)motor_ctrl_with_PID_DW.DiscreteTransferFcn_states;
      sMultiWordMul(&tmp, 1, &tmp_0, 1, &motor_ctrl_with_PID_B.r12.chunks[0U], 2);
      MultiWordSub(&motor_ctrl_with_PID_B.denAccum.chunks[0U],
                   &motor_ctrl_with_PID_B.r12.chunks[0U], &denAccum.chunks[0U],
                   2);
      motor_ctrl_with_PID_B.denAccum = denAccum;
      if (motor_ctrl_with_PID_P.den_Gd[0] == 0L) {
        if (sMultiWordGe(&motor_ctrl_with_PID_B.denAccum.chunks[0U],
                         &tmp_5.chunks[0U], 2)) {
          motor_ctrl_with_PID_B.r11 = tmp_4;
        } else {
          motor_ctrl_with_PID_B.r11 = tmp_6;
        }
      } else {
        sMultiWord2MultiWord(&motor_ctrl_with_PID_B.denAccum.chunks[0U], 2,
                             &motor_ctrl_with_PID_B.r6.chunks[0U], 3);
        sMultiWordShl(&motor_ctrl_with_PID_B.r6.chunks[0U], 3, 30U,
                      &motor_ctrl_with_PID_B.r5.chunks[0U], 3);
        sLong2MultiWord(motor_ctrl_with_PID_P.den_Gd[0],
                        &motor_ctrl_with_PID_B.r6.chunks[0U], 3);
        sMultiWordDivFloor(&motor_ctrl_with_PID_B.r5.chunks[0U], 3,
                           &motor_ctrl_with_PID_B.r6.chunks[0U], 3,
                           &motor_ctrl_with_PID_B.r.chunks[0U], 4,
                           &motor_ctrl_with_PID_B.r7.chunks[0U], 3,
                           &motor_ctrl_with_PID_B.r8.chunks[0U], 3,
                           &motor_ctrl_with_PID_B.r9.chunks[0U], 3);
        sMultiWord2MultiWord(&motor_ctrl_with_PID_B.r.chunks[0U], 4,
                             &motor_ctrl_with_PID_B.r11.chunks[0U], 2);
      }

      sMultiWordShr(&motor_ctrl_with_PID_B.r11.chunks[0U], 2, 30U,
                    &tmp_1.chunks[0U], 2);
      motor_ctrl_with_PID_DW.DiscreteTransferFcn_states = MultiWord2sLong
        (&tmp_1.chunks[0U]);

      /* End of Update for DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn' */
    }

    /* Update for Derivative: '<S7>/Derivative2' */
    if (motor_ctrl_with_PID_DW.TimeStampA == (rtInf)) {
      motor_ctrl_with_PID_DW.TimeStampA = motor_ctrl_with_PID_M->Timing.t[0];
      lastU = &motor_ctrl_with_PID_DW.LastUAtTimeA;
    } else if (motor_ctrl_with_PID_DW.TimeStampB == (rtInf)) {
      motor_ctrl_with_PID_DW.TimeStampB = motor_ctrl_with_PID_M->Timing.t[0];
      lastU = &motor_ctrl_with_PID_DW.LastUAtTimeB;
    } else if (motor_ctrl_with_PID_DW.TimeStampA <
               motor_ctrl_with_PID_DW.TimeStampB) {
      motor_ctrl_with_PID_DW.TimeStampA = motor_ctrl_with_PID_M->Timing.t[0];
      lastU = &motor_ctrl_with_PID_DW.LastUAtTimeA;
    } else {
      motor_ctrl_with_PID_DW.TimeStampB = motor_ctrl_with_PID_M->Timing.t[0];
      lastU = &motor_ctrl_with_PID_DW.LastUAtTimeB;
    }

    *lastU = motor_ctrl_with_PID_B.Gain3;

    /* End of Update for Derivative: '<S7>/Derivative2' */
    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
      /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
      sLong2MultiWord(motor_ctrl_with_PID_B.DataTypeConversion1_l,
                      &tmp_2.chunks[0U], 2);
      sMultiWordShl(&tmp_2.chunks[0U], 2, 30U,
                    &motor_ctrl_with_PID_B.denAccum.chunks[0U], 2);
      tmp = (uint32_T)motor_ctrl_with_PID_P.den_Gd[1L];
      tmp_0 = (uint32_T)motor_ctrl_with_PID_DW.DiscreteTransferFcn_states_g;
      sMultiWordMul(&tmp, 1, &tmp_0, 1, &tmp_2.chunks[0U], 2);
      MultiWordSub(&motor_ctrl_with_PID_B.denAccum.chunks[0U], &tmp_2.chunks[0U],
                   &denAccum_0.chunks[0U], 2);
      if (motor_ctrl_with_PID_P.den_Gd[0] == 0L) {
        if (sMultiWordGe(&denAccum_0.chunks[0U], &tmp_5.chunks[0U], 2)) {
          motor_ctrl_with_PID_B.r10 = tmp_4;
        } else {
          motor_ctrl_with_PID_B.r10 = tmp_6;
        }
      } else {
        sMultiWord2MultiWord(&denAccum_0.chunks[0U], 2,
                             &motor_ctrl_with_PID_B.r6.chunks[0U], 3);
        sMultiWordShl(&motor_ctrl_with_PID_B.r6.chunks[0U], 3, 30U,
                      &motor_ctrl_with_PID_B.r5.chunks[0U], 3);
        sLong2MultiWord(motor_ctrl_with_PID_P.den_Gd[0],
                        &motor_ctrl_with_PID_B.r6.chunks[0U], 3);
        sMultiWordDivFloor(&motor_ctrl_with_PID_B.r5.chunks[0U], 3,
                           &motor_ctrl_with_PID_B.r6.chunks[0U], 3,
                           &motor_ctrl_with_PID_B.r.chunks[0U], 4,
                           &motor_ctrl_with_PID_B.r7.chunks[0U], 3,
                           &motor_ctrl_with_PID_B.r8.chunks[0U], 3,
                           &motor_ctrl_with_PID_B.r9.chunks[0U], 3);
        sMultiWord2MultiWord(&motor_ctrl_with_PID_B.r.chunks[0U], 4,
                             &motor_ctrl_with_PID_B.r10.chunks[0U], 2);
      }

      sMultiWordShr(&motor_ctrl_with_PID_B.r10.chunks[0U], 2, 30U,
                    &tmp_3.chunks[0U], 2);
      motor_ctrl_with_PID_DW.DiscreteTransferFcn_states_g = MultiWord2sLong
        (&tmp_3.chunks[0U]);

      /* End of Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
    }

    /* Update for Derivative: '<S3>/Derivative2' */
    if (motor_ctrl_with_PID_DW.TimeStampA_c == (rtInf)) {
      motor_ctrl_with_PID_DW.TimeStampA_c = motor_ctrl_with_PID_M->Timing.t[0];
      lastU = &motor_ctrl_with_PID_DW.LastUAtTimeA_b;
    } else if (motor_ctrl_with_PID_DW.TimeStampB_g == (rtInf)) {
      motor_ctrl_with_PID_DW.TimeStampB_g = motor_ctrl_with_PID_M->Timing.t[0];
      lastU = &motor_ctrl_with_PID_DW.LastUAtTimeB_p;
    } else if (motor_ctrl_with_PID_DW.TimeStampA_c <
               motor_ctrl_with_PID_DW.TimeStampB_g) {
      motor_ctrl_with_PID_DW.TimeStampA_c = motor_ctrl_with_PID_M->Timing.t[0];
      lastU = &motor_ctrl_with_PID_DW.LastUAtTimeA_b;
    } else {
      motor_ctrl_with_PID_DW.TimeStampB_g = motor_ctrl_with_PID_M->Timing.t[0];
      lastU = &motor_ctrl_with_PID_DW.LastUAtTimeB_p;
    }

    *lastU = motor_ctrl_with_PID_B.Gain3_g;

    /* End of Update for Derivative: '<S3>/Derivative2' */
    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
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
      motor_ctrl_with_PID_DW.UD_DSTATE = rtb_TSamp;

      /* Update for UnitDelay: '<S8>/UD' incorporates:
       *  SampleTimeMath: '<S8>/TSamp'
       *
       * About '<S8>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S8>/UD':
       *
       *  Store in Global RAM
       */
      motor_ctrl_with_PID_DW.UD_DSTATE_f = rtb_TSamp_g;
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
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

    if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {/* Sample time: [0.01s, 0.0s] */
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
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(motor_ctrl_with_PID_M)) {
    rt_ertODEUpdateContinuousStates(&motor_ctrl_with_PID_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++motor_ctrl_with_PID_M->Timing.clockTick0;
    motor_ctrl_with_PID_M->Timing.t[0] = rtsiGetSolverStopTime
      (&motor_ctrl_with_PID_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      motor_ctrl_with_PID_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void motor_ctrl_with_PID_derivatives(void)
{
  XDot_motor_ctrl_with_PID_T *_rtXdot;
  _rtXdot = ((XDot_motor_ctrl_with_PID_T *) motor_ctrl_with_PID_M->derivs);

  /* Derivatives for Integrator: '<S7>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = motor_ctrl_with_PID_B.Gain1_e;

  /* Derivatives for Integrator: '<S3>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_i = motor_ctrl_with_PID_B.Gain1_j;
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
    rtsiSetdXPtr(&motor_ctrl_with_PID_M->solverInfo,
                 &motor_ctrl_with_PID_M->derivs);
    rtsiSetContStatesPtr(&motor_ctrl_with_PID_M->solverInfo, (real_T **)
                         &motor_ctrl_with_PID_M->contStates);
    rtsiSetNumContStatesPtr(&motor_ctrl_with_PID_M->solverInfo,
      &motor_ctrl_with_PID_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&motor_ctrl_with_PID_M->solverInfo,
      &motor_ctrl_with_PID_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&motor_ctrl_with_PID_M->solverInfo,
      &motor_ctrl_with_PID_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&motor_ctrl_with_PID_M->solverInfo,
      &motor_ctrl_with_PID_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&motor_ctrl_with_PID_M->solverInfo, (boolean_T**)
      &motor_ctrl_with_PID_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&motor_ctrl_with_PID_M->solverInfo,
                          (&rtmGetErrorStatus(motor_ctrl_with_PID_M)));
    rtsiSetRTModelPtr(&motor_ctrl_with_PID_M->solverInfo, motor_ctrl_with_PID_M);
  }

  rtsiSetSimTimeStep(&motor_ctrl_with_PID_M->solverInfo, MAJOR_TIME_STEP);
  motor_ctrl_with_PID_M->intgData.y = motor_ctrl_with_PID_M->odeY;
  motor_ctrl_with_PID_M->intgData.f[0] = motor_ctrl_with_PID_M->odeF[0];
  motor_ctrl_with_PID_M->intgData.f[1] = motor_ctrl_with_PID_M->odeF[1];
  motor_ctrl_with_PID_M->intgData.f[2] = motor_ctrl_with_PID_M->odeF[2];
  motor_ctrl_with_PID_M->contStates = ((X_motor_ctrl_with_PID_T *)
    &motor_ctrl_with_PID_X);
  motor_ctrl_with_PID_M->contStateDisabled = ((XDis_motor_ctrl_with_PID_T *)
    &motor_ctrl_with_PID_XDis);
  motor_ctrl_with_PID_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&motor_ctrl_with_PID_M->solverInfo, (void *)
                    &motor_ctrl_with_PID_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&motor_ctrl_with_PID_M->solverInfo, false);
  rtsiSetSolverName(&motor_ctrl_with_PID_M->solverInfo,"ode3");
  rtmSetTPtr(motor_ctrl_with_PID_M, &motor_ctrl_with_PID_M->Timing.tArray[0]);
  rtmSetTFinal(motor_ctrl_with_PID_M, -1);
  motor_ctrl_with_PID_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  motor_ctrl_with_PID_M->Sizes.checksums[0] = (3090545905U);
  motor_ctrl_with_PID_M->Sizes.checksums[1] = (1828928126U);
  motor_ctrl_with_PID_M->Sizes.checksums[2] = (3700948376U);
  motor_ctrl_with_PID_M->Sizes.checksums[3] = (3192649003U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    motor_ctrl_with_PID_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motor_ctrl_with_PID_M->extModeInfo,
      &motor_ctrl_with_PID_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motor_ctrl_with_PID_M->extModeInfo,
                        motor_ctrl_with_PID_M->Sizes.checksums);
    rteiSetTPtr(motor_ctrl_with_PID_M->extModeInfo, rtmGetTPtr
                (motor_ctrl_with_PID_M));
  }

  /* Start for Constant: '<Root>/Constant7' */
  motor_ctrl_with_PID_B.Constant7 = motor_ctrl_with_PID_P.b;

  /* Start for Constant: '<Root>/Constant8' */
  motor_ctrl_with_PID_B.Constant8 = motor_ctrl_with_PID_P.r;

  /* Start for Constant: '<Root>/Constant4' */
  motor_ctrl_with_PID_B.Constant4 = motor_ctrl_with_PID_P.f;

  /* Start for Constant: '<Root>/Constant10' */
  motor_ctrl_with_PID_B.Constant10 = motor_ctrl_with_PID_P.Constant10_Value;

  /* Start for Constant: '<Root>/Constant9' */
  motor_ctrl_with_PID_B.Constant9 = motor_ctrl_with_PID_P.Constant9_Value;

  /* Start for Constant: '<Root>/Constant6' */
  motor_ctrl_with_PID_B.Constant6 = motor_ctrl_with_PID_P.l;

  /* InitializeConditions for DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn' */
  motor_ctrl_with_PID_DW.DiscreteTransferFcn_states =
    motor_ctrl_with_PID_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for Integrator: '<S7>/Integrator2' */
  motor_ctrl_with_PID_X.Integrator2_CSTATE =
    motor_ctrl_with_PID_P.Integrator2_IC;

  /* InitializeConditions for Derivative: '<S7>/Derivative2' */
  motor_ctrl_with_PID_DW.TimeStampA = (rtInf);
  motor_ctrl_with_PID_DW.TimeStampB = (rtInf);

  /* InitializeConditions for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
  motor_ctrl_with_PID_DW.DiscreteTransferFcn_states_g =
    motor_ctrl_with_PID_P.DiscreteTransferFcn_InitialSt_p;

  /* InitializeConditions for Integrator: '<S3>/Integrator2' */
  motor_ctrl_with_PID_X.Integrator2_CSTATE_i =
    motor_ctrl_with_PID_P.Integrator2_IC_g;

  /* InitializeConditions for Derivative: '<S3>/Derivative2' */
  motor_ctrl_with_PID_DW.TimeStampA_c = (rtInf);
  motor_ctrl_with_PID_DW.TimeStampB_g = (rtInf);

  /* InitializeConditions for UnitDelay: '<S11>/UD'
   *
   * Block description for '<S11>/UD':
   *
   *  Store in Global RAM
   */
  motor_ctrl_with_PID_DW.UD_DSTATE =
    motor_ctrl_with_PID_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S8>/UD'
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  motor_ctrl_with_PID_DW.UD_DSTATE_f =
    motor_ctrl_with_PID_P.DiscreteDerivative_ICPrevScal_m;

  /* Start for MATLABSystem: '<Root>/가변저항' */
  motor_ctrl_with_PID_DW.obj_h.matlabCodegenIsDeleted = false;
  motor_ctrl_with_PID_DW.obj_h.SampleTime = motor_ctrl_with_PID_P._SampleTime;
  motor_ctrl_with_PID_DW.obj_h.isInitialized = 1L;
  motor_ctrl_with_PID_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(62UL);
  motor_ctrl_with_PID_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/PWM' */
  motor_ctrl_with_PID_DW.obj_p.matlabCodegenIsDeleted = false;
  motor_ctrl_with_PID_DW.obj_p.isInitialized = 1L;
  motor_ctrl_with_PID_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL,
    0.0, 0.0);
  motor_ctrl_with_PID_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM' */
  motor_ctrl_with_PID_DW.obj_e.matlabCodegenIsDeleted = false;
  motor_ctrl_with_PID_DW.obj_e.isInitialized = 1L;
  motor_ctrl_with_PID_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(3UL, 0.0,
    0.0);
  motor_ctrl_with_PID_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Encoder' */
  motor_ctrl_with_PID_DW.obj.Index = 0U;
  motor_ctrl_with_PID_DW.obj.matlabCodegenIsDeleted = false;
  motor_ctrl_with_PID_DW.obj.SampleTime =
    motor_ctrl_with_PID_P.Encoder_SampleTime_a;
  motor_ctrl_with_PID_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &motor_ctrl_with_PID_DW.obj.Index);
  motor_ctrl_with_PID_DW.obj.isSetupComplete = true;
  motor_ctrl_with_PID_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S5>/Encoder' */
  MW_EncoderReset(motor_ctrl_with_PID_DW.obj.Index);

  /* Start for MATLABSystem: '<S1>/Encoder' */
  motor_ctrl_with_PID_DW.obj_d.Index = 0U;
  motor_ctrl_with_PID_DW.obj_d.matlabCodegenIsDeleted = false;
  motor_ctrl_with_PID_DW.obj_d.SampleTime =
    motor_ctrl_with_PID_P.Encoder_SampleTime;
  motor_ctrl_with_PID_DW.obj_d.isInitialized = 1L;
  MW_EncoderSetup(20UL, 21UL, &motor_ctrl_with_PID_DW.obj_d.Index);
  motor_ctrl_with_PID_DW.obj_d.isSetupComplete = true;
  motor_ctrl_with_PID_DW.obj_d.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
  MW_EncoderReset(motor_ctrl_with_PID_DW.obj_d.Index);
}

/* Model terminate function */
void motor_ctrl_with_PID_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/가변저항' */
  if (!motor_ctrl_with_PID_DW.obj_h.matlabCodegenIsDeleted) {
    motor_ctrl_with_PID_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((motor_ctrl_with_PID_DW.obj_h.isInitialized == 1L) &&
        motor_ctrl_with_PID_DW.obj_h.isSetupComplete) {
      motor_ctrl_with_PID_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close
        (motor_ctrl_with_PID_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/가변저항' */
  /* Terminate for MATLABSystem: '<S6>/PWM' */
  if (!motor_ctrl_with_PID_DW.obj_p.matlabCodegenIsDeleted) {
    motor_ctrl_with_PID_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((motor_ctrl_with_PID_DW.obj_p.isInitialized == 1L) &&
        motor_ctrl_with_PID_DW.obj_p.isSetupComplete) {
      motor_ctrl_with_PID_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_SetDutyCycle
        (motor_ctrl_with_PID_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      motor_ctrl_with_PID_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_Close(motor_ctrl_with_PID_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM' */
  /* Terminate for MATLABSystem: '<S2>/PWM' */
  if (!motor_ctrl_with_PID_DW.obj_e.matlabCodegenIsDeleted) {
    motor_ctrl_with_PID_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((motor_ctrl_with_PID_DW.obj_e.isInitialized == 1L) &&
        motor_ctrl_with_PID_DW.obj_e.isSetupComplete) {
      motor_ctrl_with_PID_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (3UL);
      MW_PWM_SetDutyCycle
        (motor_ctrl_with_PID_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      motor_ctrl_with_PID_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (3UL);
      MW_PWM_Close(motor_ctrl_with_PID_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM' */
  /* Terminate for MATLABSystem: '<S5>/Encoder' */
  if (!motor_ctrl_with_PID_DW.obj.matlabCodegenIsDeleted) {
    motor_ctrl_with_PID_DW.obj.matlabCodegenIsDeleted = true;
    if ((motor_ctrl_with_PID_DW.obj.isInitialized == 1L) &&
        motor_ctrl_with_PID_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Encoder' */
  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!motor_ctrl_with_PID_DW.obj_d.matlabCodegenIsDeleted) {
    motor_ctrl_with_PID_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((motor_ctrl_with_PID_DW.obj_d.isInitialized == 1L) &&
        motor_ctrl_with_PID_DW.obj_d.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
