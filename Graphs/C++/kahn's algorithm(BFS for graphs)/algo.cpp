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
//kahns algo for bfs
void solve(){
    ll n,e;
    cin>>n>>e;
    vector<ll> adj[n];
    ll maxsize=0;
    ll indegree[n]={0};
    for(int i=0; i<e; i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    // for(int i=0; i<n; i++){
    //     cout<<indegree[i]<<" ";
    // }
    // cout<<endl;
    deque<ll> que;
    vector<ll> ans;
    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            que.push_back(i);
        }
    }
    while(que.size()){
        ll curr_node=que.front();
        ans.push_back(curr_node);
        que.pop_front();    
        for(auto it : adj[curr_node]){
            if(indegree[it]!=0){
                indegree[it]--;
                if(indegree[it]==0)
                    que.push_back(it);   
            }
        }

    }
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;

}



int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}