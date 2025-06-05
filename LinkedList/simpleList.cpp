#include <iostream>
using namespace std;

struct simpleList
{
    int value = 0;
    simpleList *next;
};

void createList(simpleList *&list, int value);

int main(int argc, char const *argv[])
{
    simpleList *list = NULL;
    simpleList *aux;
    createList(list, 25);
    createList(list, 30);
    createList(list, 31);
    aux = list;

    while (aux != NULL)
    {
        cout<<aux->value<<endl;
        aux = aux->next;
    }

    return 0;
}

void createList(simpleList *&list, int value)
{
    simpleList *aux1 = list;
    simpleList *aux2 = NULL;

    if (aux1 == NULL)
    {
        simpleList *new_node = new simpleList();
        new_node->value = value;
        list = new_node;
        new_node->next = NULL;
    }
    else
    {
        while (aux1 != NULL)
        {
            aux2 = aux1;
            aux1 = aux1->next;
        }
        simpleList *new_node = new simpleList();
        new_node->value = value;
        aux2->next = new_node;
        new_node->next = aux1;
    }
}
