#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int n; scanf("%d", &n);
    long long* arr = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) { scanf("%lld", &arr[i]); }
    long long allXor = 0LL;
    for (int i = 0; i < n; i++) { allXor = allXor ^ arr[i]; }
    for (int bit = 0; bit < 64; bit++)
    {
        if (allXor & (1LL << bit))
        {
            long long tempXor = 0LL;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] & (1LL << bit))
                {
                    tempXor = tempXor ^ arr[i];
                }
            }
            long long a = tempXor, b = tempXor ^ allXor;
            if (a > b)
            {
                long long t = a;
                a = b;
                b = t;
            }
            printf("%lld %lld\n", a, b);
            return 0;
        }
    }
    return 0;
}
