// Grafo simples nao-direcionado ponderado

#include <iostream>

using namespace std;

typedef string tipoItem;

class grafo {
    private:
    int arestaNula;
    int maxVertices;
    int numVertices;
    tipoItem* vertices;
    int** matrizAdj;


    public:
    grafo(int max, int valorArestaNula); //construtor, duas entradas, uma o valor maximo do vetor e a outra o valor das arestas
    ~grafo();
    int obterIndice(tipoItem item); //ve qual a ordem dos itens adicionados no vetor
    bool estaCheio();
    void insereVertice(tipoItem item);
    void insereAresta(tipoItem noSaida, tipoItem noEntrada, int peso);
    int obterPeso(tipoItem noSaida, tipoItem noEntrada);
    int obterGrau(tipoItem item);
    void imprimirMatriz();
    void imprimirVertices();
};