/*
 * kwatch - Projeto 2 (Algoritmos e Programação II, turma 02P11)
 * Nicolas Soares Santos, RA 10370082
 */

#include "kwatch.h"
#include <stdio.h>

int main ()
{
  int ids[MAX]; int unidadeIds[MAX]; int meses[MAX]; int anos[MAX]; float consumos[MAX]; int unidadeIdsCatalogo[MAX]; char descricoes[MAX][50];

  int n = carregarLeituras("leituras.txt", ids, unidadeIds, meses, anos, consumos, MAX);

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
            case 1: bubbleSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, n);
              break;
            case 2: insertionSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, n);
              break;
            case 3: selectionSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, n);
              break;
            case 4: quickSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, 0, n - 1);
              break;
            case 5: mergeSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, 0, n - 1);
              break;
          }
          ordenado = 1;
        }
        printf("Leituras ordenadas por ID:\n");
        printf("ID | Unidade | Descricao | Mes | Ano | Consumo (kWh)\n");
        printf("-----------------------------------------------------------------------\n");
        for (int i = 0; i < n; i++) {
          int pos = buscaLinear(unidadeIdsCatalogo, nUnidade, unidadeIds[i]); 
          printf("%d | %d | %s | %d | %d | %.2f\n", ids[i], unidadeIds[i], descricoes[pos], meses[i], anos[i], consumos[i]);
        }
        break;             // sai do switch; sem ele, roda o case de baixo também
        
      case 2:
        printf("Digite o ID da leitura:");
        int idProcurado; int busca; int pos;
        scanf("%d", &idProcurado);

        printf("Escolha o algoritmo de busca:\n");
        printf("1. Busca linear\n");
        printf("2. Busca binaria\n");
        printf("Opcao:");
        scanf("%d", &busca);
        
        switch (busca) {
          case 1:
            pos = buscaLinear(ids, n, idProcurado);
            break;
          case 2:
            if (ordenado == 0) {
              quickSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, 0, n - 1);
              ordenado = 1;
            }
            pos = buscaBinaria(ids, n, idProcurado);
            break;
        }

        if (pos != -1) {
          int posDesc = buscaLinear(unidadeIdsCatalogo, nUnidade, unidadeIds[pos]);
          
          printf("Leitura encontrada:\n");
          printf("ID Leitura: %d\n", ids[pos]);
          printf("Unidade: %d\n", unidadeIds[pos]);
          printf("Descricao: %s\n", descricoes[posDesc]);
          printf("Mes: %d\n", meses[pos]);
          printf("Ano: %d\n", anos[pos]);
          printf("Consumo: %.2f kWh\n", consumos[pos]);
          
        } else {
          printf("Leiura nao encontrada.\n");
        }
        
        break;
        
      case 3:
        printf("Digite o ID da unidade:");
        int idUnidade; int posUni; float totalConsumo = 0.0;
        scanf("%d", &idUnidade);

        posUni = buscaLinear(unidadeIdsCatalogo, nUnidade, idUnidade);

        if (posUni == -1) {
          printf("Unidade nao encontrada.\n");
        } else {
          totalConsumo = calcularConsumoUnidade(unidadeIds, consumos, n, idUnidade);

          printf("Consumo da unidade:\n");
          printf("Unidade: %d\n", idUnidade);
          printf("Descricao: %s\n", descricoes[posUni]);
          printf("Consumo total: %.2f kWh\n", totalConsumo);
        }
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
