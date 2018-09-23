#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hsh[1111];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,l=0;
    scanf("%d %d",&n,&k);
    for(i=2;i<=n;i++)
    {
        if(hsh[i]==0)
        {
            for(j=i;j<=n;j+=i)
            {
                if(hsh[j]==0)
                {
                    hsh[j]=1;
                    l++;
                    if(l==k)
                    {
                        printf("%d",j);
                        return 0;
                    }
                }
            }
        }
    }
}
