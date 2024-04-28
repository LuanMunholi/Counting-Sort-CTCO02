#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>

// Struct e funçóes do vetor 
typedef struct {
  int *vet;
  int tam;
} tVet;

// Função que retorna o tamanho do vetor
int getVetTam(tVet *res);

// Função que retorna o vetor
int *getVet(tVet *res);

// Função que imprime um vetor
void imprimeVet(int *v, int tam);

// Função que coloca vetor em um .txt
void imprimeVetArq(int *v, int tam, char *filename);

// Função que lê um arquivo e retorna um ponteiro para a estrutura tVet
tVet *leArquivo(char *nomeArquivo);

// Struct e funções do contador
typedef struct {
  long long int comp;
  long long int trocas;
} contador;

// Função que retorna a quantidade de comparações
long long int getComp(contador *res);

// Função que retorna a quantidade de trocas
long long int getTrocas(contador *res);

//Função que adiciona uma comparação
void addComp(contador *res);

//Função que adiciona uma troca
void addTroca(contador *res);

//Função que zera o contador
void resetCont(contador *res);

#endif /* STRUCTS_H */
