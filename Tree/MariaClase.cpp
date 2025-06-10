#include <iostream>
using namespace std;

struct nodeTree
{
    int value = 0;
    nodeTree *left = NULL; // los ABL tienen dos lados que se traduce en dos punteros y aqui lo estamos inicializando
    nodeTree *right = NULL; // serian derecha izquierda 
};

//Esto es el prototipado de las funciones mejora la legibilidad del codigo se pone el tipo del dato 
//mas no la variable 

bool search (nodeTree *, int);
nodeTree *createNode(int);
bool numeroPrimo (int);
void insertNode(nodeTree *&, int);
void insertNodePrimos(nodeTree *&, int);
void preOrder (nodeTree *);
void postOrder (nodeTree *);
void inOrder (nodeTree *);
void showTree(nodeTree *&, int);

int main(){
    nodeTree *tree = NULL;
    nodeTree *tree_primos = NULL;
    int value,count = 0;
    int resp;

    do {
        cout << "MENU\n\n";
        cout << "1) Imprimir Arbol\n";
        cout << "2) Insertar elemento\n";
        cout << "3) Mostrar Arbol\n";
        cout << "4) Mostrar arbol solo con numero primos\n";
        cout << "5) Consultar si un elemento ya existe\n";
        cout << "0) Salir\n\n";
        cout << "\tMarque su opcion: ";
        cin >> resp;
        switch (resp) {
            case 0: {
                cout << "Finalizando programa";            
            } break;

            case 1: {
                cout<<"El arbol en forma de Pre Orden\n";
                preOrder(tree);
                cout<<"El arbol en forma de Post Orden\n";
                postOrder(tree);
                cout<<"\n";
                cout<<"El arbol en forma de In Orden\n";
                inOrder(tree);
                system("pause");
            } break;

            case 2: {
                cout << "Digite un numero = ";
                cin >> value;
                insertNode(tree, value);
                insertNodePrimos(tree_primos, value);
            } break;

            case 3: {
                showTree(tree, count);
                cout << "\n";
                system("pause");
            } break;

            case 4: {
                showTree(tree_primos, count);
                cout << "\n";
                system("pause");
            } break;

            case 5: {
                int value;
                cout << "\tIngrese el elemento a buscar: ";
                cin >> value;
                if (search(tree, value)) cout << "El valor indicado ya ha sido agregado a la lista" << endl; 
                else cout << "El valor indicado no ha sido agregado a la lista" << endl;
                system("pause");
            } break;

            default:
                cout << "Opción no valida" << endl;
                system("pause");
            break;
        } 
        system("cls");
    } while(resp != 0);

    return 0;
}


nodeTree *createNode(int value)
{
    nodeTree *new_node = new nodeTree(); // Basicamente aqui estamos creando un nuevo nodo de tipo arbol con un puntero new
    new_node->value = value; // le asignamos un valor al nuevo nodo

    return new_node;
}

bool numeroPrimo (int value){
    for (int i=2 ; i<value ; i++){
        if (value % i ==0) return false;
    }
    return true;
}

void insertNodePrimos(nodeTree *&treeprimos, int value) // toma como parametro un puntero y un valor 
{
    if (value%value == 0 && value%1 == 0) return;
    if (treeprimos == NULL)
    {
        nodeTree *new_node = createNode(value); // si el arbol esta vacio el arbol se vuelve el nuevo nodo 
        treeprimos = new_node;
    }
    else
    {
        int valueNode = treeprimos->value; // esto es para saber el valor del padre y asi compararlo 
        if (value < valueNode)
        {
            insertNode(treeprimos->left, value); // lo insertamos a la izq si es menor y para eso hacemos la llamada recursiva OJO
        }
        else
        {
            insertNode(treeprimos->right, value); // dere si es mayor 
        }
    }
}

void insertNode(nodeTree *&tree, int value) // toma como parametro un puntero y un valor 
{
    if (tree == NULL)
    {
        nodeTree *new_node = createNode(value); // si el arbol esta vacio el arbol se vuelve el nuevo nodo 
        tree = new_node;
    }
    else
    {
        int valueNode = tree->value; // esto es para saber el valor del padre y asi compararlo 
        if (value < valueNode)
        {
            insertNode(tree->left, value); // lo insertamos a la izq si es menor y para eso hacemos la llamada recursiva OJO
        }
        else
        {
            insertNode(tree->right, value); // dere si es mayor 
        }
    }
}

bool search (nodeTree *tree, int value){  // esta funcion es para saber si el numero ya esta en el arbol
    if (!tree) return false;
    else
        if (tree->value== value) return true;
    else if (tree->value>value) return search (tree->left, value);
    else return search (tree->right,value);
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

void preOrder (nodeTree *tree){ // Raiz izq derecha 
    if (tree){
        cout<<tree->value<<"\n";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
void postOrder (nodeTree *tree){ // izq derecha Raiz 
    if (tree){
        postOrder(tree->left);
        postOrder(tree->right);
        cout<<tree->value<<"\n";
    }
}

void inOrder (nodeTree *tree){ // izq raiz derecha o en oreden de menor a mayor
    if (tree){
        inOrder(tree->left);
        cout<<tree->value<<"\n";
        inOrder(tree->right);
    }
}

