#include <stdio.h>
#include <math.h>
const int SS_INF_ROOTS = -1;
const double EPS = 1e-9;

int Its_Zero(double n);
int SquareSolver(double a, double b, double c, double* x1, double* x2);

int main(void)
{
    printf("# Solver of quadratic equations!\n");
    printf("Author: Daniil\n\n");

    double a = 0;
    double b = 0;
    double c = 0;
    
    printf("Enter a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double x1 = 0, x2 = 0;
    int nRoots = SquareSolver(a, b, c, &x1, &x2);

    switch(nRoots)
        {
        case 0:
            printf("No Roots!");
            break;
        case 1:
            printf("Single root: x = %lf", x1);
            break;
        case 2:
            printf("Two roots: x1 = %lf and x2 = %lf", x1, x2);
            break;
        case SS_INF_ROOTS:
            printf("Infinite roots :)");
            break;
        default: printf("main(): Error: nRoots = %d", nRoots);
        }

    return 0;
}
int SquareSolver(double a, double b, double c, double* x1, double* x2)
{
    if(Its_Zero(a))
    {
        if(Its_Zero(double b))
        {
            return ((Its_Zero(c))? SS_INF_ROOTS : 0);
        }
        else /* a == 0 è b != 0 */
        {
            *x1 = -c / b;
            return 1;
        }
    }
    else /* a != 0 è b != 0 */
    {
        double d = ((b * b) - (4 * a * c));

        if(!Its_Zero(d) && d < 0)
            return 0;
        else
        {
        *x1 = ((-b + sqrt(d);
        *x2 =((-b - sqrt(d);
        return 2;
        }
    }
}
int Its_Zero(double n)
{
    return (fabs(n) < EPS);        
}
