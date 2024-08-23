#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "tests.h"
#include "mathtricks.h"



int RunTester (int nTests, testdata data)
{
    quadratic roots = {.x1 = 0,
                       .x2 = 0,
                       .nRoots = 0};


    roots.nRoots = SquareSolver (data.coeffs, &roots);

    if ((roots.nRoots) != data.wanted_roots.nRoots)
    {
        printf ("ERROR in %d Test\n", nTests);
        return 1;
    }

    switch (roots.nRoots)
    {
        case 0:
            return 1;

        case 1:
            if (!Its_Double_Equal (roots.x1, data.wanted_roots.x1))
            {
                PrintTestError(nTests, data, roots);
                return 1;
            }

            break;

        case 2:
            if (!Its_Double_Equal (roots.x1, data.wanted_roots.x1) || !Its_Double_Equal (roots.x2, data.wanted_roots.x2))
            {
                PrintTestError(nTests, data, roots);
                return 1;
            }

            break;

        case SS_INF_ROOTS:
            return 1;

        default: assert (0 && "Error");
    }

    return 0;
}



void PrintTestError (int nTests, testdata data, quadratic roots)
{
    printf ("ERROR Test %d: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, nRoots = %d\n"
            "Expected: x1 = %lg, x2 = %lg, nRoots = %d\n",
            nTests, data.coeffs.a, data.coeffs.b, data.coeffs.c, fix_zero_sign (roots.x1), fix_zero_sign (roots.x2), roots.nRoots,
            data.wanted_roots.x1, data.wanted_roots.x2, data.wanted_roots.nRoots);
}





void AllTests(void)
{
    const int nTests = 11;

//                               a      b      c        x1   x2     nRoots
    testdata data[nTests] = {{   1,     0,    -4,       -2,  +2,      2       },
                             {   1,    -2,     1,        1,   0,      1       },
                             {   4,     4,     1,     -0.5,   0,      1       },
                             {   1,    -3,   -10,       -2,   5,      2       },
                             {   0,     0,     0,        0,   0, SS_INF_ROOTS },
                             {  -1,     0,     0,        0,   0,      1       },
                             {   4,     8,     4,       -1,   0,      1       },
                             {   2,     4,     6,        0,   0,      0       },
                             {   1,     2,    -3,       -3,   1,      2       },
                             {   9,    -6,     1,  1.0/3.0,   0,      1       },
                             {   1,     5,   -85,        0,   0,      2       }};

    for(int i = 0; i < nTests; i++)
        RunTester(i, data[i]);
}


int SquareSolver (equation coeffs, quadratic* roots)
{
    assert (roots != NULL);
//  assert(( Its_Zero ((*roots).x1)) && "x1 is null");       assert (( Its_Zero (roots->x2)) && "x2 is null");

    assert ((!isnan (coeffs.a)) && "a is NAN");  // __LINE__            !!!
    assert ((!isnan (coeffs.b)) && "b is NAN");
    assert ((!isnan (coeffs.c)) && "c is NAN");

    if (Its_Zero (coeffs.a))
    {
        return lin_equation (coeffs, roots);
    }
    else /* a != 0 */
    {
        double d = ((coeffs.b * coeffs.b) - (4 * coeffs.a * coeffs.c));

        if (Its_Zero (d))
        {
            roots->x1 = -(coeffs.b) / (2 * (coeffs.a));
            return 1;
        }

        else if (d > 0)
        {
            roots->x1 = ((-coeffs.b) - sqrt (d)) / (2 * (coeffs.a));
            roots->x2 = ((-coeffs.b) + sqrt (d)) / (2 * (coeffs.a));
            return 2;
        }
        else // d < 0
            return 0;
    }
}



int lin_equation (equation coeffs, quadratic* roots)
{
    assert (roots != NULL);
//  assert (( Its_Zero (roots->x1)) && "x is null");

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
