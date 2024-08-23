#ifndef TESTS_H_
#define TESTS_H_

#include "structs.h"

void PrintTestError(int nTests, testdata data, quadratic roots);

void AllTests(void);


int SquareSolver (equation coeffs, quadratic* roots);

int lin_equation (equation coeffs, quadratic* roots);

int RunTester (int nTests, testdata data);

#endif // TESTS_H_
