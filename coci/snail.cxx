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
	int a,b,c,fst,mid,lst,i,j,k,mn=2000000000;
	scanf("%d %d %d",&a,&b,&c);
	fst=0;lst=c+1;
	while(fst<=lst)
    {
        mid=(fst+lst)/2;
        if(mid*(a-b)+b>=c)
        {
            mn=min(mn,mid);
            lst=mid-1;
        }
        else
        {
            fst=mid+1;
        }
    }
    printf("%d",mn);
}
