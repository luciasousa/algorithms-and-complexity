#include<stdio.h>

void torresDeHanoi(char origem, char auxiliar, char destino, int n){
    if(n == 1){

        contadorGlobalMovs++;
        //imprimir movimento da origem para destino
        moverDisco(origem,destino);

        return;
    }
    //divide and conquer
    torresDeHanoi(origem,destino,auxiliar,n-1);
    //movimento de um disco
    contadorGlobalMovs++;
    moverDisco(origem,destino);
    torresDeHanoi(auxiliar,origem,destino,n-1);
}

int main(void){
    
    return 0;
}