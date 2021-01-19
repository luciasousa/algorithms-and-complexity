#include<stdio.h>

long factorial(int n)
{
  if (n == 0){ // Base case
    return 1;
  }
  else{
    return (n*factorial(n-1));
  }
}

int main(void){
    int m = 0;
    for(int a1=0; a1 <= 9; a1++){
        for(int a2=0; a2 <= 9; a2++){
            for(int a3=0; a3 <= 9; a3++){
                
                if(a1!=0 && a2!=0){
                    m +=3;
                    if(a1*100+a2*10+a3==factorial(a1)+factorial(a2)+factorial(a3)){
                        int r = a1*100+a2*10+a3;
                        m +=3;
                        printf("%d é factorião\n",r);
                    }
                }
                if(a1==0 && a2 ==0){
                    if(a3==factorial(a3)){
                        int r = a3;
                        printf("%d é factorião\n",r);
                    }
                }
                if(a1==0 && a2 !=0){
                    m+=2;
                    if(a2*10+a3==factorial(a2)+factorial(a3)){
                        int r = a2*10+a3;
                        m +=2;
                        printf("%d é factorião\n",r);
                    }
                }
            }
        }
    }
    printf("Multiplicacoes: %d\n", m);
    return 0;
}