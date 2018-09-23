#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
tuple<int,int,int> a[500005];
int fw[700],ww[500005],bs[500005];
int jum[700][700];
void add(int x)
{
    while(x<700)
    {
        fw[x]++;
        x+=x&-x;
    }
}
int sum(int x)
{
    int ss=0;
    while(x>0)
    {
        ss+=fw[x];
        x-=x&-x;
    }
    return ss;
}
int main()
{
    freopen("out.txt","w",stdout);
    int n,i,x,y,d;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        jum[x+1][y+1]++;
        a[i]=make_tuple(x+1,-y-1,i);
    }
    sort(a,a+n);
    memset(fw,0,sizeof fw);
    for(i=0;i<n;i++)
    {
        tie(x,y,d)=a[i];
        ww[d]=n-sum(-y-1);
        if(x==651) ww[d]-=jum[1][-y];
        if(y==651) ww[d]-=jum[x][1];
        add(-y);
    }
    memset(fw,0,sizeof fw);
    for(i=n-1;i>=0;i--)
    {
        tie(x,y,d)=a[i];
        bs[d]=(n-1-i)-sum(-y)+1;
        add(-y);
    }
    for(i=0;i<n;i++)
        printf("%d %d\n",bs[i],ww[i]);

}