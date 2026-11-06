# kwatch

Sistema de Análise de Consumo de Energia em C (Projeto 2 de Algoritmos e Programação II, Universidade Presbiteriana Mackenzie, turma 02P11).

O programa carrega leituras de consumo (`leituras.txt`) e o cadastro de unidades (`unidades.csv`) em arrays paralelos (sem `struct`) e oferece um menu para listar leituras ordenadas por ID (5 algoritmos), buscar leitura por ID (linear ou binária), calcular o consumo de uma unidade, o consumo de um período e a unidade de maior consumo.

## Como compilar e executar (comandos do enunciado, p16)

```
gcc -o main.exe *.c *.h
main.exe
```

O programa é avaliado no Windows. O CI (`.github/workflows/build.yml`) compila exatamente com esse comando em `windows-latest`.

Os arquivos `leituras.txt` e `unidades.csv` devem estar na mesma pasta do executável. Para testar localmente, copie os do exemplo do PDF:

```
copy tests\pdf\leituras.txt .
copy tests\pdf\unidades.csv .
```

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
