#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
using namespace std;
int n,L,m,a[111];
int jum[111][111];
vector<int> vec;
int dp(int idx,int skill)
{
    if(jum[idx][skill]>=0)
        return jum[idx][skill];
//    printf("%d %d\n",idx,skill);
    int i,j,sum=1;
    vector<pair<int,int> > v;
    for(i=idx+1;i<=n;i++)
    {
        v.emplace_back(a[i],-i);
    }
    sort(v.begin(),v.end());
    int tmp=0;
    for(i=0;i<v.size();i++)
    {
        if(v[i].X<=a[idx])
        {
            if(skill>0)
            {
                tmp=dp(-v[i].Y,skill-1);
                sum+=tmp;
//                if(sum>m+1)sum=m+1;
            }
        }
        else
        {
            tmp=dp(-v[i].Y,skill);
            sum+=tmp;
//            if(sum>m+1)
//                sum=m+1;
        }
    }
    return jum[idx][skill]=sum;
}
int result[111];
void dfs(int idx,int skill,int C,int quota)
{
    int i,j,sum=0,x,y;
    printf("%d %d %d %d\n",idx,skill,C,quota);
    if(quota==0)
    {
        printf("\n");
        for(i=1;i<C;i++)
        {
            printf("%d ",result[i]);
        }
        printf("\n\n");
        return;
    }
    vector<pair<int,int> > v;
    for(i=idx+1;i<=n;i++)
    {
        v.emplace_back(a[i],-i);
    }
    sort(v.begin(),v.end());
    int tmp=0;
    for(i=0;i<v.size();i++)
    {
        if(v[i].X<=a[idx])
        {
            if(skill>0)
            {
                if(quota-jum[-v[i].Y][skill-1]>=0)
                {
                    result[C]=v[i].X;
                    quota-=jum[-v[i].Y][skill-1];
                    x=-v[i].Y;y=skill-1;
                }
            }
        }
        else
        {
            if(quota-jum[-v[i].Y][skill]>=0)
            {
                quota-=jum[-v[i].Y][skill];
                result[C]=v[i].X;
                x=-v[i].Y;y=skill;
            }
        }
    }
    dfs(x,y,C+1,quota);
    return;
}
int main()
{
    int i,j,k;
    memset(jum,-1,sizeof jum);
    scanf("%d %d %d",&n,&L,&m);
    a[0]=-1;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d\n",dp(0,L));
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=L;j++)
        {
            printf("%d ",jum[i][j]);
        }
        printf("\n");
    }
    dfs(0,L,1,m);
//    for(i=vec.size()-1;i>=0;i--)
//    {
//        printf("%d ",vec[i]);
//    }
}
