# Material de consulta

Tudo o que as tarefas T00a a T00c pedem para consultar, tirado do enunciado (o número da página do PDF vem em cada seção). As tarefas trazem links direto para a seção certa daqui.

- [Arquivos de entrada](#arquivos-de-entrada)
- [Dados do exemplo do PDF](#dados-do-exemplo-do-pdf)
- [Dados de borda](#dados-de-borda)
- [Menu e segundos menus](#menu-e-segundos-menus)
- [Saídas de cada opção](#saídas-de-cada-opção)
- [Regras](#regras)
- [Assinaturas das 12 funções](#assinaturas-das-12-funções)
- [Retornos especiais](#retornos-especiais)
- [Arquivos do projeto](#arquivos-do-projeto)
- [Termos](#termos)

## Arquivos de entrada

PDF p1 e p2.

| Arquivo | Uma linha por | Formato | Separador |
|---|---|---|---|
| `leituras.txt` | leitura (medição) | `id unidade_id mes ano consumo` | espaço |
| `unidades.csv` | unidade (setor) | `id;descricao` | `;` (a descrição pode ter espaços) |

O `unidade_id` de cada leitura é o `id` de uma unidade do `unidades.csv`. Toda unidade usada nas leituras está cadastrada (PDF p2).

## Dados do exemplo do PDF

PDF p2. Os mesmos arquivos estão em `tests/pdf/`.

`leituras.txt`:

```
1 101 1 2026 245.5
3 101 2 2026 310.2
2 203 1 2026 185.7
4 150 2 2026 420.0
5 203 2 2026 205.8
```

`unidades.csv`:

```
101;Laboratorio de Informatica
203;Biblioteca Central
150;Bloco Administrativo
```

Depois de carregados nos arrays, na ordem do arquivo (PDF p3):

| i | ids[i] | unidadeIds[i] | meses[i] | anos[i] | consumos[i] |
|---|---|---|---|---|---|
| 0 | 1 | 101 | 1 | 2026 | 245.5 |
| 1 | 3 | 101 | 2 | 2026 | 310.2 |
| 2 | 2 | 203 | 1 | 2026 | 185.7 |
| 3 | 4 | 150 | 2 | 2026 | 420.0 |
| 4 | 5 | 203 | 2 | 2026 | 205.8 |

| j | unidadeIdsCatalogo[j] | descricoes[j] |
|---|---|---|
| 0 | 101 | Laboratorio de Informatica |
| 1 | 203 | Biblioteca Central |
| 2 | 150 | Bloco Administrativo |

## Dados de borda

Arquivos em `tests/borda/` (não estão no PDF; servem para testar empate, consumo zero, unidade sem leituras e descrição de 49 letras).

| i | ids[i] | unidadeIds[i] | meses[i] | anos[i] | consumos[i] |
|---|---|---|---|---|---|
| 0 | 7 | 300 | 12 | 2025 | 100.0 |
| 1 | 2 | 301 | 1 | 2026 | 50.5 |
| 2 | 9 | 300 | 1 | 2026 | 25.0 |
| 3 | 1 | 301 | 12 | 2025 | 74.5 |
| 4 | 5 | 302 | 2 | 2026 | 0.0 |

| j | unidadeIdsCatalogo[j] | descricoes[j] |
|---|---|---|
| 0 | 301 | Sala de Aula 12 |
| 1 | 300 | Laboratorio de Redes |
| 2 | 302 | Auditorio |
| 3 | 303 | Unidade Sem Leituras Cadastrada Para Teste De Lim |

## Menu e segundos menus

Menu principal (PDF p12). Depois das opções 1 a 5, o menu aparece de novo.

```
===== SISTEMA DE ANALISE DE CONSUMO DE ENERGIA =====
1. Mostrar leituras ordenadas por ID
2. Buscar leitura por ID
3. Calcular consumo de uma unidade
4. Calcular consumo em um periodo
5. Identificar unidade com maior consumo
6. Sair da aplicacao
Escolha uma opcao:
```

Segundo menu da **opção 1** (PDF p12 e p13). Só aparece na primeira vez; nas outras, a lista sai direto.

```
Escolha o algoritmo de ordenacao:
1. Bubble Sort
2. Insertion Sort
3. Selection Sort
4. Quick Sort
5. Merge Sort
Opcao:
```

Segundo menu da **opção 2** (PDF p13), depois de pedir o ID:

```
Escolha o algoritmo de busca:
1. Busca linear
2. Busca binaria
Opcao:
```

Qual função cada opção usa:

| Opção | Função | PDF |
|---|---|---|
| início do programa (antes do menu) | `carregarLeituras`, `carregarUnidades` | p12 |
| 1 | a ordenação escolhida no segundo menu | p12, p13 |
| 2 | a busca escolhida no segundo menu; se for a binária e ainda não ordenou, ordena antes | p13 |
| 3 | `calcularConsumoUnidade` | p14 |
| 4 | `calcularConsumoPeriodo` | p15 |
| 5 | `encontrarUnidadeMaiorConsumo` | p15 |

## Saídas de cada opção

Texto exato do PDF (com os dados do exemplo). O consumo sai sempre com 2 casas: `310.20`.

Erro ao abrir arquivo (p12):

```
Erro ao abrir o arquivo leituras.txt.
Encerrando o programa.
```

Opção 1 (p13):

```
Leituras ordenadas por ID:
ID | Unidade | Descricao | Mes | Ano | Consumo (kWh)
-----------------------------------------------------------------------
1 | 101 | Laboratorio de Informatica | 1 | 2026 | 245.50
2 | 203 | Biblioteca Central | 1 | 2026 | 185.70
3 | 101 | Laboratorio de Informatica | 2 | 2026 | 310.20
4 | 150 | Bloco Administrativo | 2 | 2026 | 420.00
5 | 203 | Biblioteca Central | 2 | 2026 | 205.80
```

Opção 2 (p13, p14), achou e não achou (o "Leiura" é do PDF; dúvida D5):

```
Leitura encontrada:
ID Leitura: 3
Unidade: 101
Descricao: Laboratorio de Informatica
Mes: 2
Ano: 2026
Consumo: 310.20 kWh
```

```
Leiura nao encontrada.
```

Opção 3 (p14), achou e não achou:

```
Consumo da unidade:
Unidade: 101
Descricao: Laboratorio de Informatica
Consumo total: 555.70 kWh
```

```
Unidade nao encontrada.
```

Opção 4 (p15), válido e inválido:

```
Consumo no periodo:
Periodo: 01/2026 ate 02/2026
Consumo total: 1367.20 kWh
```

```
Periodo invalido.
```

Opção 5 (p15):

```
Unidade com maior consumo:
Unidade: 101
Descricao: Laboratorio de Informatica
Consumo total: 555.70 kWh
```

Opção 6 (p15):

```
Encerrando o programa.
```

## Regras

| Regra | PDF |
|---|---|
| Sem `struct`: os dados ficam em arrays paralelos | p3 |
| Toda ordenação move os 5 arrays juntos, para cada leitura continuar com os seus dados | p7, p13 |
| A busca binária exige `ids` em ordem crescente; na opção 2, se ainda não ordenou, ordena antes | p6, p13 |
| Período: soma todas as unidades, incluindo o mês inicial e o final | p10, p15 |
| Período inválido: algum mês fora de 1 a 12, ou o início depois do fim | p15 |
| Maior consumo: soma por unidade; empate, vence o menor ID | p11, p15 |
| Descrição com no máximo 49 letras (a 50ª posição é o `'\0'`) | p5 |

## Assinaturas das 12 funções

PDF p4 a p11. Têm que ser copiadas exatamente assim.

| Página | Assinatura |
|---|---|
| p4 | `int carregarLeituras(const char nomeArquivo[], int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int max);` |
| p5 | `int carregarUnidades(const char nomeArquivo[], int unidadeIds[], char descricoes[][50], int max);` |
| p6 | `int buscaLinear(int ids[], int n, int idProcurado);` |
| p6 | `int buscaBinaria(int ids[], int n, int idProcurado);` |
| p7 | `void bubbleSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int n);` |
| p7 | `void insertionSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int n);` |
| p8 | `void selectionSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int n);` |
| p8 | `void quickSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int inicio, int fim);` |
| p9 | `void mergeSortLeituraPorId(int ids[], int unidadeIds[], int meses[], int anos[], float consumos[], int inicio, int fim);` |
| p10 | `float calcularConsumoUnidade(int unidadeIds[], float consumos[], int n, int unidadeId);` |
| p10 | `float calcularConsumoPeriodo(int meses[], int anos[], float consumos[], int n, int mesInicial, int anoInicial, int mesFinal, int anoFinal);` |
| p11 | `int encontrarUnidadeMaiorConsumo(int unidadeIds[], float consumos[], int n);` |

Parâmetros, como o PDF descreve cada um:

| Parâmetro | O que é | PDF |
|---|---|---|
| `nomeArquivo[]` | nome do arquivo de entrada (o texto `"leituras.txt"` ou `"unidades.csv"`) | p4, p5 |
| `ids[]`, `unidadeIds[]`, `meses[]`, `anos[]`, `consumos[]` | os 5 arrays paralelos das leituras; nas cargas chegam vazios e a função os preenche | p4, p7 a p9 |
| `unidadeIds[]` (em `carregarUnidades`) | array de IDs das unidades do catálogo (no `main` é o `unidadeIdsCatalogo`) | p5 |
| `descricoes[][50]` | array com as descrições, até 49 caracteres cada | p5 |
| `max` | capacidade máxima dos arrays: a função não carrega mais linhas que isso | p4, p5 |
| `n` | quantidade de registros (leituras) que estão nos arrays | p6 a p11 |
| `idProcurado` | ID da leitura a ser buscado | p6 |
| `inicio`, `fim` | primeira e última posição do pedaço a ordenar | p8, p9 |
| `unidadeId` | ID da unidade consultada | p10 |
| `mesInicial`, `anoInicial`, `mesFinal`, `anoFinal` | início e fim do período | p10 |

Como ler uma assinatura:

| Parte | Exemplo em `int buscaLinear(int ids[], int n, int idProcurado);` | O que diz |
|---|---|---|
| antes do nome | `int` | o que a função devolve: `int` número inteiro, `float` número com casas decimais, `void` nada |
| nome | `buscaLinear` | como a função é chamada |
| entre parênteses | `int ids[], int n, int idProcurado` | o que ela recebe; `[]` é um array |

Uma função `void` não devolve valor, mas pode mudar os arrays que recebeu: é assim que as ordenações trabalham.

Quick e merge recebem `inicio` e `fim` em vez de `n` porque dividem o array em pedaços e chamam a si mesmas para cada pedaço; cada chamada precisa saber onde o seu pedaço começa e termina. Se `fim` é a última posição ou a quantidade é a dúvida D3; até a resposta, vale a última posição.

## Retornos especiais

| Função | O que o PDF diz no "Retorno" | PDF |
|---|---|---|
| `carregarLeituras` | número de registros carregados; -1 em caso de erro ao abrir o arquivo | p4 |
| `carregarUnidades` | número de registros carregados; -1 em caso de erro ao abrir o arquivo | p5 |
| `buscaLinear` | índice onde o ID foi encontrado; -1 caso não encontrado | p6 |
| `buscaBinaria` | índice onde o ID foi encontrado; -1 caso não encontrado | p6 |
| ordenações | não possui retorno | p7 a p9 |
| `calcularConsumoUnidade` | consumo total da unidade, em kWh | p10 |
| `calcularConsumoPeriodo` | consumo total registrado no período | p10 |
| `encontrarUnidadeMaiorConsumo` | ID da unidade com maior consumo; em empate, a de menor ID | p11 |

## Arquivos do projeto

| Arquivo | O que guarda |
|---|---|
| `carga.c` | as funções que leem os arquivos |
| `busca.c` | as buscas |
| `organizacao.c` | as ordenações |
| `analise.c` | os cálculos de consumo |
| `main.c` | o `main`: carga, menu e `printf` |
| `kwatch.h` | `#define MAX 1000` e as 12 assinaturas |

## Termos

| Termo | O que significa | Exemplo |
|---|---|---|
| leitura | uma medição: quanto uma unidade gastou num mês de um ano | `3 101 2 2026 310.2` |
| unidade | setor da instituição que gasta energia | 101, Laboratorio de Informatica |
| kWh | medida de energia (número com casas decimais) | 310.2 |
| posição (índice) | número da linha no array, começa em 0 | o ID 3 está na posição 1 |
| valor | o que está guardado numa posição | `ids[1]` vale 3 |
| arrays paralelos | arrays em que a mesma posição é a mesma leitura | `ids[1]`, `consumos[1]` são da leitura 3 |
| `'\0'` | caractere que marca o fim de um texto em C | "Bloco": 5 letras, 6 posições |
