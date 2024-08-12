#include <stdio.h>
#include "Utils.h"
#include "ArvoreAVL.h"

int main(){
    pDArvore arvore = criarArvore(2);
    int *aux, i, *p;
    p = malloc(sizeof(int));
    FILE* arq;
    arq = fopen("1k.txt","a+b");
    *aux = fread(p,sizeof(int),1,arq);
    for(i=0;i<=1000;i++){
        incluirInfo(arvore, aux, comparaInt);
        *aux = fread(p,sizeof(int),1,arq);
    }
    *aux = fread(p,sizeof(int),1,arq);
    for(i=0;i<=1000;i++){
        excluirInfo(arvore, aux, comparaInt);
        *aux = fread(p,sizeof(int),1,arq);
    }

    fclose(arq);
 }
