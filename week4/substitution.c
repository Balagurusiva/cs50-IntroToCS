 #include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //check the command line argument
    if (argc != 2)
    {
        printf("usage: ./substitution key\n");
        return 1;
    }

    //validate the key that consist only of alphabet
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
       if(!isalpha(key[i]))
       {
           printf("usage: ./substitution key\n");
           return 1;
       }
    }

   //validate the given key consist of 26 character
   if (strlen(key) != 26)
   {
       printf("key must contain 26 character.\n");
       return 1;
   }

   //validate that each each character in the key is unique
   for (int i =0; i < strlen(key); i++)
   {
       for (int j =i + 1; j < strlen(key); j++)
       {
           if (toupper(key[i]) == toupper(key[j]))
           {
               printf("usage: ./substitution key\n");
               return 1;
           }
       }
   }

   //get the plaintext from the user
   string plaintext = get_string("plaintext:");

   //conver all alphabet in the key to uppercase
   for (int i =0; i < strlen(key); i++)
   {
       if (islower(key[i]))
       {
           key[i] = key[i] - 32;
       }
   }

   //print the ciphertext
   printf("ciphertext: ");
   for (int i = 0; i< strlen(plaintext); i++)
   {
       if (isupper(plaintext[i]))
       {
           int letter = plaintext[i] - 65;
           printf("%c",key[letter]);
       }
       else if (islower(plaintext[i]))
       {
           int letter = plaintext[i] - 97;
           printf("%c",key[letter] +32);
       }
       else printf("%c",plaintext[i]);
   }
   printf("\n");
}

