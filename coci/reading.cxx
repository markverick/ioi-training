#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[55];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n;
	string mn={'z'+1},x;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n-2;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            x.clear();
            for(k=i;k>=1;k--)
                x.push_back(s[k]);
            for(k=j;k>i;k--)
                x.push_back(s[k]);
            for(k=n;k>j;k--)
                x.push_back(s[k]);
            if(mn>x)
                mn=x;
        }
    }
    cout << mn;
}
