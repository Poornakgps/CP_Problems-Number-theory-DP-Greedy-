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
    ll k;
    cin>>k;
    ll dp[k+1][n+1]={0};

    for(int i=0; i<=n; i++){
        if(i>0)
            dp[1][i]=1;
    }
    for(int i=2; i<=k; i++){
        for(int j=0;  j<=n; j++){
            if(i>j){
                dp[i][j]=0;
            }
            else if(i==j){
                dp[i][j]=1;
            }
            else{
                dp[i][j]= i*dp[i][j-1]+dp[i-1][j-1];
            }
        }
    }
    cout<<dp[k][n]<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}