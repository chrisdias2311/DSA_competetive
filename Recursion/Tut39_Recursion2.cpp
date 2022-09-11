#include<iostream>
using namespace std;


//Check if an array is sorted or not 
// bool sorted(int arr[], int n){
//     if(n==1){
//         return true;
//     }

//     bool restArray = (arr+1, n-1);
//     if(arr[0]<arr[1] && restArray){
//         return true;
//     } else {
//         return false;
//     }
// }
// int main(){
//     int arr[] = {1,2,6,4,5};
//     cout<<sorted(arr, 5)<<endl;

//     return 0;
// }






//Print the numbers upto N 










//Find the first and last occurance of a nu,ber in an array 
int firstOcc(int arr[], int n, int i, int key){
    if(i==n){
        return -1;
    }
    
    if(arr[i]==key){
        return i;
    } 

    return firstOcc(arr, n, i+1, key);
}
int lastOcc(int arr[], int n, int i, int key){
    if(i==n){
        return -1;
    }

    int restArray = lastOcc(arr, n , i+1, key);

    if(restArray!=-1){
        return restArray;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}
int main(){
    int arr[] = {4,2,1,2,5,2,7};
    cout<<firstOcc(arr, 7, 0, 2)<<endl;
    cout<<lastOcc(arr, 7, 0, 2);
}