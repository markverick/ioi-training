#include<bits/stdc++.h>
using namespace std;
int p[200135],num[200135],id[200135],n;
long long s[200135];
//persistent union find!
int Find(int x)
{
    while(x!=p[x])
    {
        x=p[x];
    }
    return x;
}
void Union(int x,int y)
{
    x=Find(x);y=Find(y);
    if(x!=y)
    {
        if(rand()%2)
        {
            p[y]=x;
            s[x]+=s[y];
            num[x]+=num[y];
        }
        else
        {
            p[x]=y;
            s[y]+=s[x];
            num[y]+=num[x];
        }
    }
}
void Move(int x,int y)
{
    int xx=Find(id[x]),yy=Find(id[y]);
    if(xx==yy)
        return;
    s[xx]-=x;
    num[xx]--;
    id[x]=++n;
    s[id[x]]=x;
    num[id[x]]=1;
    Union(id[x],yy);
}

int main()
{
//    freopen("out.txt","w",stdout);
    int i,j,k,m,ch,a,b;
    srand(127);
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(i=1;i<=2*n;i++)
        {
            p[i]=i;s[i]=i;num[i]=1;id[i]=i;
        }
        while(m--)
        {

            scanf("%d",&ch);
            if(ch==1)
            {
                scanf("%d %d",&a,&b);
                Union(id[a],id[b]);
            }
            else if(ch==2)
            {
                scanf("%d %d",&a,&b);
                Move(a,b);
            }
            else
            {
                scanf("%d",&a);
                printf("%d %lld\n",num[Find(id[a])],s[Find(id[a])]);
            }
//            for(i=1;i<=n;i++)
//            {
//                printf("%d %d, ",num[Find(i)],s[Find(i)]);
//            }
//            printf("\n");
        }
    }
}
