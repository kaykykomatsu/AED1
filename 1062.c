#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct pilha{
    int dados[MAX];
    int topo;
}Pilha;

void inicializa(Pilha *p){
    p -> topo = 0;
}

void push(Pilha *p , int x){
    p -> dados[p -> topo++] = x;
}

int pop(Pilha *p){
    if(p -> topo == 0) return -1;
    return p -> dados[--p -> topo];
}

int topo(Pilha *p){
    if(p -> topo == 0) return -1;
    return p -> dados[p -> topo - 1];
}

int main(){
    int n;

    while(scanf("%d" , &n) && n){
        while(1){
            int seq[MAX];
            scanf("%d" , &seq[0]);
            if(seq[0] == 0){
                printf("\n");
                break;
            }
            for(int i = 1 ; i < n ; i++){
                scanf("%d" , &seq[i]);
            }

            Pilha pilha;
            inicializa(&pilha);

            int proximo = 1;
            int valido = 1;

            for(int i = 0 ; i < n ; i++){
                int desejado = seq[i];

                while(proximo <= n && (topo(&pilha) != desejado)){
                    push(&pilha , proximo++);
                }

                if(topo(&pilha) == desejado){
                    pop(&pilha);
                }else{
                    valido = 0;
                    break;
                }
            }

            if(valido) printf("Yes\n");
            else printf("No\n");

        }
    }
    return 0;
}