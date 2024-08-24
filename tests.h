/**
 * \file tests.h
 * @brief tests.h contains functions that are used to perform the unit-test of the quadratic equation
 */
#ifndef TESTS_H_
#define TESTS_H_

#include "structs.h"
/**
 * @brief in case of an error in Unit-test, the function displays the test results
 *
 * @param[in] nTests contais number of roots
 * @param[in] data contains structure with coefficents
 * @param[in] roots contains structure with roots and number of roots
 */
void PrintTestError(int nTests, testdata data, target roots);

/**
 * @brief contains all Unit-tests
 */
void AllTests(void);


/**
 * @brief This function tests the solution of a quadratic equation and checks its roots with wanted roots
 *
 * @param[in] nTests contais number of roots
 * @param[in] data contains two structures: 'coeffs' and 'wanted_roots'
 *
 * @return 1 - if test is failed
 *         0 - if all is ok
 */
int RunTester (int nTests, testdata data);

#endif // TESTS_H_
