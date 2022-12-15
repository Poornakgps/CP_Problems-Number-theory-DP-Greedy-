#include<bits/stdc++.h>

#define ll long long
using namespace std;


bool is_prime[90000001]; // all asigning prime initially

vector<ll> kth_prime;

void sieve()
{
    int maxN=90000000;
 
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

// try to familier with bool coz it takes less bytes(1byte) saves time and space it will helps in avoiding tle

int main()
{
    sieve();
    ll k;
    cin>>k;

    cout<<kth_prime[k-1]<<endl;
    
}