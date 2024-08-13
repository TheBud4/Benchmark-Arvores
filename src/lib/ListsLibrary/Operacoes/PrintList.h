#ifndef PRINT_LIST_H
#define PRINT_LIST_H

void PrintList(pDLista pd, FuncaoImpressao pfi){

    pNoh aux;
    aux = pd->primeiro;

    while(aux != NULL){
       /*printf("%d", *(((int *)aux->info)));*/
       pfi(aux->info);

       aux = aux->prox;

    }
}

#endif
