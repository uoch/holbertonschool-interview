#include <stdio.h>
#include <stdlib.h>
#include "mul.h"

int str_len(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        ;

    return (i);
}

void print_error(void)
{
    _putchar('E');
    _putchar('r');
    _putchar('r');
    _putchar('o');
    _putchar('r');
    _putchar('\n');
}

int is_digit(char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    int len1, len2, i;
    int *num1, *num2, *result;

    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
    {
        print_error();
        exit(98);
    }

    len1 = str_len(argv[1]);
    len2 = str_len(argv[2]);

    num1 = malloc(sizeof(int) * len1);
    num2 = malloc(sizeof(int) * len2);

    if (num1 == NULL || num2 == NULL)
    {
        print_error();
        exit(98);
    }

    for (i = 0; i < len1; i++)
        num1[i] = argv[1][i] - '0';

    for (i = 0; i < len2; i++)
        num2[i] = argv[2][i] - '0';

    result = malloc(sizeof(int) * (len1 + len2));
    if (result == NULL)
    {
        print_error();
        exit(98);
    }

    /* Multiplication logic */
    for (i = 0; i < len1 + len2; i++)
        result[i] = 0;

    for (i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            result[i + j + 1] += num1[i] * num2[j];
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }

    /* Print the result */
    for (i = 0; i < len1 + len2; i++)
    {
        _putchar(result[i] + '0');
    }
    _putchar('\n');

    free(num1);
    free(num2);
    free(result);

    return 0;
}
