#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "caesar_cipher.h"

int selectOption1ToX(int x);
int getTrueStringSize(char string[]);
void copyString(char string1[], char string2[]);

int main(){

  char confirm;
  int textMaxLength = 100 + 1;
  char textInput[textMaxLength];
  int key, trueSize;
  int option;

  do 
  {
    printf("Choose you option: \n");
    printf("1 -> Encrypt Text With Caesar Cipher.\n");
    printf("2 -> Decrypt Text With Key.\n");
    option = selectOption1ToX(2);

    // if I add more options, like without having an text input, I probly need to
    // put a if here verifiyng if the option has text input...
    
    __fpurge(stdin);
    printf("Insert the text: ");
    fgets(textInput, sizeof(textInput), stdin);
    trueSize = getTrueStringSize(textInput);

    __fpurge(stdin);
    char trueText[trueSize];
    copyString(textInput, trueText); 

    char encryptedText[trueSize];

    switch(option)
    {
      case 1: {
        char encryptedText[trueSize];
        do
        {
          __fpurge(stdin);
          key = caesar_encrypt(trueText, encryptedText);
          printf("The encypted text is: ");
          puts(encryptedText);
          printf("Your key is: %d\n", key);

          __fpurge(stdin);
          printf("Do you want to encrypt again?(y/n)");
          scanf(" %c", &option);
          if(option == 'y' || option == 'Y')
          {
            printf("All right, encrypting again...\n");
          }
        }while(option == 'y' || option == 'Y');
        
        break;
      }

      case 2: {
        char decryptedText[trueSize];
        
        __fpurge(stdin);
        printf("Insert your key: ");
        scanf("%d", &key);

        caesar_decrypt(trueText, decryptedText, key);

        printf("Decripted text: ");
        puts(decryptedText);
        break;
      }

      default:
        break;
    }

    __fpurge(stdin);
    printf("Do you want to reexecute the algorithm?(y/n)");
    scanf(" %c", &confirm);
  } while (confirm == 'y' || confirm == 'Y');

  return 0;
}

int selectOption1ToX(int x)
{
  int option;
  bool valid = false;

  do
  {
    printf("Insert the correspondent number: ");
    scanf("%d", &option);

    if(option < 1 || option > x)
    {
      printf("Invalid option, choose between [1, %d].\n", x);
      valid = false;
    }
    else
    {
      valid = true;
      return option;
    }
  }while(valid == false);
}
int getTrueStringSize(char string[])
{
  int i = 0;

  do
  {
    i++;
  }while(string[i] != '\0');

  if(string[i-1] == '\n')
  {
    i--;
    string[i] = '\0';
  }

  return i;
}
void copyString(char string1[], char string2[])
{
  int i=0;
  do
  {
    string2[i] = string1[i];
    i++;
  }while(string1[i] != '\0');

  string2[i] = '\0';
}
