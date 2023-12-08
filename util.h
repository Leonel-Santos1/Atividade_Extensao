#ifndef ATIVIDADEEXTENSAO_UTIL_H
#define ATIVIDADEEXTENSAO_UTIL_H
#define N 50

typedef struct Endereco
{
    char rua[N];
    char cidade[N];
    char estado[N];
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
    char Nome[N];
    char CPF[13];
    char Telefone[15];
}Pessoa;

typedef struct vitima
{
    Pessoa pessoa;
    Endereco enderecoVitima;
    Horario horaOcorrencia;
    Endereco localOcorrencia;
    Data dataOcorrencia;
    char relato[200];
    char numeroProcesso[16];
    int andamento;

    struct vitima *prox;
    struct vitima *ant;
}vitima;

typedef struct Lista
{
    vitima *head;
    vitima *tail;
}Lista;

char* gerarNumerosAleatorios();
vitima *RemoverVitima(Lista *lista, char *numeroProcesso);
vitima *buscar(Lista *lista, char *conteudo);


#endif //ATIVIDADEEXTENSAO_UTIL_H
