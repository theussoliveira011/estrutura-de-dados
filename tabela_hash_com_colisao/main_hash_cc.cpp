#include <iostream>
#include "hash.h"

using namespace std;

int main(){
    cout << "Programa gerador de Hash!\n";
    int tamanhoVetor, max;
    cout << "Digite o tamanho da Hash!\n";
    cin >> tamanhoVetor;
    cout << "Digite o numero maximo de elemento!\n";
    cin >> max;
    cout << "O fator de carga e: " << (float)max / (float) tamanhoVetor << endl;
    Hash alunoHash(tamanhoVetor, max);
    int opcao;
    int ra;
    string nome;
    bool busca;


    do{
        cout << "Digite 0 para parar o Algoritmo!\n";
        cout << "Digite 1 para inserir elemento!\n";
        cout << "Digite 2 para remover um elemento!\n";
        cout << "Digite 3 para buscar um elemento!\n";
        cout << "Digite 4 para imprimir a Tabela Hash!\n;";
        cin >> opcao;

        if(opcao == 1) {
            cout << "Qual RA do Aluno?\n";
            cin >> ra;
            cout << "Qual o nome do Aluno?\n";
            cin >> nome;
            Aluno aluno(ra, nome);
            alunoHash.inserir(aluno);
        }else if(opcao == 2) {
            cout << "Qual o RA do aluno?\n";
            cin >> ra;
            Aluno aluno(ra, " ");
            alunoHash.remover(aluno);
        } else if(opcao == 3) {
            cout << "Qual e o RA do aluno?\n";
            cin >> ra;
            Aluno aluno(ra, "");
            alunoHash.buscar(aluno, busca);
            if (busca) {
                cout << "Aluno encontrado! \n";
                cout << "RA: " << "  " << aluno.obterRa() << "\n";
                cout << "Nome: " << "  " << aluno.obterNome() << "\n";
            } else {
                cout << "Aluno não encontrado no banco de Dados!\n";
            }
        } else if(opcao == 4) {
            alunoHash.imprimir();
        }

    }while(opcao != 0);

    return 0;
}