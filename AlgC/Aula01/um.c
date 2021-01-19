#include<stdio.h>
int contador1 = 0;
int contador2 = 0;
int contador3 = 0;
int contador4 = 0;
unsigned int f1 (unsigned int n)
{
    unsigned int i, j, r = 0;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            r += 1;
            contador1 +=1;
        }
    }
    return r;
}

unsigned int f2 (unsigned int n)
{
    unsigned int i, j, r = 0;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= i; j++){
            r += 1;
            contador2 += 1;
        }
    }
    return r;
}

unsigned int f3 (unsigned int n)
{
    unsigned int i, j, r = 0;
    for (i = 1; i <= n; i++){
        for (j = i; j <= n; j++){
            r += j;
            contador3 += 1;
        }
    }
    return r;
}

unsigned int f4 (unsigned int n)
{
    unsigned int i, j, r = 0;
    for (i = 1; i <= n; i++){
        for (j = i; j >= 1; j /= 10){
            r += i;
            contador4 += 1;
        }
    }
    return r;
}

int main(void){
    puts("\nF1\n");
    for(int i=1; i<=15; i++){
        contador1 = 0;
        int resultado = f1(i);
        printf("%d %d %d\n",i,resultado,contador1);
    }

    puts("\nF2\n");

    for(int i=1; i<=15; i++){
        contador2 = 0;
        int resultado = f2(i);
        printf("%d %d %d\n",i,resultado,contador2);
    }
    puts("\nF3\n");
    for(int i=1; i<=15; i++){
        contador3 = 0;
        int resultado = f3(i);
        printf("%d %d %d\n",i,resultado,contador3);
    }
    puts("\nF4\n");
    for(int i=1; i<=15; i++){
        contador4 = 0;
        int resultado = f4(i);
        printf("%d %d %d\n",i,resultado,contador4);
    }

    return 0;
}