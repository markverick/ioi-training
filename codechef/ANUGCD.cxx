#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135],hsh[100135],pnai[100135],st,ed;
vector<int> pos[10135],primes;
vector<pair<int,int> > seg[10135];
void build(int idx,int fst,int lst,int t)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[t][idx]={a[pos[t][fst]],1};
        return;
    }
    build(idx*2,fst,mid,t);
    build(idx*2+1,mid+1,lst,t);
    pair<int,int> x=seg[t][idx*2],y=seg[t][idx*2+1];
    if(x.X==y.X)
        seg[t][idx]=MP(x.X,x.Y+y.Y);
    else if(x.X>y.X)
        seg[t][idx]=x;
    else
        seg[t][idx]=y;
}
pair<int,int> Max(int idx,int fst,int lst,int t)
{
    int mid=(fst+lst)/2;
    if(lst<st||fst>ed)
    {
        return MP(-1,-1);
    }
    if(fst>=st&&lst<=ed)
    {
        return seg[t][idx];
    }
    pair<int,int> x=Max(idx*2,fst,mid,t),y=Max(idx*2+1,mid+1,lst,t);
    if(x.X==y.X)
        return MP(x.X,x.Y+y.Y);
    else if(x.X>y.X)
        return x;
    else
        return y;
}
int main()
{
	int i,j,k,n,m,x,y,g;
	pair<int,int> p,mc;
	for(i=2;i<=100000;i++)
    {
        if(!hsh[i])
        {
            pnai[i]=primes.size();
            primes.emplace_back(i);
            for(j=i;j<=100000;j+=i)
                hsh[j]=1;
        }
    }
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        k=a[i];
        for(j=0;j<primes.size();j++)
        {
            if(primes[j]>sqrt(k)+1)
                break;
            if(k%primes[j]==0)
            {
                pos[j].emplace_back(i);
                while(k%primes[j]==0)
                    k/=primes[j];
            }
        }
        if(k>1)
            pos[pnai[k]].emplace_back(i);
    }
    for(i=0;i<primes.size();i++)
        sort(pos[i].begin(),pos[i].end());
    for(i=0;i<primes.size();i++)
    {
        if(!pos[i].empty())
        {
            seg[i].resize(pos[i].size()*4);
            build(1,0,pos[i].size()-1,i);
        }
//        if(pos[i].empty())continue;
//        printf("PRIME: %d\n",primes[i]);
//        for(j=0;j<pos[primes[i]].size();j++)
//            printf("%d ",pos[primes[i]][j]);
//        printf("\n");
    }
    int fk=0;
    while(m--)
    {
        scanf("%d %d %d",&g,&x,&y);
        k=g;mc=MP(-1,-1);fk=0;
        for(i=0;i<primes.size();i++)
        {
            if(primes[i]>sqrt(k)+1)
                fk=1;
            if(fk==1)
            {
                if(k>1)
                {
                    i=pnai[k];
                }
            }
            if(k%primes[i]==0)
            {
                if(!pos[i].empty())
                {
                    st=lower_bound(pos[i].begin(),pos[i].end(),x)-pos[i].begin();
                    ed=upper_bound(pos[i].begin(),pos[i].end(),y)-pos[i].begin()-1;
                    if(st<=ed)
                    {
                        p=Max(1,0,pos[i].size()-1,i);
                        if(p.X>mc.X)
                            mc=p;

                    }
                }
                while(k%primes[i]==0)
                    k/=primes[i];
            }
            if(fk)
                break;
        }
        printf("%d %d\n",mc.X,mc.Y);
    }
}
