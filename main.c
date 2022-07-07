/*======================================================*/
/*==                    Trabalho 1                    ==*/
/*==                  Programação 1                   ==*/
/*======================================================*/
/*== Autores: Nicolas A. Hilbert & Bruno Leal Maciel  ==*/
/*== Data:                                            ==*/
/*== Turma: INFO 62B                                  ==*/
/*======================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int flagOpcao=1, flagPedindo=1;
<<<<<<< HEAD
    float total=0.0, functionPedido();
    char codOpcao='\0';


    while(flagPedindo){
        do {
            system("cls");

            if(total>0.0)
=======
    float total=0.0;
    char codOpcao='\0';

    while(flagPedindo){
        do {
            if (total>0.0)
>>>>>>> 21ed4e89b2d2e4349403185752eabbae8cc25c1c
                printf("Total do pedido atual: R$%.2f\n\n", total);

            printf("=== MENU IGREBOYS ===\n");
            printf("\t[N] Novo Pedido\n");
            printf("\t[E] Encerrar Pedido\n");
            printf("\t[S] Sair do Programa\n");
            printf("\t-> Informe sua opção: ");
            fflush(stdin);
            scanf("%c", &codOpcao);

            if(codOpcao!='n'&&codOpcao!='N'&&codOpcao!='e'&&codOpcao!='E'&&codOpcao!='s'&&codOpcao!='S'){
                printf("\nDigite uma opção válida!!!\n");
                Sleep(2000);
                system("cls");
            }
            else
                flagOpcao = 0;
        } while(flagOpcao);

        switch(codOpcao){
            case 'N':
            case 'n': total += functionPedido(); break;
            case 'e':
            case 'E': break;
            case 's':
            case 'S':
            default: system("cls"); printf("Volte Sempre!!!\n\n"); flagPedindo=0; break;
        }
    }

    return 0;
}

float functionPedido() {
    int codProduto;

    do{
        system("cls");

        printf("*======================================================*\n");
        printf("*==                   MENU IGREBOYS                  ==*\n");
        printf("*==                     CARDÁPIO                     ==*\n");
        printf("*======================================================*\n");
        printf("*== Cód.                Produto               Preço  ==*\n");
        printf("*== 100                 Torrada               R$4,00 ==*\n");
        printf("*== 101                 Pastel                R$3,50 ==*\n");
        printf("*== 102               Enroladinho             R$1,50 ==*\n");
        printf("*== 103            Refrigerante Lata          R$3,00 ==*\n");
        printf("*== 104               Suco 500ml              R$3,50 ==*\n");
        printf("*======================================================*\n");
        printf("\n-> Informe o código de seu produto (0 para cancelar): ");
        fflush(stdin);
        scanf("%d", &codProduto);
    } while(codProduto!=0&&(codProduto<100||codProduto>104));

    switch(codProduto){
        case 0: printf("\n\nPedido cancelado."); Sleep(2000); return 0;
        case 100: return 4.0;
        case 101: return 3.5;
        case 102: return 1.5;
        case 103: return 3.0;
        case 104: return 3.5;
        default: system("cls"); printf("UM ERRO OCORREU!"); Sleep(2000); return 0;
    }
}
