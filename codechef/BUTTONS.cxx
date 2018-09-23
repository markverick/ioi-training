#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[1135][1135],b[1135][1135],c[1135][1135],hx[1135],hy[1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,T,x,y,n,f;
	scanf("%d",&T);
	while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&b[i][j]);
                c[i][j]=a[i][j]^b[i][j];
            }
        }
        if(c[1][1]==1)
        {
            x=0;y=0;
            memset(hx,0,sizeof hx);
            memset(hy,0,sizeof hy);
            hx[1]=1;x++;
            for(i=2;i<=n;i++)
                if(!c[1][i])
                    hy[i]=1,y++;
            for(i=2;i<=n;i++)
                if(c[i][1])
                    hx[i]=1,x++;
            f=0;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    if(c[i][j]^hx[i]^hy[j])
                        {f=1;break;}
            if(f==0)
            {
                printf("%d\n",x);
                for(i=1;i<=n;i++)
                    if(hx[i])
                        printf("%d\n",i-1);
                printf("%d\n",y);
                for(i=1;i<=n;i++)
                    if(hy[i])
                        printf("%d\n",i-1);
                continue;
            }
            memset(hx,0,sizeof hx);
            memset(hy,0,sizeof hy);
            x=0;y=0;
            hx[1]=1;x++;
            for(i=2;i<=n;i++)
                if(!c[1][i])
                    hy[i]=1,y++;
            for(i=2;i<=n;i++)
                if(c[i][1])
                    hx[i]=1,x++;
            f=0;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    if(c[i][j]^hx[i]^hy[j])
                        {f=1;break;}
            if(f==0)
            {
                printf("%d\n",x);
                for(i=1;i<=n;i++)
                    if(hx[i])
                        printf("%d\n",i-1);
                printf("%d\n",y);
                for(i=1;i<=n;i++)
                    if(hy[i])
                        printf("%d\n",i-1);
                continue;
            }
        }
        else
        {
            x=0;y=0;
            memset(hx,0,sizeof hx);
            memset(hy,0,sizeof hy);
            hx[1]=1;x++;
            hy[1]=1;y++;
            for(i=2;i<=n;i++)
                if(!c[1][i])
                    hy[i]=1,y++;
            for(i=2;i<=n;i++)
                if(!c[i][1])
                    hx[i]=1,x++;
            f=0;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    if(c[i][j]^hx[i]^hy[j])
                        {f=1;break;}
            if(f==0)
            {
                printf("%d\n",x);
                for(i=1;i<=n;i++)
                    if(hx[i])
                        printf("%d\n",i-1);
                printf("%d\n",y);
                for(i=1;i<=n;i++)
                    if(hy[i])
                        printf("%d\n",i-1);
                continue;
            }
            memset(hx,0,sizeof hx);
            memset(hy,0,sizeof hy);
            x=0;y=0;
            for(i=2;i<=n;i++)
                if(c[1][i])
                    hy[i]=1,y++;
            for(i=2;i<=n;i++)
                if(c[i][1])
                    hx[i]=1,x++;
            f=0;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    if(c[i][j]^hx[i]^hy[j])
                        {f=1;break;}
            if(f==0)
            {
                printf("%d\n",x);
                for(i=1;i<=n;i++)
                    if(hx[i])
                        printf("%d\n",i-1);
                printf("%d\n",y);
                for(i=1;i<=n;i++)
                    if(hy[i])
                        printf("%d\n",i-1);
                continue;
            }
        }
        printf("-1\n");
    }
}
