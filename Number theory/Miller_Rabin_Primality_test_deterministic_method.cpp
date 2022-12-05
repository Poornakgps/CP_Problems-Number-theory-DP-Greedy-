#include<bits/stdc++.h>
#define ll long long

using namespace std;

using u64 = uint64_t; // unsigned long long
using u128 = __uint128_t;

/*

Miller showed that it is possible to make the algorithm deterministic by only checking all bases <=O( (ln(n))^2 ) . 
Bach later gave a concrete bound, it is only necessary to test all bases a <=2*(ln(n)^2).

This is still a pretty large number of bases. So people have invested quite a lot of computation power into finding lower bounds. 
It turns out, for testing a 32 bit integer it is only necessary to check the first 4 prime bases: 2, 3, 5 and 7. 
The smallest composite number that fails this test is 3,215,031,751 = 151 * 751 * 28351 . 
And for testing 64 bit integer it is enough to check the first 12 prime bases: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37.


Implementation of code.....
*/

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result; // a^d mod n returns
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}


bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
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
        
        cout<<MillerRabin(n)<<endl;
    }
}