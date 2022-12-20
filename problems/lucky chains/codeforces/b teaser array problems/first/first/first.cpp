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
    ll maxx=0;
    ll a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        maxx=max(a[i],maxx);
    }
    ll ans=0;
    if(n>=4){
        ans=maxx*n;
    }
    else if(n==2){
        ans=max(a[0]+a[1], 2*(abs(a[0]-a[1])));
    }
    else{
        if(maxx==a[0]|| maxx==a[n-1]){
            ans=maxx*n;
        }
        else{
            ll sum=a[0]+a[1]+a[2];          
            ans=max(sum,max(max(a[0]*3, abs(a[1]-a[2])*3),max(a[2]*3, abs(a[0]-a[1])*3)));   
        }
    }
    cout<<ans<<endl;
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
