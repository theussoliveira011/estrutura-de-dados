#include <iostream>
#include "pilhadinamica.h"
#include <cstddef> //NULL   

using namespace std;


    pilhadinamica::pilhadinamica()
    {
        nodeTopo = NULL;
    }

    pilhadinamica::~pilhadinamica()
    {
        Node* nodeTemp;
        while (nodeTopo != NULL) {
            nodeTemp = nodeTopo;
            nodeTopo = nodeTopo->proximo;
            delete nodeTemp;
        }
    }

    bool pilhadinamica::estavazio()
    {
        return (nodeTopo == NULL);
        cout << "A pilha está vazia";
    }

    bool pilhadinamica::estacheio()
    {
        Node* nodeNew;
        try{
            nodeNew = new Node;
            delete nodeNew;
            return false;
        } catch(bad_alloc exception) {
            return true;
        }
    }

    void pilhadinamica::inserir(TipoItem item)
    {
        if(estacheio()) {
            cout << "A pilha está cheia";
            cout << "Não é possível inserir elementos.";
        } else {
            Node* nodeNew = new Node;
            nodeNew->valor = item;
            nodeNew->proximo = nodeTopo;
            nodeTopo = nodeNew;
        }
    }

    TipoItem pilhadinamica::remover()
    {
        if(estavazio()) {
            cout << "A pilha esta vazia\n";
            cout << "nao foi possivel remover nenhum elemento!\n";
            return 0;
        } else {
            Node* nodeTemp;
            nodeTemp = nodeTopo;
            TipoItem item = nodeTopo->valor;
            nodeTopo = nodeTopo->proximo;
            delete nodeTemp;
            return item;
        }
    }

    void pilhadinamica::imprimir()
    {
        Node* nodeTemp = nodeTopo;
        cout << "Pilha: [ ";
        while (nodeTemp != NULL) {
            cout << nodeTemp->valor << " ";
            nodeTemp = nodeTemp->proximo;
        }
        cout << "]\n";
    }
