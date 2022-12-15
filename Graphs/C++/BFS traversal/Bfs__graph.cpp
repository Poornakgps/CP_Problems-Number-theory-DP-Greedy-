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

int gcd(int a, int b){ if(b==0) return a; else return gcd(b,a%b); }

// time complexity :: O(N) for queue and O(2*E) sum_degree of all nodes = 2*Edges
class BFS_Graph{

    public:
        ll n,m;
        vector<ll> bfs;
        void Graph();
        vector<ll> bfs0Graph( vector<ll>adj[]);
        void print_Graph_Bfs(vector<ll> bfs);
};

void BFS_Graph::Graph (){
    vector<ll> bfs;
    cin>>n>>m;  //number of nodes and edges
    vector<ll> adj[n+1];
    for(int i=0; i<m; i++){
        ll a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs=bfs0Graph(adj);
    for(auto it: bfs){
        cout<<it<<" ";
    }
    cout<<endl;
}

vector<ll> BFS_Graph::bfs0Graph(vector<ll> adj[]){   // v is number of nodes

    ll vis[n+1]={0};

    queue<ll> q;
    q.push(1);  // if we are keeping 1 as starting point
    vis[1]=1;
    vector<ll> bfs;
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){

            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}



int main(){

    fastio();
    BFS_Graph object1;
    object1.Graph();
}