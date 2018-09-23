#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int ft[100135],w[100135];
priority_queue<pair<int,int> > pq;
void add(int x,int val)
{
    while(x<=100000)
    {
        ft[x]+=val;
        x+=x&-x;
    }
}
int sum(int x)
{
    int sm=0;
    while(x>0)
    {
        sm+=ft[x];
        x-=x&-x;
    }
    return sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n=0,i,j,k,ch,m,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&ch);
        if(ch==1)
        {
            scanf("%d",&w[++n]);
            w[n]++;
            pq.emplace(-w[n],n);
            add(w[n],1);
        }
        else if(ch==2)
        {
            tie(j,k)=pq.top();
            pq.pop();
            printf("%d\n",k);
            add(-j,-1);
        }
        else
        {
            scanf("%d",&j);
            printf("%d\n",sum(w[j]-1));
        }
    }
}
