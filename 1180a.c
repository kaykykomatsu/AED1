#include <stdio.h>

int main() {

    int n, menor, posicao, x[1000];

    scanf("%d", &n);

    if(n > 1 && n < 1000) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }
        
        menor = x[0];
        posicao = 0;
        
        for(int i = 1; i < n; i++) {
            if(x[i] < menor) {
                menor = x[i];
                posicao = i;
            }
        }
        printf("Menor valor: %d\n", menor);
        printf("Posicao: %d\n", posicao);
    }
    return 0;
}