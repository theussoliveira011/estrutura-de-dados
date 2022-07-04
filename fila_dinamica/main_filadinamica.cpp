#include <iostream>
#include "filadinamica.h"

using namespace std;

int main(){

    filadinamica fila1;
    int opcao;
    TipoItem item;
    cout << "Programa gerador de filas\n";

    do
    {
        cout << "Digite 0 para parar o Programa!\n";
        cout << "Digite 1 para Inserir Elemento!\n";
        cout << "Digite 2 para excluir um elemento!\n";
        cout << "Digite 3 para imprimir a fila!\n";
        cin >> opcao;

        if(opcao == 1) {
            cout << "Digite o Elemento a ser inserido!\n";
            cin >> item;
            fila1.inserir(item);
        } else if (opcao == 2) {
            item = fila1.remover();
            cout << "O elemento removido e: " << item << endl;
        } else if (opcao == 3) {
            fila1.imprimir();
        }
    } while (opcao != 0);
    


    return 0;
}