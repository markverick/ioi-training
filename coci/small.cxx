#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
set<int> x,y;
set<int> ::iterator I,J;
int main()
{
	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b,mc=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        x.insert(a);
        y.insert(b);
        J=y.end();J--;
        mc=0;
        for(I=x.begin();I!=x.end();I++,J--)
        {
            mc=max(mc,*I+*J);
        }
        printf("%d\n",mc);
    }
}
