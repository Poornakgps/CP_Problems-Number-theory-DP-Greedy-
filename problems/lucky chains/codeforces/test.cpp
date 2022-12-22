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
    ll n,m, flag=0;
    cin>>n>>m;

    ll ans[n+1];
    for(int i=1; i<=n; i++){
        ans[i]=i;
    }
    for(int i=1; i<=m; i++){
        ll a,b;
        cin>>a>>b;
        ll maxx=0;
        maxx=max(a,b);
        ans[maxx]=min(ans[maxx],maxx-min(a,b));
    }
    ll sum=0;
    ll effect=0;
    ll temp=0;
    cout<<endl;
    for(int i=1; i<=n; i++){
        if(ans[i]==i && effect==0){
            sum+=ans[i];
        }
        else{
            if(flag==0){
                sum += min(ans[i-1]+1,ans[i]);
                temp=min(ans[i-1]+1,ans[i]);
            }
            else{
                sum+= min(temp+1, ans[i]);
            }
            temp=min(temp+1,ans[i]);
            flag=1;
            effect=1;
        }
    }
    cout<<endl;
    cout<<sum<<endl;

}


int main(){
    fastio();
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}