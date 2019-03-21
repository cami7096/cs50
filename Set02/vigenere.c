#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int i;
    int j;
    char *plaintext;
    
    i = j = 0;
    // Validate if there is a second argument
    if (argc == 2)
    {
        int *key = malloc(sizeof(int) * strlen(argv[1]));
        while (argv[1][i] != '\0')
        {
            // Validate if the argument is a word and transform it into an                 array of integers
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
                key[i] = argv[1][i] - 'a';
            else if (argv[1][i] >= 'A' && argv[1][i] >= 'Z')
                key[i] = argv[1][i] - 'A';
            else
            {
                printf("Usage: argument must be a word\n");
                return (1);
            }
            i++;
        }
        i = 0;
        // Prompt user for the plaintext
        plaintext = get_string("plaintext: ");
        // Tranform plaintext into the cyphertext using the word prompt as the         word key
        while (plaintext[i] != '\0')
        {
            if (key[j] == '\0')
                j = 0;
            if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                plaintext[i] = ((plaintext[i] - 'a') + key[j]) % 26 + 'a';
                j++;
            }
            else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                plaintext[i] = ((plaintext[i] - 'A') + key[j]) % 26 + 'A';
                j++;
            }
            i++;
        }
        printf("ciphertext: %s\n", plaintext);
        return (0);
    }
    else
    {
        printf("Usage: missing one argument(word)\n");
        return (1);
    }
}
