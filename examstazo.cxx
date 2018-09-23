#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
class Query
{
    public:
        int op,a,b,id;

};
int seg[800005];
int val;
pair<int,int> p[200005];
void add(int l,int r,int idx)
{
    if(l==r)
    {
        seg[idx]=max(seg[idx],p[val].X);
        return;
    }
    int mid=(l+r)/2;
    if(p[val].Y<=mid) add(l,mid,idx*2);
    else add(mid+1,r,idx*2+1);
    seg[idx]=max(seg[idx*2],seg[idx*2+1]);
}
int d,res;
bool sum(int l,int r,int idx)
{
    if(p[d].Y+1>r||seg[idx]<p[d].X) return 0;
    if(l==r)
    {
        res=l;
        return 1;
    }
    int mid=(l+r)/2,op;
    op=sum(l,mid,idx*2);
    if(op) return 1;
    return sum(mid+1,r,idx*2+1);
}

Query a[200005];
vector<pair<int,int> > fs,fs1;
char s[5];
set<pair<int,int> > kb[200005];
set<pair<int,int> >::iterator it;
int main()
{
    int m,i,j,n=0,ct;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%s",&s);
        if(s[0]=='D')
        {
            scanf("%d%d",&a[i].a,&a[i].b);
            a[i].op=1;
            fs1.emplace_back(a[i].b,i);
            fs.emplace_back(a[i].a,i);
        }
        else
        {
            scanf("%d",&a[i].id);
            a[i].op=2;
        }
    }

    sort(fs.begin(),fs.end());
    for(i=0,n=0;i<fs.size();i++)
    {
        if(i==0||fs[i].X!=fs[i-1].X) n++;
        a[fs[i].Y].a=n;
    }
    sort(fs1.begin(),fs1.end());
    for(i=0,n=0;i<fs1.size();i++)
    {
        if(i==0||fs1[i].X!=fs1[i-1].X) n++;
        a[fs1[i].Y].b=n;
    }

    for(i=0,ct=0;i<m;i++)
    {
        if(a[i].op==1)
        {
            //printf("D %d %d\n",a[i].a,a[i].b);
            ct++;
            p[ct]={a[i].a,a[i].b};
            kb[p[ct].Y].insert({p[ct].X,ct});

            val=ct;
            add(1,n,1);
        }
        else
        {
            d=a[i].id;
            it=kb[p[d].Y].lower_bound({p[d].X+1,0});
            //printf("%d %d==>",p[d].X,p[d].Y);
            if(it!=kb[p[d].Y].end())
            {
                printf("%d\n",(*it).Y);
                continue;
            }
            res=-1;
            sum(1,n,1);
            if(res==-1) printf("NE\n");
            else
            {
                it=kb[res].lower_bound({p[d].X,0});
                printf("%d\n",(*it).Y);
            }
        }
    }

}
