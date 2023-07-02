#include <iostream>
using namespace std;
long long int countDerangements(int n) {
    //base case
    
    if(n==1){
        return 0;
    }

    if(n==2){
        return 1;
    }

    long long int ans = (n-1)*(countDerangements(n-2)+countDerangements(n-1));
    return ans;
}

int main(){
    int n ;
    cin>>n;
    cout<<countDerangements(n);
    return 0;
}