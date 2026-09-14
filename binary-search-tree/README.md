# Árvore Binária de Busca em C

Implementação de uma **Árvore Binária de Busca (Binary Search Tree — BST)** em C utilizando alocação dinâmica de memória, desenvolvida com o objetivo de estudar estruturas de dados, ponteiros, recursividade, gerenciamento manual de memória e os princípios de organização e navegação em estruturas não lineares.

## Funcionalidades

- Inicialização da árvore (`initBinarySearchTree`)
- Inserção de elementos (`insert`)
- Busca de elementos (`search`)
- Remoção de elementos (`removeValue`)
- Busca do menor elemento (`findMin`)
- Busca do maior elemento (`findMax`)
- Percurso In-Order (`printInOrder`)
- Percurso Pre-Order (`printPreOrder`)
- Percurso Post-Order (`printPostOrder`)
- Cálculo da altura da árvore (`height`)
- Contagem de nós (`countNodes`)
- Contagem de folhas (`countLeaves`)
- Limpeza da árvore (`clear`)
- Liberação da árvore (`destroyBinarySearchTree`)
- Impressão detalhada de um nó (`printNode`)
- Visualização da árvore no terminal (`printTree`)

---

# Estrutura do Projeto

```text
binary-search-tree-c/

├── src/
│   ├── binary_search_tree.h
│   ├── binary_search_tree.c
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
BinarySearchTree *tree = initBinarySearchTree();

insert(tree, 50);
insert(tree, 30);
insert(tree, 70);
insert(tree, 20);
insert(tree, 40);
insert(tree, 60);
insert(tree, 80);

printTree(tree);
```

A estrutura resultante:

```text
                         50

                 30              70

             20      40      60      80
```

---

# Inserção

A inserção segue as regras de uma **Árvore Binária de Busca**:

- Valores menores que o nó atual são inseridos à esquerda.
- Valores maiores que o nó atual são inseridos à direita.
- Valores duplicados não são inseridos.

Por exemplo, inserindo:

```text
50, 30, 70, 20, 40, 60, 80
```

obtemos:

```text
                         50

                 30              70

             20      40      60      80
```

---

# Busca

A operação `search` percorre a árvore comparando o valor procurado com o valor do nó atual.

```c
SearchNode *result = search(tree, 40);
```

A busca utiliza a propriedade da BST para decidir qual caminho seguir.

Por exemplo:

```text
             50
            /
           30
             \
              40
```

Para procurar o valor `40`:

```text
40 < 50 → esquerda
40 > 30 → direita
40 == 40 → encontrado
```

Além do nó encontrado, a estrutura `SearchNode` mantém uma referência ao seu **pai**, permitindo que operações como a remoção sejam realizadas de maneira mais simples.

---

# Remoção

A operação `removeValue` trata os três principais casos de remoção em uma BST.

## 1. Remoção de um nó folha

Um nó folha é um nó que não possui filhos.

Exemplo:

```text
    30
```

Ao remover o nó:

```text
    X
```

O nó é removido e sua memória é liberada.

---

## 2. Remoção de um nó com um filho

Quando o nó possui apenas um filho:

```text
    30
      \
       40
```

O pai passa a apontar diretamente para o filho:

```text
    40
```

Dessa forma, o nó removido deixa de fazer parte da árvore sem alterar a estrutura dos demais nós.

---

## 3. Remoção de um nó com dois filhos

Quando o nó possui dois filhos:

```text
        50
       /  \
     30    70
          /
         60
```

É utilizado o **sucessor em ordem**, que corresponde ao menor valor encontrado na subárvore direita.

Nesse exemplo:

```text
Sucessor de 50 = 60
```

A estrutura passa a ser:

```text
        60
       /  \
     30    70
```

Esse processo mantém a propriedade da Árvore Binária de Busca.

---

# Percursos da Árvore

O projeto implementa os três principais percursos de uma árvore binária.

## In-Order

Ordem:

```text
Esquerda → Raiz → Direita
```

Para a árvore:

```text
        50
       /  \
     30    70
    /  \   / \
   20  40 60 80
```

O resultado será:

```text
20 30 40 50 60 70 80
```

Uma característica importante é que o percurso **In-Order de uma BST retorna os valores em ordem crescente**.

---

## Pre-Order

Ordem:

```text
Raiz → Esquerda → Direita
```

Resultado:

```text
50 30 20 40 70 60 80
```

---

## Post-Order

Ordem:

```text
Esquerda → Direita → Raiz
```

Resultado:

```text
20 40 30 60 80 70 50
```

Esse percurso é particularmente útil para operações que precisam processar os filhos antes do próprio nó, como a liberação de toda a árvore.

---

# Menor e Maior Elemento

## Menor elemento

Para encontrar o menor elemento:

```c
findMin(tree);
```

basta seguir os ponteiros `left` até não existir mais um filho à esquerda.

Exemplo:

```text
        50
       /
     30
    /
   20
  /
 10
```

O menor valor é:

```text
10
```

---

## Maior elemento

Da mesma forma, para encontrar o maior elemento, percorremos os ponteiros `right`.

Exemplo:

```text
        50
          \
           70
             \
              80
                \
                 90
```

O maior valor é:

```text
90
```

---

# Altura da Árvore

A função `height` calcula a altura da árvore.

Neste projeto, a convenção utilizada é:

```text
Árvore vazia → -1
Folha         → 0
```

Por exemplo:

```text
        50
       /  \
     30    70
    /
   20
  /
 10
```

A altura dessa árvore é:

```text
3
```

---

# Contagem de Nós

A função:

```c
countNodes(tree);
```

retorna a quantidade total de nós presentes na árvore.

Exemplo:

```text
        50
       /  \
     30    70
    /  \   / \
   20  40 60 80
```

Quantidade:

```text
7 nós
```

---

# Contagem de Folhas

A função:

```c
countLeaves(tree);
```

conta os nós que não possuem filhos.

No exemplo:

```text
        50
       /  \
     30    70
    /  \   / \
   20  40 60 80
```

As folhas são:

```text
20
40
60
80
```

Portanto:

```text
4 folhas
```

---

# Limpeza e Gerenciamento de Memória

A função:

```c
clear(tree);
```

remove todos os nós da árvore e libera a memória alocada.

Depois da operação:

```text
tree->root == NULL
```

A estrutura `BinarySearchTree` continua existindo, porém sem nenhum nó.

Para liberar também a própria estrutura da árvore:

```c
destroyBinarySearchTree(tree);
```

O projeto utiliza `malloc` para alocação dinâmica e `free` para liberar a memória.

---

# Complexidade das Operações

Considerando uma BST com altura `h`:

| Operação | Complexidade |
|----------|--------------|
| `insert` | O(h) |
| `search` | O(h) |
| `removeValue` | O(h) |
| `findMin` | O(h) |
| `findMax` | O(h) |
| `printInOrder` | O(n) |
| `printPreOrder` | O(n) |
| `printPostOrder` | O(n) |
| `height` | O(n) |
| `countNodes` | O(n) |
| `countLeaves` | O(n) |
| `clear` | O(n) |
| `printTree` | O(n) |

Em uma árvore **balanceada**, a altura tende a ser:

```text
h = O(log n)
```

Consequentemente, operações como busca, inserção e remoção podem ter complexidade:

```text
O(log n)
```

Porém, em uma árvore completamente desbalanceada:

```text
10
  \
   20
     \
      30
        \
         40
           \
            50
```

a árvore se comporta praticamente como uma lista encadeada.

Nesse cenário, operações como busca, inserção e remoção podem chegar a:

```text
O(n)
```

---

# Conceitos Praticados

- Ponteiros
- Estruturas (`struct`)
- Estruturas auto referenciadas
- Ponteiros para estruturas
- Alocação dinâmica de memória (`malloc`)
- Liberação de memória (`free`)
- Recursividade
- Árvores binárias
- Árvores Binárias de Busca (BST)
- Relação entre nós pai e filhos
- Ponteiros `left` e `right`
- Tratamento de ponteiros nulos (`NULL`)
- Busca em estruturas não lineares
- Inserção e remoção de nós
- Percursos em árvores
- Sucessor em ordem
- Gerenciamento manual de memória
- Análise de complexidade de algoritmos

---

# Como a Estrutura Funciona

Cada nó da árvore possui:

- Um valor (`data`)
- Um ponteiro para o filho esquerdo (`left`)
- Um ponteiro para o filho direito (`right`)

A árvore mantém um ponteiro principal:

- **Root**, que aponta para o primeiro nó da árvore.

```text
                    Root
                      ↓
                    +----+
                    | 50 |
                    +----+
                   /      \
                  ↓        ↓
              +----+     +----+
              | 30 |     | 70 |
              +----+     +----+
              /  \        /  \
             ↓    ↓      ↓    ↓
           +----+ +----+ +----+ +----+
           | 20 | | 40 | | 60 | | 80 |
           +----+ +----+ +----+ +----+
```

A principal regra da BST é:

```text
              Nó
             /   \
            /     \
     menores       maiores
```

Ou seja:

```text
              50
             /  \
           <50  >50
```

Essa propriedade permite realizar buscas de maneira eficiente quando a árvore possui uma estrutura equilibrada.

---

# Demonstração Interativa

O projeto inclui uma aplicação de terminal para testar as operações da Árvore Binária de Busca.

Operações disponíveis:

```text
 1  - Insert Value
 2  - Remove Value
 3  - Search
 4  - Print InOrder
 5  - Print PreOrder
 6  - Print PostOrder
 7  - Print Tree
 8  - Find Minimum
 9  - Find Maximum
10  - Height
11  - Number of Nodes
12  - Number of Leaves
13  - Clear Tree
 0  - Exit
```

A interface exibe o estado atual da árvore após as operações, além de mensagens de sucesso e erro, facilitando a visualização do comportamento da estrutura.

---

# Objetivo do Projeto

Este projeto faz parte de uma trilha de estudos em **Estruturas de Dados utilizando a linguagem C**.

O objetivo é aprofundar os conhecimentos adquiridos com estruturas lineares, aplicando conceitos de:

- Ponteiros
- Alocação dinâmica
- Recursividade
- Gerenciamento manual de memória
- Organização hierárquica de dados
- Busca e navegação em estruturas não lineares
- Análise de complexidade

A implementação de uma Árvore Binária de Busca serve como base para estruturas mais avançadas, como:

- **Árvores AVL**
- **Árvores Red-Black**
- **Heaps**
- **Tabelas Hash**
- **Grafos**
- Outras estruturas de dados não lineares

---

# Próximos Passos

Após a implementação da BST, um próximo passo natural é estudar **Árvores AVL**, entendendo como rotações podem manter a árvore equilibrada e preservar operações eficientes de busca, inserção e remoção.
