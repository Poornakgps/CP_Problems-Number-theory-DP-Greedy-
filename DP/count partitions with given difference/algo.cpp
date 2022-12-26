#include<bits/stdc++.h>
#include<algorithm>
#include <vector>

#define ll long long
#define MOD 1000000007
#define MOD1 998244353
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;

int countWays(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){

     if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = countWays(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = countWays(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%MOD;
}

void countPartitions(int n, int d, vector<int> &arr){   
    int sum=0;
    for(auto it: arr){
        sum+=it;
    }
    if(sum-d<0 || (sum-d)%2){ 
        cout<<0<<endl;
        return;
    }
    int s2 = (sum-d)/2;
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    cout<<countWays(n-1,s2,arr,dp)<<endl; 
}

void solve(){
    ll n,d;
    cin>>n>>d;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    countPartitions(n,d,arr);

}
// tabulation 
// int findWays(vector<int> &num, int tar){
//      int n = num.size();

//     vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
//     if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
//     else dp[0][0] = 1;  // 1 case - not pick
    
//     if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
//     for(int ind = 1; ind<n; ind++){
//         for(int target= 0; target<=tar; target++){
            
//             int notTaken = dp[ind-1][target];
    
//             int taken = 0;
//                 if(num[ind]<=target)
//                     taken = dp[ind-1][target-num[ind]];
        
//             dp[ind][target]= (notTaken + taken)%mod;
//         }
//     }
//     return dp[n-1][tar];
// }

// int countPartitions(int n, int d, vector<int>& arr){
//     int totSum = 0;
//     for(int i=0; i<n;i++){
//         totSum += arr[i];
//     }
    
//     //Checking for edge cases
//     if(totSum-d <0 || (totSum-d)%2 ) return 0;
    
//     return findWays(arr,(totSum-d)/2);
// }

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}