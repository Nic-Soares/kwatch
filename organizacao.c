/*
 * kwatch - Projeto 2 (Algoritmos e Programação II, turma 02P11)
 * Nicolas Soares Santos, RA 10370082
 */

#include "kwatch.h"

/* Troca as leituras das posições a e b nos 5 arrays (função auxiliar, não está no PDF). */
static void trocaLeitura(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int a, int b) {
  int t;    // guarda um valor inteiro enquanto as duas posições trocam
  float tc; // guarda o consumo; float para não perder as casas decimais

  t = ids[a]; ids[a] = ids[b]; ids[b] = t;                          // troca o id
  t = unidadeIds[a]; unidadeIds[a] = unidadeIds[b]; unidadeIds[b] = t; // troca a unidade
  t = meses[a]; meses[a] = meses[b]; meses[b] = t;                  // troca o mês
  t = anos[a]; anos[a] = anos[b]; anos[b] = t;                      // troca o ano
  tc = consumos[a]; consumos[a] = consumos[b]; consumos[b] = tc;    // troca o consumo
}

/* Bubble sort (PDF p7): compara vizinhos e troca quando estão fora de ordem; a cada passada o maior id
   que sobrou vai para o fim. Troca os 5 arrays juntos. */
void bubbleSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int n) {
  // Laço de fora: controla o número de passadas necessárias para ordenar o vetor
  for (int i = 0; i < n - 1; i++) {

    // Laço de dentro: percorre os elementos adjacentes na parte ainda não ordenada
    for (int j = 0; j < n - 1 - i; j++) {

      // Compara o elemento atual com o seu vizinho da frente
      if (ids[j] > ids[j + 1]) {

        // Se estiverem fora de ordem, troca as duas leituras inteiras (os 5 arrays)
        trocaLeitura(ids, unidadeIds, meses, anos, consumos, j, j + 1);
      }
    }
  }
}

/* Insertion sort (PDF p7): pega a leitura i e a insere na posição certa entre as já ordenadas à esquerda,
   deslocando as maiores uma casa para a direita. Move os 5 arrays juntos. */
void insertionSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int n) {
  // A posição 0 sozinha já está em ordem: começa inserindo a leitura da posição 1
  for (int i = 1; i < n; i++) {

    // Guarda as 5 colunas da leitura i, porque o primeiro deslocamento escreve por cima dela
    int chaveId = ids[i];
    int chaveU = unidadeIds[i];
    int chaveM = meses[i];
    int chaveA = anos[i];
    float chaveC = consumos[i];

    // j começa no vizinho da esquerda da chave
    int j = i - 1;

    // Enquanto existe posição à esquerda e o id dela é maior que o da chave, anda essa leitura uma casa para a direita
    while (j >= 0 && ids[j] > chaveId) {
      ids[j + 1] = ids[j];
      unidadeIds[j + 1] = unidadeIds[j];
      meses[j + 1] = meses[j];
      anos[j + 1] = anos[j];
      consumos[j + 1] = consumos[j];
      j--; // vai para a posição de antes
    }

    // Coloca a leitura guardada no buraco que sobrou (j + 1)
    ids[j + 1] = chaveId;
    unidadeIds[j + 1] = chaveU;
    meses[j + 1] = chaveM;
    anos[j + 1] = chaveA;
    consumos[j + 1] = chaveC;
  }
}

/* Selection sort (PDF p8): para cada posição i, procura o menor id do resto e troca com a posição i.
   Troca os 5 arrays juntos. */
void selectionSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int n) {
  // Cada passada põe na posição i o menor id que sobrou; a última posição fica certa sozinha
  for (int i = 0; i < n - 1; i++) {

    // pm guarda a POSIÇÃO do menor id visto até agora; o primeiro candidato é a própria posição i
    int pm = i;

    // Procura, da posição i + 1 até o fim, um id menor que o da posição pm
    for (int j = i + 1; j < n; j++) {
      if (ids[j] < ids[pm]) {
        pm = j; // achou um menor: guarda a posição dele
      }
    }

    // Depois de olhar todas, troca a leitura i com a do menor (só se o menor não já estiver em i)
    if (pm != i) {
      trocaLeitura(ids, unidadeIds, meses, anos, consumos, i, pm);
    }
  }
}

/* Partição do quick sort (função auxiliar, não está no PDF): pivô = id da posição fim.
   Junta à esquerda as leituras com id menor ou igual ao pivô e devolve a posição final do pivô. */
static int particionaLeituras(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int inicio, int fim) {
  int pivo = ids[fim]; // o pivô é o id da última posição do pedaço
  int i = inicio - 1;  // última posição do grupo "menor ou igual ao pivô" (começa vazio)

  // Compara cada posição de inicio até fim - 1 com o pivô
  for (int j = inicio; j < fim; j++) {
    if (ids[j] <= pivo) {
      i++; // o grupo dos menores ou iguais cresce uma posição
      trocaLeitura(ids, unidadeIds, meses, anos, consumos, i, j); // traz a leitura j para dentro do grupo
    }
  }

  // Põe o pivô logo depois do grupo dos menores ou iguais: é o lugar definitivo dele
  trocaLeitura(ids, unidadeIds, meses, anos, consumos, i + 1, fim);
  return i + 1;
}

/* Quick sort (PDF p8): separa o pedaço inicio..fim em torno de um pivô e ordena cada lado chamando a
   própria função. Chamada inicial: (..., 0, n - 1). */
void quickSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int inicio, int fim) {
  // Caso base: pedaço com 0 ou 1 posição já está em ordem, não faz nada
  if (inicio < fim) {

    // Separa o pedaço em torno do pivô; p é a posição final do pivô
    int p = particionaLeituras(ids, unidadeIds, meses, anos, consumos, inicio, fim);

    // Ordena o que ficou antes e o que ficou depois do pivô (p já está no lugar certo)
    quickSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, inicio, p - 1);
    quickSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, p + 1, fim);
  }
}

/* Intercala as metades já ordenadas inicio..meio e meio+1..fim, levando os 5 arrays juntos
   (função auxiliar, não está no PDF). */
static void intercalaLeituras(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int inicio, int meio, int fim) {
  // Arrays auxiliares, um por coluna; static para não ocupar a pilha a cada chamada
  static int auxIds[MAX], auxU[MAX], auxM[MAX], auxA[MAX];
  static float auxC[MAX];

  int i = inicio;   // frente da metade da esquerda
  int j = meio + 1; // frente da metade da direita
  int k = 0;        // próxima posição livre nos auxiliares

  // Enquanto as duas metades têm leituras, copia a de menor id da frente
  while (i <= meio && j <= fim) {
    if (ids[i] <= ids[j]) {
      auxIds[k] = ids[i]; auxU[k] = unidadeIds[i]; auxM[k] = meses[i]; auxA[k] = anos[i]; auxC[k] = consumos[i];
      i++; // a da esquerda foi usada
    } else {
      auxIds[k] = ids[j]; auxU[k] = unidadeIds[j]; auxM[k] = meses[j]; auxA[k] = anos[j]; auxC[k] = consumos[j];
      j++; // a da direita foi usada
    }
    k++;
  }

  // Sobra da esquerda (a direita acabou)
  while (i <= meio) {
    auxIds[k] = ids[i]; auxU[k] = unidadeIds[i]; auxM[k] = meses[i]; auxA[k] = anos[i]; auxC[k] = consumos[i];
    i++;
    k++;
  }

  // Sobra da direita (a esquerda acabou)
  while (j <= fim) {
    auxIds[k] = ids[j]; auxU[k] = unidadeIds[j]; auxM[k] = meses[j]; auxA[k] = anos[j]; auxC[k] = consumos[j];
    j++;
    k++;
  }

  // Copia o pedaço intercalado de volta: aux[t] vai para a posição inicio + t
  for (int t = 0; t < k; t++) {
    ids[inicio + t] = auxIds[t];
    unidadeIds[inicio + t] = auxU[t];
    meses[inicio + t] = auxM[t];
    anos[inicio + t] = auxA[t];
    consumos[inicio + t] = auxC[t];
  }
}

/* Merge sort (PDF p9): divide o pedaço inicio..fim ao meio, ordena cada metade chamando a própria função
   e intercala as duas. Chamada inicial: (..., 0, n - 1). */
void mergeSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int inicio, int fim) {
  // Caso base: pedaço com 0 ou 1 posição já está em ordem, não faz nada
  if (inicio < fim) {

    // meio é a última posição da metade da esquerda
    int meio = (inicio + fim) / 2;

    // Ordena cada metade chamando a própria função
    mergeSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, inicio, meio);
    mergeSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, meio + 1, fim);

    // Junta as duas metades ordenadas em uma só
    intercalaLeituras(ids, unidadeIds, meses, anos, consumos, inicio, meio, fim);
  }
}
