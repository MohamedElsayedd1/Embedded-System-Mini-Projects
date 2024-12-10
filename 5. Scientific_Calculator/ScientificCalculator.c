#include "ScientificCalculator.h"

float my_strtof(const char *str, char **endptr) {
    float result = 0.0f;
    float factor = 1.0f;
    int decimal_point = 0;
    
    // Skip leading whitespaces
    while (isspace(*str)) str++;

    // Check for negative sign
    if (*str == '-') {
        factor = -1.0f;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Convert the whole number part before the decimal point
    while (isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }

    // If there's a decimal point, process the fractional part
    if (*str == '.') {
        str++;
        float place_value = 0.1f;

        while (isdigit(*str)) {
            result += (*str - '0') * place_value;
            place_value *= 0.1f;
            str++;
        }
    }

    // Apply the sign factor (negative if needed)
    result *= factor;

    // Set the endptr if it's not NULL
    if (endptr) {
        *endptr = (char*)str;
    }

    return result;
}


// Function to evaluate the expression
float calculate(char *expression) {
    char *expr = expression;
    return parseExpression(&expr);
}

// Parse the entire expression (handles +, -)
float parseExpression(char **expr) {
    float result = parseTerm(expr);
    while (**expr == '+' || **expr == '-') {
        char op = **expr;
        (*expr)++;
        float value = parseTerm(expr);
        if (op == '+')
            result += value;
        else
            result -= value;
    }
    return result;
}

// Parse a term (handles *, /, %, ^)
float parseTerm(char **expr) {
    float result = parsePower(expr);  // Call to parsePower for handling ^
    while (**expr == '*' || **expr == '/' || **expr == '%') {
        char op = **expr;
        (*expr)++;
        float value = parsePower(expr);  // Call to parsePower to handle precedence correctly
        if (op == '*')
            result *= value;
        else if (op == '/')
            result /= value;
        else if (op == '%')
            result = fmodf(result, value);  // Use fmodf for float modulus
    }
    return result;
}

// Parse power (handles ^ operator)
float parsePower(char **expr) {
    float result = parseFactor(expr);  // Parse the base (factor)
    while (**expr == '^') {
        (*expr)++;  // Skip over the '^'
        float exponent = parseFactor(expr);  // Parse the exponent
        result = powf(result, exponent);  // Apply the power operation
    }
    return result;
}

// Parse a factor (handles functions, parentheses, numbers)
float parseFactor(char **expr) {
    if (**expr == '(') {
        (*expr)++;
        float result = parseExpression(expr);
        if (**expr == ')') (*expr)++;
        return result;
    } else if (isalpha(**expr)) {
        return parseFunction(expr);
    } else {
        return parseNumber(expr);
    }
}

// Parse a number (including handling of negative numbers)
float parseNumber(char **expr) {
    float result = my_strtof(*expr, expr);  // Use strtof to convert to float
    return result;
}


// Parse functions (sin, cos, tan, etc.)
float parseFunction(char **expr) {
    char func[10];
    int i = 0;
    while (isalpha(**expr)) {
        func[i++] = tolower(*(*expr)++);
    }
    func[i] = '\0';

    float value = 0;
    if (**expr == '(') {
        (*expr)++;
        value = parseExpression(expr);  // Parse the expression inside the parentheses
        if (**expr == ')') (*expr)++;   // Move past the closing ')'
    }

    // Convert degrees to radians for trigonometric functions
    const float PI = 3.14159265358979323846f;  // Use 'f' suffix for float constants
    float radians = value * (PI / 180.0f);  // Conversion to radians

    // Evaluate the function
    if (strcmp(func, "sin") == 0) 
        return sinf(radians);  // Use sinf for float
    if (strcmp(func, "cos") == 0) 
        return cosf(radians);  // Use cosf for float
    if (strcmp(func, "tan") == 0) 
        return tanf(radians);  // Use tanf for float
    if (strcmp(func, "arcsin") == 0) 
        return asinf(value);  // Inverse trig is already in radians
    if (strcmp(func, "arccos") == 0) 
        return acosf(value);  // Use acosf for float
    if (strcmp(func, "arctan") == 0) 
        return atanf(value);  // Use atanf for float
    if (strcmp(func, "sqrt") == 0) 
        return sqrtf(value);  // Use sqrtf for float
    if (strcmp(func, "log") == 0) 
        return log10f(value);  // Use log10f for float (base 10)
    if (strcmp(func, "ln") == 0) 
        return logf(value);     // Use logf for natural log
    if (strcmp(func, "exp") == 0) 
        return expf(value);    // Use expf for exponential function

    return 0.0f; // If function is not recognized, return 0
}

void uint32ToString(uint32_t value, char *str) {
    // Handle the case for zero
    if (value == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    // Find the length of the number
    uint32_t temp = value;
    int length = 0;
    while (temp > 0) {
        temp /= 10;
        length++;
    }

    // Add the null terminator at the end
    str[length] = '\0';

    // Convert the number to string in reverse order
    while (value > 0) {
        str[--length] = (value % 10) + '0';  // Get the last digit and convert to character
        value /= 10;  // Remove the last digit
    }
}

void floatToString(float num, char* str) {
    // Check if the number is negative
    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        num = -num;  // Make the number positive for now
    }
    
    // Extract the integer part
    int integerPart = (int)num;
    
    // Extract the decimal part
    float decimalPart = num - integerPart;
    
    // Convert integer part to string
    int i = 0;
    if (isNegative) {
        str[i++] = '-';
    }
    
    // Convert integer part to string manually
    char intStr[20];  // To hold the integer part string
    int j = 0;
    if (integerPart == 0) {
        intStr[j++] = '0';
    } else {
        while (integerPart > 0) {
            intStr[j++] = (integerPart % 10) + '0';
            integerPart /= 10;
        }
    }
    
    // Reverse the integer part string
    for (int k = 0; k < j / 2; k++) {
        char temp = intStr[k];
        intStr[k] = intStr[j - 1 - k];
        intStr[j - 1 - k] = temp;
    }
    
    // Add the integer part to the result string
    for (int k = 0; k < j; k++) {
        str[i++] = intStr[k];
    }
    
    // Add the decimal point if needed
    str[i++] = '.';
    
    // Convert the decimal part to string
    decimalPart *= 100;  // We want 2 decimal places
    int decimalInt = (int)decimalPart;
    str[i++] = (decimalInt / 10) + '0';  // Tens place
    str[i++] = (decimalInt % 10) + '0';  // Ones place
    
    // Null terminate the string
    str[i] = '\0';
}