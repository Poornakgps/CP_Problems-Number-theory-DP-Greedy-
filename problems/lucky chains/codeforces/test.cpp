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

// void solve(){
//     ll n,m;
//     cin>>n>>m;

//     vector<ll> req;
//     ll tsum=0,psum=0;

//     for(int i=0; i<n; i++){
//         ll temp;
//         cin>>temp;
//         if(i<m){
//             tsum+=temp;
//             psum+=temp;
//         }
//         else{
//             if(temp<=0)
//                 req.push_back(abs(temp));
//             tsum+=temp;
//         }
        
//     }
//    // cout<<tsum<<" "<<psum<<endl;
//     sort(req.begin(),req.end());
//     for(auto it: req){
//         cout<<it<<" ";
//     }
//     cout<<endl;

//     if(tsum>=psum){
//         cout<<0<<endl;
//     }
//     else{
//         ll count=0;
//         while(psum>tsum){
//             tsum+= req.back();
//             //cout<<req.back()<<endl;
//             req.pop_back();
//             count++;
//             //cout<<tsum<<" "<<psum<<endl;
//         }
//         cout<<count<<endl;
//     }
// }
void solve(){
    ll n;
    cin>>n;
    //cout<<n<<endl;
    ll a[n],q[n+1],p[n+1];
    map<ll,ll> m;
    vector<pair<ll,ll>> pp;
    for(ll i=0; i<n; i++){
        cin>>a[i];
        m[a[i]]++;
        pp.push_back({a[i],i+1});
    }
    sort(pp.begin(),pp.end());
    if(m[1]>1 || m[n]<1){
        cout<<"NO\n";
        return;
    }

    ll vis1[n+1]={0},vis2[n+1]={0};
    ll least=0,least1=0;
    for(int i=0; i<n; i++){

        ll l=pp[i].first;
        ll r=pp[i].second;   
            if(vis1[l]==0){
                q[r]=l;
                vis1[l]=1;
                while(vis2[least+1]==1)
                    least++;
                //cout<<least+1<<"1 "<<endl;
                vis2[least+1]=1;
                p[r]=least+1;
            }
            else if(vis2[l]==0){
                p[r]=l;
                while(vis1[least1+1]==1)
                    least1++;
                    //cout<<least1+1<<"2 "<<endl;
                vis1[least1+1]=1;
                vis2[l]=1;
                q[r]=least1+1;
                //least1++;
                //cout<<
            }
            else{
                cout<<"NO\n";
                return;
            }
            
    }
    map<ll,ll>m1,m2;
    for(int i=0; i<n; i++){
        m1[p[i+1]]++;
        m2[q[i+1]]++;
    }
    if(m1.size()!=n || m2.size() !=n){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n"; 
    for(int i=1; i<=n; i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<=n; i++){
        cout<<q[i]<<" ";
    }
    cout<<endl;
}


int main(){
    //sieve();
    fastio();
    ll t;
    cin>>t;

    while(t--)
        solve();
}
