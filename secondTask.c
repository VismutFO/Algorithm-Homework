#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 02-2: Разворот половины последовательности
На стандартном потоке ввода задаётся некоторое количество целых чисел (не более 10000 штук), не равных 0. Последовательность оканчивается нулём, который в неё не входит.

На стандартный поток вывода напечатайте последовательность, полученную из исходной следующей перестановкой чисел. Сначала выводятся все нечётные элементы исходной последовательности (то есть первый, третий, пятый и так далее), а затем — все чётные в обратном порядке. Число 0, являющееся признаком конца последовательности, выводить не нужно.

Указание: при решении используйте массивы.
*/

int even[10000], odd[10000];

int main(int argc, char** argv)
{
    int sizeEven = 0, sizeOdd = 0, temp;
    scanf("%d", &temp);
    while (temp != 0)
    {
        if ((sizeEven + sizeOdd) % 2 == 0)
        {
            odd[sizeOdd++] = temp;
        }
        else
        {
            even[sizeEven++] = temp;
        }
        scanf("%d", &temp);
    }
    for (int i = 0; i < sizeOdd; i++)
    {
        printf("%d ", odd[i]);
    }
    for (int i = sizeEven - 1; i >= 0; i--)
    {
        printf("%d ", even[i]);
    }
    printf("\n");
    return 0;
}
