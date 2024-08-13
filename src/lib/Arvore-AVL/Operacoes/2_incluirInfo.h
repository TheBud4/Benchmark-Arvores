#ifndef CRIAR_ARVORE_BINARIA_H
#define CRIAR_ARVORE_BINARIA_H

//---------------------------------------
pNohArvore rotacaoDireita(pNohArvore raiz) {
  pNohArvore u;

  u = raiz->esquerda;
  raiz->esquerda = u->direita;
  u->direita = raiz;

  return u;
}

//---------------------------------------
pNohArvore rotacaoEsquerda(pNohArvore raiz) {
  pNohArvore u;

  u = raiz->direita;
  raiz->direita = u->esquerda;
  u->esquerda = raiz;

  return u;
}

//---------------------------------------
pNohArvore rotacaoEsquerdaDireita(pNohArvore raiz) {
  raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
  return rotacaoDireita(raiz);
}

//---------------------------------------
pNohArvore rotacaoDireitaEsquerda(pNohArvore raiz) {
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

  // faz a inclus�o normal na �rvore, em seguida, recalcula o FB
  // de cada n�h afetado pela inclus�o (conforme a pilha de recurs�o) e
  // verifica quais ficaram desbalanceados e aplica as opera��es de rota��o
  // necess�rias, conforme cada caso.
  // As rota��es devem ser aplicadas no sentido dos n�s folha
  // para a raiz da �rvore. Por que? Porque a rotacao de um n� interno pode
  // afetar o FB do n� pai.

  // � preciso tamb�m recalcular o FB dos n�hs rotacionados
  //

  // printf("\n FB da raiz: %d[fb=%d] \n", *((int*)raiz->info), raiz->fb);
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
        printf(" -> Rotacao simples Direita <- ");

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
  printf("\n --- Incluindo info: %d ---\n", *((int *)info));
  arvore->raiz = incluirInfoRecursivo(arvore->raiz, info, pfc);
}

#endif
