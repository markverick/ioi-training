#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char ch[3];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,a,b;
	priority_queue<pair<int,int> > pq;
	scanf("%d %d",&n,&m);
	k=n+m;
	while(k--)
    {
        scanf("%s",ch);
        if(ch[0]=='T')
        {
            scanf("%d %d",&a,&b);
            pq.emplace(-a,b);
        }
        else
        {
            if(!pq.empty())
            {
                printf("%d\n",pq.top().Y);
                pq.pop();
            }
            else printf("0\n");
        }
    }
}
