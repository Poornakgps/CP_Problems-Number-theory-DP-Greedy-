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
int dpp(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp){

    if(ind1<0 ||ind2<0){
        return 0;
    }
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

    if(s1[ind1] == s2[ind2]){
        //cout<<ind1<<" "<<ind2<<endl;
        return dp[ind1][ind2] = 1 + dpp(s1,s2,ind1-1,ind2-1,dp);
    }
    
    else 
        return dp[ind1][ind2] = 0 + max(dpp(s1,s2,ind1,ind2-1,dp),dpp(s1,s2,ind1-1,ind2,dp));
}
void solve(){
    int n;
	cin>>n;
	string s1 ;
	cin>>s1;
	string s2=s1;
	reverse(s1.begin() , s1.end() );
    //cout<<s1<<" "<<s2<<endl;
	vector<vector<int>> py(n+1 , vector<int>(n+1 , 0));
	    
	for(int i =1 ; i<=n ; i++){
	    for(int j =1 ; j<=n ; j++){
	        if( s2[i-1]== s1[j-1]){
	            py[i][j] = 1+ py[i-1][j-1];
	        }
	        else{
	            py[i][j] = max(py[i-1][j] , py[i][j-1]);
	        }
	            
	    }
	        
	}
	cout<< py[n][n]/2<<endl; 
}
int main(){
    fastio();
    ll t;
    cin>>t;
    while(t--){ 
     solve(); 
    }
}