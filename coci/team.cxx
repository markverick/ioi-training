#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,a,b,c,mc=0;
	scanf("%d %d %d",&a,&b,&c);
    for(i=0;i<=c;i++)
    {
        if(a-i>=0&&b-(c-i)>=0)
        {
            mc=max(mc,min((a-i)/2,b-(c-i)));
        }
    }
    printf("%d",mc);
}
