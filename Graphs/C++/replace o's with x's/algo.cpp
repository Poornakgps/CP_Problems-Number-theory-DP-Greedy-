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

    int step; // path
    int x;
    int y;
};

struct graph create(int x, int y, int step ){
    struct graph temp;
    temp.x=x;
    temp.y=y;
    temp.step= step; 
    return temp;
}

class Solution{
    public:
        void dfs(int row,int col, vector<vector<int>> &vis, vector<vector<char>> grid ){
            vis[row][col]=1;
            int n=grid.size();
            int m=grid[0].size();
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0; i<4; i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]=='O'&& !vis[nrow][ncol]){
                    dfs(nrow,ncol,vis,grid);
                }
            }

        }
        vector<vector<char>>fill(int n, int m,vector<vector<char>>grid){

            vector<vector<int>> vis(n, vector<int>(m,0));
            vector<vector<char>> v(n, vector<char>(m,'O'));
            for(int i=0; i<m; i++){
                if(grid[0][i]=='O' && vis[0][i]==0){
                    dfs(0,i,vis,grid);
                }
                if(grid[n-1][i]=='O' && vis[n-1][i]==0){
                    dfs(n-1,i,vis,grid);
                }
            }

            for(int i=0; i<n; i++){
                if(grid[i][m-1]=='O' && vis[i][m-1]==0){
                    dfs(i,m-1,vis,grid);
                }
                if(grid[i][0]=='O'&& vis[i][0]==0){
                    dfs(i,0,vis,grid);
                }
            }
            vector<vector<char>> ans(n, vector<char>(m,'O'));
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(vis[i][j]==0){
                        ans[i][j]='X';
                    }
                    else{
                        ans[i][j]='O';
                    }
                }
            }
            return ans;
        }
};
int main(){
    fastio();
    ll t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> grid(n, vector<char>(m,'O'));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution obj ;
        vector<vector<char>> ans=obj.fill(n,m,grid);
        for(auto i:ans){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
}