#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void CaesarCipher(string s, int k);
int main(int argc, string argv[])
{
    if ((argc == 2) && (atoi(argv[1]) >= 0))
    {
        string n=GetString();
        CaesarCipher(n, atoi(argv[1]));
        return 0;
    }
    else
    {
        printf("You must input an integer greater or equal to 0\n");
        return 1;
        
    }
}
void CaesarCipher(string s, int k)
{
    for (int i=0, n=strlen(s); i < n; i++)
    {
        if (isalpha(s[i]) && isupper(s[i]))
        printf("%c", (char)((int)'A'+ ((int)(s[i]-'A') + k)%26));
        else if (isalpha(s[i]) && islower(s[i]))
        printf("%c", (char)((int)'a'+ ((int)(s[i]-'a') + k)%26));
        else
        printf("%c", s[i]);
    }
    printf("\n");
}