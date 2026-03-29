float dot (int *entrada, float *pesos, int tamanho) {
float soma = 0;

for (int i=0; i < tamanho; i++)

soma += entrada[i] * pesos[i];

}