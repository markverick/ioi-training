#include<stdio.h>
#include<queue>
#include<stdlib.h>
#define MP(x,y,z) make_pair(x,make_pair(y,z))
using namespace std;

priority_queue<pair<int,pair<int,int> > > pq;
int x[60000],y[60000];
int ob[1200][1200];
int chk[1200][1200];
int n,xS,yS;
int hix=0,hiy=0;
int main()
{
    scanf("%d %d %d",&n,&xS,&yS);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        ob[x[i]][y[i]]=1;
        hix=max(hix,x[i]);
        hiy=max(hiy,y[i]);
    }
    pq.push(MP(0,-xS,-yS));
    chk[xS][yS]=1;
    int c=1;
    while(!pq.empty())
    {
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        c=pq.top().first;
        //printf("%d %d %d %d\n",-c,-a,-b,pq.size());
        //printf("%d %d %d %d\n",-c,-a,-b,pq.size());
       // printf("=%d\n",ob[-a][-b]);
        //system("pause");
        pq.pop();
        if(a==0&&b==0)
        {
            printf("%d\n",-c);
            exit(0);
        }
        if(a+1<=0&&chk[-a-1][-b]==0)
        {
            chk[-a-1][-b]=1;
            if(ob[-a-1][-b]==0)
                pq.push(MP(c,a+1,b));
            else
                pq.push(MP(c-1,a+1,b));
        }
        if(b+1<=0&&chk[-a][-b-1]==0)
        {
            //printf("F");
            chk[-a][-b-1]=1;
            if(ob[-a][-b-1]==0)
                pq.push(MP(c,a,b+1));
            else
                pq.push(MP(c-1,a,b+1));
        }
        if(chk[-a+1][-b]==0)
        {
            //printf("F");
            chk[-a+1][-b]=1;
            if(ob[-a+1][-b]==0)
                pq.push(MP(c,a-1,b));
            else
                pq.push(MP(c-1,a-1,b));
        }
        if(chk[-a][-b+1]==0)
        {
            chk[-a][-b+1]=1;
            if(ob[-a][-b+1]==0)
                pq.push(MP(c,a,b-1));
            else
                pq.push(MP(c-1,a,b-1));
        }
    }
    if(c==1)
        printf("-1");
}
