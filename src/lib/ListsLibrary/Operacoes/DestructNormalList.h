#ifndef DESTRUCT_NORMAL_LIST_H
#define DESTRUCT_NORMAL_LIST_H


/* -------------------------------------*/
void DestructNormalList(pDLista pd){

   pNoh atual, aux;
   atual = pd->primeiro;

   while (atual !=NULL){

      aux = atual->prox;

      free(atual);
      atual = aux;
   }

   pd->primeiro   = NULL;
   pd->ultimo     = NULL;
   pd->quantidade = 0;
}

#endif

