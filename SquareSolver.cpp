#include <TXLib.h>
#include <stdio.h>
#include <math.h>
const int SS_INF_ROOTS = -1;
int SquareSolver(double a, double b, double c, double* x1, double* x2);
int main(void)
{
    printf("# Solver of quadratic equations!\n");
    printf("Author: Daniil\n\n");

    double a = 0, b = 0, c = 0;
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
    if(a == 0)
    {
        if(b == 0)
        {
            return ((c == 0)? SS_INF_ROOTS : 0);
        }
        else /* a == 0 è b != 0 */
            {
            *x1 = -c / b;
            return 1;
            }
    }
    else /* a != 0 è b != 0 */
        {
        *x1 = ((-b + sqrt((b * b) - (4 * a * c))) / (2 * a));
        *x2 =((-b - sqrt((b * b) - (4 * a * c))) / (2 * a));
        return 2;
        }
}
