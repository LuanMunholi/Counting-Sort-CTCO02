#include "selectionSort.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Structs/structs.h"

int buscaMenor(int *v, int inicio, int tam, contador *cont) {
  int aux = inicio;
  for (int i = inicio + 1; i < tam; i++) {
    addComp(cont);
    if (v[i] < v[aux])
      aux = i;
  }
  return aux;
}

void selectionSort(int *v, int tam, contador *cont) {
  int marc = 0, menor = 0, aux;
  while (marc < tam - 1) {
    menor = buscaMenor(v, marc + 1, tam, cont);
    if (v[menor] < v[marc]) {
      aux = v[marc];
      v[marc] = v[menor];
      v[menor] = aux;
      addTroca(cont);
    }
    marc++;
  }
}