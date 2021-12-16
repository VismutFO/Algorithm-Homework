#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 06-5: Простой калькулятор
Во входном файле input.txt задано арифметическое выражение, составленное из знаков плюс, минус и натуральных чисел, каждое из которых не превышает 109.
Элементы выражения разделяются нулём или более пробелами. Другие символы во входном файле не встречаются. Все числа, вне зависимости от наличия ведущих нулей,
должны восприниматься как десятичные.

В выходной файл output.txt необходимо вывести результат вычисления выражения.

Гарантируется, что для вычисления результата и всех промежуточных вычислений достаточно типа long long int.

Количество чисел во входном файле не превышает 100000.
*/

typedef long long ll;

char str[1000000];

int main(int argc, char** argv)
{
    FILE *input, *output;
    if ((input = fopen("input.txt", "r")) == NULL)
    {
        printf("abs");
        return 0;
    }
    
    char c;
    int len = 0;
    while (fscanf(input, "%c", &c) > 0)
    {
        if (c == ' ' || c == '\n') { continue; }
        str[len++] = c;
    }
    str[len] = '\0';
    fclose(input);
    ll res = 0LL, znak = 1LL, temp = 0LL;
    int i = 0;
    while (i < len && str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (ll)(str[i] - '0');
        i++;
    }
    while (i < len)
    {
        if (str[i] == '+' || str[i] == '-')
        {
            temp = 0LL;
            znak = (str[i] == '+' ? 1LL : -1LL);
            i++;
            while (i < len && str[i] >= '0' && str[i] <= '9')
            {
                temp = temp * 10LL + (ll)(str[i] - '0');
                i++;
            }
            res += znak * temp;
        }
    }
    output = fopen("output.txt", "w");
    fprintf(output, "%lld", res);
    fclose(output);
    return 0;
}
