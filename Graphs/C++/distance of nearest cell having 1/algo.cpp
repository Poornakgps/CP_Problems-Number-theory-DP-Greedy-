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
        vector<vector<int>>nearest(vector<vector<int>>grid){
            int n=grid.size();
            int m=grid[0].size();
	        int vis[grid.size()][grid[0].size()]={0};
            vector<vector<int>> dist(n, vector<int>(m,0));
            deque<graph> que;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j]==1){
                        que.push_back(create(i,j,0));
                        vis[i][j]=1;
                    }
                    else{
                        vis[i][j]=0;
                    }
                }
            }
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            while(que.size()){
                int r=que.front().x;
                int c=que.front().y;
                int step= que.front().step;
                que.pop_front();
                dist[r][c]=step;

                for(int i=0; i<4; i++){
                    int nrow=r+delrow[i];
                    int ncol=c+delcol[i];
                    if(vis[nrow][ncol]==0 && nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                        que.push_back(create(nrow, ncol, step+1));
                        vis[nrow][ncol]=1;
                    }

                }
            }
            return dist;
        }
};
int main(){
    fastio();
    ll t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n, vector<int>(m,-1));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution obj ;
        vector<vector<int>> ans=obj.nearest(grid);
        for(auto i:ans){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
}