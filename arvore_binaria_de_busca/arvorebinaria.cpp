#include <iostream>
#include <cstddef>
#include "arvorebinaria.h"

using namespace std;

    bst::bst() //construtor
    {   
        raiz = NULL;
    }

    bst::~bst() // destrutor
    {
        deleteBst(raiz);
    }

    void bst::deleteBst(No* noAtual)
    {
        if (noAtual != NULL){
            deleteBst(noAtual->filhoesquerda);

            deleteBst(noAtual->filhodireita);

            delete noAtual;
        }
    }

    No* bst::obterRaiz()
    {
        return raiz;
    }

    bool bst::estaVazio()
    {
        return (raiz == NULL);
    }

    bool bst::estaCheio()
    {
        try{
            No* temp = new No;
            delete temp;
            return false;
        } catch(bad_alloc exception){
            return true;
        }
    }

    void bst::inserir(Aluno aluno)
    {
        if(estaCheio()){ 
            cout << "A Arvore esta cheia!\n";
            cout << "Nao foi possivel inserir esse elemento!\n";
        } else{ //Cria um No novo para armazenar o elemento.
            No* noNovo = new No; //O "new" posibilita deletar esse no caso precise
            noNovo->aluno = aluno; // aluno inserido
            noNovo->filhodireita = NULL; // informa que o filho a direita e null
            noNovo->filhoesquerda = NULL; // idem.
            if (estaVazio()){ // testa se a raiz e igual a NULL.
                raiz = noNovo; // Se estiver vazia a raiz aponta para o noNovo
            } else{ //Caso contrario executa os comandos abaixo.
                No* temp = raiz; // Criacao de um No temporario e ele aponta para a raiz
                while (temp != NULL) { //O no continua em execucao enquanto for diferente de NULL
                    if (aluno.obterRa() < temp->aluno.obterRa()){ //Se o RA for menor que a variavel temporaria, sera armazenado na esquerda. o temp aponta para um no, pega a informacao aluno e o RA desse aluno.
                        if (temp->filhoesquerda == NULL) { //Pergunta se existe elementos a esquerda
                            temp->filhoesquerda = noNovo; // Se a afirmacao for verdadeira adiciona o temp no noNovo
                            break;
                        } else{
                            temp = temp->filhoesquerda;
                        }
                    } else{ // Se a afirmacao acima for falsa, executa a linha de codigos abaixo
                        if (temp->filhodireita == NULL){ // Se o filho da direita e NULL, adiciona o filho da direita ao noNovo;
                            temp->filhodireita = noNovo;
                            break;
                        } else{
                            temp = temp->filhodireita; //Se a afirmacao acima for falsa, o temp e armazenado no filho da direita.
                        }
                    }
                }
            }
        }
    }

    void bst::remover(Aluno aluno)
    {
        removerBusca(aluno, raiz);
    }

    void bst::removerBusca(Aluno aluno, No*& noatual)
    {
        if (aluno.obterRa() < noatual->aluno.obterRa()){
            removerBusca(aluno, noatual->filhoesquerda);
        } else if (aluno.obterRa() > noatual->aluno.obterRa()) {
            removerBusca(aluno, noatual->filhodireita);
        } else{
            deletarNo(noatual);
        }
    }

    void bst::deletarNo(No*& noatual)
    {
        No* temp = noatual;
        if (noatual->filhoesquerda == NULL){
            noatual = noatual->filhodireita;
            delete temp;
        } else if (noatual->filhodireita == NULL){
            noatual = noatual->filhoesquerda;
            delete temp;
        } else{
            Aluno alunoSucessor;
            obterSucessor(alunoSucessor, noatual);
            noatual->aluno = alunoSucessor;
            removerBusca(alunoSucessor, noatual->filhodireita);
        }
    }

    void bst::obterSucessor(Aluno& alunoSucessor, No* temp)
    {
        temp = temp->filhodireita;
        while(temp->filhoesquerda != NULL){
            temp = temp->filhoesquerda;
        }
        alunoSucessor = temp->aluno; 
    }

    void bst::buscar(Aluno& aluno, bool& busca)
    {
        busca = false;
        No* noAtual = raiz;
        while (noAtual != NULL){
            if (aluno.obterRa() < noAtual->aluno.obterRa()){ //Se o RA do aluno for menor que o RA buscado, ele segue para esquerda.
                noAtual = noAtual->filhoesquerda;
            } else if (aluno.obterRa() > noAtual->aluno.obterRa()){
                noAtual = noAtual->filhodireita;
            } else{
                busca = true;
                aluno = noAtual->aluno; //aluno recebe o valor do noAtual aluno.
                break;
            }
        }   
    }

    void bst::imprimirPreOrdem(No* noAtual)
    {
        if (noAtual != NULL){
            cout << noAtual->aluno.obterNome() << ": ";
            cout << noAtual->aluno.obterRa() << endl;

            imprimirPreOrdem(noAtual->filhoesquerda);

            imprimirPreOrdem(noAtual->filhodireita);
        }
    }

    void bst::imprimirEmOrdem(No* noAtual)
    {
        if (noAtual != NULL){
            imprimirEmOrdem(noAtual->filhoesquerda);

            cout << noAtual->aluno.obterNome() << ": ";
            cout << noAtual->aluno.obterRa() << endl;

            imprimirEmOrdem(noAtual->filhodireita);
        }
    }

    void bst::imprimirPosOrdem(No* noAtual) 
    {
        if (noAtual != NULL){
            imprimirPosOrdem(noAtual->filhoesquerda);
            
            imprimirPosOrdem(noAtual->filhodireita);

            cout << noAtual->aluno.obterNome() << ": ";
            cout << noAtual->aluno.obterRa() << endl;
        }
    }