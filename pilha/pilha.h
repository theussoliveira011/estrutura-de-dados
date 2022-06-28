
// pilha = stack
typedef int TipoItem;
const int max_items = 100;

class stack{
    private:
    int tamanho;
    TipoItem* estrutura;

    public:
    stack(); // Construtora // stack
    ~stack(); // destrutora // ~stack
    bool fullstack(); // Verifica se a pilha esta cheia
    bool nullstack(); // Verifica se a pilha esta vazia
    void push(TipoItem item); // Inserir um dado na pilha//push 
    TipoItem pop(); // Tira dado da pilha
    void print(); //    print
    int qualTamanho(); // tamanho

};