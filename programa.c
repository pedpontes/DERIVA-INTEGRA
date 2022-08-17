#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "operacoes.h"

int main(){
    int opc;

    system("color 2F");

    do{
        printf("\nDigite uma das opcoes:\n");
        printf("1.\tDescobrir a derivada e se a funcao decresce ou cresce em um ponto especifico, e com qual velocidade isso acontece;\n");
        printf("2.\tDescobrir a integral e a area por baixo da funcao dado um intervalo;\n");
        printf("3.\tDescobrir desvio padrao da pop/amostra,variancia pop. e media;\n");
        printf("4.\tSair!\n");
        printf("Resposta: ");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                derivacao();
                break;
            case 2:
                integral();
                break;
            case 3:
                estatistica();
                break;
            default:
                opc = 4;
                break;
        }
    system("cls");
    }while(opc != 4);
return 0;
}
