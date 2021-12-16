#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 06-8: Слова
Во входном файле words.in вводится текст, состоящий из больших и маленьких латинских букв, а также символа пробела. Текст заканчивается точкой и имеет длину не более
106символов. Словом считается любая последовательность подряд идущих латинских букв (любого регистра). Требуется из каждого слова нечетной длины удалить центральный
символ и вывести полученный тескт в файл words.out. Слова нужно разделять одним пробелом, в конце тескта вывести точку.

Указание: при решении данной задачи запрещается использовать массивы. Для хранения используйте однонаправленный или двунаправленный список.
*/

typedef long long ll;

struct node
{
    char c;
    struct node* next;
};

void init(struct node **temp)
{
    *temp = (struct node*)malloc(sizeof(struct node));
    (*temp)->c = 0;
    (*temp)->next = NULL;
    return;
}

void erase(struct node** temp)
{
    if (*temp == NULL) { return; }
    erase(&(*temp)->next);
    free(*temp);
    return;
}

void push(struct node** temp, char c)
{
    if (*temp == NULL) { init(temp); }
    if ((*temp)->c == 0) { (*temp)->c = c; return; }
    push(&(*temp)->next, c);
    return;
}

void print(FILE* output, struct node** root, int len)
{
    if (len % 2 == 0)
    {
        struct node** temp = root;
        while (*temp != NULL)
        {
            if ((*temp)->c == 0) { break; }
            fprintf(output, "%c", (*temp)->c);
            temp = &(*temp)->next;
        }
        return;
    }
    struct node** temp = root;
    int i = 0;
    while (*temp != NULL)
    {
        if ((*temp)->c == 0) { break; }
        if (i != len / 2) { fprintf(output, "%c", (*temp)->c); }
        temp = &(*temp)->next;
        i++;
    }
    return;
}

int main(int argc, char** argv)
{
    FILE *input, *output;
    input = fopen("words.in", "r");
    output = fopen("words.out", "w");
    //input = stdin;
    //output = stdout;
    struct node* root = NULL, *last = NULL;
    char c;
    int len = 0;
    while (fscanf(input, "%c", &c) > 0)
    {
        if (c == ' ')
        {
            if (len == 1)
            {
                erase(&root);
                root = NULL;
                last = NULL;
                len = 0;
                continue;
            }
            print(output, &root, len);
            erase(&root);
            root = NULL;
            last = NULL;
            len = 0;
            break;
        }
        else if (c == '.')
        {
            if (len == 1)
            {
                erase(&root);
                root = NULL;
                last = NULL;
                len = 0;
                fprintf(output, ".");
                
                //
                fclose(input);
                fclose(output);
                return 0;
            }
            print(output, &root, len);
            erase(&root);
            root = NULL;
            last = NULL;
            len = 0;
            fprintf(output, ".");

            //
            fclose(input);
            fclose(output);
            return 0;
        }
        else
        {
            if (root == NULL)
            {
                push(&root, c);
                last = root;
            }
            else
            {
                while (last->next != NULL) { last = last->next; }
                push(&last, c);
            }
            len++;
        }
    }
    while (fscanf(input, "%c", &c) > 0)
    {
        if (c == '\n') { continue; }
        if (c == ' ')
        {
            if (len == 1)
            {
                erase(&root);
                root = NULL;
                last = NULL;
                len = 0;
                continue;
            }
            fprintf(output, " ");
            print(output, &root, len);
            erase(&root);
            root = NULL;
            last = NULL;
            len = 0;
        }
        else if (c == '.')
        {
            if (len == 1)
            {
                erase(&root);
                root = NULL;
                last = NULL;
                len = 0;
                fprintf(output, ".");
                
                //
                fclose(input);
                fclose(output);
                return 0;
            }
            fprintf(output, " ");
            print(output, &root, len);
            erase(&root);
            root = NULL;
            last = NULL;
            len = 0;
            fprintf(output, ".");
            
            //
            fclose(input);
            fclose(output);
            return 0;
        }
        else
        {
            if (root == NULL)
            {
                push(&root, c);
                last = root;
            }
            else
            {
                while (last->next != NULL) { last = last->next; }
                push(&last, c);
            }
            len++;
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
