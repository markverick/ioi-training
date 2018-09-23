#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
tuple<int,int,int> v[1135];
int a[1135];
unordered_map<int,int> hsh,fst;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,c;
	scanf("%d %d",&n,&c);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        hsh[a[i]]++;
        if(fst[a[i]]==0)
            fst[a[i]]=i;
    }
    for(i=1;i<=n;i++)
        v[i]=MT(-hsh[a[i]],fst[a[i]],a[i]);
    sort(&v[1],&v[n+1]);
    for(i=1;i<=n;i++)
    {
        printf("%d ",get<2>(v[i]));
    }
}
