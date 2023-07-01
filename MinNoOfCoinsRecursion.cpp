#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int solveRec(vector<int> &num,int x){
    //base case
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }

    int mini = INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans = solveRec(num, x-num[i]);
        if(ans!=INT_MAX){
            mini = min(mini,1+ans);
        }
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int ans = solveRec(num,x);
    if(ans==INT_MAX){
        return -1;
    }else{
        return ans;
    }
}

int main(){
    int n ;
    cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int x;
    cin>>x;
    cout<<minimumElements(num,x);
}