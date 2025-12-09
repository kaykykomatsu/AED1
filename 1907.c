#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int *info;
    int topo;
    int capacidade;
}Pilha;

int inicia_pilha(Pilha *p , int capacidade){
    p -> info = (int*)malloc((size_t)capacidade * sizeof(int));
    if(!p -> info)
        return 0;
    p -> topo = 0;
    p -> capacidade = capacidade;
    return 1;
}

void libera_pilha(Pilha *p){
    if(p -> info)
        free(p -> info);
    p -> info = NULL;
    p -> topo = 0;
    p -> capacidade = 0;
}

int pilha_vazia(Pilha *p){
    return p -> topo == 0;
}

int pilha_push(Pilha *p , int valor){
    if(p -> topo >= p -> capacidade) return 0;
    p -> info[p -> topo++] = valor;
    return 1;
}

int pilha_pop(Pilha *p , int *out){
    if(p -> topo == 0) return 0;
    p -> topo--;
    *out = p -> info[p -> topo];
    return 1;
}

void dfs_interativa(int sr , int sc , char *grade , char *visitado , Pilha *pilha , int n , int m){
    int inicio = sr * m + sc;
    pilha_push(pilha , inicio);
    visitado[inicio] = 1;

    while(!pilha_vazia(pilha)){
        int cur;
        pilha_pop(pilha , &cur);
        int r = cur / m;
        int c = cur % m;

        if(r - 1 >= 0){
            int ni = (r - 1) * m + c;
            if(!visitado[ni] && grade[ni] == '.'){
                visitado[ni] = 1;
                pilha_push(pilha , ni);
            }
        }

        if(r + 1 < n){
            int ni = (r + 1) * m + c;
            if(!visitado[ni] && grade[ni] == '.'){
                visitado[ni] = 1;
                pilha_push(pilha , ni);
            }
        }

        if(c - 1 >= 0){
            int ni = r * m + (c - 1);
            if(!visitado[ni] && grade[ni] == '.'){
                visitado[ni] = 1;
                pilha_push(pilha , ni);
            }
        }

        if(c + 1 < m){
            int ni = r * m + (c + 1);
            if(!visitado[ni] && grade[ni] == '.'){
                visitado[ni] = 1;
                pilha_push(pilha , ni);
            }
        }
    }
}

int main(void){
    int n , m;

    if(scanf("%d %d" , &n , &m) != 2) return 0;

    char *linha = (char*)malloc((m + 2) * sizeof(char));
    if(!linha) return 0;

    size_t total = (size_t) n * m;
    char *grade = (char*)malloc(total * sizeof(char));
    if(!grade) {
        free(linha);
        return 0;
    }

    for(int i = 0 ; i < n ; i++){
        if(scanf("%s" , linha) != 1){
            free(linha);
            free(grade);
            return 0;
        }
        for(int j = 0 ; j < m ; j++) grade[i * m + j] = linha[j];
    }

    char *visitado = (char*)calloc(total , sizeof(char));
    if(!visitado){
        free(linha);
        free(grade);
        return 0;
    }

    Pilha pilha;
    if(!inicia_pilha(&pilha , (int)total)){
        free(linha);
        free(grade);
        free(visitado);
        return 0;
    }

    int componentes = 0;
    for(int r = 0 ; r < n ; ++r){
        for(int c = 0 ; c < m ; ++c){
            int idx = r * m + c;
            if(grade[idx] == '.' && !visitado[idx]){
                componentes++;
                dfs_interativa(r , c , grade , visitado , &pilha , n , m);
            }
        }
    }

    printf("%d\n" , componentes);

    libera_pilha(&pilha);
    free(linha);
    free(grade);
    free(visitado);
    return 0;

}