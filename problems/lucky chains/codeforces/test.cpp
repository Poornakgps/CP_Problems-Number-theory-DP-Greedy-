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
#define for(i,a,b) for(int i=a; i<b; i++) 

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

// void solve(){
//     ll n;
//     cin>>n;

//     ll a[n+1];
//     ll d[n-1]={0};
//     vector<int>v(n+1,1);
//     for(int i=1; i<=n; i++){
//         cin>>a[i];
//         v[i]=a[i];
//     }
//     ll ans[n]={0};

//     for(int i=1; i<=n; i++){
//         ans[n-v[i]+1]=i;
//     }
    
//     for(int i=1; i<=n; i++){
        
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
    
// }

void solve(){

    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int a1=0,b1=0;
    int s=0,d=0;

    for(i,0,n){

        if(a[i]==b[i]) s++;   
        else d++;

        if(a[i]=='1') a1++;

        if(b[i]=='1') b1++;
    }
    if(s!=n && d!=n){
        cout<<"NO\n";
        return;
    }
    vector<pair<int,int>>v;
    if(a==b){
        int k=0;
        for(i,0,n){
            if(a[i]=='1'){
                v.push_back({i+1,i+1});
                k=i;
            }
            
        }
        if(v.size()%2){
            v.push_back({n,n}), v.push_back({1,n}), v.push_back({1,n-1});
            
        }
    }
    else{

        int k=0;
        for(i,0,n){
            if(a[i]=='1'){
                v.push_back({i+1,i+1});
                k=i;
            }
        }
        if(v.size()%2==0){
            v.push_back({n,n}),v.push_back({1,n}), v.push_back({1,n-1});
        }     
    }
    cout<<"YES\n";
    cout<<v.size()<<endl;
    for(i,0,v.size()){
        cout<<v[i].first<<" "<<v[i].second<<endl;
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
