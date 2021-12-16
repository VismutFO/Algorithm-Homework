#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 06-14: Наизнанку
На вход подаётся бинарный файл в следующем формате: первые два байта являются целым числом, которое не превышает 2000 и задаёт размер квадратной матрицы, 
затем следуют целочисленные 32х битные элементы матрицы. Все числа находятся в представлении big-endian. 
Требуется отыскать след матрицы и вывести его в бинарный файл в виде 64х битного целого числа в формате big-endian.
*/

typedef long long ll;

#ifndef __GNUC__
# include <winsock.h>
# pragma comment(lib, "Ws2_32.lib")
#else
# include <arpa/inet.h>
#endif

#define htonll(x) ((1==htonl(1)) ? (x) : ((uint64_t)htonl((x) & 0xFFFFFFFF) << 32) | htonl((x) >> 32))
#define ntohll(x) ((1==ntohl(1)) ? (x) : ((uint64_t)ntohl((x) & 0xFFFFFFFF) << 32) | ntohl((x) >> 32))

int main(int argc, char** argv)
{
	FILE *input, *output;
	//input = stdin, output = stdout;
	input = fopen("matrix.in", "r"), output = fopen("trace.out", "w");
	uint16_t len;
	fread(&len, 2, 1, input);
	len = ntohs(len);
	int64_t ans = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			int temp;
			// fscanf(input, "%d", &temp);
			fread(&temp, 4, 1, input);
			temp = ntohl(temp);
			if (i == j) { ans += temp; }
		}
	}
	//printf("%llx", ans);
	ans = htonll(ans);
	fwrite(&ans, 8, 1, output);
	fclose(input);
	fclose(output);
    return 0;
}
