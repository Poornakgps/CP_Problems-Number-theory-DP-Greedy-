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

// void solve(){

//     ll n,h;
//     cin>>n>>h;

//     ll a[n+1];
//     for(int i=1; i<=n; i++){
//         cin>>a[i];
//     }
//     vector<ll> dp(6,0);
//     ll factors[6]={1,2,3,4,6,12};
//     for(int i=0; i<6; i++){
//         dp[i] += h*factors[i];
//     }
//     a[0]=0;
//     sort(a,a+n+1);
//     ll start=0;
//     ll ans=0;

//     for(int i=0; i<=n; i++){

//         for(int j=0; j<6; j++){

//             if(j>=start){
//                 if(a[i] <dp[j]){
//                     dp[j] += a[i]/2;
//                 }
//                 else{
//                     start++;
//                     if(j==0){
//                         dp[j+1]=max(dp[j+1], 2*dp[j]),
//                         dp[j+2]=max(dp[j+2], 3*dp[j]),
//                         dp[j+3]=max(dp[j+3], 4*dp[j]),
//                         dp[j+4]=max(dp[j+4], 6*dp[j]),
//                         dp[j+5]=max(dp[j+5], 12*dp[j]);
//                     }
//                     else if(j==1){
                        
//                         dp[j+2]= max(dp[j+2], 2*dp[j]),
//                         dp[j+3]=max(dp[j+3], 3*dp[j]),
//                         dp[j+4]=max(dp[j+4], 6*dp[j]);
//                     }
//                     else if(j==2){
//                         dp[j+2]= max(dp[j+2], 2*dp[j]),
//                         dp[j+3]=max(dp[j+3], 4*dp[j]);         
//                     }
//                     else if(j==3){
//                         dp[j+2]= max(dp[j+2], 3*dp[j]);                    
//                     }
//                     else if(j==4){
//                         dp[j+1]= max(dp[j+1], 2*dp[j]);          
//                     }
//                 }
//             }
//         }
//         if(start==6){
//             ans=i;
//             break;
//         }
//     }
//     if(ans==0)
//     cout<<n<<endl;
//     else{
//         cout<<ans-1<<endl;
//     }
// }

//unordered_map<ll,ll> actual;



bool condition(pair<ll,ll> a, pair<ll,ll> b){
    return a.first<b.first;
}
int main(){
  
    ll t;
    cin>>t;
    ll n=t;
    ll ans=0;
    while(t--){
        ll index=1;
        map<ll,ll> req,actual;
        vector<ll> data;  
        ll k;
        cin>>k;
        for(int i=0; i<k; i++){
            ll weight;
            cin>>weight;
            actual[weight]=index;
            index++;
            data.push_back(weight);
        }
        index=1;
        for(auto it: actual){
            req[it.first]=index;
            index++;
        }
        ll split=0;
        for(int i=0; i<data.size()-1; i++){
            //cout<<actual[data[i]]-actual[data[i+1]]<<" "<<req[data[i]]-req[data[i+1]]<<endl;
            if(actual[data[i]]-actual[data[i+1]]== req[data[i]]-req[data[i+1]]){
                continue;
            }
            else{
                split++;
            }
        }
        ans+=split;
    }

    cout<<ans<<" "<<n+ans-1<<endl;
}