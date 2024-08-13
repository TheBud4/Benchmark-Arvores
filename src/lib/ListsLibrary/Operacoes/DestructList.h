#ifndef DESTRUCT_LIST_H
#define DESTRUCT_LIST_H

void DestructRecursiveList(pNoh atual){
    if (atual == NULL)
        return;
    DestructRecursiveList(atual->prox);
    free(atual);
}


/* -------------------------------------*/
void DestructList(pDLista pd){
   DestructRecursiveList(pd->primeiro);
   pd->primeiro   = NULL;
   pd->ultimo     = NULL;
   pd->quantidade = 0;
}

#endif

