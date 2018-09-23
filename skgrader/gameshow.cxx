#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int ha[135],hb[135],A[135],B[135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b,m=100,x,y,mc=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        mc=0;
        scanf("%d %d",&a,&b);
        ha[a]++;hb[b]++;
        for(j=1;j<=m;j++)
            A[j]=ha[j],B[j]=hb[j];
        x=1;y=m;
        while(x<=100||y>=1)
        {
            k=min(A[x],B[y]);
            if(k)
                mc=max(mc,x+y);
            A[x]-=k;B[y]-=k;
            if(A[x]==0)
                x++;
            if(B[y]==0)
                y--;
        }
        printf("%d\n",mc);
    }

}