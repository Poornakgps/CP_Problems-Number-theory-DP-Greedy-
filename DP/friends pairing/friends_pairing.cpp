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

void solve(){

    ll n;
    cin>>n;
    ll dp[n+1]={0};
    dp[2]=2;
    dp[1]=1;

    for(int i=3; i<=n; i++){
        dp[i]=dp[i-1]+(i-1)*dp[i-2];
    }
    cout<<dp[n]<<endl;

}

int main(){

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}