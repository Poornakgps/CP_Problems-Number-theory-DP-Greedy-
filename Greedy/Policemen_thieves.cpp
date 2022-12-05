#include <bits/stdc++.h>
#define ll long lone
using namespace std;

vector<ll> police,thieves;

void algo(ll n , ll k)
{
    ll p=0,t=0,res=0;

    for(int i=0; i<n; i++)
    {
        if(abs(thieves[t]-police[p])>=k)
        {
            p++,t++,res++;
        }
        else if(thieves[t]<police[p])
        {
            t++;
        }
        else
        p++;
    }
    cout<<res<<endl;
}

int main()
{
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        
        cin.ignore();

        for(int i=0; i<n; i++)
        {
            char c;

            if(c=='p')
            police.push_back(i+1);
            else
            thieves.push_back(i+1);
        }
        algo(n,k);
    }
    return 0;
}