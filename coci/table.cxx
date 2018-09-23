#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char maps[405][405];
int qs[405][405],r,c;
inline bool isFree(int x,int y,int X,int Y)
{
    if(qs[X][Y]-qs[X][y-1]-qs[x-1][Y]+qs[x-1][y-1]==0)
        return 1;
    return 0;
}
int main()
{
	int i,j,k,fst,mid,lst,mc=0,fu,fk;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
        for(j=1;j<=c;j++)
        {
            if(maps[i][j]=='X')
                qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+1;
            else
                qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    fst=2;lst=r+c;
    while(fst<=lst)
    {
        fu=0;
        mid=(fst+lst)/2;
//        printf("%d %d %d\n",fst,mid,lst);
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
//                j+mid-k-1<=c
//                j+mid-c-1<=k
//                i+k-1<=r
//                k<=r+1-i
                fk=min(mid-1,r-i+1);
                for(k=max(1,j+mid-c-1);k<=fk;k++)
                {
                    if(isFree(i,j,i+k-1,j+mid-k-1))
                    {
//                        printf("%d %d %d %d\n",i,j,k,mid-k);
                        fu=1;break;
                    }
                }
                if(fu==1)break;
            }
            if(fu==1)break;
        }
        if(fu==1)
        {
            mc=max(mc,mid);
            fst=mid+1;
        }
        else
        {
            lst=mid-1;
        }
    }
    if(mc>0)
        printf("%d",mc*2-1);
    else
        printf("0");
}
