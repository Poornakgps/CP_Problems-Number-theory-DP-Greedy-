#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

// Finding modulo inverse


//modulo multiplicative inverse: modulo multiplicative inverse of a number N , 
//under modulo P is defined to be a number x that  N*X congruence to 1 (mod P)
/**
 * (6/2)%5 == ((6%5) * (3%5))%5 = (1*3)%5 =3
 * coz modulo multiplicative inverse of 2 is under 5 is 3
 * 
 */


// Fermats little theorem

/*
    if(gcd of a^m-1 and m is 1 means both are co prime) 
*/

int power(int a , int n, int m)
{
    int res=1;
    while(n)
    {
        if(n%2)
        {
            res= (res*a)%m;
            n--;
        }
        else
        {
            a= (a*a)%m;
            n=n/2;
        }
    }
    return res;
}
/**
 * @brief 
 * if a=4 and m=7  note: a and m must be coprimes
 * then modulo inverse of 4 is 2 coz 4 * 2 = 8 % 7 is 1 
 * 
 */

int main()
{
    ll t;
    cin>> t;
    while(t--)
    {
        ll a,b,m;
        cin>>a>>m;
        cout<<"a^-1 "<<power(a,m-2,m)<<endl;

    }
}
