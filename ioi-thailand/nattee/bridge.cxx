#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135],b[100135],pos[100135],c[100135];
vector<int> v;
vector<int> ::iterator it;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        pos[b[i]]=i;
    }
    for(i=1;i<=n;i++)
        c[i]=pos[a[i]];
//    for(i=1;i<=n;i++)
//        printf("%d ",c[i]);
    for(i=1;i<=n;i++)
    {
        it=lower_bound(v.begin(),v.end(),c[i]);
        if(it!=v.end())
            v[it-v.begin()]=c[i];
        else
            v.emplace_back(c[i]);
    }
    printf("%d",v.size());
}
