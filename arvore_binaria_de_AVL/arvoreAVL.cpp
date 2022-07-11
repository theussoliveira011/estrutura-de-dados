#include <iostream>
#include <cstddef>
#include "arvoreAVL.h"

using namespace std;

    arvoreAVL::arvoreAVL() //construtor
    {   
        raiz = NULL;
    }

    arvoreAVL::~arvoreAVL() // destrutor
    {
        deleteBst(raiz);
    }

    void arvoreAVL::deleteBst(No* noAtual)
    {
        if (noAtual != NULL){
            deleteBst(noAtual->filhoesquerda);

            deleteBst(noAtual->filhodireita);

            delete noAtual;
        }
    }

    No* arvoreAVL::obterRaiz()
    {
        return raiz;
    }

    bool arvoreAVL::estaVazio()
    {
        return (raiz == NULL);
    }

    bool arvoreAVL::estaCheio()
    {
        try{
            No* temp = new No;
            delete temp;
            return false;
        } catch(bad_alloc exception){
            return true;
        }
    }

    void arvoreAVL::inserir(Aluno aluno)
    {
        bool cresceu;
        insereRecursivo(raiz, aluno, cresceu);
    }

    void arvoreAVL::insereRecursivo(No*& noatual, Aluno aluno, bool& cresceu){
        if(noatual == NULL){
            noatual= new No;
            noatual->filhodireita = NULL;
            noatual->filhoesquerda = NULL;
            noatual-> aluno;
            noatual-> fatorB = 0;
            return;
        }
        if (aluno.obterRa() < noatual->aluno.obterRa()){
            insereRecursivo(noatual->filhoesquerda, aluno, cresceu);
            if(cresceu){
                noatual->fatorB-=1;
            }
        } else {
            insereRecursivo(noatual->filhodireita, aluno, cresceu);
            if(cresceu){
                noatual->fatorB+=1;
            }
        }
        realizarotacao(noatual);

        if(cresceu && noatual->fatorB == 0){
            cresceu = false;
        } 
    }

    void arvoreAVL::remover(Aluno aluno)
    {
        bool diminuiu;
        removerBusca(aluno, raiz, diminuiu);
    }

    void arvoreAVL::removerBusca(Aluno aluno, No*& noatual, bool& diminuiu)
    {
        if (aluno.obterRa() < noatual->aluno.obterRa()){
            removerBusca(aluno, noatual->filhoesquerda, diminuiu);
            if(diminuiu){
                noatual->fatorB+=1;
            }
        } else if (aluno.obterRa() > noatual->aluno.obterRa()) {
            removerBusca(aluno, noatual->filhodireita, diminuiu);
            if(diminuiu){
                noatual->fatorB-=1;
            }
        } else{
            deletarNo(noatual, diminuiu);
        }
        if (noatual != NULL){
            realizarotacao(noatual);
            if (diminuiu && noatual->fatorB != 0){
                diminuiu = false;
            }
        }
    }

    void arvoreAVL::deletarNo(No*& noatual, bool& diminuiu)
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
            removerBusca(alunoSucessor, noatual->filhodireita, diminuiu);
            if (diminuiu){
                noatual->fatorB-=1;
            }
        }
    }

    void arvoreAVL::obterSucessor(Aluno& alunoSucessor, No* temp)
    {
        temp = temp->filhodireita;
        while(temp->filhoesquerda != NULL){
            temp = temp->filhoesquerda;
        }
        alunoSucessor = temp->aluno; 
    }

    void arvoreAVL::buscar(Aluno& aluno, bool& busca)
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

    void arvoreAVL::imprimirPreOrdem(No* noAtual)
    {
        if (noAtual != NULL){
            cout << noAtual->aluno.obterNome() << ": ";
            cout << noAtual->aluno.obterRa() << endl;

            imprimirPreOrdem(noAtual->filhoesquerda);

            imprimirPreOrdem(noAtual->filhodireita);
        }
    }

    void arvoreAVL::imprimirEmOrdem(No* noAtual)
    {
        if (noAtual != NULL){
            imprimirEmOrdem(noAtual->filhoesquerda);

            cout << noAtual->aluno.obterNome() << ": ";
            cout << noAtual->aluno.obterRa() << endl;

            imprimirEmOrdem(noAtual->filhodireita);
        }
    }

    void arvoreAVL::imprimirPosOrdem(No* noAtual) 
    {
        if (noAtual != NULL){
            imprimirPosOrdem(noAtual->filhoesquerda);
            
            imprimirPosOrdem(noAtual->filhodireita);

            cout << noAtual->aluno.obterNome() << ": ";
            cout << noAtual->aluno.obterRa() << endl;
        }
    }


//Metodos arvore AVL

void arvoreAVL::rotacaoDireita(No*& pai){
    No* novopai = pai->filhoesquerda;
    pai->filhoesquerda = novopai->filhodireita;
    novopai->filhodireita = pai;
    pai = novopai;
}

void arvoreAVL::rotacaoEsquerda(No*& pai){
    No* novopai = pai->filhodireita;
    pai->filhodireita = novopai->filhoesquerda;
    novopai->filhoesquerda = pai;
    pai = novopai;
}

void arvoreAVL::rotacaoDireitaEsquerda(No*& pai){
    No* filho = pai->filhodireita;
    rotacaoDireita(filho);
    pai->filhodireita = filho;
    rotacaoEsquerda(filho);
}

void arvoreAVL::rotacaoesquerdadireita(No*& pai){
    No* filho = pai->filhoesquerda;
    rotacaoDireita(filho);
    pai->filhodireita = filho;
    rotacaoEsquerda(filho);
}

void arvoreAVL::realizarotacao(No*& pai){
    No* filho;
    No* neto;
    if (pai->fatorB == -2){ //rotaciona para a direita
        filho = pai->filhoesquerda;

        if (filho->fatorB == -1){ //simples para a direita
            pai->fatorB = 0;
            filho->fatorB = 0;
            rotacaoDireita(pai);

        } else if (filho->fatorB == 0){ //simples para a direita
            pai->fatorB = -1;
            filho->fatorB = 1;
            rotacaoDireita(pai);

        } else if (filho->fatorB == 1){ //Rotacao dupla
            neto = filho->filhodireita;

            if (neto->fatorB == -1){
                pai->fatorB = 1;
                filho->fatorB = 0;

            } else if (neto->fatorB == 0){
                pai->fatorB = 0;
                filho->fatorB = 0;

            } else if (neto->fatorB == 1){
                pai->fatorB = 0;
                filho->fatorB = -1;
            }

            neto->fatorB = 0;
            rotacaoesquerdadireita(pai);
        }



    } else if(pai->fatorB == 2){ //rotacao para esquerda
        filho = pai->filhodireita;

        if (filho->fatorB == 1){ // simples para a esquerda
            pai->fatorB = 0;
            filho->fatorB = 0;
            rotacaoEsquerda(pai);

        } else if (filho->fatorB == 0){ //simples para a esquerda
            pai->fatorB = 1;
            filho->fatorB = -1;

        } else if (filho->fatorB == -1){ // rotacao dupla
            neto = filho->filhoesquerda;

                if (neto->fatorB == -1){
                    pai->fatorB = 0;
                    filho->fatorB = 1;

                } else if (neto->fatorB == 1){
                    pai->fatorB = -1;
                    filho->fatorB = 0;
                }

                neto->fatorB = 0;
                rotacaoDireitaEsquerda(pai);
        }
    }
}

