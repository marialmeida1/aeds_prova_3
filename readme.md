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

### Letra B

Crie uma função para cadastrar o paciente com o protótipo a seguir. O paciente é criado sem doença.

```C
Paciente cadastrar(char nome[], int codigo, char genero);
```

#### O que é um protótipo e como realizá-lo com uma struct?

Como falado anteriormente, uma strct funciona como um novo tipo de variável por isso podemos criar uma função do tipo Paciente, sendo "Paciente", a struct que criamos anteriormente. Mas o que é um protótipo?
Um protótipo é como se fosse uma pré definição do que será a sua função, por exemplo, o que ela irá retornar, qual o seu nome e o que ela recebe como parâmetro. No protótipo oferecido, as seguintes informações:

-  'Paciente': sendo o tipo que ela retorna
-  'cadastrar': seu nome | que acaba indicando o que ela faz
-  '(char nome[], int codigo, char genero)': por meio disso vemos que ela recebe três parâmetros, dois do tipo char e um do tipo int

Por meio disso podemos observar que ela é uma função que irá realizar o cadastro na nossa struct e que irá retornar para nós a struct que foi preenchida. Se ela estivesse do tipo "void" como retorno, poderiamos constatar que ela não retorna nenhum elemento para nós!

```C

// Criando a função
Paciente cadastrar(char nome[], int codigo, char genero){

  Paciente novo_paciente;

  strcpy(novo_paciente.nome, nome);
  novo_paciente.codigo = codigo;
  novo_paciente.genero = genero;

  for(int i=0; i<10; i++){
    novo_paciente.doenca[i] = 0;
  }

  novo_paciente.total = 0;

  return novo_paciente;
}


// Chamando no main
 Paciente p = cadastrar("Mari", 12345, 'F');

```

Para que o objeto 'novo_paciente' na função seja criado dinâmicamento você deve instânciá-lo com a alocação dinâmica e acessas suas informações por meio de '->', retorna para a função um valor de Paciente, já que é isso que seu protótipo pede.

```C
// Criando a função com alocação dinâmica
Paciente cadastrar(char nome[], int codigo, char genero){

  Paciente *novo_paciente = (Paciente *) malloc(sizeof(Paciente));

  strcpy(novo_paciente->nome, nome);
  novo_paciente->codigo = codigo;
  novo_paciente->genero = genero;

  for(int i=0; i<10; i++){
    novo_paciente->doenca[i] = 0;
  }

  novo_paciente->total = 0;

  return *novo_paciente;
}
```
