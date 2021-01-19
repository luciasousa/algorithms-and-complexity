#include<stdio.h>
#include <assert.h>

int isValid(int* arr,int n){
    assert(n > 1);
    int i;
    int count = 0;
    int ncomp = 0;
    int res = 0;
    for(i = 0; i < n-1; i++){
        ncomp++;
        if(arr[i+1]-arr[i] != 1){
            printf("Count = %d\tNcomp = %d\tRes = %d\n",count,ncomp,res);
            return 0;
        }
    }
    printf("Count = %d\tNcomp = %d\tRes = %d\n",count,ncomp,res);  
    return 1;
}

int main(void){

    int a0[] = {1,3,4,5,5,6,7,7,8,9};
    int a1[] = {1,2,4,5,5,6,7,8,8,9};
    int a2[] = {1,2,3,6,8,8,8,9,9,9};
    int a3[] = {1,2,3,4,6,7,7,8,8,9};
    int a4[] = {1,2,3,4,5,7,7,8,8,9};
    int a5[] = {1,2,3,4,5,6,8,8,9,9};
    int a6[] = {1,2,3,4,5,6,7,9,9,9};
    int a7[] = {1,2,3,4,5,6,7,8,8,9};
    int a8[] = {1,2,3,4,5,6,7,8,9,9};
    int a9[] = {1,2,3,4,5,6,7,8,9,10};
    
    int res0 = function(a0,10);
    int res1 = function(a1,10);
    int res2 = function(a2,10);
    int res3 = function(a3,10);
    int res4 = function(a4,10);
    int res5 = function(a5,10);
    int res6 = function(a6,10);
    int res7 = function(a7,10);
    int res8 = function(a8,10);
    int res9 = function(a9,10);

    printf("Res = %d\n",res0);
    printf("Res = %d\n",res1);
    printf("Res = %d\n",res2);
    printf("Res = %d\n",res3);
    printf("Res = %d\n",res4);
    printf("Res = %d\n",res5);
    printf("Res = %d\n",res6);
    printf("Res = %d\n",res7);
    printf("Res = %d\n",res8);
    printf("Res = %d\n",res9);

    return 0;
}