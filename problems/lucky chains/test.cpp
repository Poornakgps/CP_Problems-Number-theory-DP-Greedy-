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

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    return a.second>b.second;
}

void solve(ll t){
    ll n,m;
    cin>>n>>m;

    vector<pair<ll,ll>> act,req;
    
    for(int i=0; i<n; i++){
        ll temp;
        cin>>temp;
        act.push_back({temp,i+1});
        req.push_back({temp,i});
    }
    sort(req.begin(),req.end());
    ll maxwin=0;
    ll sum=0;
    map<ll,ll> mp;
    ll cha=0;
    ll value=0;
    for(int i=0; i<n; i++){
        sum+=req[i].first;
        if(sum<=m){
            mp[req[i].first]++;
            maxwin++;
        }
        else{
            value=req[i].first;
            if(i>0)
                sum=sum-req[i-1].first;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if(mp[act[i].first]!=0){
            mp[act[i].first]--;
            act[i].second--;
        }
    }
    sort(act.begin(),act.end(),comp);

    for(int i=0; i<n; i++){

        if(maxwin>=act[i].second){
            
            if(sum<=m && sum-act[i-1].first>=0 && maxwin+1==act[i-1].second){
                cout<<i<<endl;
                return;
            }
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<n+1<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--){ 
     solve(t); 
    }
}