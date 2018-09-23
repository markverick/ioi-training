#include<bits/stdc++.h>
using namespace std;
char str[135];
int n,len,x,y;
int N,E,W,S;
int main()
{
    int i;
    scanf("%s",str);
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='N')
        {
            x++;N++;
        }
        else if(str[i]=='S')
        {
            x--;S++;
        }
        else if(str[i]=='E')
        {
            y++;E++;
        }
        else if(str[i]=='W')
        {
            y--;W++;
        }
    }
    scanf("%d",&n);
    int mc=0;
    if(x>=0&&y>=0)
    {
        mc=min(n,S+W);
        n-=min(n,S+W);
    }
    if(x<0&&y>=0)
    {
        mc=min(n,N+W);
        n-=min(n,N+W);
    }
    if(x>=0&&y<0)
    {
        mc=min(n,S+E);
        n-=min(n,S+E);
    }
    if(x<0&&y<0)
    {
        mc=min(n,N+E);
        n-=min(n,N+E);
    }
    printf("%d",(abs(x)+abs(y)+mc-n)*2);
}
