#include <vector>
#include <iostream>
using namespace std;
#define mod 1000000007

long long int solve(int n,vector<long long int>& dp){
    if(n==1){
        return 0;
    }

    if(n==2){
        return 1;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] =(((n-1)%mod)*((solve(n-1,dp)%mod)+(solve(n-2,dp)%mod))%mod);
    return dp[n];
}

long long int countDerangements(int n) {
    //base case
    
    vector<long long int> dp(n+1,-1);
    //long long int ans = solve(n,dp);
    return solve(n,dp);
}

int main(){
    int n ;
    cin>>n;
    cout<<countDerangements(n);
    return 0;
}
