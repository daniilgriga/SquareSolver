#include <stdio.h>
#include <math.h>
#include <assert.h>
// #include <stdlib.h>

#include "tests.h"
#include "mathtricks.h"
#include "equations.h"

/**
 * @brief in case of an error in Unit-test, the function displays the test results
 *
 * @param[in] nTests contais number of roots
 * @param[in] data contains structure with coefficents
 * @param[in] roots contains structure with roots and number of roots
 */
static void PrintTestError(size_t nTests, testdata data, target roots)
{
    printf("# \033[1;31m" "ERROR " "\033[0m" "Test %zu: a = %g, b = %g, c = %g, x1 = %g, x2 = %g, nRoots = %d\n"
           "# Expected: x1 = %g, x2 = %g, nRoots = %d\n\n",
           nTests, data.coeffs.a, data.coeffs.b, data.coeffs.c, fix_zero_sign (roots.x1), fix_zero_sign (roots.x2), roots.nRoots,
           data.wanted_roots.x1, data.wanted_roots.x2, data.wanted_roots.nRoots);
}

int RunTester(size_t nTests, testdata data)
{
    target roots = {.x1 = 0,
                    .x2 = 0,
                    .nRoots = 0};


    roots.nRoots = SquareSolver(data.coeffs, &roots);

    if ((roots.nRoots) != data.wanted_roots.nRoots)
    {
        printf("ERROR in %zu Test\n", nTests);
        return 1; // EXIT_FAILURE
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

        default: assert (0 && "unexpected number of roots");
    }

    return 0; // EXIT_SUCCESS
}

void AllTests(void)
{

//                           a      b      c           x1   x2     nRoots
    testdata data[] = { { {  1,     0,    -4},  {      -2,  +2,      2      } },
                        { {  1,    -2,     1},  {       1,   0,      1      } },
                        { {  4,     4,     1},  {    -0.5,   0,      1      } },
                        { {  1,    -3,   -10},  {      -2,   5,      2      } },
                        { {  0,     0,     0},  {       0,   0,  INF_ROOTS  } },
                        { { -1,     0,     0},  {       0,   0,      1      } },
                        { {  4,     8,     4},  {      -1,   0,      1      } },
                        { {  2,     4,     6},  {       0,   0,      0      } },
                        { {  1,     2,    -3},  {      -3,   1,      2      } },
                        { {  9,    -6,     1},  { 1.0/3.0,   0,      1      } },
                        { {  1,     5,   -85},  {       0,   0,      2      } } };

    for (size_t i = 0; i < sizeof data / sizeof(testdata); i++)
        RunTester(i, data[i]);

    #if 0
    printf("\033[1;32m" "FAILED" "\033[0m");
    #endif
}
