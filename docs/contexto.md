# Contexto do projeto

Respostas das tarefas T00a a T00c do [roadmap](roadmap.md), escritas com as próprias palavras. Cada item traz a pergunta (em citação) e a resposta logo abaixo. Onde houver □, a resposta ainda falta.

## T00a · Entender o problema e os dados (PDF p1 a p3)

### 1. O que o sistema faz

> Em uma frase: o que o sistema faz. Depois, as 5 perguntas que ele responde, em forma de pergunta, como o usuário faria.
>
> As perguntas saem das opções 1 a 5 do menu do programa (PDF p12). O menu é este:
>
> ```
> ===== SISTEMA DE ANALISE DE CONSUMO DE ENERGIA =====
> 1. Mostrar leituras ordenadas por ID
> 2. Buscar leitura por ID
> 3. Calcular consumo de uma unidade
> 4. Calcular consumo em um periodo
> 5. Identificar unidade com maior consumo
> 6. Sair da aplicacao
> ```
>
> Cada opção vira uma pergunta. A opção 6 só encerra o programa, então não entra.
>
> | Opção do menu | Vira a pergunta |
> |---|---|
> | 1. Mostrar leituras ordenadas por ID | Quais são todas as leituras, em ordem de ID? |
> | 2. Buscar leitura por ID | Qual são as informações especificas da leitura de ID x? (unidade, mês, ano, consumo) |
> | 3. Calcular consumo de uma unidade | Soma o consumo total de uma unidade inteira |
> | 4. Calcular consumo em um periodo | Soma o consumo total de todas as unidades, dentro de um periodo pré estabelecido |
> | 5. Identificar unidade com maior consumo | Soma o consumo por unidade, e compara qual é a maior em consumo, trazendo essa informação |

É um Sistema de Análise de Consumo de Energia elétrica, realiza a leitura de medições de uso de energia de um arquivo, e ajuda a responder perguntas sobre, e relaciona com os lugares que realizaram o gasto.

Perguntas que o sistema responde:

1. Quais são todas as leituras, em ordem de ID?
2. Qual são as informações especificas da leitura de ID x? (unidade, mês, ano, consumo)
3. Qual o consumo total de uma unidade inteira?
4. Qual o consumo total de todas as unidades, dentro de um periodo pré estabelecido?
5. Qual é a maior unidade em consumo?

### 2. Leitura e unidade

> O que é uma leitura, o que é uma unidade, e como o `unidade_id` liga os dois arquivos.

Uma unidade é um setor da instituição que gasta energia, por exemplo 101, Laboratorio de Informatica.

Uma leitura é uma medição de gasto de energia, vinculado a uma unidade, o mês e ano em que foi feito, e quanto foi gasto, em kWh.

O unidade_id liga os dois arquivos assim: a unidade_id é a chave principal de unidades.csv, e chave estrangeria em leituras.txt que vincula as duas bases, possibilitanto vincular a leitura de energia com uma unidade.

#### Exemplo: achar a unidade de uma leitura

Linha: `5 203 2 2026 205.8`

| Passo | Pergunta | Resposta |
|---|---|---|
| 1 | Qual é o unidade_id desta leitura? | 203 |
| 2 | Qual linha do unidades.csv começa com esse número? | 2 |
| 3 | Qual é a descrição? | Biblioteca Central |

Frase final: A leitura 5 é do(a) Biblioteca Central no mês 2 de 2026 e gastou 205.8 kWh.

### 3. Os separadores

> Por que `unidades.csv` separa os campos por `;` e `leituras.txt` separa por espaço? (PDF p2)

Isso acontece porque em unidades existe células que abrigam conteudo (texto) que possuem espaço com parte da informação da célula, exemplo "Setor Administrativo", Setor e Administrativo não sao celulas diferentes e sim uma só. Isso não existe em leituras, logo lá pode ser separado por espaço.

### 4. Os dados nos arrays

> Montar na mão, com o exemplo da p2 e na ordem do arquivo, as tabelas `i | ids[i] | unidadeIds[i] | meses[i] | anos[i] | consumos[i]` e `j | unidadeIdsCatalogo[j] | descricoes[j]` (PDF p3).
>
> Esta é a memória do programa depois da carga: o que `carregarLeituras` e `carregarUnidades` têm que produzir (T02, T03). A coluna `i` (posição) não existe no arquivo: é o número da linha contando a partir de 0. A 1ª linha (posição 0) já está preenchida como modelo.

**Leituras** (`leituras.txt`)

| i | ids[i] | unidadeIds[i] | meses[i] | anos[i] | consumos[i] |
|---|--------|---------------|----------|---------|-------------|
| 0 | 1 | 101 | 1 | 2026 | 245.5 |
| 1 | 3 | 101 | 2 | 2026 | 310.2 |
| 2 | 2 | 203 | 1 | 2026 | 185.7 |
| 3 | 4 | 150 | 2 | 2026 | 420.0 |
| 4 | 5 | 150 | 2 | 2026 | 205.8 |

**Unidades** (`unidades.csv`)

| j | unidadeIdsCatalogo[j] | descricoes[j] |
|---|-----------------------|---------------|
| 0 | 101 | Laboratorio de Informatica |
| 1 | 203 | Biblioteca Central |
| 2 | 150 | Bloco Administrativo |

### 5. Posição × valor

**a) Em que posição está a leitura de ID 3?**

A leitura de ID 3 esta na posição 1 da tabela de leitura.

**b) Qual é a descrição da unidade da leitura na posição 4?**

Biblioteca Central

**c) Por que `descricoes` tem 50 posições se o nome tem no máximo 49 letras?**

> O PDF declara `char descricoes[MAX][50];` (p3) e diz que a descrição tem "até 49 caracteres" (p5). Em C, todo texto termina com um caractere a mais, o `'\0'`, que marca onde o texto acaba. Exemplo: "Bloco" tem 5 letras e ocupa 6 posições (5 letras + o `'\0'`).

Porque em C as coisas começar com indece 0 a n - 1, nesse caso de 0 a 49, de 0 a 48 dá 49 chars, e apois isso 49 fica como  '\0', e toda string preciso disso pra dizer "esse texto acaba aqui"
