#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H

pNohArvore buscarInfoRecursivo (pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if(raiz == NULL){
        return NULL;
    }
    else if(pfc(raiz->info,info) == 0){ //info = raiz
        return raiz;
    }
    else if(pfc(raiz->info,info) > 0){  //info > raiz
        return buscarInfoRecursivo(raiz->direita,info,pfc);
    }
    else{                                //info < raiz
        return buscarInfoRecursivo(raiz->esquerda,info,pfc);
    }
}


/* ----------------------------------------------------------*/
pNohArvore buscarInfo (pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    pNohArvore aux;
    if(arvore->raiz == NULL){
        return NULL;
    }
    else{
        aux = buscarInfoRecursivo(arvore->raiz, info, pfc);
        if(aux!=NULL){
            return aux;
        }
        else{
            return NULL;
        }
    }
}

#endif

