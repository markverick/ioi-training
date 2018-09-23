#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[200135];
int a[200135];
int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int mn=2000000000;
    for(i=2;i<=n;i++)
    {
        if(s[i-1]=='R'&&s[i]=='L')
        {
            mn=min(mn,(a[i]-a[i-1])/2);
        }
    }
    if(mn==2000000000)
        printf("-1");
    else
        printf("%d\n",mn);
}
