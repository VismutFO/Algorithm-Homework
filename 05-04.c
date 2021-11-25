#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 05-4: Кто меньше?
На вход программе подается последовательность натуральных чисел, заканчивающаяся нулем (ноль в последовательность не входит) a1, a2, ..., an, 0.
Все числа в последовательности не превосходят 109.

Требуется определить, сколько элементов последовательности меньше последнего ее элемента.

Гарантируется, что программе выделено как минимум в 3 раза больше памяти, чем необходимо для хранения всей последовательности.
Преподаватели могут произвольно менять ограничение по памяти и размеры тестов при условии сохранения этого ограничения. Вся динамически выделенная в программе
память должна быть освобождена в конце.
*/

typedef long long ll;

int main(int argc, char** argv)
{
    int realSize = 1, n = 0;
    int* arr = (int*)malloc(realSize * sizeof(int));
    int x;
    scanf("%d", &x);
    while (x != 0)
    {
        arr[n++] = x;
        scanf("%d", &x);
        if (n == realSize)
        {
            int* temp = arr;
            realSize *= 2;
            arr = (int*)malloc(realSize * sizeof(int));
            for (int i = 0; i < n; i++)
            {
                arr[i] = temp[i];
            }
            free(temp);
        }
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[n - 1])
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
