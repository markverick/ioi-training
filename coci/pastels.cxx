#include<bits/stdc++.h>
using namespace std;
int ar[260][260][260],hsh[260][260][260],a[100135],b[100135],c[100135];
int main()
{
	int i,j,k,n,m;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
        a[i]++;b[i]++;c[i]++;
        hsh[a[i]][b[i]][c[i]]++;
    }
    for(i=1;i<=256;i++)
        for(j=1;j<=256;j++)
            for(k=1;k<=256;k++)
                hsh[i][j][k]+=hsh[i-1][j][k]+hsh[i][j-1][k]+hsh[i][j][k-1]-hsh[i-1][j-1][k]-hsh[i-1][j][k-1]-hsh[i][j-1][k-1]+hsh[i-1][j-1][k-1];
    int fs=0,md,ls=256,fk=0,mn=256,x,y,z;
    while(fs<=ls)
    {
        md=(fs+ls)/2;fk=0;
        for(i=1;i<=256-md;i++)
        {
            for(j=1;j<=256-md;j++)
            {
                for(k=1;k<=256-md;k++)
                {
                    if(hsh[i+md][j+md][k+md]-hsh[i-1][j+md][k+md]-hsh[i+md][j-1][k+md]-hsh[i+md][j+md][k-1]+hsh[i-1][j-1][k+md]+hsh[i-1][j+md][k-1]+hsh[i+md][j-1][k-1]-hsh[i-1][j-1][k-1]>=m)
                    {
                        fk=1;
                        break;
                    }
                }
                if(fk) break;
            }
            if(fk) break;
        }
        if(fk)
        {
            if(mn>md)
                mn=md,x=i,y=j,z=k;
            ls=md-1;
        }
        else
            fs=md+1;
    }
    printf("%d\n",mn);
    for(i=1;i<=n;i++)
    {
        if(a[i]>=x&&a[i]<=x+mn&&b[i]>=y&&b[i]<=y+mn&&c[i]>=z&&c[i]<=z+mn)
        {
            printf("%d %d %d\n",a[i]-1,b[i]-1,c[i]-1);
            if(--m)break;
        }
    }
}
