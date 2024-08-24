/**
 * \file SquareSolver.h
 * @brief solves the quadratic equation
 */
#ifndef SQUARESOLVER_H_
#define SQUARESOLVER_H_

/**
 * @brief this function solves the quadratic equation
 *
 * @param[in] coeffs contais number of roots
 * @param[in, out] roots contains structure with roots and number of roots
 *
 * @return 0 - if equation have no roots;
 *         1 - if equation have one root;
 *         2 - if equation have two roots;
 */
int SquareSolver (coefficients coeffs, target* roots);

/**
 * @brief this function solves the linear equation
 *
 * @param[in] coeffs contais number of roots
 * @param[in, out] roots contains structure with roots and number of roots
 *
 * @return 1 - if linear equation have a root
 *         0 - if b == 0
 *         SS_INF_ROOTS = -1 - if b == 0 b c == 0
 */
int lin_equation(coefficients coeffs, target* roots);
#endif //SQUARESOLVER_H_
