#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int fac[14],hsh[14],out[14];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,L,bd,i,j,k,l;
	scanf("%d %d %d",&n,&m,&L);
	L--;
	fac[1]=1;
	fac[2]=n-m+1;
	for(i=3;i<=n;i++)
    {
        fac[i]=fac[i-1]*(i+n-m-1);
    }
    bd=m;
//    printf("%d\n",bd);
    k=L;
    for(i=m;i>=1;i--)
    {
        j=k/fac[i]+1;
//        printf("!%d\n",j);
        for(l=1;l<=n;l++)
        {
            if(!hsh[l])j--;
            if(j==0)
            {
                hsh[l]=1;
                out[m-i+1]=l;
                break;
            }
        }
        k%=fac[i];
    }
    for(i=1;i<=m;i++)
        printf("%d ",out[i]);
}
