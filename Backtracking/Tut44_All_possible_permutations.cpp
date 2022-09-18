#include<iostream>
#include<vector>
#include "bits/stdc++.h"
using namespace std;

// Return all possible permutations. Time complexity O(N!)
// vector<vector<int>> ans;          //vector ans (Global vector)

// void permute(vector<int> &a, int idx){
//     if(idx == a.size()){
//         ans.push_back(a);
//         return;
//     }
//     for(int i = idx; i<a.size(); i++){
//         swap(a[i], a[idx]);
//         permute(a, idx+1);
//         swap(a[i], a[idx]);
//     }
// }

// int main(){
//     int n;
//     cout<<"Enter length of vector"<<endl;
//     cin>>n;
//     vector<int> a(n);              //vector a 
    
//     cout<<"Enter the array"<<endl;
//     for(auto &i:a){
//         cin>>i;
//     }

//     permute(a, 0);

//     for(auto v: ans){
//         for(auto i : v){
//             cout<<i<<" ";
//         }
//         cout<<"\n";
//     }

//     return 0;
// }












//Using STL libraries 

// vector<vector<int>> ans;          //vector ans (Global vector)

// int main(){
//     int n;
//     cout<<"Enter length of vector"<<endl;
//     cin>>n;
//     vector<int> a(n);              //vector a 
    
//     cout<<"Enter the array"<<endl;
//     for(auto &i:a){
//         cin>>i;
//     }

//     sort(a.begin(), a.end());
//     do{
//         ans.push_back(a);
//     }while(next_permutation(a.begin(), a.end()));

//     for(auto v: ans){
//         for(auto i : v){
//             cout<<i<<" ";
//         }
//         cout<<"\n";
//     }

//     return 0;
// }














//For arrayof numbers with duplicates          (Problem)
void helper(vector<int> a, vector<vector<int>> &ans, int idx){
    if(idx== a.size()){
        ans.push_back(a);
        return;
    }

    for(int i=idx; i<a.size(); i++){
        if(i!=idx and a[i] == a[idx]){
            continue;
        } else {
            swap(a[i], a[idx]);
            helper(a, ans, idx+1);
        }
    }
}

vector<vetor<int>> permute(vector<int> nums){
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    helper(nums, ans, 0);
    return ans;
}

int main(){
    int n;
    cout<<"Enter length of vector"<<endl;
    cin>>n;
    vector<int> a(n);              //vector a 
    
    cout<<"Enter the array"<<endl;
    for(auto &i:a){
        cin>>i;
    }

    vector<vector<int>> res = permute(a);

    for(auto v: res){
        for(auto i : v){
            cout<<i<<" ";
        }
        cout<<"\n";
    }

    return 0;
}