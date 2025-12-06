#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}No;

typedef struct arvore{
    No *raiz;
}Arvore;

typedef struct fila_no{
    No *dado;
    struct fila_no *prox;
}Fila_No;

typedef struct fila{
    Fila_No *ini;
    Fila_No *fim;
}Fila;

Fila *cria_fila(){
    Fila *f = malloc(sizeof(Fila));
    f -> ini = f -> fim = NULL;
    return f;
}

int vazia(Fila *f){
    return (f -> ini == NULL);
}

void enfilera(Fila *f , No *dado){
    Fila_No *novo = malloc(sizeof(Fila_No));
    novo -> dado = dado;
    novo -> prox = NULL;
    if(f -> fim == NULL){
        f -> ini = f -> fim = novo;
    }else{
        f -> fim -> prox = novo;
        f -> fim = novo;
    }
}

No* desenfilera(Fila *f){
    if(vazia(f)) return NULL;
    Fila_No *temp = f -> ini;
    No *dado = temp -> dado;
    f -> ini = temp -> prox;
    if(f -> ini == NULL) f -> fim = NULL;
    free(temp);
    return dado;
}

Arvore *cria(void){
    Arvore *arv = malloc(sizeof(Arvore));
    arv -> raiz = NULL;
    return arv;
}

void inserir(No **raiz , int chave){
    if(*raiz == NULL){
        No *novo = malloc(sizeof(No));
        novo -> info = chave;
        novo -> esq = novo -> dir = NULL;
        *raiz = novo;
        return;
    }
    if(chave > (*raiz) -> info){
        inserir(&((*raiz) -> dir) , chave); 
    }else{
        inserir(&((*raiz) -> esq) , chave);
    }
}

void por_nivel(No *raiz){
    if(raiz == NULL) return;

    Fila *Q = cria_fila();
    enfilera(Q , raiz);

    int primeiro = 1;

    while(!vazia(Q)){
        No *atual = desenfilera(Q);
        
        if(primeiro){
            printf("%d" , atual -> info);
            primeiro = 0;
        }else{
            printf(" %d" , atual -> info);
        }

        if(atual -> esq != NULL)
            enfilera(Q , atual -> esq);
        if(atual -> dir != NULL)
            enfilera(Q , atual -> dir);
    }
    printf("\n\n");
    free(Q);
}

void desaloca(No *raiz){
    if(raiz != NULL){
        desaloca(raiz -> esq);
        desaloca(raiz -> dir);
        free(raiz);
    }
}

void libera_arvore(Arvore *arv){
    if(arv != NULL){
        desaloca(arv -> raiz);
        free(arv);
    }
}

int main(){
    int c , n , info;
    Arvore *arv = cria();

    scanf("%d" , &c);
    while(c > 1000){
        scanf("%d" , &c);
    }

    for(int i = 0 ; i < c ; i++){
        scanf("%d" , &n);
        while(n < 1 || n > 500){
            scanf("%d" , &n);
        }
        for(int j = 0 ; j < n ; j++){
            scanf("%d" , &info);
            inserir(&(arv -> raiz) , info);
        }

        printf("Case %d:\n" , i + 1);
        por_nivel(arv -> raiz);
        libera_arvore(arv);
        arv = cria();
    }
    return 0;
}