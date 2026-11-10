/*
 * kwatch - Projeto 2 (Algoritmos e Programação II, turma 02P11)
 * Nicolas Soares Santos, RA 10370082
 */

/*
 * Guarda de inclusao: se KWATCH_H ainda nao foi definido, define agora
 * e le o resto do arquivo. Na segunda vez que o kwatch.h for incluido
 * no mesmo .c, KWATCH_H ja existe e tudo ate o #endif e pulado.
 * Evita definir MAX e os prototipos duas vezes.
 */
#ifndef KWATCH_H
#define KWATCH_H

/* Capacidade maxima dos arrays de leituras e de unidades (PDF p3). */
#define MAX 1000

int buscaLinear(int ids[], int n, int idProcurado);
int buscaBinaria(int ids[], int n, int idProcurado);
int carregarLeituras(const char nomeArquivo[], int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int max);
int carregarUnidades(const char nomeArquivo[], int unidadeIds[], char descricoes[][50], int max);
void bubbleSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int n);
void insertionSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int n);
void selectionSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int n);
void quickSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int inicio, int fim);
void mergeSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int inicio, int fim);
float calcularConsumoUnidade(int unidadeIds[], float consumos[], int n, int unidadeId);
float calcularConsumoPeriodo(int meses[], int anos[], float consumos[], int n, int mesInicial, int anoInicial, int mesFinal, int anoFinal);
int encontrarUnidadeMaiorConsumo(int unidadeIds[], float consumos[], int n);

/* Fim da guarda de inclusao aberta no #ifndef KWATCH_H. */
#endif
