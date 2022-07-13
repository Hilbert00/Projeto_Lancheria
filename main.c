/*======================================================*/
/*==                    Trabalho 1                    ==*/
/*==                  Programa��o 1                   ==*/
/*======================================================*/
/*== Autores: Nicolas A. Hilbert & Bruno Leal Maciel  ==*/
/*== Data: 13/07/22                                   ==*/
/*== Turma: INFO 62B                                  ==*/
/*======================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

int main()
{
    // Troca a cor do CMD para fundo roxo e letras amarelas
    system("color 5e");

    // Troca a linguagem de execu��o do programa para PT-BR
    setlocale(LC_ALL, "Portuguese");

    int flagPedindo=1; // Flag para permitir a execu��o do programa
    int encerrarPrograma(float); // Fun��o para encerrar o programa
    int encerrarPedido(float *, int); // Fun��o para encerrar o pedido
    int quantPedidos=0; // Quantidade total de produtos no pedido
    float total=0.0; // Quantidade total do valor dos produtos no pedido
    float fazerPedido(int *, float *); // Fun��o para fazer um novo pedido
    char codOpcao; // Vari�vel que recebe a op��o escolhida pelo usu�rio no menu

    // Loop principal do programa, que executar� enquanto a flagPedindo for igual a 1
    while(flagPedindo){
        system("cls"); // Limpa a tela

        // Menu de op��es do programa
        printf("=== MENU IGREBOYS ===\n");
        printf("\t[N] Novo Pedido\n");
        printf("\t[E] Encerrar Pedido\n");
        printf("\t[S] Sair do Programa\n");
        printf("\t-> Informe sua op��o: ");

        // Recebe a op��o do usu�rio e a atribui para a vari�vel codOpcao
        fflush(stdin);
        scanf("%c", &codOpcao);

        // Switch que decide o que fazer com a op��o do usu�rio no menu
        switch(codOpcao){
            case 'n':
            case 'N': fazerPedido(&quantPedidos, &total); break; // Fazer um novo pedido, atribuindo o endere�o das vari�veis total e quantPedidos
            case 'e':
            case 'E': encerrarPedido(&total, quantPedidos); break; // Encerra o pedido atual, atribuindo � fun��o o endere�o da vari�vel total e o valor da vari�vel quantPedidos
            case 's':
            case 'S': flagPedindo = encerrarPrograma(total); break; // Encerra o programa dependendo do retorno da fun��o encerrarPrograma, atribui � fun��o a vari�vel total
            default: printf("\nDigite uma op��o v�lida!!!\n"); Sleep(1500); system("cls"); break; // Op��o inv�lida, pede para o usu�rio redigitar
        }
    }
    return 0;
}

float fazerPedido(int *quantPedido, float *total) {
    // Fun��o para realizar um novo pedido
    // Recebe do fun��o main os endere�os das vari�veis quantPedido (int)
    // E da vari�vel total (float)

    int codProduto; // Vari�vel onde � atribuido o c�digo do produto
    int quantProduto=0; // Vari�vel que armazena a quantidade de produtos neste pedido
    float totalPedido=0.0; // Vari�vel que armazena o valor total deste pedido

    system("cls"); // Limpa a tela

    // Card�pio do programa
    printf("*======================================================*\n");
    printf("*==                   MENU IGREBOYS                  ==*\n");
    printf("*==                     CARD�PIO                     ==*\n");
    printf("*======================================================*\n");
    printf("*== C�d.                Produto               Pre�o  ==*\n");
    printf("*== 100                  Pastel               R$3,50 ==*\n");
    printf("*== 101                 Torrada               R$4,00 ==*\n");
    printf("*== 102               Enroladinho             R$1,50 ==*\n");
    printf("*== 103                Suco 500ml             R$3,50 ==*\n");
    printf("*== 104             Refrigerante Lata         R$3,00 ==*\n");
    printf("*======================================================*\n");

    // Loop que pede o c�digo do produto at� que um v�lido (ou 0) seja digitado
    do {
        // Recebe o c�digo do produto e armazena na vari�vel codProduto
        printf("\n-> Informe o c�digo de seu produto (0 para cancelar): ");
        fflush(stdin);
        scanf("%d", &codProduto);

        // Se o c�digo for inv�lido, escreve na tela "Digite um c�digo v�lido!"
        if(codProduto!=0&&(codProduto<100||codProduto>104))
            printf("\nDigite um c�digo v�lido!\n");
    } while(codProduto!=0&&(codProduto<100||codProduto>104));

    // Caso o c�digo de produto selecionado n�o seja 0
    // Este loop ir� pedir a quantidade do produto desejado (at� que seja v�lida / maior ou igual a 1)
    if(codProduto!=0){
        do {
            printf("\n-> Informe a quantidade do produto: ");
            fflush(stdin);
            scanf("%d", &quantProduto);

            // Se a quantidade for inv�lida (menor que 1), escreve na tela "Digite uma quantidade v�lida!"
            if(quantProduto < 1)
                printf("\nDigite uma quantidade v�lida!\n");
        } while(quantProduto < 1);
    }

    // Switch que decide o que fazer com o c�digo do produto selecionado
    // Caso o c�digo for 0, o pedido � cancelado
    // Se n�o, a vari�vel total pedido receber� o valor do produto vezes sua quantidade
    // Caso algum c�digo inv�lido chegue at� aqui, o programa escrever� "UM ERRO OCORREU!" e cancelar� o pedido
    switch(codProduto){
        case 0: printf("\n\nPedido cancelado."); Sleep(1500); return 0;
        case 100: totalPedido = 3.5*quantProduto; break;
        case 101: totalPedido = 4.0*quantProduto; break;
        case 102: totalPedido = 1.5*quantProduto; break;
        case 103: totalPedido = 3.5*quantProduto; break;
        case 104: totalPedido = 3.0*quantProduto; break;
        default: system("cls"); printf("UM ERRO OCORREU!"); Sleep(1500); return 0;
    }

    system("cls"); // Limpa a tela

    // Escreve na tela o c�digo do produto, sua quantidade, e o valor total do pedido
    printf("C�digo: %d\nQuantidade: %d\nTotal deste pedido: R$%.2f", codProduto, quantProduto, totalPedido);

    // Soma � vari�vel "total" da fun��o main o valor total deste pedido
    *total += totalPedido;

    // Soma � vari�vel "quantPedido" da fun��o main a quantidade de produtos deste pedido
    *quantPedido += quantProduto;

    // Dorme por 1 segundo e encerra a fun��o
    Sleep(1000);
    return 0;
}

int encerrarPrograma(float total){
    // Fun��o para encerrar o programa
    // Recebe o valor da vari�vel total da fun��o main (float)

    // Caso o total for maior que 0
    if(total>0.0){
        char confirmarSaida; // Vari�vel para armazenar a op��o de sa�da do usu�rio

        system("cls"); // Limpa a tela

        // Loop infinito at� que haja um return
        while(1) {
            // Pergunta ao usu�rio se quer finalizar ou n�o o pedido em andamento
            printf("*== Voc� n�o finalizou o pedido ==*\n\n");
            printf("Quer continuar?\n");
            printf("\t[S] Sim\n");
            printf("\t[N] N�o\n");

            // Armazena a op��o na vari�vel confirmarSaida
            printf("\t-> Informe sua op��o: ");
            fflush(stdin);
            scanf("%c",&confirmarSaida);

            // Switch que escolhe o que fazer com a op��o selecionada
            switch(confirmarSaida){
                case 'S':
                case 's': return 1; // Continua o pedido de onde parou, retornando 1 como seu resultado
                case 'n':
                case 'N': system("cls"); printf("Volte sempre!\n"); return 0; // Encerra o programa, retornando 0
                default: printf("\nDigite uma op��o v�lida!!!\n"); Sleep(1500); system("cls"); break; // Pede para que uma op��o v�lida seja digitada
            }
        }
    }
    // Caso o total n�o for maior que 0
    else{
        system("cls"); // Limpa a  tela
        printf("Volte sempre!\n"); // Escreve "Volte Sempre"

        return 0; // Encerra o programa, retornando 0
    }
}

int encerrarPedido(float *total, int quantPedidos){
    // Vari�vel para encerrar o pedido atual
    // Recebe o endere�o da vari�vel total da fun��o main (float)
    // E o valor da vari�vel quantPedidos da fun��o main (int)

    system("cls"); // Limpa a tela

    // Caso o valor total for maior que 0
    if (*total>0.0){
        // Escreve na tela o valor total do pedido, a quantidade de produtos e a confirma��o do pagamento
        printf("Total do pedido: R$%.2f\nQuantidade de produtos: %d\n\n", *total, quantPedidos);
        printf("Voc� pagou com sucesso!");

        // Zera o valor total ap�s o pagamento
        *total=0.0;
    }
    // Caso o valor n�o for maior que 0
    else
        // Informa o usu�rio de que n�o h� nenhum pedido em andamento
        printf("N�o h� um pedido em andamento!");

    // Dorme por um segundo e retorna 0 para encerrar a fun��o
    Sleep(1000);
    return 0;
}
