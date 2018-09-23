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
	int i,j,k,out,in;
	scanf("%d %d",&out,&in);
	k=(out+4)/2;
	for(i=1;i<k;i++)
    {
        j=k-i;
        if((i-2)*(j-2)==in)
        {
            printf("%d %d",max(i,j),min(i,j));
            break;
        }
    }
}
