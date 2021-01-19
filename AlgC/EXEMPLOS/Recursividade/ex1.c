#include<stdio.h>

double p1(double x, unsigned int n){
    if(n==0){
        return 1;
    }
    else if(n==1){
        return x;
    }
    else{
        return x*p1(x,n-1);
    }
}

int main(void){
    double res = p1(3,2);
    printf("res = %f\n",res);
    return 0;
}