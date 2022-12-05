#include<bits/stdc++.h>

#define ll long long
#define mod 100000007
using namespace std;


// bool is_prime[100000001]; // all asigning prime initially

// vector<ll> kth_prime;

// void sieve()
// {
//     // sieve of eretosthenes

//     // suppose they gave q queries q->1000000 (suppose)
//     // we need to print whether they r prime or not

//     ll maxN=100000000;
    
//     is_prime[0]=is_prime[1]=true; //since 1 and 0 are compostite numbers
    
//     for(int i=2; i*i<=maxN; i++)
//     {
//         if(!is_prime[i])
//         for(int j=i*i; j<=maxN; j+=i)
//             is_prime[j]=true; // multiples of prime numbers becoming zero
//     }
//     //  false are prime numbers

//     for(int i=2; i<=maxN; i++)
//     {
//         if(!is_prime[i])
//         kth_prime.push_back(i);
//     }
// }

// void prime_factors(ll num)
// {

//     for(int i=2; i<sqrt(num); i++)
//     {
//         if(num%i==0)
//         {
//             ll cnt=0;
//             while(num%i==0)
//             cnt++,num=num/i;

//             cout<<i<<"^"<<cnt<<endl;
//         }
//         if(num>1)
//         cout<<num<<"^"<<1<<endl;
//     }
// }

// try to familier with bool coz it takes less bytes(1byte) saves time and space it will helps in avoiding tle
ll ar[2];

void mul(ll I[2][2], ll m[1][2], ll dim)
{
    ll res[dim][dim];
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++)
        {
            res[i][j]=0;
            for(int k=0; k<dim; k++){
           //  res[i][j] +=I[i][k]*m[k][j]; it might grt overflow
            ll x=(I[i][k]*m[k][j])%mod;
            res[i][j]=(res[i][j]+x)%mod;
            }

        }
    }
}
ll getfib (ll n)
{
    if(n<=2) return ar[n];

    ll I[2][2],T[2][2];
    I[0][0]=I[1][1]=1;
    I[1][0]=I[0][1]=0;

    //let transient matrix is
    T[0][0]=1;
    T[1][0]=T[0][1]=T[1][1]=1;

    // by solving the given equation we get a , b, c ,d in transient matrix
    n=n-1;
    while(n)
    {
        if(n%2)
        mul(I,T,n),n--;
        else
        mul(T,T,n),n=n/2;

    }
    ll Fn=(ar[0] *I[0][0]+ar[1]*I[1][0])%mod;
    return Fn;
}

int main()
{
    int t;
    ll t;
    while(t--)
    {
        ll n;
        cin>>ar[0]>>ar[1]>>n;

        cout<<getfib(n)<<endl;

    }


}