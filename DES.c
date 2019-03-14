// DATA ENCRYPTION STANDARD
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* stringToBinary(char* s)
{
    if(s == NULL) return 0; /* no input string */
    size_t len = strlen(s);
    char *binary = malloc(len*8 + 1); // each char is one byte (8 bits) and + 1 at the end for null terminator
    binary[0] = '\0';
    for(size_t i = 0; i < len; ++i) {
        char ch = s[i];
        for(int j = 7; j >= 0; --j){
            if(ch & (1 << j)) {
                strcat(binary,"1");
            } else {
                strcat(binary,"0");
            }
        }
    }
    return binary;
}

int main(void)
{
  char string[1000];
  printf("Enter the Plain Text \n");
  scanf("%s",string);

  char key[7];
  printf("Enter the Key of 7 characters \n");
  scanf("%s",key);
  printf("%s\n, %s\n",string, key);
  // CONVERT THE STRING & KEY INTO BINARY

  char* b_text = stringToBinary(string);
  char* b_key = stringToBinary(key);

  printf("%s\n, %s\n",b_text, b_key);


}
