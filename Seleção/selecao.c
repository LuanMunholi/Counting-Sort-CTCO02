#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *vet;
    int tam;
} tVet;

// Função que retorna o tamanho do vetor
int getVetTam(tVet *res)
{
    return res->tam;
}

// Função que retorna o vetor
int *getVet(tVet *res)
{
    return res->vet;
}

// Função que imprime um vetor
// printf("%d ", vet[i])
void imprimeVet(int *v, int tam)
{
    for (int i = 0; i < tam; i++) // for com o tamanho do vetor
    {
        printf("%d ", v[i]);
    }
}

tVet *leArquivo(char *nomeArquivo)
{
    FILE *file;
    int tam;
    file = fopen(nomeArquivo, "r");
    if (file == NULL)
    {
        printf("file vazio");
        return NULL;
    }

    fscanf(file, "%d", &tam); // escaneia o primeiro inteiro

    tVet *str = malloc(sizeof(tVet)); // com o tamanho agora é possivel criar a struct
    if (str == NULL)
    {
        printf("Impossivel alocar struct");
        fclose(file);
        return NULL;
    }

    str->tam = tam;
    str->vet = malloc(tam * sizeof(int)); // aloca memória para o vetor

    if (str->vet == NULL)
    {
        printf("Impossível alocar memória para o vetor.\n");
        free(str); // libera a memória alocada para a estrutura
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < tam; i++) // lendo os numeros do vetor
    {
        fscanf(file, "%d", &str->vet[i]);
    }

    fclose(file);

    return str;
}

int buscaMenor(int *v, int inicio, int tam){
    int aux = inicio;
    for(int i = inicio + 1; i < tam; i++){
        if(v[i]<v[aux])
            aux = i;
    }
    return aux;
}

void selecao(int *v, int tam){
    int marc = 0, menor = 0, aux;
    while(marc < tam - 1){
        menor = buscaMenor(v,marc+1,tam);
        if(v[menor]<v[marc]){
            aux = v[marc]; 
            v[marc] = v[menor];
            v[menor] = aux;
        }
        marc++;
    }
}

