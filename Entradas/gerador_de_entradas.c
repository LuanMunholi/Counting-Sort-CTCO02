#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    int total_numbers = 10000000, temp = 0, index_to_shuffle = 0; 
    int *numbers = malloc(total_numbers * sizeof(int));
    int num_to_shuffle = total_numbers * 0.10;

    // Verifica se a alocação de memória foi bem-sucedida
    if (numbers == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Gerando números ordenados
    for (int i = 0; i < total_numbers; i++) {
        numbers[i] = i+1;
    }

    //Seed diferente pra cara arquivo
    srand(42376019);

    // Selecionando 10% dos números para embaralhar
    for (int i = 0; i < num_to_shuffle; i++) {
        index_to_shuffle = rand() % total_numbers;
        temp = numbers[i];
        numbers[i] = numbers[index_to_shuffle];
        numbers[index_to_shuffle] = temp;
    }

    // Escrevendo os números com 10% deles desordenados de volta para o arquivo
    file = fopen("quase_ordenado_10000000_5.txt","a");
    fprintf(file, "%d\n",total_numbers);

    for (int i = 0; i < total_numbers; i++) {
        fprintf(file, "%d ", numbers[i]);
    }
    fclose(file);
}