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

class Solution{
    private:
        void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]){
            vis[node]=1;

            for(auto it : adj[node]){
                if(!vis[it]) dfs(it,vis,st,adj);
            }
            st.push(node);
        }
    public:
        vector<int> topoSort(int V, vector<int> adj[]){
            int vis[V]={0};

            stack<int> st;

            for(int i=0; i<V; i++){
                if(!vis[i]){
                    dfs(i,vis,st,adj);
                }
            }
            vector<int> ans;
            while(st.size()){
                ans.push_back(st.top());
                st.pop();
            }
            return ans;
        }
};
int check(int V, vector<int> &res, vector<int> adj[]){ // checking whether user inputed graph is a toposorted graph or not

    if(V!=res.size()){
        return 0;
    }
    vector<int> map(V,-1);

    for(int i=0; i<V; i++){
        map[res[i]]=i;
    }

    for(int i=0; i<V; i++){
        for(auto v : adj[i] ){
            if(map[i]>map[v]) return 0;
        }
    }
    return 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>E>>V;

        vector<int>adj[V];
        for(int i=0; i<E; i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        Solution obj;

        vector<int> res=obj.topoSort(V,adj);

        cout<<check(V,res,adj)<<endl;
    }
}