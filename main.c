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
  
  return 0;
}