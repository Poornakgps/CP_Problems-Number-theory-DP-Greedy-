#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll w,n,m,flag=1;
        cin>>w>>n>>m;
        vector<pair<ll,pair<ll,ll>>> v;

            if(w%m==0)
            {
                cout<<0 <<" "<<w/m<<" "<<0<<endl;
            }
            else
            {
                ll k=(w-m*(w/m));
                ll p=k/n;
                ll temp=w%m,j=0;
                ll i=0;
                for(i=w/m; i>=0; i--)
                {
                    k=(w-m*i);
                    p=k/n;
                    //cout<<p<<" "<<i<<" "<<w- (p*n+m*i)<<endl;
                    temp=min(temp, w- (p*n+m*(w/m)));
                    
                    if(temp==0){
                        flag=0;
                    break;}
                    v.push_back(make_pair(w- (p*n+m*i), make_pair(p,i)));
                    
                }

                if(flag==0)
                {
                    cout<<p<<" "<<i<<" "<<w- (p*n+m*i)<<endl;
                }
                else
                {
                    sort(v.begin(),v.end());
                    cout<<v[0].second.first<<" "<<v[0].second.second<<" "<<v[0].first<<endl;
                }
            }
     
   
    }
}