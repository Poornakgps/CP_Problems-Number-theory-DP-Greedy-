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
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        deque<graph> que;

         int n=grid.size();
         int m=grid[0].size();
         int vis[n][m]={0};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        que.push_back(create(i,j));
                        vis[i][j]=1;
                    }
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(que.size()){
            int row=que.front().x;
            int col=que.front().y;
            que.pop_front();
            for(int i=0; i<4; i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    que.push_back(create(nrow,ncol));
                    vis[nrow][ncol]=1;
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n, vector<int>(m));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }
        Solution obj;
        cout<<obj.numberOfEnclaves(grid)<<endl;
    }
}