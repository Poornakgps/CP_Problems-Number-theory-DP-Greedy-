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

  // from input 1-3 1 province and 2 is 2nd province
using namespace std;

//int gcd(int a, int b){ if(b==0) return a; else return gcd(b,a%b); }

class Solution {
  private:
        void dfs(ll node, ll vis[], vector<ll> lst[]){
            vis[node]=1;
            for(auto it: lst[node]){
                if(!vis[it]){
                    dfs(it, vis, lst);
                }
            }
        }
    public:
        ll numProvinces(vector<vector<ll>>adj, ll V){
            vector<ll> lst[V];

            for(int i=0; i<V; i++){
                for(int j=0; j<V; j++){

                    if(adj[i][j]==1 && i!=j){
                        lst[i].push_back(j);
                        lst[j].push_back(i);
                    }
                }
            }
            ll vis[V]={0};
            ll cnt=0;
            for(int i=0; i<V; i++){

                if(!vis[i]){
                    cnt++;
                    dfs(i,vis,lst);
                    
                }
            }
            return cnt;
        }
};

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll V,x;
        cin>>V;

        vector<vector<ll>> adj;

        for(int i=0; i<V; i++){
            vector<ll> temp;
            for(int j=0; j<V; j++){
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        } 
        Solution ob;
        cout<<ob.numProvinces(adj,V)<<endl;;
    }

}