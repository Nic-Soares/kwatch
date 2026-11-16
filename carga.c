/*
 * kwatch - Projeto 2 (Algoritmos e Programação II, turma 02P11)
 * Nicolas Soares Santos, RA 10370082
 */

#include "kwatch.h"
#include <stdio.h>

int carregarLeituras(const char nomeArquivo[], int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int max) {

  FILE *arq; int n = 0; // arq guarda o arquivo aberto; n começa em 0 e conta as linhas gravadas
  arq = fopen(nomeArquivo, "r"); if (arq == NULL) return -1; // abre o arquivo para leitura; se não abriu (NULL), devolve -1 sem ler nada

  while (n < max && fscanf(arq, "%d %d %d %d %f", &ids[n], &unidadeIds[n], &meses[n], &anos[n], &consumos[n]) == 5) n++; // enquanto n < max e o fscanf ler as 5 colunas na posição n (id, unidade, mês, ano, consumo), o n++ avança para a próxima posição livre

  fclose(arq); // encerra a ligação com o arquivo aberto no fopen; não leio mais nada dele
  return n;    // devolve quantas linhas foram gravadas (posições 0 a n-1)
}

int carregarUnidades(const char nomeArquivo[], int unidadeIds[], char descricoes[][50], int max) {

  FILE *arq; int n = 0; // arq guarda o arquivo aberto; n começa em 0 e conta as linhas gravadas
  arq = fopen(nomeArquivo, "r"); if (arq == NULL) return -1; // abre o arquivo para leitura; se não abriu (NULL), devolve -1 sem ler nada

  while (n < max && fscanf(arq, "%d;%49[^\r\n]%*[^\n]", &unidadeIds[n], descricoes[n]) == 2) n++; // enquanto houver espaço (n < max) e o fscanf ler as 2 peças, avança para a próxima posição; o %*[^\n] descarta o que passar de 49 caracteres

  fclose(arq); // encerra a ligação com o arquivo aberto no fopen; não leio mais nada dele
  return n;    // devolve quantas linhas foram gravadas (posições 0 a n-1)
}
