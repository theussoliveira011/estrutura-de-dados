#include <iostream>
#include "aluno.h"


struct No{
    Aluno aluno;
    No* filhoesquerda;
    No* filhodireita;
};

class bst{ //BST = Binary Search Tree
    private:
    No* raiz;

    public:
    bst();
    ~bst();
    void deleteBst(No* noAtual);
    No* obterRaiz();
    bool estaCheio();
    bool estaVazio();
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void removerBusca(Aluno aluno, No*& noatual);
    void deletarNo(No*& noatual);
    void obterSucessor(Aluno& alunoSucessor, No* temp);
    void buscar(Aluno& aluno, bool& busca); 
    void imprimirPreOrdem(No* noAtual);
    void imprimirEmOrdem(No* noAtual);
    void imprimirPosOrdem(No* noAtual); 
};