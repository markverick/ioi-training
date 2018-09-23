#include<bits/stdc++.h>
#define MI 1000000000
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
	int i,j,k,bd,r,c,fs=0,md,ls=3000,mn=MI,x;
	scanf("%d",&bd);
	for(i=0;i<=3000;i++)
	{
	    if(i*(i+1)/2+1>=bd)
            break;
	}
	mn=i;
	printf("%d\n",mn);
    for(i=1;i<=mn;i++)
    {
        printf("%d %d %d %d\n",5000-i,-5000,-5000,-5000+i);
    }
}
