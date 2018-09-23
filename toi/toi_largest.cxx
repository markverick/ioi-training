#include<bits/stdc++.h>
using namespace std;
int maps[1135][1135];
int R[1135][1135];
int L[1135][1135];
int U[1135][1135];
int D[1135][1135];
int main()
{
    int T,t,i,j,k,r,c;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        memset(R,0,sizeof R);
        memset(L,0,sizeof L);
        memset(U,0,sizeof U);
        memset(D,0,sizeof D);
        scanf("%d %d",&r,&c);
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                scanf("%d",&maps[i][j]);
            }
        }
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(maps[i][j]>=maps[i][j-1])
                    L[i][j]=L[i][j-1]+1;
                else
                    L[i][j]=1;
            }
            for(j=c;j>=1;j--)
            {
                if(maps[i][j]>=maps[i][j+1])
                    R[i][j]=R[i][j+1]+1;
                else
                    R[i][j]=1;
            }
        }
        for(j=1;j<=c;j++)
        {
            for(i=1;i<=r;i++)
            {
                if(maps[i][j]>=maps[i-1][j])
                    U[i][j]=U[i-1][j]+1;
                else
                    U[i][j]=1;
            }
            for(i=r;i>=1;i--)
            {
                if(maps[i][j]>=maps[i+1][j])
                    D[i][j]=D[i+1][j]+1;
                else
                    D[i][j]=1;
            }
        }
        int mc=-1,idx=0,idy=0;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(mc<U[i][j]+D[i][j]+R[i][j]+L[i][j]-3)
                {
                    mc=U[i][j]+D[i][j]+R[i][j]+L[i][j]-3;
                    idx=i;idy=j;
                }
            }
        }
        printf("%d\n%d %d\n",mc,idx,idy);
    }
}
