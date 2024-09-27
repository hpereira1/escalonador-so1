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
            count <<
        }
            jobs.push_back(j);
    }   // create jobs and push them into jobs vector 

}
    
int main(){
    vector<int> startTime = {1,2,3,4,6};
    vector<int> endTime = {3,5,10,6,9};
    vector<int> profit = {20,20,100,70,60};
    vector<int> size_er = {3, 4, 10, 6};    //test size
    vector<int> zero_er;

    int expected = 150;



    

    return 0;
}