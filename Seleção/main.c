#include <stdio.h>
#include <stdlib.h>
#include "selecao.h"

int main(){
    // DECLARAÇÃO DE VARIÁVEIS
    tVet *res;
    char nomeArquivo[80];
    scanf("%s", nomeArquivo);//Colocar o nome do arquivo de teste
    
    res = leArquivo(nomeArquivo);
    imprimeVet(getVet(res), getVetTam(res));
    printf("\n");
    selecao(getVet(res),getVetTam(res));
    imprimeVet(getVet(res), getVetTam(res));
    free(res);
    return 0;

}