# Matriz de requisitos

Fonte única: enunciado do Projeto 2 (Sistema de Análise de Consumo de Energia), 17 páginas. Turma 02P11.
Cada linha é um requisito atômico. A coluna Tarefas lista as tarefas do [roadmap](roadmap.md) que o atendem; as ambiguidades estão em [duvidas.md](duvidas.md).

| R | Requisito | Seção/página | Tipo | Como verificar | Tarefas |
|---|---|---|---|---|---|
| R-01 | Implementar o sistema em C | §2 p1, p16 | restrição | Fontes `.c` compilam com gcc | T00, T01 |
| R-02 | Ler `leituras.txt`, uma leitura por linha no formato `id unidade_id mes ano consumo`, separados por espaço | §3 p1-2 | funcional | Carregar o exemplo da p2 e conferir os 5 registros | T02 |
| R-03 | O consumo é um float em kWh | p2 | funcional | Ler `245.5` e exibir `245.50` | T02 |
| R-04 | `leituras.txt` pode vir fora da ordem de ID (exemplo 1, 3, 2, 4, 5) | p2 | restrição | Caso 12 de `tests/casos.md` | T02, T21 |
| R-05 | Ler `unidades.csv` no formato `id;descricao` | p2 | funcional | Carregar o exemplo da p2 | T03 |
| R-06 | A descrição pode conter espaços | p2 | funcional | "Laboratorio de Informatica" lida inteira | T03 |
| R-07 | Todo `unidade_id` das leituras está cadastrado em `unidades.csv` (premissa) | p2 | restrição | Dados de teste respeitam | T03, T21 |
| R-08 | Leituras em 5 arrays paralelos com nomes e tipos do PDF e `#define MAX 1000` | §3 p3 | restrição | Revisão | T01, T14 |
| R-09 | Proibido usar `struct` | p3 | restrição | Busca por `struct` sem resultado | T01 |
| R-10 | Unidades em `unidadeIdsCatalogo[MAX]` e `descricoes[MAX][50]` paralelos | p3 | restrição | Revisão | T01, T14 |
| R-11 | `carregarLeituras` com assinatura idêntica | §4.1 p4 | funcional | Comparar com o PDF | T01, T02 |
| R-12 | `carregarLeituras` retorna o número de registros carregados | p4 | funcional | Exemplo retorna 5 | T02 |
| R-13 | `carregarLeituras` retorna -1 se não abrir o arquivo | p4 | funcional | Caso 1 | T02 |
| R-14 | `carregarLeituras` não passa de `max` | p4 | funcional | Arquivo com mais de `max` linhas | T02 |
| R-15 | `carregarUnidades` com assinatura idêntica | §4.1 p5 | funcional | Comparar com o PDF | T01, T03 |
| R-16 | `carregarUnidades` retorna o número de unidades | p5 | funcional | Exemplo retorna 3 | T03 |
| R-17 | `carregarUnidades` retorna -1 se não abrir o arquivo | p5 | funcional | Caso 2 | T03 |
| R-18 | Descrição de até 49 caracteres, sem estourar `[50]` | p5 | restrição | Caso 21 | T03 |
| R-19 | `carregarUnidades` não passa de `max` | p5 | funcional | Arquivo com mais de `max` linhas | T03 |
| R-20 | `buscaLinear` com assinatura idêntica | §4.2 p6 | funcional | Comparar com o PDF | T01, T04 |
| R-21 | `buscaLinear` faz busca sequencial e retorna o índice ou -1 | p6 | funcional | Casos 14 e 17 | T04 |
| R-22 | `buscaBinaria` com assinatura idêntica | p6 | funcional | Comparar com o PDF | T01, T05 |
| R-23 | `buscaBinaria` faz busca binária em ids crescentes e retorna o índice ou -1 | p6 | funcional | Casos 15, 16 e 17 | T05 |
| R-24 | Toda ordenação reorganiza os 5 arrays juntos, mantendo cada leitura associada | §4.3 p7, p13 | restrição | Casos 7 a 12 | T06, T07, T08, T09, T10, T21 |
| R-25 | `bubbleSortLeituraPorId` com assinatura idêntica | p7 | funcional | Comparar com o PDF | T01, T06 |
| R-26 | Bubble Sort em ordem crescente de ID | p7 | funcional | Caso 7 | T06 |
| R-27 | `insertionSortLeituraPorId` com assinatura idêntica | p7 | funcional | Comparar com o PDF | T01, T07 |
| R-28 | Insertion Sort em ordem crescente de ID | p7 | funcional | Caso 8 | T07 |
| R-29 | `selectionSortLeituraPorId` com assinatura idêntica | p8 | funcional | Comparar com o PDF | T01, T08 |
| R-30 | Selection Sort em ordem crescente de ID | p8 | funcional | Caso 9 | T08 |
| R-31 | `quickSortLeituraPorId(..., int inicio, int fim)` com assinatura idêntica | p8 | funcional | Comparar com o PDF | T01, T09 |
| R-32 | Quick Sort em ordem crescente de ID | p8 | funcional | Casos 10 e 12 | T09 |
| R-33 | `mergeSortLeituraPorId(..., int inicio, int fim)` com assinatura idêntica | p9 | funcional | Comparar com o PDF | T01, T10 |
| R-34 | Merge Sort em ordem crescente de ID | p9 | funcional | Caso 11 | T10 |
| R-35 | `calcularConsumoUnidade` com assinatura idêntica | §4.4 p10 | funcional | Comparar com o PDF | T01, T11 |
| R-36 | Retorna a soma do consumo das leituras da unidade (float) | p10 | funcional | Casos 18, 20 e 29 | T11 |
| R-37 | `calcularConsumoPeriodo` com assinatura idêntica | p10 | funcional | Comparar com o PDF | T01, T12 |
| R-38 | Retorna a soma do consumo entre mês/ano inicial e mês/ano final | p10 | funcional | Casos 22 e 23 | T12 |
| R-39 | `encontrarUnidadeMaiorConsumo` com assinatura idêntica | p11 | funcional | Comparar com o PDF | T01, T13 |
| R-40 | Retorna o ID com maior consumo acumulado, somando todas as leituras do mesmo `unidade_id` | p11, p15 | funcional | Caso 27 | T13 |
| R-41 | Em caso de empate, retorna a unidade de menor ID | p11, p15 | funcional | Caso 28 | T13, T20, T21 |
| R-42 | O `main` carrega `leituras.txt` no início | p12 | funcional | Execução | T14 |
| R-43 | O `main` carrega `unidades.csv` no início | p12 | funcional | Execução | T14 |
| R-44 | Se um arquivo não abre: `Erro ao abrir o arquivo <nome>.` | p12 | saída | Casos 1 e 2 | T14, T21, T22 |
| R-45 | Depois do erro: `Encerrando o programa.` e encerra | p12 | saída | Casos 1 e 2 | T14, T22 |
| R-46 | Menu com título, 6 opções e `Escolha uma opcao:`, texto idêntico | p12 | saída | Caso 3 | T15, T22 |
| R-47 | Após as opções 1 a 5, volta ao menu | p12 | funcional | Teste de fumaça e casos 5 a 29 | T15, T22 |
| R-48 | Opção 1, primeira vez: submenu `Escolha o algoritmo de ordenacao:` (1 a 5) e `Opcao:` | p12-13 | saída | Casos 7 a 11 | T16, T22 |
| R-49 | Usa a função de ordenação correspondente à escolha | p13 | funcional | Revisão e casos 7 a 11 | T16, T22 |
| R-50 | Exibe as leituras em ordem crescente de ID | p13 | funcional | Casos 7 a 12 | T16, T22 |
| R-51 | Nas vezes seguintes, não precisa perguntar e lista as já ordenadas | p13 | funcional | Caso 13 | T16, T22 |
| R-52 | Cabeçalho `Leituras ordenadas por ID:`, linha de colunas e separador de 71 hífens | p13 | saída | Caso 7 | T16, T22 |
| R-53 | Linha `id \| unidade \| descricao \| mes \| ano \| consumo` com consumo em 2 casas | p13 | saída | Caso 7 | T16, T22 |
| R-54 | A descrição de cada leitura vem do cadastro, pelo `unidade_id` | p2, p13 | funcional | Caso 7 | T16, T22 |
| R-55 | Opção 2 pede `Digite o ID da leitura:` | p13 | saída | Caso 14 | T17, T22 |
| R-56 | Submenu `Escolha o algoritmo de busca:` (1 linear, 2 binaria) e `Opcao:` | p13 | saída | Caso 14 | T17, T22 |
| R-57 | Usa `buscaLinear` ou `buscaBinaria` conforme a escolha | p13 | funcional | Revisão | T17, T22 |
| R-58 | Busca binária com leituras ainda não ordenadas: ordena antes | p13 | funcional | Caso 15 | T17, T21, T22 |
| R-59 | Encontrada: `Leitura encontrada:`, `ID Leitura:`, `Unidade:`, `Descricao:`, `Mes:`, `Ano:`, `Consumo: x.xx kWh` | p13-14 | saída | Caso 14 | T17, T22 |
| R-60 | Não encontrada: `Leiura nao encontrada.` | p14 | saída | Caso 17 (ver dúvida) | T17, T22 |
| R-61 | Opção 3 pede `Digite o ID da unidade:` | p14 | saída | Caso 18 | T18, T22 |
| R-62 | Unidade não cadastrada: `Unidade nao encontrada.` | p14 | saída | Caso 19 | T18, T21, T22 |
| R-63 | Unidade existente: calcula com `calcularConsumoUnidade` | p14 | funcional | Revisão | T18, T22 |
| R-64 | Saída `Consumo da unidade:`, `Unidade:`, `Descricao:`, `Consumo total: x.xx kWh` | p14 | saída | Caso 18 | T18, T22 |
| R-65 | Opção 4 pede `Digite o mes inicial:`, `Digite o ano inicial:`, `Digite o mes final:`, `Digite o ano final:` | p14 | saída | Caso 22 | T19, T22 |
| R-66 | Calcula com `calcularConsumoPeriodo` | p15 | funcional | Revisão | T19, T22 |
| R-67 | Saída `Consumo no periodo:`, `Periodo: MM/AAAA ate MM/AAAA`, `Consumo total: x.xx kWh` | p15 | saída | Caso 22 | T19, T22 |
| R-68 | Mês fora de 1 a 12: `Periodo invalido.` | p15 | saída | Casos 24 e 25 | T19, T21, T22 |
| R-69 | Período inicial posterior ao final: `Periodo invalido.` | p15 | saída | Caso 26 | T19, T21, T22 |
| R-70 | Opção 5 usa `encontrarUnidadeMaiorConsumo` | p15 | funcional | Revisão | T20, T22 |
| R-71 | Saída `Unidade com maior consumo:`, `Unidade:`, `Descricao:`, `Consumo total: x.xx kWh` | p15 | saída | Caso 27 | T20, T22 |
| R-72 | Opção 6: `Encerrando o programa.` e finaliza | p15 | saída | Caso 4 | T15, T22 |
| R-73 | Opção fora do intervalo: `Opcao invalida. Tente novamente.` e volta ao menu | p15-16 | saída | Casos 5 e 6 | T15, T21, T22 |
| R-74 | Código-fonte postado no Moodle | p16 | entrega | Comprovante de envio | T23 |
| R-75 | Nome e RA dos integrantes no cabeçalho de cada arquivo-fonte | p16 | entrega | Checklist de revisão | T01, T22, T23 |
| R-76 | Compila com `gcc -o main.exe *.c *.h` | p16 | restrição | CI em windows-latest | T00 |
| R-77 | Executa no Windows com `main.exe` | p16 | restrição | CI em windows-latest | T00 |
| R-78 | Não é necessário usar arquivos `.h` | p16 | restrição | Decisão registrada na task de CI | T00 |
| R-79 | Também pode ser executado no Dev-C++ ou no VS Code | p16 | restrição | C padrão, sem extensões de compilador | T01 |
| R-80 | Grupo de 2 a 3 componentes | p16 | entrega | README com a equipe | T00, T24 |
| R-81 | Entrega no Moodle até 18/11 (02P11) | p17 | entrega | Milestone M4 | T23 |
| R-82 | Apresentação de funcionamento em 19/11 (02P11) | p17 | avaliação | Milestone M5 | T24 |
| R-83 | Questionário prático individual em 26/11 (02P11) | p17 | avaliação | Milestone M5 | T24 |
| R-84 | Demonstração individual da aplicação funcionando: até 1 ponto | p16 | avaliação | Ensaio de cada pessoa | T24 |
| R-85 | Questionário com modificações no código: até 9 pontos | p16 | avaliação | Treino de modificações | T24 |
| R-86 | Cópia de outro projeto: projeto zerado e grupo sem questionário | p16 | avaliação | Código autoral, histórico no git | T23, T24 |
| R-87 | Não compila e não gera o executável: projeto zerado | p16 | avaliação | CI verde na tag `v1.0.0` | T00, T22 |
| R-88 | Projeto não entregue: zerado | p17 | avaliação | Comprovante de envio | T23 |
| R-89 | Demonstração individual não realizada: zero para o aluno, sem questionário | p17 | avaliação | Ensaio de cada pessoa | T24 |
| R-90 | Programa exige arquivo adicional que não está presente: -0,5 | p17 | avaliação | Pacote conferido | T23 |
| R-91 | Erros de compilação e/ou travamento na execução: -0,5 | p17 | avaliação | CI e casos de borda | T21, T22 |
| R-92 | Sem identificação do grupo no código-fonte: até -1,0 | p17 | avaliação | Cabeçalhos | T23 |
| R-93 | Arquivos enviados em formatos incorretos: até -1,0 | p17 | avaliação | Pacote conferido | T23 |
| R-94 | Arquivos ou pastas intermediárias da compilação enviados: até -1,0 | p17 | avaliação | Pacote sem `.exe`, `.o`, `.gch` ou pastas | T23 |
| R-95 | Só erros de compilação contam; warnings não são penalizados | p17, nota 1 | avaliação | CI falha só em erro | T00, T22 |

## Cobertura

R-01 a R-95: 95 de 95 cobertos por pelo menos uma tarefa.

Casos de teste correspondentes: [`tests/casos.md`](../tests/casos.md).
