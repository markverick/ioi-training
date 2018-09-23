#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> adj[12];
int n,p,L,d[12][12],a[12];
int dif(int x,int y)
{
    int cot=0;
    if(x>p&&y>p)
        x-=p,y-=p;
    if(x<p&&y<p)
    {
        while(x!=y)
        {
            if(x>y)
                x/=2;
            else if(x<y)
                y/=2;
            cot++;
        }
        return cot;
    }
    return MI;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int Q,i,j,k,x,y,mn;
	scanf("%d %d %d",&n,&L,&Q);
	p=(1<<n);
	for(i=1;i<=2*L;i++)
    {
        for(j=1;j<=2*L;j++)
            d[i][j]=MI;
        d[i][i]=0;
    }
	for(i=1;i<=L;i++)
    {
        scanf("%d %d",&a[i],&a[L+i]);
    }
    for(i=1;i<=L*2;i++)
    {
        for(j=i+1;j<=L*2;j++)
        {
            if(i+L==j)
            {
                d[i][j]=1;
                d[j][i]=1;
                continue;
            }
            d[i][j]=dif(a[i],a[j]);
            d[j][i]=d[i][j];
        }
    }
    for(k=1;k<=L*2;k++)
        for(i=1;i<=L*2;i++)
            for(j=1;j<=L*2;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//    for(i=1;i<=L*2;i++)
//    {
//        for(j=1;j<=L*2;j++)
//        {
//            printf("%d ",d[i][j]);
//        }
//        printf("\n");
//    }
    while(Q--)
    {
        scanf("%d %d",&x,&y);
        mn=dif(x,y);
        for(i=1;i<=L*2;i++)
        {
            for(j=1;j<=L*2;j++)
            {
                mn=min(mn,dif(x,a[i])+dif(y,a[j])+d[i][j]);
            }
        }
        printf("%d\n",mn);
    }
}
