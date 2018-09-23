#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef pair<int,int> pii;
map<pii,int> mat;
int c[12000],d[12000];
int main()
{
    //freopen("xxx.output","w",stdout);
    int n,m,a,b,t,CHCK=0,chck=0;
    int i,j,k;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(chck!=0)
        {
            printf("\n");
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if(a==0)continue;
            for(j=1;j<=a;j++)
            {
                scanf("%d",&c[j]);
                d[c[j]]++;
            }
            for(j=1;j<=a;j++)
            {
                scanf("%d",&b);
                mat[mp(c[j],i)]=b;
            }
        }
        int co=0;
        printf("%d %d\n",m,n);
        for(i=1;i<=m;i++)
        {
            if(i!=1)printf("\n");
            if(d[i]!=0)
                printf("%d ",d[i]);
            for(j=1,co=0;j<=n;j++)
            {
                if(mat[mp(i,j)]==0)
                {
                    mat.erase(mp(i,j));
                    continue;
                }
                else
                {
                    co++;
                    if(co!=d[i])
                        printf("%d ",j);
                    else
                        printf("%d",j);
                }
            }
            if(d[i]!=0)printf("\n");
            CHCK=0;
            for(j=1,co=0;j<=n;j++)
            {
                if(mat[mp(i,j)]==0)
                {
                    mat.erase(mp(i,j));
                    continue;
                }
                else
                {
                    co++;
                    if(co!=d[i])
                        printf("%d ",mat[mp(i,j)]);
                    else
                        printf("%d",mat[mp(i,j)]);
                    CHCK=1;
                }
            }
            if(CHCK==0)
            {
                printf("0\n");
                CHCK=0;
            }



        }
        chck=1;
        a=0;b=0;mat.clear();memset(c,0,sizeof c);memset(d,0,sizeof d);
    }
    printf("\n");
}
