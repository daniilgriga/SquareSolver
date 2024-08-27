#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "structs.h"
#include "mathtricks.h"
#include "equations.h"


int SquareSolver(coefficients coeffs, target* roots)
{
    assert (roots != NULL);
//  assert(( Is_Zero ((*roots).x1)) && "x1 is null");       assert (( Is_Zero (roots->x2)) && "x2 is null");

    assert ((!isnan (coeffs.a)) && "a is NAN");  // __LINE__!!!
    assert ((!isnan (coeffs.b)) && "b is NAN");
    assert ((!isnan (coeffs.c)) && "c is NAN");

    if (Is_Zero(coeffs.a))
    {
        return lin_equation(coeffs, roots);
    }
    else /* a != 0 */
    {
        double d = ((coeffs.b * coeffs.b) - (4 * coeffs.a * coeffs.c));

        if (Is_Zero(d))
        {
            roots->x1 = -(coeffs.b) / (2 * (coeffs.a));
            return ONE_ROOT;
        }

        else if (d >= EPS)
        {
            roots->x1 = ((-coeffs.b) - sqrt (d)) / (2 * (coeffs.a));
            roots->x2 = ((-coeffs.b) + sqrt (d)) / (2 * (coeffs.a));
            return TWO_ROOTS;
        }
        else // d <= EPS
            return NO_ROOTS;
    }
}


int lin_equation(coefficients coeffs, target* roots)
{
    assert (roots != NULL);
//  assert (( Is_Zero (roots->x1)) && "x is null");

    assert (!isnan (coeffs.b));
    assert (!isnan (coeffs.c));

    if (Is_Zero(coeffs.b))
    {
        return ((Is_Zero(coeffs.c)) ? INF_ROOTS : NO_ROOTS);
    }
    else
    {
        roots->x1 = -coeffs.c / coeffs.b;
        return ONE_ROOT;
    }
}
