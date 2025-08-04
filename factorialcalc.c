#include <stdio.h>
#include <string.h>
#define LENGTH_OF_ANSWER 100

void multiply(int result[], int *length, int next_number)
{
    int carryover = 0;
    for (int i = 0; i < *length; i++)
    {
        int product = (result[i] * next_number) + carryover;
        result[i] = product % 10;
        carryover = product / 10;
    }

    while (carryover)
    {
        result[(*length)++] = carryover % 10;
        carryover /= 10;
    }
}

char *factorial(int n)
{
    int answer[LENGTH_OF_ANSWER];
    static char secondanswer[LENGTH_OF_ANSWER];
    answer[0] = 1;
    int len = 1;

    for (int i = 2; i <= n; i++)
        multiply(answer, &len, i);

    for (int i = 0; i < len; i++)
    {
        secondanswer[len - i - 1] = answer[i] + '0';
    }

    secondanswer[len] = '\0';

    return secondanswer;
}

int main(void)
{
    int c;
    printf("Enter your number to calculate the factorial of - ");
    scanf("%d", &c);
    printf("The factorial of the given number is %s \n", factorial(c));
}