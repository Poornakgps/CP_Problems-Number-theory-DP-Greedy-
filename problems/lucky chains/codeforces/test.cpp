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
        return ((temp %mod)* temp)%mod;
    else
        return ((x)%mod * (((temp)%mod) * temp)%mod)%mod;
}
ll bpow(ll x, ll v) {	
	if (v == 0)
		return 1 % mod;
 
	if (v % 2 == 1)
		return (x * bpow(x, v - 1)) % mod;
 
	ll r = bpow(x, v / 2);
 
	return (r * r) % mod;	
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
//     ll n,x;
//     cin>>n>>x;

//     ll arr[n];
//     ll sum=0;
    
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//         sum=(sum+arr[i]);
//     }
//     map<ll,ll> m;
//     for(int i=0; i<n; i++){
//         ll k=(sum-arr[i]);
//         m[k]++;
//     }
//     for(auto it: m){

//         if(it.ss%x==0){
//             ll kk=0;
//             ll temp=it.ss;
//             ll flag=0;
//             while(temp%x==0){
//                 kk++;
//                 temp=temp/x;
//                 flag=1;
//             }
//             if(flag==1){
//                 m[it.ff +kk]=m[it.ff +kk]+temp;
//                 m[it.ff]=0;
//             }
//         }     
//     }
//     ll ans;
//     for(auto it: m){
//         if(it.ss>0){
//             ans=it.ff;
//             break;
//         }
//     }
//     ans=min(ans,sum);
//     ll k=bpow(x,ans);
//     cout<<1ll*k<<endl;
// }
// void solve(){
//     ll n;
//     cin>>n; 

//     vector<ll> v;
//     ll maxx=0,ind=0;
//     for(int i=0; i<n; i++){
//         ll temp;
//         cin>>temp;
//         v.push_back(temp);
//         if(maxx<=temp){
//             maxx=temp;
//             ind=i;
//         }
//     }
//     ll sum=0,avg=0;
//     ll ans=0;
//     for(int i=0; i<n; i++){
//         sum+=v[i];
//         if(i<=ind){
//             avg=ceil((float)sum/(i+1));
//             if(v[0]<=avg)
//                 ans=avg;
//         }
//         if(v[i]>=avg){
//             avg=ceil((float)sum/(i+1));
//         }
//        // cout<<avg<<endl;
//     }
//     cout<<max(avg,ans)<<endl;
// }
void solve(){
    ll n;
    cin>>n;

    ll a[n], b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    ll min11=min(abs(a[n-1]-a[n-2]),abs(a[n-1]-b[n-2]));
    ll minel1;
    if(min11==abs(a[n-1]-a[n-2])){
        minel1=min(a[n-1],a[n-2]);
    }
    else{
        minel1=min(a[n-1],b[n-2]);
    }
    ll minel2;

    ll min22=min(abs(b[n-1]-a[n-2]),abs(b[n-1]-b[n-2]));
    if(min22==abs(b[n-1]-a[n-2])){
        minel2=min(a[n-1],a[n-2]);
    }
    else{
        minel2=min(b[n-1],b[n-2]);
    }   
    for(int i=n-3; i>=0; i--){
        ll minn=min(min11,min22);
        ll x=abs(min11-a[i]), y=abs(min22-a[i]);
        
        // min11=min(abs(min11-a[i]), abs(min11-b[i]));
        // min22=min(abs(min22-a[i]), abs(min22-b[i]));

        if(x<y){
            min11=x;
        }
        else if(y>x){
            min11=y;
        }
        else{

        }
        ll c=abs(min22-b[i]),d=abs(min11-b[i]);
    }

}

int main(){
    //sieve();
    fastio();
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
