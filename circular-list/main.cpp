#include <iostream>
#include "CircularList.h"

using namespace std;

void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    CList* list = new CList();
    int option = 0;
    int value = 0;
    int position = 0;

    do {
        cout << "\n\n\t\t.:MENÚ:." << endl;
        cout << "0. Salir" << endl;
        cout << "1. Insertar nodo al inicio" << endl;
        cout << "2. Insertar nodo al medio" << endl;
        cout << "3. Insertar nodo al final" << endl;
        cout << "4. Eliminar nodo al inicio" << endl;
        cout << "5. Eliminar nodo al medio" << endl;
        cout << "6. Eliminar nodo al final" << endl;
        cout << "7. Listar" << endl;
        cout << "8. Ver tamaño de la lista" << endl;
        cout << "Digite una opción: ";

        cin >> option;

        switch (option) {
            case 0:
                cout << "Nos vemos" << endl;
                return;
            case 1:
                cout << "Ingrese el valor a insertar" << endl;
                cin >> value;
                list->insertFirst(value);
                break;
            case 2:
                cout << "Ingrese el valor y la posición a insertar: (Ej: 1 4)" << endl;
                cin >> value >> position;
                list->insertAt(value, position);
                break;
            case 3:
                cout << "Ingrese el valor a insertar" << endl;
                cin >> value;
                list->insertLast(value);
                break;
            case 4:
                list->deleteFirst();
                break;
            case 5:
                cout << "Ingrese el nodo a eliminar" << endl;
                cin >> position;
                list->deleteAt(position);
                break;
            case 6:
                list->deleteLast();
                break;
            case 7:
                cout << "Ingrese el número de vueltas" << endl;
                cin >> position;
                list->print(position);
                break;
            case 8:
                cout << list->getSize() << endl;
                break;
            default:
                cout << "method not implemented" << endl;
                break;
        }

    } while (option != 0);
}