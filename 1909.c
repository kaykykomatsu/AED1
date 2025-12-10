#include <stdio.h>
#include <string.h>

long long mdc(long long a , long long b){
    while(b){
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long mmc(long long a , long long b){
    if(a == 0 || b == 0) return 0;
    
    long long g = mdc(a , b);
    return (a / g) * b;
}

int main(){
    int n , t;
    while(scanf("%d %d" , &n , &t) == 2){
        if(n == 0 && t == 0) break;

        int tempos[105];
        int i;
        for(i = 0 ; i < n ; ++i){
            scanf("%d" , &tempos[i]);
        }

        int presente[100001] = {0};
        for(i = 0 ; i < n ; ++i){
            if(tempos[i] <= 100000)
                presente[tempos[i]] = 1;
        }

        long long mmc_atual = 1;
        for(i = 0 ; i < n ; ++i){
            mmc_atual = mmc(mmc_atual , tempos[i]);
            if(mmc_atual > t) break;
        }

        if(mmc_atual > t || (t % mmc_atual) != 0){
            printf("impossivel\n");
            continue;
        }

        int achou = 0;
        for(int x = 2 ; x <= t ; ++x){
            if(t % x != 0) continue;
            if(presente[x]) continue;
            long long novo_mmc = mmc(mmc_atual , x);
            if(novo_mmc == t){
                printf("%d\n" , x);
                achou = 1;
                break;
            }
            if(novo_mmc > t) continue;
        }
        if(!achou) printf("impossivel\n");
    }
    return 0;
}