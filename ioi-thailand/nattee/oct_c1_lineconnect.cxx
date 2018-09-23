#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int x[100135],hsh[100135],p[100135];
vector<int> v;
int Find(int x)
{
    if(x==p[x]) return x;
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
	int n,i,j,k,mn=MI,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        scanf("%d",&x[i]),p[i]=i;
    for(i=1;i<=n-2;i++)
        scanf("%d %d",&a,&b),Union(a,b);
    k=Find(a);
    for(i=1;i<=n;i++)
    {
        if(Find(i)==k)
            v.emplace_back(x[i]);
    }
    sort(v.begin(),v.end());
    for(i=1;i<=n;i++)
    {
        if(Find(i)!=k)
        {
            j=lower_bound(v.begin(),v.end(),x[i])-v.begin();
            if(j<v.size())
                mn=min(mn,abs(v[j]-x[i]));
            j--;
            if(j>=0)
                mn=min(mn,abs(v[j]-x[i]));
        }
    }
    printf("%d",mn);
}
