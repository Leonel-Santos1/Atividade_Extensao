#include <stdio.h>
#include "util.h"


void principal() {
    Lista *leve = NULL;
    Lista *medio = NULL;
    Lista *grave = NULL;
    Lista *casosConcluidos = NULL;

    int escolhaEntrada;
    int escolhaUser;


    printf("----Bem-Vindo(a)----");

    do {
        printf("\n1-Área Civil\n2-Área Servidor\n0-Sair\nEscolha:");
        scanf("%d", &escolhaEntrada);

        switch (escolhaEntrada) {

            case 1:
                printf("\n1-Registrar B.O\n2-Acompanhar Caso\n3-Buscar CPF\n4-Voltar");
                scanf("%d", &escolhaUser);
                fflush(stdin);

                if (escolhaUser == 1) {
                    fazerBO(leve, medio, grave);
                } else if (escolhaUser == 2) {
                    buscarBO(leve, medio, grave);
                } else {
                    printf("csdf");
                }
                break;

            case 2:
                printf("\n1-Fazer B.O\n2-Atualizar Casos\n3-Imprimir Detalhes Caso");
                scanf("%d", &escolhaUser);

                if (escolhaUser == 1) {

                    fazerBO(leve, medio, grave);
                } else if (escolhaUser == 2) {
                    char conteudo[12];
                    int escolhaCaso;

                    printf("\nDigite o número do caso ou CPF.");
                    scanf("%s", conteudo);

                    printf("Digite o tipo de ocorrência:\n1-Para Embriagez no volante ou Injúria\n2- Para Roubo ou Furto\n3-Para Lesão corporal ou Homicidio\n");
                    scanf("%d", &escolhaCaso);
                    if (escolhaCaso == 1) {
                        atualizarCaso(leve, conteudo, casosConcluidos);
                    } else if (escolhaCaso == 2) {
                        atualizarCaso(medio, conteudo, casosConcluidos);
                    } else {
                        atualizarCaso(grave, conteudo, casosConcluidos);
                        break;
                    }
                }

        }
    } while (escolhaEntrada != 0);
}

int main(void) {
    principal();

    return 0;
}