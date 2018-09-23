#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,int> p[100000];
int main()
{
    int n,m,i;
	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
    {
        scanf("%d %d",&p[i].X,&p[i].Y);
    }
    sort(&p[0],&p[m]);
    printf("%d %d\n",n,m);
    for(i=0;i<m;i++)
    {
        printf("%d %d\n",p[i].X,p[i].Y);
    }
}
