#ifndef REVERSE_LIST_H
#define REVERSE_LIST_H


/* -------------------------------------*/
void ReverseList(pDLista pd){

    pNoh atual, aux, aux1;

    atual       = pd->primeiro;
    aux         = atual->prox;
    atual->prox = NULL;

    while(aux != NULL){
        aux1      = aux->prox;
        aux->prox = atual;

        atual = aux;
        aux   = aux1;
    }

    pd->ultimo   = pd->primeiro;
    pd->primeiro = atual;

}

#endif

