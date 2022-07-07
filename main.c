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
    float total=0.0;
    char codOpcao='\0';

    while(flagPedindo){
        do {
            if (total>0.0)
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
            case 'n': break;
            case 'e':
            case 'E': break;
            case 's':
            case 'S':
            default: system("cls"); printf("Volte Sempre!!!\n\n"); flagPedindo=0; break;
        }
    }

    return 0;
}
