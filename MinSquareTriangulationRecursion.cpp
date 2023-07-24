#include <bits/stdc++.h> 
#include<vector>
using namespace std;

    int solve(vector<int>& values,int i , int j ){
        //base case
        if(i+1==j){
            return 0;
        }

        int ans = INT_MAX;
        for(int k = i+1;k<j;k++){
            ans = min(ans,values[i]*values[k]*values[j]+solve(values,i,k)+solve(values,k,j));
        }
        return ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(),vector<int>(values.size(),-1));
        return solve(values,0,values.size()-1);
    }