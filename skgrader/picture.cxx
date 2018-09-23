#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char op[100135][7];
int c[100135],xa[100135],ya[100135],xb[100135],load[100135],yb[100135],p[1135][1135],hsh[1135][1135],save[100135],S=1;
int Find(int la,int x)
{
    if(p[la][x]==x)return x;
    return p[la][x]=Find(la,p[la][x]);
}
void Union(int la,int x,int y)
{
    x=Find(la,x);
    y=Find(la,y);
    p[la][x]=y;
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,m,color;
	scanf("%d %d %d",&n,&color,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%s",op[i]);
        if(op[i][0]=='P')
        {
            scanf("%d %d %d %d %d",&c[i],&xa[i],&ya[i],&xb[i],&yb[i]);
            xa[i]++;ya[i]++;xb[i]++;yb[i]++;
        }
        else if(op[i][0]=='S')
            save[S++]=i;
        else if(op[i][0]=='L')
            scanf("%d",&load[i]);
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            p[i][j]=j;
    }
    for(i=m;i>=1;i--)
    {
        if(op[i][0]=='L')
        {
            i=save[load[i]];
            continue;
        }
        else if(op[i][0]=='S')
            continue;
        for(k=xa[i];k<=xb[i];k++)
        {
            for(j=(k-xa[i])%2?ya[i]+1:ya[i];j<=yb[i];j+=2)
            {
                j=Find(k,j);
//                if(((k-xa[i])%2)^((j-ya[i])%2))
//                    continue;
                if(j<=yb[i]&&hsh[k][j]==0)
                {
                    hsh[k][j]=c[i];
                }
                if(hsh[k][j+2])
                    Union(k,j,j+2);
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(hsh[i][j]==0)
                hsh[i][j]=1;
            printf("%d ",hsh[i][j]);
        }
        printf("\n");
    }
}
