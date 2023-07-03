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

int solveTab(int n ,int k){
    vector<int> dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));

    for(int i = 3;i<=n;i++){
        dp[i]= add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
}

int numberOfWays(int n, int k) {
    // Write your code here.
    vector<int> dp(n+1,-1);
    return solveTab(n,k);
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<numberOfWays(n,k);
}
