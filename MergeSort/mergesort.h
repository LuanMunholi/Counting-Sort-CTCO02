#ifndef Merge_Sort
#define Merge_Sort

#include "../Structs/structs.h"

void mergeSort(int *v, int inicio, int fim, contador *cont);
// Função recursiva que executa a fase de divisão do algoritmo mergesort

void merge(int *v, int inicio, int meio, int fim, contador *cont);
// Função que faz a fusão de dois vetores pré-ordenados e os copia para o vetor original

#endif // Merge_Sort