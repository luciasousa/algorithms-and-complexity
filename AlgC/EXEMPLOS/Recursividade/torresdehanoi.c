
void torresDeHanoi(char origem,char auxiliar, char destino, int n) {

    if(n == 1) {

        moverDisco(origem,destino);//Imprimir mover da origem para o destino

        return;
    }

    torresDeHanoi(origem,destino,auxiliar,n-1);
    moverDisco(origem,destino);
    torresDeHanoi(auxiliar,origem,destino,n-1);

}