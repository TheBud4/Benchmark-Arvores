#ifndef CREATE_LIST_H
#define CREATE_LIST_H

#include "./ListStructs.h"

pDLista CreateList(){
    /* aloca memoria para o descritor */
    pDLista pd = malloc(sizeof(DLista));

    /* seta os campos com os valores default */
    pd->quantidade = 0;
    pd->primeiro   = NULL;
    pd->ultimo     = NULL;
    return pd;
}

#endif
