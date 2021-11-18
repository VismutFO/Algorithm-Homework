#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 04-2: Хокку
В мировой культуре известны различные виды стихотворного искусства, подчиняющиеся чётким правилам построения.
Чаще всего эти правила включают в себя фиксированное количество строк в стихотворении и определённое количество слогов в каждой из этих строк.
Например, в хокку — 3 строки, в первой и третьей — по 5 слогов, а во второй — 7. В танка пять строк, по 5, 7, 5, 7 и 7 слогов соответственно.
Считайте, что каждый гласный звук начинает новый слог, за исключением случая, когда несколько гласных звуков следуют подряд (например, в слове “cuckoo” — 2 слога).
Гласными считаются звуки, соответствующие латинским буквам a, e, i, o, u, y.
На стандартном потоке ввода ваша программа получает сначала количество строк N (0 ≤ N ≤ 104), а затем — N натуральных чисел — количество слогов в соответствующей строке.
Каждое из чисел не превышает 100.
Далее задаются N строк стихотворения. В строках могут встречаться заглавные и строчные латинские буквы, пробелы, апострофы и знаки препинания.
Строки не превышают по длине 100 символов.
Требуется вывести в том же порядке, что и во входных данных, те строки стихотворения, которые удовлетворяют критериям.
*/

int isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i'
        || c == 'o' || c == 'u' || c == 'y'
        || c == 'A' || c == 'E' || c == 'I'
        || c == 'O' || c == 'U' || c == 'Y';
}

int main(int argc, char** argv)
{
    int n;
    scanf("%d", &n);
    int* lens = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &lens[i]);
    }
    for (int i = 0; i < n; i++)
    {
        char buf[200];
        fgets(buf, 200, stdin);
        int ans = 0;
        for (int j = 0; j < 200; j++)
        {
            if (buf[j] == '\0') { break; }
            if (isVowel(buf[j]) && (j == 0 || !isVowel(buf[j - 1])))
            {
                ans++;
            }
        }
        if (ans == lens[i])
        {
            printf("%s", buf);
        }
    }
    return 0;
}
