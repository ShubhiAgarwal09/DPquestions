#include <bits/stdc++.h> 
#include<vector>
using namespace std;

int solveMem(int n, vector<int>& days, vector<int>& cost,int index,vector<int>& dp){
    if(index>=n){
        return 0;
    }

    if(dp[index]!=-1){
        return dp[index];
    }

    //1 day pass
    int option1 = cost[0]+solveMem(n,days,cost,index+1,dp);

    //7 days pass
    int i ;
    for(i=index;i<n&&days[i]<days[index]+7;i++); //loop for incrementing i
    int option2 = cost[1]+solveMem(n,days,cost,i,dp);

    //30 days pass
    for(i=index;i<n&&days[i]<days[index]+30;i++); //loop for incrementing i
    int option3 = cost[2]+solveMem(n,days,cost,i,dp);

    dp[index]=min(option1,min(option2,option3));
    return dp[index];

}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1,-1);
    return solveMem(n,days,cost,0,dp);
}