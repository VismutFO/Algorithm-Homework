#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 05-15: Уравнение с пропущенными цифрами
В уравнении вида A + B = C, где A, B и C — неотрицательные целые числа, некоторые цифры заменены на знаки вопроса.

Необходимо подставить вместо знаков вопроса такие десятичные цифры, чтобы уравнение стало верным, либо определить, что это невозможно.

На входе подаётся единственная строка текста — уравнение с вопросительными знаками. Длина уравнения не превышает 200 символов. Входные данные не содержат никаких символов,
кроме десятичных цифр, вопросительных знаков, символа «плюс» и символа «равно». Кроме того, после конца строки может следовать символ перевода строки.

На стандартный поток вывода напечатайте уравнение с подставленными вместо знаков вопроса цифрами, если решение существует, и выведите единственное слово No, если решения нет.
Если задача допускает несколько решений, выводите любое. В ответе разрешены ведущие нули (см. примеры).
*/

typedef long long ll;

#define MAXSIZE 210

int first[MAXSIZE], second[MAXSIZE], result[MAXSIZE];
int lenF = 0, lenS = 0, lenR = 0, len;

int states[2][MAXSIZE];// Если 0, то уже пробовали собрать, не получилось, иначе 1
// первый индекс - получили ли мы единичку от предыдущего разряда, второй - номер разряда, начиная с последнего

int bruteForce(int ind, int plus)// 0, если не получилось, иначе 1
{
    if (ind == len) { return (plus == 0 ? 1 : 0); }
    for (int i = 0; i < 10; i++)
    {
        if (first[ind] != -1 && i != first[ind]) { continue; }
        for (int j = 0; j < 10; j++)
        {
            if (second[ind] != -1 && j != second[ind]) { continue; }
            for (int k = 0; k < 10; k++)
            {
                if (result[ind] != -1 && k != result[ind]) { continue; }
                if ((i + j + plus) % 10 == k && states[(i + j + plus) / 10][ind + 1])
                {
                    if (bruteForce(ind + 1, (i + j + plus) / 10))
                    {
                        first[ind] = i;
                        second[ind] = j;
                        result[ind] = k;
                        return 1;
                    }
                    else { states[(i + j + plus) / 10][ind + 1] = 0; }
                }
            }
        }
    }
    return 0;
}

void mySwap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

int myMax(int a, int b) { return (a > b ? a : b); }

int main(int argc, char** argv)
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        first[i] = second[i] = result[i] = 0;
        states[0][i] = states[1][i] = 1;
    }

    char c;
    scanf("%c", &c);
    while (c != '+')
    {
        if (c == '?') { first[lenF++] = -1; }
        else { first[lenF++] = (int)(c - '0'); }
        scanf("%c", &c);
    }

    scanf("%c", &c);
    while (c != '=')
    {
        if (c == '?') { second[lenS++] = -1; }
        else { second[lenS++] = (int)(c - '0'); }
        scanf("%c", &c);
    }

    scanf("%c", &c);
    while (c != '\n')
    {
        if (c == '?') { result[lenR++] = -1; }
        else { result[lenR++] = (int)(c - '0'); }
        scanf("%c", &c);
    }

    for (int i = 0; i < lenF / 2; i++)
    {
        mySwap(&first[i], &first[lenF - i - 1]);
    }
    for (int i = 0; i < lenS / 2; i++)
    {
        mySwap(&second[i], &second[lenS - i - 1]);
    }
    for (int i = 0; i < lenR / 2; i++)
    {
        mySwap(&result[i], &result[lenR - i - 1]);
    }

    len = myMax(myMax(lenF, lenS), lenR);

    if (!bruteForce(0, 0))
    {
        printf("No\n");
        return 0;
    }
    for (int i = lenF - 1; i >= 0; i--)
    {
        printf("%d", first[i]);
    }
    printf("+");
    for (int i = lenS - 1; i >= 0; i--)
    {
        printf("%d", second[i]);
    }
    printf("=");
    for (int i = lenR - 1; i >= 0; i--)
    {
        printf("%d", result[i]);
    }
    printf("\n");
    return 0;
}
