#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumbers(size) {
  char filename[50];
  // Formata o nome do arquivo com base no tamanho especificado
  sprintf(filename, "random_%d.txt", size);
  FILE *file = fopen(filename, "w");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  // Semente para números aleatórios baseada no tempo atual
  srand(time(NULL));

  // Escreve o tamamho do vetor no arquivo
  fprintf(file, "%d\n", size);

  fprintf(file, "%d\n", rand());
  // Escreve números aleatórios no arquivo
  for (int i = 0; i < size; i++) {
    fprintf(file, "%d\n", rand());
  }

  fclose(file);
}