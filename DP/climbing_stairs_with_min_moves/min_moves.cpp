#include<bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462

using namespace std;


void solve()
{
    ll n;
    cin>>n;
    ll jumps[n];
    for(int i=0; i<n; i++)
    cin>>jumps[i];
    
    ll dp[n+1]={0};
    dp[n]=0;

    for(int i=n-1; i>=0; i--)
    {
        if(jumps[i]>0){
            ll minn=MOD;
            for(int j=1; j<=jumps[i] && i+j<n+1; j++)
            {
                if(dp[i+j]!=0 || i+j==n-1)
                    minn=min(dp[i+j],minn);
            }
            if(minn!=MOD)
                dp[i]=minn+1;
                //cout<<dp[i]<<" ";
        }
    }
    cout<<endl<<dp[0]<<endl;

}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}