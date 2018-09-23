#include<bits/stdc++.h>
#define MP(x,y,z) make_pair(make_pair(x,y),z)
using namespace std;
char str[70];
int len=0;
int chs=0;
map<pair<pair<int,int>,int >,long long> jum[60][4];
long long dp(int idx,int color,int a,int b,int c)
{
    //printf("%d %d %d %d\n",idx,color,a,b,c);
    //printf("%lld\n",jum[idx][color][a][b][c]);
    if(a>=0&&b>=0&&c>=0&&jum[idx][color].find(MP(a,b,c))!=jum[idx][color].end())
        return jum[idx][color][MP(a,b,c)];
    if(a<0||b<0||c<0)
        return 0;
    if(idx<=0)
    {
        //printf("%d %d %d %d\n",idx,color,a,b,c);
        if(color==chs)
            return 0;
        else
        {
            return 1;
        }

    }
    if(color==0)
    {
        return jum[idx][color][MP(a,b,c)]=(dp(idx-1,1,a,b-1,c)+dp(idx-1,2,a,b,c-1))%1000000007;
    }
    if(color==1)
    {
        return jum[idx][color][MP(a,b,c)]=(dp(idx-1,0,a-1,b,c)+dp(idx-1,2,a,b,c-1))%1000000007;
    }
    if(color==2)
    {
        return jum[idx][color][MP(a,b,c)]=(dp(idx-1,0,a-1,b,c)+dp(idx-1,1,a,b-1,c))%1000000007;
    }
}
int main()
{
    int i,j,k;
    while(scanf("%s",str)!=EOF)
    {
        int l,p;
        for(i=0;i<60;i++)
            for(j=0;j<4;j++)
                jum[i][j].clear();
       // memset(jum,-1,sizeof jum);
        len=strlen(str);
        int a=0,b=0,c=0;
        for(i=0;i<len;i++)
        {
            if(str[i]=='A')
                a++;
            else if(str[i]=='B')
                b++;
            else if(str[i]=='C')
                c++;
        }
        long long sum=0;
        chs=0;
        sum+=dp(len-1,0,a-1,b,c);
        sum%=1000000007;
        for(i=0;i<60;i++)
            for(j=0;j<4;j++)
                jum[i][j].clear();
        chs=1;
        sum+=dp(len-1,1,a,b-1,c);
        for(i=0;i<60;i++)
            for(j=0;j<4;j++)
                jum[i][j].clear();
        sum%=1000000007;
        chs=2;
        sum+=dp(len-1,2,a,b,c-1);
        sum%=1000000007;

        printf("%lld\n",sum%1000000007);
    }
}
