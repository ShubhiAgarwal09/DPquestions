#include <vector>
#include <iostream>
using namespace std;
#define mod 1000000007

long long int solveTab(int n){
    vector<long long int> dp(n+1,0);
    dp[1]=0;
    dp[2]=1;

    for(int i = 3;i<=n;i++){
        long long int sum = (dp[i-1]%mod)+(dp[i-2]%mod);
        long long int ans = ((i-1)*sum)%mod;
        dp[i]=ans;
    }
    return dp[n];
}

long long int countDerangements(int n) {
    //base case
    
    vector<long long int> dp(n+1,-1);
    //long long int ans = solve(n,dp);
    return solveTab(n);
}

int main(){
    int n ;
    cin>>n;
    cout<<countDerangements(n);
    return 0;
}