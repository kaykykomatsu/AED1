#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int vertice;
    struct no *prox;
}No;

typedef struct grafo{
    No *lista[10010];
    int num_vertices;
}Grafo;

No *cria_no(int v){
    No *novo = malloc(sizeof(No));
    novo -> vertice = v;
    novo -> prox = NULL;
    return novo;
}

void adiciona_aresta(Grafo *g , int u , int v){
    No *novo = cria_no(v);
    novo -> prox = g -> lista[u];
    g -> lista[u] = novo;
}

int dfs_ciclo(int v , int estado[] , Grafo *g){
    estado[v] = 1;
    No *temp = g -> lista[v];
    while(temp){
        if(estado[temp -> vertice] == 1){
            return 1;
        }
        if(estado[temp -> vertice] == 0){
            if(dfs_ciclo(temp -> vertice , estado , g)) return 1;
        }
        temp = temp -> prox;
    }
    estado[v] = 2;
    return 0;
}

int main(){
    int t;
    scanf("%d" , &t);

    while(t--){
        Grafo g;
        int n , m;
        scanf("%d %d" , &n , &m);
        g.num_vertices = n;
        for(int i = 0 ; i <= n ; i++){
            g.lista[i] = NULL;
        }

        for(int i = 0 ; i < m ; i++){
            int u , v;
            scanf("%d  %d" , &u , &v);
            adiciona_aresta(&g , u , v);
        }

        int estado[10010] = {0};
        int ciclo = 0;

        for(int i = 1 ; i <= n && !ciclo ; i++){
            if(estado[i] == 0){
                if(dfs_ciclo(i , estado , &g)){
                   ciclo = 1; 
                }
            }
        }
        if(ciclo) printf("SIM\n");
        else printf("NAO\n");
    }
    return 0;
}