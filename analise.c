/*
 * kwatch - Projeto 2 (Algoritmos e Programação II, turma 02P11)
 * Nicolas Soares Santos, RA 10370082
 */

#include "kwatch.h"
#include <stdio.h>

float calcularConsumoUnidade(int unidadeIds[], float consumos[], int n, int unidadeId) {
  float total = 0.0;
  for (int i = 0; i < n; i++) {
    if (unidadeIds[i] == unidadeId) {
      total += consumos[i];
    }
  }

  return total;
}