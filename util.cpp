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
        } else if (strcasecmp(aux->pessoa.CPF == conteudo) == 0) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void atualizarCaso(Lista *lista, char *conteudo, Lista *listaCasosConcluidos) {

    vitima *aux = buscar(lista, conteudo);

    if (aux != NULL) {
        printf("Deseja atualizar o andamento do caso?\n");
        printf("1 - Concluído\n");
        printf("2 - Permanecer em Andamento\n");
        int opcao;
        scanf("%d", &opcao);
        if (opcao == 1) {
            aux->andamento = 1;
            if (aux->andamento == 1) {
                printf("Caso concluido\n");

                RemoverVitima(lista, conteudo);

                listaCasosConcluidos = inserirLista(listaCasosConcluidos, aux);
            }
        } else if (opcao == 2) {
            printf("Caso permanece em andamento\n");
        }
    } else {
        printf("Numero de processo ou CPF nao encontrado\n");
    }

}

void fazerBO(Lista *ptr_registroLeve, Lista *ptr_registroMedio, Lista *ptr_registroGrave) {
    vitima *ptr_novo = (vitima *) malloc(sizeof(vitima));
    ptr_novo->prox = NULL;
    ptr_novo->ant = NULL;
    ptr_novo->andamento = 0;
    strcpy(ptr_novo->numeroProcesso, gerarNumerosAleatorios());

    printf("Digite o nome da vítima:\n");
    fgets(ptr_novo->pessoa.Nome, N, stdin);
    fflush(stdin);

    printf("Digite o CPF da vítima:\n");
    fgets(ptr_novo->pessoa.CPF, 13, stdin);
    fflush(stdin);

    printf("Digite o telefone da vítima:\n");
    fgets(ptr_novo->pessoa.Telefone, 15, stdin);
    fflush(stdin);

    printf("Digite a idade da vitima:\n");
    scanf("%d", &ptr_novo->pessoa.Idade);
    fflush(stdin);

    printf("Digite o endereço da vítima:\n");
    fgets(ptr_novo->enderecoVitima.rua, N, stdin);
    fflush(stdin);

    printf("Digite a cidade da vítima:\n");
    fgets(ptr_novo->enderecoVitima.cidade, N, stdin);
    fflush(stdin);

    printf("Digite o estado da vítima:\n");
    fgets(ptr_novo->enderecoVitima.estado, N, stdin);
    fflush(stdin);

    printf("Digite a dia do ocorrido:\n");
    scanf("%d", &ptr_novo->dataOcorrencia.dia);
    fflush(stdin);

    printf("Digite o mês do ocorrido:\n");
    scanf("%d", &ptr_novo->dataOcorrencia.mes);
    fflush(stdin);

    printf("Digite o ano do ocorrido:\n");
    scanf("%d", &ptr_novo->dataOcorrencia.ano);
    fflush(stdin);

    printf("Digite o local do ocorrido:\n");
    fgets(ptr_novo->localOcorrencia.rua, N, stdin);
    fflush(stdin);

    printf("Digite a cidade do ocorrido:\n");
    fgets(ptr_novo->localOcorrencia.cidade, N, stdin);
    fflush(stdin);

    printf("Digite o estado do ocorrido:\n");
    fgets(ptr_novo->localOcorrencia.estado, N, stdin);
    fflush(stdin);

    printf("Digite a hora do ocorrido:\n");
    scanf("%d", &ptr_novo->horaOcorrencia.hora);

    printf("Digite o minuto do ocorrido:\n");
    scanf("%d", &ptr_novo->horaOcorrencia.min);

    printf("Digite o segundo do ocorrido:\n");
    scanf("%d", &ptr_novo->horaOcorrencia.seg);

    printf("Digite o tipo de ocorrência:\n1-Para Embriagez no volante ou Injúria\n2- Para Roubo ou Furto\n3-Para Lesão corporal ou Homicidio\n");
    scanf("%d", &ptr_novo->grauOcorrencia);
    fflush(stdin);

    printf("Digite a nota do ocorrido:\n");
    fgets(ptr_novo->relato, 200, stdin);
    fflush(stdin);

    if (ptr_novo->grauOcorrencia == 1) {
        ptr_registroLeve = inserirLista(ptr_registroLeve, ptr_novo);
    } else if (ptr_novo->grauOcorrencia == 2) {
        ptr_registroMedio = inserirLista(ptr_registroMedio, ptr_novo);
    } else if (ptr_novo->grauOcorrencia == 3) {
        ptr_registroGrave = inserirLista(ptr_registroGrave, ptr_novo);
    }

    printf("Leve:");
    for (vitima *ptr_aux = ptr_registroLeve->head; ptr_aux != NULL; ptr_aux = ptr_aux->prox) {
        printf("%s\n", ptr_aux->pessoa.Nome);
    }
    printf("Medio:");
    for (vitima *ptr_contador = ptr_registroMedio->head; ptr_contador != NULL; ptr_contador = ptr_contador->prox) {
        printf("%s\n", ptr_contador->pessoa.Nome);
    }
    printf("Grave:");
    for (vitima *ptr_atualizador = ptr_registroGrave->head;
         ptr_atualizador != NULL; ptr_atualizador = ptr_atualizador->prox) {
        printf("%s\n", ptr_atualizador->pessoa.Nome);
    }
}

Lista *inserirLista(Lista *ptr_registro, vitima *ptr_elementoNovo) {
    if (ptr_registro->head == NULL) {
        ptr_registro->head = ptr_elementoNovo;
        ptr_registro->tail = ptr_elementoNovo;
    } else {
        if (strcasecmp(ptr_registro->head->pessoa.Nome, ptr_elementoNovo->pessoa.Nome) > 0) {
            ptr_elementoNovo->prox = ptr_registro->head;
            ptr_registro->head->ant = ptr_elementoNovo;
            ptr_registro->head = ptr_elementoNovo;
        } else {
            for (vitima *ptr_aux = ptr_registro->head; ptr_aux != NULL; ptr_aux = ptr_aux->prox) {
                if (strcasecmp(ptr_aux->pessoa.Nome, ptr_elementoNovo->pessoa.Nome) > 0) {
                    ptr_elementoNovo->prox = ptr_aux;
                    ptr_elementoNovo->ant = ptr_aux->ant;
                    ptr_aux->ant->prox = ptr_elementoNovo;
                    ptr_aux->ant = ptr_elementoNovo;
                } else if (strcasecmp(ptr_aux->pessoa.Nome, ptr_elementoNovo->pessoa.Nome) < 0 &&
                           ptr_aux->prox == NULL) {
                    ptr_aux->prox = ptr_elementoNovo;
                    ptr_elementoNovo->ant = ptr_aux;
                    ptr_registro->tail = ptr_elementoNovo;
                }
            }
        }
    }
    return ptr_registro;
}

void imprimirDetalhesDoCaso(vitima *ptr_aux) {
    if (ptr_aux->andamento == 0) {
        printf("Caso encontrado:\n");
        printf("Nome da vitima: %s\n", ptr_aux->pessoa.Nome);
        printf("Idade da vitima: %d", ptr_aux->pessoa.Idade);
        printf("Data do ocorrido: %d/%d/%d\n", ptr_aux->dataOcorrencia.dia, ptr_aux->dataOcorrencia.mes,
               ptr_aux->dataOcorrencia.ano);
        printf("Hora do ocorrido: %d:%d:%d\n", ptr_aux->horaOcorrencia.hora, ptr_aux->horaOcorrencia.min,
               ptr_aux->horaOcorrencia.seg);
        printf("Local do ocorrido: %s", ptr_aux->localOcorrencia.rua);
        printf("Estado e Cidade do ocorrido: No estado %s,na cidade %s", ptr_aux->localOcorrencia.estado,
               ptr_aux->localOcorrencia.cidade);
        printf("Relato do ocorrido: %s", ptr_aux->relato);
    } else {
        printf("Caso Encerrado\n");
    }
}

void buscarBO(Lista *ptr_registroLeve, Lista *ptr_registroMedio, Lista *ptr_registroGrave) {
    char conteudo[N];
    int tipoOcorrencia;

    printf("Digite o numero do processo ou CPF:\n->");
    fgets(conteudo, N, stdin);
    fflush(stdin);

    printf("Digite o tipo de ocorrência:\n1-Para Embriagez no volante ou Injúria\n2- Para Roubo ou Furto\n3-Para Lesão corporal ou Homicidio\n");
    scanf("%d", &tipoOcorrencia);
    fflush(stdin);

    vitima *ptr_aux = NULL;
    if (tipoOcorrencia == 1) {
        ptr_aux = buscar(ptr_registroLeve, conteudo);
    } else if (tipoOcorrencia == 2) {
        ptr_aux = buscar(ptr_registroMedio, conteudo);
    } else {
        ptr_aux = buscar(ptr_registroGrave, conteudo);
    }

    if (ptr_aux != NULL) {
        imprimirDetalhesDoCaso(ptr_aux);
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
