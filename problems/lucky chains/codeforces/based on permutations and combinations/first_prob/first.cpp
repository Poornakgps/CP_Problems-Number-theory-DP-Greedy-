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
    ll prev=1;
    vector<ll> ans;
    ans.push_back(1);
    for(int i=1; i<n-1; i++){
        if(s[i]==s[i-1]){
            ans.push_back(prev);
            //prev++;
        }
        else{
            prev=i+1;
            ans.push_back(i+1);
        }
    }
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    fastio();
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
