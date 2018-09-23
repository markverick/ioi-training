#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int,int> > q;
int hsh[10135],ar[300135];
int n,m,c,R,L,id,out[10135];
int main()
{
    int i,j,k,a,b,sz,fu=0,fst,lst;
    scanf("%d %d",&n,&c);
    sz=ceil(sqrt(n))+0.000001;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
    }
    scanf("%d",&m);
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
        for(j=1;j<=c;j++)
        {
            if(hsh[j]>(lst-fst+1)/2)
            {
                out[id]=j;
                break;
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        if(out[i]==0)
            printf("no\n");
        else
        {
            printf("yes %d\n",out[i]);
        }
    }
}
