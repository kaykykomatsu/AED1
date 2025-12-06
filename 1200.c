#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char info;
    struct no *esq;
    struct no *dir;
}No;

typedef No* Arvore;

No* cria_no(char c){
    No* novo = (No*)malloc(sizeof(No));
    novo -> info = c;
    novo -> esq = novo -> dir = NULL;
    return novo;
}

No* insere(No* raiz , char c){
    if(raiz == NULL) return cria_no(c);
    if(c < raiz -> info) raiz -> esq = insere(raiz -> esq , c);
    else if(c > raiz -> info) raiz -> dir = insere(raiz -> dir , c);
    return raiz;
}

int busca(Arvore raiz , char c){
    while(raiz){
        if(c == raiz -> info) return 1;
        else if(c < raiz -> info){
            raiz = raiz -> esq;
        }else{
            raiz = raiz -> dir;
        }
    }
    return 0;
}

void prefixo(Arvore raiz , int *primeiro){
    if(raiz == NULL) return;
    if(*primeiro){
        *primeiro = 0 ; printf("%c" , raiz -> info);
    }else
        printf(" %c" , raiz -> info);
    prefixo(raiz -> esq , primeiro);
    prefixo(raiz -> dir , primeiro);
}

void infixo(Arvore raiz , int *primeiro){
    if(raiz == NULL) return;
    infixo(raiz -> esq , primeiro);
    if(*primeiro){
        *primeiro = 0;
        printf("%c" , raiz -> info);
    }else
        printf(" %c" , raiz -> info);
    infixo(raiz -> dir , primeiro);
}

void posfixo(Arvore raiz , int *primeiro){
    if(raiz == NULL) return;
    posfixo(raiz -> esq , primeiro);
    posfixo(raiz -> dir , primeiro);
    if(*primeiro){
        *primeiro = 0;
        printf("%c" , raiz -> info);
    }else
        printf(" %c" , raiz -> info);
}

void libera(Arvore r){
    if(r != NULL){
        libera(r -> esq);
        libera(r -> dir);
        free(r);
    }
}

int main(){
    char c , comando[128];
    Arvore raiz = NULL;

    while(fgets(comando , sizeof(comando) , stdin)){
        comando[strcspn(comando , "\r\n")] = '\0';

        if(strncmp(comando , "I " , 2) == 0){
            char x = comando[2];
            raiz = insere(raiz , x);
        }else if(strncmp(comando , "P " , 2) == 0){
            char x = comando[2];
            if(busca(raiz , x)) printf("%c existe\n" , x);
            else printf("%c nao existe\n" , x);
        }else if(strcmp(comando , "PREFIXA") == 0){
            int primeiro = 1;
            prefixo(raiz , &primeiro);
            printf("\n");
        }else if(strcmp(comando , "INFIXA") == 0){
            int primeiro = 1;
            infixo(raiz , &primeiro);
            printf("\n");
        }else if(strcmp(comando , "POSFIXA") == 0){
            int primeiro = 1;
            posfixo(raiz , &primeiro);
            printf("\n");
        }
    }
    libera(raiz);
    return 0;
}
