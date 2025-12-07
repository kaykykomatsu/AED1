    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct no{
        int info;
        struct no *prox;
    }No;

    typedef struct grafo{
        int vert;
        No **adj;
    }Grafo;

    Grafo *cria_grafo(int valor){
        Grafo *g = (Grafo*)malloc(sizeof(Grafo));
        g -> vert = valor;
        g -> adj = (No**)calloc(valor , sizeof(No*));
        return g;
    }

    void adiciona_aresta(Grafo *g , int u , int v){
        No *novo = (No*)malloc(sizeof(No));
        novo -> info = v;
        novo -> prox = g -> adj[u];
        g -> adj[u] = novo;
        novo = (No*)malloc(sizeof(No));
        novo -> info = u;
        novo -> prox = g -> adj[v];
        g -> adj[v] = novo;
    }

    void dfs(Grafo *g , int v , int *visitado , char *comp){
        visitado[v] = 1;
        int len = strlen(comp);
        comp[len] = 'a' + v;
        comp[len + 1] = '\0';
        for(No *p = g -> adj [v] ; p ; p = p -> prox)
            if(!visitado[p -> info]) dfs(g , p -> info , visitado , comp);
    }

    void ordena(char *comp){
        int n = strlen(comp);
        for(int i = 0 ; i < n - 1 ; i++){
            for(int j = i + 1 ; j < n ; j++){
                if(comp[i] > comp[j]){
                    char temp = comp[i];
                    comp[i] = comp[j];
                    comp[j] = temp;
                }
            }
        }
    }

    int main(){
        int casos;
        scanf("%d" , &casos);

        for(int c = 1 ; c <= casos ; c++){
            int valor , e;
            scanf("%d %d" , &valor , &e);
            Grafo *g = cria_grafo(valor);
            int *visitado = (int*)calloc(valor , sizeof(int));

            for(int i = 0 ; i < e ; i++){
                char u , v;
                scanf(" %c %c" , &u , &v);
                adiciona_aresta(g , u - 'a' , v - 'a');
            }

            printf("Case #%d:\n" , c);
            int componentes = 0;

            for(int i = 0 ; i < valor ; i++){
                if(!visitado[i]){
                    char comp[50];
                    comp[0] = '\0';

                    dfs(g , i , visitado , comp);
                    ordena(comp);

                    for(int j = 0 ; comp[j] ; j++){
                        printf("%c," , comp[j]);
                    }
                    printf("\n");
                    componentes++;
                }
            }
            printf("%d connected components\n\n" , componentes);

            for(int i = 0 ; i < valor ; i++){
                No *p = g -> adj[i];
                while(p){
                    No *temp = p;
                    p = p -> prox;
                    free(temp);
                }
            }
            free(g -> adj);
            free(g);
            free(visitado);
        }
        return 0;
    }