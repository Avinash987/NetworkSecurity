#include <stdio.h>

main(){
    int i,len;
    char str[] = "Hello World";
    char str1[11];
    char str2[11];
    len = strlen(str);
    for( i = 0; i < len; i++)
    {
        str1[i] = str[i]^0;
        printf("%c",str1[i]);
    }
    printf("\n");
    for( i = 0; i < len; i++)
    {
        str2[i] = str[i]&127;
        printf("%c",str2[i]);
    }
    printf("\n");
    
}
