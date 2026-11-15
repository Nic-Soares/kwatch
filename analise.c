/*
 * kwatch - Projeto 2 (Algoritmos e Programação II, turma 02P11)
 * Nicolas Soares Santos, RA 10370082
 */

#include "kwatch.h" // protótipos e constantes do projeto
#include <stdio.h> // biblioteca padrão de entrada e saída

// Soma o consumo de todas as leituras de uma unidade
float calcularConsumoUnidade(int unidadeIds[], float consumos[], int n, int unidadeId) {
  float total = 0.0; // acumulador do consumo da unidade, começa zerado
  for (int i = 0; i < n; i++) { // percorre as n leituras, da posição 0 a n - 1
    if (unidadeIds[i] == unidadeId) { // só entra se a leitura i for da unidade procurada
      total += consumos[i]; // soma o consumo da leitura i no acumulador
    } // fim do if
  } // fim do for

  return total; // devolve a soma depois de olhar todas as leituras
} // fim da função

// Soma o consumo das leituras dentro do período (mês/ano inicial até mês/ano final)
float calcularConsumoPeriodo(int meses[], int anos[], float consumos[], int n, int mesInicial, int anoInicial, int mesFinal, int anoFinal) {
  float total = 0.0; int date = 0; // total acumula o consumo; date guarda o número do mês/ano da leitura
  int periodoInicial = (anoInicial * 12) + mesInicial; // mês/ano inicial vira um número só
  int periodoFinal = (anoFinal * 12) + mesFinal; // mês/ano final vira um número só

  for (int i = 0; i < n; i++) { // percorre as n leituras
    date = (anos[i] * 12) + meses[i]; // mês/ano da leitura i vira um número só
    if (date >= periodoInicial && date <=periodoFinal) { // leitura dentro do período (inclusive nas pontas)
      total += consumos[i]; // soma o consumo da leitura i
    } // fim do if
  } // fim do for
  return total; // devolve o consumo total do período
} // fim da função

int encontrarUnidadeMaiorConsumo(int unidadeIds[], float consumos[], int n) {

  if (n <= 0) return -1; 

  int melhorId = unidadeIds[0];
  float melhorTotal = calcularConsumoUnidade(unidadeIds, consumos, n, melhorId);

  for (int i = 1; i < n; i++) {
    int idAtual = unidadeIds[i];
    float totalAtual = calcularConsumoUnidade(unidadeIds, consumos, n, idAtual);

    // Condição de troca: total maior OU (empate no total MAS com ID menor)
    if (totalAtual > melhorTotal || (totalAtual == melhorTotal && idAtual < melhorId)) {
      melhorTotal = totalAtual;
      melhorId = idAtual;
    }
  }

  return melhorId;
}
