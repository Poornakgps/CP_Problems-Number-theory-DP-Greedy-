#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;

// genral reecursive approach
// ll general(ll n)
// {
//     if(n==0)
//     return 0;
//     else if(n<0)
//     return 0;

//     ll nm1=general(n-1);
//     ll nm2=general(n-2);
//     ll nm3=general(n-3);

//     return (nm1+nm2+nm3);
// }

// memorization (topdown)
ll countpaths_dpm( ll n, ll dp[])
{
    if(n==0){
    return 1;}

    else if(n<0){
    return 0;}

    if(dp[n]>0)
    {
        return dp[n];
    }
    ll nm1=countpaths_dpm(n-1,dp);
    ll nm2=countpaths_dpm(n-2,dp);
    ll nm3=countpaths_dpm(n-3,dp);

    dp[n]=nm1+nm2+nm3;

    return (dp[n]);
}

//tabulation (bottomup)
ll coutntpaths_dpt(ll n)
{
    ll dp[n+1];
    dp[0]=1;

    for(int i=1; i<=n; i++)
    {
        if(i==1)
        {
            dp[i]=dp[i-1];
        }
        else if(i==2)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        else
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }

    return dp[n];
}


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll dp[n+1]={0};

        //cout<<general(n)<<endl;

        cout<<countpaths_dpm(n,dp)<<endl;
        cout<<coutntpaths_dpt(n)<<endl;
    }
}