#include<bits/stdc++.h>
using namespace std;
char maps[10][23];
int hsh[10][250];
int main()
{
    int n,i,j,k,f=0,cot;
    while(scanf("%d",&n)!=EOF)
    {
        memset(maps,0,sizeof maps);
        memset(hsh,0,sizeof hsh);
        if(n==0)
            return 0;
        for(i=1;i<=5;i++)
        {
            scanf("%s",&maps[i][1]);
            for(j=1;j<=n;j++)
            {
                if(maps[i][j]=='X')
                    hsh[i][j]=1;
            }
        }
        cot=10;
        for(i=1;i<=200;i++)
        {
            f=0;
            for(j=1;j<=5;j++)
            {
                for(k=i;k<=i+n;k++)
                {
                    if(maps[j][k-i+1]!='X')
                        continue;
                    if(hsh[j][k]==1)
                    {
                        f=1;
                    }
                }
            }
            if(f==0)
            {
                for(j=1;j<=5;j++)
                    for(k=i;k<=i+n;k++)
                        if(maps[j][k-i+1]=='X')
                            hsh[j][k]=1;
                cot--;
            }
//            for(j=1;j<=5;j++)
//            {
//                for(k=1;k<=36;k++)
//                {
//                    printf("%d ",hsh[j][k]);
//                }
//                printf("\n");
//            }
//            system("pause");
            if(cot==0)
                break;
        }
        int mc=0;
        for(i=1;i<=5;i++)
        {
            for(j=1;j<=230;j++)
            {
                if(hsh[i][j])
                    mc=max(mc,j);
            }
        }
        printf("%d\n",mc);
    }
}
