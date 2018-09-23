#include<bits/stdc++.h>
using namespace std;
long long n;
int jum[10000005][4];
int main()
{
    int i,j,k;
    //memset(jum,-1,sizeof jum);
    scanf("%I64d",&n);
    jum[0][0]=0;
    jum[0][1]=1;
    jum[0][2]=1;
    jum[0][3]=1;
    for(i=1;i<n;i++)
    {
        //int sum=0;
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                if(j==k)
                    continue;
                jum[i][j]+=jum[i-1][k];
                jum[i][j]%=1000000007;
            }
        }
    }
    printf("%d",jum[n-1][0]);
}
