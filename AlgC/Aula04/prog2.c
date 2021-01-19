#include<stdio.h>

void function(int* input,int* n){

    int i,j,k;

   /* printf("Array = {");
    for(l = 0; l < *n; l++){
        printf("%d,",input[l]);
    }
    printf("}");
    printf("\n");*/
    int ncomp = 0;
    int ndesl = 0;
    for(i = 0; i < *n; i++){
        for(j = i + 1; j < *n; j++){
            ncomp++;
            if(input[j] == input[i]){
                for(k=j;k<(*n)-1;k++){
                    ndesl++;
                    input[k]=input[k+1];
                }
                j--;
                (*n)--;
            }
        }
    }
   /* printf("Alterado = {");
    for(m = 0; m < *n; m++){
        printf("%d,",input[m]);
    }
    printf("}");
    printf("\n");*/
    printf("Número de comparações = %d\n",ncomp);
    printf("Número de cópias = %d\n",ndesl);
}

int main(void){

    int a0[] = {1,1,1,1} ;
    int n = 4;
    function(a0,&n);

    return 0;
}