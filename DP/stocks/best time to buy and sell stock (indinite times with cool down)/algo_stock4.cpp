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
    ll obsp=-arr[0];
    ll ossp=0;
    ll ocsp=0;
    for(int i=1; i<n; i++){
        ll nbsp=0;
        ll nssp=0;
        ll ncsp=0;
        if(ocsp-arr[i]>obsp){
            nbsp=ocsp-arr[i];
        }
        else{
            nbsp=obsp;
        }

        if(obsp+arr[i]>ossp){
            nssp=obsp+arr[i];
        }
        else{
            nssp=ossp;
        }
        ncsp=max(ocsp,ossp);
        ocsp=ncsp;
        ossp=nssp;
        obsp=nbsp;
    }
    cout<<ocsp<<endl;

}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}