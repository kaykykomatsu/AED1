#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}No;

No *novo_no(int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo -> info = valor;
    novo -> esq = novo -> dir = NULL;
    return novo;
}

void insere(No *raiz , int valor){
    if(valor < raiz -> info){
        if(raiz -> esq == NULL) raiz -> esq = novo_no(valor);
        else insere(raiz -> esq , valor);
    }else{
        if(raiz -> dir == NULL) raiz -> dir = novo_no(valor);
        else insere(raiz -> dir , valor);
    }
}

typedef struct fila_item{
    No *node;
    int nivel;
}Fila_Item;

int main(){
    int n , h;

    scanf("%d" , &n);
    scanf("%d" , &h);

    No *raiz = novo_no(h);

    for(int i = 1 ; i < n ; i++){
        scanf("%d" , &h);
        insere(raiz , h);
    }

    Fila_Item fila[500];
    int frente = 0 , tras = 0;
    fila[tras++] = (Fila_Item){raiz , 0};

    int menorAltura[250];

    for(int i = 0 ; i < 250 ; i++){
        menorAltura[i] = 1000000;
    }

    int nivelMax = 0;

    while(frente < tras){
        Fila_Item fi = fila[frente++];
        No* node = fi.node;
        int nivel = fi.nivel;

        if(node -> info < menorAltura[nivel]) menorAltura[nivel] = node -> info;
        if(nivel > nivelMax) nivelMax = nivel;

        if(node -> esq) fila[tras++] = (Fila_Item){node -> esq , nivel + 1};
        if(node -> dir) fila[tras++] = (Fila_Item){node -> dir , nivel + 1};
    }

    for(int i = 0 ; i <= nivelMax ; i++){
        printf("%d %d\n" , i , menorAltura[i]);
    }

    return 0;
    
}