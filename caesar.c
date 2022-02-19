#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, string argv[])
{
    if (argc == 2 && isdigit(*argv[1]))
    {
        int k = atoi(argv[1]);
        string s = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(s) ; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                printf("%c", (((s[i] - 'a') + k) % 26) + 'a');
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                printf("%c", (((s[i] - 'A') + k) % 26) + 'A');
            }
            else
            {
                printf("%c", s[i]);
            }
        }
            printf("\n");
            return 0;
    }
    else
    {
    printf("Usage: ./caesar key\n");
    return 1;
    }
}//Gareth Rogers 2022