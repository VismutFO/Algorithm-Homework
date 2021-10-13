#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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
