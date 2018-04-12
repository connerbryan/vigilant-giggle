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
        int k = atoi(argv[1]);
        string p = get_string("plaintext: ");
        int n = strlen(p);

    printf("ciphertext: ");

        for (int i = 0; i < n; i++)
        {
            if(isalpha(p[i]))
            {
                if(isupper(p[i])) {
                    int m = (((p[i]) - 65) + k)%26;
                    char c = m + 65;
                    printf("%c", c);
                }

                else if(islower(p[i]))
                {
                    int m = ((p[i] - 97) + k)%26;
                    char c = m + 97;
                    printf("%c", c);
                }
        }

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
