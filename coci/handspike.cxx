#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> x,y,z,A,B;
vector<vector<int> > g;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a;
	scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a%3==0)
            x.emplace_back(a);
        else if(a%3==1)
            y.emplace_back(a);
        else
            z.emplace_back(a);
    }
//    printf("%d %d %d\n",x.size(),y.size(),z.size());
    if(x.empty())
    {
        if(!y.empty()&&!z.empty())
            printf("impossible");
        else
        {
            for(i=0;i<y.size();i++)
                printf("%d ",y[i]);
            for(i=0;i<z.size();i++)
                printf("%d ",z[i]);
        }
        return 0;
    }
    if(x.size()>=2+y.size()+z.size())
    {
        printf("impossible");
        return 0;
    }
    vector<int> emp;
    emp.emplace_back(0);
    if(y.size()>=x.size())
    {
        for(i=0;i<x.size();i++)
        {
            emp[0]=y[i];
            g.emplace_back(emp);
        }
        for(i=x.size();i<y.size();i++)
            g[0].emplace_back(y[i]);
        emp.clear();
        for(i=0;i<z.size();i++)
            emp.emplace_back(z[i]);
        g.emplace_back(emp);
    }
    else
    {
        for(i=0;i<y.size();i++)
        {
            emp[0]=y[i];
            g.emplace_back(emp);
        }
        for(i=y.size(),j=0;i<x.size();j++,i++)
        {
            emp[0]=z[j];
            g.emplace_back(emp);
        }
        emp.clear();
        for(i=j;i<z.size();i++)
        {
            emp.emplace_back(z[i]);
        }
        g.emplace_back(emp);
    }
    if(x.size()<=y.size()+z.size())
    {
        for(i=0;i<x.size();i++)
        {
            for(j=0;j<g[i].size();j++)
            {
                printf("%d ",g[i][j]);
            }
            printf("%d ",x[i]);
        }
        for(j=0;j<g[g.size()-1].size();j++)
            printf("%d ",g[g.size()-1][j]);
    }
    else
    {
        printf("%d ",x[0]);
        for(i=1;i<x.size();i++)
        {
            for(j=0;j<g[i-1].size();j++)
                printf("%d ",g[i-1][j]);
            printf("%d ",x[i]);
        }
    }
}
