#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 05-16: Апельсин
К Вам на улице подходит незнакомец и говорит, что всем известно эффективное решение задачи вычисления i-ого члена последовательности Фибоначчи по модулю числа p*.
Однако, теперь его интересует более общая задача для произвольной линейной рекуррентной последовательности, заданной формулой
Fn = A1 * Fn-1 + ... + AkFn-k.
Не в силах противостоять ему, Вы решаете помочь. Ваша задача посчитать FN mod p.

Входные данные имеют следующий формат. Сначала идут целые положительные числа k, N, p каждое с новой строки.2 ≤ k ≤ 10, N ≤ 2*109, p ≤ 2*105.
В следующей строке содержатся первые k членов данной последовательности F1..Fk. Каждое число целое неотрицательное и не превосходит 105.
В последней строке файла содержатся коэффициенты A1..Ak. Каждое число целое неотрицательное и не превосходит 105.
*/

typedef long long ll;

ll mod;//p

ll** multiplication(ll size, ll** arr1, ll** arr2)
{
    ll** ans = (ll**)malloc(size * sizeof(ll*));
    for (ll i = 0; i < size; i++)
    {
        ans[i] = (ll*)calloc(size, sizeof(ll));
        for (ll j = 0; j < size; j++)
        {
            for (ll k = 0; k < size; k++)
            {
                ans[i][j] += arr1[i][k] * arr2[k][j];
                ans[i][j] %= mod;
            }
        }
    }
    return ans;
}

ll** myPow(ll size, ll** arr, ll n)
{
    if (n == 1) { return arr; }
    if (n % 2 == 0)
    {
        ll** b = myPow(size, arr, n / 2);
        ll** ans = multiplication(size, b, b);
        if (n != 2) { free(b); }
        return ans;
    }
    ll** b = myPow(size, arr, n - 1);
    ll** ans = multiplication(size, b, arr);
    free(b);
    return ans;
}

int main(int argc, char** argv)
{
    ll k, n;
    scanf("%lld\n%lld\n%lld\n", &k, &n, &mod); n--;
    ll* F = (ll*)malloc(k * sizeof(ll));
    for (ll i = 0; i < k; i++)
    {
        scanf("%lld", &F[k - i - 1]);
        F[k - i - 1] %= mod;
    }
    if (n < k)
    {
        printf("%lld\n", F[n]);
        return 0;
    }
    ll** A = (ll**)malloc(k * sizeof(ll*));
    A[0] = (ll*)calloc(k, sizeof(ll));
    for (ll i = 0; i < k; i++)
    {
        scanf("%lld", &A[0][i]);
        A[0][i] %= mod;
    }
    for (ll i = 1; i < k; i++)
    {
        A[i] = (ll*)calloc(k, sizeof(ll));
        A[i][i - 1] = 1;
    }
    ll** An = myPow(k, A, n - k + 1);
    ll res = 0;
    for (ll i = 0; i < k; i++)
    {
        res += (An[0][i] * F[i]) % mod;
        res %= mod;
    }
    printf("%lld\n", res);
    free(F);
    free(A);
    free(An);
    return 0;
}
