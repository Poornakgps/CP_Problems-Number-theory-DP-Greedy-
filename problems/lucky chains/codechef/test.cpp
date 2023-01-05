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

void solve(){
    ll n,k,s;
    cin>>n>>k>>s;
    ll temp=s;
    ll count=0;
    while(temp>=1 ){
        temp=temp/k;
        count++;
    }
    //cout<<count<<endl;
    count--;
    if(count >n){
        cout<<-2<<endl;
        return;
    }
    ll a[count+1];
    ll flag=0;
    ll b[3]={-1,0,1};
    ll sum=pow(k,count);
 
    a[count]=1;
    s=s-sum;


    ll i=count-1;
    while(i!=0){
        if(s<0){
            
        }

    }

    if(flag==0){
        cout<<-2<<endl;
        return;
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