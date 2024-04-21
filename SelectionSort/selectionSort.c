#include "selectionSort.h"
#include <stdio.h>
#include <stdlib.h>

int buscaMenor(int *v, int inicio, int tam) {
  int aux = inicio;
  for (int i = inicio + 1; i < tam; i++) {
    if (v[i] < v[aux])
      aux = i;
  }
  return aux;
}

void selectionSort(int *v, int tam) {
  int marc = 0, menor = 0, aux;
  while (marc < tam - 1) {
    menor = buscaMenor(v, marc + 1, tam);
    if (v[menor] < v[marc]) {
      aux = v[marc];
      v[marc] = v[menor];
      v[menor] = aux;
    }
    marc++;
  }
}
