# Dúvidas para o professor

Ambiguidades encontradas no enunciado. Ao receber a resposta, anote em **Resposta** e ajuste as tarefas afetadas do [roadmap](roadmap.md).

| D | Pergunta | PDF | Requisitos | Prioridade | Resposta |
|---|---|---|---|---|---|
| D1 | O grupo tinha 3 integrantes; um desistiu e o outro está sem contato. O enunciado pede grupos de 2 a 3 (p16). Posso entregar sozinho? Como ficam a demonstração e o questionário individuais? | p16 | R-80 | alta | |
| D2 | O comando é `gcc -o main.exe *.c *.h`, mas o PDF diz que `.h` não é necessário. No GCC 15.2 (MinGW) do Windows, sem nenhum `.h` dá `cc1.exe: fatal error: *.h: Invalid argument`. Posso entregar um `kwatch.h` com os protótipos? | p16 | R-76, R-78 | alta | |
| D3 | Quick e merge documentam "n: número de elementos", mas a assinatura tem `inicio` e `fim`. A chamada é `(0, n-1)`, com `fim` inclusivo? | p8, p9 | R-31, R-33 | média | |
| D4 | A descrição de `calcularConsumoPeriodo` repete "de uma determinada unidade". Ela soma todas as unidades no período? Os meses inicial e final são incluídos? | p10 | R-38 | média | |
| D5 | A mensagem é `Leiura nao encontrada.`. Reproduzo exatamente ou escrevo `Leitura nao encontrada.`? | p14 | R-60 | média | |
| D6 | A tabela da opção 1 precisa de colunas alinhadas ou basta separar com ` \| `? (o separador tem 71 hífens) | p13 | R-52, R-53 | baixa | |
| D7 | Em `Periodo: 01/2026 ate 02/2026`, o mês sempre tem 2 dígitos? | p15 | R-67 | baixa | |
| D8 | O que fazer com uma opção inválida nos submenus de ordenação e de busca? | p12, p13 | R-48, R-56 | média | |
| D9 | Se a busca binária precisar ordenar antes, com qual algoritmo? Depois disso, a opção 1 ainda pergunta o algoritmo na "primeira vez"? | p13 | R-51, R-58 | média | |
| D10 | O que as funções de carga fazem com mais linhas que `max`, linhas mal formatadas, descrição com mais de 49 caracteres ou arquivo vazio? | p4, p5 | R-14, R-18, R-19 | média | |
| D11 | Se `unidades.csv` não abrir, a mensagem é `Erro ao abrir o arquivo unidades.csv.` seguida de `Encerrando o programa.`? | p12 | R-44, R-45 | baixa | |
| D12 | Opção 3 com unidade cadastrada sem leituras mostra `Consumo total: 0.00 kWh`? E a opção 5 sem nenhuma leitura? | p14, p15 | R-62, R-64, R-71 | baixa | |
| D13 | O que vai no Moodle: só `.c` e `.h` ou também `leituras.txt` e `unidades.csv` (o PDF desconta 0,5 se faltar arquivo)? Arquivos soltos ou `.zip`? Qual é o "formato incorreto"? | p16, p17 | R-74, R-90, R-93 | alta | |
| D14 | Os títulos "carregarLeitura" e "quickLeituraPorId" diferem das assinaturas `carregarLeituras` e `quickSortLeituraPorId`. Vale a assinatura? | p4, p8 | R-11, R-31 | baixa | |
| D15 | "Não compila e não gera o executável" zera, mas "Há erros de compilação" desconta 0,5. Qual é a diferença? | p16, p17 | R-87, R-91 | média | |
| D16 | Os arrays podem ser globais ou devem ser locais no `main`, passados por parâmetro? | p3 | R-08, R-10 | baixa | |
| D17 | Se o usuário digitar letras no menu, no ID ou no período, o que o programa deve fazer? (travar desconta 0,5) | p12 a p15 | R-73, R-91 | média | |
