#include <iostream>
#include <vector>
#include <cstdlib> 
#include <algorithm>

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
    


    if (jobs_n < 1 || jobs_n > 5e4 ){
        cout << "Error: the number of jobs must be between 1 and 5e4" << endl;
        return 0;
    }   // test if the n of jobs is between 1 and 50k

    if (jobs_n != endTime.size() || endTime.size() != profit.size()){
        cout << "Error: Vectors must have the same size" << endl;
        return 0;
    }   // test if the vectors have the same size
       
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
        cout << "Job " << i << " created\n" << endl;
    }   // create jobs and push them into jobs vector 
    //print jobs
    cout << "Jobs created: " << endl;
    for (int i = 0; i < jobs_n; i++) {
        cout << "Job " << i << " startTime: " << jobs[i].startTime << " endTime: " << jobs[i].endTime << " profit: " << jobs[i].profit << endl;
    }
    //sort jobs by endTime
    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.endTime < b.endTime;
    });
    //print sorted jobs
    cout << "Sorted jobs" << endl;
    for (int i = 0; i < jobs_n; i++) {
        cout << "Job " << i << " startTime: " << jobs[i].startTime << " endTime: " << jobs[i].endTime << " profit: " << jobs[i].profit << endl;
    }

    return 0;
}
    
int main(){
    vector<int> startTime = {1,2,3,4,6};
    vector<int> endTime = {3,5,10,6,9};
    vector<int> profit = {20,20,100,70,60};
    vector<int> size_er = {3, 4, 10, 6};    //test size
    vector<int> zero_er;

    int expected = 150;
        
    int result = jobScheduling(startTime, endTime, profit);
    cout << "result: " << result << endl;
    cout << endl;

    int size_er_result = jobScheduling(startTime, endTime, size_er);
    cout << "size_er_result: " << size_er_result << endl;
    cout << endl;

    int zero_er_result = jobScheduling(startTime, endTime, zero_er);

    return 0;
}