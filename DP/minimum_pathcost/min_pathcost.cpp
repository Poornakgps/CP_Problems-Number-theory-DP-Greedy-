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
    ll matrix[n][n]={0};
    
    for(int i=0; i<n; i++)
        for(int j=0 ; j<n; j++)
            cin>>matrix[i][j];

    ll dp[n][n]={0};

    dp[n-1][n-1]=matrix[n-1][n-1];

    for(int i=n-1; i>=0; i--)
    {

        for(int j=n-1; j>=0; j--)
        {
            if(i==n-1)
            {
                if(j==n-1){
                    continue;}
                dp[i][j]= matrix[i][j]+dp[i][j+1];
            }
            else if(j==n-1)
            {
                dp[i][j]=dp[i+1][j]+matrix[i][j];
            }
            else
            dp[i][j]=matrix[i][j] +min(dp[i][j+1],dp[i+1][j]);
        }
    }
    cout<<dp[0][0]<<endl;

}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}