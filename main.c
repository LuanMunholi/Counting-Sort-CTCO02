#include "./QuickSort/quickSort.h"
#include "./InsertionSort/insertionSort.h"
#include "./CountingSort/countingSort.h"
#include "./MergeSort/mergeSort.h"
#include "./SelectionSort/selectionSort.h"
#include "./RandomNumbers/randomNumbers.h"
#include "./Vetor/vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void sort(char* algName, tVet* tArr);

int main() {
  tVet *tArr;
  char inFile[25];
  char resposta;
  clock_t start, end;
  double tempo_decorrido;

  /*
  printf("Deseja gerar números aleatórios? (y/n): ");
  scanf(" %c", &resposta); // Espaço antes de %c para ignorar espaços em branco e quebras de linha

  if (resposta == 'y' || resposta == 'Y') {
    printf("Gerando números aleatórios...\n");
    for(int i=1000; i<=10000000; i=i*10){
       generateRandomNumbers(i);
    }
  } else if (resposta == 'n' || resposta == 'N') {
    printf("Números aleatórios contidos nos arquivos sendo reutilizados..\n");
    // Lógica para não gerar números aleatórios
  } else {
    printf("Resposta inválida. Digite 'y' para sim ou 'n' para não.\n");
    return 1;
  }

  for(int i=1000; i<=1000; i=i*10){
    sprintf(inFile, "random_%d.txt", i);
  */


  tArr = leArquivo(inFile);


  //Exemplo de captura de tempo do algoritimo
  // Captura o tempo antes da execução da função
  start = clock();

  //Roda o algoritimo
  sort("quickSort", tArr);

  // Captura o tempo depois da execução da função
  end = clock();

  // Calcula o tempo decorrido em milissegundos
  tempo_decorrido = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC;

  tArr = leArquivo(inFile);
  sort("insertionSort", tArr);
  tArr = leArquivo(inFile);
  sort("countingSort", tArr);
  //tArr = leArquivo(inFile);
  sort("mergeSort", tArr);
  //tArr = leArquivo(inFile);
  //sort("selectionSort", tArr);
  
  //}

  // TESTAR AQUI
  imprimeVetArq(getVet(tArr), getVetTam(tArr), "saida_1000.txt");
}

void sort(char* algName, tVet* tArr){
  if(!strcmp(algName, "quickSort"))
    quickSort(getVet(tArr), 0, getVetTam(tArr)-1);
  else if(!strcmp(algName, "insertionSort"))
    insertionSort(getVet(tArr), getVetTam(tArr)-1);
  else if (!strcmp(algName, "mergeSort"))
    mergeSort(getVet(tArr), 0, getVetTam(tArr)-1);
  else if (!strcmp(algName, "countingSort"))
    countingSort(getVet(tArr), 0, getVetTam(tArr)-1);
  else if (!strcmp(algName, "selectionSort"))
    selectionSort(getVet(tArr), getVetTam(tArr)-1);

  char outFile[25];
  sprintf(outFile, "out_%s_%d.txt", algName, getVetTam(tArr));
  imprimeVetArq(getVet(tArr), getVetTam(tArr), outFile);
}
