#include <iostream>
#include "hash.h"

using namespace std;


    int Hash::funcaoHash(Aluno aluno)
    {
        return (aluno.obterRa() % max_posicoes);
    }

    Hash::Hash(int tamanhoVetor, int max)
    {
        quant_itens = 0;
        max_itens = max;
        max_posicoes = tamanhoVetor;
        estrutura = new Aluno[tamanhoVetor];
    }

    Hash::~Hash()
    {
        delete [] estrutura;
    }

    bool Hash::estaCheio()
    {
        return (quant_itens == max_itens);
    }

    int Hash::tamanhoAtual()
    {
        return (quant_itens);
    }

    void Hash::inserir(Aluno aluno)
    {
        int local = funcaoHash(aluno);
        estrutura[local] = aluno;
        quant_itens++;
    }

    void Hash::remover(Aluno aluno)
    {
        int local = funcaoHash(aluno);
        if(estrutura[local].obterRa() != -1) {
            estrutura[local] = Aluno(-1, " ");
            quant_itens--;
        }
    }

    void Hash::buscar(Aluno& aluno, bool& busca)
    {
        int local = funcaoHash(aluno);
        Aluno aux = estrutura[local];
        if(aluno.obterRa() != aux.obterRa()) {
            busca = false;
        } else {
            busca = true;
            aluno = aux;
        }
    }

    void Hash::imprimir()
    {
        cout << "RA  ||  NOME \n";
        for(int i=0; i<max_posicoes; i++) {
            if(estrutura[i].obterRa() != -1) {
                cout << i << " : " << estrutura[i].obterRa();
                cout << estrutura[i].obterNome() << endl;
            }
        }
    }