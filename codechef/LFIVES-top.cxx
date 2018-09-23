#include<bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define X first
#define Y second
using namespace std;
vector<pair<int,int> > v;
int a[2005],fw[3][2005],res[2005][2005];
void add(int x,int val,int op)
{
    while(x<2005)
    {
        fw[op][x]+=val;
        x+=x&-x;
    }
}
int query(int x,int op)
{
    int ss=0;
    while(x>0)
    {
        ss+=fw[op][x];
        x-=x&-x;
    }
    return ss;
}
int main()
{
    int n,q,i,j,x,ct,kb,y;
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        v.emplace_back(x,i);
    }
    sort(ALL(v));
    ct=1;
    for(i=0;i<v.size();i++)
    {
        if(i!=0&&v[i].X==v[i-1].X)
            a[v[i].Y]=a[v[i-1].Y];
        else
            a[v[i].Y]=ct++;
    }
    for(i=0;i<n;i++)
    {
        memset(fw,0,sizeof fw);
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i]) add(a[j],1,0);
            kb=query(a[j]-1,0);
            add(a[j],kb,1);
            kb=query(2004,1)-query(a[j],1);
            add(a[j],kb,2);
            res[i][j]=query(a[j]-1,2);
            //printf("%d\n",query(a[j]-1,2));
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<i;j++)
            printf(" ");
        for(j=i;j<=n;j++)
        {
            printf("%d",res[i-1][j-1]);
        }
        printf("\n");
    }
    while(q--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",res[x-1][y-1]);
    }
}
