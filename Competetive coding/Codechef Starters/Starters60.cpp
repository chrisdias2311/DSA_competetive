// You have NN cards placed in front of you on the table. The i^{th}i 
// th
//   card has the number A_iA 
// i
// ​
//   written on it.

// In one move, you can remove any one card from the remaining cards on the table.

// Find the minimum number of moves required so that all the cards remaining on the table have the same number written on them.

// Input Format
// The first line contains a single integer TT — the number of test cases. Then the test cases follow.
// The first line of each test case contains an integer NN — the number of cards on the table.
// The second line of each test case contains NN space-separated integers A_1, A_2, \dots, A_NA 
// 1
// ​
//  ,A 
// 2
// ​
//  ,…,A 
// N
// ​
//   where A_iA 
// i
// ​
//   is the number written on the i^{th}i 
// th
//   card.
// Output Format
// For each test case, output the minimum number of moves required so that all the cards remaining on the table have the same number written on them.








#include <iostream>
#include<map>
#include<unordered_map>
using namespace std;

int Frequency(int arr[], int n){
    unordered_map<int, int> map;
    
    for (int i = 0; i < n; i++){
        map[arr[i]]++;
    }
    
    int maxFreq=0;
    
    for(auto x:map){
        if(x.second>maxFreq){
            maxFreq=x.second;
        }
    }
    
    return maxFreq;
}

int main() {
    int tc;
    cin>>tc;
    
    while(tc!=0){
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        
        cout<<n-Frequency(arr, n)<<endl;
        
        tc--;
    }
	return 0;
}
