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
    int Idade;
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
    int grauOcorrencia;
    int andamento;

    struct vitima *prox;
    struct vitima *ant;
}vitima;

typedef struct Lista
{
    vitima *head;
    vitima *tail;
}Lista;

typedef struct piauiRG
{
    int RG;
    char nome[60];
    char nomePai[60];
    char nomeMae[60];
    char naturalidade[15];
    int diaExpedicao;
    int mesExpedicao;
    int anoExpedicao;
    char CPF[12];

    struct piauiRG *proxpi;

} piauiRG;

typedef struct maranhaoRG
{
    int RG;
    char nome[60];
    char nomePai[60];
    char nomeMae[60];
    char naturalidade[15];
    int diaExpedicao;
    int mesExpedicao;
    int anoExpedicao;
    char CPF[12];

    struct maranhaoRG *proxma;

} maranhaoRG;

typedef struct seguranca
{
    char login[20];
    char servidor[20];
    struct seguranca *prox;
} seguranca;

char* gerarNumerosAleatorios();
vitima *RemoverVitima(Lista *lista, char *numeroProcesso);
vitima *buscar(Lista *lista, char *conteudo);
Lista * inserirLista(Lista *ptr_registro,vitima *ptr_elementoNovo);
void fazerBO(Lista *ptr_registroLeve,Lista *ptr_registroMedio,Lista *ptr_registroGrave);
void buscarBO(Lista *ptr_registroLeve, Lista *ptr_registroMedio, Lista *ptr_registroGrave);
void imprimirDetalhesDoCaso(vitima *ptr_aux);
void imprimirNacionalPI(piauiRG **head, char CPFdigitado[12]);
void CadastraInscricao(seguranca **head);
void BuscarInscricao(seguranca **head);
void ImprimirInscricao(seguranca **head);
void AcessoAdmin();
int verificadorCPFpi(piauiRG **headPi, char CPFDigitado[12]);
int verificadorCPFma(maranhaoRG **headMa, char CPFDigitado[12]);
void PiauiRG(piauiRG **headPI);
void imprimirPi(piauiRG **head);
void imprimirNacionalPI(piauiRG **head, char CPFdigitado[12]);
void MaranhaoRg(maranhaoRG **headman);
void imprimirMA(maranhaoRG **headma);
void imprimirNacionalMA(maranhaoRG **head, char CPFdigitado[12]);
void BuscarNacional(piauiRG **headPi, maranhaoRG **headMa, char CPFdigitado[12]);

#endif //ATIVIDADEEXTENSAO_UTIL_H
