#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int codigo;
    char genero;
    int doenca[100];
    int total;
} Paciente;

int main(){
    Paciente *p = (Paciente *) malloc(sizeof(Paciente));

    strcpy(p->nome, "Joao Silva");
    p->codigo = 12345;
    p->genero = 'M';
    p->doenca[0] = 1;
    p->doenca[1] = 99;
    p->total = 2;

    printf("Nome: %s\n", p->nome);
    printf("Codigo: %d\n", p->codigo);
}