#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,T,m,fs,md,ls,cot=0,mn;
	scanf("%d",&T);
	while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d",&a[i]);
            a[i]*=2;
        }
        sort(&a[1],&a[m+1]);
        fs=0;md=0;ls=a[m]-a[1];mn=a[m]-a[1];
        while(fs<=ls)
        {
            md=(fs+ls)/2;
//            printf("%d <- %d -> %d\n",fs,md,ls);
            j=a[1]+md;
            cot=1;
            for(i=1;i<=m;i++)
            {
                if(a[i]>j+md)
                {
                    j=a[i]+md;
                    cot++;
                }
            }
            if(cot<=n)
            {
                mn=min(mn,md);
                ls=md-1;
            }
            else
                fs=md+1;
        }
        if(mn%2==0)
            printf("%d.0\n",mn/2);
        else
            printf("%d.5\n",mn/2);
    }
}
