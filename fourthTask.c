#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int n; scanf("%d", &n);
    int* arrFirst = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { scanf("%d", &arrFirst[i]); }
    int ans = 0, tempSecond;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempSecond);
        ans += (arrFirst[i] > tempSecond ? arrFirst[i] : tempSecond);
    }
    printf("%d\n", ans);
    return 0;
}
