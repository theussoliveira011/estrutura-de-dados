// Fila Dinâmica = Dynamic Queue

typedef int TipoItem;

class No 
{
    public:
    TipoItem valor;
    No* proximo;
};

class filadinamica {
    private: 
    No* primeiro;
    No* ultimo;  

    public: 
    filadinamica();
    ~filadinamica();
    bool estavazio();
    bool estacheio();
    void inserir(TipoItem item);
    TipoItem remover();
    void imprimir();
};