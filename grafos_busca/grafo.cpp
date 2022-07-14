#include <iostream>
#include "grafo.h"
#include "filadinamica.h"
#include "pilhadinamica.h"


using namespace std;

    grafo::grafo(int max, int valorArestaNula) //construtor, duas entradas, uma o valor maximo do vetor e a outra o valor das arestas
    {
        numVertices = 0;
        maxVertices = max;
        arestaNula = valorArestaNula;

        marcador = new bool[maxVertices];

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

        // matrizAdj[coluna][linha] = peso; //Remover se for direcionado
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

    void grafo::limpaMarcador()
    {
        for (int i = 0; i<maxVertices; i++){
            marcador[i] = false;
        }
    }

    void grafo::buscaEmLargura(tipoItem origem, tipoItem destino)
    {
        filadinamica filavertices;
        bool encontrado = false;
        limpaMarcador();
        filavertices.inserir(origem);

        do{
            tipoItem verticeAtual = filavertices.remover();
            if (verticeAtual == destino) {
                cout << "Visitando: " << verticeAtual << endl;
                cout << "Caminho encontrado!\n";
                encontrado = true;
            } else{
                int indice = obterIndice(verticeAtual);
                cout << "Visitando: " << verticeAtual << endl;
                for (int i = 0; i<maxVertices; i++){
                    if (matrizAdj[indice][i] != arestaNula){
                        if(!marcador[i]){
                            cout << "Enfileirando: " << vertices[i] << endl;
                            filavertices.inserir(vertices[i]);
                            marcador[i] = true;
                        }
                    }
                }
            }

        } while(!filavertices.estavazio() && !encontrado);
        if (!encontrado){
            cout << "Caminho nao encontrado!\n";
        }
    }

    void grafo::buscaEmProfundidade(tipoItem origem, tipoItem destino)
    {
        pilhadinamica pilhavertices;
        bool encontrado = false;
        limpaMarcador();
        pilhavertices.inserir(origem);

        do{
            tipoItem verticeAtual = pilhavertices.remover();
            if (verticeAtual == destino) {
                cout << "Visitando: " << verticeAtual << endl;
                cout << "Caminho encontrado!\n";
                encontrado = true;
            } else{
                int indice = obterIndice(verticeAtual);
                cout << "Visitando: " << verticeAtual << endl;
                for (int i = 0; i<maxVertices; i++){
                    if (matrizAdj[indice][i] != arestaNula){
                        if(!marcador[i]){
                            cout << "Empilhando: " << vertices[i] << endl;
                            pilhavertices.inserir(vertices[i]);
                            marcador[i] = true;
                        }
                    }
                }
            }

        } while(!pilhavertices.estavazio() && !encontrado);
        if (!encontrado){
            cout << "Caminho nao encontrado!\n";
        }
    }