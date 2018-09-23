#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int,int> > q;
int hsh[500005],ar[500005];
int n,m,R,L,id,out[500005];
vector<int> v;
unordered_map<int,int> mp;
int main()
{
    int i,j,k,a,b,sz,fu=0,fst,lst,cot=0;
    scanf("%d",&n);
    sz=sqrt(n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
        v.emplace_back(ar[i]);
    }
    sort(v.begin(),v.end());
    auto it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    for(i=0;i<v.size();i++)
    {
        mp[v[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
        ar[i]=mp[ar[i]];
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        a++;b++;
        q.emplace_back(a/sz,b,a,i);
    }
    sort(q.begin(),q.end());
    fst=1;lst=1;
    hsh[ar[fst]]=1;
    for(i=0;i<q.size();i++)
    {
        tie(a,R,L,id)=q[i];
        while(lst<R)
        {
            lst++;
            hsh[ar[lst]]++;
        }
        while(lst>R)
        {
            hsh[ar[lst]]--;
            lst--;
        }
        while(fst<L)
        {
            hsh[ar[fst]]--;
            fst++;
        }
        while(fst>L)
        {
            fst--;
            hsh[ar[fst]]++;
        }
        cot=0;
//        printf("%d -> %d\n",L,R);
        for(j=0;j<v.size();j++)
        {
//            printf("[%d] = %d\n",v[j],hsh[j]);
            if(hsh[j]>1)
            {
                cot+=hsh[j]-1;
            }
        }
        out[id]=cot;
    }
    for(i=1;i<=m;i++)
    {
        printf("%d\n",out[i]);
    }
}
