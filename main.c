#include "./QuickSort/quickSort.h"
#include "./InsertionSort/insertionSort.h"
#include "./CountingSort/countingSort.h"
#include "./MergeSort/mergeSort.h"
#include "./SelectionSort/selectionSort.h"
#include "./Structs/structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void testAscending(char *algName);
void testRandom(char *algName);
void testAlmostSorted(char *algName);
void testDescending(char *algName);
void sort(char* algName, tVet* tArr, contador* cont);

int main() {
  //se algum estourar memoria ou processamento, coloque a linha do algoritmo como comentario.
  printf("------ TEST WITH RANDOM NUMBERS ------\n");
  testRandom("quickSort");
  //testRandom("insertionSort");
  //testRandom("countingSort");
 // testRandom("mergeSort");
  //testRandom("selectionSort");

  /*printf("------ TEST WITH ASCENDING ORDER ------\n");
  testAscending("quickSort");
  testAscending("insertionSort");
  //testAscending("countingSort");
  testAscending("mergeSort");
  testAscending("selectionSort");

  printf("------ TEST WITH DESCENDING ORDER ------\n");
  testDescending("quickSort");
  testDescending("insertionSort");
  //testDescending("countingSort");
  testDescending("mergeSort");
  testDescending("selectionSort");

  printf("------ TEST WITH ALMOST SORTED ------\n");
  testAlmostSorted("quickSort");
  testAlmostSorted("insertionSort");
  //testAlmostSorted("countingSort");
  testAlmostSorted("mergeSort");
  testAlmostSorted("selectionSort");*/
}

void testRandom(char* algName){
  printf("  [%s]", algName);
  char inFile[60];
  tVet *tArr;
  clock_t start, end;
  double tempo_decorrido;
  contador *cont = inicializarContador();

  //fazendo o teste de tempo para cada arquivo de entrada para o algoritmo recebido como parametro.
  for(int i=1000; i<=1000000; i=i*10){
    printf("    Entry size: %d\n", i);
    for(int j=1; j<=5; j++){
      sprintf(inFile, "Entradas/Aleatorio/%d/aleatorio_%d_%d.txt", i, i, j);
      tArr = leArquivo(inFile);
      start = clock(); //inicia relogio
      sort(algName, tArr, cont); //ordena vetor
      end = clock(); //para relogio
      tempo_decorrido = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC; //calcula tempo
      printf("    [%d]:\n", j);
      printf("      - time: %f\n", tempo_decorrido);
      printf("      - swap: %lld\n", getTrocas(cont));
      printf("      - comparison: %lld\n", getComp(cont));
      resetCont(cont);
    }
  }
  free(cont);
}

void testAscending(char* algName){
  printf("  [%s]", algName);
  char inFile[60];
  tVet *tArr;
  clock_t start, end;
  double tempo_decorrido;
  contador *cont = inicializarContador();

  //fazendo o teste de tempo para cada arquivo de entrada para o algoritmo recebido como parametro.
  for(int i=1000; i<=10000000; i=i*10){
    printf("    Entry size: %d\n", i);
      sprintf(inFile, "Entradas/Ordem crescente/ordem_crescente_%d.txt", i);
      tArr = leArquivo(inFile);
      start = clock(); //inicia relogio
      sort(algName, tArr, cont); //ordena vetor
      end = clock(); //para relogio
      tempo_decorrido = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC; //calcula tempo
      printf("      - time: %f\n", tempo_decorrido);
      printf("      - swap: %lld\n", getTrocas(cont));
      printf("      - comparison: %lld\n", getComp(cont));
      resetCont(cont);
  }
  free(cont);
}

void testDescending(char* algName){
  printf("  [%s]", algName);
  char inFile[60];
  tVet *tArr;
  clock_t start, end;
  double tempo_decorrido;
  contador *cont = inicializarContador();

  //fazendo o teste de tempo para cada arquivo de entrada para o algoritmo recebido como parametro.
  for(int i=1000; i<=10000000; i=i*10){
    printf("    Entry size: %d\n", i);
      sprintf(inFile, "Entradas/Ordem decrescente/ordem_decrescente_%d.txt", i);
      tArr = leArquivo(inFile);
      start = clock(); //inicia relogio
      sort(algName, tArr, cont); //ordena vetor
      end = clock(); //para relogio
      tempo_decorrido = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC; //calcula tempo
      printf("      - time: %f\n", tempo_decorrido);
      printf("      - swap: %lld\n", getTrocas(cont));
      printf("      - comparison: %lld\n", getComp(cont));
      resetCont(cont);
  }
  free(cont);
}

void testAlmostSorted(char* algName){
  printf("  [%s]", algName);
  char inFile[60];
  tVet *tArr;
  clock_t start, end;
  double tempo_decorrido;
  contador *cont = inicializarContador();

  //fazendo o teste de tempo para cada arquivo de entrada para o algoritmo recebido como parametro.
  for(int i=1000; i<=100000; i=i*10){
    printf("    Entry size: %d\n", i);
    for(int j=1; j<=5; j++){
      sprintf(inFile, "Entradas/Quase Ordenado/%d/aleatorio_%d_%d.txt", i, i, j);
      tArr = leArquivo(inFile);
      start = clock(); //inicia relogio
      sort(algName, tArr, cont); //ordena vetor
      end = clock(); //para relogio
      tempo_decorrido = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC; //calcula tempo
      printf("    [%d]:\n", j);
      printf("      - time: %f\n", tempo_decorrido);
      printf("      - swap: %lld\n", getTrocas(cont));
      printf("      - comparison: %lld\n", getComp(cont));
      resetCont(cont);
    }
  }
  free(cont);
}

void sort(char* algName, tVet* tArr, contador* cont){
  if(!strcmp(algName, "quickSort"))
    quickSort(getVet(tArr), 0, getVetTam(tArr)-1, cont);//
  else if(!strcmp(algName, "insertionSort"))
    insertionSort(getVet(tArr), getVetTam(tArr), cont);//
  else if (!strcmp(algName, "mergeSort"))
    mergeSort(getVet(tArr), 0, getVetTam(tArr)-1, cont);//
  else if (!strcmp(algName, "countingSort"))
    countingSort(getVet(tArr), getVetTam(tArr), cont);//
  else if (!strcmp(algName, "selectionSort"))
    selectionSort(getVet(tArr), getVetTam(tArr), cont);//
}

//codigo gcc para executar 
//gcc main.c QuickSort/quickSort.c InsertionSort/insertionSort.c CountingSort/countingSort.c MergeSort/mergeSort.c SelectionSort/selectionSort.c Structs/structs.c -o teste