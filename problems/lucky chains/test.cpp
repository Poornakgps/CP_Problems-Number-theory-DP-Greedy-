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
// void solve(){
//     int n;
// 	cin>>n;
// 	string s1 ;
// 	cin>>s1;
// 	string s2=s1;
// 	reverse(s1.begin() , s1.end() );
//     //cout<<s1<<" "<<s2<<endl;
// 	vector<vector<int>> py(n+1 , vector<int>(n+1 , 0));
	    
// 	for(int i =1 ; i<=n ; i++){
// 	    for(int j =1 ; j<=n ; j++){
// 	        if( s2[i-1]== s1[j-1]){
// 	            py[i][j] = 1+ py[i-1][j-1];
// 	        }
// 	        else{
// 	            py[i][j] = max(py[i-1][j] , py[i][j-1]);
// 	        }
	            
// 	    }
	        
// 	}
// 	cout<< py[n][n]/2<<endl; 
// }

// void solve(){
//     ll n,m,k;
//     cin>>n>>m>>k;

//     ll a[m];
//     ll op1=n/k;
//     ll rem= n%k;
//     bool div=n%k;
//    // cout<<div<<endl;
//     bool ans=true;
//     for(int i=0; i<m; i++){
//         cin>>a[i];
//         if(a[i]>op1){
//             if(a[i]>(op1+ div) || rem==0){
//                 ans=false;
//             }
//             rem--;
//         }
             
//     }
//     if(ans){
//         cout<<"YES\n";
//     }
//     else{
//         cout<<"NO\n";
//     }

// }
// void solve1(){
//         int n, m, k;
//     cin >> n >> m >> k;
//     int x;
//     bool yes = true;
//     int r = n % k;
//     int lim1 = n / k, lim2 = lim1 + (r == 0 ? 0 : 1);
//     cout<<lim2<<endl;
//     for (int i = 0; i < m; ++i) {
//       cin >> x;
//       if (x > lim1) {
//         if (x > lim2 || --r < 0)
//           yes = false;
//       }
//     }
//     if (yes)
//       cout << "YES\n";
//     else
//       cout << "NO\n";
//   }
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    map<int,int> m;
    ll evens=0,odds=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]%2){
            odds++;
        }
        else{
            evens++;
        }
        m[a[i]]++;
    }
    if(odds>1 && evens>1){
        cout<<"NO\n";
        return;
    }
    if(m.size()<n){
        cout<<"NO\n";
        return;
    }
    ll flag=0;
    map<ll,ll>m2;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++ ){
            m2[__gcd(a[i],a[j])]++;
        }
    }
    if(m2.size()%2==0 || m2.size()==1 )
        cout<<"YES\n";
    else{
            cout<<"NO\n";
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