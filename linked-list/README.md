# Lista Encadeada em C

Implementação de uma **lista simplesmente encadeada (Singly Linked List)** em C, desenvolvida com o objetivo de estudar estruturas de dados, ponteiros, alocação dinâmica de memória e análise de complexidade.

## Funcionalidades

* Inicialização da lista
* Inserção no início (`pushFront`)
* Inserção no final (`pushBack`)
* Inserção em uma posição específica (`insertAt`)
* Remoção de um elemento por valor (`removeValue`)
* Busca de um elemento (`find`)
* Impressão da lista (`printList`)
* Impressão detalhada de um nó (`printNode`)
* Liberação de toda a memória alocada (`freeList`)

---

## Estrutura do Projeto

```text
linked-list-c/
├── src/
│   ├── node.h
│   ├── linked_list.h
│   ├── linked_list.c
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
LinkedList list;

initList(&list);

pushBack(&list, 10);
pushBack(&list, 20);
pushBack(&list, 30);

insertAt(&list, 1, 15);

printList(&list);
```

Saída:

```text
10 -> 15 -> 20 -> 30 -> NULL
```

---

## Complexidade das Operações

| Operação    | Complexidade |
| ----------- | ------------ |
| pushFront   | O(1)         |
| pushBack    | O(n)         |
| insertAt    | O(n)         |
| find        | O(n)         |
| removeValue | O(n)         |
| printList   | O(n)         |

---

## Conceitos Praticados

* Ponteiros
* Estruturas (`struct`)
* Alocação dinâmica de memória (`malloc`)
* Liberação de memória (`free`)
* Manipulação de listas encadeadas
* Percorrimento de estruturas dinâmicas
* Tratamento de ponteiros nulos (`NULL`)
* Análise de complexidade de algoritmos

---

## Objetivo do Projeto

Este projeto faz parte de uma trilha de estudos em Estruturas de Dados utilizando a linguagem C. O foco é compreender como estruturas dinâmicas funcionam internamente, praticar gerenciamento manual de memória e desenvolver uma base sólida para estruturas mais avançadas, como pilhas, filas, tabelas hash, árvores e grafos.
