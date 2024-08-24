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
const int SS_INF_ROOTS = -1;

/**
 * @struct coefficents
 *
 * @brief This structure contains three coefficents of quadratic equation
 * @var coefficents::a
 * Member 'a' contains first coefficents in quadratic equation
 * @var coefficents::b
 * Member 'b' contains second coefficents in quadratic equation
 * @var coefficents::c
 * Member 'c' contains third coefficents in quadratic equation
 */
struct coefficents
{
    double a;
    double b;
    double c;
};

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
struct target
{
    double x1;
    double x2;
    int nRoots;
};

/**
 * @struct testdata
 *
 * @brief This structure contains two structers
 * @var testdata::coeffs
 * Member 'coeffs' contains three coefficents of quadratic equation
 * @var testdata::wanted_roots
 * Member 'wanted_roots' contains two wanted roots and wanted number of roots
 */
struct testdata
{
    coefficents coeffs;
    target wanted_roots;
};

#endif // STRUCTS_H_
