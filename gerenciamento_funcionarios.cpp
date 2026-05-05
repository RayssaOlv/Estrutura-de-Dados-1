#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Funcionario {
    int prontuario;
    string nome;
    double salario;
};

bool prontuarioExiste(const vector<Funcionario>& lista, int prontuario) {
    for (const auto& f : lista) {
        if (f.prontuario == prontuario) {
            return true;
        }
    }
    return false;
}

void incluirFuncionario(vector<Funcionario>& lista) {
    Funcionario novo;
    cout << "\n--- Incluir Funcionario ---" << endl;
    cout << "Prontuario: ";
    cin >> novo.prontuario;

    if (prontuarioExiste(lista, novo.prontuario)) {
        cout << "Erro: Ja existe um funcionario cadastrado com este prontuario!" << endl;
        return;
    }

    cout << "Nome: ";
    cin.ignore();
    getline(cin, novo.nome);
    cout << "Salario: ";
    cin >> novo.salario;

    lista.push_back(novo);
    cout << "Funcionario cadastrado com sucesso!" << endl;
}

void excluirFuncionario(vector<Funcionario>& lista) {
    int prontuario;
    cout << "\n--- Excluir Funcionario ---" << endl;
    cout << "Digite o prontuario do funcionario a ser excluido: ";
    cin >> prontuario;

    for (auto it = lista.begin(); it != lista.end(); ++it) {
        if (it->prontuario == prontuario) {
            lista.erase(it);
            cout << "Funcionario excluido com sucesso!" << endl;
            return;
        }
    }
    cout << "Funcionario nao encontrado." << endl;
}

void pesquisarFuncionario(const vector<Funcionario>& lista) {
    int prontuario;
    cout << "\n--- Pesquisar Funcionario ---" << endl;
    cout << "Digite o prontuario para pesquisa: ";
    cin >> prontuario;

    for (const auto& f : lista) {
        if (f.prontuario == prontuario) {
            cout << "Funcionario Encontrado:" << endl;
            cout << "Nome: " << f.nome << endl;
            cout << "Salario: R$ " << fixed << setprecision(2) << f.salario << endl;
            return;
        }
    }
    cout << "Funcionario nao encontrado." << endl;
}

void listarFuncionarios(const vector<Funcionario>& lista) {
    double totalSalarios = 0;
    cout << "\n--- Lista de Funcionarios ---" << endl;
    
    if (lista.empty()) {
        cout << "Nenhum funcionario cadastrado." << endl;
        return;
    }

    cout << left << setw(12) << "Prontuario" << setw(25) << "Nome" << "Salario" << endl;
    cout << string(50, '-') << endl;

    for (const auto& f : lista) {
        cout << left << setw(12) << f.prontuario 
             << setw(25) << f.nome 
             << "R$ " << fixed << setprecision(2) << f.salario << endl;
        totalSalarios += f.salario;
    }

    cout << string(50, '-') << endl;
    cout << "Total de Salarios: R$ " << fixed << setprecision(2) << totalSalarios << endl;
}

int main() {
    vector<Funcionario> listaFuncionarios;
    int opcao;

    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Pesquisar" << endl;
        cout << "4. Listar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                incluirFuncionario(listaFuncionarios);
                break;
            case 2:
                excluirFuncionario(listaFuncionarios);
                break;
            case 3:
                pesquisarFuncionario(listaFuncionarios);
                break;
            case 4:
                listarFuncionarios(listaFuncionarios);
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}
