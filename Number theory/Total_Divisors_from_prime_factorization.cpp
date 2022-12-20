#include<bits/stdc++.h>

#define ll long long

using namespace std;

int gcd(ll a, ll b)
  {
      if(b==0)
      return a;
      else
      return gcd(b,a%b);
  }
#define max 1000000001
// ll spf[max];
 
// // Calculating SPF (Smallest Prime Factor) for every
// // number till MAXN.
// // Time Complexity : O(nloglogn)
// void sieve()
// {
//     spf[1] = 1;
//     for (int i=2; i<=1e9; i++)
 
//         // marking smallest prime factor for every
//         // number to be itself.
//         spf[i] = i;
 
//     // separately marking spf for every even
//     // number as 2
//     for (int i=4; i<=1e9; i+=2)
//         spf[i] = 2;
 
//     for (int i=3; i*i<=1e9; i++)
//     {
//         // checking if i is prime
//         if (spf[i] == i)
//         {
//             for (int j=i*i; j<=1e9; j+=i)
//                 if (spf[j]==j)
//                     spf[j] = i;
//         }
//     }
// }
// vector<ll> getFactorization(int x)
// {
//     vector<ll> ret;
//     while (x != 1)
//     {
//         ret.push_back(spf[x]);
//         x = x / spf[x];
//     }
//     return ret;
// }
vector<ll>factor[1001];
void sieve(){
    for(ll i=2; i*i<=1001; i++){
        //cout<<"HEY\n";
        for(int j=i; j<=1001; j+=i){
            factor[i].push_back(j);
            //cout<<"HELLO\n";
        }
    }
}

ll power(ll a ,ll n,  ll d)
{
    ll ans=1;
    while(n)
    {
        if(n%2==0)
        {
            a=( (a%d) * (a%d) )%d;
            n=n/2;
        }
        else
        {
            ans= ( (ans%d) * (a%d) ) % d;
            n--;
        }
    }
    return a;
}
int main(){
    cout<<(1<<30)<<endl;
    // ll n;
    // sieve();
    // cin>>n;
    // //vector<ll> factors=getFactorization(n);
    // for(int i=0; i<factor[n].size(); i++){
    //     cout<<factor[n][i]<<endl;
    // }

}

