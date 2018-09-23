#include<bits/stdc++.h>
using namespace std;
int t[100135];
int tr[100135];
int n;
int las[100135];
int lds[100135];

vector<int> x;
vector<int>::iterator it;
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
    }
    for(i=0;i<n;i++)
    {
        tr[i]=t[n-i-1];
    }
    for(i=0;i<n;i++)
    {
        it=lower_bound(x.begin(),x.end(),t[i]);
        if(it==x.end())
        {
            x.emplace_back(t[i]);
            las[i]=x.size();
            //printf("%d\n",t[i]);
        }
        else
        {
            x[it-x.begin()]=t[i];
            las[i]=it-x.begin()+1;
        }
        //printf("%d %d\n",las[i],t[i]);
    }
    x.clear();
    for(i=0;i<n;i++)
    {
        it=lower_bound(x.begin(),x.end(),tr[i]);
        if(it==x.end())
        {
            x.emplace_back(tr[i]);
            lds[n-i-1]=x.size();
            //printf("%d\n",t[i]);
        }
        else
        {
            x[it-x.begin()]=tr[i];
            lds[n-i-1]=it-x.begin()+1;
        }
        //printf("%d %d\n",las[i],t[i]);
    }
    /*for(i=0;i<n;i++)
    {
        printf("%d ",las[i]);
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
       printf("%d ",lds[i]);
    }*/
    int mc=0;
    for(i=0;i<n;i++)
    {
        //if(t[i]!=t[i+1])
            mc=max(mc,las[i]+lds[i]-1);
    }
    //mc=max(mc,las[n-1]);
    //mc=max(mc,lds[0]);
    printf("%d",mc);

}
