//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "util.h"
//
//void CadastraInscricao(seguranca **head)
//{
//    seguranca *novo = (seguranca *)malloc(sizeof(seguranca));
//
//    if (novo)
//    {
//        printf("\nDigite a inscriço: ");
//        scanf("%s", novo->login);
//
//        novo->prox = *head;
//        *head = novo;
//    }
//
//    else
//    {
//        printf("\nErro de alocaç?o de memoria.");
//    }
//}
//
//void BuscarInscricao(seguranca **head)
//{
//
//    seguranca *aux = *head;
//    char loginDigitado[20];
//
//    if (*head == NULL)
//    {
//        printf("\nA lista está vazia.");
//    }
//
//    else
//    {
//        printf("\nDigite a inscriç?o: ");
//        scanf("%s", loginDigitado);
//
//        if (strcasecmp((*head)->login, loginDigitado) == 0)
//        {
//            printf("\nInscriç?o Encontrada.");
//        }
//
//        else
//        {
//
//            while (aux != NULL && strcasecmp(aux->login, loginDigitado) != 0)
//            {
//                aux = aux->prox;
//            }
//            if (aux != NULL && strcasecmp(aux->login, loginDigitado) == 0)
//            {
//                printf("\nInscriç?o Encontrada.");
//            }
//            else
//            {
//                printf("\nInscriç?o Inválida.");
//            }
//        }
//    }
//}
//
//void ImprimirInscricao(seguranca **head)
//{
//    seguranca *aux = *head;
//
//    if (*head == NULL)
//    {
//        printf("\nSem elemento na lista.");
//    }
//
//    else
//    {
//
//        while (aux != NULL)
//        {
//
//            printf("\n%s", aux->login);
//            aux = aux->prox;
//        }
//    }
//}
//
//void MenuAdmin(){
//
//    int escolha;
//    seguranca *head = NULL;
//
//    do
//    {
//        printf("\n1-Cadastrar Inscriç?o\n2-Imprimir Inscriç?es\n3-Buscar_Inscriç?o\n0-Sair Área Administrador\nEscolha:");
//        scanf("%d", &escolha);
//
//        switch (escolha)
//        {
//
//        case 1:
//            CadastraInscricao(&head);
//            break;
//
//        case 2:
//            ImprimirInscricao(&head);
//            break;
//
//        case 3:
//            BuscarInscricao(&head);
//            break;
//
//        case 0:
//            printf("\nSaindo ...");
//            break;
//
//        default:
//            printf("\nOpç?o inválida.");
//            break;
//        }
//    } while (escolha != 0);
//}
//
//void AcessoAdmin()
//{
//    char LoginAdmin[] = {"Admin"};
//    char SenhaAdmin[] = {"Admin"};
//    char LoginDigitado[20];
//    char SenhaDigitada[20];
//    int NumTentativasL = 3;
//    int NumTentativasS = 3;
//    int RetornoLogin;
//    int RetornoSenha;
//
//    printf("---Área Administrador---");
//
//    do
//    {
//        printf("\nDigite o Login: ");
//        scanf("%s", LoginDigitado);
//
//        RetornoLogin = strcmp(LoginAdmin, LoginDigitado);
//
//        if (RetornoLogin == 0)
//        {
//            break;
//        }
//
//        NumTentativasL--;
//
//        if(NumTentativasL == 0){
//            break;
//        }
//        printf("\nLogin incorreto! Você tem %d tentativa(s).", NumTentativasL);
//
//    } while (RetornoLogin != 0 && NumTentativasL != 0);
//
//    if (RetornoLogin == 0)
//    {
//        do
//        {
//            printf("\nDigite a senha: ");
//            scanf("%s", SenhaDigitada);
//
//            RetornoSenha = strcmp(SenhaAdmin, SenhaDigitada);
//
//            if (RetornoSenha == 0)
//            {
//                break;
//            }
//
//            NumTentativasS--;
//
//            if(NumTentativasS == 0){
//                break;
//            }
//
//            printf("\nLogin incorreto! Você tem %d tentativa(s).", NumTentativasS);
//
//        } while (RetornoSenha != 0 && NumTentativasS != 0);
//
//        if (RetornoSenha == 0)
//        {
//            MenuAdmin();
//        }
//        else
//        {
//            printf("\nNúmero de tentativas excedido.\nSaindo do Sitema...");
//        }
//    }
//    else
//    {
//        printf("\nNúmero de tentativas excedido.\nSaindo do Sitema...");
//    }
//}
//
//int main(void){
//    AcessoAdmin();
//}
//
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//#include <string.h>
//
//int verificadorCPFpi(piauiRG **headPi, char CPFDigitado[12])
//{
//    piauiRG *auxPI = *headPi;
//
//    if (*headPi == NULL)
//    {
//        return 0;
//    }
//
//    else
//    {
//        if (strcasecmp((*headPi)->CPF, CPFDigitado) == 0)
//        {
//            return 1;
//        }
//
//        else
//        {
//            while (auxPI != NULL && strcasecmp(auxPI->CPF, CPFDigitado) != 0)
//            {
//                auxPI = auxPI->proxpi;
//            }
//            if (auxPI != NULL && strcasecmp(auxPI->CPF, CPFDigitado) == 0)
//            {
//                return 1;
//            }
//            else
//            {
//                return 0;
//            }
//        }
//    }
//}
//
//int verificadorCPFma(maranhaoRG **headMa, char CPFDigitado[12])
//{
//    maranhaoRG *auxMA = *headMa;
//
//    if (*headMa == NULL)
//    {
//        return 0;
//    }
//
//    else
//    {
//        if (strcasecmp((*headMa)->CPF, CPFDigitado) == 0)
//        {
//            return 1;
//        }
//
//        else
//        {
//            while (auxMA != NULL && strcasecmp(auxMA->CPF, CPFDigitado) != 0)
//            {
//                auxMA = auxMA->proxma;
//            }
//            if (auxMA != NULL && strcasecmp(auxMA->CPF, CPFDigitado) == 0)
//            {
//                return 1;
//            }
//            else
//            {
//                return 0;
//            }
//        }
//    }
//}
//
//void PiauiRG(piauiRG **headPI)
//{
//    piauiRG *novo = (piauiRG *)malloc(sizeof(piauiRG));
//    int retorno;
//
//    if (novo)
//    {
//        printf("\nDigite o CPF: ");
//        scanf("%s", novo->CPF);
//
//        retorno = verificadorCPFpi(headPI, novo->CPF);
//        if (retorno == 1)
//        {
//            printf("\nEsse CPF já foi cadastrado.");
//        }
//
//        else
//        {
//            printf("\nDigite o nome:");
//            scanf("%s", novo->nome);
//            printf("\nDigite o nome do pai: ");
//            scanf("%s", novo->nomePai);
//            printf("\nDigite o nome da mae: ");
//            scanf("%s", novo->nomeMae);
//            printf("\nDigite a naturalidade(cidade-PI): ");
//            scanf("%s", novo->naturalidade);
//            printf("\nDigite a data de expedicao(dd/mm/aaaa)");
//            scanf("%d%d%d", &novo->diaExpedicao, &novo->mesExpedicao, &novo->anoExpedicao);
//            printf("\nDigite o RG: ");
//            scanf("%d", &novo->RG);
//            printf("\nCadastado com sucesso.");
//
//            novo->proxpi = *headPI;
//            *headPI = novo;
//        }
//    }
//    else
//    {
//        printf("Erro de alocacao de memoria");
//    }
//}
//
//void imprimirPi(piauiRG **head)
//{
//    piauiRG *aux = *head;
//
//    if (*head == NULL)
//    {
//        printf("\nA lista esta vazia.");
//    }
//    else
//    {
//        while (aux != NULL)
//        {
//            printf("\nPiaui: ");
//            printf("\nNome: %s", aux->nome);
//            printf("\nFiliacao:\n%s\n%s", aux->nomePai, aux->nomeMae);
//            printf("\nNaturalidade: %s", aux->naturalidade);
//            printf("\nData de expedicao: %d/%d/%d", aux->diaExpedicao, aux->mesExpedicao, aux->anoExpedicao);
//            printf("\nCPF: %s", aux->CPF);
//            printf("\nRG:%d\n", aux->RG);
//            aux = aux->proxpi;
//        }
//    }
//}
//
//void imprimirNacionalPI(piauiRG **head, char CPFdigitado[12]){
//    piauiRG *aux = *head;
//
//    if(strcmp((aux -> CPF), CPFdigitado) == 0){
//            printf("\nPiaui: ");
//            printf("\nNome: %s", aux->nome);
//            printf("\nFiliacao:\n%s\n%s", aux->nomePai, aux->nomeMae);
//            printf("\nNaturalidade: %s", aux->naturalidade);
//            printf("\nData de expedicao: %d/%d/%d", aux->diaExpedicao, aux->mesExpedicao, aux->anoExpedicao);
//            printf("\nCPF: %s", aux->CPF);
//            printf("\nRG:%d\n", aux->RG);
//            aux = aux->proxpi;
//    }
//    else{
//        while(strcasecmp(aux -> CPF, CPFdigitado) != 0 && aux != NULL){
//           aux = aux -> proxpi;
//        }
//        if(strcasecmp(aux -> CPF, CPFdigitado) == 0){
//            printf("\nPiaui: ");
//            printf("\nNome: %s", aux->nome);
//            printf("\nFiliacao:\n%s\n%s", aux->nomePai, aux->nomeMae);
//            printf("\nNaturalidade: %s", aux->naturalidade);
//            printf("\nData de expedicao: %d/%d/%d", aux->diaExpedicao, aux->mesExpedicao, aux->anoExpedicao);
//            printf("\nCPF: %s", aux->CPF);
//            printf("\nRG:%d\n", aux->RG);
//            aux = aux->proxpi;
//        }
//        else{
//            printf("\nEsse CPF nao esta registrado.");
//        }
//    }
//
//}
//
//
//void MaranhaoRg(maranhaoRG **headman)
//{
//    maranhaoRG *novo = (maranhaoRG *)malloc(sizeof(maranhaoRG));
//    int retorno;
//
//    if (novo)
//    {
//        printf("\nDigite o CPF: ");
//        scanf("%s", novo->CPF);
//
//        retorno = verificadorCPFma(headman, novo->CPF);
//        if (retorno == 1)
//        {
//            printf("\nEsse CPF já foi cadastrado.");
//        }
//        else
//        {
//            printf("\nDigite o nome:");
//            scanf("%s", novo->nome);
//            printf("\nDigite o nome do pai: ");
//            scanf("%s", novo->nomePai);
//            printf("\nDigite o nome da mae: ");
//            scanf("%s", novo->nomeMae);
//            printf("\nDigite a naturalidade(cidade-PI): ");
//            scanf("%s", novo->naturalidade);
//            printf("\nDigite a data de expedicao(dd/mm/aaaa)");
//            scanf("%d%d%d", &novo->diaExpedicao, &novo->mesExpedicao, &novo->anoExpedicao);
//            printf("\nDigite o RG: ");
//            scanf("%d", &novo->RG);
//            printf("\nCadastrado com sucesso.");
//
//            novo->proxma = *headman;
//            *headman = novo;
//        }
//    }
//    else
//    {
//        printf("Erro de alocacao de memoria");
//    }
//}
//
//void imprimirMA(maranhaoRG **headma)
//{
//    maranhaoRG *auxma = *headma;
//
//    if (*headma == NULL)
//    {
//        printf("\nA lista esta vazia.");
//    }
//    else
//    {
//        while (auxma != NULL)
//        {
//            printf("\nMaranhao:");
//            printf("\nNome: %s", auxma->nome);
//            printf("\nFiliacao:\n%s\n%s", auxma->nomePai, auxma->nomeMae);
//            printf("\nNaturalidade: %s", auxma->naturalidade);
//            printf("\nData de expedicao: %d/%d/%d", auxma->diaExpedicao, auxma->mesExpedicao, auxma->anoExpedicao);
//            printf("\nCPF: %s", auxma->CPF);
//            printf("\nRG: %d\n", auxma->RG);
//            auxma = auxma->proxma;
//        }
//    }
//}
//void imprimirNacionalMA(maranhaoRG **head, char CPFdigitado[12]){
//    maranhaoRG *aux = *head;
//
//    if(strcmp((aux -> CPF), CPFdigitado) == 0){
//            printf("\nPiaui: ");
//            printf("\nNome: %s", aux->nome);
//            printf("\nFiliacao:\n%s\n%s", aux->nomePai, aux->nomeMae);
//            printf("\nNaturalidade: %s", aux->naturalidade);
//            printf("\nData de expedicao: %d/%d/%d", aux->diaExpedicao, aux->mesExpedicao, aux->anoExpedicao);
//            printf("\nCPF: %s", aux->CPF);
//            printf("\nRG:%d\n", aux->RG);
//            aux = aux->proxma;
//    }
//    else{
//        while(strcasecmp(aux -> CPF, CPFdigitado) != 0 && aux != NULL){
//           aux = aux -> proxma;
//        }
//        if(strcasecmp(aux -> CPF, CPFdigitado) == 0){
//            printf("\nMaranh?o: ");
//            printf("\nNome: %s", aux->nome);
//            printf("\nFiliacao:\n%s\n%s", aux->nomePai, aux->nomeMae);
//            printf("\nNaturalidade: %s", aux->naturalidade);
//            printf("\nData de expedicao: %d/%d/%d", aux->diaExpedicao, aux->mesExpedicao, aux->anoExpedicao);
//            printf("\nCPF: %s", aux->CPF);
//            printf("\nRG:%d\n", aux->RG);
//            aux = aux->proxma;
//        }
//        else{
//            printf("\nEsse CPF nao esta registrado.");
//        }
//    }
//
//}
//void BuscarNacional(piauiRG **headPi, maranhaoRG **headMa, char CPFdigitado[12])
//{
//    piauiRG *auxPI = *headPi;
//    maranhaoRG *auxMA = *headMa;
//
//    if (*headMa == NULL && *headPi == NULL)
//    {
//        printf("\nSem CPF cadastrado.");
//    }
//    else
//    {
//        if (*headPi != NULL && *headMa != NULL && strcasecmp((*headPi)->CPF, CPFdigitado) == 0 && strcasecmp((*headMa)->CPF, CPFdigitado) == 0)
//        {
//            imprimirNacionalMA(headMa,CPFdigitado);
//            imprimirNacionalPI(headPi,CPFdigitado);
//        }
//        else if (*headPi != NULL && strcasecmp((*headPi)->CPF, CPFdigitado) == 0)
//        {
//            imprimirNacionalPI(headPi,CPFdigitado);
//        }
//        else if (*headMa != NULL && strcasecmp((*headMa)->CPF, CPFdigitado) == 0)
//        {
//            imprimirNacionalMA(headMa,CPFdigitado);
//        }
//        else
//        {
//            while ((auxPI != NULL && strcasecmp(auxPI->CPF, CPFdigitado)) != 0 || (auxMA != NULL && strcasecmp(auxMA->CPF, CPFdigitado) != 0))
//            {
//                auxPI = auxPI->proxpi;
//                auxMA = auxMA->proxma;
//            }
//            if ((auxPI != NULL && strcasecmp(auxPI->CPF, CPFdigitado) == 0) || (auxMA != NULL && strcasecmp(auxMA->CPF, CPFdigitado) == 0))
//            {
//                if (strcasecmp((*headPi)->CPF, CPFdigitado) == 0 && strcasecmp((*headMa)->CPF, CPFdigitado) == 0)
//                {
//                    imprimirNacionalMA(headMa,CPFdigitado);
//                    imprimirNacionalPI(headPi,CPFdigitado);
//                }
//                else if (strcasecmp((*headPi)->CPF, CPFdigitado) == 0)
//                {
//                    imprimirNacionalPI(headPi,CPFdigitado);
//                }
//                else if (strcasecmp((*headMa)->CPF, CPFdigitado) == 0)
//                {
//                    imprimirNacionalMA(headMa,CPFdigitado);
//                }
//            }
//            else
//            {
//                printf("\nCPF n?o encontrado.");
//            }
//        }
//    }
//}
//
////Aqui é uma main que o Augusto fez para testar o código dele
////int main(void)
////{
////
////    piauiRG *headPI = NULL;
////    maranhaoRG *headMA = NULL;
////    int escolhaEntrada;
////    int escolhaRegistrar;
////    int escolhaExibir;
////    char digitar[12];
////
////    do
////    {
////        printf("\n\n0-Sair\n1-Registrar\n2-Exibir\n3-Busca Nacional\nEscolha:");
////        scanf("%d", &escolhaEntrada);
////
////        switch (escolhaEntrada)
////        {
////        case 1:
////            printf("\n1-Piaui\n2-Maranhao\nEscolha o estado: ");
////            scanf("%d", &escolhaRegistrar);
////
////            if (escolhaRegistrar == 1)
////            {
////                PiauiRG(&headPI);
////            }
////            else
////            {
////                MaranhaoRg(&headMA);
////            }
////            break;
////
////        case 2:
////            printf("\n1-Piaui\n2-Maranhao\nEscolha o estado:");
////            scanf("%d", &escolhaExibir);
////
////            if (escolhaExibir == 1)
////            {
////                imprimirPi(&headPI);
////            }
////            else
////            {
////                imprimirMA(&headMA);
////            }
////            break;
////
////        case 3:
////            printf("\nNumero do CPF:");
////            scanf("%s", digitar);
////            BuscarNacional(&headPI, &headMA,digitar);
////            break;
////
////        default:
////            if (escolhaEntrada == 0)
////            {
////                printf("\nSaindo...");
////                break;
////            }
////            printf("Escolha inválida.");
////            break;
////        }
////    } while (escolhaEntrada != 0);
////}
//
//
//
//
//
