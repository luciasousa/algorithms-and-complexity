#include<stdio.h>
#include <assert.h>
int count = 0;
int function(int arr[], int n){
    assert(n > 1);
    int i;
    int j;
    int ncomp = 0;
    int maior = 0;
    int indice = -1;
    for(i = 1; i < n; i++){
        for(j = i; j > 0 ; j--){
            ncomp++;
            if(arr[j] < arr[i]){
                count++;
            }
        }
        if (count > maior){
            indice = i;
            maior = count;
        }
        count = 0;
    }
    
    if(maior == 0){
        indice = -1;
    }

    printf("Comp: %d\n",ncomp);

    return indice;
   
}    

int main(void){

    int arr[] = {2,2,2,2,2};
    int res = function(arr,5);
    printf("Indice: %d\n",res);
    return 0;
}