#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,int> p[10];
int ord[10];
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b,t=0,fk,out;
	double fs,md,ls,mc,x;
	while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            return 0;
        t++;mc=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            a*=60;b*=60;
            p[i]=MP(a,b);
            ord[i]=i;
        }
        do
        {
            fs=0;ls=1440*3600;
            while(abs(fs-ls)>0.00001)
            {
//                printf("%f %f %f\n",fs,md,ls);
                md=(fs+ls)/2;
                fk=0;
                x=-MI;
                for(i=0;i<n;i++)
                {
                    if((double)p[ord[i]].Y<x+md)
                    {
                        fk=1;
                        break;
                    }
                    x=max(x+md,(double)p[ord[i]].X);
                }
                if(fk==0)
                {
                    mc=max(mc,md);
                    fs=md;
                }
                else
                    ls=md;
            }
        }
        while(next_permutation(&ord[0],&ord[n]));
        out=nearbyint(mc);
        printf("Case %d: %d:%02d\n",t,out/60,out%60);
    }
}
