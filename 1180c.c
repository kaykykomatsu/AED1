#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, menor, posicao, *x;

  scanf("%d", &n);

  if (n > 1 && n < 1000) {
    x = (int *)malloc(n * sizeof(int));
    if (x == NULL) {
      return 1;
    }

    for (int i = 0; i < n; i++) {
      scanf("%d", &x[i]);
    }

    menor = x[0];
    posicao = 0;

    for (int i = 1; i < n; i++) {
      if (x[i] < menor) {
        menor = x[i];
        posicao = i;
      }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    free(x);
  }
  return 0;
}
