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

  int n = carregarLeituras("leituras.txt", ids, unidadeIds, meses, anos, consumos, MAX); // carrega as leituras nos 5 arrays; n = quantas carregou, ou -1 se o arquivo não abriu

  if (n == -1) { // não abriu leituras.txt: mensagem do PDF (p12) e encerra
    printf("Erro ao abrir o arquivo leituras.txt.\nEncerrando o programa.\n");
    return 0; // return no main encerra o programa
  }

  int nUnidades = carregarUnidades("unidades.csv", unidadeIdsCatalogo, descricoes, MAX); // carrega o catálogo nos 2 arrays; nUnidades = quantas carregou, ou -1

  if (nUnidades == -1) { // não abriu unidades.csv: mesma mensagem, com o nome deste arquivo
    printf("Erro ao abrir o arquivo unidades.csv.\nEncerrando o programa.\n");
    return 0;
  }

  int opcao; int ordenado = 0; // opcao guarda a escolha do menu; ordenado: 0 = ainda não ordenou, 1 = já ordenou por ID

  do { // repete o menu até a pessoa escolher 6
    printf("\n"); // linha em branco: separa o menu do resultado da opção anterior
    printf("===== SISTEMA DE ANALISE DE CONSUMO DE ENERGIA =====\n");
    printf("1. Mostrar leituras ordenadas por ID\n");
    printf("2. Buscar leitura por ID\n");
    printf("3. Calcular consumo de uma unidade\n");
    printf("4. Calcular consumo em um periodo\n");
    printf("5. Identificar unidade com maior consumo\n");
    printf("6. Sair da aplicacao\n");
    printf("Escolha uma opcao:");

    if (scanf("%d", &opcao) != 1) { // o scanf devolve quantos números leu; != 1 quer dizer que não veio número
      if (feof(stdin)) opcao = 6; // acabou a entrada (fim do arquivo): trata como sair
      else { scanf("%*s"); opcao = 0; } // veio letra: %*s lê a palavra e joga fora; 0 cai no default
    } // lê a opção; letra vira opção inválida (0) e fim da entrada vira sair (6)

    switch (opcao) {       // escolhe o bloco pelo valor de opcao
      case 1: // opção 1: listar as leituras ordenadas por ID
        if (ordenado == 0) { // só na primeira vez: pergunta o algoritmo e ordena
          printf("Escolha o algoritmo de ordenacao:\n");
          printf("1. Bubble Sort\n");
          printf("2. Insertion Sort\n");
          printf("3. Selection Sort\n");
          printf("4. Quick Sort\n");
          printf("5. Merge Sort\n");
          printf("Opcao:");

          int algOrdenacao = 0; // começa em 0 (inválido) caso o scanf falhe
          scanf("%d", &algOrdenacao); // lê o número do algoritmo escolhido
          switch (algOrdenacao) { // chama a ordenação escolhida; todas trocam os 5 arrays juntos
            case 1: bubbleSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, n); // n = quantidade de leituras
              break;
            case 2: insertionSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, n);
              break;
            case 3: selectionSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, n);
              break;
            case 4: quickSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, 0, n - 1); // quick e merge recebem a primeira (0) e a última (n - 1) posição
              break;
            case 5: mergeSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, 0, n - 1);
              break;
          }
          if (algOrdenacao < 1 || algOrdenacao > 5) { // nenhum case rodou: algoritmo inválido
            printf("Opcao invalida. Tente novamente.\n");
            break; // sai da opção 1 sem listar e sem marcar ordenado
          }
          ordenado = 1; // daqui em diante a opção 1 lista direto, sem perguntar
        }
        printf("\n"); // linha em branco: separa as perguntas do resultado
        printf("Leituras ordenadas por ID:\n");
        printf("ID | Unidade | Descricao | Mes | Ano | Consumo (kWh)\n");
        printf("-----------------------------------------------------------------------\n");
        for (int i = 0; i < n; i++) { // uma linha da tabela por leitura, já em ordem de id
          int posCatalogo = buscaLinear(unidadeIdsCatalogo, nUnidades, unidadeIds[i]); // posição da unidade da leitura i no catálogo (ou -1)
          if (posCatalogo == -1) { // unidade fora do catálogo: imprime sem descrição para não ler descricoes[-1]
            printf("%d | %d |  | %d | %d | %.2f\n", ids[i], unidadeIds[i], meses[i], anos[i], consumos[i]);
          } else { // achou: a descrição está na mesma posição no catálogo
            printf("%d | %d | %s | %d | %d | %.2f\n", ids[i], unidadeIds[i], descricoes[posCatalogo], meses[i], anos[i], consumos[i]);
          }

        }
        break;             // sai do switch; sem ele, roda o case de baixo também

      case 2: // opção 2: buscar uma leitura pelo id
        printf("Digite o ID da leitura:");
        int idProcurado = 0; int algBusca = 0; int pos = -1; // valores iniciais inválidos: se o scanf falhar, cai em não encontrada
        scanf("%d", &idProcurado); // lê o id da leitura procurada

        printf("Escolha o algoritmo de busca:\n");
        printf("1. Busca linear\n");
        printf("2. Busca binaria\n");
        printf("Opcao:");
        scanf("%d", &algBusca); // lê 1 (linear) ou 2 (binária)
        printf("\n"); // linha em branco: separa as perguntas do resultado

        switch (algBusca) { // chama a busca escolhida; pos = posição da leitura nos 5 arrays, ou -1
          case 1:
            pos = buscaLinear(ids, n, idProcurado); // linear: funciona com os ids em qualquer ordem
            break;
          case 2:
            if (ordenado == 0) { // binária exige ids em ordem (PDF p13): se ainda não ordenou, ordena antes
              quickSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, 0, n - 1);
              ordenado = 1; // marca para não ordenar de novo
            }
            pos = buscaBinaria(ids, n, idProcurado); // agora a binária pode procurar
            break;
        }

        if (pos != -1) { // achou a leitura: imprime as 7 linhas do PDF (p13, p14)
          int posCatalogo = buscaLinear(unidadeIdsCatalogo, nUnidades, unidadeIds[pos]); // a descrição vem do catálogo: procura a unidade da leitura

          printf("Leitura encontrada:\n");
          printf("ID Leitura: %d\n", ids[pos]);
          printf("Unidade: %d\n", unidadeIds[pos]);
          if (posCatalogo == -1) { // unidade fora do catálogo: descrição vazia em vez de descricoes[-1]
            printf("Descricao: \n");
          } else {
            printf("Descricao: %s\n", descricoes[posCatalogo]);
          }
          printf("Mes: %d\n", meses[pos]);
          printf("Ano: %d\n", anos[pos]);
          printf("Consumo: %.2f kWh\n", consumos[pos]);

        } else { // não achou (pos == -1), ou o algoritmo era inválido
          printf("Leiura nao encontrada.\n"); // mensagem exatamente como no PDF (p14), com o erro de digitação (dúvida D5)
        }

        break;

      case 3: // opção 3: consumo total de uma unidade
        printf("Digite o ID da unidade:");
        int idUnidade = 0; int posCatalogo; float totalUnidade; // idUnidade começa em 0 (não existe unidade 0) caso o scanf falhe
        scanf("%d", &idUnidade); // lê o número da unidade
        printf("\n"); // linha em branco: separa as perguntas do resultado

        posCatalogo = buscaLinear(unidadeIdsCatalogo, nUnidades, idUnidade); // a unidade tem que estar no catálogo (unidades.csv)

        if (posCatalogo == -1) { // não está no catálogo: mensagem do PDF (p14)
          printf("Unidade nao encontrada.\n");
        } else {
          totalUnidade = calcularConsumoUnidade(unidadeIds, consumos, n, idUnidade); // soma o consumo de todas as leituras dessa unidade

          printf("Consumo da unidade:\n");
          printf("Unidade: %d\n", idUnidade);
          printf("Descricao: %s\n", descricoes[posCatalogo]);
          printf("Consumo total: %.2f kWh\n", totalUnidade);
        }
        break;

      case 4: // opção 4: consumo de todas as leituras num período
        printf("Digite o mes inicial:");
        int mesInicial = 0; int mesFinal = 0; int anoInicial = 0; int anoFinal = 0; float totalPeriodo; // começam em 0 (mês inválido) caso algum scanf falhe
        scanf("%d", &mesInicial);
        printf("Digite o ano inicial:");
        scanf("%d", &anoInicial);
        printf("Digite o mes final:");
        scanf("%d", &mesFinal);
        printf("Digite o ano final:");
        scanf("%d", &anoFinal);
        printf("\n"); // linha em branco: separa as perguntas do resultado

        if (mesInicial < 1 || mesInicial > 12 || mesFinal < 1 || mesFinal > 12 || anoInicial * 12 + mesInicial > anoFinal * 12 + mesFinal) { // inválido se algum mês sai de 1 a 12 ou se o início (ano * 12 + mês) vem depois do fim
          printf("Periodo invalido.\n");
        } else {
          totalPeriodo = calcularConsumoPeriodo(meses, anos, consumos, n, mesInicial, anoInicial, mesFinal, anoFinal); // soma o consumo das leituras do período, incluindo as pontas

          printf("Consumo no periodo:\n");
          printf("Periodo: %02d/%d ate %02d/%d\n", mesInicial, anoInicial, mesFinal, anoFinal); // %02d mostra o mês com 2 dígitos (01), como no PDF (p15)
          printf("Consumo total: %.2f kWh\n", totalPeriodo);
        }

        break;

      case 5: // opção 5: unidade com o maior consumo total
        { // chaves próprias: as variáveis deste case não colidem com as dos outros
          int idMaior; float totalMaior; int posCatalogo;
          printf("\n"); // linha em branco: separa as perguntas do resultado
          idMaior = encontrarUnidadeMaiorConsumo(unidadeIds, consumos,n); // número da unidade de maior total (empate: menor número), ou -1 sem leituras
          if (idMaior == -1) { // sem leituras: não há unidade para mostrar
            printf("Nenhuma leitura carregada.\n");
            break; // sai da opção 5 antes de usar o -1
          }
          totalMaior = calcularConsumoUnidade(unidadeIds, consumos, n, idMaior); // total dessa unidade
          posCatalogo = buscaLinear(unidadeIdsCatalogo, nUnidades, idMaior); // posição dela no catálogo, para a descrição

          printf("Unidade com maior consumo:\n");
          printf("Unidade: %d\n", idMaior);
          printf("Descricao: %s\n", descricoes[posCatalogo]);
          printf("Consumo total: %.2f kWh\n", totalMaior);
        }

        break;

      case 6: // opção 6: sair
        printf("Encerrando o programa.\n");
        break;
      default:             // qualquer número fora de 1 a 6 (ou letra, que virou 0)
        printf("Opcao invalida. Tente novamente.\n");
        break;
    }                      // fecha o switch
  } while (opcao != 6); // volta ao menu, a não ser que a escolha tenha sido 6

  return 0; // fim normal do programa
}
