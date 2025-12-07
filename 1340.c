#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct fila{
    int dados[MAX];
    int frente;
    int tras;
}Fila;

void inicializa_fila(Fila *f){
    f -> frente = 0;
    f -> tras = 0;
}

void enqueue(Fila *f , int x){
    f -> dados[f -> tras++] = x;
}

int dequeue(Fila *f){
    if(f -> frente == f -> tras) return -1;
    return f -> dados[f -> frente++];
}

typedef struct pilha{
    int dados[MAX];
    int topo;
}Pilha;

void inicializa_pilha(Pilha *p){
    p -> topo = 0;
}

void push(Pilha *p , int x){
    p -> dados[p -> topo++] = x;
}

int pop(Pilha *p){
    if(p -> topo == 0) return -1;
    return p -> dados[--p -> topo];
}

typedef struct fila_prioridade{
    int dados[MAX];
    int tamanho;
}Fila_Prioridade;

void inicializa_FP(Fila_Prioridade *fp){
    fp -> tamanho = 0;
}

void insereFP(Fila_Prioridade *fp , int x){
    fp -> dados[fp -> tamanho++] = x;
}

int removeFP(Fila_Prioridade *fp){
    if(fp -> tamanho == 0) return -1;
    int indiceMax = 0;
    for(int i = 1 ; i < fp -> tamanho ; i++){
        if(fp -> dados[i] > fp -> dados[indiceMax]){
            indiceMax = i;
        }
    }
    int valor = fp -> dados[indiceMax];
    fp -> dados[indiceMax] = fp -> dados[--fp -> tamanho];
    return valor;
}

int main(){
    int n;
    
    while(scanf("%d" , &n) != EOF){
        Pilha pilha;
        Fila fila;
        Fila_Prioridade fp;

        inicializa_pilha(&pilha);
        inicializa_fila(&fila);
        inicializa_FP(&fp);

        int ehPilha = 1 , ehFila = 1 , ehFP = 1;

        for(int i = 0 ; i < n ; i++){
            int op , x;

            scanf("%d %d" , &op , &x);

            if(op == 1){
                push(&pilha , x);
                enqueue(&fila , x);
                insereFP(&fp , x);
            }else{
                if(pop(&pilha) != x) ehPilha = 0;
                if(dequeue(&fila) != x) ehFila = 0;
                if(removeFP(&fp) != x) ehFP = 0;
            }
        }
        if(ehPilha + ehFila + ehFP == 0){
            printf("impossible\n");
        }else if(ehPilha + ehFila + ehFP > 1){
            printf("not sure\n");
        }else{
            if(ehPilha) printf("stack\n");
            else if(ehFila) printf("queue\n");
            else if(ehFP) printf("priority queue\n");
        }
    }
    return 0;
}