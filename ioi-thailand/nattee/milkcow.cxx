#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int qs[1000135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,mc,MC,cot,COT,a,b,st=MI,ed=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        st=min(st,a);
        ed=max(ed,b);
        qs[a]++;
        qs[b]--;
    }
    cot=0;COT=0;mc=0;MC=0;
    for(i=st;i<ed;i++)
    {
        qs[i]+=qs[i-1];
        if(qs[i])
            cot++,COT=0;
        else
            cot=0,COT++;
//        printf("%d\n",COT);
        mc=max(mc,cot);
        MC=max(MC,COT);
    }
    printf("%d %d",mc,MC);
}
