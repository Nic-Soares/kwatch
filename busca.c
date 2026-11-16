/*
 * kwatch - Projeto 2 (Algoritmos e Programação II, turma 02P11)
 * Nicolas Soares Santos, RA 10370082
 */

#include "kwatch.h"
#include <stdio.h>

int buscaLinear(int ids[], int n, int idProcurado) {
  for (int i = 0; i < n; i++) { // inicia laço e indice em 0, que vai até n - 1
    if (ids[i] == idProcurado) return i; // se o valor na posição i é o procurado, devolve a posição i
  }
  return -1; // ao percorrer todo o array e não achar o valor procurado retorna -1
}

int buscaBinaria(int ids[], int n, int idProcurado) {
  int ini = 0;
  int fim = n - 1; // o fim deve começar no último índice válido do array (n - 1)

  while (ini <= fim) { // continua enquanto houver espaço de busca válido
    int meio = (ini + fim) / 2; // calcula o índice do elemento central

    if (ids[meio] == idProcurado) {
      return meio; // encontrou o valor exato no meio, retorna a posição
    }
    else if (ids[meio] < idProcurado) {
      ini = meio + 1; // se o valor procurado é maior, descarta a metade esquerda ajustando o início
    }
    else {
      fim = meio - 1; // se o valor procurado é menor, descarta a metade direita ajustando o fim
    }
  }
  return -1; // se o intervalo de busca se esgotar (ini > fim) e não achar, retorna -1
}
