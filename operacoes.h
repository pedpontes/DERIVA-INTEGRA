#ifndef OPERACOES_H_INCLUDED
#define OPERACOES_H_INCLUDED
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
void criarfuncao(){
    float valor = 0;
    int n, exp;

    FILE * apont;
    apont = fopen("polinomio.txt","w");

    printf("Digite o numero de elementos da funcao: ");
    scanf("%d", &n);
    fprintf(apont, "%d ", n);
    printf("\nDigite o coeficiente e a potencia da variavel separados por ',', respectivamente:\n");
    for(int i = 0; i<n; i++){
        scanf("%f,%d", &valor,&exp);
        fprintf(apont, "%.1fx^%d ", valor, exp);
    }
    fclose(apont);
}

float criaramostra(int n){
    FILE *apont;
    apont = fopen("estatistica.txt","w");

    int i;
    float amostra;

    fprintf(apont, "%d", n);
    printf("Digite as amostras separadas por enter: \n");

    for(i = 0; i < n; i++)
    {
        scanf("%f", &amostra);
        fprintf(apont, " %f ", amostra);
    }
    fclose(apont);
    return 0;
}

int estatistica(){
    int n, i, esc;

    FILE *apont;
    apont = fopen("estatistica.txt","r");

    if(apont == NULL){
        printf("Arquivo nao encontrado!\n\n");
        printf("Quantas amostras deseja inserir? ");
        scanf("%d", &n);
        criaramostra(n);
        apont = fopen("estatistica.txt","r");
    }
    else{
        printf("Arquivo encontrado!\n\n");
        printf("\nDeseja criar um arquivo com novos valores? 1 (SIM) 2 (NAO)\n");
        scanf("%d", &esc);
        if(esc == 1){
            printf("\nQuantas amostras deseja inserir? ");
            scanf("%d", &n);
            criaramostra(n);
            fclose(apont);
            apont = fopen("estatistica.txt","r");
        }
    }
    fscanf(apont, "%d", &n);

    float soma = 0, media = 0, distquad[n], desvpop = 0, desvamo = 0, somaquad = 0, vetamostras[n];

    for(i = 0; i < n; i++)
    {
        fscanf(apont, " %f ", &vetamostras[i]);
    }
    for(i = 0; i < n; i++)
    {
        soma =soma + vetamostras[i];
    }

    media = soma / n;

    int j=0;

    for(i = 0; i < n; i++)
    {
        distquad[i] = vetamostras[i] - media;
        distquad[i] *= distquad[i];
        somaquad += distquad[i];
        j++;
    }
    desvpop = somaquad / n;
    desvamo = somaquad / (n-1);

    fclose(apont);
    apont = fopen("estatistica.txt","a");

        fprintf(apont, "\n\nValor medio:  %.3f\n\n", media);
        fprintf(apont, "Soma dos numeros:  %.3f\n\n", soma);
        fprintf(apont, "Numeros totais (n):  %d\n\n", j);
        fprintf(apont, "Desvio padrao da populacao:  %.3lf\n\n", sqrt(desvpop));
        fprintf(apont, "Desvio padrao da amostra:  %.3lf\n\n", sqrt(desvamo));
        fprintf(apont, "Variancia populacional:  %.3f\n\n", desvpop);

    fclose(apont);
    printf("\nFoi criado um arquivo texto 'ESTATISTICA' com os resultados!\n");
    system("PAUSE");
return 0;
}

int derivacao(){
    int arg = 0, esc;

    FILE * apont;
    apont = fopen("polinomio.txt","r");
    if(apont == NULL){
        printf("Arquivo 'polinomio.txt' nao encontrado!");
        criarfuncao();
        apont = fopen("polinomio.txt","r");
    }
    else{
        printf("Arquivo encontrado!\n\n");
        printf("\nDeseja criar um arquivo com novos valores? 1 (SIM) 2 (NAO)\n");
        scanf("%d", &esc);
        if(esc == 1){
            criarfuncao();
            fclose(apont);
            apont = fopen("polinomio.txt","r");
        }
    }

    system("cls");

        //lendo a quantidade de elementos

    fscanf(apont,"%d ", &arg);

    float coef[arg];
    int pot[arg];

        //lendo a funcao

    for(int i = 0; i<arg; i++){
        fscanf(apont, "%fx^%d ", &coef[i], &pot[i]);
    }
    fclose(apont);

        //derivando

    float deriv[arg];
    int potder[arg];

    for(int i = 0;i<arg; i++){
        potder[i] = pot[i]-1;
        deriv[i] = pot[i]*coef[i];
    }

        //imprime a derivada

    apont = fopen("polinomio.txt", "a");
    fprintf(apont, "\nF' = ");
    for(int i = 0; i<arg; i++){
        if(pot[i] != 0 && deriv[i] < 0)
            fprintf(apont," %.1fx^%d ", deriv[i], potder[i]);
        else if(pot[i] != 0 && deriv[i] > 0)
            fprintf(apont," + %.1fx^%d ", deriv[i], potder[i]);
    }

        //descobrindo o ponto

    float valor = 0, x = 0;

    printf("Ponto em X que queira descobrir: ");
    scanf("%f", &x);

    for(int i = 0; i<arg; i++){
        valor = valor + deriv[i]*pow(x, potder[i]);
    }

    if(valor > 0)
        fprintf(apont, "\nA Funcao cresce em %.1f a uma velocidade de %.1f", x, valor);
    else if(valor < 0)
        fprintf(apont, "\nA Funcao decresce em %.1f a uma velocidade de %.1f", x, valor);
    else
        fprintf(apont, "\nA Funcao e um ponto critico em %.1f ou um ponto de sela tendo velocidade igual a 0", x);
    fclose(apont);

    printf("\nFoi criado um arquivo texto 'POLINOMIO' com os resultados!\n");
    system("PAUSE");

return 0;
}

int integral(){
    int arg = 0, esc;

    FILE * apont;
    apont = fopen("polinomio.txt","r");
    if(apont == NULL){
        printf("Arquivo 'polinomio.txt' nao encontrado!");
        criarfuncao();
        apont = fopen("polinomio.txt","r");
    }
    else{
        printf("Arquivo encontrado!\n\n");
        printf("\nDeseja criar um arquivo com novos valores? 1 (SIM) 2 (NAO)\n");
        scanf("%d", &esc);
        if(esc == 1){
            criarfuncao();
            fclose(apont);
            apont = fopen("polinomio.txt","r");
        }
    }

        //lendo a quantidade de elementos

    system("cls");
    fscanf(apont,"%d ", &arg);

    float coef[arg];
    int pot[arg];

        //lendo a funcao

    for(int i = 0; i<arg; i++){
        fscanf(apont, "%fx^%d ", &coef[i], &pot[i]);
    }
    fclose(apont);

        //integrando

    float inte[arg];
    int potint[arg];

    for(int i = 0;i<arg; i++){
        if(pot[i] != -1){
            potint[i] = pot[i]+1;
            inte[i] = (coef[i]/potint[i]);
        }
        else{
            potint[i] = pot[i]+1;
            inte[i] = coef[i];
        }
    }

        //imprime a equação ja integrada

    apont = fopen("polinomio.txt", "a");

    fprintf(apont, "\nIntegral(F) = ");
    for(int i = 0; i<arg; i++){
        if(potint[i] != 0 && inte[i] < 0)
            fprintf(apont," %.1fx^%d ", inte[i], potint[i]);
        else if(potint[i] != 0 && inte[i] > 0)
            fprintf(apont," + %.1fx^%d ", inte[i], potint[i]);
        else if(potint[i] == 0 && inte[i] < 0)
            fprintf(apont," %.1fln(x) ", inte[i]);
        else if(potint[i] == 0 && inte[i] > 0)
            fprintf(apont," + %.1fln(x) ", inte[i]);
    }
    float valor[2] = {0,0}, x[2] = {0,0}, valorf = 0;

    printf("Digite os valores de integracao, valor superior e inferior, respectivamente separados por ',': ");
    scanf("%f,%f", &x[0], &x[1]);

        //calculando a area definida

    for(int j = 0; j< 2; j++){
        for(int i = 0; i < arg; i++){
            if(potint[i] != 0){
                valor[j] = valor[j] + inte[i]*pow(x[j],potint[i]);
            }
            else{
                valor[j] = valor[j] + inte[i]*log(x[j]);
            }
        }
        printf("\n");
    }
    valorf = valor[0] - valor[1];
    if(valorf < 0)
        valorf = valorf*-1;
    fprintf(apont, "\nArea abaixo de Fx = %.1f no intervalo de %.1f a %.1f", valorf, x[0], x[1]);

    fclose(apont);
    printf("\nFoi criado um arquivo texto 'POLINOMIO' com os resultados!\n");
    system("PAUSE");

return 0;
}
#endif // OPERACOES_H_INCLUDED
