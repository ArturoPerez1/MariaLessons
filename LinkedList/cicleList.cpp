#include <iostream>
using namespace std;

struct cicleList
{
    int value = 0;
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

    do{
        cout << aux->value << endl;
        aux = aux->next;
    }while(aux != list);

    return 0;
}

void createList(cicleList *&list, int value)
{
    cicleList *aux1 = list;
    cicleList *aux2 = list;

    if(aux1 == NULL){
        cicleList *new_node = new cicleList();
        new_node->value = value;
        list = new_node;
        new_node->next = list;
    }else{
        cicleList *new_node = new cicleList();
        new_node->value = value;

        while(aux2->next != aux1){
            aux2 = aux2->next;
        }

        aux2->next = new_node;
        new_node->next = aux1;
    }

}
