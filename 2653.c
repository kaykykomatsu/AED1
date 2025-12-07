#include <stdio.h>
#include <stdlib.h>

int main(){
    char joias[1000][1000];
    int n = 0;

    while(scanf("%s" , joias[n]) != EOF){
        int repetida = 0;
        for(int i = 0 ; i < n ; i++){
            if(strcmp(joias[i] , joias[n]) == 0){
                repetida = 1;
                break;
            }
        }
        if(!repetida) n++;
    }
    printf("%d\n" , n);
    return 0;
}