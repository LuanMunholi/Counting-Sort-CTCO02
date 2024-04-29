#include "structs.h"
#include <stdio.h>
#include <stdlib.h>

//inicializacao da struct
contador* inicializarContador() {
    contador *cont = malloc(sizeof(contador));
    if (cont == NULL) {
      printf("Erro ao alocar contador. Saindo...\n");
      exit (1);
    }
    cont->comp = 0;
    cont->trocas = 0;
    return cont;
}

// Função que retorna o tamanho do vetor
int getVetTam(tVet *res) { return res->tam; }

// Função que retorna o vetor
int *getVet(tVet *res) { return res->vet; }

// Função que imprime um vetor
// printf("%d ", vet[i])
void imprimeVet(int *v, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("%d ", v[i]);
  }
}

void imprimeVetArq(int *v, int tam, char *filename) {
  FILE *file = fopen(filename, "w");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  for (int i = 0; i < tam; i++) {
    fprintf(file, "%d\n", v[i]);
  }
}

tVet *leArquivo(char *nomeArquivo) {
  FILE *file;
  int tam;
  file = fopen(nomeArquivo, "r");
  if (file == NULL) {
    printf("file vazio");
    return NULL;
  }

  fscanf(file, "%d", &tam); // escaneia o primeiro inteiro

  tVet *str = malloc(sizeof(tVet)); // com o tamanho agora é possivel criar a struct
  if (str == NULL) {
    printf("Impossivel alocar struct");
    free(str);
    fclose(file);
    return NULL;
  }

  str->tam = tam;
  str->vet = malloc(tam * sizeof(int)); // aloca memória para o vetor

  if (str->vet == NULL) {
    printf("Impossível alocar memória para o vetor.\n");
    free(str); // libera a memória alocada para a estrutura
    fclose(file);
    return NULL;
  }

  // lendo os numeros do vetor
  for (int i = 0; i < tam; i++) {
    fscanf(file, "%d", &str->vet[i]);
  }

  fclose(file);

  return str;
}

// Função que retorna a quantidade de comparações
long long int getComp(contador *res) {
    return res->comp;
}

// Função que retorna a quantidade de trocas
long long int getTrocas(contador *res) {
    return res->trocas;
}

// Função que adiciona uma comparação
void addComp(contador *res) {
    res->comp++;
}

// Função que adiciona uma troca
void addTroca(contador *res) {
    res->trocas++;
}

// Função que zera o contador
void resetCont(contador *res) {
    res->comp = 0;
    res->trocas = 0;
}

void liberarMemoria(tVet *res) {
    // Liberar a memória alocada para o vetor
    free(res->vet);
    // Liberar a própria estrutura
    free(res);
}