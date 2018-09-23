#include<bits/stdc++.h>
using namespace std;
char str[70];
int len=0;
long long jum[60][4][60][60][60];
long long dp(int idx,int color,int a,int b,int c)
{
    //printf("%d %d %d %d\n",idx,color,a,b,c);
    //printf("%lld\n",jum[idx][color][a][b][c]);
    if(a>=0&&b>=0&&c>=0&&jum[idx][color][a][b][c]>=0)
        return jum[idx][color][a][b][c];
    if(a<0||b<0||c<0)
        return 0;
    if(idx<=0)
    {
        //printf("%d %d %d %d\n",idx,color,a,b,c);
        if(color==0)
            return 0;
        else
        {
            return 1;
        }

    }
    if(color==0)
    {
        return jum[idx][color][a][b][c]=(dp(idx-1,1,a,b-1,c)+dp(idx-1,2,a,b,c-1))%1000000007;
    }
    if(color==1)
    {
        return jum[idx][color][a][b][c]=(dp(idx-1,0,a-1,b,c)+dp(idx-1,2,a,b,c-1))%1000000007;
    }
    if(color==2)
    {
        return jum[idx][color][a][b][c]=(dp(idx-1,0,a-1,b,c)+dp(idx-1,1,a,b-1,c))%1000000007;
    }
}
int main()
{
    int i,j,k;
    while(scanf("%s",str)!=EOF)
    {
        int l,p;
//        for(i=0;i<60;i++)
//            for(j=0;j<4;j++)
//                for(k=0;k<60;k++)
//                    for(l=0;l<60;l++)
//                        for(p=0;p<60;p++)
//                            jum[i][j][k][l][p]=-1;
        memset(jum,-1,sizeof jum);
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
        int chs=0;
        if(a>0)
            chs=0;
        else if(b>0)
            chs=1;
        else if(c>0)
            chs=2;
        printf("%lld\n",(3*dp(len-1,chs,a-1,b,c)))%1000000007;
    }
}
