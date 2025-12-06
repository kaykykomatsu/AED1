#include <stdio.h>
#include <stdlib.h>

void Intercala (int p , int q , int r , int h[]){
    int i , j , k , *w;
    w = malloc((r - p)*sizeof(int));
    i = p; j = q; k = 0;
    while (i < q && j < r){
        if(h[i] <= h[j]) w[k++] = h[i++];
        else w[k++] = h[j++];
    } 
    while(i < q) w[k++] = h[i++];
    while(j < r) w[k++] = h[j++];
    for(i = p ; i < r ; i++) h[i] = w[i - p];
    free(w);
}

void Mergesort(int p , int r , int h[]){
    if(p < r - 1){
        int q = (p + r) / 2;
        Mergesort(p , q , h);
        Mergesort(q , r , h);
        Intercala(p , q , r , h);
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

    Mergesort(0 , n , h);

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
