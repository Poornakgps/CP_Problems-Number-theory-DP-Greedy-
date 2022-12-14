void prime_factors(ll num)
{

    for(int i=2; i<=sqrt(num); i++)
    {
        if(num%i==0)
        {
            ll cnt=0;
            while(num%i==0)
            cnt++,num=num/i;

            cout<<i<<"^"<<cnt<<endl;
        }
    }
        if(num>1)
        cout<<num<<"^"<<1<<endl;
}