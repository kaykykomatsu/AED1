#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
}No;

void adiciona_vertice(No *adj[] , int x , int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo -> info = valor;
    novo -> prox = adj[x];
    adj[x] = novo;
}

void dfs(int x , No *adj[] , int visitado[] ,int *cont){
    visitado[x] = 1;
    No *p = adj[x];

    while(p != NULL){
        if(!visitado[p -> info]){
            (*cont)++;
            dfs(p -> info , adj , visitado , cont);
            (*cont)++;
        }
        p = p -> prox;
    }
}

int main(){
    int t;
    scanf("%d" , &t);

    while(t--){
        int comeco , v , e;
        scanf("%d %d %d" , &comeco , &v , &e);

        No **adj = (No**)malloc(v * sizeof(No*));
        int *visitado = (int*)malloc(v * sizeof(int));

        for(int i = 0 ; i < v ; i++){
            adj[i] = NULL;
            visitado[i] = 0;
        }

        for(int i = 0 ; i < e ; i++){
            int x , valor;
            scanf("%d %d" , &x , &valor);
            adiciona_vertice(adj , x , valor);
            adiciona_vertice(adj , valor , x);
        }

        int cont = 0;
        dfs(comeco , adj , visitado , &cont);

        printf("%d\n" , cont);

        for(int i = 0 ; i < v ; i++){
            No *p = adj[i];
            while(p != NULL){
                No *temp = p;
                p = p -> prox;
                free(temp);
            }
        }
        free(adj);
        free(visitado);
    }
    return 0;
}