# Conceitos do projeto

O porquê de cada coisa aprendida no kwatch, na ordem em que apareceu. Cada conceito tem: **em uma linha**, **por que existe**, **exemplo** com os dados do projeto e **cuidado** (o erro comum). Os dados dos exemplos são os do PDF p2 (ver [material de consulta](contexto/referencia.md#dados-do-exemplo-do-pdf)).

| # | Conceito | Tarefa |
|---|---|---|
| 1 | [Leitura, unidade e a ligação pelo ID](#1-leitura-unidade-e-a-ligação-pelo-id) | T00a |
| 2 | [Separadores dos arquivos](#2-separadores-dos-arquivos) | T00a |
| 3 | [Arrays paralelos](#3-arrays-paralelos) | T00a |
| 4 | [Posição × valor](#4-posição--valor) | T00a |
| 5 | [Texto em C e o `'\0'`](#5-texto-em-c-e-o-0) | T00a |
| 6 | [Saída idêntica ao PDF](#6-saída-idêntica-ao-pdf) | T00b |
| 7 | [Período: válido e o que soma](#7-período-válido-e-o-que-soma) | T00b |
| 8 | [Maior consumo e desempate](#8-maior-consumo-e-desempate) | T00b |
| 9 | [Ordenar move os 5 arrays juntos](#9-ordenar-move-os-5-arrays-juntos) | T00b |
| 10 | [Busca binária precisa de ordem](#10-busca-binária-precisa-de-ordem) | T00b |
| 11 | [Assinatura de uma função](#11-assinatura-de-uma-função) | T00c |
| 12 | [Preencher arrays × devolver um valor](#12-preencher-arrays--devolver-um-valor) | T00c |
| 13 | [O -1 como aviso](#13-o--1-como-aviso) | T00c |
| 14 | [`inicio` e `fim`](#14-inicio-e-fim) | T00c |
| 15 | [Os 5 algoritmos de ordenação em uma frase](#15-os-5-algoritmos-de-ordenação-em-uma-frase) | T00c |
| 16 | [Cabeçalho com nome e RA](#16-cabeçalho-com-nome-e-ra) | T01 |
| 17 | [Arquivo `.h` e guarda de inclusão](#17-arquivo-h-e-guarda-de-inclusão) | T01 |
| 18 | [Protótipo × definição](#18-protótipo--definição) | T01 |
| 19 | [Fluxo de trabalho no git](#19-fluxo-de-trabalho-no-git) | todas |
| 20 | [`char descricoes[][50]`: lista de textos](#20-char-descricoes50-lista-de-textos) | T01 |
| 21 | [Parênteses vazios no protótipo](#21-parênteses-vazios-no-protótipo) | T01 |
| 22 | [Compilar × ligar e o `main`](#22-compilar--ligar-e-o-main) | T01 |
| 23 | [Ler um arquivo: `fopen`, `fscanf`, `fclose`](#23-ler-um-arquivo-fopen-fscanf-fclose) | T02 |
| 24 | [Carregar arquivo em arrays paralelos](#24-carregar-arquivo-em-arrays-paralelos) | T02 |
| 25 | [Ler `id;descricao`: o `;` e o `%49[^\n]`](#25-ler-iddescricao-o--e-o-49n) | T03 |
| 26 | [Busca linear: achei e o -1 depois do laço](#26-busca-linear-achei-e-o--1-depois-do-laço) | T04 |
| 27 | [Busca binária: `inicio`, `fim` e `meio`](#27-busca-binária-inicio-fim-e-meio) | T05 |
| 28 | [Bubble sort por ID trocando os 5 arrays](#28-bubble-sort-por-id-trocando-os-5-arrays) | T06 |
| 29 | [Insertion sort por ID guardando a leitura inteira](#29-insertion-sort-por-id-guardando-a-leitura-inteira) | T07 |
| 30 | [Selection sort por ID: `pm` guarda a posição](#30-selection-sort-por-id-pm-guarda-a-posição) | T08 |
| 31 | [Quick sort por ID: partição com pivô no fim](#31-quick-sort-por-id-partição-com-pivô-no-fim) | T09 |
| 32 | [Merge sort por ID: intercalar os 5 arrays](#32-merge-sort-por-id-intercalar-os-5-arrays) | T10 |
| 33 | [Função auxiliar `static`: `trocaLeitura`](#33-função-auxiliar-static-trocaleitura) | T06 a T10 |
| 34 | [Acumulador com filtro: somar só o que interessa](#34-acumulador-com-filtro-somar-só-o-que-interessa) | T11 |
| 35 | [Mês e ano como um número só](#35-mês-e-ano-como-um-número-só) | T12 |
| 36 | [Maior total reaproveitando `calcularConsumoUnidade`](#36-maior-total-reaproveitando-calcularconsumounidade) | T13 |
| 37 | [O `main` declara os arrays e carrega](#37-o-main-declara-os-arrays-e-carrega) | T14 |
| 38 | [Menu com `do`/`while` e `switch`](#38-menu-com-do-while-e-switch) | T15 |
| 39 | [Opção 1: submenu uma vez e a descrição pelo catálogo](#39-opção-1-submenu-uma-vez-e-a-descrição-pelo-catálogo) | T16 |
| 40 | [Opção 2: busca e o `ordenado` antes da binária](#40-opção-2-busca-e-o-ordenado-antes-da-binária) | T17 |
| 41 | [Opção 4: validar o período e o `%02d`](#41-opção-4-validar-o-período-e-o-02d) | T19 |

---

## 1. Leitura, unidade e a ligação pelo ID

**Em uma linha:** a leitura guarda só o número da unidade; o nome dela é procurado no cadastro de unidades.

**Por que existe:** a mesma unidade tem uma leitura por mês. Se cada leitura guardasse o nome, ele se repetiria em todas; guardando só o número, o nome fica escrito uma vez, no `unidades.csv`. O número que liga os dois arquivos se chama `unidade_id` nas leituras e `id` nas unidades (é a "chave").

**Exemplo:** a leitura `5 203 2 2026 205.8` é da unidade 203; no `unidades.csv`, `203;Biblioteca Central`. Então a leitura 5 é da Biblioteca Central.

**Cuidado:** a descrição nunca vem da leitura; sempre é preciso procurar o número no cadastro.

## 2. Separadores dos arquivos

**Em uma linha:** `leituras.txt` separa por espaço; `unidades.csv` separa por `;`.

**Por que existe:** o nome da unidade tem espaços ("Biblioteca Central"). Se o separador fosse espaço, não daria para saber onde o nome termina. Nas leituras só há números, que nunca têm espaço.

**Exemplo:** `203;Biblioteca Central` tem 2 campos; `5 203 2 2026 205.8` tem 5.

**Cuidado:** na T03, a leitura do `unidades.csv` precisa cortar no `;`, não no espaço.

## 3. Arrays paralelos

**Em uma linha:** cada coluna do arquivo vira um array, e a mesma posição em todos eles é a mesma leitura.

**Por que existe:** o PDF proíbe `struct` (p3). Sem `struct`, o jeito de manter os 5 dados de uma leitura juntos é guardá-los na mesma posição de 5 arrays.

**Exemplo:**

| i | ids[i] | unidadeIds[i] | meses[i] | anos[i] | consumos[i] |
|---|---|---|---|---|---|
| 1 | 3 | 101 | 2 | 2026 | 310.2 |

Tudo na linha `i = 1` é da leitura 3.

**Cuidado:** qualquer operação que mude a ordem de um array tem que mudar os outros 4 do mesmo jeito (conceito 9).

## 4. Posição × valor

**Em uma linha:** a posição é o número da linha no array (começa em 0); o valor é o que está guardado nela.

**Por que existe:** o arquivo não tem número de linha; no programa, todo dado é acessado pela posição (`consumos[1]`). As buscas devolvem posição, não ID.

**Exemplo:**

| Posição `i` | 0 | 1 | 2 |
|---|---|---|---|
| Valor `ids[i]` | 1 | 3 | 2 |

O ID 3 está na posição 1. `ids[3]` não é a leitura 3.

**Cuidado:** ao comparar, compare **valores** (`ids[i] > ids[i + 1]`), não posições (`i > i + 1` nunca é verdade).

## 5. Texto em C e o `'\0'`

**Em uma linha:** um texto em C é um array de `char` que termina com um caractere a mais, o `'\0'`, que marca o fim.

**Por que existe:** o array não guarda quantas letras foram usadas; quem lê o texto (o `printf` com `%s`, por exemplo) anda até achar o `'\0'`.

**Exemplo:** "Bloco" tem 5 letras e ocupa 6 posições (0 a 4 para as letras, 5 para o `'\0'`). Por isso `descricoes[MAX][50]`: até 49 letras (posições 0 a 48) mais o `'\0'` na posição 49 (PDF p5).

**Cuidado:** na T03, um nome com mais de 49 letras tem que ser cortado em 49; escrever a 50ª letra apaga o `'\0'`.

## 6. Saída idêntica ao PDF

**Em uma linha:** cada mensagem que o programa mostra tem que ser igual, letra por letra, à do PDF.

**Por que existe:** o professor confere a saída com o PDF; diferença conta como erro (PDF p17).

**Exemplo:** consumo sempre com 2 casas: `310.20`, `420.00`, `936.00`. Mensagens com o ponto final: `Unidade nao encontrada.`. O PDF tem `Leiura nao encontrada.` (sem o "t"); até o professor responder (D5), vale como está.

**Cuidado:** não inventar mensagem; quando não souber, procurar em [Saídas de cada opção](contexto/referencia.md#saídas-de-cada-opção).

## 7. Período: válido e o que soma

**Em uma linha:** a opção 4 soma o consumo de **todas** as unidades cujas leituras estão entre o mês/ano inicial e o final, inclusive.

**Por que existe:** a função `calcularConsumoPeriodo` não recebe unidade (p10); o exemplo do PDF (p15) dá 1367.20, a soma das 5 leituras de 3 unidades.

**Exemplo:** 02/2026 até 02/2026: posições 1, 3 e 4; 310.2 + 420.0 + 205.8 = 936.0.

**Cuidado:** é inválido (`Periodo invalido.`) se algum mês estiver fora de 1 a 12 **ou** se o início vier depois do fim (03/2026 até 01/2026).

## 8. Maior consumo e desempate

**Em uma linha:** soma o consumo de cada unidade; vence a de maior total; se empatar, vence o **menor ID**.

**Por que existe:** a regra do empate está no PDF (p11, p15); sem ela, duas respostas seriam possíveis.

**Exemplo** (dados de `tests/borda`): 300 = 100.0 + 25.0 = 125.0; 301 = 50.5 + 74.5 = 125.0. Empate no consumo; o desempate olha o **ID**: 300 é menor que 301, vence a 300.

**Cuidado:** o desempate não olha o consumo de novo (ele está empatado); olha o número da unidade.

## 9. Ordenar move os 5 arrays juntos

**Em uma linha:** quando duas leituras trocam de posição, as 5 colunas trocam juntas.

**Por que existe:** os arrays são paralelos (conceito 3); se só o `ids` mudar, cada ID fica com os dados de outra leitura (PDF p7, p13).

**Exemplo:** ordenando só o `ids`, o ID 2 vai para a posição 1, mas `consumos[1]` continua 310.2 (da leitura 3). O programa mostraria o consumo errado para a leitura 2 (o certo é 185.7).

**Cuidado:** em toda ordenação, cada troca é feita 5 vezes, uma por array.

## 10. Busca binária precisa de ordem

**Em uma linha:** a binária olha o meio e descarta a metade onde o valor não pode estar; isso só funciona com o array em ordem crescente.

**Por que existe:** o descarte supõe que tudo à esquerda do meio é menor. No arquivo (1, 3, 2, 4, 5) isso não vale; por isso, na opção 2, o programa ordena antes da binária (PDF p6, p13).

**Exemplo:** procurando o 3 em 1, 3, 2, 4, 5: volta 1, meio 2, `ids[2]` = 2, menor que 3, `inicio` = 3; volta 2, meio 3, `ids[3]` = 4, maior que 3, `fim` = 2; `inicio` (3) passou de `fim` (2): para sem achar, embora o 3 esteja na posição 1.

**Cuidado:** a busca para quando `inicio` passa de `fim`; não achar não quer dizer que o valor não está lá se o array não estava ordenado.

## 11. Assinatura de uma função

**Em uma linha:** a primeira linha da função: o que ela devolve, o nome e o que recebe.

**Por que existe:** é o "contrato" da função: quem chama sabe o que mandar e o que vai receber. O PDF exige as 12 assinaturas idênticas (p4 a p11).

**Exemplo:** `int buscaLinear(int ids[], int n, int idProcurado)`

| Parte | Aqui | Significa |
|---|---|---|
| antes do nome | `int` | devolve um inteiro (`float` = número com casas; `void` = nada) |
| nome | `buscaLinear` | como é chamada |
| entre parênteses | `int ids[], int n, int idProcurado` | recebe um array de inteiros e dois inteiros; `[]` = array |

**Cuidado:** cada parâmetro tem tipo e nome; os nomes do PDF não podem ser trocados.

## 12. Preencher arrays × devolver um valor

**Em uma linha:** uma função pode mudar os arrays que recebeu **e**, separado disso, devolver um valor.

**Por que existe:** em C, um array passado para a função é o mesmo array de quem chamou; o que a função muda nele fica mudado. O valor devolvido (o `return`) é outra coisa.

**Exemplo:** `carregarLeituras` enche os 5 arrays **e** devolve um `int`: quantas leituras carregou (vira o `n` das outras funções). As ordenações reordenam os 5 arrays e não devolvem nada (`void`).

**Cuidado:** na coluna "o que devolve", olhar só o que vem antes do nome.

## 13. O -1 como aviso

**Em uma linha:** -1 é a resposta de "deu errado" ou "não achei".

**Por que existe:** as posições começam em 0, então 0 é uma resposta válida ("achei na posição 0"). -1 nunca é posição nem quantidade, então não se confunde com nenhum resultado bom.

**Exemplo:** `buscaLinear` do ID 1 devolve 0 (achou na posição 0); do ID 99 devolve -1. `carregarLeituras` devolve -1 se o arquivo não abrir, e o `main` mostra o erro e encerra (p12).

**Cuidado:** quem chama tem que testar o -1 antes de usar o resultado como posição.

## 14. `inicio` e `fim`

**Em uma linha:** quick e merge recebem a primeira e a última posição do pedaço a ordenar, não o tamanho.

**Por que existe:** os dois dividem o array em pedaços e chamam a si mesmos para cada pedaço; cada chamada precisa saber onde o seu pedaço começa e termina.

**Exemplo:** na primeira chamada, o pedaço é o array todo: com 5 leituras, `inicio` = 0 e `fim` = 4; com `n` leituras, `inicio` = 0 e `fim` = n − 1.

**Cuidado:** `fim` como última posição é provisório até o professor responder a D3.

## 15. Os 5 algoritmos de ordenação em uma frase

| Algoritmo | O que faz | Como não confundir |
|---|---|---|
| bubble | compara vizinhos e troca quando o da esquerda é maior | olha sempre 2 vizinhos |
| selection | procura o **menor** do resto e o coloca na frente (`pm` = posição do menor) | guarda a posição do menor |
| insertion | pega o próximo e o **encaixa** entre os da esquerda, deslocando os maiores para a direita | não procura o menor; encaixa |
| quick | escolhe um pivô, põe menores de um lado e maiores do outro, repete em cada lado | divide pelo pivô |
| merge | divide ao meio até sobrar 1, depois junta os pedaços em ordem | divide ao meio e junta |

**Cuidado:** os 5 movem os 5 arrays juntos (conceito 9).

## 16. Cabeçalho com nome e RA

**Em uma linha:** todo arquivo do projeto começa com um comentário com nome e RA.

**Por que existe:** o PDF pede (p16). Comentário (`/* ... */`) é ignorado pelo compilador.

**Exemplo:**

```c
/*
 * kwatch - Projeto 2 (Algoritmos e Programação II, turma 02P11)
 * Nicolas Soares Santos, RA 10370082
 */
```

**Cuidado:** vale para os 5 `.c` e o `.h`.

## 17. Arquivo `.h` e guarda de inclusão

**Em uma linha:** o `.h` guarda o que vários `.c` precisam conhecer (`MAX` e os protótipos); a guarda faz ele ser lido uma vez só por arquivo.

**Por que existe:** o compilador lê um `.c` por vez; cada `.c` faz `#include "kwatch.h"` para conhecer as funções dos outros. Se o `.h` fosse lido duas vezes no mesmo `.c`, o `MAX` seria definido duas vezes. Além disso, o comando oficial `gcc -o main.exe *.c *.h` falha no Windows se não houver nenhum `.h` (D2).

**Exemplo:**

| Linha | Faz |
|---|---|
| `#ifndef KWATCH_H` | se KWATCH_H ainda não existe... |
| `#define KWATCH_H` | ...cria agora (na 2ª leitura, já existe e tudo é pulado) |
| `#endif` | fim do trecho protegido (última linha do arquivo) |

**Cuidado:** tudo do `.h` fica entre o `#define KWATCH_H` e o `#endif`. Linhas que começam com `#` (`#include`, `#define`, `#ifndef`, `#endif`) são ordens ao pré-processador, não comandos de C: **não terminam com `;`**. Arquivo seu vai entre aspas (`"kwatch.h"`, procurado na pasta do projeto); arquivo da biblioteca vai entre `< >` (`<stdio.h>`, procurado nas pastas do sistema).

## 18. Protótipo × definição

**Em uma linha:** o protótipo é a assinatura terminada em `;`; a definição é a assinatura com o corpo `{ ... }`.

**Por que existe:** o `main.c` chama funções escritas em outros `.c`. O protótipo no `.h` avisa o compilador "esta função existe e é assim"; a definição, no `.c` dela, é onde o trabalho é feito.

**Exemplo:**

| | Onde fica | Como é |
|---|---|---|
| protótipo | `kwatch.h` | `int buscaLinear(int ids[], int n, int idProcurado);` |
| definição | `busca.c` | `int buscaLinear(int ids[], int n, int idProcurado) { ... }` |

**Cuidado:** o protótipo e a definição têm que ser iguais (tipo, nome, parâmetros); a diferença é só `;` × `{ ... }`.

## 19. Fluxo de trabalho no git

**Em uma linha:** cada tarefa tem a sua branch, vira um PR para `develop`, passa no CI e entra por squash.

**Por que existe:** o `develop` só recebe código que compila com o comando oficial (o CI roda no Windows); o PR guarda o que mudou e por quê (`CONTRIBUTING.md`).

**Exemplo:**

| Passo | Comando |
|---|---|
| partir do `develop` atualizado | `git checkout develop && git pull` |
| branch da tarefa | `git checkout -b feat/T01-esqueleto` |
| gravar | `git add <arquivos>` e `git commit -m "feat: ..."` |
| enviar e abrir o PR | `git push -u origin <branch>` e `gh pr create --base develop` |
| juntar | `gh pr merge <número> --squash --delete-branch` |

**Cuidado:** `git add` pelo nome do arquivo (não `git add .`), para não levar o que não é da tarefa; marcar `[x]` no roadmap no mesmo PR.

## 20. `char descricoes[][50]`: lista de textos

**Em uma linha:** uma matriz de `char`: cada linha é o nome de uma unidade, cada coluna é uma letra.

**Por que existe:** um nome é um array de `char` (conceito 5). Vários nomes são vários arrays de `char` empilhados: uma matriz. No `main` ela é `char descricoes[MAX][50]` (MAX linhas, 50 colunas).

**Exemplo:**

| j | 0 | 1 | 2 | ... | 18 | ... | 49 |
|---|---|---|---|---|---|---|---|
| 0 | `L` | `a` | `b` | ... | ... | ... | |
| 1 | `B` | `i` | `b` | ... | `'\0'` | ... | |

`descricoes[1]` é o nome inteiro da linha 1 ("Biblioteca Central"); `descricoes[1][0]` é a letra `B`.

**Por que o primeiro `[]` fica vazio e o segundo tem 50, no parâmetro:** a função não precisa saber quantas linhas há (ela recebe `max` para isso), mas precisa saber o tamanho de cada linha: na memória as linhas ficam uma depois da outra, e para chegar à linha `j` o computador pula `j × 50` letras. Sem o 50, ele não sabe onde a linha 1 começa.

**Cuidado:** `char descricoes[]` (um `[]` só) seria **um** texto, não uma lista.

## 21. Parênteses vazios no protótipo

**Em uma linha:** `void f();` diz só o nome e o tipo de retorno; sem a lista de parâmetros, o compilador não confere a chamada.

**Por que existe:** o protótipo serve para o compilador avisar quando uma chamada está errada (conceito 18). Ele só consegue avisar se souber quais parâmetros a função recebe. Com `()` vazio, em C, ele aceita qualquer chamada, até com o número errado de argumentos, e o erro só aparece quando o programa roda.

**Exemplo:** com `void bubbleSortLeituraPorId();`, a chamada `bubbleSortLeituraPorId(ids, n);` (faltando 4 arrays) compila sem aviso. Com o protótipo completo do PDF p7, o compilador recusa: "too few arguments".

**Cuidado:** compilar sem erro não prova que o protótipo está certo. A assinatura tem que ser igual à do PDF, parâmetro por parâmetro.

## 22. Compilar × ligar e o `main`

**Em uma linha:** cada `.c` é compilado sozinho; depois o ligador (linker) junta todos num executável, e ele só consegue se existir exatamente um `main`.

**Por que existe:** o executável precisa saber por onde começar, e o começo é sempre o `main`. Compilar um `.c` só confere se ele está escrito certo; o protótipo basta para isso. Juntar os `.c` é outra etapa: nela, toda função chamada precisa ter definição (corpo) em algum `.c`, e o `main` precisa existir.

**Exemplo:** com os 5 `.c` só com cabeçalho e `#include`, cada um compila (`gcc -c carga.c` dá certo), mas `gcc -o main *.c` falha: `Undefined symbols: "_main"` (no Windows: `undefined reference to 'WinMain'` ou `'main'`).

**Cuidado:** dois `main` (por exemplo, um em `main.c` e outro num arquivo de teste na mesma pasta) também falham ao juntar: `duplicate symbol _main`.

## 23. Ler um arquivo: `fopen`, `fscanf`, `fclose`

**Em uma linha:** abro o arquivo com `fopen`, leio com `fscanf` (o `scanf` que lê do arquivo em vez do teclado) e fecho com `fclose`.

**Por que existe:** os dados do kwatch estão no disco (`leituras.txt`, `unidades.csv`), não são digitados. O programa precisa pedir acesso ao arquivo (abrir), tirar os valores dele (ler) e devolver o acesso no fim (fechar).

**Exemplo:**

| Linha de C | O que faz |
|---|---|
| `FILE *arq;` | variável que representa um arquivo aberto (tipo `FILE *`, de `<stdio.h>`) |
| `arq = fopen("leituras.txt", "r");` | abre para leitura (`"r"` = read); devolve `NULL` se não conseguiu |
| `if (arq == NULL) return -1;` | arquivo não abriu: a `carregarLeituras` devolve -1 (PDF p4) |
| `fscanf(arq, "%d", &id);` | lê um `int` do arquivo, como o `scanf` |
| `fclose(arq);` | fecha |

**O que o `fscanf` devolve:** quantos valores conseguiu ler naquela chamada: `1` (leu o `%d` pedido) ou `-1`, chamado `EOF` (fim do arquivo, não leu nada e não mexeu na variável). Ele lê da esquerda para a direita e para no primeiro valor que não combina com o formato: `5 abc` com `"%d %f"` devolve `1` (leu só o 5). Ler até o fim: `while (fscanf(arq, "%d", &x) == 1)`.

**Arquivo vazio × arquivo que não abre:** vazio abre normalmente (o `fopen` não devolve `NULL`); o que falha é o `fscanf`. Na `carregarLeituras`: não abriu → -1; vazio → 0 leituras.

**Onde está o `FILE`:** o tipo `FILE` e as funções `fopen`, `fscanf` e `fclose` vêm de `<stdio.h>`. O arquivo `.c` que usa essas peças precisa de `#include <stdio.h>` no topo; sem ele, o compilador para em `FILE *arq;` com `unknown type name 'FILE'` (não conhece o tipo).

**Cuidado:** testar o `NULL` logo depois do `fopen`: ler ou fechar um arquivo que não abriu derruba o programa. E o `fclose` vem antes do `return`, porque nada depois do `return` roda.

## 24. Carregar arquivo em arrays paralelos

**Em uma linha:** a cada linha do arquivo, o `fscanf` grava cada coluna direto na posição `n` do seu array e `n` sobe 1; paro no fim do arquivo ou quando `n` chega em `max`.

**Por que existe:** a `carregarLeituras` (PDF p4) tem que pôr as 5 colunas de cada linha do `leituras.txt` na **mesma posição** dos 5 arrays, para a leitura continuar inteira (conceito 3), e não pode gravar além do tamanho dos arrays (`max`).

**Exemplo:** `while (n < max && fscanf(arq, "%d %f", &ids[n], &consumos[n]) == 2) n++;` com o arquivo `3 185.7` / `1 245.5` / `2 198.3`:

| `i` | `ids[i]` | `consumos[i]` |
|---|---|---|
| 0 | 3 | 185.7 |
| 1 | 1 | 245.5 |
| 2 | 2 | 198.3 |

devolve `n` = 3.

| Peça | Por quê |
|---|---|
| `&ids[n]` | endereço da posição `n`: o `fscanf` grava ali, sem variável no meio |
| `n` | antes de ler, é a posição livre; no fim, é quantas linhas li (gravei em 0, 1, 2, então `n` = 3) |
| `== 2` | o formato pede 2 valores; a linha só está completa se ele leu os 2 (na `carregarLeituras`, são 5) |
| `n < max &&` na frente | o `&&` para no primeiro lado falso: com `n == max` o `fscanf` nem roda e nada é gravado em `ids[max]`, que não existe |

**Cuidado:** sem o `n++` no corpo do laço, toda linha é gravada na posição 0, uma por cima da outra (fica só a última), e a função devolve 0. A ordem dos destinos no `fscanf` é a ordem das colunas no arquivo (`id unidade_id mes ano consumo`, PDF p2).

## 25. Ler `id;descricao`: o `;` e o `%49[^\n]`

**Em uma linha:** `fscanf(arq, "%d;%49[^\n]", &unidadeIds[n], descricoes[n])` lê o número, pula o `;` e lê o resto da linha, com os espaços, até no máximo 49 letras.

**Por que existe:** no `unidades.csv` (PDF p2) as colunas são separadas por `;`, e a descrição tem espaços (`Laboratorio de Informatica`). O `%s` que você já conhece para no primeiro espaço, então leria só `Laboratorio`. E `descricoes[n]` tem 50 posições (PDF p5): 49 letras e o `'\0'` (conceito 5).

**As peças do formato `"%d;%49[^\n]"`, lendo `101;Laboratorio de Informatica`:**

| Peça | O que faz | Aqui |
|---|---|---|
| `%d` | lê um `int` | grava 101 em `unidadeIds[n]` |
| `;` | um caractere comum no formato: o `fscanf` exige um `;` exatamente ali e o pula | consome o `;` |
| `%[^\n]` | lê todo caractere que **não** é fim de linha (`^` = "não", `\n` = fim de linha); espaço entra | `Laboratorio de Informatica` |
| `49` entre `%` e `[` | lê no máximo 49 caracteres; o `fscanf` põe o `'\0'` logo depois | no máximo as posições 0 a 48, com o `'\0'` em até a 49 |

O `fscanf` devolve quantos valores gravou: aqui, 2 numa linha completa (o `;` não conta, ele não grava nada).

**Exemplo:** `tests/pdf/unidades.csv` com `while (n < max && fscanf(arq, "%d;%49[^\n]", &unidadeIds[n], descricoes[n]) == 2) n++;`

| `j` | `unidadeIds[j]` | `descricoes[j]` |
|---|---|---|
| 0 | 101 | Laboratorio de Informatica |
| 1 | 203 | Biblioteca Central |
| 2 | 150 | Bloco Administrativo |

devolve `n` = 3. Com `%s` no lugar de `%49[^\n]`, `descricoes[0]` seria só `Laboratorio`; na volta seguinte o `%d` tentaria ler `de` como número, falharia, e a função devolveria 1.

**Por que `descricoes[n]` vai sem `&`:** `descricoes[n]` é uma linha inteira da matriz (conceito 20), um array de `char`. Nome de array, passado para uma função, já é o endereço da posição 0 dele. Já `unidadeIds[n]` é um `int` só, e o `fscanf` precisa do endereço dele: `&unidadeIds[n]`.

**Por que `[^\r\n]` no kwatch (sugestão):** arquivo salvo no Windows termina cada linha com `\r\n`. No Windows o `fopen` com `"r"` já tira o `\r`; no Mac ele chega ao `fscanf`, e com só `[^\n]` ficaria no fim da descrição (`"Laboratorio de Informatica\r"`). Com `%49[^\r\n]` a leitura para no que vier primeiro.

**E o fim de linha?** O `%[^\n]` para **antes** do `\n` e o deixa no arquivo. Na volta seguinte, o `%d` pula espaços e fins de linha antes do número, então o `\n` some sem fazer nada.

**Cuidado:** sem o `49`, uma descrição de 60 letras seria gravada até a posição 60 de uma linha que só tem 50 posições, por cima da linha seguinte. O `49` é o tamanho da linha (50) menos 1, por causa do `'\0'`. Material de fora do Vault (o Vault não tem material de arquivos): o `%[...]` é chamado de *scanset* na documentação do C.

## 26. Busca linear: achei e o -1 depois do laço

**Em uma linha:** olho as posições de 0 a `n - 1`, uma por uma; na primeira em que `ids[i]` é o procurado, devolvo `i`; se o laço acabar sem achar, devolvo -1.

**Por que existe:** a opção 2 do menu (PDF p13) precisa saber **em que posição** está a leitura de um ID, para mostrar a unidade, o mês, o ano e o consumo da mesma posição nos outros arrays (conceito 3). A busca linear funciona com os IDs em qualquer ordem, inclusive na ordem do arquivo.

**Exemplo:** `ids` = 1, 3, 2, 4, 5 (ordem do `leituras.txt`, PDF p2), procurando 4:

| `i` | `ids[i]` | `ids[i] == 4`? |
|---|---|---|
| 0 | 1 | não |
| 1 | 3 | não |
| 2 | 2 | não |
| 3 | 4 | **sim: devolve 3** |

Devolve 3, a **posição**. O valor 4 o `main` já sabe: foi ele que pediu.

**Por que o -1 fica depois do laço:** só dá para dizer "não está" depois de olhar **todas** as posições. Dentro do laço, uma posição diferente diz só que o ID não está **ali**.

**Cuidado:** um `else return -1;` dentro do laço faz a função desistir já na posição 0: procurando 3, olha `ids[0]` = 1, é diferente, e devolve -1, sem nunca chegar à posição 1, onde o 3 está.

## 27. Busca binária: `inicio`, `fim` e `meio`

**Em uma linha:** com o array em ordem crescente, olho a posição do meio do pedaço que sobrou; se for o procurado, devolvo o meio; se for menor, o procurado só pode estar à direita (`inicio = meio + 1`); se for maior, só à esquerda (`fim = meio - 1`).

**Por que existe:** a opção 2 do menu oferece a binária (PDF p13). Em vez de olhar uma posição por volta, como a linear (conceito 26), cada volta descarta metade do que sobrou: com 1000 leituras, a linear pode precisar de 1000 voltas; a binária, de no máximo 10.

| Variável | O que guarda | Começa em | Muda quando |
|---|---|---|---|
| `inicio` | primeira posição onde o procurado ainda pode estar | 0 | `ids[meio]` é menor que o procurado: vira `meio + 1` |
| `fim` | última posição onde o procurado ainda pode estar | `n - 1` | `ids[meio]` é maior que o procurado: vira `meio - 1` |
| `meio` | a posição olhada nesta volta | calculada em toda volta | `(inicio + fim) / 2`, divisão inteira (`7 / 2` dá 3) |

**Exemplo:** `ids` = 1, 2, 3, 4, 5, procurando 2:

| Volta | `inicio` | `fim` | `meio` | `ids[meio]` | O que acontece |
|---|---|---|---|---|---|
| 1 | 0 | 4 | 2 | 3 | 3 maior que 2: `fim` = 1 |
| 2 | 0 | 1 | 0 | 1 | 1 menor que 2: `inicio` = 1 |
| 3 | 1 | 1 | 1 | 2 | igual: devolve 1 |

**Quando para:** quando acha (devolve `meio`) ou quando `inicio` passa de `fim`: aí não sobrou nenhuma posição onde o procurado possa estar, e devolve -1, **depois** do laço, como na linear.

**Por que `meio + 1` e `meio - 1`, e não `meio`:** a posição `meio` já foi olhada. Com `inicio = meio`, quando `inicio` e `fim` ficam vizinhos o `meio` dá sempre o mesmo número e o laço nunca termina.

**Cuidado:** a condição é `inicio <= fim`. Quando `inicio == fim` ainda sobra **uma** posição para olhar (volta 3 do Exemplo); com `<`, ela é pulada e a função devolve -1 com o valor lá.

## 28. Bubble sort por ID trocando os 5 arrays

**Em uma linha:** comparo cada par de vizinhos (`j` e `j + 1`); se o da esquerda tem ID maior, troco as duas leituras inteiras (5 arrays); a cada passada, o maior ID que sobrou vai para o fim.

**Por que existe:** a opção 1 do menu, ordenação 1, é o bubble sort (PDF p7, p12). Ele ordena por `ids`, mas cada troca leva junto as outras 4 colunas, senão a leitura se desfaz (conceito 9).

| Variável | O que guarda | Começa em | Limite e por quê |
|---|---|---|---|
| `i` | quantas passadas já terminaram (quantos maiores já estão no fim) | 0 | `i < n - 1`: com `n - 1` maiores no lugar, o que sobra na posição 0 já é o menor |
| `j` | a posição da esquerda do par comparado | 0 | `j < n - 1 - i`: o par é `j` e `j + 1`, então `j + 1` não pode passar de `n - 1`; e as últimas `i` posições já estão no lugar |
| `aux` (`int`) | um valor de `ids`, `unidadeIds`, `meses` ou `anos` durante a troca | (a cada troca) | sem ela, o primeiro valor seria apagado antes de ser copiado |
| `auxC` (`float`) | o valor de `consumos` durante a troca | (a cada troca) | `float`: em `int`, 310.2 viraria 310 |

**Exemplo:** `ids` = 4, 1, 3, passada 1 (`i` = 0, `j` de 0 a 1):

| `j` | par comparado | troca? | `ids` depois |
|---|---|---|---|
| 0 | 4 e 1 | sim | 1, 4, 3 |
| 1 | 4 e 3 | sim | 1, 3, 4 |

O 4, o maior, chegou ao fim. A passada 2 compara só `j` = 0 (1 e 3, sem troca).

**A troca de uma coluna, em 3 linhas:** `aux = ids[j]; ids[j] = ids[j + 1]; ids[j + 1] = aux;`. Repete-se para cada um dos 5 arrays, com `auxC` nos `consumos`. (sugestão) Para não escrever 15 linhas de novo em cada ordenação, dá para criar no `organizacao.c` uma função auxiliar `trocaLeitura(..., int a, int b)` que troca as posições `a` e `b` nos 5 arrays; ela não está no PDF, então não vai no `kwatch.h` como função pedida.

**Cuidado:** trocar só `ids` passa no teste de "IDs em ordem", mas desassocia as leituras: o caso 7 confere unidade, mês, ano e consumo de cada ID (PDF p13).

## 29. Insertion sort por ID guardando a leitura inteira

**Em uma linha:** para cada `i` a partir de 1, guardo a leitura da posição `i` (a `chave`), ando para a direita cada leitura da esquerda com ID maior que o da `chave`, e ponho a `chave` no buraco que sobrou.

**Por que existe:** a opção 1 do menu, ordenação 2, é o insertion sort (PDF p7, p12). A parte da esquerda (posições 0 a `i - 1`) já está em ordem; cada volta insere mais uma leitura nela.

| Variável | O que guarda | Começa em | Muda quando |
|---|---|---|---|
| `i` | a posição da leitura que vai ser inserida | 1 (a posição 0 sozinha já está em ordem) | a cada volta do laço de fora, até `n - 1` |
| `chaveId`, `chaveU`, `chaveM`, `chaveA` (`int`), `chaveC` (`float`) | as 5 colunas da leitura da posição `i` | no começo de cada volta | não mudam até a leitura entrar no lugar |
| `j` | a posição comparada com a `chave`, andando para a esquerda | `i - 1` | `j--` a cada deslocamento; para em -1 ou num ID menor ou igual |

**Exemplo:** `ids` = 4, 1, 3:

| `i` | `chave` | Andaram para a direita | Entra na posição | `ids` depois |
|---|---|---|---|---|
| 1 | 1 | o 4 | 0 | 1, 4, 3 |
| 2 | 3 | o 4 | 1 | 1, 3, 4 |

**Por que guardar as 5:** o primeiro deslocamento copia a posição `i - 1` para a posição `i`, por cima da leitura da `chave`, nas 5 colunas. O que não estiver guardado se perde.

**O deslocamento, nas 5 colunas:** `ids[j + 1] = ids[j];` e o mesmo para `unidadeIds`, `meses`, `anos` e `consumos`. No fim: `ids[j + 1] = chaveId;` e o mesmo para as outras 4.

**Cuidado:** a condição é `j >= 0 && ids[j] > chaveId`, nessa ordem. Quando `j` vira -1, o `&&` para no primeiro lado falso e `ids[-1]` (fora do array) nunca é lido.

## 30. Selection sort por ID: `pm` guarda a posição

**Em uma linha:** em cada passada `i`, procuro a **posição** do menor ID entre `i` e o fim (`pm`) e troco a leitura da posição `i` com a da posição `pm`, nos 5 arrays.

**Por que existe:** a opção 1 do menu, ordenação 3, é o selection sort (PDF p8, p12). Cada passada põe o menor que sobrou no lugar definitivo, com no máximo uma troca por passada.

| Variável | O que guarda | Começa em | Limite e por quê |
|---|---|---|---|
| `i` | a posição que vai receber o menor que sobrou | 0 | `i < n - 1`: quando as posições 0 a `n - 2` estão certas, a última só pode ter o maior |
| `pm` | a **posição** do menor ID visto até agora na passada | `i` (o primeiro candidato) | muda quando `ids[j] < ids[pm]` |
| `j` | a posição comparada com o menor até agora | `i + 1` (a posição `i` já é o candidato inicial) | `j < n`: olha até a última posição |

**Exemplo:** `ids` = 4, 1, 3:

| `i` | `pm` no fim (posição) | `ids[pm]` (valor) | Troca? | `ids` depois |
|---|---|---|---|---|
| 0 | 1 | 1 | sim, 0 com 1 | 1, 4, 3 |
| 1 | 2 | 3 | sim, 1 com 2 | 1, 3, 4 |

**Por que posição:** a troca precisa saber **de onde** tirar a leitura (as 5 colunas da posição `pm`). O valor 1 diz qual é o menor ID, mas não diz em que posição estão a unidade, o mês, o ano e o consumo dele.

**Cuidado:** a troca fica **depois** do laço do `j`, uma vez por passada; dentro do laço, trocaria a cada candidato novo.

## 31. Quick sort por ID: partição com pivô no fim

**Em uma linha:** a partição escolhe o ID da posição `fim` como pivô, junta à esquerda as leituras com ID menor ou igual, põe o pivô logo depois delas e devolve a posição dele (`p`); depois o quick ordena, chamando a si mesmo, a parte antes de `p` e a parte depois de `p`.

**Por que existe:** a opção 1 do menu, ordenação 4, é o quick sort (PDF p8, p12). Depois da partição, o pivô está no lugar definitivo; sobram dois pedaços menores, cada um com o mesmo problema (recursão).

| Variável | O que guarda | Começa em | Muda quando |
|---|---|---|---|
| `pivo` | o ID da posição `fim` | `ids[fim]` | não muda na partição |
| `i` | a última posição do grupo "menor ou igual ao pivô" | `inicio - 1` (grupo vazio) | sobe 1 a cada `ids[j] <= pivo`, e as leituras `i` e `j` trocam |
| `j` | a posição comparada com o pivô | `inicio` | vai até `fim - 1` (a posição `fim` é o pivô) |
| `p` | a posição final do pivô | `i + 1`, no fim da partição | (devolvida) |

**Exemplo:** `ids` = 4, 1, 3 com `(0, 2)`: `pivo` = 3, `i` = -1.

| `j` | `ids[j]` | `<= 3`? | `i` depois | `ids` depois |
|---|---|---|---|---|
| 0 | 4 | não | -1 | 4, 1, 3 |
| 1 | 1 | sim | 0 (troca 0 e 1) | 1, 4, 3 |

Fim: o pivô troca com `i + 1` = 1: `ids` = 1, 3, 4; `p` = 1.

**As duas chamadas:** `(inicio, p - 1)` e `(p + 1, fim)`. A posição `p` fica de fora porque o pivô já está no lugar certo.

**Quando para:** caso base é o pedaço com 0 ou 1 posição (`inicio >= fim`): já está em ordem e a função não faz nada. Por isso o corpo inteiro fica dentro de `if (inicio < fim)`.

**Cuidado:** cada troca da partição (as de dentro do laço e a do pivô) troca as 5 colunas. A chamada do `main` é `(…, 0, n - 1)`, provisório até a resposta da D3 (conceito 14).

## 32. Merge sort por ID: intercalar os 5 arrays

**Em uma linha:** divido o pedaço `inicio`..`fim` ao meio, ordeno cada metade chamando a mesma função, e intercalo as duas metades já ordenadas, pegando sempre a leitura de menor ID da frente de cada uma.

**Por que existe:** a opção 1 do menu, ordenação 5, é o merge sort (PDF p9, p12). Juntar duas listas ordenadas em uma só é fácil: basta comparar quem está na frente de cada uma.

| Variável | O que guarda | Começa em | Muda quando |
|---|---|---|---|
| `meio` | a última posição da metade da esquerda | `(inicio + fim) / 2` | (fixo na chamada) |
| `i` | a posição da frente na metade da esquerda | `inicio` | sobe quando a leitura dela vai para o `aux`; acaba em `meio` |
| `j` | a posição da frente na metade da direita | `meio + 1` | sobe quando a leitura dela vai para o `aux`; acaba em `fim` |
| `k` | a próxima posição livre no `aux` | 0 | sobe a cada leitura copiada |
| `auxIds`, `auxU`, `auxM`, `auxA` (`int`), `auxC` (`float`) | o pedaço intercalado, nas 5 colunas | vazios | no fim, copiados de volta para as posições `inicio` a `fim` |

**Exemplo:** metades 1, 4 (posições 0 e 1) e 3 (posição 2):

| `k` | frente da esquerda | frente da direita | Vai para `aux[k]` |
|---|---|---|---|
| 0 | 1 | 3 | 1 (esquerda) |
| 1 | 4 | 3 | 3 (direita) |
| 2 | 4 | (acabou) | 4 (sobra da esquerda) |

**As duas chamadas:** `(inicio, meio)` e `(meio + 1, fim)`; caso base, como no quick: `inicio >= fim` (0 ou 1 posição).

**Por que o `aux`:** escrever direto no array apagaria leituras da direita que ainda não foram comparadas. As 5 colunas vão para os 5 `aux`; o dos consumos é `float`. No fim, `aux[t]` volta para a posição `inicio + t`.

**Cuidado:** quando uma metade acaba, a sobra da outra é copiada inteira (dois laços depois do principal). Com `<=` na comparação (`ids[i] <= ids[j]`), em empate vai primeiro a da esquerda.

## 33. Função auxiliar `static`: `trocaLeitura`

**Em uma linha:** `trocaLeitura` troca duas leituras inteiras (as posições `a` e `b` nos 5 arrays) numa chamada só; o `static` na frente diz que ela só pode ser usada dentro do `organizacao.c`.

**Por que existe:** toda ordenação troca leituras, e cada troca são 15 linhas (3 por array: guardar, copiar, devolver). Bubble, selection e quick trocam; escrever as 15 linhas em cada lugar repete código e abre espaço para esquecer um array (o erro de trocar só `ids`, conceito 9). Com a função, a troca fica escrita uma vez e cada ordenação só chama `trocaLeitura(..., j, j + 1)`.

**Exemplo:** com os dados do PDF (p2) na ordem do arquivo, `trocaLeitura(ids, unidadeIds, meses, anos, consumos, 1, 2)`:

| Posição | Antes | Depois |
|---|---|---|
| 1 | 3, 101, 2, 2026, 310.2 | 2, 203, 1, 2026, 185.7 |
| 2 | 2, 203, 1, 2026, 185.7 | 3, 101, 2, 2026, 310.2 |

No bubble, é a troca do `j` = 1 da 1ª passada (`T06.md`, seção 2).

**O que o `static` faz:** sem ele, qualquer `.c` do projeto poderia chamar `trocaLeitura` (o ligador junta todos, conceito 22). Com ele, a função é "particular" do `organizacao.c`: não entra no `kwatch.h` e não aparece para o `main.c`. Serve para separar o que o PDF pede (as 12 funções, no `kwatch.h`) do que é só ajuda interna. `particionaLeituras` (quick) e `intercalaLeituras` (merge) são `static` pelo mesmo motivo.

**Cuidado:** a função `static` tem que estar escrita **acima** de quem a chama no arquivo, porque não tem protótipo no `.h` (conceito 18). E ela não é uma das 12 do PDF: as assinaturas pedidas continuam idênticas.

## 34. Acumulador com filtro: somar só o que interessa

**Em uma linha:** passo por todas as leituras; quando a unidade da leitura é a procurada, somo o consumo dela num `total` que começou em 0; no fim, devolvo o `total`.

**Por que existe:** a opção 3 do menu (PDF p14) mostra o consumo total de uma unidade. As leituras da mesma unidade estão espalhadas pelo array (no PDF, a 101 está nas posições 0 e 1, a 203 nas 2 e 4), então é preciso olhar todas.

| Variável | O que guarda | Começa em | Muda quando |
|---|---|---|---|
| `total` (`float`) | a soma dos consumos da unidade até agora | `0` (nada somado ainda) | `unidadeIds[i] == unidadeId`: `total += consumos[i]` |
| `i` | a posição da leitura olhada | 0 | a cada volta, até `n - 1` |

**Exemplo:** unidade 203 com os dados do PDF:

| `i` | `unidadeIds[i]` | `consumos[i]` | é 203? | `total` depois |
|---|---|---|---|---|
| 0 | 101 | 245.5 | não | 0.0 |
| 1 | 101 | 310.2 | não | 0.0 |
| 2 | 203 | 185.7 | sim | 185.7 |
| 3 | 150 | 420.0 | não | 185.7 |
| 4 | 203 | 205.8 | sim | 391.5 |

Devolve 391.5 (no menu, `391.50`).

**Cuidado:** o `total` é `float`: em `int`, 245.5 + 310.2 perderia as casas. Sem `= 0`, ele começa com o lixo que estava na memória. E o `return total` fica **depois** do laço: dentro, devolveria só a primeira leitura.

## 35. Mês e ano como um número só

**Em uma linha:** (sugestão) `ano * 12 + mes` transforma cada mês/ano num número que cresce de 1 em 1 a cada mês; aí "estar no período" vira `inicio <= numero && numero <= fim`.

**Por que existe:** a `calcularConsumoPeriodo` (PDF p10) soma as leituras entre mês/ano inicial e final, inclusive (conceito 7; D4, provisório). Um período pode virar o ano (12/2025 até 01/2026, caso 23), e aí comparar o mês sozinho falha.

**Exemplo:**

| Mês/ano | `ano * 12 + mes` |
|---|---|
| 11/2025 | 24311 |
| 12/2025 | 24312 |
| 01/2026 | 24313 |

Dezembro e janeiro ficam vizinhos, como no calendário.

| Variável | O que guarda |
|---|---|
| `inicio` | `anoInicial * 12 + mesInicial` |
| `fim` | `anoFinal * 12 + mesFinal` |
| `atual` | `anos[i] * 12 + meses[i]`, a leitura da posição `i` |
| `total` (`float`) | a soma, como no conceito 34 |

**Cuidado:** com só os meses, de 12 até 1 nenhum mês é `>= 12` e `<= 1` ao mesmo tempo: a função devolveria 0 em vez de 250.00. A validação (`Periodo invalido.`, mês fora de 1 a 12 ou início depois do fim) é do menu, na T19 (PDF p15).

## 36. Maior total reaproveitando `calcularConsumoUnidade`

**Em uma linha:** (sugestão) para cada leitura, peço à `calcularConsumoUnidade` o total da unidade dela; se for maior que o melhor até agora, ou igual com ID menor, essa unidade vira a melhor; no fim, devolvo o ID da melhor.

**Por que existe:** a opção 5 do menu (PDF p15) mostra a unidade de maior consumo. A soma por unidade já está pronta na T11; chamar a função evita escrever outro acumulador. Uma unidade aparece em várias leituras e é calculada de novo a cada vez, mas com no máximo 1000 leituras isso é rápido.

| Variável | O que guarda | Começa em | Muda quando |
|---|---|---|---|
| `melhorId` | o ID da unidade vencedora até agora | `unidadeIds[0]` | a condição abaixo é verdadeira |
| `melhorTotal` (`float`) | o total da unidade vencedora | o total de `unidadeIds[0]` | junto com `melhorId` |
| `total` (`float`) | o total da unidade da leitura `i` | `calcularConsumoUnidade(unidadeIds, consumos, n, unidadeIds[i])` | a cada `i` |

**Exemplo** (dados do PDF, p2):

| `i` | `unidadeIds[i]` | total | Troca? | `melhorId` / `melhorTotal` |
|---|---|---|---|---|
| 0 | 101 | 555.7 | primeira | 101 / 555.7 |
| 1 | 101 | 555.7 | não (igual, mesmo ID) | 101 / 555.7 |
| 2 | 203 | 391.5 | não (menor) | 101 / 555.7 |
| 3 | 150 | 420.0 | não (menor) | 101 / 555.7 |
| 4 | 203 | 391.5 | não | 101 / 555.7 |

**A condição:** `total > melhorTotal || (total == melhorTotal && unidadeIds[i] < melhorId)`. O primeiro lado escolhe o maior consumo; o segundo é o desempate do PDF (p11): no empate, fica o **menor ID**.

**Cuidado:** com `n` = 0 não há leitura para olhar (`unidadeIds[0]` não existe): (sugestão) devolver -1 antes do laço. O empate compara o **ID** (conceito 8), não a posição em que a unidade aparece.

## 37. O `main` declara os arrays e carrega

**Em uma linha:** o `main` cria os arrays (as funções só preenchem o que recebem), chama as duas cargas e, se alguma devolver -1, mostra o erro do PDF e termina com `return 0` antes do menu.

**Por que existe:** as funções da T02 e da T03 recebem os arrays prontos (PDF p3, p4, p5); quem cria é o `main`. E o PDF (p12) manda encerrar se um arquivo não abrir.

| No `main` | Por quê |
|---|---|
| `int ids[MAX], unidadeIds[MAX], meses[MAX], anos[MAX];` e `float consumos[MAX];` | os 5 arrays paralelos das leituras (conceito 3) |
| `int unidadeIdsCatalogo[MAX];` e `char descricoes[MAX][50];` | o catálogo de unidades (conceito 20) |
| `int n = carregarLeituras("leituras.txt", ids, unidadeIds, meses, anos, consumos, MAX);` | `n` é quantas leituras há; todas as outras funções recebem esse `n` |
| `int nUnidades = carregarUnidades("unidades.csv", unidadeIdsCatalogo, descricoes, MAX);` | quantas unidades há no catálogo |

**Exemplo** (PDF p12), pasta sem `leituras.txt`:

```
Erro ao abrir o arquivo leituras.txt.
Encerrando o programa.
```

**Cuidado:** o `printf` precisa de `#include <stdio.h>` no `main.c`. O texto é idêntico ao do PDF, com o ponto final e o `\n`. Para o `unidades.csv`, a mensagem troca só o nome do arquivo (caso 2, provisório).

## 38. Menu com `do`/`while` e `switch`

**Em uma linha:** o `do`/`while` mostra o menu, lê a opção e repete até a opção 6; o `switch` escolhe o que fazer com cada número, e o `default` pega tudo que não é 1 a 6.

**Por que existe:** o PDF (p12) manda o menu voltar depois das opções 1 a 5, encerrar na 6 com `Encerrando o programa.` e, em qualquer outro número, mostrar `Opcao invalida. Tente novamente.` e voltar.

| Peça | O que faz | Por quê |
|---|---|---|
| `int opcao;` | guarda o número digitado | |
| `do { ... } while (opcao != 6);` | roda o corpo **antes** de testar | o menu aparece antes de existir qualquer opção; com `while` na frente, `opcao` seria testada sem valor |
| `printf` do menu | as 8 linhas do PDF p12, idênticas | saída idêntica (conceito 6) |
| `scanf("%d", &opcao);` | lê a opção | |
| `switch (opcao) { case 1: ... break; ... }` | um bloco por opção | mais limpo que 6 `if` encadeados |
| `case 6:` | `printf("Encerrando o programa.\n");` | depois dele o `while (opcao != 6)` dá falso e o laço termina |
| `default:` | `printf("Opcao invalida. Tente novamente.\n");` | 0, 7, 9, -1... |

**Exemplo** (caso 5): entrada 9 e depois 6: menu, `Opcao invalida. Tente novamente.`, menu, `Encerrando o programa.`

**Cuidado:** sem `break;` no fim de cada `case`, o C continua executando o `case` de baixo. Letra digitada no lugar de número trava o `scanf` (dúvida D17): tratar na T21.

## 39. Opção 1: submenu uma vez e a descrição pelo catálogo

**Em uma linha:** na primeira vez, pergunto o algoritmo, ordeno os 5 arrays e marco `ordenado = 1`; em toda vez, imprimo o cabeçalho e uma linha por leitura, buscando a descrição no catálogo pela unidade.

**Por que existe:** o PDF (p13) diz que a escolha do algoritmo só é feita na primeira vez; depois os arrays já estão em ordem e a lista sai direto (caso 13). E a tabela mostra a descrição, que não está nas leituras (conceito 1).

| Variável | O que guarda | Começa em | Muda quando |
|---|---|---|---|
| `ordenado` | 0 se ainda não ordenou, 1 se já | `0`, declarada antes do `do` do menu | depois da ordenação do submenu: `ordenado = 1` |
| `alg` | a escolha do submenu (1 a 5) | lida com `scanf` | só na primeira vez |
| `pos` | a posição da unidade no catálogo | `buscaLinear(unidadeIdsCatalogo, nUnidade, unidadeIds[i])` | a cada leitura `i` |

**A descrição:** a `buscaLinear` da T04 procura um número num array e devolve a posição. Procurando `unidadeIds[i]` dentro de `unidadeIdsCatalogo`, ela devolve a posição `pos` da unidade no catálogo; a descrição é `descricoes[pos]`. Exemplo: a 101 está na posição 0 do catálogo, então `descricoes[0]` = `Laboratorio de Informatica`.

**Exemplo** (PDF p13), uma linha da tabela:

```
3 | 101 | Laboratorio de Informatica | 2 | 2026 | 310.20
```

`printf("%d | %d | %s | %d | %d | %.2f\n", ids[i], unidadeIds[i], descricoes[pos], meses[i], anos[i], consumos[i]);`

**Cuidado:** o separador tem 71 hífens (PDF p13). O consumo sai com `%.2f`. Opção inválida no submenu é a dúvida D8 (provisório: não ordena e não marca `ordenado`).

## 40. Opção 2: busca e o `ordenado` antes da binária

**Em uma linha:** peço o ID, pergunto a busca, chamo a busca escolhida e uso a posição que ela devolve para imprimir a leitura, ou a mensagem de não encontrada se ela devolver -1.

**Por que existe:** a busca binária só funciona com `ids` em ordem (conceito da T05), e o `leituras.txt` vem fora de ordem (PDF p2). O PDF (p13) manda ordenar antes quando a binária for escolhida e a opção 1 ainda não tiver ordenado. A variável `ordenado` da T16 já diz isso.

| Situação | `ordenado` | O que fazer antes da binária |
|---|---|---|
| a opção 1 já rodou | `1` | nada: `ids` já está em ordem |
| a opção 1 ainda não rodou | `0` | ordenar os 5 arrays e fazer `ordenado = 1` |

Qual ordenação usar aqui o PDF não diz (sugestão: `quickSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, 0, n - 1);`). Depois disso, a opção 1 não pergunta mais o algoritmo, porque `ordenado` já vale 1.

**Exemplo** (dados do PDF, ID 3): a binária devolve `pos = 2` (depois de ordenar, o ID 3 está na posição 2). A descrição sai de uma segunda busca, igual à da opção 1: `buscaLinear(unidadeIdsCatalogo, nUnidade, unidadeIds[pos])`.

```
Leitura encontrada:
ID Leitura: 3
Unidade: 101
Descricao: Laboratorio de Informatica
Mes: 2
Ano: 2026
Consumo: 310.20 kWh
```

**Cuidado:** a busca devolve uma **posição**, não um ID: imprima `ids[pos]`, não `pos`. A linear funciona com `ids` fora de ordem e não precisa ordenar. Não achou (devolveu -1): `Leiura nao encontrada.`, com o erro de digitação do PDF (dúvida D5). Opção inválida no submenu é a D8.

## 41. Opção 4: validar o período e o `%02d`

**Em uma linha:** antes de somar, confiro se os dois meses estão entre 1 e 12 e se o início não vem depois do fim; se algo falhar, `Periodo invalido.` e não calculo nada.

**Por que existe:** o PDF (p15) manda recusar mês fora de 1 a 12 e início posterior ao fim. A função `calcularConsumoPeriodo` só soma; quem valida é o `main`.

| Motivo | Condição que torna inválido |
|---|---|
| mês fora de 1 a 12 | `mesIni < 1 \|\| mesIni > 12 \|\| mesFim < 1 \|\| mesFim > 12` |
| início depois do fim | `anoIni * 12 + mesIni > anoFim * 12 + mesFim` (conceito 35) |

As duas juntas num `if` só, com `||` entre elas: se **qualquer** uma for verdadeira, é inválido.

**Por que não comparar só o mês:** 12/2025 até 1/2026 tem `mesIni = 12` maior que `mesFim = 1`, mas é válido (caso 23). Com o número único: 2025 × 12 + 12 = 24312 e 2026 × 12 + 1 = 24313, e 24312 não é maior que 24313.

**O `%02d`:** imprime o inteiro com no mínimo 2 dígitos, completando com zero à esquerda. `printf("%02d", 1)` sai `01`; `printf("%02d", 12)` sai `12`. O PDF mostra `Periodo: 01/2026 ate 02/2026`, então o mês sai com `%02d` e o ano com `%d`.

**Exemplo** (caso 22, dados do PDF):

```
Consumo no periodo:
Periodo: 01/2026 ate 02/2026
Consumo total: 1367.20 kWh
```

**Cuidado:** `ate` e `periodo` sem acento. Na chamada, a ordem é mês antes de ano: `calcularConsumoPeriodo(meses, anos, consumos, n, mesIni, anoIni, mesFim, anoFim)`. Com `%d` no lugar de `%02d` sai `1/2026`, que não é igual ao PDF.
