#include<bits/stdc++.h>
#include<algorithm>
#include <vector>

#define ll long long
#define MOD 1000000007
#define MOD1 998244353
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0)


using namespace std;

class Algorithm{

    public:
        bool ans=0;
        Algorithm();// construcor
        Algorithm(ll n); // paramaterized constructor 
        ~Algorithm(); //destructor
};

// Algorithm::Algorithm()
// {
//     cin>>n;
//     cout<<1<<endl;
//     Algorithm(n);
// }

Algorithm::Algorithm(ll n){

    ll arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    ll tar;
    cin>>tar;

    bool dp[n+1][tar+1]={0};


    for(int i=0; i<(n+1); i++){
        for(int j=0; j<(tar+1); j++){

            if(i==0 && j==0)
               dp[i][j]=true;//,cout<<1<<" "; 
             
            else if(i==0)
                dp[i][j]=false;//,cout<<0<<" ";
            
            else if(j==0)
                dp[i][j]=true;//,cout<<1<<" ";

            else{
                if(j>=arr[i-1])
                    dp[i][j]= (dp[i-1][j] || dp[i-1][j-arr[i-1]]);//cout<<dp[i][j]<<" ";
                else
                     dp[i][j]=dp[i-1][j];//cout<<dp[i][j]<<" ";
            }
        }
        //cout<<endl;
    }
    ans=dp[n][tar];

}
Algorithm::~Algorithm(){

    cout<<ans<<endl;
}
int main()
{
    fastio();
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        Algorithm object(n); // will call paramaterized constructor
    }
    
}