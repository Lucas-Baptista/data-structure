# Lista Duplamente Encadeada em C

Implementação de uma **Lista Duplamente Encadeada (Doubly Linked List)** em C utilizando alocação dinâmica de memória, desenvolvida com o objetivo de estudar estruturas de dados, ponteiros, gerenciamento manual de memória e navegação bidirecional entre os nós.

## Funcionalidades

- Inicialização da lista (`initList`)
- Inserção de elementos no início (`pushFront`)
- Inserção de elementos no final (`pushBack`)
- Inserção de elementos em uma posição específica (`insertAt`)
- Remoção do primeiro elemento (`popFront`)
- Remoção do último elemento (`popBack`)
- Remoção de um elemento pelo valor (`removeValue`)
- Remoção de um elemento pelo índice (`removeAt`)
- Busca de um elemento (`find`)
- Inversão da lista (`reverseList`)
- Consulta ao primeiro elemento (`head`)
- Consulta ao último elemento (`tail`)
- Verificação se a lista está vazia (`isEmpty`)
- Consulta da quantidade de elementos (`size`)
- Impressão da lista (`printList`)
- Impressão detalhada de um nó (`printNode`)
- Liberação de toda a memória alocada (`freeList`)

---

# Estrutura do Projeto

```text
doubly-linked-list-c/
├── src/
│   ├── doubly_linked_list.h
│   ├── doubly_linked_list.c
│   └── main.c
│
├── Makefile
└── README.md
```

---

# Compilação

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

# Exemplo de Uso

```c
DoublyLinkedList *list = initList();

pushBack(list, 10);
pushBack(list, 20);
pushBack(list, 30);

printList(list);

pushFront(list, 5);

printList(list);

removeValue(list, 20);

printList(list);
```

Saída:

```text
Head -> [10] ⇄ [20] ⇄ [30] <- Tail

List size: 3
```

Após inserir um elemento no início:

```text
Head -> [5] ⇄ [10] ⇄ [20] ⇄ [30] <- Tail

List size: 4
```

Após remover o valor `20`:

```text
Head -> [5] ⇄ [10] ⇄ [30] <- Tail

List size: 3
```

---

# Complexidade das Operações

| Operação | Complexidade |
|----------|--------------|
| pushFront | O(1) |
| pushBack | O(1) |
| popFront | O(1) |
| popBack | O(1) |
| head | O(1) |
| tail | O(1) |
| isEmpty | O(1) |
| size | O(1) |
| find | O(n) |
| insertAt | O(n) |
| removeAt | O(n) |
| removeValue | O(n) |
| reverseList | O(n) |
| printList | O(n) |

---

# Conceitos Praticados

- Ponteiros
- Estruturas (`struct`)
- Estruturas auto referenciadas
- Alocação dinâmica de memória (`malloc`)
- Liberação de memória (`free`)
- Manipulação de nós duplamente encadeados
- Tratamento de ponteiros nulos (`NULL`)
- Gerenciamento manual de memória
- Manipulação dos ponteiros `head` e `tail`
- Navegação bidirecional entre os nós
- Inserção e remoção eficiente nas extremidades da lista
- Inversão de lista em memória
- Análise de complexidade de algoritmos

---

# Como a Estrutura Funciona

Cada nó da lista possui:

- Um valor
- Um ponteiro para o próximo nó (`next`)
- Um ponteiro para o nó anterior (`prev`)

A lista mantém dois ponteiros principais:

- **Head**, que aponta para o primeiro elemento.
- **Tail**, que aponta para o último elemento.

```text
               next →
Head
 ↓
+------+     +------+     +------+
 | 10 |   ⇄  | 20 |   ⇄   | 30 |
+------+     +------+     +------+
                                   ↑
                                 Tail
            ← prev
```

Graças aos ponteiros `next` e `prev`, é possível percorrer a lista tanto do início para o fim quanto do fim para o início. Além disso, inserções e remoções nas extremidades da lista possuem complexidade **O(1)**.

---

# Demonstração Interativa

O projeto inclui uma aplicação de terminal para testar todas as operações da lista duplamente encadeada.

Operações disponíveis:

- Push Front
- Push Back
- Insert At
- Pop Front
- Pop Back
- Remove Value
- Remove At
- Find
- Reverse List
- Print List
- Head
- Tail
- Size
- Is Empty

A interface exibe o estado atual da lista após cada operação, além de mensagens de sucesso e erro, facilitando a visualização do funcionamento da estrutura.

---

# Objetivo do Projeto

Este projeto faz parte de uma trilha de estudos em **Estruturas de Dados utilizando a linguagem C**. O foco é compreender o funcionamento interno de estruturas dinâmicas, praticar o gerenciamento manual de memória e consolidar conceitos fundamentais para estruturas mais avançadas, como **Árvores Binárias**, **Árvores AVL**, **Tabelas Hash**, **Grafos** e outras estruturas não lineares.