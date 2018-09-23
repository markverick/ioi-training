#include<bits/stdc++.h>
using namespace std;
int kp[200135];
int tmp[200135];
int x[105],y[105];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
        for(i=1;i<=200000;i++)
            kp[i]=-100000;
    kp[100000]=0;
    for(i=1;i<=n;i++)
    {
        for(j=200000;j>=0;j--)
            tmp[j]=kp[j];
        for(j=200000;j>=0;j--)
        {
            if(j+x[i]>=0&&j+x[i]<=200000)
                tmp[j+x[i]]=max(tmp[j+x[i]],kp[j]+y[i]);
        }
        for(j=200000;j>=0;j--)
            kp[j]=tmp[j];
    }
    int mc=0;
    for(j=100000;j<200000;j++)
    {
        if(kp[j]>=0)
            mc=max(mc,kp[j]+j-100000);
            //printf("%d + %d = %d\n",kp[n][j],j-100000,kp[n][j]+j-100000);
        //system("pause");
        //if(kp[n][j]+j-100000<0)
        //    break;
    }
        printf("%d\n",mc);
}
