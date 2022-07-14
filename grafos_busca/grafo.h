// Grafo simples direcionado ponderado
#include <iostream>
#include "No.h"
#include "pilhadinamica.h"
#include "filadinamica.h"



using namespace std;

// typedef string tipoItem;

class grafo {
    private:
    int arestaNula;
    int maxVertices;
    int numVertices;
    tipoItem* vertices;
    int** matrizAdj;
    bool* marcador; //Vê a quantidade de vertices e guarda a informação se é verdadeiro ou falso. Começa falso e termina verdadeiro.

    public:
    grafo(int max, int valorArestaNula); //construtor, duas entradas, uma o valor maximo do vetor e a outra o valor das arestas
    ~grafo();
    int obterIndice(tipoItem item); //Vê qual a ordem dos itens adicionados no vetor
    bool estaCheio();
    void insereVertice(tipoItem item);
    void insereAresta(tipoItem noSaida, tipoItem noEntrada, int peso);
    int obterPeso(tipoItem noSaida, tipoItem noEntrada);
    int obterGrau(tipoItem item);
    void imprimirMatriz();
    void imprimirVertices();


    void limpaMarcador();
    void buscaEmLargura(tipoItem origem, tipoItem destino);
    void buscaEmProfundidade(tipoItem origem, tipoItem destino);
};