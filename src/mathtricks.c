#include <math.h>
#include <assert.h>

#include "mathtricks.h"

const double EPS = 1e-9;

int Is_Zero(const double n)
{
    return (fabs (n) < EPS);
}


double fix_zero_sign(const double k)
{
    return Is_Zero (k) ? 0 : k;
}


int Is_Double_Equal(const double p, const double q)
{
    assert(isfinite(q));
    assert(isfinite(p));

    return (fabs (p - q) < EPS);
}
