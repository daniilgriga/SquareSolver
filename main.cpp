#include <stdio.h>
#include <math.h>

#include "structs.h"
#include "inout.h"
#include "tests.h"
#include "mathtricks.h"
#include "equations.h"

#define TEST

int main (void)
{                                                                                                                                                                                                                                                   printf ("MEOW\n\n"); // Ded, ya zametil
    struct coefficents coeffs = {.a = NAN,
                                 .b = NAN,
                                 .c = NAN};

    struct target roots = {.x1 = NAN,
                           .x2 = NAN,
                           .nRoots = 0};

    printf ("# Solver of quadratic equations!\n");
    printf ("# Author: Daniil\n\n");

#ifdef TEST
    AllTests();
#endif


    if(Enter_Coeffs(&coeffs.a, "a") == 1)
        return 1;

    if(Enter_Coeffs(&coeffs.b, "b") == 1)
        return 1;

    if(Enter_Coeffs(&coeffs.c, "c") == 1)
        return 1;

    roots.nRoots = SquareSolver(coeffs, &roots);

    output(roots);

    return 0;
}
