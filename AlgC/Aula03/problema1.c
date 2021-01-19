#include <stdio.h>
#include <assert.h>
int count = 0;
int ncomp = 0;
int function(int arr[], int n){
    assert(n > 1);
   
    int i;
    for(i = 1; i < n; i++){
        ncomp++;
        if(arr[i] != arr[i-1]){
            count ++;
        }
    }
    return count;
}

int main(void){

    int a[] = {1,2,3,3};
    int res = function(a,4);
    printf("%d\n",res);

    return 0;
}