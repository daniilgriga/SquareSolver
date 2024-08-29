#include <stdio.h>
#include <math.h>
#include <string.h>

#include "structs.h"
#include "inout.h"
#include "tests.h"
#include "mathtricks.h"
#include "equations.h"

#define TEST

const char* TEST_FLAG = "--test";

int main (const int argc, const char* argv[])
{
    if(argc == 2 && strcmp(argv[1], "--help")==0)
    {
        printf("This program solves the quadratic equation! :D\n");
        return 0;
    }

#ifdef TEST
    if(argc == 2 && strcmp(argv[1], TEST_FLAG)==0)
    {
        AllTests();

        printf("The end of tests!\n");

        return 0;
    }
#endif

    if(argc >= 2 && (strcmp(argv[1], "--help") || strcmp(argv[1], TEST_FLAG)))
    {
        printf("Error. This unknown flags, you can use only \"--help\" and \"%s\"!!!\n", TEST_FLAG);

        return 1;
    }
                                                                                                                                                                                                                   printf ("# MEOW - ded ya vse znayu\n\n");
    coefficients coeffs = {.a = NAN,
                           .b = NAN,
                           .c = NAN};

    roots_data roots = {.x1 = NAN,
                    .x2 = NAN,
                    .nRoots = 0};

    printf("# Solver of quadratic equations!\n");
    printf("# Author: Daniil\n\n");

    if(Enter_Coeff(&coeffs.a, "a") == 1)
        return 1;

    if(Enter_Coeff(&coeffs.b, "b") == 1)
        return 1;

    if(Enter_Coeff(&coeffs.c, "c") == 1)
        return 1;

    roots.nRoots = SquareSolver(coeffs, &roots);

    output_roots(roots);

    return 0;
}
