#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int a[200135],b[200135],seg[800135],n=0,k,toAdd,val,no[200135],on[200135];
char ch[200135][3];
unordered_map<int,int> mx,my;
map<pair<int,int>,int> mp;
set<pair<int,int> > lst[200135];
set<pair<int,int> > ::iterator it;
vector<int> x,y;
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]=max(seg[idx],val);
        return;
    }
    if(toAdd<=mid)
    {
        add(idx*2,fst,mid);
    }
    else
    {
        add(idx*2+1,mid+1,lst);
    }
    seg[idx]=max(seg[idx*2],seg[idx*2+1]);
}
int Find(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2,tmp=0;
//    printf("%d <- %d -> %d !%d\n",fst,mid,lst,b[k]);
    if(fst==lst)
    {
        if(seg[idx]>=a[k])
            return fst;
        else
            return 0;
    }
    if(b[k]+1>lst)
    {
        return 0;
    }
    if(b[k]+1>=mid+1)
    {
//        printf("%d %d\n",seg[idx*2+1],a[k]);
        if(seg[idx*2+1]>=a[k])
            return Find(idx*2+1,mid+1,lst);
        else
            return 0;
    }
    else
    {
        if(seg[idx*2]>=a[k])
        {
            tmp=Find(idx*2,fst,mid);
            if(tmp)
            {
                return tmp;
            }
            else
            {
                if(seg[idx*2+1]>=a[k])
                    return Find(idx*2+1,mid+1,lst);
                else
                    return 0;
            }
        }
        else
        {
            if(seg[idx*2+1]>=a[k])
                return Find(idx*2+1,mid+1,lst);
            else
                return 0;
        }
    }
}
int main()
{
//    freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
    int T,i,j,tmp;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%s",ch[i]);
        if(ch[i][0]=='D')
        {
            scanf("%d %d",&a[i],&b[i]);
            n++;
            x.emplace_back(a[i]);
            y.emplace_back(b[i]);
            no[i]=n;
            on[n]=i;
//            c[n]=MP(MP(a[i],b[i]),i);
        }
        else
        {
            scanf("%d",&a[i]);
        }
    }
    sort(x.begin(),x.end());
    auto tt=unique(x.begin(),x.end());
    x.resize(distance(x.begin(),tt));
    for(i=0;i<x.size();i++)
        mx[x[i]]=i+1;
    sort(y.begin(),y.end());
    tt=unique(y.begin(),y.end());
    y.resize(distance(y.begin(),tt));
    for(i=0;i<y.size();i++)
        my[y[i]]=i+1;
    for(i=1;i<=T;i++)
    {
        if(ch[i][0]=='D')
        {
            a[i]=mx[a[i]];b[i]=my[b[i]];//,
            mp[MP(a[i],b[i])]=no[i];
        }
    }
    for(i=1;i<=T;i++)
    {
//        system("pause");
        if(ch[i][0]=='D')
        {
            toAdd=b[i];val=a[i];
            add(1,1,n);
            lst[b[i]].insert(MP(a[i],no[i]));
        }
        else
        {
            k=on[a[i]];
//            printf("%d %d\n",a[k],b[k]);
            it=lst[b[k]].lower_bound(MP(a[k]+1,0));
            if(it!=lst[b[k]].end())
                printf("%d\n",(*it).Y);
            else
            {
                j=Find(1,1,n);
                it=lst[j].lower_bound(MP(a[k],0));
                if(it!=lst[j].end())
                    printf("%d\n",(*it).Y);
                else
                    printf("NE\n");
            }
        }
    }
}
