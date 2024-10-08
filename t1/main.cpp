#include <iostream>
#include <vector>
#include <cstdlib> 
#include <algorithm>
#include <map>

using namespace std;


//NAO MEXER NO NOME DO METODO
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    struct Job{
        int startTime;
        int endTime;
        int profit;
    } ;  // struct de Job 
    
    vector<Job> jobs;  // vetor de jobs
    int jobs_n = startTime.size();  // número de jobs

    // ----------------------- Testes de input -----------------------
    if (jobs_n < 1 || jobs_n > 5e4 ){
        cout << "Erro: O número de jobs deve ser entre 1 e 50000" << endl;
        return 0;
    } // testa se o número de jobs está entre 1 e 50000

    if (jobs_n != endTime.size() || endTime.size() != profit.size()){
        cout << "Erro: Todos os três vetores devem conter o mesmo tamanho" << endl;
        return 0;
    }  // testa se os vetores tem o mesmo tamanho
       
    for (int i = 0; i < jobs_n; i++) {
        Job j = {startTime[i], endTime[i], profit[i]};
        if (j.startTime >= j.endTime) {
            cout << "Error: startTime do job " << i << " deve ser menor que endTime" << endl;
            return 0;
        }  // testa se startTime é menor que endTime

        if (j.startTime < 1 || j.startTime > 1e9 || j.endTime < 1 || j.endTime > 1e9 ){
            cout << "Error: startTime, endTime do job " << i << " deve estar entre 1 e 1e9" << endl;
            return 0;
        }   // testa se startTime e endTime estão entre 1 e 1e9

        if (j.profit < 1 || j.profit > 1e4){
            cout << "Error: profit do job " << i << " deve estar entre 1 and 1e4" << endl;
            return 0;
        }   // testa se profit está entre 1 e 1e4

        jobs.push_back(j); // adiciona o job ao vetor de jobs
    }

    //----------------------- ordenar jobs pelo endTime -----------------------

    sort(jobs.begin(), jobs.end(), [](Job i, Job j) {
        return i.endTime < j.endTime; // ordena os jobs pelo endTime
    });
    
    // ----------------------- implementação do algoritmo -----------------------

    map<int, int> max_profit;   // map que armazena o lucro máximo acumulado, onde a chave é o endTime e o valor é o lucro acumulado até aquele momento
    
    max_profit[0] = 0;   // inicializa o lucro acumulado em 0, para o endTime 0
    
    for (const Job& job : jobs){
        auto aux = max_profit.upper_bound(job.startTime); // procura o menor elemento em max_profit que a chave endTime seja imeadiatamente maior que job.startTime
        --aux;  // decrementa o iterador para apontar para o último endTime que ocorre antes do início de job.startTime 

        int cur_profit = aux->second + job.profit;   // calcula o lucro atual, que é o lucro acumulado até o horário de término do job anterior + o lucro do job atual

        max_profit[job.endTime] = max(cur_profit, max_profit.rbegin()->second);  // guarda em max_profit o max entre o lucro atual e o lucro acumulado até o horário de término do job anterior 

    }
    return max_profit.rbegin()->second; //rbegin() retorna um iterador para o último elemento do map, o ->second retorna o valor(lucro) associado a chave(endTime)
    
}
    
int main(){
    // Exemplo 2 do enunciado
    vector<int> startTime = {1,2,3,4,6}; 
    vector<int> endTime = {3,5,10,6,9};
    vector<int> profit = {20,21,100,70,60};

    int result = jobScheduling(startTime, endTime, profit); 
    
    cout << result << endl;

    return 0;
}