#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

typedef struct
{
    int linha;
    int coluna;
    int valor;

}matriz;

int colunas(void);

int linhas(void);

int testav(char);

int addvalor(matriz*,int,int,int,int);

void consultar(matriz*,int,int,int);

void somalin(matriz*,int,int,int);

void somacol(matriz*,int,int,int);

int menu(void);

void splash(void);
