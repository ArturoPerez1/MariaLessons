#include <iostream>
using namespace std;

struct cicleList
{
    int value = 0;
    cicleList *prev = NULL;
    cicleList *next = NULL;
};

void createList(cicleList *&list, int value);

int main(int argc, char const *argv[])
{
    cicleList *list = NULL;
    cicleList *aux;
    createList(list, 25);
    createList(list, 30);
    createList(list, 31);
    aux = list;

    do
    {
        cout << aux->value << endl;
        aux = aux->next;
    } while (aux != list);

    cout << "\n"<< endl;

    aux = list;
    do{
        aux = aux->prev;
        cout << aux->value << endl;
    }while(aux != list);
    

    return 0;
}

void createList(cicleList *&list, int value)
{
    cicleList *aux1 = list;
    cicleList *aux2 = list;

    if (aux1 == NULL)
    {
        cicleList *new_node = new cicleList();
        new_node->value = value;
        list = new_node;
        new_node->next = list;
        new_node->prev = list;
    }
    else
    {
        cicleList *new_node = new cicleList();
        new_node->value = value;

        while (aux2->next != aux1)
        {
            aux2 = aux2->next;
        }

        aux2->next = new_node;
        new_node->next = aux1;
        new_node->prev = aux2;
        aux1->prev = new_node;
    }
}
