#include <stdio.h>
#include <stdlib.h>

void Selecao (int n, int h[]) {
  int i, j, min, x;
  for (i = 0 ; i < n - 1 ; i++) {
    min = i;
    for(j = i+1; j < n; j++)
      if (h[j] < h[min]) min = j;
        x = h[i]; h[i] = h[min]; h[min] = x;
  }
}

int main(){
  int nc , n , *h;

  do{
    scanf("%d" , &nc);
  }while(nc < 1 || nc > 100);

  for(int i = 0 ; i < nc ; i++){
    scanf("%d", &n);
    h = malloc(n * sizeof(int));
    for(int j = 0 ; j < n ; j++){
      do{
        scanf("%d", &h[j]);
      }while(h[j] < 20 || h[j] > 230);
    }

    Selecao(n , h);

    for(int j = 0 ; j < n ; j++){
      printf("%d", h[j]);
      if (j < n - 1) {
        printf(" ");
      }
    }
    printf("\n");
    free(h);
  }
  return 0;
}
