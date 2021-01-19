#include<stdio.h>

int numChamRec1;
int numChamRec2;
int numChamRec3;

int t1(int n){
    
    if(n == 0){
        return 0;
    }
    numChamRec1++;
    int r = t1(n/3)+n;
    return r;
}

int t2(int n){
    if(n == 0 || n == 1 || n == 2){
        return n;
    }
    numChamRec2+=2;
    int r = t2(n/3) + t2((n+2)/3) + n;
    return r;
}

int t3(int n){
    
    if(n == 0 || n == 1 || n == 2){
        return n;
    }
    numChamRec3++;
    if(n%3 == 0){
        int r = 2*t3(n/3)+n;
        return r;
    }
    numChamRec3++;
    int r = t3(n/3) + t3((n+2)/3) +n;
    return r;
}

int main(void){
    int i,j,k;
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;

    printf("\n----T1----\n");
    printf("T1(n)\tNumChamadasRecursivas\n");
    for(i=0;i<29;i++){
        res1 = t1(i);
        printf("%d\t%d\n",res1,numChamRec1);
        numChamRec1=0;
    }

    printf("\n----T2----\n");
    printf("T2(n)\tNumChamadasRecursivas\n");
    for(j=0;j<29;j++){
        res2 = t2(j);
        printf("%d\t%d\n",res2,numChamRec2);
        numChamRec2=0;
    }

    printf("\n----T3----\n");
    printf("T3(n)\tNumChamadasRecursivas\n");
    for(k=0;k<29;k++){
        res3 = t3(k);
        printf("%d\t%d\n",res3,numChamRec3);
        numChamRec3=0;
    }

    return 0;
}