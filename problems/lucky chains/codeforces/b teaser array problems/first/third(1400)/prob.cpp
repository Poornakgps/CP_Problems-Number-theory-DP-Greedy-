#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MOD1 998244353

#define PI 3.141592653589793238462
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0)


using namespace std;

int gcd(int a, int b){ if(b==0) return a; else return gcd(b,a%b); }

int power(ll x, ll y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return ((temp %MOD1)* temp)%MOD1;
    else
        return (x * (temp * temp)%MOD1)%MOD1;
}
/**
 * @brief
 * An array looks sorted when a1<= a2 , a2<=a3 ,...
 * 
 * For each pair of adajacent elements, let's deduce which values x put them in the correct order. 
 * Any value of x that puts all pairs in the correct order will be the answer.
 * 
 * Consider any a[i] and a[i+1] and solve the inequality |a[i]−x|≤|a[i+1]−x|. If a[i]=a[i+1], 
 * then any value of x works. Let ai be smaller than a[i+1].
 *
 * 1- if(a[i] >=x ) then inequality becomes a[i]-x <=  a[i+1]-x . thus they dont change their order and any x<=a[i] works
 * 2- if(a[i+1]<=x)  then the inequality becomes x−a[i] ≤ x−a[i+1]⇔a[i] ≥ a[i+1]. Thus, they always change their order, and none of x≥a[i] work.
 * 
 * 3- If x is between a[i] and a[i+1], then the inequality becomes x−a[i] ≤ a[i+1]− x ⇔ 2x ≤ a[i]+a[i+1] ⇔ x ≤ (a[i]+a[i+1])/2. 
 *     Thus, they only remain in the same order for any integer x such that a[i] ≤x ≤ ⌊a[i]+a[i+1]/2.
 * 
 * In union , that tells us that all values of x that work for such pairsare x<= (a[i]+a[i+1])/2
 * 
 * The similar analysis can apply to a[i]>a[i+1] , which required to being x>= (a[i]+a[i+1])/2
 * 
 * 
 */
void solve(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll minn=0, maxx=1e9;

    for(int i=0; i<n-1; i++){

        ll x=arr[i];
        ll y=arr[i+1];

        ll midl=(x+y)/2;
        ll midr=(x+y+1)/2;

        if(x>y){
            minn=max(minn,midr);
        }
        if(x<y){
            maxx=min(maxx,midl);
        }
    }

    if(minn<=maxx){
        cout<<minn<<endl;
        return;
    }
    cout<<-1<<endl;
}
int main(){
    fastio();
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}