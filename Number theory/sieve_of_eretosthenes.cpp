#include<bits/stdc++.h>

#define ll long long
using namespace std;

// sieve of eretosthenes

// suppose they gave q queries q->1000000 (suppose)
// we need to print whether they r prime or not

int is_prime[100001];

void sieve()
{
    int maxN=1000000;

    for(int i=1; i<=maxN; i++)
        is_prime[i]=1;
    
    is_prime[0]=is_prime[1]=0; //since 1 and 0 are compostite numbers
    
    for(int i=2; i*i<=maxN; i++)
    {
        for(int j=i*i; j<=maxN; j+=i)
            is_prime[j]=0; // multiples of prime numbers becoming zero
        
    }
}

int main()
{
    sieve();
    
}