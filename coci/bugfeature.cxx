#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char a[135][22],b[135][22];
int c[135],d[1100005];
priority_queue<pair<int,int> > pq;
int main()
{
	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,w,bit,v,fk=0,T=0;
	while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            return 0;
        T++;
        for(i=1;i<=m;i++)
        {
            scanf("%d %s %s",&c[i],a[i],b[i]);
        }
        for(i=0;i<=1100000;i++)
            d[i]=MI;
        d[0]=0;
        pq.emplace(0,0);
        while(!pq.empty())
        {
            tie(w,bit)=pq.top();
            w=-w;
//            printf("!%d %d\n",w,bit);
            pq.pop();
            for(i=1;i<=m;i++)
            {
                fk=0;
                for(j=0;j<n;j++)
                {
                    k=((1<<j)|bit)==bit;
                    if(k==0&&a[i][j]=='-')
                    {
                        fk=1;break;
                    }
                    if(k&&a[i][j]=='+')
                    {
                        fk=1;break;
                    }
                }
                if(fk)
                    continue;
                v=bit;
                for(j=0;j<n;j++)
                {
                    if(b[i][j]=='-')
                        v|=(1<<j);
                    else if(b[i][j]=='+')
                        v&=~(1<<j);
                }
                if(d[v]>w+c[i])
                {
                    d[v]=w+c[i];
                    pq.emplace(-d[v],v);
                }
            }
        }
        k=d[(1<<n)-1];
        printf("Product %d\n",T);
        if(k==MI)
            printf("Bugs cannot be fixed.\n\n");
        else
            printf("Fastest sequence takes %d seconds.\n\n",k);
    }
}
