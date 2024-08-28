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
void output(target roots);

/**
 * @brief Cleans the buffer
 */
void Clean_Buffer(void);

/**
 * @brief Accepts only double numbers. when you enter a number with letters, a letter, or a special character, the buffer is cleared
 *
 * @param[out] a readed number
 * @param[in] str name of the coefficent
 *
 * @return 1 - if input is success; 0 - if input is failed
 */
int input_update(double* a, const char* str);

/**
 * @brief Gives user several attemts to enter number
 *
 * @param[in, out] a coefficent
 * @param[in] str name of coefficent
 *
 * @return 1 - if input is success; 0 - if input is failed
 */
int Enter_Coeff(double* a, const char* str);

#endif // INOUT_H_
