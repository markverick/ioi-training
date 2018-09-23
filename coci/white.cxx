#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[10]={1,1,2,2,2,8};
int main()
{
	int i,j,k;
	for(i=0;i<6;i++)
    {
        scanf("%d",&j);
        printf("%d ",a[i]-j);
    }
}
