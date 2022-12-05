#include<bits/stdc++.h>
#define ll long long

using namespace std;

//fermats primality test is tooo fast comparing to trial division method it will be done in O(log(N)) complexity
/*
This is a probabilistic test.

Fermat's little theorem (see also Euler's totient function) states, that for a prime number  and a coprime integer  the following equation holds:

(a^(p-1) is congruent to 1 (mod p))

In general this theorem doesn't hold for composite numbers.

This can be used to create a primality test. We pick an integer (2<=a<=p-2) , and check if the equation holds or not. 
If it doesn't hold, e.g.( a^(p-1) not congruent to 1 (mod p) ), we know that 'P'  cannot be a prime number. In this case we call the base  'a' a Fermat witness for the compositeness of p.

However it is also possible, that the equation holds for a composite number. So if the equation holds, 
we don't have a proof for primality. We only can say that 'p' is probably prime. If it turns out that the number is actually composite, we call the base 'a' a Fermat liar.

By running the test for all possible bases 'a' , we can actually prove that a number is prime. 
However this is not done in practice, since this is a lot more effort that just doing trial division. 
Instead the test will be repeated multiple times with random choices for 'a' . If we find no witness for the compositeness, 
it is very likely that the number is in fact prime.


bool probablyPrimeFermat(int n, int iter=5) {
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1)
            return false;
    }
    return true;
}
We use Binary Exponentiation to efficiently compute the power (a^(p-1)).

There is one bad news though: there exist some composite numbers where ( a^(n-1) congruent to 1 (mod n) ) holds for all 'a' coprime to 'n' , for instance for the number 561 = 11*7*13.
 Such numbers are called Carmichael numbers. The Fermat primality test can identify these numbers only, if we have immense luck and choose a base 'a' with (gcd(a,n) != 1).

The Fermat test is still be used in practice, as it is very fast and Carmichael numbers are very rare. E.g. there only exist 646 such numbers below 10^9.

*/

/*
    code begins
*/

ll mulmod(ll a, ll b, ll c)
{
    ll x=0, y=a%c;
    while(b>0)
    {
        if(b%2==1)
        {
            x=(x+y)%c;
        }
        y=(y*2ll)%c;
        b/=2;
    }
    return x%c;
}
ll binpower(ll a, ll n, ll mod)
{
    ll res=1;
    while(n)
    {
        if(n&1)
        res=mulmod(res,a,mod);

        n>>=1;
        a=mulmod(a,a,mod);
    }
    return res%mod;

}
bool fermat_primality(ll n)
{
    ll iter=5; // we can choose any value but it is better to choose optimized one 
    if(n<4)
    {
        return n==2 || n==3;
    }

    for(int i=1; i<=iter; i++)
    {
        ll a=2+ rand() %(n-3);
        ll res=binpower(a,n-1,n);
        if(res!=1)
        return false;
    }
    return true;

}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<fermat_primality(n)<<endl;
    }
}