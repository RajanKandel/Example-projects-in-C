#include <stdio.h>
#include <ctype.h>

// function to count the number of letters in the file

/* command line input to generate executable file: gcc script_filename -o script_filename.exe
 command line input for running program: script_filename.exe filename_to_count_letters */

// eg command line input
// compile c code: gcc read_file.c -o read_file
// run program: ./read_file.exe ./files/textnum1.txt

int main(int argc, char *argv[])
// argc: argument count, argv: argument vector as the array of string from the command line//
{
    if (argc != 2)
    { /*error handling code*/
        printf("Not enough argument");
    }
    else
    {
        int c;
        int countletters = 0;

        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL)
        { /* Error handling code */
            perror("Error in opening file");
            return (-1);
        }
        else
        {
            do
            {
                c = fgetc(fp);
                printf("%c ", c);
                if (isalpha(c))
                {
                    countletters++;
                }
            } while (!feof(fp));
            fclose(fp);
        }
        printf("\n Number of letters in %s is: %d", argv[1], countletters);

        return (0);
    }
}

// End