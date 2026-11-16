/*
 * kwatch - Projeto 2 (Algoritmos e Programação II, turma 02P11)
 * Nicolas Soares Santos, RA 10370082
 */

#include "kwatch.h"
#include <stdio.h>

int main ()
{
  int ids[MAX]; int unidadesIds[MAX]; int meses[MAX]; int anos[MAX]; float consumos[MAX]; int unidadeIdsCatalogo[MAX]; char descricoes[MAX][50];

  int n = carregarLeituras("leituras.txt", ids, unidadesIds, meses, anos, consumos, MAX);

  if (n == -1)
  {
    printf("Erro ao abrir o arquivo leituras.txt.\nEncerrando o programa.\n");
    return 0;
  }

  int nUnidade = carregarUnidades("unidades.csv", unidadeIdsCatalogo, descricoes, MAX);

  if (nUnidade == -1) {
    printf("Erro ao abrir o arquivo unidades.csv.\nEncerrando o programa.\n");
    return 0;
  }

  int opcao; int ordenado = 0;

  do {
    printf("===== SISTEMA DE ANALISE DE CONSUMO DE ENERGIA =====\n");
    printf("1. Mostrar leituras ordenadas por ID\n");
    printf("2. Buscar leitura por ID\n");
    printf("3. Calcular consumo de uma unidade\n");
    printf("4. Calcular consumo em um periodo\n");
    printf("5. Identificar unidade com maior consumo\n");
    printf("6. Sair da aplicacao\n");
    printf("Escolha uma opcao:");

    scanf("%d", &opcao); // lê o número digitado e guarda em opcao

    switch (opcao) {       // escolhe o bloco pelo valor de opcao
      case 1:
        if (ordenado == 0) {
          printf("Escolha o algoritmo de ordenacao:\n");
          printf("1. Bubble Sort\n");
          printf("2. Insertion Sort\n");
          printf("3. Selection Sort\n");
          printf("4. Quick Sort\n");
          printf("5. Merge Sort\n");
          printf("Opcao:");

          int alg;
          scanf("%d", &alg);
          switch (alg) {
            case 1: bubbleSortLeituraPorId(ids, unidadesIds, meses, anos, consumos, n);
              break;
            case 2: insertionSortLeituraPorId(ids, unidadesIds, meses, anos, consumos, n);
              break;
            case 3: selectionSortLeituraPorId(ids, unidadesIds, meses, anos, consumos, n);
              break;
            case 4: quickSortLeituraPorId(ids, unidadesIds, meses, anos, consumos, 0, n - 1);
              break;
            case 5: mergeSortLeituraPorId(ids, unidadesIds, meses, anos, consumos, 0, n - 1);
              break;
          }
          ordenado = 1;
        }
        printf("Leituras ordenadas por ID:\n");
        printf("ID | Unidade | Descricao | Mes | Ano | Consumo (kWh)\n");
        printf("-----------------------------------------------------------------------\n");
        for (int i = 0; i < n; i++) {
          int pos = buscaLinear(unidadeIdsCatalogo, nUnidade, unidadesIds[i]); 
          printf("%d | %d | %s | %d | %d | %.2f\n", ids[i], unidadesIds[i], descricoes[pos], meses[i], anos[i], consumos[i]);
        }
        break;             // sai do switch; sem ele, roda o case de baixo também
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        printf("Encerrando o programa.\n");
        break;
      default:             // qualquer número que não é 1 a 6
        printf("Opcao invalida. Tente novamente.\n");
        break;
    }                      // fecha o switch
  } while (opcao != 6);

  return 0;
}
