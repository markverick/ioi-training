#include<bits/stdc++.h>
using namespace std;
int seq[200];
int jum[200][3][1200];
int n;
int dp(int idx,short op,int num)
{
    int hi=-1;
    int i,j,k;
    if(jum[idx][op][num]>=0)
        return jum[idx][op][num];
    if(idx==n)
    {
        return 0;
    }
    hi = dp(idx+1,op,num);
    if(op==0&&seq[idx]>num)
    {
        return jum[idx][op][num]= max(dp(idx+1,1,seq[idx])+1,hi);
    }
    else if(op==1&&seq[idx]<num)
    {
        return jum[idx][op][num]= max(dp(idx+1,0,seq[idx])+1,hi);
    }
    else
    {
        return jum[idx][op][num]=hi;
    }


}
int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        memset(jum,-1,sizeof jum);
        for(i=0;i<n;i++)
        {
            scanf("%d",&seq[i]);
        }
        printf("%d\n",max(dp(0,1,seq[0]),dp(0,0,seq[0]))+1);
    }
}
