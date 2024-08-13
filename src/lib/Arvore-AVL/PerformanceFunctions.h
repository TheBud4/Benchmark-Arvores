#ifndef PERFORMANCE_FUNCTIONS_H
#define PERFORMANCE_FUNCTIONS_H

int* generateRandomData(int size) {
    int* data = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        data[i] = rand() % (size * 10); // Gera n�meros entre 0 e size*10-1
    }
    return data;
}

double measureInsertionTime(pDArvore arvore, int* data, int size) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int i = 0; i < size; i++) {
        int* pdata = alocaInt(data[i]);
        incluirInfo(arvore, pdata, comparaInt);
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

#endif // PERFORMANCE_FUNCTIONS_H
