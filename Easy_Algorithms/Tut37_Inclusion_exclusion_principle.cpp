#include<iostream>
using namespace std;

int divisible(int num, int n1, int n2){
    int c1 = num/n1;
    int c2 = num/n2;

    int c3 = num/(n1*n2);

    return c1+c2-c3;
}

int main(){

    int n, a, b;
    cin>>n>>a>>b;

    cout<<divisible(n, a, b);

    return 0;
}