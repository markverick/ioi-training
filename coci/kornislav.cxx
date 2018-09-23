#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[6];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n=4,r,c,mc=0;
	for(i=1;i<=4;i++)
        scanf("%d",&a[i]);
    sort(&a[1],&a[n+1]);
    do
    {
//        printf("%d %d %d %d\n",a[1],a[2],a[3],a[4]);
        r=min(a[1],a[2]);
        c=min(a[3],a[4]);
        mc=max(mc,r*c);
    }
    while(next_permutation(&a[1],&a[n+1]));
    printf("%d\n",mc);
}
