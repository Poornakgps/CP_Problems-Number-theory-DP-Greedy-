#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll gcd(ll a, ll b, ll &x,  ll &y)
{
    if(b==0){
    
    x=1;
    y=0;

    return a;
    }

    ll x1,y1;
    //cout<<a%b<<endl;
    ll d=gcd(b, a%b, x1, y1);
    x=y1;
    y= x1 - y1*(a/b);
    //cout<<x1<<" "<<y1<<endl;

    return d; 
}

bool find_any_solutions(ll a , ll b, ll c , ll &x,  ll &y)
{
    ll x0,y0;

    ll g=gcd(abs(a),abs(b),x0,y0);
    
    if(c%g)
    {
        return false;
    }

    x= x0*(c/g);
    y= y0*(c/g);

    if(a<0)x=-x;
    if(b<0)y=-y;
    return true;

}


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,x,y;
        cin>>a>>b>>c;

        if(find_any_solutions(a,b,c,x,y)==false)
        {
            cout<<"No solutions\n";
        }
        else
        {
            cout<<x<<" "<<y<<endl;
        }
    }
}