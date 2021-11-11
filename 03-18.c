#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 03-18: Удваивающаяся последовательность
Задается два числа N и A (1 ≤ N, A ≤ 2000000000). Строится бесконечная последовательность Xi.
X1 = N mod 2010
X2 = (X1#X1) mod 2010 ... Xi+1 = (Xi#Xi) mod 2010
Здесь C mod D означает остаток от деления C на D. C#D - дает число, которое получится если приписать D к C. Например, 20#10 = 2010.
Подразумевается запись числа в десятичной системе счисления, без ведущих нулей.
Выведите одно слово YES если A встречается в последовательности X или NO если не встречается.
Указание: реализуйте функцию, выполняющую описанную операцию #.
*/

long long len(long long x)
{
    long long result = 0;
    while (x > 0LL)
    {
        x /= 10LL;
        result++;
    }
    return result;
}

long long getFactor(long long x)
{
    long long n = len(x), pow = 1LL;
    for (long long i = 0LL; i < n; i++)
    {
        pow *= 10LL;
    }
    pow++;
    pow %= 2010LL;
    return pow;
}

long long getNext(long long x)
{
    return (x * getFactor(x)) % 2010LL;
}

int main(int argc, char** argv)
{
    long long n, a;
    scanf("%lld %lld", &n, &a);
    if (a >= 2010LL)
    {
        printf("NO\n");
        return 0;
    }
    n %= 2010LL;
    for (long long i = 0LL; i < 10000LL; i++, n = getNext(n))
    {
        if (n == a)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
