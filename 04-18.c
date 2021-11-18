#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 04-18: Интегрирование
Студенту Коле его преподавать мат.анализа задал проинтегрировать 9000 многочленов от одной переменной. Однако Коля очень занят, и попросил Васю помочь ему.
Вася не мог отказать своему лучше другу, однако он очень ленив и попросил помощи у Вас. Помогите Васе сделать домашнее задание Коли и напишите программу, которая
интегрирует многочлен.

На стандартном потоке ввода задана единственная строка, длина которой не более 100000 символов. Строка представляет собой запись некоторого многочлена.
Многочлен состоит из одного и более одночленов. Одночлены могут быть разделены нулем или более пробелами. Переменные всех одночленов в многочлене совпадают.
Одночлены могут следовать в многочлене не по порядку своих степеней, в многочлене не могут присутствовать несколько одночленов одной степени.

Каждый одночлен состоит из четырех частей. Первая часть одночлена является знаком '+' или '-'. Вторая часть одночлена -- коэффициент, целое неотрицательное число,
не превосходящее 1000000. Третья часть одночлена -- это переменная, записанная маленькой буквой английского алфавита. Четвертая часть -- степень, записанная знаком '^',
за которым следует показатель степени -- целое неотрицательное число, не превосходящее 1000000.

Знак первого одночлена может быть опущен, в этом случае знак коэффициента положителен. Коэффициент одночлена также может отсутствовать, в этом случае обязательно
присутствует переменная одночлена, а коэффициент приравнивается к единице. Переменная одночлена также может отсутствовать, в этом случае обязательно присутствует
коэффициент одночлена, а степень переменной также отсутствует и приравнивается к нулю. Степень переменной и знак степени может отсутствовать при наличии самой переменной,
в этом случае степень переменной приравнивается к единице. Если степень переменной присутствует, то есть также и сама переменная.

Между знаком и коэффициентом одночлена может быть нуль или более пробелов. Коэффициент и переменная одночлена могут быть записаны подряд (без пробелов)
или через знак умножения '*'. В последнем случае между коэффициентом и знаком умножения, а также между знаком умножения и переменной может быть нуль или более пробелов.
Между переменной и знаком степени '^', а также между знаком и показателем степени не содержится пробелов.

На стандартном потоке вывода напечатайте строку, представляющую канонический вид неопределенного интеграла для заданного многочлена. Одночлены в интеграле должны идти строго
в порядке уменьшения степеней и разделяться одним пробелом. Одночленов с нулевыми коэффициентами не должно быть в выводе. Переменная выходного многочлена должна совпадать
с переменной входного. Если входной переменной не было, то выходной переменной должна быть буква 'x'.

Знак одночлена должен присутствовать всегда, кроме одночлена наибольшей степени, если он положителен, и отделяться от коэффициента одним
пробелом(для одночлена наибольшей степени пробелов быть не должно). Коэффициент должен быть представлен в виде целого положительного числа или рациональной
несократимой дроби (с помощью знака деления '/'; знаменатель в этом случае должен быть строго больше единицы). Коэффициент, равный единице, должен быть опущен.
Переменная должна присутствовать только в том случае, если степень одночлена не равна нулю, и записываться сразу после знака умножения без пробелов,
который должен записываться после коэффициента без пробелов. Степень одночлена со знаком степени должна присутствовать только в том случае, если она больше единицы,
и записываться после знака степени без пробелов, который должен записываться после переменной без пробелов. После последнего одночлена должна идти константа,
отделенная от него одним пробелом и записанная в виде "+ C". Если же последний одночлен отсутствует, выведите "C".

Указание: int(ax^n) = (a/n+1)x^(n+1) + C, n ≥ 0, C - const
*/

char arr[2000000];

int minq(int a, int b)
{
	return (a < b ? a : b);
}

int ind = 0, len;// индекс, с которого нужно начинать getNext()
char x = 'x';


int getNext(int* sign, int* coefficient, int* degree)// return 1, если удалось получить след., иначе 0
{
    *coefficient = *degree = 0;
    *sign = 1;
    if (ind < len)
    {
        if (arr[ind] == '+' || (arr[ind] >= '0' && arr[ind] <= '9') || (arr[ind] >= 'a' && arr[ind] <= 'z'))
        {
            if (arr[ind] == '+') { ind++; }
            int myFlag = 1;
            while (ind < len && arr[ind] >= '0' && arr[ind] <= '9')
            {
                *coefficient = (*coefficient) * 10 + (int)(arr[ind] - '0');
                ind++;
                myFlag = 0;
            }
            if (ind < len && arr[ind] >= 'a' && arr[ind] <= 'z')
            {
                if (*coefficient == 0 && myFlag) { *coefficient = 1; }
                x = arr[ind];
                *degree = 1;
                ind++;
                if (ind < len && arr[ind] == '^')
                {
                    *degree = 0;
                    ind++;
                    while (ind < len && arr[ind] >= '0' && arr[ind] <= '9')
                    {
                        *degree = (*degree) * 10 + (int)(arr[ind] - '0');
                        ind++;
                    }
                }
            }
            return 1;
        }
        if (arr[ind] == '-')
        {
            *sign = -1; ind++;
            int myFlag = 1;
            while (ind < len && arr[ind] >= '0' && arr[ind] <= '9')
            {
                *coefficient = (*coefficient) * 10 + (int)(arr[ind] - '0');
                ind++;
                myFlag = 0;
            }
            if (ind < len && arr[ind] >= 'a' && arr[ind] <= 'z')
            {
                if (*coefficient == 0 && myFlag) { *coefficient = 1; }
                x = arr[ind];
                *degree = 1;
                ind++;
                if (ind < len && arr[ind] == '^')
                {
                    *degree = 0;
                    ind++;
                    while (ind < len && arr[ind] >= '0' && arr[ind] <= '9')
                    {
                        *degree = (*degree) * 10 + (int)(arr[ind] - '0');
                        ind++;
                    }
                }
            }
            return 1;
        }
        return 0;
    }
    else { return 0; }
}

int cmp(const void* a, const void* b)
{
    return (*((int **)a))[2] - (*((int**)b))[2];
}

int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

void printNext(int* monomial, int flag)//flag = 0 - первый элемент, 2 - последний, 3 - единственный, 1 - остальные
{
    if (flag == 0)
    {
        if (monomial[0] == -1) { printf("-"); }
        int numerator = monomial[1] / gcd(abs(monomial[1]), abs(monomial[2] + 1)), 
            denominator = (monomial[2] + 1) / gcd(abs(monomial[1]), abs(monomial[2] + 1));
        if (denominator == 1)
        {
            if (numerator != 1)
            {
                printf("%d*", numerator);
            }
        }
        else
        {
            printf("%d/%d*", numerator, denominator);
        }
        printf("%c", x);
        if (monomial[2] != 0)
        {
            printf("^%d", monomial[2] + 1);
        }
        return;
    }
    else if (flag == 1)
    {
        if (monomial[0] == -1) { printf(" - "); }
        else { printf(" + "); }
        int numerator = monomial[1] / gcd(abs(monomial[1]), abs(monomial[2] + 1)),
            denominator = (monomial[2] + 1) / gcd(abs(monomial[1]), abs(monomial[2] + 1));
        if (denominator == 1)
        {
            if (numerator != 1)
            {
                printf("%d*", numerator);
            }
        }
        else
        {
            printf("%d/%d*", numerator, denominator);
        }
        printf("%c", x);
        if (monomial[2] != 0)
        {
            printf("^%d", monomial[2] + 1);
        }
        return;
    }
    else if (flag == 2)
    {
        if (monomial[0] == -1) { printf(" - "); }
        else { printf(" + "); }
        int numerator = monomial[1] / gcd(abs(monomial[1]), abs(monomial[2] + 1)),
            denominator = (monomial[2] + 1) / gcd(abs(monomial[1]), abs(monomial[2] + 1));
        if (denominator == 1)
        {
            if (numerator != 1)
            {
                printf("%d*", numerator);
            }
        }
        else
        {
            printf("%d/%d*", numerator, denominator);
        }
        printf("%c", x);
        if (monomial[2] != 0)
        {
            printf("^%d", monomial[2] + 1);
        }
        printf(" + C");
        return;
    }
    else
    {
        if (monomial[0] == -1) { printf("-"); }
        int numerator = monomial[1] / gcd(abs(monomial[1]), abs(monomial[2] + 1)),
            denominator = (monomial[2] + 1) / gcd(abs(monomial[1]), abs(monomial[2] + 1));
        if (denominator == 1)
        {
            if (numerator != 1)
            {
                printf("%d*", numerator);
            }
        }
        else
        {
            printf("%d/%d*", numerator, denominator);
        }
        printf("%c", x);
        if (monomial[2] != 0)
        {
            printf("^%d", monomial[2] + 1);
        }
        printf(" + C");
        return;
    }
}

int main(int argc, char** argv)
{
    char temp;
    len = 0;
    while (1)
    {
        scanf("%c", &temp);
        if (temp == ' ' || temp == '*') { continue; }
        if (temp == '\n')
        {
            arr[len++] = temp;
            break;
        }
        else
        {
            arr[len++] = temp;
        }
    }
    arr[len] = '\0';
    int sign, coefficient, degree;
    int** monomials = (int**)malloc(1000000 * sizeof(int*));
    int lenOfMon = 0;
    while (getNext(&sign, &coefficient, &degree))
    {
        if (coefficient != 0)
        {
            monomials[lenOfMon] = (int*)malloc(3 * sizeof(int));
            monomials[lenOfMon][0] = sign;
            monomials[lenOfMon][1] = coefficient;
            monomials[lenOfMon][2] = degree;
            lenOfMon++;
        }
    }
    qsort(monomials, lenOfMon, sizeof(int*), cmp);
    if (lenOfMon == 0)
    {
        printf("C");
        return 0;
    }
    if (lenOfMon == 1)
    {
        printNext(monomials[0], 3);
        return 0;
    }
    printNext(monomials[lenOfMon - 1], 0);
    for (int i = lenOfMon - 2; i > 0; i--)
    {
        printNext(monomials[i], 1);
    }
    printNext(monomials[0], 2);
    free(monomials);
    return 0;
}
