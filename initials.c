#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string n = GetString();
    if (n != NULL)
    {
        //prints capital version of first character in name, plus capital version of first character after each space.
        printf("%c", toupper(n[0]));
        for (int i=0, a = strlen(n); i < a; i++)
        {
            if (n[i] == ' ')
            printf("%c", toupper( n[ i + 1 ]));
        }
        printf("\n");
    }
}