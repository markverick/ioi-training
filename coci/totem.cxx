#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[1000135],b[1000135],d[1000135],tma[1000135],l[1000135],r[1000135],h[1000135],u,w,n,m;
priority_queue<pair<int,int> > pq;
void append(int x,int val,int ch)
{
	if(x<1||x>m)return;
	if(ch==0)
		if(val!=a[x])return;
	if(ch)
		if(val!=b[x])return;
	if(w+1<d[x])
	{
		d[x]=w+1;
		tma[x]=u;
		pq.emplace(-d[x],x);
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d",&n);
	m=n*n-n/2;
	k=0;
	for(i=1;i<=n;i++)
	{
		if(i%2)
		{
			l[k+1]=1;
			for(j=1;j<=n;j++)
			{
				k++;
				scanf("%d %d",&a[k],&b[k]);
				h[k]=1;
			}
			r[k]=1;
		}
		else
		{
			l[k+1]=1;
			for(j=1;j<n;j++)
			{
				k++;
				scanf("%d %d",&a[k],&b[k]);
				h[k]=0;
			}
			r[k]=1;
		}
	}
	for(i=1;i<=m;i++)
		d[i]=MI;
	d[1]=1;
	pq.emplace(-1,1);
	while(!pq.empty())
	{
		tie(w,u)=pq.top();pq.pop();w=-w;
		if(h[u])
		{
			if(l[u])
			{
				append(u+1,b[u],0);
				append(u-n+1,b[u],0);
				append(u+n,b[u],0);	
				continue;
			}
			if(r[u])
			{
				append(u-1,a[u],1);
				append(u-n,a[u],1);
				append(u+n-1,a[u],1);
				continue;
			}
			append(u-1,a[u],1);
			append(u-n,a[u],1);
			append(u+n-1,a[u],1);
			append(u+1,b[u],0);
			append(u-n+1,b[u],0);
			append(u+n,b[u],0);
		}
		else
		{
			if(l[u])
			{
				append(u-n,a[u],1);
				append(u+n-1,a[u],1);
				append(u+1,b[u],0);
				append(u-n+1,b[u],0);
				append(u+n,b[u],0);
				continue;
			}
			if(r[u])
			{
				append(u-1,a[u],1);
				append(u-n,a[u],1);
				append(u+n-1,a[u],1);
				append(u-n+1,b[u],0);
				append(u+n,b[u],0);
				continue;
			}
			append(u-1,a[u],1);
			append(u-n,a[u],1);
			append(u+n-1,a[u],1);
			append(u+1,b[u],0);
			append(u-n+1,b[u],0);
			append(u+n,b[u],0);
		}
		
	}
	vector<int> v;
	for(i=m;i>=1;i--)
	{
		if(d[i]<MI)
		{
			k=i;
			printf("%d\n",d[k]);
			while(k)
			{
				v.emplace_back(k);
				k=tma[k];
			}
			for(i=v.size()-1;i>=0;i--)
				printf("%d ",v[i]);
			break;
		}
		// printf("Shorest Path = %d, From %d\n",d[i],tma[i]);
	}
}