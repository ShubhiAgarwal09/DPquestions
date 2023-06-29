#include<iostream>
#include<vector>
using namespace std;

int solve(int n,int i,vector<int>& dp){
    //base case
    if(n==i){
        return 1;
    }
    if(i>n){
        return 0;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]= solve(n,i+1,dp)+solve(n,i+2,dp);
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    vector<int> dp(n+1,-1);

    cout<<solve(n,0,dp);
    return 0;
}