#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int check_character(string text, int key);

int main(int argc, string argv[])
{   
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            
            if (isdigit(argv[1][i]) != 0)
            {
                continue;
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
         }
     }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }  
    int key = atoi(argv[1]) % 26;
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    check_character(text, key);
    printf("\n");
    return 0;
}



int check_character(string text, int key)
{	
	
    for (int i = 0; i < strlen(text); i++) 
  {	
		if (text[i] >= 65 && text[i] <= 90)
		{
			if (text[i] + key > 90)
				{
				printf("%c", (text[i] + key) - 26);
				}
			else if (text[i] + key >= 65 && text[i] + key <= 90)
				{
				printf("%c", text[i] + key);
				}
		}
		else if (text[i] >=97 && text[i] <= 122)
		{
			if (text[i] + key > 122)
				{
				printf("%c", (text[i] + key) - 26);
				}
			else if (text[i] + key >= 97 && text[i] + key <= 122)
				{
				printf("%c", text[i] + key);
				}
		}
		else if ((text[i] >= 0 && text[i] < 65) 
		         || (text[i] > 90 && text[i] < 97)
		         || (text[i] > 122 && text[i] <= 127))
			{
			 printf("%c", text[i]);
			}
  }
    return 0;
}
