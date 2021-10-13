#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int arr[16];
    int hasRightTower[16];
    for (int i = 0; i < 16; i++)
    {
        scanf("%d", &arr[i]);
        hasRightTower[i] = 0;
    }
    int ans = 0;
    // ходим по строкам, когда нашли ответ, проверяем столбцы
    for (int i = 0; i < 8; i++)
    {
        // сначала пытаемся найти столбец такой, что arr[i] = arr[j+8] и hasRightTower[j+8]=0
        if (!hasRightTower[i])
        {
            for (int j = 0; j < 8; j++)
            {
                if (arr[i] == arr[j + 8] && !hasRightTower[j + 8])
                {
                    ans += arr[i];
                    hasRightTower[i] = hasRightTower[j + 8] = 1;
                    break;
                }
            }
        }
        // потом просто arr[i]=arr[j+8]
        if (!hasRightTower[i])
        {
            for (int j = 0; j < 8; j++)
            {
                if (arr[i] == arr[j + 8])
                {
                    ans += arr[i];
                    hasRightTower[i] = hasRightTower[j + 8] = 1;
                    break;
                }
            }
        }
        // затем arr[i]<=arr[j+8]
        if (!hasRightTower[i])
        {
            for (int j = 0; j < 8; j++)
            {
                if (arr[i] <= arr[j + 8])
                {
                    ans += arr[i];
                    hasRightTower[i] = 1;
                    break;
                }
            }
        }
    }

    //добавляем башни для столбцов
    for (int j = 0; j < 8; j++)
    {
        if (!hasRightTower[j + 8])
        {
            for (int i = 0; i < 8; i++)
            {
                if (arr[i] >= arr[j+8])
                {
                    ans += arr[j + 8];
                    hasRightTower[j + 8] = 1;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 16; i++)
    {
        if (!hasRightTower[i])
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
