#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *vet;
    int tam;
} tVet;

// Função que imprime um vetor
// printf("%d ", vet[i])
void imprimeVet(int *v, int tam)
{
    for (int i = 0; i < tam; i++) // for com o tamanho do vetor
    {
        printf("%d ", v[i]);
    }
}

// Função que faz a fusão de dois vetores pré-ordenados e os copia para o vetor original
void merge(int *v, int inicio, int meio, int fim)
{
    // variaveis auxiliares
    int i = 0, j = 0, k = 0;

    // calculando tamanho dos vetores
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int n3 = (fim - inicio) + 1;

    // iniciando os vetores
    int *V1 = malloc(n1 * sizeof(int));
    int *V2 = malloc(n2 * sizeof(int));
    int *V3 = malloc(n3 * sizeof(int));
    if (V1 == NULL || V2 == NULL || V3 == NULL)
    {
        printf("Não foi possível alocar vetores V1, V2, V3");
        return;
    }

    // preenchendo os vetores
    for (i = 0; i < n1; i++)
        V1[i] = v[inicio + i];

    for (j = 0; j < n2; j++)
        V2[j] = v[meio + 1 + j];

    i = 0;
    j = 0;

    // compara os elementos de V1 e V2 e ordena no vetor auxiliar V3
    while (i < n1 && j < n2)
    {
        if (V1[i] <= V2[j])
        {
            V3[k] = V1[i];
            i++;
        }
        else
        {
            V3[k] = V2[j];
            j++;
        }
        k++;
    }

    // em caso de sobra de elementos em V1
    while (i < n1)
    {
        V3[k] = V1[i];
        i++;
        k++;
    }

    // em caso de sobra de elementos em V2
    while (j < n2)
    {
        V3[k] = V2[j];
        j++;
        k++;
    }

    // copiando os elementos ordenados de V3 de volta para o vetor original v
    for (int i = 0; i < n3; i++)
        v[inicio + i] = V3[i];
}

// Função recursiva que executa a fase de divisão do algoritmo mergesort
void mergesort(int *v, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        mergesort(v, inicio, meio);
        mergesort(v, meio + 1, fim);

        merge(v, inicio, meio, fim);
    }
}

// Função que lê os dados de um arquivo e carrega em um vetor de inteiros
// Retorna o tipo tVet, composto por um vetor de inteiros e o tamanho do vetor
// A primeira linha do arquivo possui o tamanho do vetor
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
