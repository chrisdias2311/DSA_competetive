#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int maximumFrequency(vector<int> &arr, int n) {
    unordered_map<int, int> count;
    
    int maxfreq = 0;
    int maxAns = 0;
    
    for(int i=0; i<arr.size(); i++){
        count[arr[i]++];
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for(int i=0; i<arr.size; i==){
        if(maxFreq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}

int main(){

    return 0;
}