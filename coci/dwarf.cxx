#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[12];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,sum=0;
    for(i=1;i<=9;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=9;i++)
    {
        for(j=i+1;j<=9;j++)
        {
            sum=0;
            for(k=1;k<=9;k++)
            {
                if(k!=i&&k!=j)
                    sum+=a[k];
            }
            if(sum==100)
            {
                for(k=1;k<=9;k++)
                {
                    if(k!=i&&k!=j)
                        printf("%d\n",a[k]);
                }
                return 0;
            }
        }
    }
}
