#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 02-13: Кубики наоборот
Вася выложил на шахматную доску кубики в несколько столбиков. При этом если один кубик лежит на другом, то нижняя грань верхнего кубика совпадает
с верхней гранью нижнего кубика, а у каждого из кубиков, лежащих непосредственно на доске, нижняя грань совпадает с одной из клеток доски.
Затем Вася посмотрел спереди на сооружение (увидев при этом восемь столбиков) и записал высоту каждого столбика слева направо.
Потом он посчитал высоту каждого столбика и записал ее, глядя на кубики справа от доски. После этого Вася сообщил найденные 16 чисел Пете.
Петя хочет узнать, какое наименьшее количество кубиков мог использовать Вася.

На вход программе подается 16 целых неотрицательных чисел (каждое не больше 100) в указанном порядке.
Требуется вывести единственное целое число – наименьшее возможное количество кубиков, либо число –1, если Вася ошибся в подсчете.
*/

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
