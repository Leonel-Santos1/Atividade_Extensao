#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>

char *gerarNumerosAleatorios() {
    static char numerosC[16]; // Aumentar o tamanho para acomodar o caractere nulo

    int numeros[15];

    for (int i = 0; i < 15; ++i) {
        numeros[i] = rand() % 9 + 1; // Ajustar o intervalo para ser de 1 a 9
    }
    for (int i = 0; i < 15; ++i) {
        numerosC[i] = '0' + numeros[i];
    }

    numerosC[15] = '\0'; // Adicionar o caractere nulo no final

    return numerosC;
}

vitima *buscar(Lista *lista, char *conteudo) {
    vitima *aux = lista->head;

    while (aux != NULL) {
        if (strcasecmp(aux->numeroProcesso, conteudo) == 0) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}


void atualizarCaso(Lista *lista, char *conteudo) {

    vitima *aux = buscar(lista, conteudo);

    if (aux != NULL) {
        printf("Deseja atualizar o andamento do caso?\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        int opcao;
        scanf("%d", &opcao);
        if (opcao == 1) {
            aux->andamento = 1;
            if(aux->andamento == 1){
                printf("Caso concluido\n");

                RemoverVitima(lista, conteudo);

                //Aqui ele vai ser movido para outra lista

            }

        }
    } else {
        printf("Numero de processo nao encontrado\n");
    }


}

vitima *RemoverVitima(Lista *lista, char *numeroProcesso) {
    vitima *atual = buscar(lista, numeroProcesso);
    vitima *anterior = NULL;

    if (atual != NULL) {
        if (atual == lista->head) {
            lista->head = atual->prox;
            if (lista->head == NULL) // Se a lista ficou vazia
            {
                lista->tail = NULL;
            }
        } else {
            anterior = atual->ant;

            if (atual == lista->tail) {
                lista->tail = anterior;
            } else {
                anterior->prox = atual->prox;
            }
        }

        atual->ant = NULL;

        return atual;
    } else
        return NULL;

}