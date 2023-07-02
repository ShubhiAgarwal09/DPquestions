#include <iostream>
#include<vector>
using namespace std;
#include <limits.h>
int solveTab(int n, int x, int y, int z){
	vector<int> dp(n+1,INT_MIN);
	dp[0]=0;
	for(int i = 1;i<=n;i++){
		if(i-x>=0){
			dp[i]=max(dp[i],dp[i-x]+1);
		}
		if(i-y>=0){
			dp[i]=max(dp[i],dp[i-y]+1);
		}
		if(i-z>=0){
			dp[i]=max(dp[i],dp[i-z]+1);
		}
	}
	if(dp[n]<0){
		return 0;
	}
	return dp[n];
}


int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	int ans = solveTab(n,x,y,z);
	if(ans<0){
		return 0;
	}
	return ans;
}


int main(){
    int n ,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<cutSegments(n,x,y,z);
    return 0;
}