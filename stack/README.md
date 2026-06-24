# Pilha em C

Implementação de uma **pilha (Stack)** em C utilizando uma estrutura encadeada, desenvolvida com o objetivo de estudar estruturas de dados, ponteiros, alocação dinâmica de memória e o comportamento da estratégia **LIFO (Last In, First Out)**.

## Funcionalidades

* Inicialização da pilha (`createStack`)
* Inserção de elementos no topo (`push`)
* Remoção de elementos do topo (`pop`)
* Verificação do elemento no topo (`peek`)
* Verificação se a pilha está vazia (`isEmpty`)
* Impressão da pilha (`printStack`)
* Impressão detalhada de um nó (`printCell`)
* Liberação de toda a memória alocada (`freeStack`)

---

## Estrutura do Projeto

```text
stack-c/
├── src/
│   ├── stack.h
│   ├── stack.c
│   └── main.c
│
├── Makefile
└── README.md
```

---

## Compilação

Para compilar o projeto:

```bash
make
```

Para executar:

```bash
make run
```

Para remover os arquivos gerados:

```bash
make clean
```

---

## Exemplo de Uso

```c
Stack *stack = createStack();

push(stack, 10);
push(stack, 20);
push(stack, 30);

printStack(stack);

pop(stack);

printStack(stack);
```

Saída:

```text
 TOP
  ↓

+----+
 30
+----+
  ↓

+----+
 20
+----+
  ↓

+----+
 10
+----+
  ↓

 NULL

stack size: 3
```

Após o `pop`:

```text
 TOP
  ↓

+----+
 20
+----+
  ↓

+----+
 10
+----+
  ↓

 NULL

stack size: 2
```

---

## Complexidade das Operações

| Operação   | Complexidade |
| ---------- | ------------ |
| push       | O(1)         |
| pop        | O(1)         |
| peek       | O(1)         |
| isEmpty    | O(1)         |
| printStack | O(n)         |

---

## Conceitos Praticados

* Ponteiros
* Estruturas (`struct`)
* Ponteiros para estruturas
* Alocação dinâmica de memória (`malloc`)
* Liberação de memória (`free`)
* Manipulação de nós encadeados
* Tratamento de ponteiros nulos (`NULL`)
* Implementação da estratégia LIFO
* Gerenciamento manual de memória
* Análise de complexidade de algoritmos

---

## Como a Estrutura Funciona

A pilha mantém um ponteiro para o elemento do topo. Cada novo elemento inserido passa a ser o novo topo da estrutura.

```text
TOP
 ↓
+----+     +----+     +----+
| 30 | --> | 20 | --> | 10 |
+----+     +----+     +----+
```

Quando um elemento é removido, o topo passa a apontar para o próximo nó da sequência.

---

## Objetivo do Projeto

Este projeto faz parte de uma trilha de estudos em Estruturas de Dados utilizando a linguagem C. O foco é compreender o funcionamento interno de estruturas dinâmicas, praticar o gerenciamento manual de memória e consolidar conceitos fundamentais para estruturas mais avançadas, como filas, listas duplamente encadeadas, árvores, tabelas hash e grafos.
