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
    ll arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll curr=arr[1];
    ll minn=arr[0];
    ll ans=-10;

    for(int i=2; i<n; i++){

        ans=max(ans,curr-minn);
        curr=arr[i];
        minn=min(minn,arr[i-1]);
    }
    ans=max(ans,curr-minn);

    cout<<ans<<endl;

}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}