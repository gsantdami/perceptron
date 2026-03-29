#include <stdio.h>
#include <stdlib.h>
#include "dot.h"


#define taxaDeAprendizado 0.1

const int entradas[4][2] = {
    {0,0},
    {1,0},
    {0,1},
    {1,1}
};

const int saidas[4] = {0,0,0,1};

 float pesos[3] = {0.0, 0.0, 0.0};

float calcOutput(const int *reg);


int step(float soma) {
    if (soma >= 1) return 1;
    return 0;
}

int main() {
    int erroTotal = 1;

    while (erroTotal != 0) {
        erroTotal = 0;

        for (int i = 0; i < sizeof(saidas)/sizeof(saidas[0]); i++) {

            int saidaCalc = calcOutput(entradas[i]);
            int erro = saidas[i] - saidaCalc;

            erroTotal += abs(erro);

            for (int j = 0; j < 2; j++) {
                pesos[j] += taxaDeAprendizado * entradas[i][j] * erro;
                printf("Peso att: %.2f\n", pesos[j]);
            }

            pesos[2] += taxaDeAprendizado * erro;
            printf("Bias att: %.2f\n", pesos[2]);
        }

        printf("Total de erros: %d\n", erroTotal);
    }
}

float calcOutput(const int *reg) {

    float s =0;

    for (int i = 0; i < 2; i++) {
        s += reg[i] * pesos[i];
    }

    s += pesos[2]; 

    return step(s);
}
