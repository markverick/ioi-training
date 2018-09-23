#include<bits/stdc++.h>
using namespace std;
int ar[100135];
int qs[100135],out[100135];
int hsh[1230135];
int n,m;
vector<tuple<int,int,int,int> > q;
int main()
{
    int i,j,k,o,sz,fst,lst,R,L,id,cot,a,b,sum;
    scanf("%d %d %d",&n,&m,&o);
    sz=ceil(sqrt(n))+0.000001;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        q.emplace_back(a/sz,b,a,i);
    }
    sort(q.begin(),q.end());
    fst=0;lst=0;
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
        sum=0;
        for(j=0;j<=1000000;j++)
        {
            sum+=hsh[j]*hsh[o^j];
        }
        out[id]=sum;
    }
    for(i=1;i<=m;i++)
    {
        printf("%d\n",out[id]);
    }
}
