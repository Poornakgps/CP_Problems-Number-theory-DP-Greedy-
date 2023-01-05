#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MOD1 998244353

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

void lcs_path(string s1, string s2) {
    
    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    int len = dp[n][m];
    int i = n;
    int j = m;

    int index = len - 1;
    string str = "";
    for (int k = 1; k <= len; k++) {
        str += "$"; // dummy string
    }

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            str[index] = s1[i - 1];
            index--;
            i--;
            j--;
        } else if (s1[i - 1] > s2[j - 1]) {
            i--;
        } else j--;
    }
    cout << str;
}

void solve(){
    int n;
    string s1,s2;
    cin>>s1>>s2;
    lcs_path(s1,s2);
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}