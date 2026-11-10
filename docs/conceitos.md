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
