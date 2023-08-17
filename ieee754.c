#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>  
#include <fenv.h>
#include <math.h>


// +***************************************+
// |     Author: Érico Riess Panazzolo     |
// |     Registration: 212012290-8         |
// |     Date: 08/10/2023 - 08/17/2023     |
// +***************************************+


// Function to print the binary representation of a floating point number in the IEEE754 standard
void convertToBinaryRep(float value) {
    uint32_t *ptr = (uint32_t *)&value;
    uint32_t bits = *ptr;
    for (int i = 31; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
        if (i == 31 || i == 23) printf(" ");
    }
}

// Function to perform the operation, display the results in the IEEE 754 standard,
// and check if any flag was activated to turn it on
void performOperation(float val1, char op, float val2) {
    float result;

    feclearexcept(FE_ALL_EXCEPT); // Clear pending exceptions

    switch (op) {
        case '+':
            result = val1 + val2;
            break;
        case '-':
            result = val1 - val2;
            break;
        case 'x':
            result = val1 * val2;
            break;
        case 'X':
            result = val1 * val2;
            break;
        case '/':
            result = val1 / val2;
            break;
        default:
            printf("Invalid operation!\n\nYou can perform:\n+ (Addition)\n- (Subtraction)\nx or (X) (Multiplication)\n/ (Division)\n");
            return;
    }

    // Print the values ​​and result of the operation
    printf("Result = %.26f %c %.26f = %.26f\n\n", val1, op, val2, result);

    printf("val1 = ");
    convertToBinaryRep(val1);
    printf(" = %.26f", val1);
    printf("\n");

    printf("val2 = ");
    convertToBinaryRep(val2);
    printf(" = %.26f", val2);
    printf("\n");

    printf("res = ");
    convertToBinaryRep(result);
    printf(" = %.26f", result);
    printf("\n");
    printf("\n");

    // Check if any exception occurred and what was it, if so, activate the flag
    if (fetestexcept(FE_INEXACT)) {
        printf("Exception FE_INEXACT: 1\n");
    } else {
        printf("Exception FE_INEXACT: 0\n");
    }

    if (fetestexcept(FE_DIVBYZERO)) {
        printf("Exception FE_DIVBYZERO: 1\n");
    } else {
        printf("Exception FE_DIVBYZERO: 0\n");
    }

    if (fetestexcept(FE_UNDERFLOW)) {
        printf("Exception FE_UNDERFLOW: 1\n");
    } else {
        printf("Exception FE_UNDERFLOW: 0\n");
    }

    if (fetestexcept(FE_OVERFLOW)) {
        printf("Exception FE_OVERFLOW: 1\n");
    } else {
        printf("Exception FE_OVERFLOW: 0\n");
    }

    if (fetestexcept(FE_INVALID)) {
        printf("Exception FE_INVALID: 1\n");
    } else {
        printf("Exception FE_INVALID: 0\n");
    }
}


// Main function that receives arguments from the command line and calls the performOperation function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s val1 op val2\n", argv[0]);
        return 1;
    }

    float val1 = strtof(argv[1], NULL);
    char op = argv[2][0];
    float val2 = strtof(argv[3], NULL);

    performOperation(val1, op, val2);

    return 0;
}
