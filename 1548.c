#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int v[] , int n){
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - 1 ; j++){
            if(v[j] < v[j + 1]){
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n , m;
    
    scanf("%d" , &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &m);

        int *original = malloc(m * sizeof(int));
        int *ordenado = malloc(m * sizeof(int));

        for(int j = 0 ; j < m ; j++){
            scanf("%d" , &original[j]);
            ordenado[j] = original[j];
        }

        bubble_sort(ordenado , m);

        int fixos = 0;

        for(int j = 0 ; j < m ; j++){
            if(original[j] == ordenado[j]){
                fixos++;
            }
        }

        printf("%d\n" , fixos);

        free(original);
        free(ordenado);
    }
    return 0;
}
