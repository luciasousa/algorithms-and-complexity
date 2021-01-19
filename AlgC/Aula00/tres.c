#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	puts("Número de linhas da tabela: ");
	int n = 0;
	n = atoi(argv[1]);
	//printf("%d\n",n);
	puts("i quadrados	 raizes");
	puts("-----------------------");
	
	for(double i = 0; i < n; i++){
		printf("%f %f %f\n",i, i*i, sqrt(i));
	}
	return 0;
}
