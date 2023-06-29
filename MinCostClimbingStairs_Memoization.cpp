#include <iostream>
#include<vector>
using namespace std;


int solve2(vector<int>& cost,int n,vector<int>& dp){
        //base case
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        //step2
        dp[n] = cost[n]+ min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //step1
        vector<int> dp(n+1,-1);
        int ans = min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        return ans;
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