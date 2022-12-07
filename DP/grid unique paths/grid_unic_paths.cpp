#include<bits/stdc++.h>
#include<algorithm>

#define ll long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462

using namespace std;
//  2d vector
//  vector<vector<int>> v(num_row, row) ;
//  vector<vector<int>> v(num_row, vector<int> (num_col, 0)) ;
//  vector<vector<int>> v {{1, 0, 1}, {0, 1}, {1, 0, 1}}; 
//  1 0 1 
//  0 1 
//  1 0 1 

class Algorithm{

    public:
        ll m,n,ans;
        //introducing constructor
        Algorithm(){
            cin>>n>>m;

            ll dp[n][m]={0};
            if(m==1 || n==1){
                ans=1;
                _exit;  // to stop the constructor like break in loop
            }

                dp[n-2][m-1]=1;

                for(int i=0; i<m; i++ )
                    dp[n-1][i]=1;

                for(int i=0; i<n-1; i++)
                    dp[i][m-1]=1;

                ll temp;
                for(int i=n-2; i>=0; i--)
                {
                    for(int j=m-2; j>=0; j--)
                    {                   
                        dp[i][j]=dp[i+1][j]+dp[i][j+1];
                    }
                }
                ans=dp[0][0];
        }
        void print_ans()
        {
                cout<<ans<<endl;
        }
};

int main()
{
    ll t;
    cin>>t;

    while(t--)
    {
        Algorithm object;
        object.print_ans();
    }
}