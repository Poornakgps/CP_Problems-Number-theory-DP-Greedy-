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
        ll n,ans=0;
        Algorithm();
        ~Algorithm();
};

Algorithm::Algorithm(){

    cin>>n;
    ll array[n][n];

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){
            ll temp;
            cin>>temp;
            array[i][j] = temp;
        }
    }
    vector<ll> dp(n,0);
    ll maxx=0;
    for(int i=n-2; i>=0; i--){

        for(int j=0 ; j<n; j++){

            if(j!=0 && j!=n-1 ){
                    
                array[j][i]=array[j][i] + max( array[j][i+1] , max( array[j-1][i+1], array[j+1][i+1] ));
                // cout<<array[j][i]<<" ";
                if(i==0){
                    maxx=max(maxx,array[j][i]);
                }
            }
            else if(j==0 ){
                
                array[j][i]=array[j][i]+max(array[j][i+1], array[j+1][i+1]);
                // cout<<array[j][i]<<" ";
                if(i==0){
                    maxx=max(maxx,array[j][i]);
                
                }
            }
            else if( j==n-1){
                array[j][i]=array[j][i]+max(array[j][i+1], array[j-1][i+1]);
                // cout<<array[j][i]<<" ";
                if(i==0){
                    maxx=max(maxx,array[j][i]);
                    
                }
            }
        }
        cout<<endl;

    }
    ans=maxx;
}

Algorithm::~Algorithm(){

    cout<<ans<<endl;
}

int main(){

    fastio(); 

    ll t;
    cin>>t;
    while(t--){
        Algorithm object;
    }
    return 0;
}
