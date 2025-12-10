#include <stdio.h>
#include <string.h>

int main(){
    char linha[128];
    char tempo_str[16];
    int hora , minuto , segundo;
    long segundos_previos = 0;
    double velocidade = 0.0;
    double distancia = 0.0;

    segundos_previos = 0;

    while(fgets(linha , sizeof(linha) , stdin)){
        linha[strcspn(linha , "\r\n")] = '\0';

        int nova_velocidade;
        int campos = sscanf(linha , "%15s %d" , tempo_str , &nova_velocidade);
        if(sscanf(tempo_str , "%d:%d:%d" , &hora , &minuto , &segundo) != 3) continue;

        long segundos_atual = hora * 3600L + minuto * 60L + segundo;
        long delta_segundos = segundos_atual - segundos_previos;
        if(delta_segundos > 0){
            distancia += velocidade * (delta_segundos / 3600.0);
        }
        segundos_previos = segundos_atual;

        if(campos == 1){
            printf("%s %.2f km\n" , tempo_str , distancia);
        }else if(campos == 2){
            velocidade = (double)nova_velocidade;
        }
    }
    return 0;
}