#include <stdio.h>
#include <stdlib.h>
#include "countingSort.h"

void countingSort(int arr[], int n, int max) {
  int output[n];
  int count[max + 1];
  int i;

  for (i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  for (i = 0; i < n; i++) {
    count[arr[i]]++;
  }

  for (i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (i = n - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  for (i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}