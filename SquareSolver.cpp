#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#define TEST

const int SS_INF_ROOTS = -1;

const double EPS = 1e-9;

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

void input (equation* coeffs);

void output (quadratic roots);

void RunTests (void);

int Its_Double_Equal (const double p, const double q);

int RunTester (int nTests, const equation coeffs, double x1wanted, double x2wanted, int nRootsWanted);

int SquareSolver (equation coeffs, quadratic* roots);

int lin_equation (const equation coeffs, quadratic* roots);

double fix_zero_sign (const double k);

int Its_Zero (const double n);





int main (void)
{
    struct equation coeffs = {.a = NAN,
                              .b = NAN,
                              .c = NAN};

    struct quadratic roots = {.x1 = 0,
                              .x2 = 0,
                              .nRoots = 0};


    printf ("# Solver of quadratic equations!\n");
    printf ("# Author: Daniil\n\n");

    //double a = NAN;
    //double b = NAN;
    //double c = NAN;

#ifdef TEST
    RunTests ();
#endif


    input (&coeffs);

    //double x1 = 0;
    //double x2 = 0;
    //int nRoots = SquareSolver (coeffs, &x1, &x2);

    output (roots);

    return 0;
}

int SquareSolver (equation coeffs, quadratic* roots)
{
    assert (roots != NULL); assert (( Its_Zero ((*roots).x1)) && "x1 is null");
                            assert (( Its_Zero (roots->x2))&& "x2 is null");

    assert (!isnan (coeffs.a));
    assert (!isnan (coeffs.b));
    assert (!isnan (coeffs.c));

    if (Its_Zero (coeffs.a))
    {
        return lin_equation (coeffs, roots);
    }
    else /* a != 0 */
    {
        double d = ((coeffs.b * coeffs.b) - (4 * coeffs.a * coeffs.c));

        if (Its_Zero (d))
        {
            roots->x1 = -coeffs.b / (2 * coeffs.a);
            return 1;
        }

        else if (d > 0)
        {
            roots->x1 = (-coeffs.b - sqrt (d)) / (2 * coeffs.a);
            roots->x2 = (-coeffs.b + sqrt (d)) / (2 * coeffs.a);
            return 2;
        }
        else
            return 0;
    }
}

int Its_Zero (const double n)
{
    return (fabs (n) < EPS);
}

int lin_equation (equation coeffs, quadratic* roots)
{
    assert (( Its_Zero ((*roots).x1)) && "x is null");

    assert (!isnan (coeffs.b));
    assert (!isnan (coeffs.c));

    if (Its_Zero (coeffs.b))
    {
        return ((Its_Zero (coeffs.c)) ? SS_INF_ROOTS : 0);
    }
    else
    {
        roots->x1 = -coeffs.c / coeffs.b;
        return 1;
    }
}

double fix_zero_sign (const double k)
{
    return Its_Zero (k) ? 0 : k;
}

void input (equation* coeffs)
{
    printf ("# Enter a, b, c: ");
    scanf ("%lf %lf %lf", & (*coeffs).a, &coeffs->b, &coeffs->c);
}

void output (quadratic roots)
{
    switch (roots.nRoots)
    {
        case 0:
            printf ("No Roots!");
            break;

        case 1:
            printf ("Single root: x = %lg", fix_zero_sign (roots.x1));
            break;

        case 2:
            printf ("Two roots: x1 = %lg and x2 = %lg", fix_zero_sign (roots.x1), fix_zero_sign (roots.x2));
            break;

        case SS_INF_ROOTS:
            printf ("Infinite roots :)");
            break;

        default: assert (0 && "Error1");
    }
}

int RunTester (int nTests, equation coeffs, double x1wanted, double x2wanted, int nRootsWanted)
{
    quadratic roots = {.x1 = 0,
                       .x2 = 0,
                       .nRoots = 0};

    roots.nRoots = SquareSolver (coeffs, &roots);

    if ((roots.nRoots) != nRootsWanted)
    {
        printf ("ERROR in %d Test\n", nTests);
        return 1;
    }

    switch (roots.nRoots)
    {
        case 0:
            return 1;

        case 1:
            if (!Its_Double_Equal (roots.x1, x1wanted))
            {
                printf ("ERROR Test %d: a = %lg, b = %lg, c = %lg, x1 = x2 = %lg, nRoots = %d\n"
                        "Expected: x1 = x2 = %lg, nRoots = %d\n",
                        nTests, coeffs.a, coeffs.b, coeffs.c, fix_zero_sign (roots.x1), roots.nRoots,
                        x1wanted, nRootsWanted);
                return 1;
            }

            break;

        case 2:
            if (!Its_Double_Equal (roots.x1, x1wanted) || !Its_Double_Equal (roots.x2, x2wanted))
            {
                printf ("ERROR Test %d: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, nRoots = %d\n"
                       "Expected: x1 = %lg, x2 = %lg, nRoots = %d\n",
                       nTests, coeffs.a, coeffs.b, coeffs.c, fix_zero_sign (roots.x1), fix_zero_sign (roots.x2), roots.nRoots,
                       x1wanted, x2wanted, nRootsWanted);
                return 1;
            }

            break;

        case SS_INF_ROOTS:
            return 1;

        default: assert (0 && "Error");
    }

    return 0;
}


void RunTests (void)
{
    RunTester (1, {.a = 1, .b = 0, .c = -4}, -2, +2, 2);

//                   a   b    c
    RunTester ( 2, { 1, -2,   1},  1 ,      0, 1);
    RunTester ( 3, { 4,  4,   1}, -0.5,     0, 1);
    RunTester ( 4, { 1, -3, -10}, -2,       5, 2);
    RunTester ( 5, { 0,  0,   0},  0,       0, SS_INF_ROOTS);
    RunTester ( 6, {-1,  0,   0},  0,       0, 1);
    RunTester ( 7, { 4,  8,   4}, -1,       0, 1);
    RunTester ( 8, { 2,  4,   6},  0,       0, 0);
    RunTester ( 9, { 1,  2,  -3}, -3,       1, 2);
    RunTester (10, { 9, -6,   1},  1.0/3.0, 0, 1);
}

int Its_Double_Equal (const double p, const double q)
{
    return (fabs (p - q) < EPS);
}
