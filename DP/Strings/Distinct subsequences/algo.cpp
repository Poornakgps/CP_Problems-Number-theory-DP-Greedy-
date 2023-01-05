#include<bits/stdc++.h>
#include<algorithm>
#include <vector>

#define ll long long
#define mod 1000000007
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

/**************************************************************************************************
 * 
 * 
 * 
 * 
   * * * * * * * * * * * *               * * * * * * * * * * *
   * * * * * * * * * * * *                     * * * * * * * * * * *
   * * * * * * * * * * * *                            * * * * * * * * * * *              
   * * *           * * * *                                  * * * * * * * * * * *          
   * * *           * * * *                            * * * * * * * * * * *                  * * * * * * * * * * *
   * * *           * * * *                     * * * * * * * * * * *                               * * * * * * * * * * *    
   * * *           * * * *               * * * * * * * * * * *                                            * * * * * * * * * * *
   * * *           * * * *                                                                                     * * * * * * * * * * * *              
   * * * * * * * * * * * *               * * * * * * * * * * *                                           * * * * * * * * * * *
   * * * * * * * * * * * *                     * * * * * * * * * * *                               * * * * * * * * * * *
   * * * * * * * * * * * *                     * * * * * * * * * * *                    * * * * * * * * * * *
   * * *                                                   * * * * * * * * * * *      
   * * *                                             * * * * * * * * * * *
   * * *                                       * * * * * * * * * * *
   * * *                                 * * * * * * * * * * *
   * * *
   * * *
 *
 * 
 *
 * 
**************************************************************************************************/


ll algo(ll ind1, int ind2, string s1, string s2, vector<vector<ll>> &dp){

    if(ind2<0){
        return 1;
    }
    if(ind1<0){
        return 0;
    }

    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

    if(s1[ind1]==s2[ind2]){
        return dp[ind1][ind2]=algo(ind1-1, ind2-1, s1,s2,dp)+algo(ind1-1, ind2, s1,s2, dp);
    }
    else{
        return dp[ind1][ind2]=algo(ind1-1, ind2, s1, s2, dp);
    }
} 


ll tabulation(ll n, ll m, string s1, string s2){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<m+1;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            
            if(s1[i-1]==s2[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
}
void solve(){

    ll n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;

    vector<vector<ll>> dp(n,vector<ll>(m,-1));
    //cout<<algo(n-1,m-1,s1,s2,dp)<<endl;
    cout<<tabulation(n,m,s1,s2)<<endl;
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