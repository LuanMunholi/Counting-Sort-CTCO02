#include <stdio.h>
#include <stdlib.h>
#include "countingSort.h"
#include "../Structs/structs.h"

void countingSort(int *v, int n, contador *cont) {
  
  // Encontrando o valor máximo em v
  int max = v[0];
  for (int i = 1; i < n; i++) {
      addComp(cont);
      if (v[i] > max) {
          max = v[i];
      }
  }
  
  // iniciando os vetores
  int *count = malloc((max + 1) * sizeof(int));
  int *output = malloc(n * sizeof(int));
  
  int i;

  //iniciando vetor count
  for (i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Contando as ocorrências de cada elemento
  for (i = 0; i < n; i++) {
    count[v[i]]++;
  }

  // Calculando a posição de cada elemento no vetor ordenado
  for (i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Ordenando os elementos no vetor de saída
  for (i = n - 1; i >= 0; i--) {
    output[count[v[i]] - 1] = v[i];
    addTroca(cont);
    count[v[i]]--;
  }

  // Copiando os elementos ordenados de volta para o vetor original
  for (i = 0; i < n; i++) {
    v[i] = output[i];
  }

  // Liberando a memória alocada
    free(count);
    free(output);
    
}