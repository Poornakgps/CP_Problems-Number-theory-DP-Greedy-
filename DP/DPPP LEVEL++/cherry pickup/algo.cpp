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

 // 3D vector
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

int dpp(int r1, int c1, int c2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){

    if(c1<0 || c2<0 || c1>c || c2>c){
        return -1e8;
    }
    if(r1==r-1){
        if(c1==c2) return grid[r1][c1];
        else{
            return grid[r1][c1] + grid[r1][c2];
        }
    }
    if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
    
    int maxx= -1;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            int value=0;
            if(c1==c2) value+=grid[r1][c1];
            else{
                value =grid[r1][c1] + grid[r1][c2];
            }
            value += dpp(r1+1, c1+i, c2+j, r, c, grid, dp);
            maxx=max(maxx,value);
        }
    }
    return dp[r1][c1][c2]=maxx;
}
void solve(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>>grid(r,(vector<int>(c,0)));

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    cout<<dpp(0,0,c-1,r,c,grid,dp)<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}