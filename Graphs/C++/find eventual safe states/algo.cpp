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

struct graph{
    int x;
    int y;
};

struct graph create(int x, int y ){
    struct graph temp;
    temp.x=x;
    temp.y=y;
    return temp;
}

class Solution {
  public:
    bool dfscheck(int node, vector<int> adj[], int vis[], int pathvis[], int check[]){
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        for(auto it: adj[node]){
        if(!vis[it]){
            if(dfscheck(it,adj,vis,pathvis,check)==1){
                return true;
            }      
        }
        else{
            if(pathvis[it]){
                return true;  // presence of cycle
            }
        }
      }
      check[node]=1;
      pathvis[node]=0;
      return false;  // absence of cycle
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathvis[V]={0};
        int check[V]={0};
        vector<int> safenodes;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfscheck(i,adj,vis,pathvis,check);
            }
        }
        for(int i=0; i<V; i++) {
            if(check[i]) safenodes.push_back(i);
        }
        return safenodes;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;

        vector<int>adj[V];
        for(int i=0; i<E; i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        Solution obj;

        vector<int> Safenodes=obj.eventualSafeNodes(V,adj);

        for(auto i : Safenodes){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}