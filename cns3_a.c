// Ceaser Cipher

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
  char string[1000];
  char str1[1000], str2[1000];
  printf("Enter the Plain Text \n");
  scanf("%[^\n]%*c",string);

  int key = 0;
  printf("Enter the Key \n");
  scanf("%d",&key);

  for (int i = 0; i < strlen(string); i++)
  {
    if(isalpha(string[i])!= 0 )
    {
      if(isupper(string[i] != 0))
        str1[i] = (char)(((int)string[i] + key - 65) % 26 + 65);
      else
        str1[i] = (char)(((int)string[i] + key - 97) % 26 + 97);
    }
    else
      str1[i] = string[i];
  }

  printf("The Cipher Text is \n%s\n",str1);

  for (int i = 0; i < strlen(str1); i++)
  {
    if(isalpha(str1[i])!= 0 )
    {
      if(isupper(str1[i] != 0))
        str2[i] = (char)(((int)str1[i] - key - 90) % 26 + 90);
      else
        str2[i] = (char)(((int)str1[i] - key - 122) % 26 + 122);
    }
    else
      str2[i] = str1[i];
  }
  printf("The Decrypted Text is \n%s\n",str2);
}
