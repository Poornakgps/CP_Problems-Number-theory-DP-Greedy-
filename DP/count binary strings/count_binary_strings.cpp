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
/**
 * @brief No of binary strings of length n which ahave no consecutive 0's
 * 
 */
void solve(){

    ll n;
    cin>>n;

    ll dp[2][n+1]={0};
    dp[0][1]=1;
    dp[1][1]=1;
    
    for(int i=2; i<=n; i++){
        dp[1][i]=dp[1][i-1]+dp[0][i-1];
        dp[0][i]=dp[1][i-1];
    }
    cout<<dp[1][n]+dp[0][n]<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){

        solve();
    }
}