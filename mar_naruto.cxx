#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int level[333000];
pair<int,int> b[135000],a[333000];
int out[135000];
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i].X);
        a[i].Y=i;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&b[i].X);
        b[i].Y=i;
    }
    sort(&a[1],&a[n+1]);
    sort(&b[1],&b[m+1]);
    j=1;
    level[0]=1;level[n+1]=1;
    int num=1;
    for(i=1;i<=m;i++)
    {
        while(a[j].X<b[i].X)
        {
            level[a[j].Y]=1;
            if(level[a[j].Y+1]==0&&level[a[j].Y-1]==0)
                num++;
            else if(level[a[j].Y+1]==1&&level[a[j].Y-1]==1)
                num--;
            j++;
        }
        out[b[i].Y]=num;
    }
    for(i=1;i<=m;i++)
    {
        printf("%d\n",max(0,out[i]));
    }
}
