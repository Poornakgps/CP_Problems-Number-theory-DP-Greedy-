#include<bits/stdc++.h>
#include<algorithm>

#define ll long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462

using namespace std;

class ninja_training{


    public:
        ll testcases,length_of_2d_array;

        void print_answer();

    private:

        ll Algorithm(ll day, ll last, ll array[][3], ll dp[][4])
        {
            if (day==0)
            {
                ll maxi=0;
                for(int task=0; task<3; task++)
                {
                    if(task!=last){
                        maxi=max(maxi,array[0][task]);
                    }
                    
                }
                return maxi;
        
            }

            if(dp[day][last]!=0) return dp[day][last];

            ll maxi=0;
            for(int task=0; task<3; task++)
            {
                if(task!=last)
                {
                    ll point=array[day][task] + Algorithm(day-1,task,array, dp);

                    maxi=max(maxi,point);
                }
            }
            
            return dp[day][last]= maxi;
        }
};


void ninja_training::print_answer()
{

    cin>>length_of_2d_array;
    ll day=length_of_2d_array;
    ll array[length_of_2d_array][3];
    ll dp[day][4]={0};
    for(int i=0; i<length_of_2d_array; i++)
    {
        for(int j=0; j<3; j++)
            cin>>array[i][j];
    }
    cout<<Algorithm(day-1,3, array , dp)<<endl;  // from public methods we can acces private methods but we can't acces from outside class
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ninja_training object1;

        object1.print_answer();

    }
}