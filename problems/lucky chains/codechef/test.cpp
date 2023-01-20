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

bool is_prime[200000]; // all asigning prime initially

void sieve()
{
    int maxN=200000;
 
    is_prime[0]=is_prime[1]=true; //since 1 and 0 are compostite numbers
    
    for(int i=2; i*i<=maxN; i++)
    {
        if(!is_prime[i])
        for(int j=i*i; j<=maxN; j+=i)
            is_prime[j]=true; // multiples of prime numbers becoming zero
    }

}

// void solve(){
    
//     ll n,m;
//     cin>>n>>m;

//     map<ll,ll>mp;

//     ll a[n],p[m];
//     ll summ=0;
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//         mp[a[i]]++;
//         summ+=a[i];
//     }
//     for(int i=0; i<m; i++){
//         cin>>p[i];
//     }

//     ll maxx=INT_MIN;
//     ll ans[m]={0};
//     ans[0]=summ;
//     for(int i=1; i<m; i++){
//         ans[i]=ans[i-1]-(i)*mp[i]-((i)*(i-1)/2)*mp[i] ;
//     }

//     for(int i=1; i<=m; i++){

//          maxx=max(maxx,(ans[i-1]/i -1)*p[i-1]);
//          cout<<ans[i-1]/i -1<<endl;
//     }
//    // cout<<endl;
//     cout<<max(summ*p[0],maxx)<<endl;
// }

void solve(){
    ll n;
    cin>>n;
    ll k=10000000;

    for(int i=0; i<n; i++){
        cout<<k-n+i<<" ";
    }
     cout<<endl;
}


int main(){
    fastio();
    // ll t;
    // cin>>t;
    // while(t--){
        solve();
    // }
}