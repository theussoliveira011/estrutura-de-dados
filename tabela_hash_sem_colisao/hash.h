#include <iostream>
#include "aluno.h"


class Hash {
    private:
    int funcaoHash(Aluno aluno);
    int max_itens;
    int max_posicoes;
    int quant_itens;
    Aluno* estrutura;

    public:
    Hash(int tamanhoVetor, int max);
    ~Hash();
    bool estaCheio();
    int tamanhoAtual();
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void buscar(Aluno& aluno, bool& busca);
    void imprimir(); 

};