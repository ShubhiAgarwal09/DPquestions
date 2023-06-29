#include <iostream>
#include<vector>
using namespace std;


int solve2(vector<int>& cost,int n){
    vector<int> dp(n+1);
    dp[0]=cost[0];
    dp[1]= cost[1];
    
    for(int i =2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }

    return min(dp[n-1],dp[n-2]);
}

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve2(cost,n);
    }

    int main(){
        int n ;
        cin>>n;
        vector<int> cost(n);
        for(int i = 0;i<n;i++){
            cin>>cost[i];
        }
        cout<<minCostClimbingStairs(cost);
    }