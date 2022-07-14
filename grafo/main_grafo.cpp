#include <iostream>
#include "grafo.h"

using namespace std;

int main(){
    int max, valorArestaNula;
    cout << "Digite a quantidade maxima de vertices: ";
    cin >> max;
    cout <<  "Digite o valor para representar a ausencia de aresta: ";
    cin >> valorArestaNula;
    grafo grafo1(max, valorArestaNula);
    tipoItem item1, item2;
    int opcao, valor, peso;


    do {
        cout << "Digite 0 para parar o algoritmo!\n";
        cout << "Digite 1 para inserir um vertice!\n";
        cout << "Digite 2 para inserir uma aresta!\n";
        cout << "Digite 3 para imprimir o grau de um vertice!\n";
        cout << "Digite 4 para imprimir o peso de uma aresta!\n";
        cout << "Digite 5 para imprimir a matriz de adjacencias!\n";
        cout << "Digite 6 para imprimir a lista de vertices!\n";
        cin >> opcao;

        if (opcao == 1){
            cout << "Digite o elemento do vertice que sera inserido:\n";
            cin >> item1;
            grafo1.insereVertice(item1);
        } else if (opcao == 2){
            cout << "Digite o vertice de saida:\n";
            cin >> item1;
            cout << "Digite o vertice de entrada:\n";
            cin >> item2;
            cout << "Digite o peso desta aresta:\n";
            cin >> peso;
            grafo1.insereAresta(item1, item2, peso);
        }  else if (opcao == 3){
            cout << "digite o vertice que sera calculado o grau:\n";
            cin >> item1;
            valor = grafo1.obterGrau(item1);
            cout << "O grau desse vertice e: " << valor << endl;
        } else if (opcao == 4){
            cout << "Digite o vertice de saida:\n";
            cin >> item1;
            cout << "Digite o vertice de entrada:\n";
            cin >> item2;
            valor = grafo1.obterPeso(item1, item2);
            cout << "O peso dessa aresta e: " << valor << endl;
        } else if (opcao == 5){
            grafo1.imprimirMatriz();
        } else if (opcao == 6){
            grafo1.imprimirVertices();
        }



    } while (opcao != 0);
};