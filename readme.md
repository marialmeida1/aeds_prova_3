# Prova 3 de Algoritimo e Estrututa de Dados

## Questão 1

Um hospital possui um sistema de gestão de pacientes, armazenando as seguintes informações sobre os mesmos:
nome, código do paciente como um número inteiro, gênero ('M' ou 'F'), um arranjo de 100 inteiros em que cada
elemento representa uma doença no histórico do paciente e um inteiro que representa a total de doenças que o
paciente já teve.

Por exemplo, dados que gripe é representada pelo código 1 e que covid pelo código 99, um paciente
que tenha tido apenas essas duas doenças terá, no arranjo, os dois primeiros elementos sendo 1 e 99, e o total de
doenças igual a 2.

### Letra A

Faça a estrutura struct do anunciado acima

#### O que é uma estrutura struct?

A estrutura struct funciona como um modo de criar vários objetos em uma único tipo, como por exemplo o requerido na atividade. Por meio de um único tipo podemos acessar valores de tipos como int, strings, char, e assim por diante.
A struct deve ser declarada fora do `main` utilizando junto também o `tipydef`, maneira de colocar um "apelido" na struct.

```C
// Declaração
    typedef struct {
        char nome[100];
        int codigo;
        char genero;
        int doenca[100];
        int total;
    } Paciente;


// Chamando a estrutura
    Paciente p = {
        "Joao",
        12345,
        'M',
        {1,99},
        2
    };


// Printando a estrutura
    printf("Nome: %s\n", p.nome);
    printf("Codigo: %d\n", p.codigo);
    // ...
```

Para acessar os valores dentro do "objeto" criado deve-se primeiramente, instanciá-lo, para que assim possamos acessar através de um "." (ponto). Caso o "objeto" seja instanciado por meio de alocação dinâmica, ele deve ser acessado por meio de um "->", visto que é um ponteiro para um struct.

```C
// Declaração igual
    typedef struct {
        char nome[100];
        int codigo;
        char genero;
        int doenca[100];
        int total;
    } Paciente;


// Alocando dinâmicamente
    Paciente *p = (Paciente *) malloc(sizeof(Paciente));

// Chamando a função
    p->nome = "Joao";
    p->codigo = 12345;
    p->nome = 'M';
    p->doenca[0] = 1;
    p->doenca[1] = 99;
    p->total = 2;


// Printando a estrutura
    printf("Nome: %s\n", p->nome);
    printf("Codigo: %d\n", p->codigo);
    // ...
```
