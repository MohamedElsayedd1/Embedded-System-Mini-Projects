#ifndef _CALC_H_
#define _CALC_H_

#include <avr/io.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <avr/interrupt.h>


float custom_sin(float radians);
float custom_cos(float radians);
float custom_tan(float radians);
float custom_arcsin(float value);
float custom_arccos(float value);
float custom_arctan(float value);
float custom_sqrt(float value);
float custom_log(float value);
float custom_ln(float value);
float custom_exp(float value);

float parseExpression(char **expr);
float parseTerm(char **expr);
float parseFactor(char **expr);
float parseNumber(char **expr);
float parseFunction(char **expr);
float parsePower(char **expr);
float calculate(char *expression);

// Convert uint32_t to string
void uint32ToString(uint32_t value, char *str);
void floatToString(float num, char *str);

#endif