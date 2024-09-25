#include <iostream>
#include <vector>
#include <cstdlib> // Para std::stoi

using namespace std;

//NAO MEXER NO NOME DO METODO
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    // mplementar logica aqui
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Erro: número insuficiente de argumentos." << endl;
        cerr << "Uso: " << argv[0] << " startTimes endTimes profits" << endl;
        return 1;
    }

    int totalArgs = argc - 1; // desconsidera o primeiro arg que é o nome do programa
    int numElementsPerVector = totalArgs / 3; // número de elementos por vetor, como cada vetor tem tamanho Igual, e são 3 vetores
    

    if (totalArgs % 3 != 0) { // verifica se o total de argumentos é múltiplo de 3 para poder preencher cada vetor
        cerr << "Erro: número inválido de argumentos." << endl;
        cerr << "Uso: " << argv[0] << " startTimes endTimes profits" << endl;
        return 1;
    }
    
    if (numElementsPerVector < 1 || numElementsPerVector > 50000) {
        cerr << "Erro: número de elementos por vetor deve estar entre 1 e 5 * 10^4." << endl;
        return 1;
    }

    vector<int> startTime(numElementsPerVector); //vetor que vai ter os tempos iniciais 
    vector<int> endTime(numElementsPerVector); //vetor que vai ter os tempos finais
    vector<int> profit(numElementsPerVector); //vetor com cada valor de profit

    // preenche startTime
    for (int i = 0; i < numElementsPerVector; ++i) {
        startTime[i] = stoi(argv[i + 1]);
    }

    // preenche endTime
    for (int i = 0; i < numElementsPerVector; ++i) {
        endTime[i] = stoi(argv[numElementsPerVector + i + 1]);
    }

    // preenche profit
    for (int i = 0; i < numElementsPerVector; ++i) {
        profit[i] = stoi(argv[2 * numElementsPerVector + i + 1]);
    }

    // Imprimir vetores(ignorar, foi para testar se a entrada deu certo ou nao)
    cout << "startTime: ";
    for (const int& time : startTime) {
        cout << time << " ";
    }
    cout << endl;

    cout << "endTime: ";
    for (const int& time : endTime) {
        cout << time << " ";
    }
    cout << endl;

    cout << "profit: ";
    for (const int& p : profit) {
        cout << p << " ";
    }
    cout << endl;

    int maxProfit = jobScheduling(startTime, endTime, profit);
    
    //impressão do resultado do maxprofit no final do programa
    cout << maxProfit << endl;

    return 0;
}