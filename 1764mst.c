#include <stdio.h>
#include <stdlib.h>

typedef struct aresta{
    int origem;
    int destino;
    int peso;
}Aresta;

typedef struct arvore{
    int *pai;
    int *rank;
    int tamanho;
}Arvore;

Arvore *cria_arvore(int n){
    Arvore *arv = (Arvore*)malloc(sizeof(Arvore));
    arv -> pai = (int*)malloc(n * sizeof(int));
    arv -> rank = (int*)malloc(n * sizeof(int));
    arv -> tamanho = n;

    for(int i = 0 ; i < n ; i++){
        arv -> pai[i] = i;
        arv -> rank[i] = 0;
    }
    return arv;
}

int encontrar(Arvore *arv , int x){
    if(arv -> pai[x] != x){
        arv -> pai[x] = encontrar(arv , arv -> pai[x]);
    }
    return arv -> pai[x];
}

void unir(Arvore *arv , int a , int b){
    a = encontrar(arv , a);
    b = encontrar(arv , b);

    if(a != b){
        if(arv -> rank[a] < arv -> rank[b]){
            arv -> pai[a] = b;
        }else if(arv -> rank[a] > arv -> rank[b]){
            arv -> pai[b] = a;
        }else{
            arv -> pai[b] = a;
            arv -> rank[a]++;
        }
    }
}

void libera_arvore(Arvore *arv){
    free(arv -> pai);
    free(arv -> rank);
    free(arv);
}

void troca(Aresta *a , Aresta *b){
    Aresta temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(Aresta *arestas , int baixo , int alto){
    int pivo = arestas[alto].peso;
    int i = baixo - 1;

    for(int j = baixo ; j < alto ; j++){
        if(arestas[j].peso <= pivo){
            i++;
            troca(&arestas[i] , &arestas[j]);
        }
    }
    troca(&arestas[i + 1] , &arestas[alto]);
    return i + 1;
}

void quicksort(Aresta *arestas , int baixo , int alto){
    if(baixo < alto){
        int pi = particiona(arestas , baixo , alto);
        quicksort(arestas , baixo , pi - 1);
        quicksort(arestas , pi + 1 , alto);
    }
}

int main(){
    int n , m;
    
    while(scanf("%d %d" , &n , &m) && (n || m)){
        Aresta *arestas = (Aresta*)malloc(m * sizeof(Aresta));

        for(int i = 0 ; i < m ; i++){
            scanf("%d %d %d" , &arestas[i].origem , &arestas[i].destino ,&arestas[i].peso);
        }

        Arvore *arv = cria_arvore(n);

        quicksort(arestas , 0 , m - 1);

        long long custo_total = 0;

        for(int i = 0 ; i < m ; i++){
            if(encontrar(arv , arestas[i].origem) != encontrar(arv , arestas[i].destino)){
                unir(arv , arestas[i].origem , arestas[i].destino);
                custo_total += arestas[i].peso; 
            }
        }

        printf("%lld\n" , custo_total);

        libera_arvore(arv);
        free(arestas);
    }
    return 0;
}
