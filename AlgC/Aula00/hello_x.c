#include<stdio.h>

int main(void)
{
	char name[50];
	puts("Whats your name?");
	fgets(name,50,stdin);
	//gets(name) 				//não funciona
	//scanf("%s",name);			//não funciona
	printf("Hello %s", name);

	return 0;
}
