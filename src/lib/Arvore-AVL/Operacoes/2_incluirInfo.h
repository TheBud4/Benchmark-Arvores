#ifndef CRIAR_ARVORE_BINARIA_H
#define CRIAR_ARVORE_BINARIA_H

//---------------------------------------
pNohArvore rotacaoDireita(pNohArvore raiz) {
  if (raiz == NULL || raiz->esquerda == NULL) {
    return raiz;  // Nada a rotacionar se raiz ou raiz->esquerda for NULL
  }
  pNohArvore u = raiz->esquerda;
  raiz->esquerda = u->direita;
  u->direita = raiz;
  return u;
}

//---------------------------------------
pNohArvore rotacaoEsquerda(pNohArvore raiz) {
  if (raiz == NULL || raiz->direita == NULL) {
    return raiz;  // Nada a rotacionar se raiz ou raiz->esquerda for NULL
  }
  pNohArvore u = raiz->direita;
  raiz->direita = u->esquerda;
  u->esquerda = raiz;
  return u;
}

//---------------------------------------
pNohArvore rotacaoEsquerdaDireita(pNohArvore raiz) {
  if (raiz == NULL || raiz->esquerda == NULL) {
    return raiz;  // Nada a rotacionar se raiz ou raiz->esquerda for NULL
  }
  raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
  return rotacaoDireita(raiz);
}

//---------------------------------------
pNohArvore rotacaoDireitaEsquerda(pNohArvore raiz) {
  if (raiz == NULL || raiz->direita == NULL) {
    return raiz;  // Nada a rotacionar se raiz ou raiz->esquerda for NULL
  }
  raiz->direita = rotacaoDireita(raiz->direita);
  return rotacaoEsquerda(raiz);
}

/* --------------------------*/
pNohArvore incluirInfoRecursivo(pNohArvore raiz, void *info,
                                FuncaoComparacao pfc) {
  // caso base
  if (raiz == NULL) {
    pNohArvore pnh = malloc(sizeof(NohArvore));
    pnh->info = info;
    pnh->esquerda = NULL;
    pnh->direita = NULL;
    pnh->fb = 0;
    return pnh;
  }

  // caso recursivo
  if (pfc(raiz->info, info) <= 0) {
    raiz->esquerda = incluirInfoRecursivo(raiz->esquerda, info, pfc);
  } else {
    raiz->direita = incluirInfoRecursivo(raiz->direita, info, pfc);
  }

 
  //  recalcular o FB da raiz que recebeu o novo noh como filho da esquerda
  raiz->fb = alturaRecursiva(raiz->direita) - alturaRecursiva(raiz->esquerda);

  if (raiz->fb == 2 || raiz->fb == -2) {
    // precisa balancear, ent�o verifica qual rota��o aplicar

    if (raiz->fb == 2) {
      // sinais iguais -> rota��o simples
      if ((raiz->direita != NULL &&
           (raiz->direita->fb == 1 || raiz->direita->fb == 0)) ||
          (raiz->esquerda != NULL &&
           (raiz->esquerda->fb == 1 || raiz->esquerda->fb == 0))) {
        // rotacao simples esquerda
        pNohArvore novaRaiz = rotacaoEsquerda(raiz);
        recalcularFB_Recursivo(novaRaiz);
        return novaRaiz;
      }

      // sinais diferentes -> rotacao dupla direita-esquerda
      if ((raiz->direita != NULL && raiz->direita->fb == -1) ||
          (raiz->esquerda != NULL && raiz->esquerda->fb == -1)) {
        // rotacao dupla direita-esquerda
        pNohArvore novaRaiz = rotacaoDireitaEsquerda(raiz);
        recalcularFB_Recursivo(novaRaiz);
        return novaRaiz;
      }
    }

    if (raiz->fb == -2) {
      // sinais iguais -> rota��o simples
      if ((raiz->direita != NULL &&
           (raiz->direita->fb == -1 || raiz->direita->fb == 0)) ||
          (raiz->esquerda != NULL &&
           (raiz->esquerda->fb == -1 || raiz->esquerda->fb == 0))) {
       // printf(" -> Rotacao simples Direita <- ");

        // rotacao simples direita
        pNohArvore novaRaiz = rotacaoDireita(raiz);
        recalcularFB_Recursivo(novaRaiz);
        return novaRaiz;
      }

      // sinais diferentes -> rotacao dupla
      if ((raiz->direita != NULL && raiz->direita->fb == 1) ||
          (raiz->esquerda != NULL && raiz->esquerda->fb == 1)) {
        // rotacao dupla esquerda-direita
        pNohArvore novaRaiz = rotacaoEsquerdaDireita(raiz);
        recalcularFB_Recursivo(novaRaiz);
        return novaRaiz;
      }
    }
  }

  return raiz;
}

/* ----------------------------------------------------------*/
void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {
  //printf("\n --- Incluindo info: %d ---\n", *((int *)info));
  arvore->raiz = incluirInfoRecursivo(arvore->raiz, info, pfc);
}

#endif
