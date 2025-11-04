#include <stdio.h>
#include <stdlib.h>

void Insercao(int n , int h[]){
  int i , j , x;
  for(j = 1 ; j < n ; j++){
    x = h[j];
    for(i = j - 1 ; i >= 0 && h[i] > x ; i--){
      h[i + 1] = h[i];
    }
    h[i + 1] = x;
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

    Insercao(n , h);

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