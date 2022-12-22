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

// time : O(N + 2E) + O(N) 
// space : O(N)+O(N)
class Solution{
    public:
    /* bfs
        bool detect(int V, vector<int> adj[], int vis[]){
            vis[V]=1;
            queue<pair<int ,int>> que;
            que.push({V,-1});

            while(que.size()){
                int node= que.front().first;
                int parent=que.front().second;
                que.pop();
                for(auto it : adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        que.push({it,node});
                    }
                    else if(parent != it){
                        return true;
                    }
                }
            }
        }
    */  
        // dfs very effecient
        // SC: O(N) + O(N)  TC: O(N+2E) +O(N) 

        bool detect(int node, int parent, vector<int> adj[], int vis[]){
            vis[node]=1;
            for(auto it: adj[node]){
                if(!vis[it]){
                    if(detect(it,node,adj,vis)) return true;
                }
                else if(it!=parent){
                    return true;
                }
            }
            return false;
        } 
        bool isCycle(int V, vector<int>adj[]){
            int vis[V]={0};

            for(int i=0; i<V; i++){
                if(!vis[i]){
                    if(detect(i,-1,adj,vis))
                    return true;
                }
            }
            return false;
        }
        
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int V,e;
        cin>>V>>e;
        vector<int>adj[V];
        for(int i=0; i<V; i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans=obj.isCycle(V,adj);
        if(ans){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}