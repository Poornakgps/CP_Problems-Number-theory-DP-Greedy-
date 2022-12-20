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
class Solution{
    public:
    // void dfs(ll node, vector<ll>adj[], ll vis[], vector<ll> &ls){
    //     vis[node]=1;

    //     ls.push_back(node);
    //     for(auto it: adj[node]){
    //         if(!(vis[it])){
    //             dfs(it,adj,vis,ls);
    //         }
    //     }
    // }

    void dfs(int row, int col, vector<vector<int>> &res, vector<vector<int>> &image, int newColor, int delrow[], int delcol[], int incolor){

        res[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0; i<4; i++){
            int nrow=row + delrow[i];
            int ncol=col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==incolor && res[nrow][ncol]!=newColor){
                dfs(nrow,ncol,res,image, newColor, delrow, delcol, incolor);
            }   
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor){

        int in_color=image[sr][sc];
        vector<vector<int>>res=image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        dfs(sr,sc,res,image,newColor, delrow, delcol, in_color);
        return res;
    }
    // void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){

    //     vis[row][col]=1;
    //     queue<pair<int,int>> q;
    //     q.push({row,col});
    //     int n=grid.size();
    //     int m=grid[0].size();

    //     while(!q.empty()){
    //         int row=q.front().first;
    //         int col=q.front().second;
    //         q.pop();

    //         // traverse through its neighbors and mark as 1

    //         for(int delrow=-1; delrow<=1;delrow++ ){
    //             for(int delcol=-1; delcol<=1; delcol++){
    //                 int nrow = row + delrow;
    //                 int ncol = col + delcol;
    //                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
    //                     vis[nrow][ncol]=1,q.push({nrow,ncol});
    //             }
    //         }
    //     }

    // }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>>image(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for(auto i: ans){
            for(auto j: i)
                cout << j <<" ";
            cout << "\n";
        }
    }
    return 0;
 
}
