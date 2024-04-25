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

  tArr = leArquivo("Entradas/Aleatorio/1000/aleatorio_1000_1.txt");
  //imprimeVet(getVet(tArr), getVetTam(tArr));

  //Exemplo de captura de tempo do algoritimo
  // Captura o tempo antes da execução da função
  start = clock();

  //Funcao a contar o tempo
  //selectionSort(getVet(tArr),getVetTam(tArr));
  mergeSort(getVet(tArr), 0, getVetTam(tArr) - 1, cont);

  // Captura o tempo depois da execução da função
  end = clock();

  // Calcula o tempo decorrido em milissegundos
  tempo_decorrido = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC;

  printf("\nnovo vetor\n");
  imprimeVet(getVet(tArr), getVetTam(tArr));

  printf("\n A ordenacao levou: %f ms\n",tempo_decorrido);
  printf("Quantidade de comparacoes: %d\n", getComp(cont));
  printf("Quantidade de trocas: %d\n", getTrocas(cont));
}
