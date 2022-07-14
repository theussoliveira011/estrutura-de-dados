#include <iostream>
#include "grafo.h"


using namespace std;

    grafo::grafo(int max, int valorArestaNula) //construtor, duas entradas, uma o valor maximo do vetor e a outra o valor das arestas
    {
        numVertices = 0;
        maxVertices = max;
        arestaNula = valorArestaNula;

        vertices = new tipoItem[maxVertices];

        matrizAdj = new int*[maxVertices];

        for (int y=0; y<maxVertices; y++){
            matrizAdj[y] = new int[maxVertices];
        }

        for (int i=0; i<maxVertices; i++){
            for(int j=0; j<maxVertices; j++){
                matrizAdj[i][j] = arestaNula;
            }
        }
    }

    grafo::~grafo() // destrutor
    {
        delete [] vertices;
        for (int i=0; i<maxVertices; i++){
            delete [] matrizAdj[i];
        }
        delete [] matrizAdj;
    }

    int grafo::obterIndice(tipoItem item) //ve qual a ordem dos itens adicionados no vetor
    {
        int indice = 0;
        while (item != vertices[indice]){
            indice ++;
        }
        if (item == vertices[indice]){
            return indice;
        } else {
            return indice = -1;
        }
        return indice;
    }
    
    bool grafo::estaCheio()
    {
        return (numVertices == maxVertices);
    }

    void grafo::insereVertice(tipoItem item)
    {
        if (estaCheio()){
            cout << "O numero maximo de vertices foi alcancado!\n";
        } else {
            vertices[numVertices] = item;
            numVertices++;
        }
    }

    void grafo::insereAresta(tipoItem noSaida, tipoItem noEntrada, int peso)
    {
        int linha = obterIndice(noSaida);
        int coluna = obterIndice(noEntrada);

        matrizAdj[linha][coluna] = peso;

        matrizAdj[coluna][linha] = peso; //Remover se for direcionado
    }

    int grafo::obterPeso(tipoItem noSaida, tipoItem noEntrada)
    {
        int linha = obterIndice(noSaida);
        int coluna = obterIndice(noEntrada);
        return (matrizAdj[linha][coluna]);
    }

    int grafo::obterGrau(tipoItem item)
    {
        int linha = obterIndice(item);
        int grau = 0;
        for (int i=0; i<maxVertices; i++){
            if (matrizAdj[linha][i] != arestaNula){
                grau++;
            }
        }
        return grau;
    }

    void grafo::imprimirMatriz()
    {
        cout << "Matriz de Adjacencias:\n";
        for (int i=0; i<maxVertices; i++){
            for (int j=0; j<maxVertices; j++){
                cout << matrizAdj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void grafo::imprimirVertices()
    {
        cout << "Lista de vertices:\n";
        for (int i=0; i<numVertices; i++){
            cout << i << ": " << vertices[i] << endl;
        }
    }