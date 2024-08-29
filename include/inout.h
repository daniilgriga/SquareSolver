/**
 * \file inout.h
 * @brief inout.h contains functions that perform input, output, input filtering, and buffer cleanup
 */
#ifndef INOUT_H_
#define INOUT_H_

#include "structs.h"

/**
 * @brief It prints roots
 *
 * @param[in] roots contains x1, x2 and nRoots
 */
void output_roots(roots_data roots);

/**
 * @brief Cleans the buffer
 */
void clean_buffer(void);

/**
 * @brief Accepts only double numbers. when you enter a number with letters, a letter, or a special character, the buffer is cleared
 *
 * @param[out] a readed number
 * @param[in] coeff_name name of the coefficent
 *
 * @return 1 - if input is success; 0 - if input is failed
 */
int input_coeff(double* a, const char* coeff_name);

/**
 * @brief Gives user several attemts to enter number
 *
 * @param[in, out] a coefficent
 * @param[in] coeff_name name of coefficent
 *
 * @return 1 - if input is success; 0 - if input is failed
 */
int Enter_Coeff(double* a, const char* coeff_name);

#endif // INOUT_H_
