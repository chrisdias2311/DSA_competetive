#include<iostream>
using namespace std;

//Backtracking is an algorithmic technique for solving recursive problems by trying to build every posible solution increamently and removing those solutionsthat fail to satisfy the constraints of the problem at any point of time 
bool isSafe(int** arr, int x, int y, int n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false; 
}

bool ratInMaze(int** arr, int x, int y, int n, int** solArr){
    if(x==n-1 && y==n-1){
        solArr[x][y]=1;
        return true;
    }

    if(isSafe(arr,x,y,n)){
        solArr[x][y]=1;
        if(ratInMaze(arr, x+1, y, n, solArr)){
            return true;                          //1. first check 
        }
        if(ratInMaze(arr, x, y+1, n, solArr)){
            return true;                          //2. second check 
        }
        solArr[x][y]=0;      //backtracking 
        return false;                             //if both the conditions are false, backtrack and return false 
    }
    return false;                                 // if isSafe() is not true, return false 
}

int main(){
    int n;
    cin>>n;
    int** arr = new int*[n];

    for(int i=0; i<n; i++){
        arr[i] = new int [n];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }


    //Solution matrix 
    int** solArr = new int*[n];
    for(int i=0; i<n; i++){
        solArr[i] = new int[n];
        for(int j=0; j<n; j++){
            solArr[i][j]=0;
        }
    }

    if(ratInMaze(arr, 0, 0, n, solArr)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<solArr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}

// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1 