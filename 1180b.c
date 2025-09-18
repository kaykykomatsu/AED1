#include <stdio.h>

int main() {

    int n, menor, posicao, x[1000];
    int *p;

    scanf("%d", &n);

    if(n > 1 && n < 1000) {
        for(p = x; p < x + n; p++) {
            scanf("%d", p);
        }
        menor = *x;
        posicao = 0;
        for(p = x + 1; p < x + n; p++) {
            if(*p < menor) {
                menor = *p;
                posicao = p - x;
            }
        }
        printf("Menor valor: %d\n", menor);
        printf("Posicao: %d\n", posicao);
    }
    return 0;
}
