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
// void solve()
// {
//     int n,k;
//     cin>>n>>k;
//     int a[n];
//     for(int i=0; i<n; i++) cin>>a[i];
//     ll dp = 0;
//     ll sum = 0;
//     for(int i=-1; i<n; i++){
//         ll alt = sum;
//         for(int j=i+1; j<min(n,i+32); j++){
//             ll temp=a[j];
//             temp=temp/pow(2,j-i);
//             alt+=temp;
//         }
//         dp=max(dp,alt);
//         if(i+1!=n){
//             sum+=a[i+1]-k;
//         }
//     }
//     cout<<dp<<endl;
// }

// void solve(){
//     ll n;
//     cin>>n;
//     ll k;
//     cin>>k;
//     string s=to_string(n) ;
//     ll l=s.length();
//     ll o=0;
//     for(int i=0; i<l; i++){
//         if(s[i]=='0'){
//             o++;
//         }
//     }
//     if(o==0){
//         string str=s;
//         ll last;
//         if(2*k<=l)
//             last=2*k,sort(s.begin(),s.begin()+2*k);
//         else{
//             last=l;
//             sort(s.begin(),s.end());
//         }
//         map<char,ll> m;
        
//         for(int i=last-1; i>=last-k; i--){
//             m[s[i]]++;
//         }

//         for(int i=0; i<l; i++){
//             if(m[str[i]]==0){
//                 cout<<str[i];
//             }
//             else{
//                 m[str[i]]--;
//             }
//         }
//         cout<<endl;
//         return;
//     }
//     else{
//         string str=s;
//         k=k;

//         vector<ll> v;
//         ll ind=0;
//         for(int i=0; i<k+1 && i<l; i++){

//             if(str[i]=='0'){
//                 ind=i;
//                 //sort(s.begin()+i+1,s.end());
//                 break;
//             }
//             else{
//                 v.push_back((ll)str[i]-48);
//                 //cout<<v.front()<<endl;
//             }
//         }
//         sort(v.begin(),v.end());
//         ll req=k;
//         ll temp=k;
//         if(ind>2){
//             for(int i=0; i<ind-2; i++){
//                 cout<<v[i];
//                 k--;
//                 temp--;
//                 if(k==0){
//                     return;
//                 }
//             }
//         }
//         else{

//         }

        
//         sort(s.begin()+ind,s.end());

//         map<char,ll> m;
//         cout<<l-k-ind<<endl;
//         for(int i=l-1; i>=l-k-ind+1; i--){
//             m[s[i]]++;
//         }

//         for(int i=0; i<l; i++){
//             if(m[str[i]]==0){
//                 cout<<str[i];
//             }
//             else{
//                 m[str[i]]--;
//             }
//         }
//         cout<<endl; 
//     }

// }
void solve(){

    ll n;
    cin>>n;
    vector<ll> v;
    ll k=pow((ceil(float(sqrt(n)))),2);
    ll tt=n-1;
    for(int i=n-1; i>=0; i--){
        if(k-i<=tt){
           v.push_back(k-i); 
        }
        else{
            tt=sqrt(k)-1;
            k=pow(tt,2);
            v.push_back(k-i);
        }
        //cout<<k<<" "<<i<<endl;
    }

    ll count=0;
    for(int i=n-1; i>=0; i--){
        if(sqrt(v[i]+n-1-i) == ceil(float(sqrt(v[i]-i+n-1))))
            count++;

        if(v[i]>=353 || v[i]<0)
            break;
    }
    map<ll,ll> m;
    for(auto it: v){
        m[it]++;
    }
    if(m.size()!=n && sqrt(n)!= ceil(float(sqrt((float)n))) ){
        cout<<-1<<endl;
        return;
    }
    // if(sqrt(n)== ceil(float(sqrt((float)n)))){
    //     for(int i=n-1; i>=0; i--){

    //         if(i==n-1){
    //             cout<<0<<" ";
    //             continue;
    //         }
    //         cout<<v[i]<<" ";
    //     }
    // }
    // else{
    //     for(int i=n-1; i>=0; i--){
    //         cout<<v[i]<<" ";
    //     }
    // }
    //  cout<<endl;
     cout<<count<<endl;
}


int main(){

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}