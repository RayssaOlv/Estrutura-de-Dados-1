#include <iostream>
#include <string>
#include <ctime>

using namespace std;


class Data {
private:
    int dia;
    int mes;
    int ano;

public:

    Data() : dia(1), mes(1), ano(2000) {}


    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}

    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAno() const { return ano; }


    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }
};


class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:

    Contato() : email(""), nome(""), telefone(""), dtnasc(Data()) {}

    Contato(string e, string n, string t, Data d) : email(e), nome(n), telefone(t), dtnasc(d) {}

    string getEmail() const { return email; }
    string getNome() const { return nome; }
    string getTelefone() const { return telefone; }
    Data getDtnasc() const { return dtnasc; }

    void setEmail(string e) { email = e; }
    void setNome(string n) { nome = n; }
    void setTelefone(string t) { telefone = t; }
    void setDtnasc(Data d) { dtnasc = d; }

    int idade() {
        time_t t = time(0);
        struct tm * now = localtime(&t);
        int anoAtual = now->tm_year + 1900;
        int mesAtual = now->tm_mon + 1;
        int diaAtual = now->tm_mday;

        int idadeCalculada = anoAtual - dtnasc.getAno();

        if (mesAtual < dtnasc.getMes() || (mesAtual == dtnasc.getMes() && diaAtual < dtnasc.getDia())) {
            idadeCalculada--;
        }

        return idadeCalculada;
    }
};

int main() {
    const int TOTAL_CONTATOS = 5;
    Contato listaContatos[TOTAL_CONTATOS];

    cout << "--- CADASTRO DE " << TOTAL_CONTATOS << " CONTATOS ---" << endl;

    for (int i = 0; i < TOTAL_CONTATOS; i++) {
        string nome, email, telefone;
        int d, m, a;

        cout << "\nContato " << i + 1 << ":" << endl;
        cout << "Nome: ";
        getline(cin >> ws, nome); // ws pra limpar espaço em branco
        
        cout << "E-mail: ";
        getline(cin, email);
        
        cout << "Telefone: ";
        getline(cin, telefone);
        
        cout << "Data de Nascimento (dia mes ano): ";
        cin >> d >> m >> a;

        Data dataNasc(d, m, a);
        listaContatos[i] = Contato(email, nome, telefone, dataNasc);
    }

    cout << "\n\n--- EXIBICAO DOS CONTATOS CADASTRADOS ---" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < TOTAL_CONTATOS; i++) {
        cout << "Nome:     " << listaContatos[i].getNome() << endl;
        cout << "E-mail:   " << listaContatos[i].getEmail() << endl;
        cout << "Telefone: " << listaContatos[i].getTelefone() << endl;
        cout << "Idade:    " << listaContatos[i].idade() << " anos" << endl;
        cout << "------------------------------------------------------------" << endl;
    }

    cout << "\nPressione Enter para sair...";
    cin.ignore();
    cin.get();

    return 0;
}
