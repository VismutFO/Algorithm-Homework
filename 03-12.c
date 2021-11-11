#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 03-12: Жертвоприношение
Вводится целое число N (1 ≤ N ≤ 14), и следом N целых чисел A1,...,AN (0 ≤ Ai ≤ 100).
Требуется найти два непустых подмножества таких, что сумма их элементов равна и максимальна
среди всех возможных решений (подмножества не должны пересекаться), и вывести эту сумму или 0, если такой пары нет.
*/

int sum = 0;
int n;
int* arr;

void func(int sum1, int sum2, int i)
{
    if (i == n)
    {
        if (sum1 == sum2 && sum1 > sum)
        {
            sum = sum1;
        }
        return;
    }
    func(sum1 + arr[i], sum2, i + 1);
    func(sum1, sum2 + arr[i], i + 1);
    func(sum1, sum2, i + 1);
}

int main(int argc, char** argv)
{
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    func(0, 0, 0);
    printf("%d", sum);
    return 0;
}
