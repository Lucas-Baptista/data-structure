# Fila em C

Implementação de uma **fila (Queue)** em C utilizando uma estrutura encadeada, desenvolvida com o objetivo de estudar estruturas de dados, ponteiros, alocação dinâmica de memória e o comportamento da estratégia **FIFO (First In, First Out)**.

## Funcionalidades

* Inicialização da fila (`initQueue`)
* Inserção de elementos no final da fila (`enqueue`)
* Remoção de elementos do início da fila (`dequeue`)
* Consulta ao primeiro elemento (`front`)
* Consulta ao último elemento (`rear`)
* Verificação se a fila está vazia (`isEmpty`)
* Consulta da quantidade de elementos (`size`)
* Impressão da fila (`printQueue`)
* Impressão detalhada de um nó (`printNode`)
* Liberação de toda a memória alocada (`freeQueue`)

---

## Estrutura do Projeto

```text
queue-c/
├── src/
│   ├── queue.h
│   ├── queue.c
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
Queue *queue = initQueue();

enqueue(queue, 10);
enqueue(queue, 20);
enqueue(queue, 30);

printQueue(queue);

dequeue(queue);

printQueue(queue);
```

Saída:

```text
 Front
  ↓

+----+
 10
+----+
  ↓

+----+
 20
+----+
  ↓

+----+
 30
+----+
  ↑
 Rear

queue size: 3
```

Após o `dequeue`:

```text
 Front
  ↓

+----+
 20
+----+
  ↓

+----+
 30
+----+
  ↑
 Rear

queue size: 2
```

---

## Complexidade das Operações

| Operação   | Complexidade |
| ---------- | ------------ |
| enqueue    | O(1)         |
| dequeue    | O(1)         |
| front      | O(1)         |
| rear       | O(1)         |
| isEmpty    | O(1)         |
| size       | O(1)         |
| printQueue | O(n)         |

---

## Conceitos Praticados

* Ponteiros
* Estruturas (`struct`)
* Ponteiros para estruturas
* Alocação dinâmica de memória (`malloc`)
* Liberação de memória (`free`)
* Manipulação de nós encadeados
* Tratamento de ponteiros nulos (`NULL`)
* Implementação da estratégia FIFO
* Gerenciamento manual de memória
* Manutenção de ponteiros para início e fim da fila
* Análise de complexidade de algoritmos

---

## Como a Estrutura Funciona

A fila mantém dois ponteiros:

* **Front**, que aponta para o primeiro elemento da fila.
* **Rear**, que aponta para o último elemento da fila.

Novos elementos são inseridos sempre no final (**Rear**) e removidos sempre do início (**Front**), seguindo a estratégia **FIFO (First In, First Out)**.

```text
Front
 ↓
+----+     +----+     +----+
| 10 | --> | 20 | --> | 30 |
+----+     +----+     +----+
                           ↑
                         Rear
```

Após um `dequeue`, o ponteiro **Front** passa a apontar para o próximo elemento da fila.

---

## Objetivo do Projeto

Este projeto faz parte de uma trilha de estudos em Estruturas de Dados utilizando a linguagem C. O foco é compreender o funcionamento interno de estruturas dinâmicas, praticar o gerenciamento manual de memória e consolidar conceitos fundamentais para estruturas mais avançadas, como listas duplamente encadeadas, árvores, tabelas hash e grafos.
