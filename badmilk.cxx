#include<bits/stdc++.h>
using namespace std;
int invalid[135],sick[135],sickat[135],dieat[135];
int a[1135],b[1135],c[1135],x[1135],y[1135];
int drinkat[135][135];
int main()
{
    freopen("badmilk.in","r",stdin);
    freopen("badmilk.out","w",stdout);
    int n,m,d,s,i,j,k;
    scanf("%d %d %d %d",&n,&m,&d,&s);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            drinkat[i][j]=1000000000;
    for(i=1;i<=n;i++)
        dieat[i]=1000000000;
    for(i=1;i<=d;i++)
    {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
//        drinkat[a[i]][b[i]]=min(drinkat[a[i]][b[i]],c[i]);
    }
    for(i=1;i<=s;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        sickat[x[i]]=y[i];
    }
    int cot,mc=0;
    for(i=1;i<=m;i++)
    {
        memset(sick,0,sizeof sick);
        for(j=1;j<=n;j++)
            dieat[j]=1000000000;
        cot=0;
        for(j=1;j<=d;j++)
        {
            if(b[j]==i)
                dieat[a[j]]=min(dieat[a[j]],c[j]);
        }
        for(j=1;j<=n;j++)
        {
            if(sickat[j]==0)
            continue;
            if(dieat[j]==1000000000)
            {
                if(sickat[j]>0)
                {
//                    printf("CHICKEN-DIE\n");
                    invalid[i]=1;
                }
            }
            else
            {
                if(sickat[j]<=dieat[j])
                {
//                    printf("EARLY-DIE at %d\n",j);
                    invalid[i]=1;
                }
            }
        }
        if(invalid[i])continue;
        for(j=1;j<=d;j++)
        {
            if(b[j]==i&&sick[a[j]]==0)
                sick[a[j]]=1,cot++;
        }
//        printf("%d %d\n",i,cot);
        mc=max(mc,cot);

    }
    printf("%d",mc);
}
