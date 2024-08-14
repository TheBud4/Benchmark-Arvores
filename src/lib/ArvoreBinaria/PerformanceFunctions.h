#ifndef PERFORMANCE_FUNCTIONS_H
#define PERFORMANCE_FUNCTIONS_H

// TODO: Implementar geração de nuemeros

int* gerarDadoAleatorio(int size) {
  if(size <= 0)
   return NULL;

  int* data = (int*)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    data[i] = rand() % (size);  // Gera n�meros entre 0 e size*10-1
  }
  return data;
}

double medirTempoInsercao(pDArvore arvore, int* data, int size) {
  clock_t start, end;
  int* pdata;
  double cpu_time_used;
  for (int i = 0; i < size - 1; i++) {
    pdata = alocaInt(data[i]);
    incluirInfo(arvore, pdata, comparaInt);
  }
  pdata = alocaInt(data[size - 1]);
  start = clock();
  incluirInfo(arvore, pdata, comparaInt);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  return cpu_time_used;
}

double medirTempoBusca(pDArvore arvore, int* data, int size) {
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  buscarInfo(arvore, data, comparaInt);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  return cpu_time_used;
}

double medirTempoExclusao(pDArvore arvore, int* data, int size) {
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  excluirInfo(arvore, data, comparaInt);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  return cpu_time_used;
}

#endif  // PERFORMANCE_FUNCTIONS_H
