#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,int> p[10];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n=8,i,j,k,sum=0;
	for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i].X);
        p[i].Y=i;
    }
    sort(&p[1],&p[n+1]);
    vector<int> v;
    for(i=n;i>n-5;i--)
    {
        sum+=p[i].X;
        v.emplace_back(p[i].Y);
    }
    sort(v.begin(),v.end());
    printf("%d\n",sum);
    for(i=0;i<v.size();i++)
    {
        printf("%d ",v[i]);
    }
}
