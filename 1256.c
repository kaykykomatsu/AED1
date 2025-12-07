#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
}No;

void insere(No **lista , int valor){
    No *novo = malloc(sizeof(No));
    novo -> info = valor;
    novo -> prox = NULL;

    if(*lista == NULL){
        *lista = novo;
    }else{
        No *aux = *lista;
        while(aux -> prox != NULL) aux = aux -> prox;
        aux -> prox = novo;
    }
}

void imprime(int indice , No *lista){
    printf("%d ->" , indice);

    for(No *aux = lista ; aux != NULL ; aux = aux -> prox){
        printf(" %d ->" , aux -> info);
    }
    printf(" \\\n");
}

void libera(No *lista){
    while(lista != NULL){
        No *temp = lista;
        lista = lista -> prox;
        free(temp);
    }
}

int main(){
    int casos;
    scanf("%d" , &casos);

    while(casos--){
        int m , c;
        scanf("%d %d" , &m , &c);

        No **tabela = (No**) calloc(m , sizeof(No*));

        for(int i = 0 ; i < c ; i++){
            int valor;
            scanf("%d" , &valor);
            insere(&tabela[valor % m] , valor);
        }

        for(int i = 0 ; i < m ; i++){
            imprime(i , tabela[i]);
            libera(tabela[i]);
        }
        free(tabela);
        if(casos) printf("\n");
    }
    return 0;
}