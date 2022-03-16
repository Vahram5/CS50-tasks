#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Your name?");
    printf("Hi dear %s\n", name);
}