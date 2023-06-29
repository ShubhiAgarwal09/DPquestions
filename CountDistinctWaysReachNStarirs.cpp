#include<iostream>
using namespace std;

int solve(int n,int i){
    //base case
    if(n==i){
        return 1;
    }
    if(i>n){
        return 0;
    }
    return solve(n,i+1)+solve(n,i+2);
}

int main(){
    int n;
    cin>>n;

    cout<<solve(n,0);
    return 0;
}