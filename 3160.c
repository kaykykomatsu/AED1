#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char nome[101];
    struct no *prox;
}No;

typedef struct list{
    No *head;
    No *tail;
}List;

List *cria_lista(){
    List *list = (List*)malloc(sizeof(List));
    list -> head = list -> tail = NULL;
    return list;
}

void append(List *list , char *name){
    No *novo = (No*)malloc(sizeof(No));
    strcpy(novo -> nome , name);
    novo -> prox = NULL;

    if(list -> tail == NULL){
        list -> head = list -> tail = novo;
    }else{
        list -> tail -> prox = novo;
        list -> tail = novo;
    }
}

void insert_before(List *list , char *target , List *novoAmigo){
    if(novoAmigo -> head == NULL) return;

    if(list -> head == NULL || strcmp(list -> head -> nome , target) == 0){
        novoAmigo -> tail -> prox = list -> head;
        list -> head = novoAmigo -> head;
        if(list -> tail == NULL){
            list -> tail = novoAmigo -> tail;
        }
        return;
    }

    No *atual = list -> head;
    while(atual -> prox != NULL && strcmp(atual -> prox -> nome , target) != 0){
        atual = atual -> prox;
    }

    if(atual -> prox != NULL){
        novoAmigo -> tail -> prox = atual -> prox;
        atual -> prox = novoAmigo -> head;
    }else{
        atual -> prox = novoAmigo -> head;
        list -> tail = novoAmigo -> tail;
    }
}

void imprime(List *list){
    No *atual = list -> head;
    int primeiro = 1;

    while(atual != NULL){
        if(!primeiro) printf(" ");
        printf("%s" , atual -> nome);
        primeiro = 0;
        atual = atual -> prox;
    }
    printf("\n");
}

void libera(List *list){
    No *atual = list -> head;
    while(atual != NULL){
        No *temp = atual;
        atual = atual -> prox;
        free(temp);
    }
    free(list);
}

int main(){
    char line[10001];
    List *amigosAtuais = cria_lista();
    List *novosAmigos = cria_lista();
    char target[101];

    if(fgets(line , sizeof(line) , stdin)){
        char *token = strtok(line , " \n");
        while(token != NULL){
            append(amigosAtuais , token);
            token = strtok(NULL , " \n");
        }
    }

    if(fgets(line , sizeof(line) , stdin)){
        char *token = strtok(line , " \n");
        while(token != NULL){
            append(novosAmigos , token);
            token = strtok(NULL , " \n");
        }
    }

    if(fgets(target , sizeof(target) , stdin)){
        target[strcspn(target , "\n")] = '\0';
    }

    if(strcmp(target , "nao") == 0){
        if(amigosAtuais -> tail != NULL && novosAmigos -> head != NULL){
            amigosAtuais -> tail -> prox = novosAmigos -> head;
            amigosAtuais -> tail = novosAmigos -> tail;
        }else if(novosAmigos -> head != NULL){
            amigosAtuais -> head = novosAmigos -> head;
            amigosAtuais -> tail = novosAmigos -> tail;
        }
    }else{
        insert_before(amigosAtuais , target , novosAmigos);
    }

    imprime(amigosAtuais);

    libera(amigosAtuais);
    free(novosAmigos);

    return 0;
}