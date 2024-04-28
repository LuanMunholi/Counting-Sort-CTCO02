#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <stdio.h>
#include <stdlib.h>

// Struct que contém o vetor e seu tamanho
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

// Função que lê um arquivo e retorna um ponteiro para a estrutura tVet
tVet *leArquivo(char *nomeArquivo);

#endif /* INSERTION_SORT_H */
