#include<iostream>
using namespace std;

//Tiling Problem 
// int tilingWays(int n){
//     if(n==0){
//         return 0;
//     }
//     if(n==1){
//         return 1;
//     }

//     return tilingWays(n-1)+tilingWays(n-2);
// }

// int main(){
//     cout<<tilingWays(4);

//     return 0;
// }











//Friends pairing problem 

// int friendsPairing(int n){
//     if(n==0 || n==1 || n==2){
//         return n;
//     }

//     return friendsPairing(n-1) + friendsPairing(n-2)*(n-1);
// }
// int main(){
//     cout<<friendsPairing(4);

//     return 0;
// }










//Knapsack Problem
int knapSack(int value[], int wt[], int n, int W){

    if(n==0 || W==0){
        return 0;
    }

    if(wt[n-1]>W){
        return knapSack(value, wt, n-1, W);
    }

    // int include = knapSack(value, wt, n-1, W-wt[n-1])+value[n-1];
    // int ignore = knapSack(value, wt, n-1, W);

    return max(knapSack(value, wt, n-1, W-wt[n-1])+value[n-1],knapSack(value, wt, n-1, W));
}
int main(){
    int wt[] = {10, 20, 30};
    int value[]={100,50,150};
    int W = 50;

    cout<<knapSack(value,wt,3,W)<<endl;

    return 0;
}