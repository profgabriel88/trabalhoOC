#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

    ifstream valoresDeEntrada("lista.txt");
    string linha;

    ofstream valoresDeSaida("listaConvertida.txt");

    while (getline(valoresDeEntrada, linha))
    {
        int abacaxi = stoi(linha), i = 0;
        unsigned int n = 6;
        unsigned int abacaBin[n] = {0};
        unsigned int abacaGray[n] = {0};

        valoresDeSaida << "Valor de entrada: " << abacaxi << ", ";
        //cout << "\n";

        while (abacaxi > 0)
        {
            abacaBin[i] = abacaxi%2;
            abacaxi = abacaxi/2;
            i++;    
        }
        
        
        for (int j = n-1; j >= 0; j--)
        {
            if (j == n-1) abacaGray[j] == abacaBin[j];

            else
            {
                abacaGray[j] = abacaBin[j+1]^abacaBin[j];
            }
            //cout << abacaGray[j];
            
        }

        valoresDeSaida << "código binário: ";
        for (int i = n-1; i >= 0; i--) 
            valoresDeSaida << abacaBin[i];
        valoresDeSaida << ", ";

        valoresDeSaida << "código gray: ";
        for (int i = n-1; i >= 0; i--) 
            valoresDeSaida << abacaGray[i];
        valoresDeSaida << "\n";
    }
    return 0;
}