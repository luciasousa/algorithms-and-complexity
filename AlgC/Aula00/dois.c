#include<stdio.h>

int main(int argc, char* argv[])
{
	puts("Número de linhas da tabela: ");
	int n = 0;
	n = atoi(argv[1]);
	printf("%d!\n",n);
	return 0;
}

