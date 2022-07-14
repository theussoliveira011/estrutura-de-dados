#include <iostream>
#include "filadinamica.h"
#include <cstddef>
#include <new>

using namespace std;


    filadinamica::filadinamica()
    {
        primeiro = NULL;
        ultimo = NULL;
    }

    filadinamica::~filadinamica()
    {
        No* temp;
        while(primeiro != NULL) {
            temp = primeiro;
            primeiro = primeiro->proximo;
            delete temp;
        }
        ultimo = NULL;
    }

    bool filadinamica::estavazio()
    {
        return (primeiro == NULL);
    }

    bool filadinamica::estacheio()
    {
        No* temp;
        try {
            temp = new No;
            delete temp;
            return false;
        } catch(bad_alloc exception) {
            return true;
        }
    }

    void filadinamica::inserir(tipoItem item)
    {
        if(estacheio()) {
            cout << "A Fila está cheia";
            cout << "Não foi possivel inserir esse elemento!\n";
        } else{
            No* noNovo = new No;
            noNovo->valor = item;
            noNovo->proximo = NULL;
            if (primeiro == NULL) {
                primeiro = noNovo;
            } else {
                ultimo->proximo = noNovo;
            }

            ultimo = noNovo;
        }
    }

    tipoItem filadinamica::remover()
    {
        if(estavazio()) {
            cout << "A fila esta vazia!\n";
            cout << "Nao existe elementos a serem removidos!\n";
            return 0;
        } else {
            No* temp = primeiro;
            tipoItem item = primeiro->valor;
            primeiro = primeiro->proximo;
            if(primeiro == NULL) {
                ultimo = NULL;
            }
            delete temp;
            return item;
        }
    }

    void filadinamica::imprimir()
    {
        No* temp = primeiro;
        cout << "Fila= [ ";
        while (temp != NULL) {
            cout << temp->valor << " ";
            temp = temp->proximo;
        }
        cout << "]\n";
    }

    