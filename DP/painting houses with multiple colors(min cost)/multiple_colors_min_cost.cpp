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

// O(n^3)
// void solve(){

//     ll n;
//     cin>>n;
//     ll k;
//     cin>>k;

//     ll arr[n][k];

//     for(int i=0; i<n; i++){

//         for(int j=0; j<k; j++){
//             cin>>arr[i][j];
//         }
//     }
//     ll dp[n][k]={0};

//     for(int i=0; i<k ;i++){
//         dp[0][i]=arr[0][i];
//     }
//     ll ans=1e8;
//     for(int i=1; i<n; i++){

//         for(int j=0; j<k; j++){
//             ll minn=1e8;
//             for(int r=0; r<k ;r++){
//                 if(r!=j){
//                     minn=min(minn,dp[i-1][r]);
//                 }
//             }

//             dp[i][j]=minn+arr[i][j];
//             if(i==n-1){
//                 ans=min(ans,dp[i][j]);
//             }
//         }
//     }
//     cout<<ans<<endl;
// }

// optimized one O(n^2)
void solve(){

    ll n;
    cin>>n;
    ll k;
    cin>>k;

    ll arr[n][k];

    for(int i=0; i<n; i++){

        for(int j=0; j<k; j++){
            cin>>arr[i][j];
        }
    }
    ll dp[n][k]={0};

    for(int i=0; i<k ;i++){
        dp[0][i]=arr[0][i];
    }
    ll ans=1e8;
    for(int i=1; i<n; i++){

        pair<ll,ll> min1=make_pair(0,1e8),min2=make_pair(0,1e8);
        
        for(int j=0; j<k; j++){

            if(j==0){

                for(int r=0; r<k ;r++){
                    if(min1.second>dp[i-1][r]){
                        min1.second=min(min1.second,dp[i-1][r]);
                        min1.first=r;
                    }
                    else if(dp[i-1][r]<min2.second){
                        min2.second= min(min2.second,dp[i-1][r]);
                        min2.first=r;
                    }
                }
            }
            if(j!=min1.first){
                dp[i][j]=arr[i][j]+min1.second;
            }
            else{
                dp[i][j]=arr[i][j]+min2.second;
            }

            if(i==n-1){
                ans=min(ans,dp[i][j]);
            }
        }
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