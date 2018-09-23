#include<bits/stdc++.h>
#define MI 1000000000
#define EPS 0.000000001
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
priority_queue<int> pq;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,a,b,L,H,i,j,k;
	double bd;
	scanf("%d %d %d",&n,&L,&H);
	while(n--)
    {
        scanf("%d",&a);
        while(a--)
        {
            scanf("%d",&b);
            pq.emplace(b);
        }
        scanf("%d %d",&a,&b);
        bd=(double)H/b*a+L;
        while(!pq.empty()&&pq.top()>=bd-EPS)
        {
            pq.top();
            pq.pop();
        }
        printf("%d\n",pq.size());
    }
}
