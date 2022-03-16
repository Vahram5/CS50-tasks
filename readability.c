#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int letters = 0, sent = 0, index = 0;
    float L, S;
    string s = get_string("Text: ");
    int a = strlen(s);
    //words
    int words = 1;
    for (int i = 0; i < a; i++)
    {
        if ((char) s[i] == (char) 32)
        {
            words += 1;
        }
    }
    //sentences
    for (int i = 0; i < a; i++)
    {
        if ((char) s[i] == (char) 33 || (char) s[i] == (char) 46 || (char) s[i] == (char) 63)
        {
            sent += 1;
        }
    }
    //letters
    for (int i = 0; i < a; i++)
    {
        if (((int) s[i] >= 65 && (int) s[i] <= 90) || ((int) s[i] >= 97 && (int) s[i] <= 122))
        {
            letters += 1;
        }
    }
    L = (float) letters / (float) words * 100;
    S = (float) sent / (float) words * 100;
    index = round(0.0588 * L - 0.296 * S - 15.8);


    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}