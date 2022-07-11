#include <iostream>
#include "aluno.h"


struct No{
    Aluno aluno;
    No* filhoesquerda;
    No* filhodireita;


    int fatorB; //fator de balanceamento
};

class arvoreAVL{
    private:
    No* raiz;

    public:
    arvoreAVL();
    ~arvoreAVL();
    void deleteBst(No* noAtual);
    No* obterRaiz();
    bool estaCheio();
    bool estaVazio();
    void inserir(Aluno aluno);
    void insereRecursivo(No*& noatual, Aluno aluno, bool& cresceu);
    void remover(Aluno aluno);
    void removerBusca(Aluno aluno, No*& noatual, bool& diminuiu);
    void deletarNo(No*& noatual, bool& diminuiu);
    void obterSucessor(Aluno& alunoSucessor, No* temp);
    void buscar(Aluno& aluno, bool& busca); 
    void imprimirPreOrdem(No* noAtual);
    void imprimirEmOrdem(No* noAtual);
    void imprimirPosOrdem(No* noAtual); 

    void rotacaoDireita(No*& tree);
    void rotacaoEsquerda(No*& tree);
    void rotacaoesquerdadireita(No*& tree);
    void rotacaoDireitaEsquerda(No*& tree);
    void realizarotacao(No*& tree);
    
};