// Fila Dinâmica = Dynamic Queue
#ifndef FILADINAMICA_H
#define FILADINAMICA_H

#include "No.h"

/*typedef int TipoItem;

class No 
{
    public:
    TipoItem valor;
    No* proximo;
}; */

class filadinamica {
    private: 
    No* primeiro;
    No* ultimo;  

    public: 
    filadinamica();
    ~filadinamica();
    bool estavazio();
    bool estacheio();
    void inserir(tipoItem item);
    tipoItem remover();
    void imprimir();
};

#endif