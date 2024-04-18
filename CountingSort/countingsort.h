#ifndef Counting_Sort
#define Counting_Sort

typedef struct tVet tVet;

int getVetTam(tVet *res);
// Função que retorna o tamanho do vetor

int *getVet(tVet *res);
// Função que retorna o vetor

void imprimeVet(int *v, int tam);
// Função que imprime um vetor
// printf("%d ", vet[i])

tVet *leArquivo(char *nomeArquivo);
// Função que lê os dados de um arquivo e carrega em um vetor de inteiros
// Retorna o tipo tVet, composto por um vetor de inteiros e o tamanho do vetor
// A primeira linha do arquivo possui o tamanho do vetor



#endif // Counting_Sort