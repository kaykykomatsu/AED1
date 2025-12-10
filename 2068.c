#include <stdio.h> 

long long mdc(long long a , long long b){
    if(a < 0) a = -a;
    if(b < 0) b = -b;

    while(b != 0){
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    long long t1 , t2 , n;
    
    while(scanf("%lld %lld %lld" , &t1 , &t2 , &n) == 3){
        long long s = (t2 - t1) * 60LL;
        long long numerador = n * (2 * s - n);
        long long denominador = s * s;
        long long g = mdc(numerador , denominador);
        
        numerador /= g;
        denominador /= g;

        printf("%lld/%lld\n" , numerador , denominador);
    }
    return 0;
}