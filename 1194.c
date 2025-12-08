#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char info;
    struct no *esq;
    struct no *dir;
}No;

No* novo_no(char valor){
    No *novo = (No*)malloc(sizeof(No));
    novo -> info = valor;
    novo -> esq = novo -> dir = NULL;
    return novo;
}

No *cria_arvore(char *pre , char *in , int n){
    if(n <= 0) return NULL;

    char raiz = pre[0];
    No *novo = novo_no(raiz);

    int pos;
    for(pos = 0 ; pos < n ; pos++){
        if(in[pos] == raiz) break;
    }

    novo -> esq = cria_arvore(pre + 1 , in , pos);

    novo -> dir = cria_arvore(pre + pos + 1 , in + pos + 1 , n - pos - 1);

    return novo;
}

void pos_ordem(No *raiz){
    if(raiz == NULL) return;
    pos_ordem(raiz -> esq);
    pos_ordem(raiz -> dir);
    putchar(raiz -> info);
}

void libera(No *raiz){
    if(raiz == NULL) return;
    libera(raiz -> esq);
    libera(raiz -> dir);
    free(raiz);
}

int main(){
    int c;
    scanf("%d" , &c);

    while(c--){
        int n;
        char pre[60] , in[60];
        scanf("%d %s %s" , &n , pre , in);

        No *raiz = cria_arvore(pre , in , n);
        pos_ordem(raiz);
        putchar('\n');

        libera(raiz);
    }
    return 0;
}