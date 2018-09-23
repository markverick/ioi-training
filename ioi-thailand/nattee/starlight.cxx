#include<bits/stdc++.h>
#define EPS 0.000000001
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int x[5135],y[5135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,s,n,fk;
	double fs,md,ls,mn;
	scanf("%d %d",&s,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    x[n+1]=s;
    y[n+1]=s;
    sort(&x[1],&x[n+1]);
    sort(&y[1],&y[n+1]);
    fs=0;ls=s;mn=s;
    while(abs(ls-fs)>=EPS)
    {
        md=(fs+ls)/2;
        fk=0;
        x[0]=-md;x[n+1]=s+md;
        y[0]=-md;y[n+1]=s+md;
        for(i=0;i<=n;i++)
        {
            if(x[i+1]-x[i]>md*2)
            {
                fk++;
                break;
            }
        }
        for(i=0;i<=n;i++)
        {
            if(y[i+1]-y[i]>md*2)
            {
                fk++;
                break;
            }
        }
        if(fk<2)
        {
            mn=min(mn,md);
            ls=md;
        }
        else
            fs=md;
    }
    printf("%.3f",mn);
}
