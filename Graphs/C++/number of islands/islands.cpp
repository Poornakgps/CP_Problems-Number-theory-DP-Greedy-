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
// number of islands @graphs
    // run code in terminal...
class solution{
    public:
    void dfs(ll node, vector<ll>adj[], ll vis[], vector<ll> &ls){
        vis[node]=1;

        ls.push_back(node);
        for(auto it: adj[node]){
            if(!(vis[it])){
                dfs(it,adj,vis,ls);
            }
        }
    }
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){

        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            // traverse through its neighbors and mark as 1

            for(int delrow=-1; delrow<=1;delrow++ ){
                for(int delcol=-1; delcol<=1; delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
                        vis[nrow][ncol]=1,q.push({nrow,ncol});
                }
            }
        }

    }


    int numIslands(vector<vector<char>> &grid){
        /*-Code-*/
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!(vis[i][j]) && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis, grid);
                }
            }
        }
        return cnt;
    }

};


int main(){
    ll t;
    cin>>t;
    fastio();

    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<vector<char>> grid(n,vector<char>(m,'#'));
        cin.ignore();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
                //cin.ignore();
            }
        }
        solution obj;
        ll ans=obj.numIslands(grid);
        cout<<ans<<endl;
    }
    return 0;
}