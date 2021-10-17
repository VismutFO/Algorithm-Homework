#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 02-8: Золотая середина
На вход программе подается натуральное число N (N ≤ 4000) и последовательность натуральных чисел a1, a2,... aN (ai ≤ 100000).
Требуется найти, сколько существует троек натуральных чисел (i, j, k) таких, что:

1 ≤ i < k < j ≤ N
k = (i + j) / 2
ak = (ai + aj) / 2
*/

int main(int argc, char** argv)
{
    int n; scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }
    int ans = 0;
    for (int k = 0; k < n; k++)
    {
        for (int len = 1; k - len >= 0 && k + len < n; len++)
        {
            if (arr[k] * 2 == arr[k - len] + arr[k + len])
            {
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
