#include<iostream>
using namespace std;


//Sum of N numbers 
// int Sum(int n){
//     if(n==0){
//         return 0;
//     }

//     int prevSum = Sum(n-1);
//     return n+prevSum;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<Sum(n);
// }








//X raised to N 
// int power(int n, int p){
//     if(p==1){
//         return 1;
//     }

//     int prevPower = power(n, p-1);
//     return n*prevPower;
// }

// int main(){
//     int n, p;
//     cin>>n>>p;

//     cout<<power(n,p);

//     return 0;
// }









/// find N using recursion

// int factorial(int n){
//     if(n==0){
//         return 1;
//     }
    
//     int prevFact = factorial(n-1);
//     return prevFact*n;
// }
// int main(){
//     int n;
//     cin>>n;

//     cout<<factorial(n);

//     return 0;
// }








//find the fibonacci series of N numbers 
int printFib(int n){
    if(n==0 || n==1){      //base condition
        return n;
    }
    return printFib(n-1)+printFib(n-2);
}

int main(){
    int n;
    cin>>n;

    cout<<printFib(n);
}