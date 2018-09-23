#include<bits/stdc++.h>
using namespace std;
char d[100135][35];
unordered_map<long long,long long> hsh;

char q[1000135];
int main()
{
    long long lD,lQ,D,Q,i,j,k;
    scanf("%lld %lld",&D,&lD);
    for(i=0;i<D;i++)
    {
        long long sum=0;
        scanf("%s",d[i]);
        for(j=0;j<lD;j++)
        {
            sum*=2;
            sum+=d[i][j]-'0';
        }
        //printf("sumd = %lld\n",sum);
        hsh[sum]=i;
    }
    long long mul=1;
    for(i=0;i<lD;i++)
        mul*=2;
    scanf("%lld",&Q);
        set<long long> st;
    for(i=0;i<Q;i++)
    {
        st.clear();
        scanf("%lld %s",&lQ,q);
        long long sum=0;
        for(j=0;j<lQ;j++)
        {
            sum*=2;
            sum+=q[j]-'0';
            if(j>=lD)
                sum-=mul*(q[j-lD]-'0');
            //printf("sumQ= %lld\n",sum);
            if(j>lD&&hsh.find(sum)!=hsh.end())
            {
                //printf("==%lld\n",hsh[sum]);
                st.insert(hsh[sum]);
            }
        }
        if(st.empty())
        {
            printf("OK");
        }
        else for(auto it=st.begin();it!=st.end();it++)
        {
            printf("%lld ",*it+1);
        }
        printf("\n");
    }

}
