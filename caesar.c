#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string st);
char change(char a, int key);
int main(int argc, string argv[])
{
    //if command line argument is't typed or typed more than 1 argument
    if (argc == 2)
    {
        // if commande line argument isn't only digits
        if (only_digits(argv[1]))
        {
            int key = atoi(argv[1]);
            // if key isn't negative number
            if (key > 0)
            {
                string plaintext = get_string("plaintext:  ");
                printf("ciphertext:  ");
                for (int i = 0; i < strlen(plaintext); i++)
                {
                    printf("%c", change(plaintext[i], key));
                }
                printf("\n");
            }
            else
            {
                return 1;
            }
        }
        // if key contains other symbols
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // if doesn't typed argument or more than 1 
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// check if key inludes non-nomerical symbol
bool only_digits(string st)
{
    int d = 0, o = 0;
    for (int i = 0; i < strlen(st); i++)
    {
        if (isdigit(st[i]))
        {
            d++;
        }
        else
        {
            // "o" will increase if key includes letter, dot or other symbols
            o++;
        }
    }
    //if "o" is more than 0 the function returns 0(flase)
    if (o > 0)
    {
        return 0;
    }
    // in the other case return 1(true)
    else
    {
        return 1;
    }
}

//for encrypting plaintext
char change(char a, int key)
{
    // is symbol a part of alphabet
    if (isalpha(a))
    {
        // is letter lowercase
        if (islower(a))
        {
            int lettercode = a - 97;
            int check = (lettercode + key);
            if (check < 26)
            {
                char changed = check + 97;
                return changed;
            }
            else
            {
                char changed = (check % 26) + 97;
                return changed;
            }
        }
        // other variants except lowercase (uppercase)
        else
        {
            int lettercode = a - 65;
            int check = (lettercode + key);
            if (check < 26)
            {
                char changed = check + 65;
                return changed;
            }
            else
            {
                char changed = (check % 26) + 65;
                return changed;
            }
        }
    }
    //in case of symbol isn't from alphabet return symbol without encrypting
    else
    {
        return a;
    }
}


