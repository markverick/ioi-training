#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int f[30],d[30],t[30],n;
pair<vector<int>,int> jum[30][500];
pair<vector<int>,int> dp(int idx,int time)
{
    if(jum[idx][time].Y>=0)
        return jum[idx][time];
    int i,j,sum=0,tt=time,cot=0;
    pair<vector<int>,int> mc;
    pair<vector<int>,int> p;
    vector<int> v;
    if(idx<n)
    {
        if(time-t[idx+1]>=0)
        {
            p=dp(idx+1,time-t[idx+1]);
            v.clear();
            v.emplace_back(0);
            for(i=0;i<p.X.size();i++)
                v.emplace_back(p.X[i]);
            mc=make_pair(v,p.Y);
        }
        tt=time-1;
        for(i=f[idx];tt>=0;i-=d[idx],tt--)
        {
            if(i<0)
                i=0;
            sum+=i;cot++;
            if(tt-t[idx+1]>=0)
            {
                p=dp(idx+1,tt-t[idx+1]);
//                printf("%d %d\n",idx,cot);
                if(mc.Y<=p.Y+sum)
                {
                    v.clear();
                    v.emplace_back(cot);
                    for(j=0;j<p.X.size();j++)
                        v.emplace_back((p.X)[j]);
                    mc=make_pair(v,p.Y+sum);
                }
            }
        }
        sum=0;
        cot=0;
        tt=time;
        for(i=f[idx];tt>0;i-=d[idx],tt--)
        {
            if(i<0)i=0;
            sum+=i;
            cot++;
        }
        if(mc.Y<=sum)
        {
            v.clear();
            v.emplace_back(cot);
            mc=make_pair(v,sum);
        }
        return jum[idx][time]=mc;
    }
    else
    {
        tt=time;
        sum=0;
        cot=0;
        for(i=f[idx];tt>0;i-=d[idx],tt--)
        {
            if(i<0)
                i=0;
            sum+=i;
            cot++;
        }
        v.clear();
        v.emplace_back(cot);
        return jum[idx][time]=make_pair(v,sum);
    }

}
int main()
{
//    freopen("out.txt","w",stdout);
    int T,i,j,k=0,h;
    pair<vector<int>,int> p;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            return 0;
        if(k==1)
            printf("\n");
        k=1;
        for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=498;j++)
                jum[i][j].Y=-1,jum[i][j].X.clear();
        }
        scanf("%d",&h);
        h*=12;
        for(i=1;i<=n;i++)
            scanf("%d",&f[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&d[i]);
        for(i=2;i<=n;i++)
            scanf("%d",&t[i]);
        p=dp(1,h);
        if(!p.X.empty())
        {
            printf("%d",p.X[0]*5);
            for(i=1;i<p.X.size();i++)
                printf(", %d",p.X[i]*5);
            for(i=p.X.size();i<n;i++)
                printf(", 0");
        }
        else
        {
            printf("0");
            for(i=1;i<n;i++)
                printf(", 0");
        }
        printf("\nNumber of fish expected: %d\n",p.Y);
    }
}
