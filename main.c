#include "./QuickSort/quickSort.h"
#include "./InsertionSort/insertionSort.h"
#include "./CountingSort/countingSort.h"
#include "./MergeSort/mergeSort.h"
#include "./SelectionSort/selectionSort.h"
#include "./Structs/structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
  tVet *tArr;
  char inFile[25];
  char resposta;
  clock_t start, end;
  double tempo_decorrido;
  contador *cont;
  resetCont(cont);

  tArr = leArquivo("Entradas/Aleatorio/100000/aleatorio_100000_1.txt");
  //imprimeVet(getVet(tArr), getVetTam(tArr));

  //Exemplo de captura de tempo do algoritimo
  // Captura o tempo antes da execução da função
  start = clock();

  //Funcao a contar o tempo
  //selectionSort(getVet(tArr),getVetTam(tArr),cont);
  //mergeSort(getVet(tArr), 0, getVetTam(tArr) - 1, cont);
  //quickSort(getVet(tArr), 0, getVetTam(tArr)-1, cont);
  //insertionSort(getVet(tArr), getVetTam(tArr), cont);
  countingSort(getVet(tArr),getVetTam(tArr),);

  // Captura o tempo depois da execução da função
  end = clock();

  // Calcula o tempo decorrido em milissegundos
  tempo_decorrido = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC;

  printf("\nnovo vetor\n");
  imprimeVet(getVet(tArr), getVetTam(tArr));

  printf("\nA ordenacao levou: %f ms\n",tempo_decorrido);
  printf("Quantidade de comparacoes: %lld\n", getComp(cont));
  printf("Quantidade de trocas: %lld\n", getTrocas(cont));
  resetCont(cont);
}


//codigo gcc para executar 
//gcc main.c QuickSort/quickSort.c InsertionSort/insertionSort.c CountingSort/countingSort.c MergeSort/mergeSort.c SelectionSort/selectionSort.c Structs/structs.c -o teste