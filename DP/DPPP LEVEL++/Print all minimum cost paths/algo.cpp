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

    ll m,n;
    cin>>n>>m;
    ll arr[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
    }
    ll dp[n][m]={0};

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(i==n-1 && j==m-1){
                dp[i][j]=arr[i][j];
            }
            else if(i==n-1){
                dp[i][j]= arr[i][j] + dp[i][j+1];
            }
            else if(j==m-1){
                dp[i][j]= arr[i][j] + dp[i+1][j];
            }
            else{
                dp[i][j]= arr[i][j] + min(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    queue<dpp> que;
    que.push(create(0,0,""));

    while(que.size()){
        dpp rem=que.front();     
        que.pop();

        if(rem.x==n-1 && rem.y==m-1 ){
            cout<<rem.path;
            cout<<endl;
        }
        else if(rem.x==n-1){
            que.push(create(rem.x,rem.y+1, rem.path+"H"));
        }
        else if(rem.y==m-1){
            que.push(create(rem.x+1,rem.y, rem.path+"V"));
        }
        else{
            if(dp[rem.x][rem.y +1]<dp[rem.x+1][rem.y]){
                que.push(create(rem.x,rem.y+1, rem.path+"H"));
            }
            else if(dp[rem.x][rem.y +1] > dp[rem.x+1][rem.y]){
                que.push(create(rem.x+1,rem.y, rem.path+"V"));         
            }
            else{
                que.push(create(rem.x+1,rem.y, rem.path+"V"));
                que.push(create(rem.x,rem.y+1, rem.path+"H"));
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