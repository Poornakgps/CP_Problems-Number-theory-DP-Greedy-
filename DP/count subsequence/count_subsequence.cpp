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

    string str;
    cin>>str;

    int a=0;
    int ab=0;
    int abc=0;

    for(int i=0; i<n; i++){

        if(str[i]=='a'){
            a=2*a +1;
        }
        else if(str[i]=='b'){

            ab= 2*ab + a;
        }
        else {
            abc= 2*abc +ab;
        }
    }
    cout<<abc<<endl;

}

int main(){

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}