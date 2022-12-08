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

void solve()
{
    ll n;
    cin>>n;
    ll values[n],weight[n];
    for(int i=0; i<n; i++)
        cin>>values[i];

    for(int i=0; i<n; i++)
        cin>>weight[i];

    ll maxweight;
    cin>>maxweight;

    ll dp[maxweight+1]={0};
    // for(int i=0; i<maxweight+1; i++)
    // cout<<dp[i]<<endl;
    dp[0]=0;

    for(int i=1; i<=maxweight; i++){
        ll max=0;
        for(int j=0; j<n; j++){
            if(weight[j]<=i){
                ll temp=dp[i-weight[j]]+ values[j];
                //cout<<dp[i-weight[j]]
                
                if(temp>max){
                    max=temp;
                }
            }

        }
        dp[i]=max;
        //cout<<dp[i]<<" ";
    }
    cout<<endl<<dp[maxweight]<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}