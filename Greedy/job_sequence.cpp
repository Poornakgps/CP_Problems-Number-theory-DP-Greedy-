#include<bits/stdc++.h>
#define ll long long

using namespace std;

#define mod 1000000007

ll fac[1000001];

void f ()
{
    fac[1]=1;
    for(int i=2; i<=1000000; i++)
    {
        fac[i]=((fac[i-1]%mod)*(i % mod))%mod;
    }
}

 struct job{

    string id;
    ll deadline;
    ll profit;

};

bool comp1(job a, job b)
{
    return (a.profit>b.profit);
}
bool comp2(job a, job b)
{
    return (a.deadline>b.deadline);
}

void print_queue(queue<string> q)
{
    queue<string> temp = q;
    while (!temp.empty()) {
        cout << temp.front()<<" ";
        temp.pop();
    }
    cout << '\n';
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,maxid=0;
        cin>>n;
        job arr[n+1],arr2[n+1];

        for(int i=1; i<=n; i++){
            cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
            arr2[i].id=arr[i].id,  arr2[i].deadline=arr[i].deadline, arr2[i].profit=arr[i].profit;
            maxid=max(maxid,arr[i].deadline);
        }
        //cout<<maxid<<endl;
        sort(arr2,arr2+n,comp1);
        //sort(arr,arr+n,comp2);

        queue<string> q;
        // for(int i=1; i<=n; i++)
        // {
        //     cout<<arr2[i].id<<" "<<arr2[i].deadline<<" "<<arr2[i].profit<<endl;
        // }

        for(int i=1; i<=n; i++)
        {
            if(arr2[i].deadline>=i)
            {
                q.push(arr2[i].id);
            }
            else
            {
                int j;
                for(j=i; j<=n; j++)
                {
                    if(arr2[j].deadline>=i)
                    {
                        q.push(arr2[j].id);
                        i++;
                    }
                }
                break;
            }
        }

        print_queue(q);
    }

}