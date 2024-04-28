#include <stdio.h>
#include <stdlib.h>
#include "countingSort.h"
#include "../Structs/structs.h"

void countingSort(int *v, int n, int max, contador *cont) {
  int output[n];
  int count[max + 1];
  int i;

  for (i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  for (i = 0; i < n; i++) {
    count[v[i]]++;
  }

  for (i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (i = n - 1; i >= 0; i--) {
    output[count[v[i]] - 1] = v[i];
    count[v[i]]--;
  }

  for (i = 0; i < n; i++) {
    v[i] = output[i];
  }
}