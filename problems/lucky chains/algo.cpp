#include<bits/stdc++.h>

#define ll long long
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

ll first_prime_factor[10000001];
bool is_prime[10000001]={false};
void sieve()
{

    ll maxN=10000000;

    for(int i=2; i<=maxN; i++)
    {
        if(!first_prime_factor[i])
        for(int j=i; j<=maxN; j+=i){
            first_prime_factor[j]=i;
        }
    }

}
// void solve(){

//     ll x,y;
//     cin>>x>>y;
//     if(__gcd(x,y)!=1){
//         cout<<0<<endl;
//         return;
//     }
//     if(x%2==y%2){
//         cout<<1<<endl;
//         return;
//     }
//     ll d=y-x;
    
//     ll ans=1e9;
// 	for(;d>1;d/=first_prime_factor[d])
// 	{
//         if(first_prime_factor[d]<=1){
//             continue;
//         }
// 		ans=min(ans,((x-1)/first_prime_factor[d]+1)*first_prime_factor[d]-x);
// 	}
//     if(ans==1e9){
//         cout<<-1<<endl;
//         return;
//     }
//     else{
//         cout<<ans<<endl;
//     }
//     return;
// }

void solve(){
    
}

int main(){
    fastio();
    sieve();
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}