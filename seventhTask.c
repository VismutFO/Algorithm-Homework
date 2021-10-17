#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 02-7: Проверка на перестановочность
На вход программе подается натуральное число N и, далее, N целых чисел. 
Все числа не превосходят 10000 по абсолютной величине. 
Программа должна выводить Yes, если данная последовательность задает перестановку и No в противном случае.
*/

int main(int argc, char** argv)
{
    int n; scanf("%d", &n);
    int* hasBeen = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { hasBeen[i] = 0; }
    for (int i = 0; i < n; i++)
    {
        int temp; scanf("%d", &temp); temp--;
        if (temp < 0 || temp >= n)
        {
            printf("No\n");
            return 0;
        }
        if (hasBeen[temp])
        {
            printf("No\n");
            return 0;
        }
        hasBeen[temp] = 1;
    }
    printf("Yes\n");
    return 0;
}
