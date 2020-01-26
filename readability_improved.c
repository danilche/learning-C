//improved readability program

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int check_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main()
{
    string text = get_string("Enter text here: ");
    int letters = check_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = (100 / (float) words) * letters;
    float S = (100 / (float) words) * sentences;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1) 
    {
		printf("Before Grade 1\n");
    }
	else if (index >= 16) 
	{
		printf("Grade 16+\n");
    }
	else 
	{
		printf("Grade %i\n", index);
    }
}

int check_letters(string text)
{
	int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 60 && text[i] <= 90)
             || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
	int spaces = 0;
    for (int i = 0; i < strlen(text);i++)
    {
		if (text[i] == ' ')
		{
			spaces++;
		}
	}
    int words = spaces + 1;
    return words;
}

int count_sentences(string text)
{
	int punctuation = 0;
    for (int i = 0; i < strlen(text);i++)
    {
		if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
		{
			punctuation++;
		}
    }
    return punctuation;
}
