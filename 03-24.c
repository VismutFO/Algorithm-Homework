#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 03-24: Фонарики
Полоска клетчатой бумаги 1xN описывается последовательностью из N чисел. Число 0 означает, что клетка пустая.
Число K, отличное от нуля, означает, что в данной клетке лежит фонарик. Фонарик освещает |K| клеток слева от своей клетки, если K < 0,
и справа от своей клетки, если K > 0. Фонарик не освещает свою клетку.
Фонарик освещает клетку с другим фонариком, но не освещает клетки за другим фонариком (свет фонариков не распространяется за фонарики).
Опишите функцию int lighten(int N), которая считывает со стандартного потока ввода N чисел, описывающих полоску бумаги 1xN.
Функция должна возвращать количество освещенных клеток на полоске.
Также напишите программу, демонстрирующую работу функции lighten. На вход программе подается число N, за которым следует N целых 32-битных чисел,
описывающих полоску бумаги. N — натуральное, не превосходящее 10000. Программа должна выдавать единственное число — количество освещенных клеток.
Указание: использовать массивы запрещается.
*/

long long lighten(long long n)
{
    long long answer = 0;
    long long light = 0;// насколько хватит света с последнего фонарика
    long long freeCells = 0;// сколько неосвещённых клеток слева
    long long lastCellWithLamp = INT64_MIN;// клетки с фонарями обрабатываем отдельно
    for (long long i = 0; i < n; i++)
    {
        long long x; scanf("%lld", &x);
        if (x > 0LL)
        {
            if (light > 0LL)
            {
                answer++;
                lastCellWithLamp = INT64_MIN;
            }
            else
            {
                lastCellWithLamp = i;
            }
            light = x;
            freeCells = 0LL;
        }
        else if (x < 0LL)
        {
            x *= -1LL;
            if (x <= freeCells) { answer += x; }
            else { answer += freeCells; }

            if (lastCellWithLamp != INT64_MIN && i - x <= lastCellWithLamp) { answer++; }

            if (light > 0LL)
            {
                answer++;
                lastCellWithLamp = INT64_MIN;
            }
            else
            {
                lastCellWithLamp = i;
            }
            light = 0LL;
            freeCells = 0LL;
        }
        else
        {
            if (light > 0LL)
            {
                answer++;
                light--;
            }
            else
            {
                freeCells++;
            }
        }
    }
    return answer;
}

int main(int argc, char** argv)
{
    long long n; scanf("%lld", &n);
    printf("%lld", lighten(n));
    return 0;
}
