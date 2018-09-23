#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<int,int> p[100135];
int cross[100135],jump[100135];
int l,n,m,fin,st=1;
int main()
{
    int i,j,k;
    scanf("%d %d %d",&l,&n,&m);
    fin=l;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&p[i].X,&p[i].Y);
        if(p[i].Y==l)
            fin=min(fin,p[i].X);
        if(p[i].X==0)
            st=max(p[i].Y,st);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&cross[i]);
    }
    sort(&cross[1],&cross[m+1]);
    sort(&p[1],&p[n+1]);

    j=1;
    int hi=0,cot=0;
    for(i=1;i<=n;i++)
    {
        if(cross[j]<p[i].X)
        {
            j=hi;
            cot++;
            while(cross[j]<p[i].X)
                j++;
        }
        hi=max(hi,upper_bound(&cross[1],&cross[m+1],p[i].Y)-&cross[0]-1);
    }
    printf("%d",cot*2+1);
}
