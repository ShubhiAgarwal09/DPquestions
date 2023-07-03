#include <bits/stdc++.h> 
#define mod 1000000007
using namespace std;

int solve(int n ,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return (k*k)%mod;
    }

    int ans = (solve(n-2,k)%mod)*((k-1)%mod) + (solve(n-1,k)%mod)*((k-1)%mod);
    //int ans = solve(n-2,k)*(k-1)+ solve(n-1,k)*(k-1);
    return ans%mod;
}

int numberOfWays(int n, int k) {
    // Write your code here.
    //vector<int> dp(n+1,-1);
    return solve(n,k);
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<numberOfWays(n,k);
}