#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Given an array arr[] of size N. The task is to find the first repeating element in the array of integers, i.e. an element that  occurs more than once and whose index of first occurance is smallest     (Amazon, Oracle)
int main(){
    int n;
    
    cout<<"Enter length of array"<<endl;
    cin>>n;
    int a[n];

    cout<<"Enter elements of array"<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    const int N = 90;     // During Competetive for a longer array use N=1e6+2
    int idx[N];

    for(int i=0; i<N; i++){
        idx[i]=-1;
    }

    int minidx = 675555;

    for(int i=0; i<n; i++){
        if(idx[a[i]]!=-1){
            minidx=min(minidx, idx[a[i]]);
        } else {
            idx[a[i]] = i;              //This will store the position at which a[i] was found
        }
    }

    if(minidx==675555){
        cout<<"Minidx not found"<<endl;
    } else {
        cout<<minidx+1<<endl;              //minidx+1 so as to get the proper position of the element 
    }
}










//Given an unsorted array A of size N of non-negetive integers, find a continous sunarray which adds to a given number S
// int main(){
    
// }