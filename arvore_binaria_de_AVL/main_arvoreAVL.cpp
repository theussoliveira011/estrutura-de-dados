#include <iostream>
#include "arvoreAVL.h"

using namespace std;

int main()
{
    arvoreAVL arvoreAlunos;
    int opcao, ra, imp;
    string nome;
    bool busca = false;

    do
    {
        cout << "Digite 0 para parar o algoritmo!\n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para remover um elemento!\n";
        cout << "Digite 3 para buscar um elemento!\n";
        cout << "Digite 4 para imprimir um elemento!\n";
        cin >> opcao;

        if (opcao == 1)
        {
            cout << "Digite o nome do Aluno: \n";
            cin >> nome;
            cout << "Digite o RA do Aluno: \n";
            cin >> ra;
            Aluno aluno(ra, nome);
            if (arvoreAlunos.estaCheio())
            {
                cout << "A arvore esta cheia!\n";
                cout << "Nao foi possivel inserir o elemento!\n";
            }
            else
            {
                arvoreAlunos.inserir(aluno);
            }
        }
        else if (opcao == 2)
        {
            cout << "Digite o Ra do Aluno a ser removido!\n";
            cin >> ra;
            Aluno aluno(ra, " ");
            arvoreAlunos.remover(aluno);
        }
        else if (opcao == 3)
        {
            cout << "Digite o RA do aluno a ser buscado!\n";
            cin >> ra;
            Aluno aluno(ra, " ");
            arvoreAlunos.buscar(aluno, busca);
            if (busca)
            {
                cout << "Elemento encontrado!\n";
                cout << "Nome: " << aluno.obterNome() << endl;
                cout << "RA: " << aluno.obterRa() << endl;
            }
            else
            {
                cout << "Elemento nao encontrado!\n";
            }
        }
        else if (opcao == 4)
        {
            cout << "Digite 1 para fazer a impressao em Pre-ordem!\n";
            cout << "Digite 2 para fazer a impressao em Ordem!\n";
            cout << "Digite 3 para fazer a impressao em Pos-ordem!\n";
            cin >> imp;
            if (imp == 1)
            {
                cout << "1";
                arvoreAlunos.imprimirPreOrdem(arvoreAlunos.obterRaiz());
            }
            else if (imp == 2)
            {
                cout << "2";
                arvoreAlunos.imprimirEmOrdem(arvoreAlunos.obterRaiz());
            }
            else if (imp == 3)
            {
                cout << "3";
                arvoreAlunos.imprimirPosOrdem(arvoreAlunos.obterRaiz());
            }
            else
            {
                cout << "Você digitou a opção errada, digite apenas o solicitado!\n";
            }
        }

    } while (opcao != 0);

    return 0;
}
