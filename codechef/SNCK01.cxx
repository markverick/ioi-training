#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
int a[55];
using namespace std;
int main()
{
    int T,r,c,i,j,k,x=0,id;
    scanf("%d",&T);
    while(T--)
    {
        x=0;
        scanf("%d %d",&r,&c);
        for(i=1;i<=r;i++)
        {
            id=0;
            for(j=1;j<=c;j++)
            {
                scanf("%d",&a[j]);
            }
            for(j=c;j>=1;j--)
            {
                if(a[j]==0)continue;
                if(id<a[j])
                    id=a[j];
                else
                    id=a[j]-1;
            }
            x^=id;
//            printf("%d\n",id);
        }
        if(!x)
            printf("SECOND\n");
        else
            printf("FIRST\n");
    }
}
