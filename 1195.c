#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}No;

typedef No* Arvore;

No* cria_no(int valor){
    No* novo = malloc(sizeof(No));
    novo -> info = valor;
    novo -> esq = novo -> dir = NULL;
    return novo; 
}

Arvore insere(Arvore r , No *novo){
    No *f , *p;
    if(r == NULL) return novo;  
    f = r;
    while(f != NULL){
        p = f;
        if(f -> info > novo -> info) f = f -> esq;
        else f = f -> dir;
    }
    if(p -> info > novo -> info) p -> esq = novo;
    else p -> dir = novo;
    return r;
}

void pre_ordem(Arvore r){
    if(r != NULL){
        printf(" %d" , r -> info);
        pre_ordem(r -> esq);
        pre_ordem(r -> dir);
    }
}

void em_ordem(Arvore r){
    if(r != NULL){
        em_ordem(r -> esq);
        printf(" %d" , r -> info);
        em_ordem(r -> dir);
    }
}

void pos_ordem(Arvore r){
    if(r != NULL){
        pos_ordem(r -> esq);
        pos_ordem(r -> dir);
        printf(" %d" , r -> info);
    }
}

void libera_arvore(Arvore r){
    if(r != NULL){
        libera_arvore(r -> esq);
        libera_arvore(r -> dir);
        free(r);
    }
}

int main(){
    int c , n , valor; 
    Arvore r;

    scanf("%d" , &c);

    for(int i = 0 ; i < c ; i++){
        r = NULL;
        scanf("%d" , &n);
        for(int j = 0 ; j < n ; j++){
            scanf("%d" , &valor);
            No* novo = cria_no(valor);
            r = insere(r , novo);
        }
        printf("Case %d:\n" , i + 1);
        
        printf("Pre.:");
        pre_ordem(r);
        printf("\n");
        
        printf("In..:");
        em_ordem(r);
        printf("\n");

        printf("Post:");
        pos_ordem(r);
        printf("\n");

        libera_arvore(r);
        printf("\n");
    }
    return 0;
}
