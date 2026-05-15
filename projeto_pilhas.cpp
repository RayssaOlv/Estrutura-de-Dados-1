#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// --- usando vetor
class PilhaVetor {
private:
    int* elementos;
    int topo;
    int capacidade;

public:
    PilhaVetor(int cap) {
        capacidade = cap;
        elementos = new int[capacidade];
        topo = -1;
    }

    ~PilhaVetor() {
        delete[] elementos;
    }

    void empilhar(int valor) {
        if (topo < capacidade - 1) {
            elementos[++topo] = valor;
        }
    }

    int desempilhar() {
        if (topo >= 0) {
            return elementos[topo--];
        }
        throw runtime_error("Pilha vazia");
    }

    bool vazia() {
        return topo == -1;
    }
};

// --- usando lista
struct No {
    int dado;
    No* proximo;
};

class PilhaLista {
private:
    No* topo;

public:
    PilhaLista() {
        topo = nullptr;
    }

    ~PilhaLista() {
        while (!vazia()) {
            desempilhar();
        }
    }

    void empilhar(int valor) {
        No* novo = new No();
        novo->dado = valor;
        novo->proximo = topo;
        topo = novo;
    }

    int desempilhar() {
        if (topo != nullptr) {
            No* temp = topo;
            int valor = temp->dado;
            topo = topo->proximo;
            delete temp;
            return valor;
        }
        throw runtime_error("Pilha vazia");
    }

    bool vazia() {
        return topo == nullptr;
    }
};

void processar(int modo) {
    // modo 1: vetor, modo 2: Lista
    PilhaVetor* pParV = nullptr;
    PilhaVetor* pImparV = nullptr;
    PilhaLista* pParL = nullptr;
    PilhaLista* pImparL = nullptr;

    if (modo == 1) {
        pParV = new PilhaVetor(5);
        pImparV = new PilhaVetor(5);
        cout << "\n--- Usando Implementacao por VETOR ---" << endl;
    } else {
        pParL = new PilhaLista();
        pImparL = new PilhaLista();
        cout << "\n--- Usando Implementacao por LISTA ENCADEADA ---" << endl;
    }

    int numeros[5];
    int ultimo = -2147483648; // Menor inteiro possível (confirma)

    cout << "Digite 30 numeros inteiros em ordem crescente:" << endl;
    for (int i = 0; i < 5 ; i++) {
        int num;
        do {
            cout << "Numero " << (i + 1) << ": ";
            cin >> num;
            if (num <= ultimo) {
                cout << "Erro: O numero deve ser maior que " << ultimo << ". Tente novamente." << endl;
            }
        } while (num <= ultimo);

        ultimo = num;

        if (num % 2 == 0) {
            if (modo == 1) pParV->empilhar(num);
            else pParL->empilhar(num);
        } else {
            if (modo == 1) pImparV->empilhar(num);
            else pImparL->empilhar(num);
        }
    }

    cout << "\nDesempilhando (Ordem Decrescente):" << endl;
    
    cout << "Pares: ";
    if (modo == 1) {
        while (!pParV->vazia()) cout << pParV->desempilhar() << " ";
    } else {
        while (!pParL->vazia()) cout << pParL->desempilhar() << " ";
    }
    
    cout << "\nImpares: ";
    if (modo == 1) {
        while (!pImparV->vazia()) cout << pImparV->desempilhar() << " ";
    } else {
        while (!pImparL->vazia()) cout << pImparL->desempilhar() << " ";
    }
    cout << endl;

    if (modo == 1) {
        delete pParV;
        delete pImparV;
    } else {
        delete pParL;
        delete pImparL;
    }
}

int main() {
    int opcao;
    cout << "Escolha a implementacao da Pilha:\n1 - Vetor\n2 - Lista Encadeada\nOpcao: ";
    cin >> opcao;

    if (opcao == 1 || opcao == 2) {
        processar(opcao);
    } else {
        cout << "Opcao invalida." << endl;
    }

    cout << "\nPressione qualquer tecla para sair...";
    cin.ignore();
    cin.get();

    return 0;
}
