#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 05-9: Вирусы
Колония клеток представляет собой прямоугольную матрицу размера NxM (0 < N, M ≤ 500). В колонию проникает k (0 < k < 11) вирусов, 
которые заразили клетки с координатами (Xi,Yi),…(Xk,Yk). За единицу времени вирус проникает в клетки, соседние с зараженными (соседними считаются клетки,
имеющие общую сторону). Определить время заражения всей колонии.

Входные данные:
в первой строке два целых числа - размер матрицы: N и M;
во второй строке - количество проникших в колонию вирусов;
в последующих k строках – координаты (1 ≤ Xi ≤ M и 1 ≤ Yi ≤ N – номера столбцов и строк матрицы) первых зараженных клеток:
Выходные данные: вывести одно целое число – время заражения всей колонии.
*/

typedef long long ll;

#define QMAX 250001
int Queue[QMAX][2];
int first, last;// [)


void init(void)
{
    first = 0;
    last = 0;
    return;
}

void insert(int a, int b)
{
    if ((last - first + QMAX) % QMAX < QMAX)
    {
        Queue[last][0] = a;
        Queue[last][1] = b;
        last++;
        last %= QMAX;
    }
    else
    {
        printf("abs\n");
    }
    return;
}

int isEmpty(void)
{
    if (first == last) { return 1; }
    else { return 0; }
}

int* erase(void)
{
    int *x = calloc(2, sizeof(int));
    if (isEmpty() == 1)
    {
        printf("abs2\n");
        return x;
    }
    x[0] = Queue[first][0];
    x[1] = Queue[first][1];
    first++;
    first %= QMAX;
    return x;
}

int main(int argc, char** argv)
{
    int n, m, k;
    scanf("%d %d\n%d\n", &n, &m, &k);
    short** used = (short**)malloc(n * sizeof(short*));
    for (int i = 0; i < n; i++)
    {
        used[i] = (short*)calloc(m, sizeof(short));
    }
    init();
    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        used[y][x] = 1;
        insert(y, x);
    }
    int max = 1;
    while (!isEmpty())
    {
        int* temp = erase();
        if (temp[0] > 0 && used[temp[0] - 1][temp[1]] == 0)
        {
            used[temp[0] - 1][temp[1]] = used[temp[0]][temp[1]] + 1;
            insert(temp[0] - 1, temp[1]);
            if (used[temp[0] - 1][temp[1]] > max) { max = used[temp[0] - 1][temp[1]]; }
        }
        if (temp[0] < n - 1 && used[temp[0] + 1][temp[1]] == 0)
        {
            used[temp[0] + 1][temp[1]] = used[temp[0]][temp[1]] + 1;
            insert(temp[0] + 1, temp[1]);
            if (used[temp[0] + 1][temp[1]] > max) { max = used[temp[0] + 1][temp[1]]; }
        }
        if (temp[1] > 0 && used[temp[0]][temp[1] - 1] == 0)
        {
            used[temp[0]][temp[1] - 1] = used[temp[0]][temp[1]] + 1;
            insert(temp[0], temp[1] - 1);
            if (used[temp[0]][temp[1] - 1] > max) { max = used[temp[0]][temp[1] - 1]; }
        }
        if (temp[1] < m - 1 && used[temp[0]][temp[1] + 1] == 0)
        {
            used[temp[0]][temp[1] + 1] = used[temp[0]][temp[1]] + 1;
            insert(temp[0], temp[1] + 1);
            if (used[temp[0]][temp[1] + 1] > max) { max = used[temp[0]][temp[1] + 1]; }
        }
        free(temp);
    }
    printf("%d\n", max - 1);
    return 0;
}
