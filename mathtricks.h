/**
 * \file mathtricks.h
 * @brief mathtricks.h contains mathematical operations that use EPS(epsilon) to compare floating-point numbers,
 *        which helps to get rid of the error
 */
#ifndef MATHTRICKS_H_
#define MATHTRICKS_H_

const double EPS = 1e-9;
/**
 * @brief It contains mathematical operations of comparing them with EPSILON
 *
 * @param[in] n floating number used in comparison with zero
 *
 * @return 0 - if floating number == 0; 1 - if floating number != 0
 */
int Is_Zero(const double n);

/**
 * @brief It contains mathematical operations of comparing floating point numbers with EPSILON
 *
 * @param[in] p floating point number
 * @param[in] q floating point number
 *
 * @return 0 - if numbers isn't equal; 1 - if numbers is equal
 */
int Is_Double_Equal(const double p, const double q);

/**
 * @brief If k is -0, returns 0; else returns k
 *
 * @param[in] k floating point number
 *
 * @return 0 or k meaning
 */
double fix_zero_sign(const double k);

#endif // MATHTRICKS_H_
