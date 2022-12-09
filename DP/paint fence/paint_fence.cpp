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
/**
 * 
 * @brief Number of ways to color the fences with k different colors such that not more than 2 fences have the same color
 * 
 */

void solve(){
    ll n,k;    // n is number of fences and k is colors
    cin>>n>>k;
    ll Last2_same=k;
    ll Last2_different=k*(k-1);
    ll Total_ways=Last2_same+Last2_different;
    for(int i=2; i<n; i++){
        Last2_same=Last2_different;
        Last2_different=2*Total_ways;
        Total_ways=Last2_different+Last2_same;
    }
    cout<<Total_ways<<endl;

}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}