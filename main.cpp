#include <stdio.h>
typedef struct Endereco
{
    char rua[100];
    char cidade[100];
    char estado[100];
}Endereco;

typedef struct Data
{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct Horarario
{
    int hora;
    int min;
    int seg;
}Horario;

typedef struct Pessoa
{
    char Nome[100];
    char CPF[13];
    char Telefone[15];
}Pessoa;

typedef struct vitima
{
    Pessoa pessoa;
    Endereco enderecoVitima;
    Horarario horaOcorrencia;
    Data dataOcorrencia;
    Endereco localOcorrencia;
    char relato[200];
    char numeroProcesso[50];
    int andamento;

    struct vitima *prox;
    struct vitima *ant;
}vitima;

typedef struct queue
{
    vitima *head;
    vitima *tail;
};

