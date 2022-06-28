// Pilha dinâmica = Dynamic Stack

typedef int TipoItem;

struct Node 
{
    TipoItem valor;
    Node* proximo;
};

class pilhadinamica {
    private:
    Node* nodeTopo;

    public:
    pilhadinamica(); //construtor
    ~pilhadinamica(); //desconstrutor   
    bool estavazio(); //isempty
    bool estacheio(); //tem memória // isfull
    void inserir(TipoItem item);  //push    
    TipoItem remover(); //pop   
    void imprimir();//print
};