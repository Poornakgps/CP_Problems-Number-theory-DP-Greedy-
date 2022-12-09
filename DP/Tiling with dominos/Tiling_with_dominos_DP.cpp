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

// in how many ways u can fill the  2xn floor (matrix) with 2x1 domino's  # indirectly  fibonacci series see notes

ll dominos(ll n)
{
    ll dp[n+1]={0};

    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<dominos(n)<<endl;
    }
}