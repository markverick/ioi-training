#include<bits/stdc++.h>
using namespace std;
int l,s;
int jum[28][360][28];
int dp(int idx,int sum,int alpha)
{
    if(idx==l)
    {
        if(sum==s)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(jum[idx][sum][alpha]>=0)
        return jum[idx][sum][alpha];
    int sm=0,i;
    for(i=alpha+1;i<=26;i++)
    {
        sm+=dp(idx+1,sum+i,i);
    }
    return jum[idx][sum][alpha]=sm;
}
int main()
{
    int cot=0,c=0,i;
//    for(i=1;i<=26;i++)
//        c+=i;
//        printf("%d\n",c);
    while(scanf("%d %d",&l,&s)!=EOF)
    {
        cot++;
        memset(jum,-1,sizeof jum);
        if(l==0&&s==0)
            return 0;
        if(l*351<s||s>351||l>26)
        {
            printf("Case %d: 0\n",cot);
            continue;
        }
        printf("Case %d: %d\n",cot,dp(0,0,0));
    }
}
