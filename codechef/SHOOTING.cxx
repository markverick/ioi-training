#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#define X first
#define Y second
#define MP make_pair
using namespace std;
char maps[52][52];
vector<pair<int,int> > p;
pair<int,int> pi;
int res[18],L,hsh[52],n,m,FK,a,y,x;
void gen(int idx)
{
    if(idx==L)
    {
        int i,j,fk=0;
        memset(hsh,0,sizeof hsh);
        for(i=0;i<L;i++)
        {
            if(res[i]==0)
            {
                hsh[p[i].X]++;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(hsh[i]==0)
            {
                for(j=1;j<=m;j++)
                {
                    if(maps[i][j]=='E')
                    {
                        fk=1;
                        break;
                    }
                }
            }
            else if(hsh[i]==1)
            {
                a=0;
                for(j=1;j<=m;j++)
                {
                    if(maps[i][j]=='L')
                        break;
                    if(maps[i][j]=='E')
                        a=1;
                }
                if(a==1)for(j=j;j<=m;j++)
                {
                    if(maps[i][j]=='E')
                        a=2;
                }
                if(a==2)
                    fk=1;
            }
            if(fk)break;
        }
        if(!fk)
            FK=1;
        return;
    }
    int i;
    res[idx]=0;
    gen(idx+1);
    if(FK==1)
        return;
    res[idx]=1;
    stack<pair<int,int> > st;
    for(i=p[idx].X;i>=1;i--)
    {
        if(maps[i][p[idx].Y]=='E')
        {
            maps[i][p[idx].Y]='D';
            st.emplace(i,p[idx].Y);
        }
    }
    maps[p[idx].X][p[idx].Y]='F';
    gen(idx+1);
    while(!st.empty())
    {
        pi=st.top();st.pop();
        maps[pi.X][pi.Y]=maps[pi.X][pi.Y]='E';
    }
    maps[p[idx].X][p[idx].Y]='L';

}
int main()
{
    int i,j,k,all,sum,T;
    scanf("%d",&T);
    while(T--)
    {
        p.clear();
        all=0;sum=0;FK=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%s",maps[i]+1);
            for(j=1;j<=m;j++)
            {
                if(maps[i][j]=='L')
                    p.emplace_back(i,j);
            }
        }
        L=p.size();
        gen(0);
        if(FK==0)
            printf("Impossible\n");
        else
            printf("Possible\n");
    }
}
