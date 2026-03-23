#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_FILEIRAS = 15;
const int NUM_POLTRONAS = 40;


const double PRECO_FILEIRA_1_5 = 50.00;
const double PRECO_FILEIRA_6_10 = 30.00;
const double PRECO_FILEIRA_11_15 = 15.00;

//(true = ocupado, false = vago)
bool teatro[NUM_FILEIRAS][NUM_POLTRONAS];


void inicializarTeatro();
void exibirMenu();
bool validarEntrada(int fileira, int poltrona);
void reservarPoltrona();
void exibirMapaOcupacao();
double obterPrecoPoltrona(int fileira);
void calcularFaturamento();

int main() {
    inicializarTeatro();
    int opcao;

    do {
        exibirMenu();
        cout << "Escolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            reservarPoltrona();
        } else if (opcao == 2) {
            exibirMapaOcupacao();
        } else if (opcao == 3) {
            calcularFaturamento();
        } else if (opcao == 0) {
            cout << "Finalizando o programa." << endl;
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
        cout << endl;
    } while (opcao != 0);

    return 0;
}

void inicializarTeatro() {
    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < NUM_POLTRONAS; ++j) {
            teatro[i][j] = false; 
        }
    }
}

void exibirMenu() {
    cout << "--- Sistema de Bilheteria ---" << endl;
    cout << "0. Finalizar" << endl;
    cout << "1. Reservar poltrona" << endl;
    cout << "2. Mapa de ocupação" << endl;
    cout << "3. Faturamento" <<endl;
}

bool validarEntrada(int fileira, int poltrona) {
    if (fileira >= 1 && fileira <= NUM_FILEIRAS &&
        poltrona >= 1 && poltrona <= NUM_POLTRONAS) {
        return true;
    } else {
        cout << "Entrada inválida. Fileira deve ser entre 1 e " << NUM_FILEIRAS
                  << ", e Poltrona entre 1 e " << NUM_POLTRONAS << "." << endl;
        return false;
    }
}

void reservarPoltrona() {
    int fileira, poltrona;
    cout << "Informe a fileira (1-" << NUM_FILEIRAS << "): ";
    cin >> fileira;
    cout << "Informe a poltrona (1-" << NUM_POLTRONAS << "): ";
    cin >> poltrona;

    if (validarEntrada(fileira, poltrona)) {
        int op_fileira = fileira - 1;
        int op_poltrona = poltrona - 1;

        if (teatro[op_fileira][op_poltrona] == false) {
            teatro[op_fileira][op_poltrona] = true; 
            cout << "Poltrona F" << fileira << " P" << poltrona << " reservada com sucesso!" << endl;
        } else {
            cout << "A poltrona F" << fileira << " P" << poltrona << " já está ocupada." << endl;
        }
    }
}

void exibirMapaOcupacao() {
    cout <<endl << "--- Mapa de Ocupação do Teatro ---" << endl;
    cout << "Legenda: . = Vago, # = Ocupado" << endl << endl;

    // Arrumas poltronas dps
    cout << "   ";
    for (int p = 1; p <= NUM_POLTRONAS; ++p) {
        cout << setw(2) << p << " ";
    }
    cout <<endl;

    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        cout << setw(2) << (i + 1) << " "; 
        for (int j = 0; j < NUM_POLTRONAS; ++j) {
            cout << (teatro[i][j] ? " # " : " . ");
        }
        cout << endl;
    }
}

double obterPrecoPoltrona(int fileira) {
    if (fileira >= 1 && fileira <= 5) {
        return PRECO_FILEIRA_1_5;
    } else if (fileira >= 6 && fileira <= 10) {
        return PRECO_FILEIRA_6_10;
    } else if (fileira >= 11 && fileira <= 15) {
        return PRECO_FILEIRA_11_15;
    }
    return 0.0; // Se esse inferno der erro dnv
}

void calcularFaturamento() {
    int lugares_ocupados = 0;
    double faturamento_total = 0.0;

    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < NUM_POLTRONAS; ++j) {
            if (teatro[i][j] == true) {
                lugares_ocupados++;
                faturamento_total += obterPrecoPoltrona(i + 1);
            }
        }
    }

    cout << endl << "--- Relatório de Faturamento ---" << endl;
    cout << "Qtde de lugares ocupados: " << lugares_ocupados << endl;
    cout << fixed << setprecision(2);
    cout << "Valor da bilheteria: R$ " << faturamento_total << endl;
}
