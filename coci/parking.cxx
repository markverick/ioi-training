#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int cost[6];
int hsh[135];
int main()
{
	int i,j,k,a,b;
	scanf("%d %d %d",&cost[1],&cost[2],&cost[3]);
    for(i=1;i<=3;i++)
    {
        scanf("%d %d",&a,&b);
        for(j=a;j<b;j++)
            hsh[j]++;
    }
    int sm=0;
    for(i=1;i<=100;i++)
        sm+=cost[hsh[i]]*hsh[i];
    printf("%d",sm);
}
