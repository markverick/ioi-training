#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,int> a[200135];
int b[200135],adap[200135],con[200135],A=0;
priority_queue<pair<int,pair<int,int> > > pq;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,cot=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
        scanf("%d",&a[i].X),a[i].Y=i;
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]),pq.emplace(b[i],MP(0,i));
    sort(&a[1],&a[n+1]);
    for(i=n;i>=1;i--)
    {
        while(!pq.empty()&&pq.top().X>a[i].X)
        {
            pq.emplace((pq.top().X-1)/2+1,MP(pq.top().Y.X-1,pq.top().Y.Y));
            pq.pop();
        }
        if(pq.empty())break;
        if(a[i].X==pq.top().X)
        {
            A-=pq.top().Y.X;
            adap[pq.top().Y.Y]-=pq.top().Y.X;
            con[a[i].Y]=pq.top().Y.Y;
            cot++;
            pq.pop();
        }
    }
    printf("%d %d\n",cot,A);
    for(i=1;i<=m;i++)
        printf("%d ",adap[i]);
    printf("\n");
    for(i=1;i<=n;i++)
        printf("%d ",con[i]);
}
