#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct {
  char nome[10];
  int codigo;
  char genero;
  int doenca[10];
  int total;
} Paciente;

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

int main() {

  int temDoenca = 0;

  Paciente p = cadastrar("Mari", 12345, 'F');
  printf("Nome: %s\n", p.nome);
  printf("Codigo: %d\n", p.codigo);
  printf("Genero: %c\n", p.genero);
  printf("Total: %d\n", p.total);
  
  for(int i=0; i<10; i++){
    if(p.doenca[i] != 0){
      temDoenca = 1;
    }
  }
  
  
  if(temDoenca){
    for(int i=0; i<10; i++){
      if(p.doenca[i] != 0){
        printf("Doenca: %d", p.doenca[i]);
      }
    }
  } else {
    printf("Nao ha doencas no paciente");
  }
}