#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
queue<pair<int,int> > q;
int jum[1135];
int jj[1135][1135];
int ban[15];
int main()
{
    int n,i,a,b,c;
    scanf("%d",&n);
    q.emplace(n,0);
    for(i=0;i<1135;i++)
        jum[i]=1000000000;
    while(!q.empty())
    {
        a=q.front().X;c=q.front().Y;
        q.pop();
        b=a;
        //printf("%d\n",a);
        if(jj[a][c]==1)
            continue;
        jj[a][c]=1;
    //printf("%d %d\n",a,b);
        /*if(jum[a]<c)
        {
            printf("FFF");
            continue;
        }*/
        if(a==1)
        {
            printf("%d",c);
            return 0;
        }
        for(i=2;i<=6;i++)
            ban[i]=0;
        while(b>0)
        {
            ban[b%10]=1;
            b/=10;
        }
        for(i=2;i<=5;i++)
        {
            if(a%i==0)
                ban[i]=1;
        }
        for(i=2;i<=5;i++)
        {
            if(ban[i]==0)
            {
                if(a-i>0)
                {
                    if(jum[a-i]>c+1)
                    {
                        jum[a]=min(jum[a-i],c+1);
                        q.emplace(a-i,c+1);
                    }
                }
            }
        }
    }
    printf("-1");
}
