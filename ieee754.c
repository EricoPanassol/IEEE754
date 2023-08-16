#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>  
#include <fenv.h>
#include <math.h>


// Função para imprimir a representação binária de um número em ponto flutuante
void convertToBinaryRep(float value) {
    uint32_t *ptr = (uint32_t *)&value;
    uint32_t bits = *ptr;
    for (int i = 31; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
        if (i == 31 || i == 23) printf(" ");
    }
}


// Função para realizar a operação e mostrar os resultados no padrão IEEE 754 
// e checar se alguma flag foi ativada, caso ocorra, mostrar qual foi
void performOperation(float val1, char op, float val2) {
    float result;

    feclearexcept(FE_ALL_EXCEPT); // Limpa as exceções pendentes

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
            printf("Invalid operation\nValids: +, -, x or (X), /\n");
            return;
    }

    // Imrpime os valores e o resultado da operação
   
    // if(result == INFINITY){
    //     printf("Result %.6f %c %.6f = INF\n\n", val1, op, val2);
    // } else {
    //     printf("Result %.6f %c %.6f = %.6f\n\n", val1, op, val2, result);
    // }

    
    printf("Result = %.6f %c %.6f = %.6f\n\n", val1, op, val2, result);


    printf("val1 = ");
    convertToBinaryRep(val1);
    printf(" = %.20f", val1);
    printf("\n");

    printf("val2 = ");
    convertToBinaryRep(val2);
    printf(" = %.20f", val2);
    printf("\n");

    printf("res = ");
    convertToBinaryRep(result);
    printf(" = %.20f", result);
    printf("\n");
    printf("\n");

    // Verifica se ocorreu alguma exceção E qual foi, se sim, ativa a flag
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


// Função principal que recebe os argumentos pela linha de comando e chama a função performOperation
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
