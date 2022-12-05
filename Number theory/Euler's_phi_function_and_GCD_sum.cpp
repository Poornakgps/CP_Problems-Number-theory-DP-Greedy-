#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Eulers phi function and gcd sum
// motto is sum of all GCD(i,n) 1<=i<=n
ll phi[1000001];

// euclid's algorithm
int GCD (int a, int b)  
{
    if(b==0)
    return a;

    return GCD(b,a%b);
}

/*
void brute_force_method(int n)
{
    ll ans=0;
  
    for(int i=1; i<=n; i++)
    {
        ans+=GCD(i,n);
    }
    cout<<ans<<endl;
   //Time Complexity= O(Q* nlog(n))   //Q queries
}
*/
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
int getcount(int d , int n)
{
    return phi[n/d];
}

int sum_gcd(int n)
{
    ll ans=0;

    for(int i=1; i*i<=(n); i++)
    {
        if(!(n%i))
        {
            int d1=i;
            int d2=n/i;
            //cout<<d1<<" "<<d2<<endl;

            ans += d1*getcount(d1,n);

            if(d1!=d2)   /// for perfect square case
            ans+=d2*getcount(d2,n);
        }
    }
    return ans;
}
int main()
{
    //overall time complexity is O(nlog(log(n) + t*sqrt(n))
    initialization(1000000);
    ll t; 
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        //brute_force_method(n);
        cout<<sum_gcd(n)<<endl;
      
    }
}