#include <iostream>

using namespace std;

// --- IMPLEMENTAÇÃO DE FILA POR VETOR ---
class FilaVetor {
private:
    int* elementos;
    int capacidade;
    int frente;
    int tras;
    int tamanho;

public:
    FilaVetor(int cap = 100) {
        capacidade = cap;
        elementos = new int[capacidade];
        frente = 0;
        tras = -1;
        tamanho = 0;
    }

    ~FilaVetor() {
        delete[] elementos;
    }

    void enfileirar(int valor) {
        if (tamanho < capacidade) {
            tras = (tras + 1) % capacidade;
            elementos[tras] = valor;
            tamanho++;
        }
    }

    int desenfileirar() {
        if (tamanho > 0) {
            int valor = elementos[frente];
            frente = (frente + 1) % capacidade;
            tamanho--;
            return valor;
        }
        return -1;
    }

    int getTamanho() { return tamanho; }
    bool vazia() { return tamanho == 0; }
};

// --- IMPLEMENTAÇÃO DE FILA POR PONTEIRO (LISTA ENCADEADA) ---
struct No {
    int dado;
    No* proximo;
};

class FilaPonteiro {
private:
    No* frente;
    No* tras;
    int tamanho;

public:
    FilaPonteiro() {
        frente = nullptr;
        tras = nullptr;
        tamanho = 0;
    }

    ~FilaPonteiro() {
        while (!vazia()) {
            desenfileirar();
        }
    }

    void enfileirar(int valor) {
        No* novo = new No();
        novo->dado = valor;
        novo->proximo = nullptr;
        if (vazia()) {
            frente = tras = novo;
        } else {
            tras->proximo = novo;
            tras = novo;
        }
        tamanho++;
    }

    int desenfileirar() {
        if (!vazia()) {
            No* temp = frente;
            int valor = temp->dado;
            frente = frente->proximo;
            if (frente == nullptr) tras = nullptr;
            delete temp;
            tamanho--;
            return valor;
        }
        return -1;
    }

    int getTamanho() { return tamanho; }
    bool vazia() { return frente == nullptr; }
};

void rodarSistema(int tipo) {
    FilaVetor* fGeradasV = nullptr;
    FilaVetor* fAtendidasV = nullptr;
    FilaPonteiro* fGeradasP = nullptr;
    FilaPonteiro* fAtendidasP = nullptr;

    if (tipo == 1) {
        fGeradasV = new FilaVetor();
        fAtendidasV = new FilaVetor();
    } else {
        fGeradasP = new FilaPonteiro();
        fAtendidasP = new FilaPonteiro();
    }

    int proximaSenha = 1;
    int opcao;
    int totalAtendidas = 0;

    do {
        int aguardando = (tipo == 1) ? fGeradasV->getTamanho() : fGeradasP->getTamanho();
        
        cout << "\n========================================" << endl;
        cout << "SISTEMA DE ATENDIMENTO (" << (tipo == 1 ? "VETOR" : "PONTEIRO") << ")" << endl;
        cout << "Senhas aguardando atendimento: " << aguardando << endl;
        cout << "----------------------------------------" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Gerar senha" << endl;
        cout << "2. Realizar atendimento" << endl;
        cout << "Opcao: ";
        
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (tipo == 1) fGeradasV->enfileirar(proximaSenha);
                else fGeradasP->enfileirar(proximaSenha);
                cout << "Senha " << proximaSenha << " gerada com sucesso!" << endl;
                proximaSenha++;
                break;

            case 2: {
                int senhaAtendida;
                if (tipo == 1) senhaAtendida = fGeradasV->desenfileirar();
                else senhaAtendida = fGeradasP->desenfileirar();

                if (senhaAtendida != -1) {
                    cout << "Atendendo senha: " << senhaAtendida << endl;
                    if (tipo == 1) fAtendidasV->enfileirar(senhaAtendida);
                    else fAtendidasP->enfileirar(senhaAtendida);
                    totalAtendidas++;
                } else {
                    cout << "Nao ha senhas na fila para atendimento!" << endl;
                }
                break;
            }

            case 0:
                if (aguardando > 0) {
                    cout << "Nao e possivel sair! Ainda existem " << aguardando << " senhas aguardando." << endl;
                    opcao = -1; 
                } else {
                    cout << "\nEncerrando sistema..." << endl;
                    cout << "Total de senhas atendidas: " << totalAtendidas << endl;
                }
                break;

            default:
                cout << "Opcao invalida!" << endl;
                break;
        }

    } while (opcao != 0);

    if (tipo == 1) {
        delete fGeradasV;
        delete fAtendidasV;
    } else {
        delete fGeradasP;
        delete fAtendidasP;
    }
}

int main() {
    int escolha;
    cout << "Escolha a implementacao da Fila:\n1 - Vetor\n2 - Ponteiro\nOpcao: ";
    cin >> escolha;

    if (escolha == 1 || escolha == 2) {
        rodarSistema(escolha);
    } else {
        cout << "Opcao invalida. Reinicie o programa." << endl;
    }

    cout << "\nFim do programa." << endl;

    return 0;
}
