

#include<stdio.h>
#include<string.h>

int main(void)
{
	char* string = "Hello World";
	int i = 0;
	printf("Hello world when AND with 127 : ");
	while(string[i] != '\0')
		printf("%c",string[i++]&127);
	printf("\n");
	i = 0;
	printf("Hello world when OR with 127 : ");
	while(string[i] != '\0')
		printf("%c",string[i++]|127);
	printf("\n");
	i = 0;
	printf("Hello world when XOR with 127 : ");
	while(string[i] != '\0')
		printf("%c",string[i++]^127);
	printf("\n");
  	return 0;
}

