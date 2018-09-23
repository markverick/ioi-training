#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[1135],b[1135];
vector<pair<int,int> > v[135];
int main()
{
	//freopen("out.txt","w",stdout);
	freopen("in.txt","r",stdin);
	int i,j,k,r,c,n,mn;
	scanf("%d %d %d",&r,&c,&n);
	for(i=1;i<=n;i++)
    {
        mn=1000000000;
        for(j=1;j<=c;j++)
            scanf("%d",&a[j]);
        for(j=1;j<=c;j++)
            scanf("%d",&b[j]),mn=min(mn,b[j]);
        for(j=1;j<=c;j++)
            v[i].emplace_back(b[j]-mn,r-a[j]-b[j]);
    }
//    for(i=1;i<=n;i++)
//    {
//        for(j=0;j<v[i].size();j++)
//            printf("%d-%d ",v[i][j].X,v[i][j].Y);
//        printf("\n");
//    }
    sort(&v[1],&v[n+1]);
    int cot=1;
    for(i=2;i<=n;i++)
    {
        if(v[i]!=v[i-1])
            cot++;
    }
    printf("%d",cot);
}
