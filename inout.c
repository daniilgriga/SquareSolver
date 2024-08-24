#include <stdio.h>
#include <assert.h>

#include "mathtricks.h"
#include "inout.h"



void output (target roots)
{
    switch (roots.nRoots)
    {
        case 0:
            printf("No Roots!\n");
            break;

        case 1:
            printf("Single root: x = %lg\n", fix_zero_sign(roots.x1));
            break;

        case 2:
            printf("Two roots: x1 = %lg and x2 = %lg\n", fix_zero_sign(roots.x1), fix_zero_sign(roots.x2));
            break;

        case SS_INF_ROOTS:
            printf("Infinite roots :)\n");
            break;

        default: assert (0 && "Error1");
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
