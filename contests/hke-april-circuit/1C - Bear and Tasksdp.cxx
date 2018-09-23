#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dur=0,n;
pair<int,int> jum[1135][13][13];
int whose[1135][13][13];
int a[1135],b[1135],d[1135],c[1135];
pair<double,int> p[1135];
pair<int,int> dp(int id,int x,int y)
{
    if(jum[id][x][y].X>=0)
        return jum[id][x][y];
    if(id==n+1)
    {
        return {0,0};
    }
    int idx=p[id].Y;
    pair<int,int> A=dp(id+1,max(1,min(10,x+b[idx])),y),B=dp(id+1,x,max(1,min(10,y+d[idx])));
    A.X+=x*a[idx];
    B.Y+=y*c[idx];
    if(max(A.X,A.Y)<=max(B.X,B.Y))
    {
        whose[id][x][y]=1;
        return jum[id][x][y]=A;
    }
    else
    {
        whose[id][x][y]=2;
        return jum[id][x][y]=B;
    }
}
int main()
{
    int i,j,k,x=1,y=1,idx;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
        p[i]={min((double)b[i]/a[i],(double)d[i]/c[i]),i};
    }
    sort(&p[1],&p[n+1]);
    for(i=1;i<=n+1;i++)
    {
        for(j=0;j<=11;j++)
        {
            for(k=0;k<=11;k++)
            {
                jum[i][j][k].X=-1;
            }
        }
    }
    pair<int,int> out;
    out=dp(1,1,1);
//    printf("%d\n",max(out.X,out.Y));
    idx=1;x=1;y=1;
    vector<int> A,B;
    idx=1;
    for(i=1;i<=n;i++)
    {
        idx=p[i].Y;
        if(whose[i][x][y]==1)
        {
            A.emplace_back(idx);
            x=max(1,min(10,x+b[idx]));
        }
        else
        {
            B.emplace_back(idx);
            y=max(1,min(10,y+d[idx]));
        }
    }
    printf("%d\n",A.size());
    for(i=0;i<A.size();i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n%d\n",B.size());
    for(i=0;i<B.size();i++)
    {
        printf("%d ",B[i]);
    }
}
