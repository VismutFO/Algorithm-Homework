#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 06-4: Деревья поиска
В задаче требуется организовать структуру данных (дерево) для хранения, поиска и удаления элементов определенного вида. Каждый элемент имеет ключ и некоторые данные,
ассоциированные с этим ключом. Считается, что в структуре данных ключ однозначено определяет элемент. Определены следующие операции: сохранение нового элемента, удаление
и поиск элемента по ключу. Сохранение нового элемента с ключом K и данными D заключается в следующем. Если в структуре данных уже есть элемент с таким ключом, данные этого
элемента перезаписываются данными нового элемента, иначе, в структуре данных появляется новый элемент с ключом K и данными D. Поиск элемента по ключу заключается в нахождении
в структуре данных такого элемента, ключ которого соответствует заданному ключу. Удаление элемента по ключу заключается в удалении из структуры данных элемента с заданным
ключом (если элемента с таким ключом нет, ничего делать не нужно).

На стандартном потоке ввода задается последовательность операций, которые необходимо выполнить. Каждая операция задана в отдельной строке. Операции имеют вид
op [key [data]] (квадратные скобки означают, что, в зависимости от конкретной операции, параметры могут включаться или отсутствовать). Параметры key, data являются целыми
32-битными числами. Параметр op задает операцию и может принимать значения A, D, S и F. Значение A означает операцию добавления (обновления) элемента с ключом key и данными
data, она имеет вид A key data. Значение D означает операцию удаления элемента с ключом key и имеет вид D key. Значение S означает операцию поиска элемента по ключу key
и имеет вид S key. Значение F означает окончание входных данных. В результате выполнения операции поиска, в случае нахождения элемента с нужным ключом, на стандартный поток
вывода напечатайте значения ключа и данных найденного элемента через пробел. Ничего более на стандартный поток вывода печатать не следует.

Все операции, кроме F, могут идти в произвольном порядке. Последней всегда идет операция F. В результате выполнения этой операции, программа должна освободить занимаемые
ресурсы и завершить работу. Максимально возможное число операций составляет 15000 операций.

Указание: для решения задачи реализовать какое-либо дерево поиска.
*/

typedef long long ll;

struct node
{
    int isRoot;
    struct node* next[10];
    ll value;//INT32_MIN, если нет значения в этом месте
};

struct node* init(void)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->value = INT64_MIN;
    temp->isRoot = 0;
    for (int i = 0; i < 10; i++) { temp->next[i] = NULL; }
    return temp;
}

void add(struct node* cur, ll key, ll value)
{
    if (key == 0 && !cur->isRoot)
    {
        cur->value = value;
        return;
    }
    if (cur->next[key % 10LL] == NULL) { cur->next[key % 10LL] = init(); }
    add(cur->next[key % 10LL], key / 10LL, value);
    return;
}

void myRemove(struct node* cur, ll key)
{
    if (key == 0 && !cur->isRoot)
    {
        cur->value = INT64_MIN;
        return;
    }
    if (cur->next[key % 10LL] == NULL) { cur->next[key % 10LL] = init(); }
    myRemove(cur->next[key % 10LL], key / 10LL);
    return;
}

void find(struct node* cur, ll key, ll keyCopy)
{
    if (key == 0 && !cur->isRoot)
    {
        if (cur->value != INT64_MIN)
        {
            printf("%lld %lld\n", keyCopy, cur->value);
        }
        return;
    }
    if (cur->next[key % 10LL] == NULL) { cur->next[key % 10LL] = init(); }
    find(cur->next[key % 10LL], key / 10LL, keyCopy);
    return;
}

void killNode(struct node* cur)
{
    if (cur == NULL) { return; }
    for (int i = 0; i < 10; i++) { killNode(cur->next[i]); }
    free(cur);
}

int main(int argc, char** argv)
{
    struct node* root = init();
    root->isRoot = 1;
    char c;
    scanf("%c", &c);
    while (c != 'F')
    {
        if (c == 'A')
        {
            ll key, value;
            scanf("%lld %lld", &key, &value);
            //if (key < 0) { printf("abs"); return 0; }
            add(root, key + (1LL << 32LL), value);
        }
        else if (c == 'D')
        {
            ll key;
            scanf("%lld", &key);
            //if (key < 0) { printf("abs"); return 0; }
            myRemove(root, key + (1LL << 32LL));
        }
        else if (c == 'S')
        {
            ll key;
            scanf("%lld", &key);
            //if (key < 0) { printf("abs"); return 0; }
            find(root, key + (1LL << 32LL), key);
        }
        scanf("%c", &c);
    }
    killNode(root);
    return 0;
}
