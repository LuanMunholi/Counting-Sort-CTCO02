#ifndef Quick_Sort
#define Quick_Sort

#include "../Structs/structs.h"

void swap(int* a, int* b);
int partition(int *v, int low, int high, contador *cont);
void quickSort(int *v, int low, int high, contador *cont);

#endif // Quick_Sort