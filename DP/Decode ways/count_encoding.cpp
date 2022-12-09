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

void solve(){

    ll n;
    cin>>n;

    string str;
    cin>>str;
    ll dp[n]={0};
    dp[0]=1;

    for(int i=1; i<n; i++){
        if(str[i-1]=='0' && str[i]=='0'){
            dp[i]=0;
        }
        else if(str[i-1]=='0' && str[i]!='0'){
            dp[i]=dp[i-1];
        }
        else if(str[i-1]!='0' && str[i]=='0'){

            if(str[i-1]=='2' || str[i-1]=='1'){
                dp[i] = (i>=2 ? dp[i-2] : 1);   //if i >2 dp[i-2] else 1
            }
            else {
                dp[i]=0;
            }
        }
        else {
            dp[i]=dp[i-1];
            //cout<<stoi(str.substr(i-1,i))<<endl;
            if(int(str[i-1] -'a')*10 + int(str[i]-'a')<=26){
                
                dp[i]= dp[i] +  (i >=2 ? dp[i-2] : 1);  //if i >2 dp[i-2] else 1
            }
        }
       // cout<<dp[i]<<endl;
    }
    cout<<dp[n-1]<<endl;

}

int main(){

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}