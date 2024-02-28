#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//trebuie sa mai schimb
void randomPasswordGeneration()
{
    int i = 0;
    int randomizer = 0;
    srand((unsigned int)(time(NULL)));
    char symbols[] = "!@#$^&*?";
    int N = rand() % 5 + 8;
    char password[N];

    randomizer = rand() % 4;
    for (i = 0; i < N; i++)
    {

        if (randomizer == 1)
        {
            password[i] = (char)(48+ rand() % 26);
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomizer == 2)
        {
            password[i] = symbols[rand() % 8];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomizer == 3)
        {
            password[i] = (char)(65 + rand() % 26);
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else
        {
            password[i] = (char)(97 + rand() % 26);
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
    }
}

int main()
{

    randomPasswordGeneration();

    return 0;
}
