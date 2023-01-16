#include<bits/stdc++.h>

#define ll long long
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

ll first_prime_factor[10000001];
bool is_prime[10000001]={false};
void sieve()
{

    ll maxN=10000000;

    for(int i=2; i<=maxN; i++)
    {
        if(!first_prime_factor[i])
        for(int j=i; j<=maxN; j+=i){
            first_prime_factor[j]=i;
        }
    }

}
// void solve(){

//     ll x,y;
//     cin>>x>>y;
//     if(__gcd(x,y)!=1){
//         cout<<0<<endl;
//         return;
//     }
//     if(x%2==y%2){
//         cout<<1<<endl;
//         return;
//     }
//     ll d=y-x;
    
//     ll ans=1e9;
// 	for(;d>1;d/=first_prime_factor[d])
// 	{
//         if(first_prime_factor[d]<=1){
//             continue;
//         }
// 		ans=min(ans,((x-1)/first_prime_factor[d]+1)*first_prime_factor[d]-x);
// 	}
//     if(ans==1e9){
//         cout<<-1<<endl;
//         return;
//     }
//     else{
//         cout<<ans<<endl;
//     }
//     return;
// }

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    ll b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    ll maxp1=a[n-1],minp1=a[n-1];
    ll maxp2=b[n-1],minp2=b[n-1];
    ll ans1=0,ans2=0,ans3=0,ans4=0;

    for(int i=n-2; i>=0; i--){
        if(a[i]>=maxp1 && b[i]>= maxp1){
            maxp1=min(a[i],b[i]);
        }
        else if(a[i]<=minp1 && b[i]<=minp1){
            minp1=max(a[i],b[i]);
        }
        else if((a[i]<minp1 && b[i]>maxp1) ||  (a[i]<minp1 && b[i]>maxp1) ){
            if((a[i]<minp1 && b[i]>maxp1)){
                ll temp1=maxp1-a[i];
                ll temp2=b[i]-minp1;
                if(min(temp1,temp2)==temp1 && temp1!=temp2){
                    minp1=a[i];
                }
                else{
                    maxp1=b[i];
                }
            }
            else{
                ll temp1=maxp1-b[i];
                ll temp2=a[i]-minp1;
                if(min(temp1,temp2)==temp1 && temp1!=temp2){
                    minp1=b[i];
                }
                else{
                    maxp1=a[i];
                }     
            }
        }
        ans1=maxp1-minp1;

        if(a[i]>=maxp2 && b[i]>= maxp2){

            maxp2=min(a[i],b[i]);
        }
        else if(a[i]<=minp2 && b[i]<=minp2){
            minp2=max(a[i],b[i]);
        }
        else if((a[i]<minp2 && b[i]>maxp2) ||  (a[i]<minp2 && b[i]>maxp2) ){
            if((a[i]<minp2 && b[i]>maxp2)){
                ll temp1=maxp2-a[i];
                ll temp2=b[i]-minp2;
                if(min(temp1,temp2)==temp1 && temp1!=temp2){
                    minp2=a[i];
                }
                else{
                    maxp2=b[i];
                }
            }
            else{
                ll temp1=maxp2-b[i];
                ll temp2=a[i]-minp2;
                if(min(temp1,temp2)==temp1 && temp1!=temp2){
                    minp2=b[i];
                }
                else{
                    maxp2=a[i];
                }     
            }
        }
        ans2=maxp2-minp2;
        // cout<<i<<endl;
        // cout<<maxp1<<" "<<minp1<<endl;
        // cout<<maxp2<<" "<<minp2<<endl;
    }
    cout<<min(ans1,ans2)<<endl;
}

int main(){
    fastio();
    sieve();
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}