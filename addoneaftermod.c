#include<bits/stdc++.h>
using namespace std;
long long a[100135],n;
map<pair<long long,long long>,long long> ja,jb;
vector<long long> v;
long long dp(long long dist,long long dif)
{
    if(ja.find(make_pair(dist,dif))!=ja.end())
        return ja[make_pair(dist,dif)];
    if(dist==0)
    {
        if(dif==0)
            return 1;
        else
        {
            return 0;
        }
    }
    long long sum=0;
    if(dist+1<=abs(dif))
    {
        return 0;
    }
    if(dif>0)
    {
        sum+=dp(dist-1,dif-1);
        sum%=1000000007;
        if(dif+2<=dist)
        {
            sum+=dp(dist-1,dif+1);
            sum%=1000000007;
        }
    }
    else if(dif<0)
    {
        sum+=dp(dist-1,dif+1);
        sum%=1000000007;
        if(dif-2>=-dist)
        {
            sum+=dp(dist-1,dif-1);
            sum%=1000000007;
        }
    }
    else
    {
        if(dist>1)
            sum+=dp(dist-1,-1)+dp(dist-1,1);
    }
    if(abs(dif)+1<=dist)
    {
        sum+=dp(dist-1,dif);
        sum%=1000000007;
    }
    return ja[make_pair(dist,dif)]=sum;
}
long long below(long long dist,long long dif)
{
    if(jb.find(make_pair(dist,dif))!=jb.end())
        return jb[make_pair(dist,dif)];
    if(dist<0)
    {
        return 0;
    }
    if(dist==0)
    {
        if(dif==0)
            return 1;
        else
        {
            return 0;
        }
    }
    long long sum=0;
    if(dist+1<=abs(dif))
    {
        return 0;
    }
    if(dif>0)
    {
        if(dif-1>=0)
            sum+=below(dist-1,dif-1);
        if(dif+2<=dist)
        {
            sum+=below(dist-1,dif+1);sum%=1000000007;
        }
    }
    else
    {
        if(dist>1)
            sum+=below(dist-1,1);
    }
    if(dif+1<=dist)
    {
        sum+=below(dist-1,dif);
        sum%=1000000007;
    }
    return jb[make_pair(dist,dif)]=sum;
}

int main()
{
    long long i,j,k,n,a,cot=1,b;
    long long sum=1,tmp;
    scanf("%d",&n);
    b=0;
//    printf("%d %d\n",dp(2,0),below(-1,0));
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(i==1||i==n)
        {
            if(a>0)
            {
                printf("0");
                return 0;
            }
            continue;
        }
        if(a==-1)
        {
            cot++;
        }
        else
        {
            tmp=dp(cot,abs(b-a))-below(cot-a-b-2,0);
            if(tmp<0)
                tmp+=1000000007;
            sum*=tmp;
            sum%=1000000007;
//            printf("%d %d\n",cot-a-b-2,dp(cot,abs(b-a)));
            b=a;
            cot=1;
        }
    }
    tmp=dp(cot,abs(b))-below(cot-b-2,0);
    if(tmp<0)
        tmp+=1000000007;
    sum*=tmp;
    sum%=tmp;
    printf("%lld",sum);
}

