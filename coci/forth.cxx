#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> x,y;
int main()
{
	int i,j,k,a,b;
	for(i=1;i<=3;i++)
    {
        scanf("%d %d",&a,&b);
        x.emplace_back(a);
        y.emplace_back(b);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    if(x[1]!=x[0])
        printf("%d ",x[0]);
    else
        printf("%d ",x[2]);
    if(y[1]!=y[0])
        printf("%d ",y[0]);
    else
        printf("%d ",y[2]);
}
