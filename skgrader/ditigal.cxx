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
	int n,i,j,k,x,y;
	string s,a="BLJTV1",b="BLJTV2";
	cin >> n;
	for(i=1;i<=n;i++)
    {
        cin >>s;
        if(s==a)
            x=i;
        if(s==b)
            y=i;
    }
    if(x>y)
        y++;
    for(i=2;i<=x;i++)
        printf("1");
    for(i=2;i<=x;i++)
        printf("4");
    for(i=2;i<=y;i++)
        printf("1");
    for(i=3;i<=y;i++)
        printf("4");
}
