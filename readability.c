#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main()
{
    string text = get_string("Enter text here: ");
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                       'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
                       'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                       'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int letters = 0;
    for (int i = 0; i < strlen(text); i++) {
        for (int j = 0; j < 52; j++) {
            if (text[i] == alphabet[j])
            {
                letters++;
            }
        }
    }
    int spaces = 0;
    int punctuation = 0;
    for (int i = 0; i < strlen(text);i++)
    {
    if (text[i] == ' ')
    {spaces++;}
    if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
    {punctuation++;}
    }
    int words = spaces + 1;
    float L = (100 / (float) words) * letters;
    float S = (100 / (float) words) * punctuation;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    //printf("%i letter(s)\n", letters);
    //printf("%i word(s)\n", words);
    //printf("%i sentence(s)\n", punctuation);
    if (index < 1) {
	printf("Before Grade 1\n");
    }
	else if (index >= 16) {
	printf("Grade 16+\n");
    }
	else {
	printf("Grade %i\n", index);
    }
}
