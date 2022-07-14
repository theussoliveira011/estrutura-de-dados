#ifndef NO_H /*Se não está definido o NO_H */
#define NO_H /*Define o NO_H*/

#include <iostream>

using namespace std;

typedef string tipoItem;

struct No
{
    tipoItem valor;
    No* proximo;
};

struct Node
{
    tipoItem valor;
    Node* proximo;
};


#endif /*Termina a Definição*/