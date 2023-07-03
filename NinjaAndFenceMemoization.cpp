#include <bits/stdc++.h> 
#include<vector>
using namespace std;
#define mod 1000000007

int add(int a, int b){
    return (a%mod +b%mod)%mod;
}

int mul(int a,int b){
    return ((a%mod)*1LL*(b%mod))%mod;
}

int solve(int n ,int k,vector<int>&dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,mul(k,k-1));
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = add(mul(solve(n-2,k,dp),(k-1)),mul(solve(n-1,k,dp),(k-1)));
    //int ans = solve(n-2,k)*(k-1)+ solve(n-1,k)*(k-1);
    return dp[n];
}

int numberOfWays(int n, int k) {
    // Write your code here.
    vector<int> dp(n+1,-1);
    return solve(n,k,dp);
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<numberOfWays(n,k);
}
