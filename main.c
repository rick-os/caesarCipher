#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
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
    
    printf("Insert the text: ");
    fgets(textInput, sizeof(textInput), stdin);
    trueSize = getTrueStringSize(textInput);

    char trueText[trueSize];
    copyString(textInput, trueText); 

    switch(option)
    {
      case 1:
        break;
      case 2:
        break;
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
  }while(string[i] != '\0' && string[i] != '\n');

  if(string[i] == '\n')
  {
    string[i] = '\0';
    i--;
  }
  return i;
}
void copyString(char string1[], char string2[])
{
  int i=0;
  do
  {
    string2[i] = string1[i];
    i++
  }while(string[i] != '\0' && string2[i] != '\0');
}
