#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_REGISTROS 1000
#define MAX_STRING 100

typedef struct {
    int id_bdq;
    char foco_id[MAX_STRING];
    float lat;
    float lon;
    char data_pas[MAX_STRING];
    char pais[MAX_STRING];
    char estado[MAX_STRING];
    char municipio[MAX_STRING];
    char bioma[MAX_STRING];
} Foco;

int comparar_bioma(const void *a, const void *b) {
    return strcmp(((Foco *)a)->bioma, ((Foco *)b)->bioma);
}

int comparar_municipio(const void *a, const void *b) {
    return strcmp(((Foco *)a)->municipio, ((Foco *)b)->municipio);
}

int comparar_data(const void *a, const void *b) {
    return strcmp(((Foco *)a)->data_pas, ((Foco *)b)->data_pas);
}

void bubble_sort(Foco *focos, int total, int (*comparar)(const void *, const void *)) {
    long iteracoes = 0, trocas = 0;

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            iteracoes++;
            if (comparar(&focos[j], &focos[j + 1]) > 0) {
                Foco temp = focos[j];
                focos[j] = focos[j + 1];
                focos[j + 1] = temp;
                trocas++;
            }
        }
    }

    printf("\nIterações realizadas: %ld\n", iteracoes);
    printf("Trocas realizadas: %ld\n", trocas);
}

int particionar(Foco *focos, int baixo, int alto,
                int (*comparar)(const void *, const void *),
                long *iteracoes, long *trocas) {

    Foco pivo = focos[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        (*iteracoes)++;
        if (comparar(&focos[j], &pivo) < 0) {
            i++;
            Foco temp = focos[i];
            focos[i] = focos[j];
            focos[j] = temp;
            (*trocas)++;
        }
    }

    Foco temp = focos[i + 1];
    focos[i + 1] = focos[alto];
    focos[alto] = temp;
    (*trocas)++;

    return i + 1;
}

void quick_sort_recursivo(Foco *focos, int baixo, int alto,
                          int (*comparar)(const void *, const void *),
                          long *iteracoes, long *trocas) {
    if (baixo < alto) {
        int pi = particionar(focos, baixo, alto, comparar, iteracoes, trocas);
        quick_sort_recursivo(focos, baixo, pi - 1, comparar, iteracoes, trocas);
        quick_sort_recursivo(focos, pi + 1, alto, comparar, iteracoes, trocas);
    }
}

void quick_sort(Foco *focos, int total, int (*comparar)(const void *, const void *)) {
    long iteracoes = 0, trocas = 0;
    quick_sort_recursivo(focos, 0, total - 1, comparar, &iteracoes, &trocas);
    printf("\nIterações realizadas: %ld\n", iteracoes);
    printf("Trocas realizadas: %ld\n", trocas);
}

void heapify(Foco *focos, int n, int i,
             int (*comparar)(const void *, const void *),
             long *iteracoes, long *trocas) {

    int maior = i;        // Inicializa o maior como raiz
    int esquerda = 2 * i + 1;  // filho esquerdo
    int direita = 2 * i + 2;   // filho direito

    (*iteracoes)++;

    // Se o filho esquerdo é maior que a raiz
    if (esquerda < n && comparar(&focos[esquerda], &focos[maior]) > 0) {
        maior = esquerda;
    }

    // Se o filho direito é maior que o maior até agora
    if (direita < n && comparar(&focos[direita], &focos[maior]) > 0) {
        maior = direita;
    }

    // Se o maior não é a raiz
    if (maior != i) {
        // Troca a raiz com o maior elemento
        Foco temp = focos[i];
        focos[i] = focos[maior];
        focos[maior] = temp;
        (*trocas)++;

        // Recursivamente faz heapify na sub-árvore afetada
        heapify(focos, n, maior, comparar, iteracoes, trocas);
    }
}

void heap_sort(Foco *focos, int total, int (*comparar)(const void *, const void *)) {
    long iteracoes = 0, trocas = 0;

    // Constrói o heap (reorganiza o array)
    for (int i = total / 2 - 1; i >= 0; i--) {
        heapify(focos, total, i, comparar, &iteracoes, &trocas);
    }

    // Extrai um elemento por vez do heap
    for (int i = total - 1; i > 0; i--) {
        // Move a raiz atual para o final
        Foco temp = focos[0];
        focos[0] = focos[i];
        focos[i] = temp;
        trocas++;

        // Chama heapify no heap reduzido
        heapify(focos, i, 0, comparar, &iteracoes, &trocas);
    }

    printf("\nIterações realizadas: %ld\n", iteracoes);
    printf("Trocas realizadas: %ld\n", trocas);
}

int carregar_csv(const char *filename, Foco *focos, int *total) {
    FILE *arquivo = fopen(filename, "r");
    if (!arquivo) {
        printf("Erro ao abrir arquivo: %s\n", filename);
        return 0;
    }
    char linha[500];
    fgets(linha, sizeof(linha), arquivo); // Pula cabeçalho

    int count = *total;
    while (fgets(linha, sizeof(linha), arquivo) && count < MAX_REGISTROS) {
        linha[strcspn(linha, "\n")] = 0;

        char *token = strtok(linha, ",");
        if (token) focos[count].id_bdq = atoi(token);
        token = strtok(NULL, ",");
        if (token) strncpy(focos[count].foco_id, token, MAX_STRING - 1);
        token = strtok(NULL, ",");
        if (token) focos[count].lat = atof(token);
        token = strtok(NULL, ",");
        if (token) focos[count].lon = atof(token);
        token = strtok(NULL, ",");
        if (token) strncpy(focos[count].data_pas, token, MAX_STRING - 1);
        token = strtok(NULL, ",");
        if (token) strncpy(focos[count].pais, token, MAX_STRING - 1);
        token = strtok(NULL, ",");
        if (token) strncpy(focos[count].estado, token, MAX_STRING - 1);
        token = strtok(NULL, ",");
        if (token) strncpy(focos[count].municipio, token, MAX_STRING - 1);
        token = strtok(NULL, ",");
        if (token) strncpy(focos[count].bioma, token, MAX_STRING - 1);
        count++;
    }
    fclose(arquivo);
    *total = count;
    return 1;
}

void exibir_focos(Foco *focos, int total) {
    printf("\n%-10s %-20s %-12s %-12s %-15s %-30s %-20s\n",
           "ID", "Data", "Lat", "Lon", "Bioma", "Município", "Estado");
    printf("----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < total; i++) {
        printf("%-10d %-20s %-12.6f %-12.6f %-15s %-30s %-20s\n",
               focos[i].id_bdq,
               focos[i].data_pas,
               focos[i].lat,
               focos[i].lon,
               focos[i].bioma,
               focos[i].municipio,
               focos[i].estado);
    }
    printf("\nTotal de registros: %d\n", total);
}

int main() {
    SetConsoleOutputCP(65001);
    Foco *focos = malloc(MAX_REGISTROS * sizeof(Foco));
    if (!focos) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    int total = 0;

    printf("Carregando dados...\n");
    if (!carregar_csv("focos_br_al_ref_2023.csv", focos, &total)) {
        free(focos);
        return 1;
    }
    if (!carregar_csv("focos_br_al_ref_2024.csv", focos, &total)) {
        free(focos);
        return 1;
    }

    int opcao;
    do {
        printf("\n=== SISTEMA DE ORDENAÇÃO DE FOCOS ===\n");
        printf("1 - Ordenar por Bioma (Quick Sort)\n");
        printf("2 - Ordenar por Município (Quick Sort)\n");
        printf("3 - Ordenar por Data (Quick Sort)\n");
        printf("4 - Ordenar por Bioma (Bubble Sort)\n");
        printf("5 - Ordenar por Município (Bubble Sort)\n");
        printf("6 - Ordenar por Data (Bubble Sort)\n");
        printf("7 - Ordenar por Bioma (Heap Sort)\n");
        printf("8 - Ordenar por Município (Heap Sort)\n");
        printf("9 - Ordenar por Data (Heap Sort)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                quick_sort(focos, total, comparar_bioma);
                printf("\n--- DADOS ORDENADOS POR BIOMA (Quick Sort) ---");
                exibir_focos(focos, total);
                break;
            case 2:
                quick_sort(focos, total, comparar_municipio);
                printf("\n--- DADOS ORDENADOS POR MUNICÍPIO (Quick Sort) ---");
                exibir_focos(focos, total);
                break;
            case 3:
                quick_sort(focos, total, comparar_data);
                printf("\n--- DADOS ORDENADOS POR DATA (Quick Sort) ---");
                exibir_focos(focos, total);
                break;
            case 4:
                bubble_sort(focos, total, comparar_bioma);
                printf("\n--- DADOS ORDENADOS POR BIOMA (Bubble Sort) ---");
                exibir_focos(focos, total);
                break;
            case 5:
                bubble_sort(focos, total, comparar_municipio);
                printf("\n--- DADOS ORDENADOS POR MUNICÍPIO (Bubble Sort) ---");
                exibir_focos(focos, total);
                break;
            case 6:
                bubble_sort(focos, total, comparar_data);
                printf("\n--- DADOS ORDENADOS POR DATA (Bubble Sort) ---");
                exibir_focos(focos, total);
                break;
            case 7:
                heap_sort(focos, total, comparar_bioma);
                printf("\n--- DADOS ORDENADOS POR BIOMA (Heap Sort) ---");
                exibir_focos(focos, total);
                break;
            case 8:
                heap_sort(focos, total, comparar_municipio);
                printf("\n--- DADOS ORDENADOS POR MUNICÍPIO (Heap Sort) ---");
                exibir_focos(focos, total);
                break;
            case 9:
                heap_sort(focos, total, comparar_data);
                printf("\n--- DADOS ORDENADOS POR DATA (Heap Sort) ---");
                exibir_focos(focos, total);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    free(focos);
    return 0;
}