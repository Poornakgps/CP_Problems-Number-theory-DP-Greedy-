#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
ll F[1000001];

using namespace std;

int power(int x, int n)
{
    ll res=1;

    while(n)
    {
        if(n%2)
        {
            res=(1ll*res*x)%mod;
            n--;
        }
        else{

            n=n/2;
            x = (1ll*x*x)%mod;
        } 

    }
    return res%mod;
}

int C(int n, int k)
{
   if(k>n) return 0;

   int res= F[n];
   res=( res *1ll* power(F[k] , mod-2) ) %mod; // instead of dividing we can find the inverse of 1/k! modulo P 
   res= (res*1ll* power(F[n-k] , mod-2) )%mod;

   return res;
}

int main()
{
    ll t;
    cin>>t;
    
    F[0]=F[1]=1;
    for(int i=2;i<=1000000; i++)
    {
        F[i]=(1ll*F[i-1]*i)%mod;  // finding factorial
    }
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        //cout<<F[n]%mod<<endl;
        cout<<C(n,k)<<endl;
    }
    
}