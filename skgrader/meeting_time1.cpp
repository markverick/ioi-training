#include<bits/stdc++.h>
using namespace std;
int u[130],v[130],s[130],t[130];
vector<pair<int,int> > ajs[18];
vector<pair<int,int> > ajt[18];
//vertex,weight
char jums[20000];
char jumt[20000];
int n,m;
char chks[18];
char chkt[18];
void ds(int idx,int time)
{
    if(idx==n)
    {
        jums[time]=1;
        return;
    }
    //if(chks[idx]==1)
      //  return;
    //int mn=999999999;
    int i;
    for(i=0;i<ajs[idx].size();i++)
    {
        if(chks[ajs[idx][i].first]==1)
            continue;
        chks[ajs[idx][i].first]=1;
        ds(ajs[idx][i].first,time+ajs[idx][i].second);
        chks[ajs[idx][i].first]=0;
    }
}
void dt(int idx,int time)
{

    if(idx==n)
    {
        jumt[time]=1;
        return;
    }
    //if(chkt[idx]==1)
      //  return;
    //int mn=999999999;
    int i;
    for(i=0;i<ajt[idx].size();i++)
    {
        if(chkt[ajt[idx][i].first]==1)
            continue;
        chkt[ajt[idx][i].first]=1;
        dt(ajt[idx][i].first,time+ajt[idx][i].second);
        chkt[ajt[idx][i].first]=0;
    }
}
int main()
{

    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d %d",&u[i],&v[i],&s[i],&t[i]);
        ajs[u[i]].push_back(make_pair(v[i],s[i]));
        ajt[u[i]].push_back(make_pair(v[i],t[i]));
    }
    ds(1,0);
    dt(1,0);
    for(i=0;i<=18000;i++)
    {
        if(jums[i]==1&&jumt[i]==1)
        {
            printf("%d",i);
            exit(0);
        }
    }
    printf("IMPOSSIBLE");

}
