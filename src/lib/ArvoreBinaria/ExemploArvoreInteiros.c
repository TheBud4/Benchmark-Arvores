#include <stdio.h>
#include "Utils.h"
#include "ArvoreBinaria.h"

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
    rewind(arq);
    *aux = fread(p,sizeof(int),1,arq);
    for(i=0;i<=1000;i++){
        buscarInfo(arvore, aux, comparaInt);
        *aux = fread(p,sizeof(int),1,arq);
    }
    fclose(arq);

    //teste "normal"
    /*pDArvore pArvoreInt = criarArvore(2);
    int i,aux;
    for(i=0;i<=10000;i++){
        aux = rand()%20000;
        incluirInfo(pArvoreInt, aux, comparaInt);
    }*/
    //return 0;
}
