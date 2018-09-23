#include<bits/stdc++.h>
using namespace std;
char str[55];
int len;
unordered_map<int,bool> isFi;
int jum[60][60];
int dp(int x,int y)
{
    int i,j;
    long long a=0;
    if(jum[x][y]>=0)
        return jum[x][y];
    if(x==y)
    {
        if(str[x]=='1')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    for(i=x;i<=y;i++)
    {
        a*=2;
        if(str[i]=='1')
            a++;
    }
    //printf("a = %d\n",a);
    if(isFi.find(a)!=isFi.end())
    {
        return 1;
    }
    int mn=1000000000;
    for(i=x;i<y;i++)
    {
        mn=min(mn,dp(x,i)+dp(i+1,y));
    }
    return jum[x][y]=mn;
}
int main()
{
    int n,i,j,k;
    long long a=1;
    for(i=1;i<=23;i++)
    {
        isFi[a]=1;
        a*=5;
    }
    int out;
    while(scanf("%s",str)!=EOF)
    {
        memset(jum,-1,sizeof jum);
        len=strlen(str);
        out=dp(0,len-1);
        if(out==1000000000||out==0)
            printf("-1\n");
        else
            printf("%d\n",out);
    }
}
