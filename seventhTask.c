#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int n; scanf("%d", &n);
    int* hasBeen = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { hasBeen[i] = 0; }
    for (int i = 0; i < n; i++)
    {
        int temp; scanf("%d", &temp); temp--;
        if (temp < 0 || temp >= n)
        {
            printf("No\n");
            return 0;
        }
        if (hasBeen[temp])
        {
            printf("No\n");
            return 0;
        }
        hasBeen[temp] = 1;
    }
    printf("Yes\n");
    return 0;
}
