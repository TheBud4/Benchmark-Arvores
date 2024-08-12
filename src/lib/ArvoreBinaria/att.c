#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include "ArvoreBinaria.h"

void main(){
    pDArvore arvore = criarArvore(2);
    int *aux, i, *p;
    p = malloc(sizeof(int));
    FILE* arq;
    arq = fopen("k.txt","a+b");
    *aux = fread(p,sizeof(int),1,arq);
    for(i=0;i==999;i++){
        incluirInfo(arvore, aux, comparaInt);
        *aux = fread(p,sizeof(int),1,arq);
    }
    rewind(arq);
}
