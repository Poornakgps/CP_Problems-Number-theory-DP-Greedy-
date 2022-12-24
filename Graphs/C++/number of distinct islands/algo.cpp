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

    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis ,vector<pair<int,int>> &v, int row0, int col0 ){
        vis[row][col]=1;
        v.push_back({row-row0, col-col0});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow=row+delrow[i];
            int ncol=col + delcol[i];

            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol, grid, vis , v, row0, col0);
            }
        }

    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>v;

                    dfs(i,j,grid,vis,v,i,j);

                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }
        Solution obj;
        cout<<obj.countDistinctIslands(grid)<<endl;
    }
}