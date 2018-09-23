#include<bits/stdc++.h>
using namespace std;
vector<long long> adj[10135];
long long jum[10135];
long long hsh[10135];
long long jj[10135][5];
long long isLoop[10135];
long long fk=0,fkyo=0;
long long teema[10135];
long long dp(long long idx)
{
    printf("%lld\n",idx);
    if(jum[idx]>=0)
        return jum[idx];
    if(idx==2)
    {
        return  1;
    }
    long long sum=0;
    for(long long i=0;i<adj[idx].size();i++)
    {
//        if(hsh[teema[adj[idx][i]]]==1)
//        {
//            continue;
//        }
//        hsh[adj[idx][i]]=1;
        if(teema[adj[idx][i]]==idx)continue;
        sum+=dp(teema[adj[idx][i]]);
        if(sum>=1000000000)
        {
            fk=1;
        }
//        hsh[adj[idx][i]]=0;
        sum%=1000000000;
    }
    return jum[idx]=sum;
}
void tagloop(int idx)
{
    if(idx==2)
        return;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(hsh[adj[idx][i]]==1)
        {
            teema[idx]=adj[idx][i];
            isLoop[adj[idx][i]]=1;
            continue;
        }
        hsh[adj[idx][i]]=1;
        tagloop(adj[idx][i]);
        hsh[adj[idx][i]]=0;
    }
}
int chkloop(int idx,int fu)
{
    //printf("%lld %lld\n",idx,fu);
    if(jj[idx][fu]>=0)
        return jj[idx][fu];
    if(idx==2)
    {
        if(fu==1)
        {
            //printf("F.U.C.K");
            fkyo=1;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int mc=0;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(hsh[adj[idx][i]]==1)
            continue;
        hsh[adj[idx][i]]=1;
        if(isLoop[adj[idx][i]])
        {
            mc=max(mc,chkloop(adj[idx][i],1));
        }
        else
        {
            mc=max(mc,chkloop(adj[idx][i],max(fu,0)));
        }
        hsh[adj[idx][i]]=0;
    }
    return jj[idx][fu]=mc;
}
int main()
{
    long long n,m,i,j,k,a,b;
    memset(jum,-1,sizeof jum);
    memset(jj,-1,sizeof jj);
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%lld %lld",&a,&b);
        adj[a].emplace_back(b);
    }

    for(i=1;i<=n;i++)
    {
        teema[i]=i;
    }
    hsh[1]=1;
    tagloop(1);
    memset(hsh,0,sizeof hsh);
    long long swag=chkloop(1,isLoop[1]);
    for(i=1;i<=n;i++)
    {
//        if(isLoop[i]==1)
//            printf("%lld\n",i);
        printf("Teema[%lld] = %lld\n",i,teema[i]);
    }
    system("pause");
    memset(hsh,0,sizeof hsh);
    if(swag==1)
    {
        printf("inf");
    }
    else
    {
        printf("F");
        long long tt=dp(1);
        //printf("%lld\n",tt);
            if(fk==0)
                printf("%lld",tt);
            else
                printf("%09lld",tt);
    }
}
