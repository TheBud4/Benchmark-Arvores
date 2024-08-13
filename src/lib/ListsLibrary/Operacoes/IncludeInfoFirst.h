#ifndef INCLUDE_INFO_FIRST_H
#define INCLUDE_INFO_FIRST_H

void IncludeInfoFirst(pDLista pd, void *info){

    if (pd == NULL){
        printf("Lista nao existe ainda, nao eh possivel incluir!");
        return;
    }
    /* aloca memoria para guardar a nova info */
    pNoh pNovo = malloc(sizeof(Noh));

    /* guarda a informacao no campo "info" do novo noh alocado */
    pNovo->info = info;

    pNovo->prox  = pd->primeiro;
    pd->primeiro = pNovo;

    if(pd->ultimo == NULL)
        pd->ultimo = pNovo;
}

#endif
