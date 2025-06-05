#include <iostream>
using namespace std;

struct nodeTree
{
    int value = 0;
    nodeTree *left = NULL;
    nodeTree *right = NULL;
};

nodeTree *createNode(int);
void insertNode(nodeTree *&, int);
void showTree(nodeTree *&, int);

int main(int argc, char const *argv[])
{
    int value, option, count = 0;
    nodeTree *tree = NULL;

    do
    {
        cout << "--- MENU PRINCIPAL ---\n";
        cout << "1. Insertar nodo\n";
        cout << "2. Mostrar nodos\n";
        cout << "3. Salir\n";
        cout << "----------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Digite un número = ";
            cin >> value;
            insertNode(tree, value);
            break;
        case 2:
            showTree(tree, count);
            cout << "\n";
            system("pause");
            break;
        case 3:
            cout << "Gracias por usar\n";
            system("pause");
            break;
        default:
            cout << "Opción incorrecta\n";
            system("pause");
            break;
        }
        system("clear");
    } while (option != 3);
    return 0;
}

nodeTree *createNode(int value)
{
    nodeTree *new_node = new nodeTree();
    new_node->value = value;

    return new_node;
}

void insertNode(nodeTree *&tree, int value)
{
    if (tree == NULL)
    {
        nodeTree *new_node = createNode(value);
        tree = new_node;
    }
    else
    {
        int valueNode = tree->value;
        if (value < valueNode)
        {
            insertNode(tree->left, value);
        }
        else
        {
            insertNode(tree->right, value);
        }
    }
}

void showTree(nodeTree *&tree, int count)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        showTree(tree->right, count++);
        for (size_t i = 0; i < count; i++)
        {
            cout << " ";
        }
        cout << tree->value;
        showTree(tree->left, count++);
    }
}
