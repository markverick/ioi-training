#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135],b[100135],mc[7];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    for(k=1;k<=5;k++)
    {
        j=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]==k||b[i]==k)
                j++;
            else
                j=0;
            mc[k]=max(mc[k],j);
            m=max(m,j);
        }
    }
    for(k=1;k<=5;k++)
    {
        if(mc[k]==m)
        {
            printf("%d %d",m,k);
            return 0;
        }
    }
}
