#include<bits/stdc++.h>
#define ll long long

using namespace std;

using u64 = uint64_t; // unsigned long long
using u128 = __uint128_t;

// Miller rabin primality test better than fermets theorem
/*

Miller rabin primality test:

The Miller-Rabin test extends the ideas from the Fermat test.

For an odd number n, n-1  is even and we can factor out all powers of 2. We can write:

.    .    .    .    .    .    .    .    n-1= (2^s)*d , with d odd.

This allows us to factorize the equation of Fermat's little theorem:

.    (a^(n-1)) congruent to 1 (mod n)  == ( a^((2^s)*d )-1)  congruent to 0 mod n

.    .    .    .    .    .    .    .   == ( a^( ( 2^(s-1) )*d )-1)*( a^( ( 2^(s-1) )*d )+1) congruent to 0 mod n
.    .    .    .    .    .    .    .       .
.    .    .    .    .    .    .    .       .
.    .    .    .    .    .    .    .       .

Check notes for better understanding

If n is prime, then n has to divide one of these factors. And in the Miller-Rabin primality test we check exactly that statement,
which is a more stricter version of the statement of the Fermat test. For a base 2 <= a <= n-2 we check if either

.    .    .    .    .    .    .    .       .a^(d)  congruent to 1 mod n          

.    .    .    .    .    .    .    .        a^((2^r)*d  congruent to -1 mod n
holds for some 0<= r <= s-1 .

If we found a base 'a' which doesn't satisfy any of the above equalities, 
than we found a witness for the compositeness of 'n' . In this case we have proven that 'n' is not a prime number.

Similar to the Fermat test, it is also possible that the set of equations is satisfied for a composite number. 
In that case the base 'a' is called a strong liar. If a base 'a' satisfies the equations (one of them),  'n'
is only strong probable prime. However, there are no numbers like the Carmichael numbers, where all non-trivial bases lie. 
In fact it is possible to show, that at most 1/4 of the bases can be strong liars. If 'n' is composite, 
 we have a probability >=75% of  that a random base will tell us that it is composite. 
 By doing multiple iterations, choosing different random bases, we can tell with very high probability if the number is truly prime or 
 if it is composite.

Here is an implementation for 64 bit integer.
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

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))   //cheching compositeness
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
        u64 n;
        cin>>n;

        cout<<MillerRabin(n)<<endl;
    }
}