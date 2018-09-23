#include<bits/stdc++.h>
using namespace std;
long long maps[30][30];
long long sum[30][30];
long long Pow[30][30][30];
long long tmp[30][30];
int len;
int main()
{
    int i,j,k,l;
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            scanf("%lld",&maps[i][j]);
        }
    }
    for(i=0;i<26;i++)
    {
        Pow[0][i][i]=1;
    }
    for(k=1;k<=24;k++)
    {
        for(i=0;i<26;i++)
        {
            for(j=0;j<26;j++)
            {
                for(l=0;l<26;l++)
                {
                    tmp[i][j]+=Pow[k-1][i][l]*maps[l][j];
                    tmp[i][j]%=1000000007;
                }
            }
        }
        for(i=0;i<26;i++)
        {
            for(j=0;j<26;j++)
            {
                Pow[k][i][j]=tmp[i][j];
                //printf("%d ",Pow[k][i][j]);
                tmp[i][j]=0;
            }
            //printf("\n");
        }
        //system("pause");
    }
    int T;
    char in[3];
    long long cot=0;
    scanf("%d",&T);
    memset(tmp,0,sizeof tmp);
    while(T--)
    {
        scanf("%s %d",in,&len);
        memset(sum,0,sizeof sum);
        for(i=0;i<26;i++)
        {
            sum[i][i]=1;
        }
        for(k=0;k<=24;k++)
        {
            if((1<<k)&len)
            {

                for(i=0;i<26;i++)
                {
                    for(j=0;j<26;j++)
                    {
                        for(l=0;l<26;l++)
                        {
                            tmp[i][j]+=sum[i][l]*Pow[k][l][j];
                            tmp[i][j]%=1000000007;
                        }
                    }
                }
                for(i=0;i<26;i++)
                {
                    for(j=0;j<26;j++)
                    {
                        sum[i][j]=tmp[i][j];
                        tmp[i][j]=0;
                    }
                }
            }
        }
        cot=0;
        for(i=0;i<26;i++)
        {
            cot+=sum[i][in[0]-'a'];
            cot%=1000000007;
        }
        printf("%lld\n",cot);
    }
}
