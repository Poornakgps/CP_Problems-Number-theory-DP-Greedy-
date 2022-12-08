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
    ll values[n],weight[n];
    for(int i=0; i<n; i++)
        cin>>values[i];

    for(int i=0; i<n; i++)
        cin>>weight[i];

    // for(int i=0; i<n; i++)
    //     cout<<weight[i]<<" "<<values[i]<<endl;

    ll maxweight;
    cin>>maxweight;

    ll dp[n+1][maxweight+1]={0};


    for(int i=0; i<(n+1); i++){

        for(int j=0; j<(maxweight+1); j++){

            if(i==0|| j==0){
                dp[i][j]=0;
                continue;
            }
            if(j>=weight[i-1]){

                ll rcap=j-weight[i-1];

                if(dp[i-1][rcap] + values[i-1]> dp[i-1][j]){
                    dp[i][j]=dp[i-1][rcap] + values[i-1];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }

            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][maxweight]<<endl;
}

int main(){

    ll t;
    cin>>t;
    while(t--){

        solve();
    }
}