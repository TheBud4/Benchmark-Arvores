#ifndef SEARCH_INFO_POS_H
#define SEARCH_INFO_POS_H

/* --------------------------------- */
void* SearchInfoPos(pDLista lista, int pos){

   pNoh atual = lista->primeiro;
   int  cont  = 1;
   while (atual!=NULL){
      if (cont==pos)
        return atual->info;
      atual = atual->prox;
      cont++;
   }
   return NULL;
}

#endif
