#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int inverte(int x){
    int r = 0;
    while(x > 0){
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return r;
}

int bfs(int a , int b){
    int dist[MAX];
    for(int i = 0 ; i < MAX ; i++) dist[i] = -1;

    int fila[MAX] , frente = 0 , tras = 0;
    fila[tras++] = a;
    dist[a] = 0;

    while(frente < tras){
        int u = fila[frente++];
        if(u == b) return dist[u];

        if(u + 1 < MAX && dist[u + 1] == -1){
            dist[u + 1] = dist[u] + 1;
            fila[tras++] = u + 1;
        }

        int v = inverte(u);
        if(v < MAX && dist[v] == -1){
            dist[v] = dist[u] + 1;
            fila[tras++] = v;
        }
    }
    return -1;
}

int main(){
    int t;
    scanf("%d" , &t);
    while(t--){
        int a , b;
        scanf("%d %d" , &a , &b);
        printf("%d\n" , bfs(a , b));
    }
    return 0;
}
