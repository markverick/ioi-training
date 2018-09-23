#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int ft[22][300135],n;
void add(int x,int val,int t)
{
    while(x<=n)
    {
        ft[t][x]+=val;
        x+=x&-x;
    }
}
int sum(int x,int t)
{
    int sm=0;
    while(x>0)
    {
        sm+=ft[t][x];
        x-=x&-x;
    }
    return sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,m,t;
	long long cot=0;
	string s;
	cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        cin >> s;
        cot+=sum(i-1,s.size())-sum(max(0,i-m-1),s.size());
//        printf("%d %d\n",sum(i-1,s.size()),sum(max(0,i-m-1),s.size()));
        add(i,1,s.size());
    }
    printf("%lld",cot);
}
