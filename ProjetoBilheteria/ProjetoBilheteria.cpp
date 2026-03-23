#include <iostream>
#include <vector>
#include <iomanip>


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
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        if (opcao == 1) {
            reservarPoltrona();
        } else if (opcao == 2) {
            exibirMapaOcupacao();
        } else if (opcao == 3) {
            calcularFaturamento();
        } else if (opcao == 0) {
            std::cout << "Finalizando o programa. Até mais!" << std::endl;
        } else {
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
        std::cout << std::endl;
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
    std::cout << "--- Sistema de Bilheteria ---" << std::endl;
    std::cout << "0. Finalizar" << std::endl;
    std::cout << "1. Reservar poltrona" << std::endl;
    std::cout << "2. Mapa de ocupação" << std::endl;
    std::cout << "3. Faturamento" << std::endl;
}

bool validarEntrada(int fileira, int poltrona) {
    if (fileira >= 1 && fileira <= NUM_FILEIRAS &&
        poltrona >= 1 && poltrona <= NUM_POLTRONAS) {
        return true;
    } else {
        std::cout << "Entrada inválida. Fileira deve ser entre 1 e " << NUM_FILEIRAS
                  << ", e Poltrona entre 1 e " << NUM_POLTRONAS << "." << std::endl;
        return false;
    }
}

void reservarPoltrona() {
    int fileira, poltrona;
    std::cout << "Informe a fileira (1-" << NUM_FILEIRAS << "): ";
    std::cin >> fileira;
    std::cout << "Informe a poltrona (1-" << NUM_POLTRONAS << "): ";
    std::cin >> poltrona;

    if (validarEntrada(fileira, poltrona)) {
        int op_fileira = fileira - 1;
        int op_poltrona = poltrona - 1;

        if (teatro[op_fileira][op_poltrona] == false) {
            teatro[op_fileira][op_poltrona] = true; 
            std::cout << "Poltrona F" << fileira << " P" << poltrona << " reservada com sucesso!" << std::endl;
        } else {
            std::cout << "A poltrona F" << fileira << " P" << poltrona << " já está ocupada." << std::endl;
        }
    }
}

void exibirMapaOcupacao() {
    std::cout << std::endl << "--- Mapa de Ocupação do Teatro ---" << std::endl;
    std::cout << "Legenda: . = Vago, # = Ocupado" << std::endl << std::endl;

    // Arrumas poltronas dps
    std::cout << "   ";
    for (int p = 1; p <= NUM_POLTRONAS; ++p) {
        std::cout << std::setw(2) << p << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        std::cout << std::setw(2) << (i + 1) << " "; 
        for (int j = 0; j < NUM_POLTRONAS; ++j) {
            std::cout << (teatro[i][j] ? " # " : " . ");
        }
        std::cout << std::endl;
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

    std::cout << std::endl << "--- Relatório de Faturamento ---" << std::endl;
    std::cout << "Qtde de lugares ocupados: " << lugares_ocupados << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Valor da bilheteria: R$ " << faturamento_total << std::endl;
}