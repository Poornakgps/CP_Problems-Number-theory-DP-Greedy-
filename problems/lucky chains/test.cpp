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
// void solve(){
//     ll n,flag=0;
//     cin>>n;
//     vector<ll> a;
//     map<ll,ll>m;
//     //unordered_map<ll,ll>um;
//     for(int i=0; i<n; i++){
//         ll k;
//         cin>>k;
//         a.push_back(k);
//         m[k]++;
//         //um[a[i]]=i;
//         if(k>n){
//             flag=1;
//         }
//     }
//     if(flag==1 ){
//         cout<<-1<<endl;
//         return;
//     }
//     ll dp[n]={0};
//     ll temp=1;
//     for(int i=0; i<n; i++){
 
//         if(dp[i]==0){
//             ll last=i;
//             dp[i]=temp;
//             for(int j=0; j<a[i]-1; j++){
//                 auto it=find(a.begin()+last+1,a.end(), a[i]);
//                 if(it==a.end()){
//                     cout<<-1<<endl;
//                     return;
//                 }
//                 dp[it-a.begin()]=temp;
//                 last= it-a.begin();  
//             }
//             temp++;
//         }
        
//     }
//     for(int i=0; i<n; i++){
//         if(dp[i]==0){
//             cout<<"-1\n";
//             return;
//         }
//     }
//     for(int i=0; i<n; i++){
//         cout<<dp[i]<<" ";
//     }
//     cout<<endl;
// }

void solve(){
    ll n,m;
    cin>>n>>m;
    ll event[m];
    ll task[m];
    ll a=1,b=0;
    for(int i=0; i<m; i++){
        cin>>event[i];
    }
    for(int i=0; i<m; i++){
        cin>>task[i];
    }
    ll score=0;
    ll k=0;
    // if(n==m){
    //     cout<<n<<endl;
    //     return;
    // }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    for(int i=0; i<n; i++){
        if(event[k]==i){
            if(task[k]=1){
                if(a>b){
                    score+=1;
                }
                else{
                    a=0;
                    b=0;
                }
            }
            else{
                if(b>a){
                    score+=1;
                }
                else{
                    a=0;
                    b=0;
                }
            }
            k++;
        }
        a++;
    }
    ll a2=0,b2=1;
    k=0;
    ll score2=0;
    for(int i=0; i<n; i++){
        if(event[k]==i){
            if(task[k]=1){
                if(a2>b2){
                    score2+=1;
                }
                else{
                    a2=0;
                    b2=0;
                }
            }
            else{
                if(b2>a2){
                    score2+=1;
                }
                else{
                    a2=0;
                    b2=0;
                }
            }
            k++;
        }
        b2++;
    }
    cout<<max(score,score2)<<endl;
    //cout<<score<<endl;
}
int main(){
    fastio();
    ll t;
    cin>>t;
    while(t--){ 
     solve(); 
    }
}