/*======================================================*/
/*==                    Trabalho 1                    ==*/
/*==                  Programação 1                   ==*/
/*======================================================*/
/*== Autores: Nicolas A. Hilbert & Bruno Leal Maciel  ==*/
/*== Data: 12/07/22                                   ==*/
/*== Turma: INFO 62B                                  ==*/
/*======================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

int main()
{
    system("color 5e");

    setlocale(LC_ALL, "Portuguese");

    int flagPedindo=1;
    int encerrarPrograma(float);
    int encerrarPedido(float, int);
    int quantPedidos=0;
    float total=0.0;
    float fazerPedido();
    char codOpcao;

    while(flagPedindo){
        system("cls");

        printf("=== MENU IGREBOYS ===\n");
        printf("\t[N] Novo Pedido\n");
        printf("\t[E] Encerrar Pedido\n");
        printf("\t[S] Sair do Programa\n");
        printf("\t-> Informe sua opção: ");
        fflush(stdin);
        scanf("%c", &codOpcao);

        switch(codOpcao){
            case 'n':
            case 'N': total += fazerPedido(&quantPedidos, &total); break;
            case 'e':
            case 'E': total = encerrarPedido(total, quantPedidos); break;
            case 's':
            case 'S': flagPedindo = encerrarPrograma(total); break;
            default: printf("\nDigite uma opção válida!!!\n"); Sleep(1500); system("cls"); break;
        }
    }
    return 0;
}

float fazerPedido(int *quantPedido, float *total) {
    int codProduto;
    int quantProduto;
    float totalPedido;

    system("cls");

    printf("*======================================================*\n");
    printf("*==                   MENU IGREBOYS                  ==*\n");
    printf("*==                     CARDÁPIO                     ==*\n");
    printf("*======================================================*\n");
    printf("*== Cód.                Produto               Preço  ==*\n");
    printf("*== 100                  Pastel               R$3,50 ==*\n");
    printf("*== 101                 Torrada               R$4,00 ==*\n");
    printf("*== 102               Enroladinho             R$1,50 ==*\n");
    printf("*== 103                Suco 500ml             R$3,50 ==*\n");
    printf("*== 104             Refrigerante Lata         R$3,00 ==*\n");
    printf("*======================================================*\n");

    do {
        printf("\n-> Informe o código de seu produto (0 para cancelar): ");
        fflush(stdin);
        scanf("%d", &codProduto);

        if(codProduto!=0&&(codProduto<100||codProduto>104))
            printf("\nDigite um código válido!\n");
    } while(codProduto!=0&&(codProduto<100||codProduto>104));

    do {
        printf("\n-> Informe a quantidade do produto: ");
        fflush(stdin);
        scanf("%d", &quantProduto);

        if(quantProduto < 1)
            printf("\nDigite uma quantidade válida!\n");
    } while(quantProduto < 1);

    switch(codProduto){
        case 0: printf("\n\nPedido cancelado."); Sleep(1500); return 0;
        case 100: totalPedido = 3.5*quantProduto; break;
        case 101: totalPedido = 4.0*quantProduto; break;
        case 102: totalPedido = 1.5*quantProduto; break;
        case 103: totalPedido = 3.5*quantProduto; break;
        case 104: totalPedido = 3.0*quantProduto; break;
        default: system("cls"); printf("UM ERRO OCORREU!"); Sleep(1500); return 0;
    }

    system("cls");

    printf("Código: %d\nQuantidade: %d\nTotal deste pedido: R$%.2f", codProduto, quantProduto, totalPedido);

    *total += totalPedido;
    *quantPedido += quantProduto;

    Sleep(1000);
    return 0;
}

int encerrarPrograma(float total){
    if(total>0.0){
        char confirmarSaida;

        system("cls");

        while(1) {
            printf("*== Você não finalizou o pedido ==*\n\n");
            printf("Quer continuar?\n");
            printf("\t[S] Sim\n");
            printf("\t[N] Não\n");
            printf("\t-> Informe sua opção: ");

            fflush(stdin);
            scanf("%c",&confirmarSaida);

            switch(confirmarSaida){
                case 'S':
                case 's': return 1;
                case 'n':
                case 'N': system("cls"); printf("Volte sempre!\n"); return 0;
                default: printf("\nDigite uma opção válida!!!\n"); Sleep(1500); system("cls"); break;
            }
        }
    }
    else{
        system("cls");
        printf("Volte sempre!\n");

        return 0;
    }
}

int encerrarPedido(float total, int quantPedidos){
    system("cls");

    printf("Total do pedido: R$%.2f\nQuantidade de produtos: %d\n\n", total, quantPedidos);

    if (total>0.0){
        total=0.0;
        printf("Você pagou com sucesso!");
    }
    else
        printf("Não há um pedido em andamento!");

    Sleep(1500);

    return total;
}
