#include <bits/stdc++.h> 
#include<vector>
using namespace std;

int solve(vector<int>&nums ,int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }

    int include = solve(nums,n-2)+nums[n];
    int exclude = solve(nums,n-1)+0;

    return max(include,exclude);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    
    int ans = solve(nums,n);
    
    return ans;
}

int main(){
    int n ;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    cout<<maximumNonAdjacentSum(nums);
    return 0;
}