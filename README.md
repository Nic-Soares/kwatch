# kwatch

Sistema de Análise de Consumo de Energia em C (Projeto 2 de Algoritmos e Programação II, Universidade Presbiteriana Mackenzie, turma 02P11).

O programa carrega leituras de consumo (`leituras.txt`) e o cadastro de unidades (`unidades.csv`) em arrays paralelos (sem `struct`) e oferece um menu para listar leituras ordenadas por ID (5 algoritmos), buscar leitura por ID (linear ou binária), calcular o consumo de uma unidade, o consumo de um período e a unidade de maior consumo.

## Como compilar e executar

O programa abre `leituras.txt` e `unidades.csv` **da pasta onde ele é executado**. Por isso os comandos abaixo entram numa pasta de dados de teste antes de rodar.

### Windows (como o professor avalia, PDF p16)

No Prompt de Comando (`cmd`), na pasta do repositório:

```
gcc -o main.exe *.c *.h
cd tests\pdf
..\..\main.exe
```

O CI (`.github/workflows/build.yml`) compila exatamente com `gcc -o main.exe *.c *.h` em `windows-latest`. Sem nenhum `.h` na pasta, esse comando falha no Windows; o `kwatch.h` resolve.

### macOS e Linux

No Mac, o comando oficial falha (o `clang` não aceita `*.h` na lista). Use:

```
cd ~/Projects/kwatch
gcc -Wall -Wextra -o main *.c
cd tests/pdf
../../main
```

O executável `main` (e `main.exe`) está no `.gitignore` e não vai para o repositório.

### Dados de teste

| Pasta | O que tem | Para rodar (a partir de `tests/pdf`) |
|---|---|---|
| `tests/pdf` | o exemplo exato do PDF (p2): 5 leituras, unidades 101, 150 e 203 | `../../main` |
| `tests/borda` | casos de limite: empate entre 300 e 301, consumo 0, unidade sem leituras, descrição de 49 caracteres, período que cruza o ano | `cd ../borda && ../../main` |

### Roteiros de teste

Digite os números na ordem; `6` sai. Saídas esperadas completas em [`tests/casos.md`](tests/casos.md).

Com `tests/pdf`:

| Digite | Deve aparecer |
|---|---|
| `1`, `4` | tabela com os ids 1 a 5 em ordem; a linha 3 é `3 \| 101 \| Laboratorio de Informatica \| 2 \| 2026 \| 310.20` |
| `1` de novo | a tabela direto, sem o submenu |
| `2`, `3`, `2` | `Leitura encontrada:` e `Consumo: 310.20 kWh` |
| `2`, `99`, `1` | `Leiura nao encontrada.` |
| `3`, `101` | `Consumo total: 555.70 kWh` |
| `3`, `999` | `Unidade nao encontrada.` |
| `4`, `1`, `2026`, `2`, `2026` | `Periodo: 01/2026 ate 02/2026` e `Consumo total: 1367.20 kWh` |
| `4`, `3`, `2026`, `1`, `2026` | `Periodo invalido.` |
| `5` | `Unidade: 101` e `Consumo total: 555.70 kWh` |
| `9`, depois `a` | `Opcao invalida. Tente novamente.` nas duas vezes |
| `6` | `Encerrando o programa.` |

Com `tests/borda`:

| Digite | Deve aparecer |
|---|---|
| `5` | empate: `Unidade: 300`, `Laboratorio de Redes` (o menor número) |
| `3`, `303` | a descrição de 49 caracteres inteira e `Consumo total: 0.00 kWh` |
| `4`, `12`, `2025`, `1`, `2026` | `Consumo total: 250.00 kWh` |

Para rodar sem digitar, mande a entrada por um pipe (no Mac): `printf '1\n4\n6\n' | ../../main`.

## Formato dos arquivos de entrada (p1 e p2)

`leituras.txt`: uma leitura por linha, separada por espaços.

```
id unidade_id mes ano consumo
1 101 1 2026 245.5
```

`unidades.csv`: uma unidade por linha, separada por `;`. A descrição pode conter espaços.

```
id;descricao_da_unidade
101;Laboratorio de Informatica
```

## Organização

| Pasta ou arquivo | Conteúdo |
|---|---|
| raiz | código-fonte (o que vai para o Moodle) |
| `tests/` | dados de teste e casos de borda (não vai para o Moodle) |
| `docs/roadmap.md` | planejamento: marcos, tarefas e cronograma |
| `docs/requisitos.md` | matriz de requisitos do enunciado |
| `docs/duvidas.md` | perguntas para o professor |
| `CONTRIBUTING.md` | fluxo de branches, commits e revisão |

## Equipe

| Nome | RA | GitHub |
|---|---|---|
| Nicolas | 10370082 | [@Nic-Soares](https://github.com/Nic-Soares) |
| ______ | ______ | ______ |

O grupo tinha 3 integrantes: um desistiu e o outro está sem contato. Ver a situação e a divisão para 2 pessoas em [`docs/roadmap.md`](docs/roadmap.md).
