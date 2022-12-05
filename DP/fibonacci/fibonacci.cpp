#include<bits/stdc++.h>

#define ll long long

using namespace std;

// without dp basic recurssion
// ll fib(ll n)\
// {
//     if(n==0 || n==1)
//     return 1;

//     return fib(n-1)+fib(n-2);
// }

//with dp bottom up method which means recursive
ll fibmemorizing(ll n, ll dp[])
{
    if(n==0 || n==1)
    return 1;

    if(dp[n]!=0)
    return dp[n];

    ll fibm1=fibmemorizing(n-1,dp);
    ll fibm2=fibmemorizing(n-2,dp);

    dp[n]=fibm1+fibm2;

    return (dp[n]);
}
//tabulation method topbottom
int fibtabulation(int n)
{
    int f[n + 1];
    int i;
    f[0] = 0;
    f[1] = 1;
    for (i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
 
    return f[n];
}

int  main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll dp[n+1]={0};

        cout<<fibmemorizing(n,dp)<<endl;
    }
}
