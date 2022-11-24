#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<n; i++){
        int current = arr[i];
        int j=i-1;             //start traversing the sorted array from behind i.e from end of sorted array
        while (arr[j]>current && j>=0){  //here current is the dangling element
            arr[j+1]=arr[j];   //start shifting the terms towards the right 
            j--;
        }
        arr[j+1]=current;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}