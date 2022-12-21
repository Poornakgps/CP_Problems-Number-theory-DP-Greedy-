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

struct store{
    int r;
    int c;
    int time;
};

struct store create(int r, int c, int time){
    struct store temp;
    temp.r=r;
    temp.c=c;
    temp.time=time;
    return temp;
}

class Solution{
    public:
        //Function to find minimum time required to rot all oranges.
        int orangesRotting(vector<vector<int>>& grid) {
             // Code here
            int tm=0;
            
            int n=grid.size();
            int m=grid[0].size();
            deque<store> que;      
            int cnt1=0;
            int vis[n][m];
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j]==2){
                        que.push_back(create(i,j,0));
                        vis[i][j]=2;       // marking rotten oranges
                    }
                    else{
                        vis[i][j]=0;
                    }

                    if(grid[i][j]==1){
                        cnt1++;    // ccounting number of fresh oranges
                    }
                }
            }
                int cnt=0;

            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            while(que.size()){
                int r=que.front().r;
                int c=que.front().c;
                int time=que.front().time;
                que.pop_front();
                 tm=max(tm,time);
                for(int i=0; i<4; i++){
                    int nrow= drow[i]+r;
                    int ncol= dcol[i]+c;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                        que.push_back(create(nrow,ncol,time+1));
                        vis[nrow][ncol]=2;
                        cnt++;
                    }
                }
            }
            if(cnt1!=cnt){
                return -1;
            }
            return tm;
        }
        // int orangesRotting(vector < vector < int >> & grid) {
        //     // figure out the grid size
        //     int n = grid.size();
        //     int m = grid[0].size();

        //     // store {{row, column}, time}
        //     queue < pair < pair < int, int > , int >> q;
        //     int vis[n][m];
        //     int cntFresh = 0;
        //     for (int i = 0; i < n; i++) {
        //         for (int j = 0; j < m; j++) {
        //         // if cell contains rotten orange
        //         if (grid[i][j] == 2) {
        //             q.push({{i, j}, 0}); 
        //             // mark as visited (rotten) in visited array
        //             vis[i][j] = 2;
        //         }
        //         // if not rotten
        //         else {
        //             vis[i][j] = 0;
        //         }
        //         // count fresh oranges
        //         if (grid[i][j] == 1) cntFresh++;
        //         }
        //     }

        //     int tm = 0;
        //     // delta row and delta column
        //     int drow[] = {-1, 0, +1, 0};
        //     int dcol[] = {0, 1, 0, -1}; 
        //     int cnt = 0;

        //     // bfs traversal (until the queue becomes empty)
        //     while (!q.empty()) {
        //         int r = q.front().first.first;
        //         int c = q.front().first.second;
        //         int t = q.front().second;
        //         tm = max(tm, t);
        //         q.pop();
        //         // exactly 4 neighbours 
        //         for (int i = 0; i < 4; i++) {
        //         // neighbouring row and column
        //         int nrow = r + drow[i];
        //         int ncol = c + dcol[i];
        //         // check for valid cell and 
        //         // then for unvisited fresh orange
        //         if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
        //             vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
        //             // push in queue with timer increased
        //             q.push({{nrow, ncol}, t + 1}); 
        //             // mark as rotten
        //             vis[nrow][ncol] = 2;
        //             cnt++;
        //         }
        //         }
        //     }

        //     // if all oranges are not rotten
        //     if (cnt != cntFresh) return -1;

        //     return tm;

        //     }
};

int main(){
    ll t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>grid(n,vector<int>(m,-1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
                
            }
        }
        Solution obj;
        int ans=obj.orangesRotting(grid);
        cout<<ans<<endl;
    }
}