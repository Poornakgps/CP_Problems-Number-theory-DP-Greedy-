#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

// problem
/**Given integers AA, BB and NN, you should calculate the GCD of A^N + B^N and |A - B|. 
(Assume that GCD(0, a) = a for any positive integer a). Since this number could be very large, compute it modulo 1000000007(10^9 + 7) **/

using namespace std;

vector<ll>factors;

// int gcd(int a, int b)
//   {
//       if(b==0)
//       return a;
//       else
//       return gcd(b,a%b);
//   }

// void calc_factors(ll k)
// {
//     ll count=0;
//     for(int i=2;i<sqrt(k);i++)
//     {
//         if(!(i%k))
//         {
//             while(i%k==0)
//             {
//                 count++;
//                 factors.push_back(i);
//             }


//         }
//     }
// }

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

int gcd(ll a, ll  b, ll n)
{
    if(a-b==0)
    {    
        return ((power(a,n,mod) +power(b,n,mod)) % mod);
    }

    ll candidate=1;// highest factor which divisible both a^n +b^n and a-b
    ll dif=abs(a-b);

    for(ll i=1; i*i<=(dif); i++)
    {
        if(dif % i ==0)
        {
            ll temp=(power(a , n , i) + power(b , n , i))%i;
            if(temp==0)
            {
                candidate = max(candidate , i );
            }
            temp=(power(a , n , dif/i ) + power(b , n , dif/i ) )%(dif/i);

            if(temp==0)
            candidate = max(candidate , dif/i );
        }
    }
    return (candidate % mod);
}

  int main()
  {
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,n;
        cin>>a>>b>>n;

        //calc_factors(min(a,b));

        cout<<gcd(a,b,n)<<endl;
    }
  }