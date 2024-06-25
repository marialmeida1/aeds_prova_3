#include <stdio.h>

typedef struct {
    char nome[100];
    int codigo;
    char genero;
    int doenca[100];
    int total;
} Paciente;


int main(){

    // Chamando a estrutura
    Paciente p = {
        "Joao",
        12345,
        'M',
        {1,99},
        2
    };

    // Printando valores
    printf("Nome: %s\n", p.nome);
    printf("Codigo: %d\n", p.codigo);
    printf("Genero: %c\n", p.genero);
    for(int i=0; i<p.total; i++){
        printf("Doenca %d: %d\n", i+1, p.doenca[i]);
    }
    printf("Total: %d\n", p.total);
}