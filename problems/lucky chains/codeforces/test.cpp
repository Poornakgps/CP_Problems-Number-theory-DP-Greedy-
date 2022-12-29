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

// void solve(){
//     ll n;
//     cin>>n;

//     ll a[n+1];
//     ll d[n-1]={0};
//     vector<int>v(n+1,1);
//     for(int i=1; i<=n; i++){
//         cin>>a[i];
//         v[i]=a[i];
//     }
//     ll ans[n]={0};

//     for(int i=1; i<=n; i++){
//         ans[n-v[i]+1]=i;
//     }
    
//     for(int i=1; i<=n; i++){
        
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
    
// }
// ll a[1000000001][1000000001];
// void sieve(){
//     for(int i=1; i<=1e9; i++){
//         for(int j=1; j<=1e9; j++){
//             if(i<=507 || j<=507)
//                 a[i][j]=((i%MOD)*(j%MOD))%MOD;
//             else{
//                 ll a1=i/10+i%10;
//                 ll a2=i/10;
//                 ll b1=j/10;
//                 ll b2=j/10+j%10;
//                 ll k= ( ((a1*b2)%MOD +(a2*b1)%MOD)%MOD+ ((a1*b1)%MOD+ (b2*a2)%MOD)%MOD )%MOD;
//                 a[i][j]=k;
//             }
//         }
//     }
// }

// void solve(){
//     ll n;
//     cin>>n;
//     ll ans=0;

//     for(int i=1; i<=n; i++){
      
//         ans= (ans + a[i][i])%MOD;
//     }
//     for(int i=1; i<n; i++){
      
//         ans= (ans + a[i][i+1])%MOD;
//     }
//     ll sum= ((2*(1ll)*((1011)*(ans))%MOD)%MOD)%MOD;
    
//     cout<<sum<<endl;
// }
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
    ll n;
    cin>>n;
    ll one=0;
    ll a[n+1];
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(!is_prime[a[i]]){
            one++;
        }
    }
    vector<ll> brk;
    ll tt=a[1];
    ll k=1;
    for(int i=2; i<=n; i++){ 

        tt =(tt^a[i]);
        cout<<a[i]<<" "<<tt<<endl;
        if(is_prime[tt]){

            brk.push_back(i-k);

            cout<<i-k<<endl;
            //tt=a[i-1];
            if(!is_prime[a[i-1]^a[i]]){
                i--;
                tt=a[i-1];
            }
            k=i;
        }
        else if(i==n){
            brk.push_back(i-k);
        }
        cout<<a[i]<<" "<<tt<<endl;
    }

    ll ans=0;
    for(int i=0; i<brk.size(); i++){
        ans+=(brk[i]*(brk[i]+1))/2;
    }
    //if()
    cout<<one<<endl;
    cout<<ans+one<<endl;

}
// void solve(){
//         ll n;
//         cin >> n;
//         ll sum = 0;
//         ll k = n;
//         n = n - 1;
//         // cout<<k;
//         ll diff = 4, num = 3;
//         sum = ((((((n * (n + 1)) % mod) * ((2 * n + 1) % mod)) / 3) % mod) + ((n * (n + 1)) / 2) % mod) % mod;
//         sum = ((sum % mod) + ((k) * (k)) % mod) % mod;
//         cout << ((sum)*2022) % mod << endl;
// }

int main(){
    sieve();
    fastio();
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
