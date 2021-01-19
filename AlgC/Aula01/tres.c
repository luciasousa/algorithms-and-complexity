#include<stdio.h>
#include<math.h>
//ver numero de multiplicações
int m = 0;
int main(void){
     for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
             for(int k = 0; k <= 9; k++){
                m +=3;
                if(i*100+j*10+k==pow(i,3)+pow(j,3)+pow(k,3)){
                    int r = 100*i + 10*j + k;
                    printf("%d é um número de Armstrong\n",r);
                    m+=3;
                }
            }
        }
    }
    printf("Multiplicacoes: %d\n", m);
    return 0;
}