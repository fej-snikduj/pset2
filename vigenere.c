#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void cipher(string t, string p);
int main(int argc, string argv[])
{
    int counter = 0;
    if (argc != 2)
    {
        printf("Please input a password (only one word and no spaces).\n");
        return 1;
    }
    string password = argv[1];
    //check to make sure all characters in password are letters
    for (int i=0, n=strlen(password); i < n; i++)
    {
        if (isalpha(password[i]))
        counter++;
    }
    
    //if all characters are letters and argc=2, then prompts use for strings and runs cipher function
    if (argc == 2 && counter == strlen(password))
    {
        string text=GetString();
        cipher(text, password);
        return 0;
    }
    //if user inputted more arguments than allowed or non alphabet characters, error message
    else
    {
        printf("Please input a password containing only uppercase and lowercase letters.  THANK YOU.\n");
        return 1;
    }
}

//this function runs the cipher of the text
void cipher(string t, string p)
{
    int passwordindex = 0, UC_A = (int)'A', LC_A = (int)'a', text=0, shiftp=0, shiftt=0;
    for (int i=0, a=strlen(t), b=strlen(p) ; i < a; i++)
    {
        passwordindex = passwordindex%b;
        text=(int)t[i]; int password = (int)p[passwordindex];
        if (isupper(t[i]))
        //for an uppercase text character
        {
            if (isupper(p[passwordindex]))
            //for an uppercase password character and uppercase text
            {
                shiftp = password - UC_A, shiftt = text - UC_A;
                printf("%c",(char)(UC_A + (shiftt + shiftp)%26));
                passwordindex++;
            }
            else
            //for a lowercase password character and uppercase text
            {
                shiftp = password - LC_A, shiftt = text - UC_A;
                printf("%c",(char)(UC_A + (shiftt + shiftp)%26));
                passwordindex++;
            }
        }
        else if (islower(t[i]))
        //for a lowercase text character
        {
            if (isupper(p[passwordindex]))
            //for an uppercase password character and lowercase text
            {
                shiftp = password - UC_A, shiftt = text - LC_A;
                printf("%c",(char)(LC_A + (shiftt + shiftp)%26));
                passwordindex++;
            }
            else
            //for a lowercase password character and lowercase text
            {
                shiftp = password - LC_A, shiftt = text - LC_A;
                printf("%c",(char)(LC_A + (shiftt + shiftp)%26));
                passwordindex++;
            }
        }
        else
        {
            printf("%c", (char)text);
        }
    }
    printf("\n");
}