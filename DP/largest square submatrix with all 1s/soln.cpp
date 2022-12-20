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

    ll m,n;
    cin>>m>>n;

    ll a[m][n];
    ll dp[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
            if(i==m-1 || j==n-1)
                dp[i][j]==a[i][j];
        }
    }
    ll ans=0;
    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            dp[i][j]=a[i][j]+min(dp[i+1][j],min(dp[i][j+1], dp[i+1][j+1]));
            ans=max(dp[i][j],ans);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}