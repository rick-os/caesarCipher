#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "caesar_cipher.h"

static char newChar(char old, int key);
static int generateKey();
static int charToInt(char input);
static char intToChar(int input);
static char decryptChar(char encryptedChar, int key);

int caesar_encrypt(char textInput[], char textOutput[])
{
  int i = 0;
  int key = generateKey();

  while(textInput[i] != '\0')
  {
    if((textInput[i] >= 'a' && textInput[i] <= 'z') || (textInput[i] >= 'A' && textInput[i] <= 'Z'))
    {
      textOutput[i] = newChar(textInput[i], key);
    }
    else
    {
      textOutput[i] = textInput[i];
    }
    i++;
  } 
  
  if(textOutput[i] != '\0')
  {
    textOutput[i] = '\0';
  }

  return key;
}
void caesar_decrypt(char textInput[], char textOutput[], int key)
{
  int i = 0;
  
  while(textInput[i] != '\0')
  {
    if(textInput[i] >= 'a' && textInput[i] <= 'z')
    {
      textOutput[i] = decryptChar(textInput[i], key);
    }
    else
    {
      textOutput[i] = textInput[i];
    }
    i++;
  }
  if(textOutput[i] != '\0')
  {
    textOutput[i] = '\0';
  }
}
static char decryptChar(char encryptedChar, int key)
{
  int encryptedInt = charToInt(encryptedChar);
  int decryptedInt = (encryptedInt + (26 - key)) % 26;
  char decryptedChar = intToChar(decryptedInt);

  return decryptedChar;
}
static int charToInt(char input)
{
  int output = 0;

  if(input >= 'a' && input <= 'z')
  {
    output = input - 'a';
  }
  else if(input >= 'A' && input <= 'Z')
  {
    output = input - 'A';
  }
  return output;
}
static char intToChar(int input)
{
  char output = input + 'a';

  return output;
}

static char newChar(char old, int key)
{
  int newInt, oldInt;

  oldInt = charToInt(old);
  newInt = (oldInt + key) % 26;

  char newChar =  intToChar(newInt);

  return newChar;
}

static int generateKey()
{

  srand(time(NULL));
  int key;

  key = rand() % 26 + 1;

  return key;
}
