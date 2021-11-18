#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 04-13: Периоды большой строки
На вход программе подается строка α длиной (обозначим |α|) не более 106 симоволов, состоящая из строчных латинских букв.

Скажем, что строка α имеет период t, если

1 ≤ t ≤ |α|
a[i] = a[i - t] для всех t ≤ i < |α|
Выведите все периоды данной строки в возрастающем порядке.
*/

char arr[2000000];

int minq(int a, int b)
{
	return (a < b ? a : b);
}

int main(int argc, char** argv)
{
  fgets(arr, 2000000, stdin);
  int n = strlen(arr) - 1;
	int *z = (int*)calloc(n, sizeof(int));
	for (int i = 1, l = 0, r = 0; i < n; i++)
	{
		if (i <= r)
		{
			z[i] = minq(r - i + 1, z[i - l]);
		}
		while (i + z[i] < n && arr[z[i]] == arr[i + z[i]])
		{
			++z[i];
		}
		if (i + z[i] - 1 > r)
		{
			l = i, r = i + z[i] - 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i + z[i] == n)
		{
			printf("%d ", i);
		}
	}
	printf("%d\n", n);
    return 0;
}
