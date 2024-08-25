#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "tests.h"
#include "mathtricks.h"
#include "equations.h"

#define NTESTS 11

int RunTester(int nTests, testdata data)
{
    target roots = {.x1 = 0,
                    .x2 = 0,
                    .nRoots = 0};


    roots.nRoots = SquareSolver(data.coeffs, &roots);

    if ((roots.nRoots) != data.wanted_roots.nRoots)
    {
        printf("ERROR in %d Test\n", nTests);
        return EXIT_FAILURE;
    }

    switch (roots.nRoots)
    {
        case NO_ROOTS:
            return 1;

        case ONE_ROOT:
            if (!Is_Double_Equal(roots.x1, data.wanted_roots.x1))
            {
                PrintTestError(nTests, data, roots);
                return 1;
            }

            break;

        case TWO_ROOTS:
            if (!Is_Double_Equal(roots.x1, data.wanted_roots.x1) || !Is_Double_Equal(roots.x2, data.wanted_roots.x2))
            {
                PrintTestError(nTests, data, roots);
                return 1;
            }

            break;

        case INF_ROOTS:
            return 1;

        default: assert (0 && "Error");
    }

    return EXIT_SUCCESS;
}


void PrintTestError(int nTests, testdata data, target roots)
{
    printf("ERROR Test %d: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, nRoots = %d\n"
           "Expected: x1 = %lg, x2 = %lg, nRoots = %d\n",
           nTests, data.coeffs.a, data.coeffs.b, data.coeffs.c, fix_zero_sign (roots.x1), fix_zero_sign (roots.x2), roots.nRoots,
           data.wanted_roots.x1, data.wanted_roots.x2, data.wanted_roots.nRoots);
}


void AllTests(void)
{

//                               a      b      c        x1   x2     nRoots
    testdata data[NTESTS] = {{ {   1,     0,    -4},  {     -2,  +2,      2     }  },
                             { {  1,    -2,     1},   {     1,   0,      1      } },
                             { {  4,     4,     1},   {  -0.5,   0,      1      } },
                             { {  1,    -3,   -10},   {    -2,   5,      2      } },
                             { {  0,     0,     0},   {     0,   0, INF_ROOTS} },
                             { { -1,     0,     0},   {     0,   0,      1      } },
                             { {  4,     8,     4},   {    -1,   0,      1      } },
                             { {  2,     4,     6},   {     0,   0,      0      } },
                             { {  1,     2,    -3},   {    -3,   1,      2      } },
                             { {  9,    -6,     1},   {  1.0/3.0,   0,      1   }    },
                             { {  1,     5,   -85},   {     0,   0,      2      } }};

    for(int i = 0; i < NTESTS; i++)
        RunTester(i, data[i]);
}
