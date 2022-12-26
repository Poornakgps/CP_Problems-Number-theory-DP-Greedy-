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

int minSubsetsumDifference(vector<int> &arr, int n){

    int total=0;
    for(int i=0; i<n; i++){
        total+=arr[i];
    }
    int k=total;
    vector<vector<bool>> dp(n, vector<bool>(k+1,0));

    for(int i=0; i<n; i++) dp[i][0]=true;

    if(arr[0]<=k) dp[0][arr[0]] =true;

    for(int i=1; i<n; i++){
        for(int target=1; target<total; target++){
            bool notake= dp[i-1][target];
            bool take=false;

            if(arr[i]<=target ) take= dp[i-1][target-arr[i]];
            dp[i][target]= take | notake;
        }
    }
    int minn=1e9;

    for(int i=0; i<=total/2; i++){
        if(dp[n-1][i]==true){
            minn=min(minn, abs((total-i)-i));
        }
    }
    return minn;
}

void solve(){
    ll n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<minSubsetsumDifference(v,n)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
