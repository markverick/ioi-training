#include<bits/stdc++.h>
using namespace std;
int w[105];
int kp[105][20135];
vector<int> out;
int main()
{
    int T,n,i,j,k,sum;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        sum=0;
        memset(kp,0,sizeof kp);
        out.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
            sum+=w[i];
        }
        kp[0][10005]=1;
        for(i=1;i<=n;i++)
        {
            for(j=10005-sum;j<=10005+sum;j++)
            {
                if(kp[i-1][j]==1)
                {
                    kp[i][j]=1;
                    kp[i][j+w[i]]=1;
                    kp[i][j-w[i]]=1;
                }
            }
        }
        int cot=0;
        for(i=10006;i<=10005+sum;i++)
        {
            if(kp[n][i]==0)
            {
                out.emplace_back(i-10005);cot++;
            }
        }
        if(cot==0)
            printf("0");
        else
        {
            printf("%d\n",cot);
            for(i=0;i<cot;i++)
                printf("%d ",out[i]);
        }
        printf("\n");
    }
}
