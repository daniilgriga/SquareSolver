#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#define TEST

const int SS_INF_ROOTS = -1;

const double EPS = 1e-9;

struct equation
{
    double a;
    double b;
    double c;
};

struct quadratic
{
    double x1;
    double x2;
    int nRoots;
};

struct testdata
{
    equation coeffs;
    quadratic wanted_roots;
};




void output (quadratic roots);

void RunTests (void);

void PrintTestError(int nTests, testdata data, quadratic roots);

void Clean_Buffer(void);


int input_update(double* a, const char* str);

int input (equation* coeffs);

int Its_Double_Equal (const double p, const double q);

int RunTester (int nTests, testdata data);

int SquareSolver (equation coeffs, quadratic* roots);

int lin_equation (const equation coeffs, quadratic* roots);

int Its_Zero (const double n);

int Enter_Coeffs(double* a, const char* str);


double fix_zero_sign (const double k);





int main (void)
{
    struct equation coeffs = {.a = NAN,
                              .b = NAN,
                              .c = NAN};

    struct quadratic roots = {.x1 = NAN,
                              .x2 = NAN,
                              .nRoots = 0};

    printf ("# Solver of quadratic equations!\n");
    printf ("# Author: Daniil\n\n");

#ifdef TEST
    RunTests ();
#endif

    /*if(input_update(&coeffs.a, "a") == 1)

        return 0;
    if(input_update(&coeffs.b, "b") == 1)
        return 0;

    if(input_update(&coeffs.c, "c") == 1)
        return 0;*/

    if(Enter_Coeffs(&coeffs.a, "a") == 1)
        return 1;

    if(Enter_Coeffs(&coeffs.b, "b") == 1)
        return 1;

    if(Enter_Coeffs(&coeffs.c, "c") == 1)
        return 1;

    roots.nRoots = SquareSolver (coeffs, &roots);

    output (roots);

    return 0;
}




int input (equation* coeffs)
{
    printf ("# Enter a, b, c: ");
    return (scanf ("%lf %lf %lf", &(*coeffs).a, &coeffs->b, &coeffs->c));
}


int SquareSolver (equation coeffs, quadratic* roots)
{
    assert (roots != NULL);
//  assert(( Its_Zero ((*roots).x1)) && "x1 is null");       assert (( Its_Zero (roots->x2)) && "x2 is null");

    assert ((!isnan (coeffs.a)) && "a is NAN");  // __LINE__            !!!
    assert ((!isnan (coeffs.b)) && "b is NAN");
    assert ((!isnan (coeffs.c)) && "c is NAN");

    if (Its_Zero (coeffs.a))
    {
        return lin_equation (coeffs, roots);
    }
    else /* a != 0 */
    {
        double d = ((coeffs.b * coeffs.b) - (4 * coeffs.a * coeffs.c));

        if (Its_Zero (d))
        {
            roots->x1 = -(coeffs.b) / (2 * (coeffs.a));
            return 1;
        }

        else if (d > 0)
        {
            roots->x1 = ((-coeffs.b) - sqrt (d)) / (2 * (coeffs.a));
            roots->x2 = ((-coeffs.b) + sqrt (d)) / (2 * (coeffs.a));
            return 2;
        }
        else
            return 0;
    }
}


void output (quadratic roots)
{

    // assert(!isnan(roots.x1));

    switch (roots.nRoots)
    {
        case 0:
            printf ("No Roots!");
            break;

        case 1:
            printf ("Single root: x = %lg", fix_zero_sign (roots.x1));
            break;

        case 2:
            printf ("Two roots: x1 = %lg and x2 = %lg", fix_zero_sign (roots.x1), fix_zero_sign (roots.x2));
            break;

        case SS_INF_ROOTS:
            printf ("Infinite roots :)");
            break;

        default: assert (0 && "Error1");
    }
}


int Its_Zero (const double n)
{
    return (fabs (n) < EPS);
}


int lin_equation (equation coeffs, quadratic* roots)
{
    assert (( Its_Zero (roots->x1)) && "x is null");

    assert (!isnan (coeffs.b));
    assert (!isnan (coeffs.c));

    if (Its_Zero (coeffs.b))
    {
        return ((Its_Zero (coeffs.c)) ? SS_INF_ROOTS : 0);
    }
    else
    {
        roots->x1 = -coeffs.c / coeffs.b;
        return 1;
    }
}


double fix_zero_sign (const double k)
{
    return Its_Zero (k) ? 0 : k;
}


int RunTester (int nTests, testdata data)
{
    quadratic roots = {.x1 = 0,
                       .x2 = 0,
                       .nRoots = 0};


    roots.nRoots = SquareSolver (data.coeffs, &roots);

    if ((roots.nRoots) != data.wanted_roots.nRoots)
    {
        printf ("ERROR in %d Test\n", nTests);
        return 1;
    }

    switch (roots.nRoots)
    {
        case 0:
            return 1;

        case 1:
            if (!Its_Double_Equal (roots.x1, data.wanted_roots.x1))
            {
                PrintTestError(nTests, data, roots);
                return 1;
            }

            break;

        case 2:
            if (!Its_Double_Equal (roots.x1, data.wanted_roots.x1) || !Its_Double_Equal (roots.x2, data.wanted_roots.x2))
            {
                PrintTestError(nTests, data, roots);
                return 1;
            }

            break;

        case SS_INF_ROOTS:
            return 1;

        default: assert (0 && "Error");
    }

    return 0;
}


void RunTests (void)
{
    RunTester (1,  {.coeffs = {.a = 1, .b = 0, .c = -4}, .wanted_roots = { .x1 = -2, .x2 = +2, .nRoots = 2}});

//                      a      b      c        x1   x2    nRoots
    RunTester (  2, {   1,    -2,     1,        1,   0,      1       });
    RunTester (  3, {   4,     4,     1,     -0.5,   0,      1       });
    RunTester (  4, {   1,    -3,   -10,       -2,   5,      2       });
    RunTester (  5, {   0,     0,     0,        0,   0, SS_INF_ROOTS });
    RunTester (  6, {  -1,     0,     0,        0,   0,      1       });
    RunTester (  7, {   4,     8,     4,       -1,   0,      1       });
    RunTester (  8, {   2,     4,     6,        0,   0,      0       });
    RunTester (  9, {   1,     2,    -3,       -3,   1,      2       });
    RunTester ( 10, {   9,    -6,     1,  1.0/3.0,   0,      1       });
    RunTester ( 11, {   1,     5,   -85,        0,   0,      2       });
}


int Its_Double_Equal (const double p, const double q)
{
    return (fabs (p - q) < EPS);
}



void PrintTestError (int nTests, testdata data, quadratic roots)
{
    printf ("ERROR Test %d: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, nRoots = %d\n"
            "Expected: x1 = %lg, x2 = %lg, nRoots = %d\n",
            nTests, data.coeffs.a, data.coeffs.b, data.coeffs.c, fix_zero_sign (roots.x1), fix_zero_sign (roots.x2), roots.nRoots,
            data.wanted_roots.x1, data.wanted_roots.x2, data.wanted_roots.nRoots);
}



void Clean_Buffer(void)
{
    while((getchar()) != '\n')
        ;
}



int input_update(double* a, const char* str)
{
    printf("# Enter %s: ", str);

    if(scanf("%lf", a) == 1)
    {
        if(getchar() == '\n')
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
        printf("You didn't enter a number, try again.\n");
    }

    printf("Goodbye!");
    return 1;
}
