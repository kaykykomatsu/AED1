#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001

typedef struct no{
    char simbolo;
    struct no *prox;
}No;

void push(No **topo, char simbolo){
    No* novo = malloc(sizeof(No));
    novo -> simbolo = simbolo;
    novo -> prox = *topo;
    *topo = novo;
}

int pop(No **topo){
    if(*topo == NULL) return 0;
    No* temp = *topo;
    *topo = (*topo) -> prox;
    free(temp);
    return 1;
}

int conta_diamantes(char expressao[]){
    No* pilha = NULL;
    int diamantes = 0;

    for(int i = 0 ; expressao[i] != '\0' ; i++){
        if(expressao[i] == '<'){
            push(&pilha , '<');
        }else if(expressao[i] == '>'){
            if(pilha != NULL){
                pop(&pilha);
                diamantes++;
            }
        }
    }

    while(pilha != NULL){
        pop(&pilha);
    }
    return diamantes;
}

int main(){
    int n;
    char expressao[MAX];

    scanf("%d" , &n);
    getchar();
    
    for(int i = 0 ; i < n ; i++){
        fgets(expressao , MAX , stdin);
        expressao[strcspn(expressao , "\n")] = '\0';
        printf("%d\n" , conta_diamantes(expressao)); 
    }

    return 0;
}
