#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
/*---If the executor enters two arguments, i.e. name of the program and a translation value for the cipher---*/
    if (argc == 2)
    {
        string cipher = argv[1];
        int n = strlen(argv[1]);
        string p = get_string("plaintext: ");
        int l = strlen(p);

    printf("ciphertext: ");

/*--Iterating through all values in the sequence to encrypt--*/
        for (int i = 0; i < l; i++)
        {

/*--Creating a variable to correspond to the kth letter of the keyword code, converting that variable to alphabetical value--*/
            if(isalpha(p[i]))
            {
                int k = i % n;
                toupper(cipher[k]);
                int key = cipher[k];
                if(isupper(p[i])) {
                    int m = ((p[i] - 65) + (key -65))%26;
                    char c = m + 65;
                    printf("%c", c);
                }

                else if(islower(p[i]))
                {
                    int m = ((p[i] - 97) + (key-65))%26;
                    char c = m + 97;
                    printf("%c", c);
                }
            }

/*--If non-alphabetical, print the character from the plaintext string as it is--*/
            else    {
                printf("%c", p[i]);
            }
        }
        printf("\n");
    }

/*---If the number of arguments is anything but 2---*/
    else    {
        printf("error\n");
    }
}
