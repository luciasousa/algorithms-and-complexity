int pesqBinRec(int* v, int esq, int dir, int valor){

    unsigned int meio;
    int count = 0; //count comparações
    if(esq > dir){
        return -1;
    }

    //Posso omitir esta segunda condição
    if(esq == dir){
        count++;
        if(v[esq] == valor){
            return esq;
        }
        else{
            return -1;
        }
    }
    //-----------------------------------

    meio = (esq + dir) / 2;
    count++;
    if(v[meio] == valor){
        return meio;
    }
    count++;
    if(v[meio] > valor){
        return pesqBinRec(v,esq,meio-1,valor);
    }

    return pesqBinRec(v,meio+1,dir,valor);
}