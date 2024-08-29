#include <stdio.h>
#include <assert.h>

#include "mathtricks.h"
#include "inout.h"
#include "equations.h"


void output_roots(roots_data roots)
{
    switch (roots.nRoots)
    {
        case NO_ROOTS:
            printf("No Roots!\n");
            break;

        case ONE_ROOT:
            printf("Single root: x = %lg\n", fix_zero_sign(roots.x1));
            break;

        case TWO_ROOTS:
            printf("Two roots: x1 = %lg and x2 = %lg\n", fix_zero_sign(roots.x1), fix_zero_sign(roots.x2));
            break;

        case INF_ROOTS:
            printf("Infinite roots :)\n");
            break;

        default: assert (0 && "Error in output()");
    }
}


int input_coeff(double* coeff, const char* coeff_name)
{
    printf("# Enter %s: ", coeff_name);

    if(scanf("%lf", coeff) == 1)
    {
        int n = getchar();
        if(n == '\n' || n == EOF)
            return 0;
    }

    clean_buffer();
    return 1;
}


int Enter_Coeff(double* a, const char* coeff_name)
{
    for(int i = 5; i > 0; i--)
    {
        if(input_coeff(a, coeff_name) == 0)
            return 0;

        printf("You didn't enter a number!\n");
        printf("You have %d lifes left\n", i - 1);
    }

    printf("Goodbye!\n");
    return 1;
}


void clean_buffer(void)
{
    while((getchar()) != '\n') {;}
}
