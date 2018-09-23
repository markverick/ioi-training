#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hsh[1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,len,R,L,cot,id,mc=-1,x,MC=-1,X;
	scanf("%d %d",&len,&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d",&L,&R);
        cot=0;
        for(j=L;j<=R;j++)
        {
            if(!hsh[j])
                cot++;
            hsh[j]=1;
        }
        if(mc<cot)
            mc=cot,x=i;
        if(MC<R-L+1)
            MC=R-L+1,X=i;
    }
    printf("%d\n%d",X,x);
}
