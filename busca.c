/*
 * kwatch - Projeto 2 (Algoritmos e Programação II, turma 02P11)
 * Nicolas Soares Santos, RA 10370082
 */

#include "kwatch.h"
#include <stdio.h>

int buscaLinear(int ids[], int n, int idProcurado) {
  for (int i = 0; i < n; i++) { // inicia laço e indice em 0, que vai até n - 1
    if (ids[i] == idProcurado) return i; // se  o idProcurado for igual ao que o indece tras dentro do array, encontrou  e retorna a posição
  }
  return -1; // ao percorrer todo o array e não achar o valor procurado retorna -1
}