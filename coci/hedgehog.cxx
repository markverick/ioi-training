#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int cap[2000135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,l,p,r,c,x,inv=0,col;
	long long cot=0,n;
    scanf("%d %d",&r,&c);
    scanf("%lld",&n);
    if(r>c)
    {
        inv=1;
        swap(r,c);
    }
    for(x=0;x<=r+c-2;x++)
    {
        if(x<r)
            cap[x]=x+1;
        else if(x>=r&&x<c)
            cap[x]=r;
        else
            cap[x]=r+c-x-1;
//        printf("%d ",cap[x]);
    }
//    printf("\n");
    long long sum=0;
    for(x=0;x<=r+c-2;x++)
    {
        if(sum+cap[x]>n)
        {
            x--;
            break;
        }
        sum+=cap[x];
    }
//    printf("X = %d\n",x);
    cot=0;
    for(i=0;i<=min(r-1,x);i++)
    {
        col=x-i;
        col=min(col,c-1);
        j=col;
//        printf("!%d %d\n",i,j);
        if((j&i)==0)
            cot++;
        l=0;
        while(j>0)
            j>>=1,l++;
        for(l=l-1;l>=0;l--)
        {
            j=(1<<l);
//            printf("%d %d\n",j,col);
            if((j&col)==0)
                continue;
            k=j>>1;
            p=1;
            while(k>0)
            {
                if((i&k)==0)
                    p<<=1;
                k>>=1;
            }
            cot+=p;
            if((j&i))
            {
                break;
            }
        }
//        printf("%d\n",cot);
    }
    k=n-sum;
//    printf("%d\n",k);
    if(((x+1)%2)^inv==0)
    {
        for(i=r-1;i>=0;i--)
        {
            j=x+1-i;
            if(j>=0&&j<c)
            {
                if(k==0)
                    break;
                k--;
                if((j&i)==0)
                {
                    cot++;
                }
            }
        }
    }
    else
    {
        for(i=0;i<r;i++)
        {
            j=x+1-i;
            if(j>=0&&j<c)
            {
                if(k==0)
                    break;
                k--;
                if((j&i)==0)
                {
                    cot++;
                }
            }
        }
    }
    printf("%lld",cot);
}
