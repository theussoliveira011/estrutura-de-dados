#include <iostream>
#include "pilha.h"

using namespace std;

    stack::stack() // Construtora // stack
    {
        tamanho = 0;
        estrutura = new TipoItem[max_items];
    }

    stack::~stack()// destrutora // ~stack
    {
        delete [] estrutura;
    }

    bool stack::fullstack() // Verifica se a pilha esta cheia
    {
        return (tamanho == max_items);
    }

    bool stack::nullstack() // Verifica se a pilha esta vazia
    {
        return (tamanho == 0);
    }

    void stack::push(TipoItem item) // Inserir um dado na pilha//push 
    {
        if (fullstack()) {
            cout << "A pilha esta cheia! \n";
            cout << "Nao e possivel inserir este elemente! \n";
        } else {
            estrutura[tamanho] = item;
            tamanho++;
        }
    }

    TipoItem stack::pop() // Tira dado da pilha
    {
        if(nullstack()) {
            cout << "A pilha esta vazia!\n"; //throw
            cout << "Nao tem elemento para ser removido!\n";
            return 0;
        } else{
            tamanho--;
            return estrutura[tamanho];           
        }
    }

    void stack::print() //    print
    {
        cout << "Pilha: [ ";
        for(int i = 0; i<tamanho; i++) {
            cout << estrutura[i] << " ";
        }
        cout << "]\n";
    }

    int stack::qualTamanho() // tamanho

    
    {
        return tamanho;
    }