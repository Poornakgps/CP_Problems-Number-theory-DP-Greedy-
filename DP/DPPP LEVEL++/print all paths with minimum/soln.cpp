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

class DP{
    public:
        ll ind;
        ll value;
        ll jump_took;
        string path; 
        static void DP(ll ind, ll value, ll jump_took, string path){
            this->ind=ind;
            this->value=value;
            this->jump_took=jump_took;
            this->path=path;
        } 
};

void solve(){

    ll n;
    cin>>n;

    ll a[n];

    for(int j=0; j<n; j++){
        cin>>a[j];
    }
    ll dp[n];
    dp[n-1]=0;
    
    for(int i=n-1; i>=0; i--){
        ll steps=a[i];
        ll minn=1e18;
        for(int j=1; j<=steps; j++){
            if(a[j+i]!=0 && dp[j+i]<minn){
                minn=dp[j+i]+1;
            }
        }
        if(minn!=1e18){
            dp[i]=minn+1;
        }
    }
    //cout<<dp[0]<<endl;
    deque<DP> que;

    que.push_back(DP(0,a[0],dp[0], 0+""));
    //cout<<que<<endl;

    while(que.size()>0){
        DP rem=que.pop_front();
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}