#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 04-10: Большие префиксы и суффиксы
На стандартном потоке ввода задаются две символьные строки, разделённые символом перевода строки. Каждая из строк не превышает по длине 10^6.
В строках не встречаются пробельные символы.
На стандартный поток вывода напечатайте два числа, разделённых пробелом: первое число — длина наибольшего префикса первой строки, являющегося суффиксом второй;
второе число — наоборот, длина наибольшего суффикса первой строки,
являющегося префиксом второй. Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны).
*/

#define GAP " "

void solve(int k, char** arr, int n)
{
    if (n == 1)
    {
        printf("%s", arr[0]);
        int lenAll = strlen(arr[0]);
        for (int i = 0; i < k - lenAll; i++)
        {
            printf(GAP);
        }
        printf("\n");
        return;
    }
    int lenAll = n - 1;// имеющиеся пробелы
    for (int i = 0; i < n; i++)
    {
        lenAll += strlen(arr[i]);
    }
    int toAll = (k - lenAll) / (n - 1), toSome = (k - lenAll) % (n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%s", arr[i]);
        printf(GAP);
        for (int j = 0; j < toAll; j++)
        {
            printf(GAP);
        }
        if (toSome)
        {
            printf(GAP);
            toSome--;
        }
    }
    printf("%s\n", arr[n - 1]);
}

char buf1[3000009], buf2[3000009];

int main(int argc, char** argv)
{
    fgets(buf1, 1500000, stdin);
    fgets(buf2, 1500000, stdin);
    int len1 = strlen(buf1), len2 = strlen(buf2);
    for (int i = len1; i < len1 + len2 - 1; i++)
    {
        buf1[i] = buf2[i - len1];
    }
    for (int i = len2; i < len1 + len2 - 1; i++)
    {
        buf2[i] = buf1[i - len2];
    }
    buf1[len1 + len2 - 1] = buf2[len1 + len2 - 1] = '\0';
    int n = len1 + len2 - 1;
    int *pi = (int*)calloc(n, sizeof(int));
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && buf1[i] != buf1[j])
        {
            j = pi[j - 1];
        }
        if (buf1[i] == buf1[j]) { ++j; }
        pi[i] = j;
    }
    printf("%d ", pi[n - 1]);

    free(pi);
    pi = (int*)calloc(n, sizeof(int));
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && buf2[i] != buf2[j])
        {
            j = pi[j - 1];
        }
        if (buf2[i] == buf2[j]) { ++j; }
        pi[i] = j;
    }
    printf("%d\n", pi[n - 1]);
    return 0;
}
