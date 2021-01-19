#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "elapsed_time.h"

typedef unsigned long long u64;

u64 P1(int n){
    assert(n>=0);
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return 3*P1(n-1)+2*P1(n-2);
    }
}

u64 P2(int n){
    assert(n>=0);
    u64 a,b,c;
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    a = 0;
    b = 1;
    for(int i = 2; i <= n; i++){
        c = 3*b + 2*a;
        a = b;
        b = c;
    }
    return c;
}

long double P6(int n){
    assert(n>=0);

    long double c1 = 0.24253562503633297352;
    long double c2 = 1.27019663313689157536;

    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    
    return round(c1*expl(c2*n));
    
}

int main(void) {
    printf("\nRECURSIVA\n");
    for(int i = 0; i < 21; i++){

        printf("%d\t%llu\n",i,P1(i));
    }
    printf("\nITERATIVA\n");
    for(int i = 0; i < 21; i++){

        printf("%d\t%llu\n",i,P2(i));
    }
    printf("\nRECORRÊNCIA\n");
    for(int i = 0; i < 21; i++){

        printf("%d\t%Lf\n",i,P6(i));
    }

    return 0;
}
