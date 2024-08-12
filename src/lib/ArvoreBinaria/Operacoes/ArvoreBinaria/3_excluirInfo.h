#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H


pNohArvore encontrarMenorNo(pNohArvore no){
    pNohArvore atual = no;
    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}
/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc){

    if (raiz == NULL)
        return NULL;

    if (fc(raiz->info, info) < 0)
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, fc);

    else if (fc(raiz->info, info) > 0)
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, fc);



    else {
        if (raiz->esquerda == NULL)
         {
            pNohArvore temp = raiz->direita;
            free(raiz);
            return temp;

        }
         else if (raiz->direita == NULL)
         {
            pNohArvore temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL && raiz->esquerda == NULL)
        {
            free(raiz);
            raiz == NULL;
        }

        else
        {

            pNohArvore temp = raiz->direita;
            if (temp->esquerda == NULL)
             {
                raiz->info = temp->info;
                raiz->direita = temp->direita;
                free(temp);
             }
            else
             {
                while (temp->esquerda->esquerda != NULL)
                    temp = temp->esquerda;
                pNohArvore substituto = temp->esquerda;
                raiz->info = substituto->info;
                temp->esquerda = substituto->direita;
                free(substituto);
            }

        }



    }
    return raiz;


}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

  if (arvore->raiz == NULL)
        return NULL;

    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
    return 0;

}

#endif
