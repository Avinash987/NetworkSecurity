// Substitution Cipher
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(void)
{
  char* Plain_text_fnc =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char* Cipher_text_fnc = "ZEBRASCDFGHIJKLMNOPQTUVWXY";
  char Plain_text[1000], Encrypted_text[1000], Decrypted_text[1000];
  printf("Enter the Plain Text \n");
  scanf("%[^\n]%*c",Plain_text);
  for (int i = 0; i < strlen(Plain_text); i++)
  {
    Plain_text[i] = toupper(Plain_text[i]);
  }

  int index = 0;

  for (int i = 0; i < strlen(Plain_text); i++)
  {
    if(isalpha(Plain_text[i])!= 0)
    {
      for (int j = 0; j < strlen(Plain_text_fnc); j++)
        if(Plain_text[i] == Plain_text_fnc[j])
        {
          index = j;
          Encrypted_text[i] = Cipher_text_fnc[index];
        }
    }
    else
      Encrypted_text[i] = Plain_text[i];

  }

  Encrypted_text[strlen(Plain_text)] = '\0';
  printf("The Cipher Text is \n%s\n", Encrypted_text);


  for (int i = 0; i < strlen(Encrypted_text); i++)
  {
    if(isalpha(Encrypted_text[i])!= 0)
    {
      for (int j = 0; j < strlen(Plain_text_fnc); j++)
        if(Encrypted_text[i] == Cipher_text_fnc[j])
        {
          index = j;
          Decrypted_text[i] = Plain_text_fnc[index];
        }
    }
    else
      Decrypted_text[i] = Encrypted_text[i];

  }
  Decrypted_text[strlen(Plain_text)] = '\0';
  printf("The Decrypted Text is \n%s\n", Decrypted_text);
}
/*
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
*/
