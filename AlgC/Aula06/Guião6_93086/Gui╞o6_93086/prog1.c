#include<stdio.h>
#include<assert.h>

int numMult;

int motzkinRec(int n){
    assert(n >= 0);

    int res = 0;
    int som = 0;

    if(n == 0 || n == 1){
        return 1;
    }
    int k;
    for(k = 0; k <= n-2; k++){
        //somatório
        som += motzkinRec(k)*motzkinRec(n-2-k);
        numMult++;
    }
    res = motzkinRec(n-1) + som;
    return res;
}

int motzkinDin(int n){
    assert(n >= 0);
    if(n == 0 || n == 1){
        return 1;
    }
    int array[n+1];
    array[0] = 1;
    array[1] = 1;
    int k;
    int m;
    
    for (k = 2; k <= n; k++){
        array[k] = array[k-1];
        int som = 0;
        for (m = 0; m <= (k-2); m++){
            som += array[m]*array[k-2-m];
            numMult++;
        }
        array[k] += som;
    }
    return array[n];
}

int main(void){
    int i;
    printf("\nVersão Recursiva\n");
    printf("n\tMotzkinRec\tNumMult\n");
    for (i = 0; i < 16; i++) {
        numMult=0;
        int res = motzkinRec(i);
        printf("%d\t%d\t\t%d\n",i,res,numMult++);
    }
    int j;
    printf("\nVersão Dinâmica\n");
    printf("n\tMotzkinDin\tNumMult\n");
    for (j = 0; j < 16; j++) {
        numMult=0;
        int res = motzkinDin(j);
        printf("%d\t%d\t\t%d\n",j,res,numMult++);
    }
    return 0;
}