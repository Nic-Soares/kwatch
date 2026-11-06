# Como contribuir

O planejamento fica em [`docs/roadmap.md`](docs/roadmap.md): cada tarefa tem um código (T01, T02...). Não usamos issues nem GitHub Projects.

## Fluxo de branches

- `main`: só código entregável. Recebe apenas PR vindo de `develop`. Protegida: exige PR e CI verde.
- `develop`: integração e branch default. Protegida: exige PR e CI verde (com 2 pessoas, também 1 aprovação do outro integrante).
- Trabalho: sempre a partir de `develop`, com o código da tarefa:
  - `feat/T05-busca-binaria` (funcionalidade)
  - `fix/T19-periodo-invalido` (correção)
  - `docs/T00-roadmap` (documentação)
  - `chore/T00-ci` (infraestrutura)
- Treino para o questionário: `treino/<nome>`. Nunca abra PR dessas branches.
- Merge por squash; a branch é apagada após o merge.
- Ao concluir, marque a tarefa como `[x]` em `docs/roadmap.md` no mesmo PR.

```
git checkout develop && git pull
git checkout -b feat/T05-busca-binaria
# ... commits ...
git push -u origin feat/T05-busca-binaria
gh pr create --base develop
```

## Commits (Conventional Commits, em português)

```
feat(busca): implementa busca binária (T05)
fix(menu): corrige mensagem de período inválido (T19)
docs: atualiza roadmap
chore(ci): adiciona teste de fumaça
```

Tipos: `feat`, `fix`, `docs`, `test`, `refactor`, `chore`. Escopos: `carga`, `busca`, `ordenacao`, `analise`, `menu`, `ci`.

## Definição de pronto de uma tarefa

- [ ] Compila sem erros com `gcc -o main.exe *.c *.h` (CI verde)
- [ ] Testada com os casos indicados no roadmap e em `tests/casos.md`
- [ ] Saída idêntica à do PDF, quando houver saída
- [ ] Checklist de revisão abaixo conferido (com 2 pessoas: aprovada pelo outro integrante)
- [ ] Tarefa marcada como `[x]` no roadmap

## Checklist de revisão (tirada do enunciado)

- [ ] Assinatura da função idêntica à do PDF (nome, tipos, ordem dos parâmetros)
- [ ] Arrays paralelos, sem `struct` (PDF p3)
- [ ] Em toda ordenação, os 5 arrays (`ids`, `unidadeIds`, `meses`, `anos`, `consumos`) são trocados juntos (PDF p7 e p13)
- [ ] Texto de saída idêntico ao PDF, consumo com 2 casas decimais
- [ ] Nome e RA dos integrantes no cabeçalho de cada arquivo-fonte (PDF p16)
- [ ] Nada que faça o programa travar (PDF p17: -0,5)

Cabeçalho de cada arquivo-fonte:

```c
/*
 * kwatch - Projeto 2 (Algoritmos e Programação II, turma 02P11)
 * Nicolas, RA 10370082
 */
```

## Código autoral

O PDF zera projetos copiados (p16). Todo o código deve ser escrito pelo grupo, e cada integrante precisa entendê-lo por inteiro: o questionário individual pede modificações no código.

## Pacote de entrega (Moodle)

O pacote sai da tag `v1.0.0` em `main` e contém só os arquivos-fonte da raiz, sem `.github/`, `tests/`, `docs/`, executáveis ou pastas de compilação (o PDF desconta até 1,0 ponto, p17). Se os arquivos de dados vão junto depende da resposta do professor (dúvida D13 em [`docs/duvidas.md`](docs/duvidas.md)).

```
git fetch --tags
mkdir entrega
git archive v1.0.0 $(git ls-tree --name-only v1.0.0 | grep -E '\.(c|h)$') | tar -x -C entrega
```

Antes de postar, compile a pasta `entrega` sozinha com `gcc -o main.exe *.c *.h` e apague o `main.exe` gerado.
