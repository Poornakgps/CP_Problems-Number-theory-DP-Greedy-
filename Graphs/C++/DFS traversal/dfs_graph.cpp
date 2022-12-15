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

// SC: O(N)(nodes in dfs ) ,  O(N)(for visited) , O(N)(recursion stact space) 
// TC: O(N) + O(2*E)

int gcd(int a, int b){ if(b==0) return a; else return gcd(b,a%b); }

class DFS_graph{
    
    private:
        void dfs(ll node, vector<ll>adj[], ll vis[], vector<ll> &ls){

            vis[node]=1;
            ls.push_back(node);
            /*Traversing all neighbours */

            for(auto it:adj[node]){
                //cout<<it<<endl;
                if(!vis[it]){
                    dfs(it,adj,vis,ls);
                    //cout<<it<<endl;
                }
            }

        }

    public:
        void Graph();
        ll m,n;
        vector<ll> dfs0Graph(ll n, vector<ll>adj[]){
            ll vis[n]={0};    //visited list of nodes graph
            int start=1;
            vector<ll> ls;  // to store 
            dfs(start, adj,vis,ls);
            return ls;
        }
};
void DFS_graph::Graph (){
    vector<ll> dfs;
    cin>>n>>m;  //number of nodes and edges
    vector<ll> adj[n+1];
    for(int i=0; i<m; i++){
        ll a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs=dfs0Graph(n,adj);
    for(auto it: dfs){
        cout<<it<<" ";
    }
    cout<<endl;
}
int main(){

    DFS_graph object;
    object.Graph();
}