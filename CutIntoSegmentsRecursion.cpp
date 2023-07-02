#include <limits.h>
#include <iostream>
#include<vector>
using namespace std;

int solve(int n, int x, int y, int z){
	if(n==0){
		return 0;
	}

	if(n<0){
		return INT_MIN;
	}


	int a = solve(n-x,x,y,z)+1;
	int b = solve(n-y,x,y,z)+1;
	int c = solve(n-z,x,y,z)+1;

	int ans = max(a,max(b,c));
	return ans;


}


int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	int ans = solve(n,x,y,z);
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
