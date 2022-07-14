// Pilha dinâmica = Dynamic Stack
#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

#include "No.h"


/*typedef int tipoItem;

struct Node 
{
    TipoItem valor;
    Node* proximo;
};*/

class pilhadinamica {
    private:
    Node* nodeTopo;

    public:
    pilhadinamica(); //construtor
    ~pilhadinamica(); //desconstrutor   
    bool estavazio(); //isempty
    bool estacheio(); //tem memória // isfull
    void inserir(tipoItem item);  //push    
    tipoItem remover(); //pop   
    void imprimir();//print
};

#endif