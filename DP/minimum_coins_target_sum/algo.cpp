#include <bits/stdc++.h>
using namespace std;


int minimum_coins(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){

/**********************************Base case**************************************/
    if(ind==0){
        if(!(target%arr[ind])){
            return target/arr[ind];
        }
        else{
            return 1e9;
        }
    }
    if(dp[ind][target]!=-1) return dp[ind][target];

/**********************************Base case**************************************/
    int notake= minimum_coins(ind-1,target, arr, dp);

    int take=1e9;

    if(target>=arr[ind]){
        take = 1+ minimum_coins(ind,target-arr[ind], arr, dp);
    }

    return dp[ind][target]=min(take,notake);
}

void solve(){
    int n,target;
    cin>>n>>target;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<minimum_coins(n-1,target, arr, dp)<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
