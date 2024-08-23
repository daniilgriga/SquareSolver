#ifndef STRUCTS_H_
#define STRUCTS_H_

const int SS_INF_ROOTS = -1;

struct equation
{
    double a;
    double b;
    double c;
};

struct quadratic
{
    double x1;
    double x2;
    int nRoots;
};

struct testdata
{
    equation coeffs;
    quadratic wanted_roots;
};

#endif // STRUCTS_H_
