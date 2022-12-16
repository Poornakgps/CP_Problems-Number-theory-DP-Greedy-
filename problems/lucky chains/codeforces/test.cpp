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

int gcd(int a, int b){ if(b==0) return a; else return gcd(b,a%b); }

int power(ll x, ll y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return ((temp %MOD1)* temp)%MOD1;
    else
        return (x * (temp * temp)%MOD1)%MOD1;
}

void solve(){
    ll n;
    cin>>n;

    string s;
    cin>>s;
    ll arr[n];
    vector<ll> ones,zeros;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            zeros.push_back(i+1);
        }
        else{
            ones.push_back(i+1);
        }
    }

    for(int i=n-1; i>=0; i--){

    }
}

int main(){
    fastio();
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}