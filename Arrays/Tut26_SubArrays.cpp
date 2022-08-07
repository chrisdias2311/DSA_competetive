#include <iostream>
#include <climits> //for the minint and maxint values
#include <bits/stdc++.h>
using namespace std;

// Find the maximum sum of subarrays of an array  (BRUTE FORCE APPROACH)
//  int main(){
//      int n, sum, maxSum=0;
//      cin>>n;
//      int arr[n];
//      for(int i=0; i<n; i++){
//          cin>>arr[i];
//      }

//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             sum=0;
//             for(int k=i; k<=j; k++){
//                 sum+=arr[k];
//                 // cout<<arr[k];
//             }
//             if(sum>maxSum){
//                 maxSum=sum;
//             }
//         }
//     }

//     cout<<maxSum;

//     return 0;
// }

// Find the maximum sum of subarrays of an array  (CUMULATIVE SUM APPROACH)
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];

//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }

//     int currSum[n+1];
//     currSum[0]=0;

//     for(int i=1; i<=n; i++){
//         currSum[i] = currSum[i-1]+arr[i-1];
//     }

//     int maxSum = INT_MIN;

//     for(int i=1; i<=n; i++){
//         int sum=0;
//         for(int j=0; j<i; j++){
//             sum = currSum[i]-currSum[j];
//             maxSum = max(sum, maxSum);
//         }
//     }

//     cout<<maxSum;
//     return 0;
// }

// Find the maximum sum of subarrays of an array  (Kadane's algorithm)
//  












//MAXIMUM CIRCULAR SUBARRAY SUM 
// int kadane(int arr[], int n){
//     int currSum =0;
//     int maxSum = INT_MIN;

//     for(int i=0; i<n; i++){
//         currSum += arr[i];
//         if(currSum<0){
//             currSum = 0;
//         }
//         maxSum = max(maxSum, currSum);
//     }

//     return maxSum;
// }

// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
    
//     for(int i=0; i<n; i++){
//         cin>>arr[n];
//     }

//     int wrapSum; 
//     int noWrapSum;

//     noWrapSum = kadane(arr, n);
//     int totalSum = 0;

//     for(int i=0; i<n; i++){
//         totalSum += arr[i];
//         arr[i]=-arr[i];
//     }

//     wrapSum = totalSum + kadane(arr, n);
//     cout<<max(wrapSum, noWrapSum);
// }14,16,20

//24:51









//PAIR SUM PROBLEM                             (BRUT FORCE APPROACH)
// bool pairSum(int arr[], int n, int k){
//     for(int i=0; i<n-1; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i]+arr[j]==k){
//                 cout<<i<<" "<<j<<endl;
//                 return true;
//             }
//         }
//     }
//     return false ;
// }
// int main(){
//     int arr[] = {2,4,7,11,14,16,20,21};
//     int k=31;

//     cout<<pairSum(arr, 8, k);
// }

bool pairSum(int arr[], int n, int k){
    int low = 0;
    int high = n-1;
    while(low<high){
        if(arr[low]+arr[high]==k){
            cout<<low<<" "<<high<<endl;
            return true;
        } else if(arr[low]+arr[high]>k){
            high--;
        } else {
            low++;
        }
    }
    return false;
}
int main(){
    int arr[] = {2,4,7,11,14,16,20,21};
    int k=31;

    cout<<pairSum(arr, 8, k);
}