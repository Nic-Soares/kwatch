/*
 * kwatch - Projeto 2 (Algoritmos e Programação II, turma 02P11)
 * Nicolas Soares Santos, RA 10370082
 */

#include "kwatch.h"
#include <stdio.h>

int main() {
  // leituras (PDF p3): a leitura i está na posição i dos 5 arrays
  int ids[MAX];                // id de cada leitura
  int unidadeIds[MAX];         // unidade de cada leitura
  int meses[MAX];              // mês de cada leitura
  int anos[MAX];               // ano de cada leitura
  float consumos[MAX];         // consumo (kWh) de cada leitura
  // catálogo de unidades (PDF p3): a unidade j está na posição j dos 2 arrays
  int unidadeIdsCatalogo[MAX]; // número de cada unidade
  char descricoes[MAX][50];    // descrição de cada unidade (até 49 caracteres + '\0')

  int n = carregarLeituras("leituras.txt", ids, unidadeIds, meses, anos, consumos, MAX);

  if (n == -1) {
    printf("Erro ao abrir o arquivo leituras.txt.\nEncerrando o programa.\n");
    return 0;
  }

  int nUnidades = carregarUnidades("unidades.csv", unidadeIdsCatalogo, descricoes, MAX);

  if (nUnidades == -1) {
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

    if (scanf("%d", &opcao) != 1) {
      if (feof(stdin)) opcao = 6;
      else { scanf("%*s"); opcao = 0; }
    } // lê a opção; letra vira opção inválida (0) e fim da entrada vira sair (6)

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

          int algOrdenacao = 0;
          scanf("%d", &algOrdenacao);
          switch (algOrdenacao) {
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
          if (algOrdenacao < 1 || algOrdenacao > 5) {
            printf("Opcao invalida. Tente novamente.\n");
            break;
          }
          ordenado = 1;
        }
        printf("Leituras ordenadas por ID:\n");
        printf("ID | Unidade | Descricao | Mes | Ano | Consumo (kWh)\n");
        printf("-----------------------------------------------------------------------\n");
        for (int i = 0; i < n; i++) {
          int posCatalogo = buscaLinear(unidadeIdsCatalogo, nUnidades, unidadeIds[i]);
          if (posCatalogo == -1) {
            printf("%d | %d |  | %d | %d | %.2f\n", ids[i], unidadeIds[i], meses[i], anos[i], consumos[i]);
          } else {
            printf("%d | %d | %s | %d | %d | %.2f\n", ids[i], unidadeIds[i], descricoes[posCatalogo], meses[i], anos[i], consumos[i]);
          }

        }
        break;             // sai do switch; sem ele, roda o case de baixo também

      case 2:
        printf("Digite o ID da leitura:");
        int idProcurado = 0; int algBusca = 0; int pos = -1;
        scanf("%d", &idProcurado);

        printf("Escolha o algoritmo de busca:\n");
        printf("1. Busca linear\n");
        printf("2. Busca binaria\n");
        printf("Opcao:");
        scanf("%d", &algBusca);

        switch (algBusca) {
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
          int posCatalogo = buscaLinear(unidadeIdsCatalogo, nUnidades, unidadeIds[pos]);

          printf("Leitura encontrada:\n");
          printf("ID Leitura: %d\n", ids[pos]);
          printf("Unidade: %d\n", unidadeIds[pos]);
          if (posCatalogo == -1) {
            printf("Descricao: \n");
          } else {
            printf("Descricao: %s\n", descricoes[posCatalogo]);
          }
          printf("Mes: %d\n", meses[pos]);
          printf("Ano: %d\n", anos[pos]);
          printf("Consumo: %.2f kWh\n", consumos[pos]);

        } else {
          printf("Leiura nao encontrada.\n");
        }

        break;

      case 3:
        printf("Digite o ID da unidade:");
        int idUnidade = 0; int posCatalogo; float totalUnidade;
        scanf("%d", &idUnidade);

        posCatalogo = buscaLinear(unidadeIdsCatalogo, nUnidades, idUnidade);

        if (posCatalogo == -1) {
          printf("Unidade nao encontrada.\n");
        } else {
          totalUnidade = calcularConsumoUnidade(unidadeIds, consumos, n, idUnidade);

          printf("Consumo da unidade:\n");
          printf("Unidade: %d\n", idUnidade);
          printf("Descricao: %s\n", descricoes[posCatalogo]);
          printf("Consumo total: %.2f kWh\n", totalUnidade);
        }
        break;

      case 4:
        printf("Digite o mes inicial:");
        int mesInicial = 0; int mesFinal = 0; int anoInicial = 0; int anoFinal = 0; float totalPeriodo;
        scanf("%d", &mesInicial);
        printf("Digite o ano inicial:");
        scanf("%d", &anoInicial);
        printf("Digite o mes final:");
        scanf("%d", &mesFinal);
        printf("Digite o ano final:");
        scanf("%d", &anoFinal);

        if (mesInicial < 1 || mesInicial > 12 || mesFinal < 1 || mesFinal > 12 || anoInicial * 12 + mesInicial > anoFinal * 12 + mesFinal) {
          printf("Periodo invalido.\n");
        } else {
          totalPeriodo = calcularConsumoPeriodo(meses, anos, consumos, n, mesInicial, anoInicial, mesFinal, anoFinal);

          printf("Consumo no periodo:\n");
          printf("Periodo: %02d/%d ate %02d/%d\n", mesInicial, anoInicial, mesFinal, anoFinal);
          printf("Consumo total: %.2f kWh\n", totalPeriodo);
        }

        break;

      case 5:
        {
          int idMaior; float totalMaior; int posCatalogo;
          idMaior = encontrarUnidadeMaiorConsumo(unidadeIds, consumos,n);
          if (idMaior == -1) {
            printf("Nenhuma leitura carregada.\n");
            break;
          }
          totalMaior = calcularConsumoUnidade(unidadeIds, consumos, n, idMaior);
          posCatalogo = buscaLinear(unidadeIdsCatalogo, nUnidades, idMaior);

          printf("Unidade com maior consumo:\n");
          printf("Unidade: %d\n", idMaior);
          printf("Descricao: %s\n", descricoes[posCatalogo]);
          printf("Consumo total: %.2f kWh\n", totalMaior);
        }

        break;

      case 6:
        printf("Encerrando o programa.\n");
        break;
      default:             // qualquer número fora de 1 a 6 (ou letra, que virou 0)
        printf("Opcao invalida. Tente novamente.\n");
        break;
    }                      // fecha o switch
  } while (opcao != 6);

  return 0;
}
