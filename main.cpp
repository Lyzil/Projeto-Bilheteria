#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

#define LIN 15
#define COL 40

void mostra_matriz(char **x) {
    for (int i = 0; i < LIN; ++i) {
        for (int j = 0; j < COL; ++j) {
            cout << x[i][j] << " "; // exibir com um espaço entre as poltronas
        }
        cout << endl << endl;
    }
    cout <<". = Livre | % = reservado"<< endl << endl;
}

void reservar_assento(char **mat) {
    int fila, coluna;
    cout << "Digite a fileira (0 a " << LIN - 1 << "): ";
    cin >> fila;
    cout << "Digite a coluna (0 a " << COL - 1 << "): ";
    cin >> coluna;

    if (fila < 0 || fila >= LIN || coluna < 0 || coluna >= COL) {
        cout << "Posição inválida! Tente novamente." << endl;
        return;
    }

    if (mat[fila][coluna] == '#') {
        cout << "Assento já ocupado! Escolha outro." << endl;
    } else {
        mat[fila][coluna] = '#';
        cout << "Assento reservado com sucesso!" << endl;
    }
}

void pre_reservar_assentos(char **mat) {
    srand(time(0));

    int rf, rc;
    for (int i = 0; i < 200; ++i) {
        do {
            rf = rand() % LIN; 
            rc = rand() % COL; 
        } while (mat[rf][rc] == '#'); // impedir problema de ocupar assento ocupado

        mat[rf][rc] = '#';
    }
}

void Faturamento(char **mat) 
{
    int qtd = 0;
    double valor_total = 0.0;

    
    for (int i = 0; i < LIN; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (mat[i][j] == '#') {
                qtd++;
                
                if (i < 5) 
                { 
                    valor_total += 50.00; //  1-5
                } else if (i < 10) 
                { 
                    valor_total += 30.00; //  6-10
                } else 
                { 
                    valor_total += 15.00; //  11-15
                }
            }
        }
    }
    cout << "Qtde de lugares ocupados:" << setw(5) << qtd << endl;
    cout << "Valor da bilheteria:" << setw(5) << "R$" << valor_total << endl;
}

int main(int argc, char** argv) {
    
    int opcao;
    char **mat;

    // Alocação da matriz
    mat = (char**)malloc(LIN * sizeof(char*));
    for (int i = 0; i < LIN; ++i) 
    {
        mat[i] = (char*)malloc(COL * sizeof(char));
    }

    // preenchendo as poltronas como livre (".")
    for (int i = 0; i < LIN; ++i) 
    {
        for (int j = 0; j < COL; ++j) 
        {
            mat[i][j] = '.'; // lembrar de usar '' no futuro
        }
    }
   
   pre_reservar_assentos(mat); 
    
do{
    cout << "Menu de opções" << endl
                   << "0.	Finalizar" << endl
                   << "1.	Reservar poltrona" << endl
                   << "2.	Mapa de ocupação" << endl
                   << "3.	Faturamento" << endl <<"escolhe a opção que deseja: ";
	cin >> opcao;

switch (opcao) {
    case 0:
        break;
    case 1:
        reservar_assento(mat);
        break;
        
    case 2:
        mostra_matriz(mat);
        break;
    case 3:
        Faturamento(mat);
        break;
    default:
        cout<<"Ocorreu um erro, verifique se digitou corretamente"<< endl;
        break;
        
        }
    }while(opcao !=0);
    
    for (int i = 0; i < LIN; ++i) 
        {
        free(mat[i]);
        }
        free(mat);
        return 0;
}
