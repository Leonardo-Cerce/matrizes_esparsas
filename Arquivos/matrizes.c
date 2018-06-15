#include "header.h"

#define NUM_MAX_VAL 100000

int main()
{
    {
    FILE *imagem;
    char str[96];
    imagem=fopen("imagem.txt","rt");
    while(fgets(str,sizeof(str),imagem)!=NULL)
    {
        printf("%s",str);
    }
    }
    printf("\n\n\n");
    Sleep(4000);
    system("cls");

    char opt='\0';
    int real;
    matriz *esparsa=NULL;
    matriz *liberar=NULL;
    int lin=0;
    int col=0;
    int loop=1;
    int del=1;
    int atual=0;

    while(loop)
    {
    system("cls");
    printf("<Matriz Esparsa>\n\n");
    printf("1 - Criar matriz\n");
    printf("2 - Adicionar valor em uma posicao\n");
    printf("3 - Excluir matriz\n");
    printf("4 - Consultar valores\n");
    printf("5 - Consultar soma de uma linha\n");
    printf("6 - Consultar soma de uma coluna\n");
    printf("7 - Sair\n\n");


    printf("Escolha uma opcao: ");
    fflush(stdin);
    scanf("%c",&opt);
    real=testav(opt);
    system("cls");

    switch(real)
    {
    case 1:
        {
            if(del==0&&esparsa!=NULL)
            {
                printf("Matriz ja criada!\n\n");
                system("pause");
                break;
            }

            lin=linhas();
            col=colunas();

            esparsa = (matriz*)calloc(NUM_MAX_VAL, sizeof(matriz));
            if(esparsa==NULL)
            {
                printf("Memoria insuficiente.\n");
                return 0;
            }
            liberar=esparsa;

            printf("Matriz esparsa criada!\n\n");
            del=0;
            system("pause");
            break;
        }
    case 2:
        {
            if(del==0&&esparsa!=NULL)
            {
            atual=addvalor(esparsa,lin,col,NUM_MAX_VAL,atual);
            printf("\n\n");
            system("pause");
            break;
            }
            printf("Matriz nao criada.\n\n");
            system("pause");
            break;
        }
    case 3:
        {
            if(del==0&&esparsa!=NULL)
            {
            free(liberar);
            printf("Matriz esparsa apagada.\n\n");
            del=1;
            system("pause");
            break;
            }
            printf("Nao ha matriz para ser apagada.\n\n");
            system("pause");
            break;
        }
    case 4:
        {
            if(del==0&&esparsa!=NULL)
            {
            consultar(esparsa,lin,col,NUM_MAX_VAL);
            printf("\n\n");
            system("pause");
            break;
            }
            printf("Nao ha matriz para ser consultada.\n\n");
            system("pause");
            break;
        }
    case 5:
        {
            if(del==0&&esparsa!=NULL)
            {
            somalin(esparsa,lin,col,atual);
            printf("\n\n");
            system("pause");
            break;
            }
            printf("Nao e possivel efetuar a soma pois a matriz nao foi criada.\n\n");
            system("pause");
            break;
        }
    case 6:
        {
            if(del==0&&esparsa!=NULL)
            {
            somacol(esparsa,col,lin,atual);
            printf("\n\n");
            system("pause");
            break;
            }
            printf("Nao e possivel efetuar a soma pois a matriz nao foi criada.\n\n");
            system("pause");
            break;
        }
    case 7:
        {
            printf("Encerrando o programa...\n\n");
            loop=0;
            break;
        }
    }
    }
}
