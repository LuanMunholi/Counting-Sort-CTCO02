#include "mergeSort.h"
#include <stdio.h>
#include <stdlib.h>

// Função que faz a fusão de dois vetores pré-ordenados e os copia para o vetor
// original
void merge(int *v, int inicio, int meio, int fim) {
  // variaveis auxiliares
  int i = 0, j = 0, k = 0;

  // calculando tamanho dos vetores
  int n1 = meio - inicio + 1;
  int n2 = fim - meio;
  int n3 = (fim - inicio) + 1;

  // iniciando os vetores
  int *V1 = malloc(n1 * sizeof(int));
  int *V2 = malloc(n2 * sizeof(int));
  int *V3 = malloc(n3 * sizeof(int));
  if (V1 == NULL || V2 == NULL || V3 == NULL) {
    printf("Não foi possível alocar vetores V1, V2, V3");
    return;
  }

  // preenchendo os vetores
  for (i = 0; i < n1; i++)
    V1[i] = v[inicio + i];

  for (j = 0; j < n2; j++)
    V2[j] = v[meio + 1 + j];

  i = 0;
  j = 0;

  // compara os elementos de V1 e V2 e ordena no vetor auxiliar V3
  while (i < n1 && j < n2) {
    if (V1[i] <= V2[j]) {
      V3[k] = V1[i];
      i++;
    } else {
      V3[k] = V2[j];
      j++;
    }
    k++;
  }

  // em caso de sobra de elementos em V1
  while (i < n1) {
    V3[k] = V1[i];
    i++;
    k++;
  }

  // em caso de sobra de elementos em V2
  while (j < n2) {
    V3[k] = V2[j];
    j++;
    k++;
  }

  // copiando os elementos ordenados de V3 de volta para o vetor original v
  for (int i = 0; i < n3; i++)
    v[inicio + i] = V3[i];
}

// Função recursiva que executa a fase de divisão do algoritmo mergesort
void mergeSort(int *v, int inicio, int fim) {
  if (inicio < fim) {
    int meio = inicio + (fim - inicio) / 2;

    mergeSort(v, inicio, meio);
    mergeSort(v, meio + 1, fim);

    merge(v, inicio, meio, fim);
  }
}