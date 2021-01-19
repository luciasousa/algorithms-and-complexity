#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	char a[] = "ang";
	char b[] = "sin(ang)";
	char c[] = "cos(ang)";

	
	printf("%2s %6s %6s\n",a,b,c);
	puts("-----------------------");
	
	for(int i = 0; i < 50; i++){
		if(i%5 == 0){
			printf("%2d	%6f %6f\n",i, sin((double) i), cos((double) i));
		}
	}
	
	return 0;
}
