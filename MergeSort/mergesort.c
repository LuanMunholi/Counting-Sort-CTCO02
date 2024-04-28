#include "mergeSort.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Structs/structs.h"

// Função que faz a fusão de dois vetores pré-ordenados e os copia para o vetor
// original
void merge(int *v, int inicio, int meio, int fim, contador *cont) {
  // variaveis auxiliares
  int i = 0, j = 0, k = inicio;

  // calculando tamanho dos vetores
  int n1 = meio - inicio + 1;
  int n2 = fim - meio;

  // iniciando os vetores
  int *V1 = malloc(n1 * sizeof(int));
  int *V2 = malloc(n2 * sizeof(int));
  if (V1 == NULL || V2 == NULL ) {
    printf("Não foi possível alocar vetores V1, V2");
    return;
  }

  // preenchendo os vetores
  for (i = 0; i < n1; i++)
    V1[i] = v[inicio + i];

  for (j = 0; j < n2; j++)
    V2[j] = v[meio + 1 + j];

  i = 0;
  j = 0;

  // compara os elementos de V1 e V2 e ordena
  while (i < n1 && j < n2) {
    addComp(cont);
    if (V1[i] <= V2[j]) {
      v[k] = V1[i];
      i++;
    } else {
      v[k] = V2[j];
      j++;
      addTroca(cont);
    }
    k++;
  }

  // em caso de sobra de elementos em V1
  while (i < n1) {
    v[k] = V1[i];
    i++;
    k++;
  }

  // em caso de sobra de elementos em V2
  while (j < n2) {
    v[k] = V2[j];
    j++;
    k++;
  }

  // Liberando a memória alocada para V1 e V2
  free(V1);
  free(V2);

}

// Função recursiva que executa a fase de divisão do algoritmo mergesort
void mergeSort(int *v, int inicio, int fim, contador *cont) {
  if (inicio < fim) {
    int meio = inicio + (fim - inicio) / 2;

    mergeSort(v, inicio, meio, cont);
    mergeSort(v, meio + 1, fim, cont);

    merge(v, inicio, meio, fim, cont);
  }
}