#include <stdio.h>
#include <assert.h>

#include "mathtricks.h"
#include "inout.h"
#include "equations.h"


void output (target roots)
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


int input_update(double* a, const char* str)
{
    printf("# Enter %s: ", str);

    int n = 0;
    if(scanf("%lf", a) == 1)
    {
        if (((n = getchar()) == '\n') || ((n == EOF)))
            return 0;
        Clean_Buffer();
        return 1;
    }
    else
    {
        Clean_Buffer();
        return 1;
    }
}


int Enter_Coeffs(double* a, const char* str)
{
    for(int i = 0; i < 5; i++)
    {
        if(input_update(a, str) == 0)
            return 0;
        printf("You didn't enter a number!\n");
    }

    printf("Goodbye!\n");
    return 1;
}


void Clean_Buffer(void)
{
    while((getchar()) != '\n')
        ;
}
