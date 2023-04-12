#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_digits(string s);
int ASCII(int num);

int main(int argc, string argv[])
{

    if (argc == 1 || argc != 2) //exit status 1 for ./caesar only and arguments not exactly 2
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    //printf("all goods isang argument lang!\n");

    only_digits(argv[1]);


    string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"; //prevents index out of bounds
    string alpha = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"; //prevents index out of bounds

    int inter = atoi(argv[1]); //converts the string into an integer inter lmao

    //this for loop blocks converts keys greater than 26 into its corresponding number that is between the range of (0,26)
    for (int i = 0; i < 26; i++)
        while (inter > 26)
        {
            inter = inter - 26;
        }

    //plaintext input
    string plain = get_string("plaintext: ");

    for (int v = 0; v < strlen(plain); v++) //iterates over the plain text
    {
        if (isupper(plain[v])) //checks if the character of the plain text is uppercase
        {
            for (int q = 0; q < strlen(ALPHA); q++) //iterates over the ALPHA string array
            {
                if (plain[v] == ALPHA[q]) //if a char in plain is equal to ALPHA we take into account its index q
                {
                    plain[v] = ALPHA[q + inter]; //q + inter to cipher the char
                    //printf("%c", plain[v]);
                    break;
                }
            }
        }
        else if (islower(plain[v])) //checks if the character of the plain text is lowercase
        {
            for (int q = 0; q < strlen(alpha); q++) //iterates over the alpha string array
            {
                if (plain[v] == alpha[q]) //if a char in plain is equal to alpha we take into account its index q
                {
                    plain[v] = alpha[q + inter]; //q + inter to cipher the char
                    //printf("%c", plain[v]);
                    break;
                }
            }
        }
    }
    //ciphertext output
    printf("ciphertext: %s\n", plain);
    //printf("%i\n", inter);
}

//required function from the specs, basically checks if the input is numeric
bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            ;
        }
        else
        {
            //printf("Usage: ./caesar key\n");
            exit(1);
        }
    }
    //printf("all goods integer siya!\n");
    return true;
}
