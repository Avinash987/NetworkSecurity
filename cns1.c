

#include<stdio.h>
#include<string.h>

int main(void)
{
	char* string = "Hello World";
	int i = 0;
	while(string[i] != '\0')
		printf("%c",string[i++]^0);
	printf("\n");

}
