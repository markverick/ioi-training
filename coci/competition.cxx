#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int d[12],r[12];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,R,D;
	scanf("%d %d %d",&n,&D,&R);
	for(i=1;i<=D;i++)
    {
        scanf("%d",&j);
        d[j]=1;
    }
    for(i=1;i<=R;i++)
    {
        scanf("%d",&j);
        if(d[j]==0)
            r[j]=1;
        else
            d[j]=0;
    }
    int cot=0;
    for(i=1;i<=n;i++)
    {
        if(d[i])
        {
            if(r[i-1]==1)
                r[i-1]=0;
            else if(r[i+1]==1)
                r[i+1]=0;
            else
                cot++;
        }
    }
    printf("%d",cot);
}
