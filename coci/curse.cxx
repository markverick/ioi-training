#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[1135],b[1135];
vector<pair<int,int> > v[135],u[135];
pair<int,int> p[1135],q[1135];
map<vector<pair<int,int> >,bool> hsh;
int main()
{
	//freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
	int i,j,k,r,c,n,mn,mm,cot=0;
	scanf("%d %d %d",&r,&c,&n);
	for(i=1;i<=n;i++)
    {
        mn=1000000000;mm=1000000000;
        for(j=1;j<=c;j++)
            scanf("%d",&a[j]),mm=min(mm,a[j]);
        for(j=1;j<=c;j++)
            scanf("%d",&b[j]),mn=min(mn,b[j]);
        for(j=1;j<=c;j++)
            v[i].emplace_back(b[j]-mn,r-a[j]-b[j]);
        for(j=c;j>=1;j--)
            u[i].emplace_back(a[j]-mm,r-a[j]-b[j]);
        if(hsh[v[i]]==0)
            cot++;
        hsh[v[i]]=1;
        hsh[u[i]]=1;
        v[i].clear();u[i].clear();
        for(j=c;j>=1;j--)
            v[i].emplace_back(b[j]-mn,r-a[j]-b[j]);
        for(j=1;j<=c;j++)
            u[i].emplace_back(a[j]-mm,r-a[j]-b[j]);
        hsh[v[i]]=1;
        hsh[u[i]]=1;
    }
    printf("%d",cot);
//    for(i=1;i<=n;i++)
//    {
//        for(j=0;j<v[i].size();j++)
//            printf("%d-%d ",v[i][j].X,v[i][j].Y);
//        printf("\n");
//    }
}
