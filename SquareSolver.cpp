#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const int SS_INF_ROOTS = -1;

const double EPS = 1e-9;

void input(double* a, double* b, double* c);

void output(int nRoots, double x1, double x2);

int SquareSolver(const double a, const double b, const double c, double* x1, double* x2);

int lin_equation(const double b, const double c, double* x);

double fix_zero_sign(const double k);

int Its_Zero(const double n);


int main(void)
{
    // struct ...
    // (*coeffs).a or coeffs -> a

    printf("# Solver of quadratic equations!\n");
    printf("# Author: Daniil\n\n");

    double a = NAN;
    double b = NAN;
    double c = NAN;

    input(&a, &b, &c);

    double x1 = 0, x2 = 0;
    int nRoots = SquareSolver(a, b, c, &x1, &x2);

    output(nRoots, x1, x2);

    return 0;
}

int SquareSolver(const double a,const double b,const double c, double* x1, double* x2)
{
    assert(x1 && "x1 is null");
    assert(x2 && "x2 is null");

    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

    if(Its_Zero(a))
    {
        return lin_equation(b, c, x1);
    }
    else /* a != 0 */
    {
        double d = ((b * b) - (4 * a * c));

        if(!Its_Zero(d) && d < 0)
            return 0;
        else
        {
            *x1 = (-b + sqrt(d)) / (2 * a);
            *x2 = (-b - sqrt(d)) / (2 * a);
            return 2;
        }
    }
}

int Its_Zero(const double n)
{
    return (fabs(n) < EPS);
}

int lin_equation(const double b,const double c, double* x)
{
    assert(x && "x is null");

    assert(!isnan(b));
    assert(!isnan(c));

    if(Its_Zero(b))
    {
        return ((Its_Zero(c)) ? SS_INF_ROOTS : 0);
    }
    else
    {
        *x = -c / b;
        return 1;
    }
}

double fix_zero_sign(const double k)
{
    return Its_Zero(k) ? 0 : k;
}

void input(double* a, double* b, double* c)
{
    printf("# Enter a, b, c: ");
    scanf("%lf %lf %lf", a, b, c);
}

void output(int nRoots, double x1, double x2)
{
    switch(nRoots)
    {
        case 0:
            printf("No Roots!");
            break;
        case 1:
            printf("Single root: x = %lg", fix_zero_sign(x1));
            break;
        case 2:
            if(fabs(x1 - x2) < EPS)
            {
                printf("x1 = x2 = %lg", fix_zero_sign(x1));
                break;
            }
            else
                printf("Two roots: x1 = %lg and x2 = %lg", fix_zero_sign(x1), fix_zero_sign(x2));
                break;
        case SS_INF_ROOTS:
            printf("Infinite roots :)");
            break;
        default: assert(0 && "Error");
    }
}
