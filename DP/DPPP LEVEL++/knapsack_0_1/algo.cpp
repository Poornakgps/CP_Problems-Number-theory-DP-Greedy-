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

int gcd(int a, int b){ if(b==0) return a; else return gcd(b,a%b); }  


int power(ll x, ll y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return ((temp %MOD1)* temp)%MOD1;
    else
        return (x * (temp * temp)%MOD1)%MOD1;
}

struct dpp{

    string path; // path
    ll x;
    ll y;
};

struct dpp create(ll x, ll y, string path){
    struct dpp temp;
    temp.x=x;
    temp.y=y;
    temp.path= path; 
    return temp;
}

void solve(){

    ll n;
    cin>>n;
    ll values[n],weight[n];
    for(int i=0; i<n; i++)
        cin>>values[i];

    for(int i=0; i<n; i++)
        cin>>weight[i];

    ll maxweight;
    cin>>maxweight;

    ll dp[n+1][maxweight+1]={0};


    for(int i=0; i<(n+1); i++){

        for(int j=0; j<(maxweight+1); j++){

            if(i==0|| j==0){
                dp[i][j]=0;
                continue;
            }
            if(j>=weight[i-1]){

                ll rcap=j-weight[i-1];

                if(dp[i-1][rcap] + values[i-1]> dp[i-1][j]){
                    dp[i][j]=dp[i-1][rcap] + values[i-1];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }

            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][maxweight]<<endl;
    deque<dpp>que;
    que.push_back(create(n, maxweight, ""));

    while(que.size()){
        dpp rem=que.front();
        que.pop_front();

        if(rem.x==0 || rem.y==0){
            cout<<rem.path<<endl;
        }
        else{
            ll exc=dp[rem.x-1][rem.y];
            ll inc=dp[rem.x-1][rem.y-weight[rem.x-1]] +values[rem.x-1];

            if(inc==dp[rem.x][rem.y]){
                que.push_front(create(rem.x-1, rem.y-weight[rem.x-1],to_string(rem.x-1)+" "+ rem.path));
            }

            if(exc==dp[rem.x][rem.y]){
                que.push_front(create(rem.x-1, rem.y, rem.path));
            }

        }
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}