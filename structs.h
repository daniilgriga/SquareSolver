/**
 * \file structs.h
 * @brief structs.h contains structures containing the coefficients of the quadratic equation,
 *        the desired roots and a structure containing the coefficients with the roots of the equation
 */
#ifndef STRUCTS_H_
#define STRUCTS_H_

/**
 *
 * @brief const:)
 */
 #define SS_INF_ROOTS -1

/**
 * @struct coefficients
 *
 * @brief This structure contains three coefficients of quadratic equation
 * @var coefficients::a
 * Member 'a' contains first coefficients in quadratic equation
 * @var coefficients::b
 * Member 'b' contains second coefficients in quadratic equation
 * @var coefficients::c
 * Member 'c' contains third coefficients in quadratic equation
 */
struct coefficients_s
{
    double a;
    double b;
    double c;
};

typedef struct coefficients_s coefficients;

/**
 * @struct target
 *
 * @brief This structure contains two roots and number of roots
 * @var target::x1
 * Member 'x1' contains first root in quadratic equation
 * @var target::x2
 * Member 'x2' contains second root in quadratic equation
 * @var target::nRoots
 * Member 'nRoots' contains number of roots
 */
struct target_s
{
    double x1;
    double x2;
    int nRoots;
};

typedef struct target_s target;
/**
 * @struct testdata
 *
 * @brief This structure contains two structers
 * @var testdata::coeffs
 * Member 'coeffs' contains three coefficients of quadratic equation
 * @var testdata::wanted_roots
 * Member 'wanted_roots' contains two wanted roots and wanted number of roots
 */
struct testdata_s
{
    coefficients coeffs;
    target wanted_roots;
};

typedef struct testdata_s testdata;
#endif // STRUCTS_H_
