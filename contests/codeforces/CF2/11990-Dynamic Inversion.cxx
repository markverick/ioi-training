#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[200135],pos[200135],hsh[200135],n,x,y,val,z;
pair<int,int> seg[800135];
void build(int id,int fs,int ls)
{
    int md=(fs+ls)/2;
    if(fs==ls)
    {
        seg[id]=MP(a[fs],a[ls]);
        return;
    }
    build(id*2,fs,md);
    build(id*2+1,md+1,ls);
    seg[id]=MP(min(seg[id*2].X,seg[id*2+1].X),max(seg[id*2].Y,seg[id*2+1].Y));
}
void upd(int id,int fs,int ls)
{
    int md=(fs+ls)/2;
    if(fs==ls)
    {
        seg[id]=MP(n+1,0);
        return;
    }
    if(z<=md)
        upd(id*2,fs,md);
    else
        upd(id*2+1,md+1,ls);
    seg[id]=MP(min(seg[id*2].X,seg[id*2+1].X),max(seg[id*2].Y,seg[id*2+1].Y));
}
int Find(int id,int fs,int ls,int ch)
{
    if(fs==ls)
    {
        if(hsh[fs])
            return 0;
    }
    int md=(fs+ls)/2;
    if(y<fs||x>ls)
        return 0;
//    printf("%d %d %d %d\n",id,fs,ls,ch);
    if(fs>=x&&ls<=y)
    {
        if(ch==0)
        {
            if(val>seg[id].Y)
                return ls-fs+1;
            if(val<seg[id].X)
                return 0;
        }
        else
        {
            if(val<seg[id].X)
                return ls-fs+1;
            if(val>seg[id].Y)
                return 0;
        }
        return Find(id*2,fs,md,ch)+Find(id*2+1,md+1,ls,ch);
    }
    return Find(id*2,fs,md,ch)+Find(id*2+1,md+1,ls,ch);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	long long sm=0,sum;
	vector<long long> v;
	while(scanf("%d %d",&n,&m)!=EOF)
    {
        sum=0;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]),pos[a[i]]=i;
        build(1,1,n);
        v.clear();
        memset(hsh,0,sizeof hsh);
        while(m--)
        {
            scanf("%d",&val);
            z=pos[val];
            x=1;y=z-1;
            sm=0;
            if(y>=1)
                sm+=Find(1,1,n,1);
//                printf("%d ",sm);
            x=z+1;y=n;
            if(x<=n)
                sm+=Find(1,1,n,0);
//            printf("-> %d\n",sm);
            upd(1,1,n);
            sum+=sm;
//            printf("> %d\n",sm);
            v.emplace_back(sm);
            hsh[z]=1;
        }
        for(i=0;i<v.size();i++)
        {
            printf("%lld\n",sum);
            sum-=v[i];
        }
    }
}
