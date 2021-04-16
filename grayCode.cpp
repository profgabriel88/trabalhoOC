#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    // cria um objeto da classe Input File Stream - Arquivo de Entrada
    ifstream valoresDeEntrada("lista.txt");
    // variável string para armazenar cada linha do arquivo
    string linha;

    // cria um objeto da classe Output File Stream - Arquivo de Saída
    ofstream valoresDeSaida("listaConvertida.txt");

    // itera todas as linhas do arquivo de entrada
    while (getline(valoresDeEntrada, linha))
    {
        // recebe o valor da string e converte para inteiro
        int valorDecimal = stoi(linha);
        int i = 0; // variável para iterar a conversão decimal -> binário
        
        // vetores para armazenar os bits binários e gray
        unsigned int n = 6;
        unsigned int valorBinario[n] = {0};
        unsigned int valorGray[n] = {0};

        // escreve no arquivo de saída o valor de entrada
        valoresDeSaida << "Valor de entrada: " << valorDecimal << ", ";

        // conversão de decimal para binário por sucessivas divisões por 2
        while (valorDecimal > 0)
        {
            valorBinario[i] = valorDecimal%2;
            valorDecimal = valorDecimal/2;
            i++;    
        }
        
        // converte os binários para código gray
        for (int j = n-1; j >= 0; j--)
        {
            // o MSB é igual para os dois
            if (j == n-1) valorGray[j] = valorBinario[j];
            
            // os outros bits são obtidos pela operação XOR (^) da seguinte forma
            // 1º XOR 2º, 2º XOR 3º, nbit XOR n+1bit
            else valorGray[j] = valorBinario[j+1]^valorBinario[j];
        }

        // escreve no arquivo de saída os valores binários
        valoresDeSaida << "código binário: ";
        for (int i = n-1; i >= 0; i--) 
            valoresDeSaida << valorBinario[i];
        valoresDeSaida << ", ";

        // escreve no arquivo de saída os valores gray
        valoresDeSaida << "código gray: ";
        for (int i = n-1; i >= 0; i--) 
            valoresDeSaida << valorGray[i];
        valoresDeSaida << "\n";
    }
    return 0;
}
