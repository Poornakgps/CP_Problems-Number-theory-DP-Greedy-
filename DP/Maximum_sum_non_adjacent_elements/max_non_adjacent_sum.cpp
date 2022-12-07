#include<bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462

using namespace std;

class max_sum_non_adjacent_elements
{
    public:

        ll testcases,length_of_array;

        void print_answer();

        ll Algorithm()
        {
            ll array[length_of_array];
            for (int i=0; i<length_of_array; i++)
            {
                cin>>array[i];
            }
            ll inc=array[0];  //including first element
            ll exc=0;         //excluding first element

            for(int i=1; i<length_of_array; i++)
            {
                ll temp1=inc;
                ll temp2=exc;
                inc=temp2+array[i];
                exc=max(temp1,temp2);
            }   
            return max(inc,exc);
        }
};
//accessing public class function from outside the class
void max_sum_non_adjacent_elements::print_answer()
{
    cin>>length_of_array;
    cout<<Algorithm()<<endl;
}

int main()
{
    max_sum_non_adjacent_elements object1;
    cin>>object1.testcases;
    ll t=object1.testcases;
    while(t--)
    {
        object1.print_answer();

    }
}