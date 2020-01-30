#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt_text(string text, string key);
int check_for_duplicates(string text);
int is_letter(string letters);

int main(int argc, string argv[])
{    
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
    return 1;
    }
	else {
		if (strlen(argv[1]) != 26) {
			printf("Key must contain 26 characters.\n");
		return 1;
		}
		else {
			if (check_for_duplicates(argv[1]) != strlen(argv[1])) {
				printf("Usage: ./substitution key\n");
			return 1;
			}
			else {
                if (is_letter(argv[1]) != 0) {
                    printf("Usage: ./substitution key\n");
				return 1;
                }
                else {
                    string text = get_string("plaintext: ");
                    printf("ciphertext: ");
                    encrypt_text(text, argv[1]);
                    printf("\n");
                    return 0;
            }
		    }
	    }
   }
}

void encrypt_text(string text, string key)
{
	for (int i = 0; i < strlen(text); i++) {

	//What happens here is that if text[i] is an upper letter, I am using toupper function 
	//first to place letter within range 0-26 by subtracting 65, and then switch it to 
	//cypher letter by printing one that's in the matchin position and then convert it to upper
	//using toupper function again

		if (text[i] >= 65 && text[i] <= 90) {
			printf("%c", toupper(key[toupper(text[i]) - 65]));
		}

	//Same goes for lower letters as well, with one difference - I am using tolower function
	//at the end to convert cypher letter to lowercase

		else if (text[i] >= 97 && text[i] <= 122) {
			printf("%c", tolower(key[toupper(text[i]) - 65]));
		}
		else if ((text[i] >= 0 && text[i] < 65)
					|| (text[i] > 90 && text[i] < 97)
					|| (text[i] > 122 && text[i] <= 127)) {
				printf("%c", text[i]);
			}
	}
}

int check_for_duplicates(string text)
{
    int counter = 0;
    for (int i = 0; i < strlen(text); i++) {
        for (int j = 0; j < strlen(text); j++) {
            if (text[i] == text[j]) {
                counter++;
            }
        }
    }
   return counter;
}

int is_letter(string letters)
{	
	int is_alpha = 0;
	int is_not_alpha = 0;
	for (int i = 0; i < strlen(letters); i++) {
		if (isalpha(letters[i]) != 0) {
			is_alpha++;
		}
		else {
			is_not_alpha++;
		}
	}
	return is_not_alpha;
}
