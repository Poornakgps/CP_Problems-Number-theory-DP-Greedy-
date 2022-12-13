#include<bits/stdc++.h>

#define ll long long
using namespace std;


bool is_prime[100000001]={false}; // all asigning prime initially

vector<ll> kth_prime;

void sieve()
{
    // sieve of eretosthenes

    // suppose they gave q queries q->1000000 (suppose)
    // we need to print whether they r prime or not

    ll maxN=100000000;
    
    is_prime[0]=is_prime[1]=true; //since 1 and 0 are compostite numbers
    
    for(int i=2; i*i<=maxN; i++)
    {
        if(!is_prime[i])
        for(int j=i*i; j<=maxN; j+=i)
            is_prime[j]=true; // multiples of prime numbers becoming zero
    }
    //  false are prime numbers

    for(int i=2; i<=maxN; i++)
    {
        if(!is_prime[i])
        kth_prime.push_back(i);
    }
}

void prime_factors(ll num)
{

    for(int i=2; i<=sqrt(num); i++)
    {
        if(num%i==0)
        {
            ll cnt=0;
            while(num%i==0)
            cnt++,num=num/i;

            cout<<i<<"^"<<cnt<<endl;
        }
    }
        if(num>1)
        cout<<num<<"^"<<1<<endl;
}

// try to familier with bool coz it takes less bytes(1byte) saves time and space it will helps in avoiding tle

int main()
{
    sieve();
    ll k;
    cin>>k;

    cout<<kth_prime[k-1]<<endl;

    ll num;
    cin>>num;

    prime_factors(num);
}