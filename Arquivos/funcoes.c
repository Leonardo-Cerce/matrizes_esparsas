#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "funcoes.h"

int linhas(void)
{
    int num_linhas;
    printf("Adicione o numero de linhas: ");
    for(;;)
    {
    fflush(stdin);
    fscanf(stdin,"%d",&num_linhas);
    if(num_linhas>0)
    {
        break;
    }
    else
    {
        printf("Numero de linhas invalido.\n");
    }
    }
    return num_linhas;
}

int colunas(void)
{
    int num_col;
    printf("Adicione o numero de colunas: ");
    for(;;)
    {
    fflush(stdin);
    fscanf(stdin,"%d",&num_col);
    if(num_col>0)
    {
        break;
    }
    else
    {
        printf("Numero de colunas invalido.\n");
    }
    }
    return num_col;
}

int testav(char k)
{
    int i;

    i=k-'0';

    if(i<1||i>8)
    {
        for(;;)
        {
        printf("Opcao invalida.Tente novamente.\n");
        scanf("%c",&k);
        i=k-'0';
        if(i>=1&&i<=8)
        {
            i=0;
        }

        }
    }
return i;
}

int addvalor(matriz* nova, int numlin, int numcol, int nmax, int numat)
{
    int nlin;
    int ncol;
    int valor;
    char teste;
    int i=1;

    while(i)
    {
        system("cls");
        printf("Digite o numero da linha: ");
    for(;;)
        {
        fflush(stdin);
        scanf("%d",&nlin);
        nlin=nlin-1;
        if(nlin<numlin&&nlin>=0)
        {
            break;
        }
        printf("Valor invalido. Tente novamente. ");
        }
    printf("Digite o numero da coluna: ");
    for(;;)
        {
        fflush(stdin);
        scanf("%d",&ncol);
        ncol=ncol-1;
        if(ncol<numcol&&ncol>=0)
        {
            break;
        }
        printf("Valor invalido. Tente novamente. ");
        }
    printf("Digite o valor a ser inserido: ");
    fflush(stdin);
    scanf("%d",&valor);
    nova[numat].coluna=ncol;
    nova[numat].linha=nlin;
    nova[numat].valor=valor;
    numat+=1;
    fflush(stdin);
    printf("Deseja adicionar mais algum valor? (S para sim e N para nao): ");
    scanf("%c",&teste);
    if(teste=='N'||teste=='n')
    {
        i=0;
    }
    }
    return numat;
}

void consultar(matriz* achar, int numlin, int numcol, int maxi)
{
    int nlin;
    int ncol;
    char teste;
    int find_lin;
    int find_col;
    int j;
    int i=1;

    while(i)
    {
        system("cls");
        printf("Digite o numero da linha: ");
    for(;;)
        {
        fflush(stdin);
        scanf("%d",&nlin);
        nlin=nlin-1;
        if(nlin<numlin&&nlin>=0)
        {
            break;
        }
        printf("Valor invalido. Tente novamente. ");
        }
    printf("Digite o numero da coluna: ");
    for(;;)
        {
        fflush(stdin);
        scanf("%d",&ncol);
        ncol=ncol-1;
        if(ncol<numcol&&ncol>=0)
        {
            break;
        }
        printf("Valor invalido. Tente novamente. ");
        }
    system("cls");
    for(j=0;j<maxi;j++)
    {
        if(achar[j].coluna==ncol)
        {
            find_col=j;
            break;
        }
        find_col=-1;
    }
    for(j=0;j<maxi;j++)
    {
        if(achar[j].linha==nlin)
        {
            find_lin=j;
            break;
        }
        find_lin=-1;
    }
    if(find_col==find_lin&&find_col!=-1)
    {
        printf("Valor na linha %d e coluna %d = %d\n\n",nlin,ncol,achar[find_col].valor);
    }
    else
    {
        printf("Valor na linha %d e coluna %d = 0\n\n",nlin,ncol);
    }
    system("pause");
    printf("\n\n");
    printf("Deseja consultar mais alguma posicao? (S para sim e N para nao): ");
    fflush(stdin);
    scanf("%c",&teste);
    if(teste=='N'||teste=='n')
    {
        i=0;
    }
    }
}

void somalin(matriz* somando, int nlinmax, int ncol, int atual)
{
    int nlin;
    int soma=0;
    int i;

    printf("Digite o numero da linha que deseja obter a soma dos valores: ");
    for(;;)
    {
        fflush(stdin);
        scanf("%d",&nlin);
        nlin=nlin-1;
        if(nlin>=0&&nlin<nlinmax)
        {
            break;
        }
        printf("Linha invalida. Tente novamente. ");
    }
    for(i=0;i<atual;i++)
    {
        if(somando[i].linha==nlin)
        {
            soma+=somando[i].valor;
        }
    }
    if(soma!=0)
    {
        printf("Soma dos valores da linha %d = %d",nlin,soma);
    }
    if(soma==0)
    {
        printf("Soma dos valores da linha %d = 0",nlin);
    }
}

void somacol(matriz* somando2, int ncolmax, int nlin, int atual)
{
    int ncol;
    int soma=0;
    int i;

    printf("Digite o numero da coluna que deseja obter a soma dos valores: ");
    for(;;)
    {
        fflush(stdin);
        scanf("%d",&ncol);
        ncol=ncol-1;
        if(ncol>=0&&ncol<ncolmax)
        {
            break;
        }
        printf("Linha invalida. Tente novamente. ");
    }
    for(i=0;i<atual;i++)
    {
        if(somando2[i].coluna==ncol)
        {
            soma+=somando2[i].valor;
        }
    }
    if(soma!=0)
    {
        printf("Soma dos valores da coluna %d = %d",ncol,soma);
    }
    if(soma==0)
    {
        printf("Soma dos valores da coluna %d = 0",ncol);
    }
}
