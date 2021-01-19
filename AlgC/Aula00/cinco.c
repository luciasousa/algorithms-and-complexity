#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	printf("void* ........ %lu\n", sizeof(void*));
	printf("void ......... %lu\n", sizeof(void));
	printf("char ......... %lu\n", sizeof(char));
	printf("short ........ %lu\n", sizeof(short)); 
    printf("int .......... %lu\n", sizeof(int)); 
    printf("long ......... %lu\n", sizeof(long));
    printf("long long .... %lu\n", sizeof(long long));
    printf("float ........ %lu\n", sizeof(float)); 
    printf("double ....... %lu", sizeof(double)); 
	
	return 0;
}

