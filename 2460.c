#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int info;
    struct cel *prox;
}celula;

typedef struct fila{
    celula *ini;
    celula *fim;
}fila;

void inicializa(fila *f){
    f -> ini = malloc(sizeof(celula));
    f -> ini -> prox = NULL;
    f -> fim = f -> ini;
}

void insere(int y , fila *f){
    celula *nova = malloc(sizeof(celula));
    nova -> info = y;
    nova -> prox = NULL;
    f -> fim -> prox = nova;
    f -> fim = nova;
}

void busca_remove(int x , fila *f){
    celula *p = f -> ini;
    while(p -> prox != NULL){
        if(p -> prox -> info == x){
            celula *q = p -> prox;
            p -> prox = q -> prox;
            if(q == f -> fim){
                f -> fim = p;
            }
            free(q);
            return;
        }
        p = p -> prox;
    }
}


void imprime(celula *lst){
    celula *p = lst -> prox;
    if(p == NULL) return;

    printf("%d", p -> info);
    p = p -> prox;
    while(p != NULL){
        printf(" %d", p -> info);
        p = p -> prox;
    }
    printf("\n");
}

void libera(celula *lst){
    celula *p = lst;
    celula *temp;
    while(p != NULL){
        temp = p -> prox;
        free(p);
        p = temp;
    }
}

int main(){
    int n , id , m , id_removido;
    fila f;
    inicializa(&f);  

    scanf("%d" , &n);
    while(n < 1 || n > 50000){
        scanf("%d" , &n);
    }

    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &id);
        insere(id , &f);
    }

    scanf("%d" , &m);
    while(m < 1 || m > 50000 || m > n){
        scanf("%d" , &m);
    }

    for(int i = 0 ; i < m ; i++){
        scanf("%d" , &id_removido);
        busca_remove(id_removido , &f);
    }

    imprime(f.ini);
    libera(f.ini);

    return 0;
}
