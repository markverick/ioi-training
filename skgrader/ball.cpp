#include<bits/stdc++.h>
using namespace std;
int ballPos[1135];

int main()
{
    int n,i,j,k,pow,tmp;
    memset(ballPos,-1,sizeof ballPos);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&pow);
        tmp=pow;
        if(i>1&&pow>ballPos[1]&&ballPos[1]==0)
        {
            for(j=1;j<i;j++)
            {
                if(pow>=ballPos[j])
                {
                    pow++;
                    //ballPos[j]++;
                }
                else
                {
                    break;
                }
            }
            k=j-1;
            //printf("K= %d Pow= %d\n",k,pow);
            for(j=1;j<=k;j++)
            {
                ballPos[j]=tmp+j-1;
            }
            ballPos[i]=tmp+k;
        }
        else
        {
            for(j=1;j<i;j++)
            {
                if(pow>ballPos[j])
                {
                    ballPos[j]--;
                    pow--;
                }
                else if(pow==ballPos[j])
                    pow--;
                //sort(&ballPos[1],&ballPos[i]);
            }
            ballPos[i]=pow;
        }
        sort(&ballPos[1],&ballPos[i+1]);
        /*for(j=1;j<=i;j++)
        {
            printf("%d ",ballPos[j]);
        }
        printf("\n");*/
    }
    for(i=n;i>=1;i--)
    {
        printf("%d\n",ballPos[i]);
    }
}
