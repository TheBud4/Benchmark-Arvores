#include <stdio.h>
#include <stdlib.h>

#include "../Utils.h"
#include "./ArvoreRubroNegra.h"


int main(){
  int sizes[] = {1000, 10000, 100000, 1000000};
  int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
  printf(
      "\nTamanho do conjunto | Tempo Insercao (s) | Tempo Busca (s) | Tempo "
      "Exclusao (s)\n");
  printf(
      "------------------------------------------------------------------------"
      "----\n");
  for (int i = 0; i < num_sizes; i++) {
    int size = sizes[i];
    int* data = gerarDadoAleatorio(size);

    pDArvore testArvore = criarArvore(sizeof(int));

    // Medi��o do tempo de inser��o
    double insertionTime = medirTempoInsercao(testArvore, data, size);

    // Medi��o do tempo de busca
    //double searchTime = medirTempoBusca(testArvore, data, size);

    // Medi��o do tempo de exclus�o
   //double deletionTime = medirTempoExclusao(testArvore, data, size);

    printf("%18d | %18.6f | %15.6f | %18.6f\n", size, insertionTime/*, searchTime,
           deletionTime*/);

    // Liberar mem�ria
    free(data);
  }
    return 0;
  }
