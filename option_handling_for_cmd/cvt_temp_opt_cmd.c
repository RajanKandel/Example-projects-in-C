#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// handling the commnad line options/flags

/*
    convert temp in fahrenheit scale to celcius and kelvin using the command line options
    eg: .\cvt_temp_opt_cmd.exe -t 50 -ck Monday Friday
    above cmd line takes 50 as the temp in F and convert to c and k and display for Monday and Friday
*/
int main(int argc, char *argv[])
{
    char *temperature;
    int celciusOn = 0;
    int kelvinOn = 0;
    int count = 0;
    char opt;

    while ((opt = getopt(argc, argv, "ct:k")) != EOF)
    {
        switch (opt)
        {
        case 't':
            temperature = optarg;
            break;
        case 'c':
            celciusOn = 1;
            break;
        case 'k':
            kelvinOn = 1;
            break;
        default:
            fprintf(stderr, "Unknown Option: %s\n", optarg);
            return 1;
        }
    }

    argc -= optind;
    argv += optind;

    if (temperature[0]) // assume the temperature is given in Fahrenheit scale
    {
        printf("Temperature in fahrenheit is %s\n", temperature);
        if (celciusOn || kelvinOn)
        {
            if (celciusOn)
            {
                printf("The temperature in celcius is %f\n", ((atoi(temperature) - 32) * 5.0 / 9));
            }
            if (kelvinOn)
            {
                printf("The temperature in kelvin is %f\n", ((atoi(temperature) - 32) * 5.0 / 9) + 273);
            }

            if (argc != 0)
            {
                puts("for the days: ");
                for (int count = 0; count < argc; count++)
                {
                    puts(argv[count]);
                }
            }
        }
    }
    return 0;
}

// End