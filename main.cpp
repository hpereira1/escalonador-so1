#include <iostream>
#include <vector>
#include <cstdlib> 
#include <algorithm>
#include <map>

using namespace std;
struct Job{
    int startTime;
    int endTime;
    int profit;
} ;

//NAO MEXER NO NOME DO METODO
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<Job> jobs;
    int jobs_n = startTime.size();

    // ----------------------- Testes de input -----------------------
    if (jobs_n < 1 || jobs_n > 5e4 ){
        cout << "Erro: O número de jobs deve ser entre 1 e 50000" << endl;
        return 0;
    }

    if (jobs_n != endTime.size() || endTime.size() != profit.size()){
        cout << "Erro: Todos os três vetores devem conter o mesmo tamanho" << endl;
        return 0;
    }
       
    for (int i = 0; i < jobs_n; i++) {
        Job j = {startTime[i], endTime[i], profit[i]};
        if (j.startTime >= j.endTime) {
            cout << "Error: startTime of job " << i << " must be less than endTime" << endl;
            return 0;
        }  // test if startTime is less than endTime
        if (j.startTime < 1 || j.startTime > 1e9 || j.endTime < 1 || j.endTime > 1e9 ){
            cout << "Error: startTime, endTime of job " << i << " must be between 1 and 1e9" << endl;
            return 0;
        }   // test if startTime and endTime are between 1 and 1e9
        if (j.profit < 1 || j.profit > 1e4){
            cout << "Error: profit of job " << i << " must be between 1 and 1e4" << endl;
            return 0;
        }   // test if profit is between 1 and 1e4
        jobs.push_back(j);
        //cout << "Job " << i << " created\n" << endl;
    }   // create jobs and push them into jobs vector 
    //print jobs
    cout << "Jobs created: " << endl;
    for (int i = 0; i < jobs_n; i++) {
        cout << "Job " << i << " startTime: " << jobs[i].startTime << " endTime: " << jobs[i].endTime << " profit: " << jobs[i].profit << endl;
    }
    cout << "-----------------------" << endl;
    
    //----------------------- ordenar jobs pelo endTime -----------------------
    
    sort(jobs.begin(), jobs.end(), [](Job i, Job j) {
        return i.endTime < j.endTime;
    });
    


    cout << "-----------------------" << endl;
    //print sorted jobs
    cout << "Sorted jobs" << endl;
    for (int i = 0; i < jobs_n; i++) {
        cout << "Job " << i << " startTime: " << jobs[i].startTime << " endTime: " << jobs[i].endTime << " profit: " << jobs[i].profit << endl;
    }
    cout << "-----------------------" << endl<<endl;
    

    // ----------------------- implementação do algoritmo -----------------------

    map<int, int> max_profit;
    
    max_profit[0] = 0;
    for (const Job& job : jobs) {
        printf("Job startTime: %d\n", job.startTime);
        auto ia = max_profit.upper_bound(job.startTime); // max_profit.upper_bound(job.startTime) procura o menor elemento em max_profit cuja chave (endTime) seja estritamente maior que job.startTime.

        /*Ao fazer auto ia = max_profit.upper_bound(job.startTime), ia aponta para o primeiro horário de término que ocorre após o início de job. Isso significa que esse trabalho tem um endTime maior que job.startTime e, portanto, não pode ser incluído junto com job sem conflito.

        Quando decrementamos o iterador (--ia), movemos para o último horário de término em max_profit que ocorre antes do início de job (job.startTime). Esse trabalho não se sobrepõe a job, então o lucro armazenado em ia->second representa o maior lucro acumulado possível até aquele horário de término.

        Esse valor é usado para calcular o lucro total que podemos obter ao escolher incluir job no conjunto de trabalhos realizados.*/

        printf("ia->first = jobend: %d\n", ia->first);
        printf("ia->second = jobprofit: %d\n", ia->second);

        --ia;

        printf("ia->first = jobend: %d and ia->second = jobprofit: %d\n",ia->first, ia->second); 

        int cur_profit = ia->second + job.profit;

        printf("cur_profit: %d\n", cur_profit);
        printf("max_profit.rbegin()->first: %d\n", max_profit.rbegin()->first);
        printf("max_profit.rbegin()->second: %d\n", max_profit.rbegin()->second);

        max_profit[job.endTime] = max(cur_profit, max_profit.rbegin()->second);
        
        printf("endTime: %d\n", job.endTime);
        printf("max_profit[job.endTime]: %d\n", max_profit[job.endTime]);

                // Imprimir o estado do map após cada iteração
        cout << "Após o processamento do job com endTime " << job.endTime << " e lucro " << job.profit << ":\n";
        // create a print loop that show the job path to max_profit

        for (const auto& [time, profit] : max_profit) {
            cout << "Tempo de término: " << time << ", Lucro máximo: " << profit << endl;
        }
        cout << "-----------------------" << endl;
    }
    return max_profit.rbegin()->second;
}

    
int main(){
    vector<int> startTime = {1,2,3,4,6,4};
    vector<int> endTime = {3,5,10,6,9,6};
    vector<int> profit = {20,21,100,70,60,72};
    vector<int> size_er = {3, 4, 10, 6};    //test size
    vector<int> zero_er;

    int expected = 150;
    int result = jobScheduling(startTime, endTime, profit);
    /*    
    cout << "result: " << result << endl;
    cout << endl;

    int size_er_result = jobScheduling(startTime, endTime, size_er);
    cout << "size_er_result: " << size_er_result << endl;
    cout << endl;

    int zero_er_result = jobScheduling(startTime, endTime, zero_er);
    */
    cout << "Lucro máximo fim: " << result << endl;

    return 0;
}