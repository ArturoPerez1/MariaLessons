#include <iostream>
using namespace std;

struct dobleList
{
    int value = 0;
    dobleList *next;
    dobleList *prev;
};

void createList(dobleList *&list, int value);

int main(int argc, char const *argv[])
{
    dobleList *list = NULL;
    dobleList *aux;
    dobleList *aux2;
    createList(list, 25);
    createList(list, 30);
    createList(list, 31);
    aux = list;

    while (aux != NULL)
    {
        cout << aux->value << endl;
        aux2 = aux;
        aux = aux->next;
    }
    cout << "\n"<< endl;
    while (aux2 != NULL)
    {
        cout << aux2->value << endl;
        aux2 = aux2->prev;
    }

    return 0;
}

void createList(dobleList *&list, int value)
{
    dobleList *aux1 = list;
    dobleList *aux2 = NULL;

    if (aux1 == NULL)
    {
        dobleList *new_node = new dobleList();
        new_node->value = value;
        list = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        while (aux1 != NULL)
        {
            aux2 = aux1;
            aux1 = aux1->next;
        }
        dobleList *new_node = new dobleList();
        new_node->value = value;
        aux2->next = new_node;
        new_node->next = aux1;
        new_node->prev = aux2;
    }
}
