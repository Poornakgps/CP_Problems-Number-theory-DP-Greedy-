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

int main(){

    ll n,m;  // nodes  ,   edges
    cin>>n>>m;
   /*Matrix form*/
    ll adj[n+1][n+1]={0}; // adjacent matrix

    /* undirectional Graph */
    for(int i=0; i<m; i++){
        ll a,b;
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
    /*List form*/
    /*adjacency list for undirectional graph*/
    vector<ll> ad[n+1];  // effecient

    for(int i=0; i<m; i++){
        ll a,b;
        cin>>a>>b;

        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    
    /*for weighted graph*/
    /*
    for(int i=0; i<m; i++){
        ll a,b,wt;
        cin>>a>>b,wt;
        adj[a][b]=wt;
        adj[b][a]=wt;
    }
    */
   /* for list*/
   /*
    vector<pair> ad[n+1];  // effecient

    for(int i=0; i<m; i++){
        ll a,b,wt;
        cin>>a>>b>>wt;

        ad[a].push_back(make_pair(b,wt));
        ad[b].push_back(make_pair(a,wt));
    } 
   */
}