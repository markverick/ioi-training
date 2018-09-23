#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int num[100135],cup[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,blk,L,R,n,m,x,y,sum=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=sqrt(n)+1;i++)
    {
        if(i*i>n)
        {
            blk=i-1;
            break;
        }
    }
//    printf("!%d\n",blk);
    for(i=1;i<=m;i++)
    {
//        memset(num,0,sizeof num);
//        memset(cup,0,sizeof cup);
        sum=0;
        scanf("%d %d",&y,&x);
        y=x+y-1;
        x--;y--;
        if(x/blk==y/blk)
        {
            if(x/blk==(n-1)/blk)
            {
                if(y==n-1&&x==(x/blk)*blk)
                {
                    cup[x/blk]++;
                    sum+=cup[x/blk];
                }
                else
                {
                    for(j=x;j<=y;j++)
                        num[j]++,sum+=num[j];
                }
            }
            else if(y-x+1==blk)
                cup[x/blk]++,sum+=cup[x/blk];
            else
            {
                for(j=x;j<=y;j++)
                    num[j]++,sum+=num[j];
            }
        }
        else
        {
            if(y/blk==(n-1)/blk)
            {
                if(y==n-1)
                    cup[y/blk]++,sum+=cup[y/blk];
                else
                    for(j=(y/blk)*blk;j<=y;j++)
                        num[j]++,sum+=num[j];
                y=(y/blk)*blk-1;
            }
//            printf("+%d\n",sum);
            if(x==0)
                L=0;
            else
                L=(x-1)/blk+1;
            R=(y+1)/blk-1;
//            printf("%d %d - %d %d\n",L,R,x,y);
            for(j=L;j<=R;j++)
                cup[j]++,sum+=cup[j];
//            printf("S- %d\n",sum);
            for(j=x;j<=L*blk-1;j++)
                num[j]++,sum+=num[j];
//            printf("S- %d\n",sum);
            for(j=y;j>=(R+1)*blk;j--)
                num[j]++,sum+=num[j];
//            printf("S- %d\n",sum);
        }
        printf("%d\n",sum);
    }
}
