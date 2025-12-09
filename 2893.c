#include <stdio.h>
#include <stdlib.h>

#define MOD 1000007

typedef struct no{
    long long info;
    struct no *prox;
}No;

typedef struct fila{
    No *frente;
    No *tras;
    int tam;
    long long soma;
}Fila;

Fila *cria_fila(){
    Fila *q = (Fila*)malloc(sizeof(Fila));
    q -> frente = q -> tras = NULL;
    q -> tam = 0;
    q -> soma = 0;
    return q;
}

void enqueue(Fila *q , long long valor){
    No *novo = (No*)malloc(sizeof(No));
    novo -> info = valor;
    novo -> prox = NULL;

    if(q -> tras == NULL){
        q -> frente = q -> tras = novo;
    }else{
        q -> tras -> prox = novo;
        q -> tras = novo;
    }
    q -> tam++;
    q -> soma = (q -> soma + valor) % MOD;
}

long long dequeue(Fila *q){
    if(q -> frente == NULL) return 0;

    No *temp = q -> frente;
    long long valor = temp -> info;
    q -> frente  = q -> frente -> prox;

    if(q -> frente == NULL){
        q -> tras = NULL;
    }

    q -> soma = (q -> soma - valor + MOD) % MOD;
    q -> tam--;
    free(temp);
    return valor;
}

void libera(Fila *q){
    while(q -> frente != NULL){
        dequeue(q);
    }
    free(q);
}

int main(){
    int t;
    scanf("%d" , &t);

    while(t--){
        int k , n;
        scanf("%d %d" , &k , &n);

        Fila *q = cria_fila();

        for(int i = 0 ; i < k ; i++){
            enqueue(q , i);
        }

        if(n <= k){
            No *atual = q -> frente;
            for(int i = 1 ; i < n ; i++){
                atual = atual -> prox;
            }
            printf("%lld\n" , atual -> info);
        }else{
            for(int i = k + 1 ; i <= n ; i++){
                long long proximoValor = q -> soma;
                dequeue(q);
                enqueue(q , proximoValor);
            }
            printf("%lld\n" , q -> tras -> info);
        }
        libera(q);
    }
    return 0;
}