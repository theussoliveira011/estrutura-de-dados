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
    delete[] estrutura;
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
    if (estaCheio())
    {
        cout << "A tabela esta cheia!\n";
        cout << "O elemento nao pode ser inserido!\n";
    }
    else{
        int local = funcaoHash(aluno);
        while (estrutura[local].obterRa() > 0)
        {
            local = (local + 1) % max_posicoes;
        }
        estrutura[local] = aluno;
        quant_itens++;
    }
}

void Hash::remover(Aluno aluno)
{
    int local = funcaoHash(aluno);
    bool teste = false;
    while (estrutura[local].obterRa() != -1)
    {
        if (estrutura[local].obterRa() == aluno.obterRa())
        {
            cout << "Elemento Removido!\n";
            estrutura[local] = Aluno(-2, " ");
            quant_itens--;
            teste = true;
            break;
        }
        local = (local + 1) % max_posicoes;
    }
    if (!teste)
    {
        cout << "Elemento nao encontrado!\n";
        cout << "Nenhum elemento removido!\n";
    }
}

void Hash::buscar(Aluno &aluno, bool &busca)
{
    int local = funcaoHash(aluno);
    busca = false;
    while (estrutura[local].obterRa() != -1)
    {
        if (estrutura[local].obterRa() == aluno.obterRa())
        {
            busca = true;
            aluno = estrutura[local];
            break;
        }
        local = (local + 1) % max_posicoes;
    }
}

void Hash::imprimir()
{
    cout << "RA  ||  NOME \n";
    for (int i = 0; i < max_posicoes; i++)
    {
        if (estrutura[i].obterRa() > 0)
        {
            cout << i << " : " << estrutura[i].obterRa();
            cout << estrutura[i].obterNome() << endl;
        }
    }
}