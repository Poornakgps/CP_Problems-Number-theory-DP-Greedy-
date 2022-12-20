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
    ll a[n],sum=0;
    ll maxx=-1e18;
    ll index=0;
    ll index1=0;
    ll minn=1e18;
    
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(maxx<a[i]){
            maxx=a[i];
            index=i;
        }
        if(minn>a[i]){
            minn=a[i];
            index1=i;
        }
        sum+=a[i];
    }
    ll max_sum1=maxx;
    ll max_sum2=maxx;
    ll tt=1;
    for(int i=index-1; i>=0; i--){
        tt++;
        max_sum1+=a[i];
        if(max_sum1< (tt)*(maxx-a[i])){
            if(i==0){
                max_sum1=(tt)*(maxx-a[i]);
            }
            else{
                
            }
        }
    }
    tt=1;
    for(int i=index; i<n; i++){
        tt++;
        max_sum2+=a[i];
        if(max_sum2< (tt)*(maxx-a[i])){
            if(i==n-1){
                max_sum2=(tt)*(maxx-a[i]);
            }
        }
    }
    ll maxxx=max_sum1+max_sum2;

    // ll min_sum1=a[index1],min_sum2=a[index1];
    // ll ttt=1;
    // for(int i=index1-1; i>=0; i--){
    //     ttt++;
    //     min_sum1+=a[i];
    //     if(min_sum1< (ttt)*(a[i]-minn)){
    //         if(i==0){
    //             min_sum1=(ttt)*(a[i]-minn);
    //         }
    //     }
    // }
    // ttt=1;
    // for(int i=index1; i<n; i++){
    //     ttt++;
    //     max_sum2+=a[i];
    //     if(max_sum2< (ttt)*(-minn+a[i])){
    //         if(i==n-1){
    //             min_sum2=(ttt)*(-minn+a[i]);
    //         }
    //         else{

    //         }
    //     }
    // }

}

int main(){
    fastio();
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
