#include <bits/stdc++.h> 
#include<vector>
using namespace std;
    int solveMem(vector<int>& values,int i , int j ,vector<vector<int>>& dp){
        if(i+1==j){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans = INT_MAX;
        for(int k = i+1;k<j;k++){
            ans = min(ans,values[i]*values[k]*values[j]+solveMem(values,i,k,dp)+solveMem(values,k,j,dp));
        }
        dp[i][j]= ans;
        return dp[i][j];

    }

    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(),vector<int>(values.size(),-1));
        return solveMem(values,0,values.size()-1,dp);
    }