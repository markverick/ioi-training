#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int L[300135],R[300135];
int bk[300135],p[300135];
int Find(int x)
{
    if(x==p[x])return x;
    return p[x]=Find(p[x]);
}
void Union(int x,int y)
{
    x=Find(x);y=Find(y);
    p[x]=y;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)p[i]=i,bk[i]=i;
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        L[R[b]]=bk[Find(a)];
        R[bk[Find(a)]]=R[b];
        R[b]=a;
        L[a]=b;
        if(!R[bk[Find(a)]])
            bk[Find(b)]=bk[Find(a)];
        Union(a,b);
    }
    i=Find(1);
    while(i)
    {
        printf("%d ",i);
        i=R[i];
    }
}
