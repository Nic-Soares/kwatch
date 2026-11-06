# Casos de teste

Uma linha por regra do enunciado. Para rodar, copie `leituras.txt` e `unidades.csv` da pasta de dados para a pasta do `main.exe`. Entrada são os valores digitados, um por linha (por exemplo `printf '1\n1\n6\n' | ./main.exe`). Casos marcados com **(dúvida)** dependem da resposta do professor.

Dados:
- `tests/pdf`: exemplo exato do PDF (p2). 5 leituras fora de ordem de ID; totais: 101 = 555.70, 203 = 391.50, 150 = 420.00; geral = 1367.20.
- `tests/borda`: 5 leituras fora de ordem (IDs 7, 2, 9, 1, 5); unidades 300 e 301 empatadas com 125.00 (a 301 aparece primeiro no arquivo); 302 com consumo 0.0; 303 cadastrada sem leituras e com descrição de exatamente 49 caracteres; leituras em 12/2025 e 01/2026.
- `tests/fumaca.txt`: entrada do teste de fumaça do CI (opção inválida e depois sair).

| # | Regra (R) | Dados | Entrada | Saída esperada |
|---|---|---|---|---|
| 1 | Arquivo de leituras não abre (R-13, R-44, R-45) | pasta sem `leituras.txt` | (nenhuma) | `Erro ao abrir o arquivo leituras.txt.` e `Encerrando o programa.`; o programa termina |
| 2 | Arquivo de unidades não abre (R-17, R-44, R-45) | pasta sem `unidades.csv` | (nenhuma) | mensagem de erro para `unidades.csv` e `Encerrando o programa.` **(dúvida)** |
| 3 | Menu após a carga (R-46) | pdf | `6` | menu idêntico ao da p12 |
| 4 | Sair (R-72) | pdf | `6` | `Encerrando o programa.`; o programa termina |
| 5 | Opção inválida volta ao menu (R-73) | pdf | `9`, `6` | `Opcao invalida. Tente novamente.`, menu de novo, `Encerrando o programa.` |
| 6 | Opção 0 também é inválida (R-73) | pdf | `0`, `6` | `Opcao invalida. Tente novamente.` |
| 7 | Bubble Sort mantém os arrays associados (R-24, R-26) | pdf | `1`, `1`, `6` | tabela da p13 (IDs 1 a 5, cada um com sua unidade, mês, ano e consumo) |
| 8 | Insertion Sort (R-24, R-28) | pdf | `1`, `2`, `6` | tabela da p13 |
| 9 | Selection Sort (R-24, R-30) | pdf | `1`, `3`, `6` | tabela da p13 |
| 10 | Quick Sort (R-24, R-32) | pdf | `1`, `4`, `6` | tabela da p13 |
| 11 | Merge Sort (R-24, R-34) | pdf | `1`, `5`, `6` | tabela da p13 |
| 12 | Ordenação com arquivo desordenado (R-04, R-24) | borda | `1`, `4`, `6` | linhas na ordem 1 (301, 12/2025, 74.50), 2 (301, 1/2026, 50.50), 5 (302, 2/2026, 0.00), 7 (300, 12/2025, 100.00), 9 (300, 1/2026, 25.00) |
| 13 | Segunda vez na opção 1 não pergunta o algoritmo (R-51) | pdf | `1`, `1`, `1`, `6` | na segunda vez, a tabela sai direto, sem o submenu |
| 14 | Busca linear encontra (R-21, R-59) | pdf | `2`, `3`, `1`, `6` | bloco `Leitura encontrada:` da p13 e p14 (unidade 101, mês 2, `Consumo: 310.20 kWh`) |
| 15 | Busca binária antes de ordenar (R-23, R-58) | pdf | `2`, `3`, `2`, `6` | mesmo bloco do caso 14 (o programa ordena antes) |
| 16 | Busca binária nas pontas (R-23) | pdf | `2`, `1`, `2`, `2`, `5`, `2`, `6` | leituras 1 e 5 encontradas |
| 17 | Leitura não encontrada (R-21, R-23, R-60) | pdf | `2`, `99`, `1`, `2`, `99`, `2`, `6` | mensagem da p14 **(dúvida: Leiura ou Leitura)** |
| 18 | Consumo de unidade (R-36, R-64) | pdf | `3`, `101`, `6` | `Consumo total: 555.70 kWh` com `Laboratorio de Informatica` |
| 19 | Unidade não cadastrada (R-62) | pdf | `3`, `999`, `6` | `Unidade nao encontrada.` |
| 20 | Unidade cadastrada sem leituras (R-36) | borda | `3`, `303`, `6` | `Consumo total: 0.00 kWh` **(dúvida)** |
| 21 | Descrição de 49 caracteres sem estourar (R-18) | borda | `3`, `303`, `6` | descrição completa `Unidade Sem Leituras Cadastrada Para Teste De Lim` |
| 22 | Consumo no período (R-38, R-67) | pdf | `4`, `1`, `2026`, `2`, `2026`, `6` | `Periodo: 01/2026 ate 02/2026` e `Consumo total: 1367.20 kWh` |
| 23 | Período que cruza o ano (R-38) | borda | `4`, `12`, `2025`, `1`, `2026`, `6` | `Consumo total: 250.00 kWh` |
| 24 | Mês fora de 1 a 12 (R-68) | pdf | `4`, `13`, `2026`, `2`, `2026`, `6` | `Periodo invalido.` |
| 25 | Mês 0 (R-68) | pdf | `4`, `1`, `2026`, `0`, `2026`, `6` | `Periodo invalido.` |
| 26 | Início posterior ao fim (R-69) | pdf | `4`, `3`, `2026`, `1`, `2026`, `6` | `Periodo invalido.` |
| 27 | Unidade de maior consumo (R-40, R-71) | pdf | `5`, `6` | `Unidade: 101`, `Laboratorio de Informatica`, `Consumo total: 555.70 kWh` |
| 28 | Empate: menor ID (R-41) | borda | `5`, `6` | `Unidade: 300`, `Laboratorio de Redes`, `Consumo total: 125.00 kWh` |
| 29 | Consumo zero conta como leitura (R-36) | borda | `3`, `302`, `6` | `Consumo total: 0.00 kWh` |
| 30 | Opção inválida no submenu de algoritmo (R-48, R-56) | pdf | `1`, `7`, `6` | **(dúvida)** sem travar |
| 31 | Entrada não numérica (R-91) | pdf | `a`, `6` | **(dúvida)** sem travar nem entrar em laço infinito |
