#include <iostream>

using namespace std;

// --- ESTRUTURA DE FILA (PONTEIROS) ---
struct NoFila {
    int senha;
    NoFila* proximo;
};

class Fila {
private:
    NoFila* frente;
    NoFila* tras;
    int tamanho;

public:
    Fila() : frente(nullptr), tras(nullptr), tamanho(0) {}

    ~Fila() {
        while (!vazia()) {
            desenfileirar();
        }
    }

    void enfileirar(int s) {
        NoFila* novo = new NoFila();
        novo->senha = s;
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
        if (vazia()) return -1;
        NoFila* temp = frente;
        int s = temp->senha;
        frente = frente->proximo;
        if (frente == nullptr) tras = nullptr;
        delete temp;
        tamanho--;
        return s;
    }

    bool vazia() const { return frente == nullptr; }
    int getTamanho() const { return tamanho; }

    void listar() const {
        if (vazia()) {
            cout << "Nenhuma senha atendida." << endl;
            return;
        }
        NoFila* atual = frente;
        while (atual != nullptr) {
            cout << "[" << atual->senha << "] ";
            atual = atual->proximo;
        }
        cout << endl;
    }
};

// --- ESTRUTURA DO GUICHÊ ---
struct Guiche {
    int id;
    Fila senhasAtendidas;
    Guiche* proximo;
};

// --- ESTRUTURA DE LISTA DE GUICHÊS ---
class ListaGuiches {
private:
    Guiche* cabeca;
    int quantidade;

public:
    ListaGuiches() : cabeca(nullptr), quantidade(0) {}

    ~ListaGuiches() {
        while (cabeca != nullptr) {
            Guiche* temp = cabeca;
            cabeca = cabeca->proximo;
            delete temp;
        }
    }

    void adicionarGuiche(int id) {
        Guiche* novo = new Guiche();
        novo->id = id;
        novo->proximo = cabeca;
        cabeca = novo;
        quantidade++;
    }

    Guiche* buscarGuiche(int id) {
        Guiche* atual = cabeca;
        while (atual != nullptr) {
            if (atual->id == id) return atual;
            atual = atual->proximo;
        }
        return nullptr;
    }

    int getQuantidade() const { return quantidade; }
};

int main() {
    Fila senhasGeradas;
    ListaGuiches guiches;
    int proximaSenha = 1;
    int totalGeralAtendidas = 0;
    int opcao;

    do {
        cout << "\n========================================" << endl;
        cout << "SISTEMA DE ATENDIMENTO 2.0" << endl;
        cout << "Senhas aguardando: " << senhasGeradas.getTamanho() << endl;
        cout << "Guiches abertos: " << guiches.getQuantidade() << endl;
        cout << "----------------------------------------" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Gerar senha" << endl;
        cout << "2. Abrir guiche" << endl;
        cout << "3. Realizar atendimento" << endl;
        cout << "4. Listar senhas atendidas por guiche" << endl;
        cout << "Opcao: ";
        
        cin >> opcao;

        switch (opcao) {
            case 1:
                senhasGeradas.enfileirar(proximaSenha);
                cout << "Senha " << proximaSenha << " gerada!" << endl;
                proximaSenha++;
                break;

            case 2: {
                int id;
                cout << "Digite o ID do novo guiche: ";
                cin >> id;
                if (guiches.buscarGuiche(id)) {
                    cout << "Erro: Guiche com ID " << id << " ja existe!" << endl;
                } else {
                    guiches.adicionarGuiche(id);
                    cout << "Guiche " << id << " aberto com sucesso!" << endl;
                }
                break;
            }

            case 3: {
                if (senhasGeradas.vazia()) {
                    cout << "Nao ha senhas para atender!" << endl;
                    break;
                }
                int id;
                cout << "Digite o ID do guiche que vai atender: ";
                cin >> id;
                Guiche* g = guiches.buscarGuiche(id);
                if (g) {
                    int s = senhasGeradas.desenfileirar();
                    g->senhasAtendidas.enfileirar(s);
                    totalGeralAtendidas++;
                    cout << "Guiche " << id << " atendendo senha: " << s << endl;
                } else {
                    cout << "Erro: Guiche " << id << " nao encontrado!" << endl;
                }
                break;
            }

            case 4: {
                int id;
                cout << "Digite o ID do guiche para listar atendimentos: ";
                cin >> id;
                Guiche* g = guiches.buscarGuiche(id);
                if (g) {
                    cout << "Senhas atendidas pelo guiche " << id << ":" << endl;
                    g->senhasAtendidas.listar();
                } else {
                    cout << "Erro: Guiche " << id << " nao encontrado!" << endl;
                }
                break;
            }

            case 0:
                if (!senhasGeradas.vazia()) {
                    cout << "Nao e possivel sair! Ainda restam " << senhasGeradas.getTamanho() << " senhas." << endl;
                    opcao = -1;
                } else {
                    cout << "\nEncerrando sistema..." << endl;
                    cout << "Total de senhas atendidas no dia: " << totalGeralAtendidas << endl;
                }
                break;

            default:
                cout << "Opcao invalida!" << endl;
                break;
        }

    } while (opcao != 0);

    return 0;
}