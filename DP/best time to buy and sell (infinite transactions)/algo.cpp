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
    ll bd=0,sd=0,profit=0;

    for(int i=1; i<n; i++){

        if(arr[i]>=arr[i-1]){
            sd++;
        }
        else{
            profit+= arr[sd]- arr[bd];
            bd=sd=i;
        }
    }
    profit+= arr[sd]- arr[bd];
    cout<<profit<<endl;

}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}