# 🔄 push_swap

> push_swap é uma implementação em C que tem como objetivo ordenar uma pilha de números inteiros com o menor número possível de operações.
> O programa utiliza um conjunto limitado de instruções para manipular duas pilhas — A e B — simulando o comportamento de algoritmos de ordenação otimizados sob fortes restrições.
> Ele recebe como argumento uma lista de números e exibe, na saída padrão, a sequência de operações necessárias para ordená-los.

> ```bash
> ./push_swap 2 1 3 6 5 8
> # Exemplo de saída:
> sa
> pb
> ra
> pa
> ```

> Este projeto aprofunda conceitos de estruturas de dados, complexidade algorítmica, sorting algorithms, análise de performance e otimização de instruções.


![Banner](https://img.shields.io/badge/Project-push_swap-blueviolet) ![C](https://img.shields.io/badge/Language-C-red) ![License](https://img.shields.io/badge/License-MIT-green)

---

## 🎯 Objetivo  

O objetivo do projeto **push_swap** é criar um **programa capaz de ordenar uma lista de números inteiros** utilizando o **menor número possível de instruções**, dentro de um conjunto de operações pré-definidas.  

A ordenação deve ser feita **sem utilizar funções prontas** (como `qsort()`), apenas manipulando **duas pilhas** — chamadas **A** e **B** — através de operações como:  
- **swap** (`sa`, `sb`, `ss`): troca os dois primeiros elementos do topo de uma ou ambas as pilhas;  
- **push** (`pa`, `pb`): move o elemento do topo de uma pilha para a outra;  
- **rotate** (`ra`, `rb`, `rr`): move o primeiro elemento da pilha para o final;  
- **reverse rotate** (`rra`, `rrb`, `rrr`): move o último elemento da pilha para o topo.  

O desafio está em **implementar um algoritmo de ordenação eficiente** que use essas instruções da forma mais **otimizada possível**, respeitando as restrições de desempenho impostas pela 42.  

Além de desenvolver a lógica de ordenação, o projeto exige:
- **Criação e manipulação de estruturas de dados dinâmicas** (listas encadeadas);  
- **Análise de complexidade de algoritmos** (tempo e número de operações);  
- **Otimização de movimentos** para listas pequenas (até 5 elementos) e grandes (até 500 elementos);  
- **Organização de código modular e limpo**, seguindo boas práticas de programação em C.

Em suma, o **push_swap** testa a capacidade de projetar e implementar **um algoritmo inteligente de sorting sob fortes restrições**, equilibrando **eficiência, precisão e clareza de código**.

---

## 💻 Como usar  

#### 📦 Compilação com Makefile  

Para compilar o projeto, basta rodar no terminal:  

```bash
make
```
Isso irá compilar todos os arquivos e gerar o executável `push_swap`.

#### ♻️ Outros comandos úteis

`make re` — recompila o projeto do zero (executa fclean e depois all)

`make clean` — remove os arquivos objeto .o

`make fclean` — remove os arquivos objeto e o executável

`make bonus` — compila todos os arquivo do bonus gerando o excutável `checker`

#### ▶️ Execução
O programa recebe como argumentos uma sequência de números inteiros a serem ordenados:

```bash
./push_swap 2 1 3 6 5 8
```
Ele exibirá na saída padrão a sequência de instruções necessárias para ordenar os números:
```bash
sa
pb
ra
pa
```
Essas instruções representam as operações realizadas entre as pilhas **A** e **B** durante o processo de ordenação.

#### 🧪 Testando com o checker (opcional)

Para verificar se a sequência de instruções está correta, use o programa checker (fornecido pela 42 ou implementado separadamente):
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

OK # se a pilha A estiver ordenada e B vazia.

KO # se não estiver ordenada.
```

#### ⚙️ Exemplo prático
```bash
ARG="5 2 3 1 4"
./push_swap $ARG
```
Saída esperada (pode variar conforme a estratégia de ordenação):
```bash
pb
pb
sa
pa
pa
ra
```

---

## ⚙️ Funcionalidades  

O projeto **push_swap** é dividido em duas partes principais:  
a **obrigatória**, que gera a sequência de operações para ordenar uma pilha,  
e a **bônus**, que implementa um **verificador (`checker`)** capaz de testar essa sequência.

### 🧩 Parte obrigatória — `push_swap`

O programa `push_swap` recebe uma lista de números inteiros e deve:  
1. **Verificar os argumentos** (números válidos, sem duplicatas, dentro dos limites de `int`);  
2. **Inicializar duas pilhas** — `A` (com os números) e `B` (vazia);  
3. **Calcular a sequência mínima de instruções** para ordenar `A` em ordem crescente;  
4. **Exibir as instruções** na saída padrão (`stdout`), **sem mostrar a pilha em si**.

Exemplo:  
```bash
./push_swap 3 2 1
sa
rra
```

#### 🧠 Parte bônus — checker

O checker tem a função de verificar se uma sequência de instruções realmente ordena a pilha.
Ele não calcula as instruções — apenas lê e executa as operações simulando o comportamento real das pilhas.

🧾 Modo de uso
```
ARG="4 3 2 1"; ./push_swap $ARG | ./checker $ARG
```
-  O push_swap gera as instruções de ordenação.
- O checker lê essas instruções da entrada padrão e as aplica.
- No final, ele imprime:
  - ✅ OK — se a pilha A estiver ordenada e a pilha B vazia;
  - ❌ KO — se não estiver ordenada;
  - ⚠️ Error — se uma instrução inválida for recebida ou houver erro nos argumentos.

🧪 Testes e uso manual

Também é possível testar manualmente:
```bash
./checker 3 2 1
sa
rra
^D
```
> (`Ctrl + D` encerra a leitura de instruções)
Saída esperada:
```bash
OK
```
O bônus do push_swap é essencial para validar a eficiência e correção do algoritmo,
permitindo testar qualquer sequência de movimentos de forma automática e confiável.

---

## 📚 Conceitos e Estratégia de Ordenação  

O **push_swap** exige a criação de um algoritmo de ordenação **altamente otimizado**, usando apenas as instruções permitidas e duas pilhas.  
No meu caso, foi implementada uma variação do [**Algoritmo Turk**](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0 "Push_Swap Turk algorithm explained"), uma abordagem eficiente e bastante popular entre os projetos da 42.  

---

### ⚙️ Lógica geral do algoritmo  

1. **Divisão inicial**  
   - Todos os números são movidos da **stack A** para a **stack B**, até que restem apenas **3 elementos** em A.  
   - A pilha A é então **ordenada diretamente**, pois ordenar 3 elementos é simples e rápido com poucas operações (`sa`, `ra`, `rra`).  

2. **Cálculo de custos**  
   - Para cada número presente em **B**, é calculado o **custo de inserção** na pilha A.  
   - Esse cálculo considera:
     - 🔹 **Custo de movimentação em B:** número de rotações necessárias para trazer o elemento até o topo.  
     - 🔹 **Custo de movimentação em A:** rotações necessárias para posicionar o local correto de inserção.  
     - 🔹 **Custo total:** soma (ou combinação) dos custos de A e B.  

3. **Inserção otimizada**  
   - O elemento com o **menor custo total** é escolhido e **movido para A** na posição ideal, garantindo o menor número de operações possível.  
   - Esse processo é repetido até que **toda a pilha B esteja vazia**.  

4. **Rotação final**  
   - Quando todos os elementos voltam para A, é feita uma **rotação final** (`ra` ou `rra`) para alinhar o menor elemento no topo,  
     deixando a pilha completamente ordenada.  

---

### 🧠 Conceitos trabalhados  

- **Estruturas de dados dinâmicas:** uso de listas encadeadas para representar as pilhas e facilitar inserções e rotações.  
- **Cálculo de custo algorítmico:** avaliação em tempo real do custo de cada movimento possível.  
- **Otimização local e global:** escolha da operação mais vantajosa a cada passo para reduzir o total de instruções.  
- **Manipulação de pilhas e ponteiros:** implementação manual das operações `push`, `swap`, `rotate` e `reverse rotate`.  
- **Análise de complexidade:** equilíbrio entre custo de tempo e número de movimentos.  
- **Ordenação híbrida:** combinação de uma ordenação simples (para 3 elementos) com realocação inteligente via cálculo de custos.

Essa estratégia garante uma **alta eficiência mesmo em grandes conjuntos de dados**,  
atingindo uma quantidade de operações competitiva dentro dos limites exigidos pelo projeto.

---

## 🔍 Exemplo prático — funcionamento passo a passo  
> Caso queria um exemplo mais vizual como um mapa mental  de como funciona dentro do projeto. [clique aqui](https://excalidraw.com/#json=AQL8ZJ4V2p_w6g-0uoJ2i,URdE0B782kXLA2irWgS5gw "Mapa mental")

A seguir, um exemplo com **10 números**, demonstrando o funcionamento do algoritmo **Turk** utilizado no projeto.  

```yaml
A: [8, 3, 7, 1, 5, 2, 9, 4, 6, 10]
B: []
```

---

### 🧩 Etapa 1 — Envio de elementos para B  

Todos os números, exceto 3, são enviados para a pilha **B**,  
deixando apenas **3 elementos em A** para uma ordenação direta.  
```yaml
A: [8, 3, 7]
B: [10, 6, 4, 9, 2, 5, 1]
```

Agora, **A é ordenada** com operações simples (`sa`, `ra`, `rra`):  
```yaml
A: [3, 7, 8] ✅
B: [10, 6, 4, 9, 2, 5, 1]
```

---

### ⚙️ Etapa 2 — Cálculo dos custos  

Para cada elemento em **B**, o algoritmo calcula:  
- o **custo em B** para trazê-lo ao topo;  
- o **custo em A** para posicionar corretamente o elemento;  
- o **custo total**, que define o movimento mais vantajoso.  

| Elemento | Custo em B | Custo em A | Total |  
|:---------:|:-----------:|:-----------:|:------:|  
| 10 | 0 | 1 | 1 ✅ |  
| 6 | 1 | 2 | 3 |  
| 4 | 2 | 1 | 3 |  
| 9 | 3 | 2 | 5 |  
| 2 | 4 | 1 | 5 |  
| 5 | 5 | 2 | 7 |  
| 1 | 6 | 0 | 6 |

O **10** tem o menor custo total, então ele é o primeiro a ser movido para A.

---

### 🔄 Etapa 3 — Inserção otimizada  

O 10 é colocado no topo correto de A:  
```yaml
A: [3, 7, 8, 10]
B: [6, 4, 9, 2, 5, 1]
```

Recalcula-se os custos para os próximos elementos.  
O **6** agora é o mais barato e vai para A:  
```yaml
A: [3, 6, 7, 8, 10]
B: [4, 9, 2, 5, 1]
```

Depois o **4**:  
```yaml
B: [9, 2, 5, 1]
A: [3, 4, 6, 7, 8, 10]
```

O processo continua até todos os elementos de **B** serem reinseridos:  
```yaml
A: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
B: []
```

---

### 🔁 Etapa 4 — Rotação final  

Por fim, o menor elemento é colocado no topo (se necessário),  
garantindo que **A esteja completamente ordenada** e **B vazia**.  
```yaml
A: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 🎯
B: []
```
---

✨ **Resultado final:**  
A pilha **A** está perfeitamente ordenada em **ordem crescente**,  
a pilha **B** está **vazia**, e o número total de operações foi **otimizado**  
graças ao cálculo dinâmico de custos e à inserção inteligente.

---
## 📂 Arquivos

```bash
push_swap/
├── 📁 include/              # Headers (.h) do projeto
│   └── *.h
│
├── 📁 libft/                # Biblioteca pessoal usada no projeto
│   └── *.c
│
├── 📁 srcs/                 # Arquivos principais do push_swap
│   ├── calc_cost.c          # Calcula o custo de mover elementos entre stacks
│   ├── ft_push.c            # Implementação das operações de push
│   ├── ft_reverse_rotate.c  # Implementação das operações de reverse rotate
│   ├── ft_rotate.c          # Implementação das operações de rotate
│   ├── ft_sort.c            # Funções principais de ordenação
│   ├── ft_sort_2.c          # Funções auxiliares de ordenação
│   ├── ft_swap.c            # Implementação das operações de swap
│   ├── lst.c                # Manipulação de listas (nós, inicialização, etc)
│   ├── main.c               # Função principal do programa
│   ├── parse.c              # Parsing e verificação dos argumentos
│   ├── utils.c              # Funções utilitárias gerais
│   └── utils2.c             # Funções utilitárias complementares
│
├── 📁 srcs_bonus/           # Código bônus (checker, etc)
│   └── *.c
│
├── ⚙️ .gitignore            # Arquivos ignorados pelo Git
└── 🧩 Makefile              # Script de compilação do projeto
```

---

## 💭 Considerações e Dicas

Esse projeto foi um grande aprendizado sobre **algoritmos de ordenação**, **análise de complexidade**, **manipulação de pilhas**, e principalmente sobre como **pensar em otimizações**.

Durante o desenvolvimento, o maior desafio foi encontrar um equilíbrio entre **performance e legibilidade**. Testar diferentes abordagens até chegar em um algoritmo eficiente (no caso, o *Turk Algorithm*) ajudou muito a entender como pequenas decisões impactam o número total de movimentos.

A parte **bônus (Checker)** também foi essencial para consolidar o entendimento da lógica do programa. Ela me forçou a pensar em como validar as operações do *push_swap*, garantindo que o programa realmente ordene corretamente e respeite as regras do projeto.

### ⚙️ Dicas para quem for fazer o projeto:
- 🧩 **Entenda bem as operações básicas** antes de tentar otimizar — saber exatamente o que cada comando faz facilita tudo.  
- 🔁 **Simule manualmente com poucos números** (como 3, 5 ou 10) para enxergar o comportamento das pilhas.  
- 📊 **Use printfs estratégicos** (ou logs) pra entender o fluxo do algoritmo e corrigir erros lógicos.  
- 💡 **Pense em custo-benefício**: mover um número pode parecer bom isoladamente, mas o impacto total importa mais.  
- 🧠 **Implemente o Checker** — ele é uma ótima ferramenta pra testar sua lógica e garantir que tudo funcione como esperado.  
- 🪶 **Não complique demais no início** — faça funcionar primeiro, depois melhore a eficiência.  
- 🧷 **Estude algoritmos de ordenação** (insertion, selection, radix, quicksort) — todos têm ideias que podem ser adaptadas.

> ✨ *No fim, o Push Swap é mais do que ordenar números — é sobre aprender a pensar como um engenheiro de software, escrevendo código eficiente, modular e inteligente.*


---

## 👩‍💻 Autoria

**✨ Amy Rodrigues ✨** 

🎓 Estudante de C e desenvolvimento de baixo nível na [42 São Paulo](https://www.42sp.org.br/)

🐧 Usuária de Linux | 💻 Fã de terminal | 🎯 Apaixonada por entender como tudo funciona por trás dos bastidores

---

## 📎 Licença

Este projeto foi desenvolvido como parte do currículo educacional da 42 São Paulo.

📘 **Uso permitido**:
- Pode ser utilizado como referência para estudos e aprendizado individual
- Pode servir de inspiração para seus próprios projetos

🚫 **Proibido**:
- Submeter cópias deste projeto como se fossem de sua autoria em avaliações da 42 ou outras instituições

Seja ético e contribua para uma comunidade de desenvolvedores mais honesta e colaborativa 🤝
