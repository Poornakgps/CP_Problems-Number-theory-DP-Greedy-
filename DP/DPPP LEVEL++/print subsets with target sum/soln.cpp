#include<bits/stdc++.h>
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
// print all subsets having target sum  printing indexes
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
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll tar;
    cin>>tar;

    bool dp[n+1][tar+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=tar+1; j++){

            if(i==0 && j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
            else if(j==0){
                dp[i][j]=true;
            }
            else{
                if(j>=arr[i-1])
                    dp[i][j]= (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
                else
                     dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][tar]<<endl;
    deque<dpp> que;
    que.push_back(create(n,tar,""));

    while(que.size()){
        dpp rem=que.front();
        que.pop_front();

        if(rem.x==0 || rem.y==0){
            cout<<rem.path<<endl;
        }else{
            if(rem.y>=arr[rem.x-1]){
                bool inc= dp[rem.x -1][rem.y-arr[rem.x-1]];
                if(inc){
                    que.push_front(create(rem.x-1, rem.y-arr[rem.x-1], rem.path +to_string(rem.x-1) +" "));
                }
            }
            bool exc= dp[rem.x -1][rem.y];
            if(exc){
                que.push_front(create(rem.x-1, rem.y, rem.path));
            }

        }
    }
}
int main(){

    fastio();
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}