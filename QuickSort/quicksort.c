#include "quickSort.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Structs/structs.h"

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int *v, int low, int high, contador *cont) {
  int pivot = v[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    addComp(cont);
    if (v[j] < pivot) {
      i++;
      addTroca(cont);
      swap(&v[i], &v[j]);
    }
  }
  addTroca(cont);
  swap(&v[i + 1], &v[high]);
  return i + 1;
}

void quickSort(int *v, int low, int high, contador *cont) {
  if (low < high) {
    int pi = partition(v, low, high, cont);
    quickSort(v, low, pi - 1, cont);
    quickSort(v, pi + 1, high, cont);
  }
}