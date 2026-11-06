# Roadmap

Planejamento do Projeto 2 (Sistema de Análise de Consumo de Energia), turma 02P11. Tudo aqui sai do enunciado (17 páginas); o que não está no PDF aparece marcado "(sugestão)". Requisitos: [`requisitos.md`](requisitos.md). Perguntas para o professor: [`duvidas.md`](duvidas.md).

**Situação da equipe:** o grupo tinha 3 integrantes; um desistiu e o outro está sem contato. O plano ativo é o **de 1 pessoa**. O plano **de 2 pessoas** fica pronto para ativar se o segundo integrante voltar (ver [divisão para 2 pessoas](#divisão-para-2-pessoas)).

## Datas da turma 02P11 (PDF p17)

| Data | Evento |
|---|---|
| 18/11 | Entrega no Moodle |
| 19/11 | Apresentação de funcionamento (individual) |
| 26/11 | Questionário prático (individual, com modificações no código) |

## Marcos

| Marco | Data | Atingido quando |
|---|---|---|
| M1 Esqueleto | 07/11 | T01 em `develop`; CI verde com `gcc -o main.exe *.c *.h` |
| M2 Funções | 11/11 | T02 a T13 em `develop`, cada uma com o checklist de revisão conferido |
| M3 Menu e congelamento | 16/11 | T14 a T22 concluídas; todas as saídas conferidas com o PDF; código congelado (só correção) |
| M4 Entrega | 18/11 | Tag `v1.0.0` em `main`; pacote só com fontes postado no Moodle (T23) |
| M5 Avaliação | 26/11 | Apresentação em 19/11 e questionário em 26/11 (T24) |

## Tarefas

Estimativa total: **47 h** para 1 pessoa (cerca de 4 h por dia de 06/11 a 18/11). Cada tarefa vira uma branch `feat/Txx-descricao` e um PR para `develop` (ver [`CONTRIBUTING.md`](../CONTRIBUTING.md)).

Critério de pronto de toda tarefa: compila com o comando oficial (CI verde), testada com os casos indicados de [`tests/casos.md`](../tests/casos.md), saída idêntica à do PDF quando houver saída, checklist de revisão do CONTRIBUTING conferido.

### Setup

- [x] **T00** Repositório, CI no Windows e dados de teste. R-01, R-76, R-77, R-78, R-80, R-87, R-95.
  O CI confirmou que, com GCC 15.2 (MinGW) no Windows, `gcc -o main.exe *.c *.h` funciona com um `.h` e **falha sem `.h`** (`cc1.exe: fatal error: *.h: Invalid argument`). Por isso o projeto tem `kwatch.h` (dúvida D2).
- [ ] **T01** Criar esqueleto com as 12 assinaturas do PDF e `kwatch.h` (2 h, Sprint 1). R-01, R-08, R-09, R-10, R-11, R-15, R-20, R-22, R-25, R-27, R-29, R-31, R-33, R-35, R-37, R-39, R-75, R-79.
  - [ ] (sugestão) `main.c`, `carga.c`, `busca.c`, `ordenacao.c`, `analise.c` e `kwatch.h` (obrigatório) com os protótipos e `#define MAX 1000`
  - [ ] Assinaturas copiadas exatamente do PDF; arrays do PDF p3, sem `struct`
  - [ ] Cabeçalho com nome e RA em cada arquivo

### Carregamento (PDF 4.1)

- [ ] **T02** Implementar `carregarLeituras` (2 h, Sprint 1). R-02, R-03, R-04, R-11, R-12, R-13, R-14. Casos: exemplo retorna 5, arquivo inexistente retorna -1, mais linhas que `max`.
- [ ] **T03** Implementar `carregarUnidades` (2 h, Sprint 1). R-05, R-06, R-07, R-15 a R-19. Casos 2 e 21; descrição com espaços; no máximo 49 caracteres.

### Busca (PDF 4.2)

- [ ] **T04** Implementar `buscaLinear` (1 h, Sprint 1). R-20, R-21. Casos 14 e 17.
- [ ] **T05** Implementar `buscaBinaria` (2 h, Sprint 1). R-22, R-23. Casos 15, 16 e 17.

### Ordenação (PDF 4.3), sempre trocando os 5 arrays juntos (R-24)

- [ ] **T06** Implementar Bubble Sort por ID (2 h, Sprint 1). R-24, R-25, R-26. Casos 7 e 12.
- [ ] **T07** Implementar Insertion Sort por ID (2 h, Sprint 1). R-24, R-27, R-28. Casos 8 e 12.
- [ ] **T08** Implementar Selection Sort por ID (2 h, Sprint 1). R-24, R-29, R-30. Casos 9 e 12.
- [ ] **T09** Implementar Quick Sort por ID (3 h, Sprint 1). R-24, R-31, R-32. Casos 10 e 12; chamada inicial conforme a dúvida D3.
- [ ] **T10** Implementar Merge Sort por ID (3 h, Sprint 1). R-24, R-33, R-34. Casos 11 e 12; chamada inicial conforme a dúvida D3.

### Análise de dados (PDF 4.4)

- [ ] **T11** Implementar `calcularConsumoUnidade` (1 h, Sprint 1). R-35, R-36. Casos 18, 20 e 29.
- [ ] **T12** Implementar `calcularConsumoPeriodo` (2 h, Sprint 2). R-37, R-38. Casos 22 e 23; limites conforme a dúvida D4.
- [ ] **T13** Implementar `encontrarUnidadeMaiorConsumo` (2 h, Sprint 2). R-39, R-40, R-41. Casos 27 e 28.

### Main e menu (PDF p12 a p16)

- [ ] **T14** Implementar carga inicial e erro de abertura no `main` (2 h, Sprint 2). R-08, R-10, R-42, R-43, R-44, R-45. Casos 1 e 2.
- [ ] **T15** Implementar laço do menu, saída e opção inválida (2 h, Sprint 2). R-46, R-47, R-72, R-73. Casos 3 a 6.
  - [ ] Depois do merge, criar a variável do repositório `FUMACA_ESTRITA=true` (o CI passa a exigir as mensagens do teste de fumaça)
- [ ] **T16** Implementar opção 1, listar ordenadas (3 h, Sprint 2). R-48 a R-54. Casos 7 a 13.
- [ ] **T17** Implementar opção 2, buscar leitura (2 h, Sprint 2). R-55 a R-60. Casos 14 a 17.
- [ ] **T18** Implementar opção 3, consumo de unidade (1 h, Sprint 2). R-61 a R-64. Casos 18 a 21 e 29.
- [ ] **T19** Implementar opção 4, consumo no período (2 h, Sprint 2). R-65 a R-69. Casos 22 a 26.
- [ ] **T20** Implementar opção 5, maior consumo (1 h, Sprint 2). R-41, R-70, R-71. Casos 27 e 28.

### Testes, entrega e avaliação

- [ ] **T21** Rodar todos os casos de `tests/casos.md` (2 h, Sprint 2). R-04, R-07, R-24, R-41, R-44, R-58, R-62, R-68, R-69, R-73, R-91. Nada pode travar.
- [ ] **T22** Congelar o código e conferir as saídas com o PDF em 16/11 (2 h, Sprint 2). R-44 a R-73 (saídas), R-75, R-87, R-91, R-95.
  - [ ] Cada prompt e mensagem idênticos ao PDF; consumo com 2 casas decimais
  - [ ] Cabeçalho com nome e RA em todos os arquivos; CI verde; PR de `develop` para `main`
- [ ] **T23** Gerar o pacote da tag `v1.0.0` e entregar no Moodle até 18/11 (1 h, Sprint 2). R-74, R-75, R-81, R-86, R-88, R-90, R-92, R-93, R-94.
  - [ ] Pacote só com os `.c` e o `.h` da raiz (comando no CONTRIBUTING); dados conforme a dúvida D13
  - [ ] Compilar o pacote numa pasta vazia com o comando oficial antes de postar; guardar o comprovante
- [ ] **T24** Preparar a demonstração e o questionário (3 h, Sprint 3). R-80, R-82, R-83, R-84, R-85, R-86, R-89.
  - [ ] Ensaiar a demonstração das 6 opções até 18/11
  - [ ] (sugestão) Em branch `treino/*`, nunca mergeada, fazer modificações a partir dos requisitos: ordenar em ordem decrescente; ordenar por consumo ou por unidade; buscar a primeira leitura de uma unidade; período excluindo o mês final; desempate pelo maior ID; unidade de menor consumo
  - [ ] Saber explicar cada função sem consultar o código

## Cronograma (1 pessoa)

| Sprint | Período | Tarefas | Horas |
|---|---|---|---|
| Sprint 1 | 05 a 11/11 | T01 a T11 | 22 |
| Sprint 2 | 12 a 18/11 | T12 a T23 (congelamento em 16/11, entrega em 18/11) | 22 |
| Sprint 3 | 19 a 26/11 | Apresentação em 19/11; T24 até o questionário em 26/11 | 3 |

## Divisão para 2 pessoas

Para ativar se o segundo integrante voltar. Regras: horas equilibradas; quick e merge com pessoas diferentes; cada um implementa pelo menos uma ordenação; quem não escreveu revisa (o PR passa a exigir 1 aprovação); quem não é dono do menu testa as opções (T21).

| Pessoa | Tarefas | Horas | Revisa |
|---|---|---|---|
| A (Nicolas) | T01, T05, T09, T14 a T20, T22, T24 (A) | 25 | T02, T03, T04, T06, T07, T08, T10, T11, T12, T13, T21, T23 |
| B (______) | T02, T03, T04, T06, T07, T08, T10, T11, T12, T13, T21, T23, T24 (B) | 25 | T01, T05, T09, T14 a T20, T22 |

- Na divisão para 2, T24 é feita por cada pessoa (3 h cada) e o treino passa a ser em código que a pessoa **não** escreveu, como pede o formato do questionário. (sugestão) A modifica merge e selection (de B); B modifica quick e `buscaBinaria` (de A).

| Sprint | A | B |
|---|---|---|
| Sprint 1 | T01, T05, T09, T14 | T02, T03, T04, T06, T07, T08, T10, T11 |
| Sprint 2 | T15 a T20, T22 | T12, T13, T21, T23 |
| Sprint 3 | T24 (A) | T24 (B) |

## Riscos

| Risco | Contingência |
|---|---|
| Não compilar com o comando oficial (zera o projeto) | `kwatch.h` obrigatório; o CI no Windows bloqueia o merge sem `.h`; confirmar com o professor (D2) |
| 47 h para 1 pessoa em 13 dias | Funções primeiro (são o que o questionário modifica); conferir as saídas com o PDF só no fim; 16/11 é a data-limite do congelamento |
| Situação do grupo (PDF p16: grupos de 2 a 3) | Perguntar ao professor já (D1) e manter a divisão para 2 pronta |
