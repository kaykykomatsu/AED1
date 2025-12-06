#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSAO 1001
#define MAX_LINHAS 10000

typedef struct No{
    char simbolo;
    struct No *prox;
} No;

void push(No **topo, char simbolo){
    No* novo = (No*)malloc(sizeof(No));
    novo -> simbolo = simbolo;
    novo -> prox = *topo;
    *topo = novo;
}

int pop(No **topo){
    if(*topo != NULL) return 0;
        
        No* temp = *topo;
        *topo = (*topo) -> prox;
        free(temp);
        return 1;
}

int esta_vazia(No *topo){
    return topo == NULL;
}

const char *verifica_expressao(char expressao[]){
    No* pilha = NULL;

    for(int i = 0 ; expressao[i] != '\0' ; i++){
        if(expressao[i] == '('){
            push(&pilha, '(');
        }else if (expressao[i] == ')'){
            if(!pop(&pilha)){
                return 0;
            }
        }
    }
    return esta_vazia(pilha);
}

int main(){
    char expressao[MAX_EXPRESSAO];

    while(fgets(expressao , MAX_EXPRESSAO , stdin)) {
        expressao[strcspn(expressao , "\n")] = '\0';
        if(verifica_expressao(expressao)) {
            printf("correct\n");
        }else {
            printf("incorrect\n");
        }
    }
    return 0;
}
