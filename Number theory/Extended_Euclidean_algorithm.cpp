#include<bits/stdc++.h>
#define ll long long

using namespace std;

// see notes for theory

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
int iterative_gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int main()
{
    ll t;
    cin>>t;

    while(t--)
    {
        ll a,b,x,y,d;
        cin>>a>>b;

        d=gcd(a,b,x,y);

        cout<<x<<" "<<y<<" "<<d<<endl;

/*
        Iterative method
        d=iterative_gcd(a,b,x,y);

        cout<<x<<" "<<y<<" "<<d<<endl;

*/
    }
}
