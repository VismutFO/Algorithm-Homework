#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 05-2: Матрица с максимальным следом
Даны N квадратных матриц различной размерности. Требуется вывести матрицу, которая имеет максимальный след.

На стандартном потоке ввода задано натуральное число N и далее N квадратных матриц Mi, каждая размерности Ni. Матрицы заданы следующим образом. Сначала идет размерность, далее идут элементы матрицы по строкам - то есть, в первой строке задана первая строка матрицы, во второй - вторая и так далее. Элементы матриц - целые 32-битные числа.

На стандартный поток вывода напечатайте матрицу, которая имеет наибольший след среди введенных матриц. Если несколько введенных матриц имеют одинаковый максимальный след, выведите ту, которая была введена первой.

Указание: для хранения матриц используйте динамическую память. Считайте, что след любой входной матрицы помещается в 64-битное целое число.
*/

typedef long long ll;

int main(int argc, char** argv)
{
    int n, ansSize = 0;
    scanf("%d", &n);
    ll** ans = NULL;
    ll checkAns = INT64_MIN;
    for (int i = 0; i < n; i++)
    {
        int m;
        scanf("%d", &m);
        ll** temp = (ll**)malloc(m * sizeof(ll*)), checkTemp = 0LL;
        for (int j = 0; j < m; j++)
        {
            temp[j] = (ll*)malloc(m * sizeof(ll));
            for (int k = 0; k < m; k++)
            {
                scanf("%lld", &temp[j][k]);
                if (j == k) { checkTemp += temp[j][k]; }
            }
        }
        if (checkTemp > checkAns)
        {
            free(ans);
            ans = temp;
            ansSize = m;
            checkAns = checkTemp;
        }
        else { free(temp); }
    }
    for (int i = 0; i < ansSize; i++)
    {
        for (int j = 0; j < ansSize; j++)
        {
            printf("%lld ", ans[i][j]);
        }
        printf("\n");
    }
    free(ans);
    return 0;
}
