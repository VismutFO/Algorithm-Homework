#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 06-15: Domain Name System
Представьте, что вы пишете DNS сервер. У вас есть соответствие доменных имен компьютеров их IP-адресам.
Вам необходимо эффективно обрабатывать запросы на получение IP-адреса компьютера по его имени.

Во входном файле input.txt записано число N (1 ≤ N ≤ 100000) - количество известных соответствий между именем компьютера и его адресом, за которым следует
N записей вида ⟨имя компьютера⟩ ⟨IP-адрес компьютера⟩ - сами эти соответствия. Далее идет число M (1 ≤ M ≤ 100000) - количество запросов. Каждый запрос представляет
собой одну строку с именем компьютера.

Имена компьютеров - строки, состоящие из маленьких латинских букв, символов "." и "-". Длины имен не превышают 100 символов. IP-адреса - 32-битные беззнаковые целые числа.
Не бывает двух компьютеров с одинаковым именем. У каждого компьютера может быть только один адрес, но может быть несколько различных имен.

В выходной файл output.txt требуется вывести результаты обработки всех запросов в том порядке, в котором запросы встречаются во входном файле. 
Результатом обработки запроса является одно беззнаковое 32-битное число - IP-адрес запрашиваемого компьютера, если он известен, либо -1, если IP-адрес данного компьютера
неизвестен.
*/

typedef long long ll;

#define MAX 2000003
#define p 331
struct htype 
{
	char* key; /* ключ */
	uint32_t val; /* значение элемента данных */
	struct htype* next; /* указатель на следующий элемент
	цепочки */
	struct htype* prvs; /* указатель на предыдущий элемент
	цепочки */
};

struct htype* hash_table[MAX];

static inline int hash(char* key)
{
	
	int ans = 0, len = strlen(key);
	for (int i = 0; i < len; i++) { ans = (ans * p + (int)key[i]) % MAX; }
	return ans;
	
}
/* инициализация хеш-таблицы */
void init(void)
{
	for (int i = 0; i < MAX; i++) { hash_table[i] = NULL; }
	return;
}

struct htype* search(char *k)
{
	/* вычисление хеш-адреса */
	int h = hash(k);
	/* поиск ключа k */
	if (hash_table[h] != NULL)
	{
		struct htype* cur = hash_table[h];
		do
		{
			if (strcmp(cur->key, k) == 0) { return cur; }
			else { cur = cur->next; }
		} while (cur);
	}
	return NULL;
}

struct htype* new (void)
{
	struct htype* cur;
	cur = malloc(sizeof(struct htype));
	if (!cur) { exit(1); }
	cur->key = "\0";
	cur->val = 0;
	cur->next = NULL;
	cur->prvs = NULL;
	return cur;
}

void insert(char *k, uint32_t v) 
{
	struct htype *a, *b;
	b = new();
	b->key = k;
	b->val = v;
	a = hash_table[hash(k)];
	if (a == NULL) { hash_table[hash(k)] = b; }
	else
	{
		while (a->next != NULL) { a = a->next; }
		a->next = b;
		b->prvs = a;
	}
	a = b = NULL;
	return;
}

void freeHash(void)
{
	for (int i = 0; i < MAX; i++)
	{
		struct htype* cur = hash_table[i];
		while (cur != NULL)
		{
			free(cur->key);
			cur = cur->next;
		}
	}
}

int main(int argc, char** argv)
{
	FILE *input, *output;
	//input = stdin, output = stdout;
	input = fopen("input.txt", "r"), output = fopen("output.txt", "w");
	init();
	int n;
	fscanf(input, "%d\n", &n);
	char *buf;
	for (int i = 0; i < n; i++)
	{
		buf = (char*)malloc(301 * sizeof(char));
		fscanf(input, "%300s", buf);
		uint32_t v;
		fscanf(input, "%u\n", &v);
		insert(buf, v);
		buf = NULL;
	}
	fscanf(input, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		buf = (char*)malloc(301 * sizeof(char));
		fscanf(input, "%300s", buf);
		struct htype* result = search(buf);
		free(buf);
		buf = NULL;
		if (result == NULL) { fprintf(output, "-1\n"); }
		else { fprintf(output, "%u\n", result->val); }
	}
	freeHash();
	fclose(input);
	fclose(output);
	return 0;
}
