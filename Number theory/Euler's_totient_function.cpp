#include <bits/stdc++.h>
#define ll long long

using namespace std;

/***
 * Counts the number of co prime numbers of positive integers upto n which are co-prime to n
 * 
 * ex: GCD(1,5)=GCD(3,5)=GCD(2,5)=GCD(4,5)=1
 * phi(5)=4
*/

/**
 * Navoice approach 
 * 
 * int phi(int n)
 * {
 * int cnt=0;
 * 
 * for(int i=1; i<=n; i++)
 * if(GCD(i,N)==1)
 * cnt++;
 * 
 * return cnt;
 * }
 * O(N)
 */

/**
 * @for prime numbers like 2,3,5,7,9 be p
 * phi (p)=p-1
 * 
 * and phi(p^x) = p^x - (no.of integers not co-prime with p (means no of multiples of p in p^x) = p^(x-1))  
 *              = p^x - p^(x-1)
 *              = p^(x-1) *(P-1)
 */


// Multiplication function:
/**
 * An arithematic function f(x) is called multiplicative if f(N*M)=f(N)*f(M) where GCD(N,M)==1
 * 
 * use of multiplicative fn is 
 * helps in finding phi (n) in O(sqrt(N))
 * 
 *  
 */
/*
int phi(int n)
{
    int ans=n;

    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            ans=ans/i;
            ans=ans*(i-1);

            while(n%i==0)
            n=n/i;
        }
    }

    if(n>1)
    ans=ans/n, ans*=(n-1);
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;

        cout<<"ETF("<<n<<")"<<"= "<<phi(n)<<endl;
    }
}
*/

/**
 * Finding ETF using sieve
 * time complexity =O(N Log(Log(N))) in an effecient than upper method
 */

ll phi[1000001];

void initialization(int maxN)
{
    for(int i=1; i<=maxN; i++)
    phi[i]=i;

    for(int i=2; i<=maxN; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<=maxN; j+=i)
            {
                phi[j]=(phi[j]/i);
                phi[j]*=(i-1);
            }
        }
    }
}

int main()
{

    initialization(1000000);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<phi[n]<<endl;

    }
}