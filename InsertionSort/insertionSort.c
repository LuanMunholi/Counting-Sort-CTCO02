#include <stdio.h>
#include <stdlib.h>
#include "insertionSort.h"
#include "../Structs/structs.h"

void insertionSort(int *v, int n, contador *cont) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > key) {
            addComp(cont);
            v[j + 1] = v[j];
            addTroca(cont);
            j = j - 1;
        }
        addComp(cont);

        v[j + 1] = key;
    }
}