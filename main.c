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
    int encerrarPrograma(float), encerrarPedido(float);
    float total=1.0;
    char codOpcao='\0';


    while(flagPedindo){
        do {
            system("cls");

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
            case 'E': total = encerrarPedido(total); break;
            case 's':
            case 'S':
            default : flagPedindo = encerrarPrograma(total); break;
        }
    }

    return 0;
}

int encerrarPrograma(float total){
    int flagContinuar=1;

    if(total > 0.0){
        char confirmarSaida;

        system("cls");

        printf("===Você não finalizou o pedido===\n\n");
        printf("Você quer continuar a pedir? \n");
        printf("\t[S] Sim\n");
        printf("\t[N] Não\n");
        printf("\t-> Informe sua opção: ");

        fflush(stdin);
        scanf("%c",&confirmarSaida);

        switch(confirmarSaida){
        case 'S':
        case 's': Sleep(1000); system("cls"); break;
        case 'n':
        case 'N': flagContinuar=0; system("cls");
                  printf("Volte sempre!\n"); break;
        }
    }
    else{
        flagContinuar=0;
        system("cls");
        printf("Volte sempre!\n");
    }

    return flagContinuar;
}

int encerrarPedido(float total){
    system("cls");
    if (total>0.0){
        total=0.0;
        printf("Você pagou com sucesso!");
        Sleep(2000);
        }
    else{
        printf("Não há um pedido em andamento!");
        Sleep(2000);
    }

    return total;
}
