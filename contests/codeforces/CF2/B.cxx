#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[200135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]<0)
        {
            printf("NO");
            return 0;
        }
        a[i]%=2;
        if(a[i])
            a[i]--,a[i+1]--;
    }
    if(a[n+1]<0)
    {
        printf("NO");
        return 0;
    }
    printf("YES");
}
