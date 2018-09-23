#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int x[300135],y[300135],f[300135],tema[300135],out[300135];
pair<int,int> row[300135],col[300135];
tuple<int,int,int,int> p[300135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,cost,id,a,b,c;
	scanf("%d %d",&n,&cost);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&x[i],&y[i],&f[i]);
        p[i]=MT(x[i],y[i],f[i],i);
    }
    row[x[1]]=MP(f[1],1);
    col[y[1]]=MP(f[1],1);
    sort(&p[1],&p[n+1]);
    pair<int,int> pr,pc;
    for(i=1;i<=n;i++)
    {
        tie(a,b,c,id)=p[i];
        if(a<x[1]||b<y[1]||MP(x[1],y[1])==MP(a,b))
            continue;
        pr=MP(-1,-1);pc=MP(-1,-1);
        if(row[a].X>=cost)
            pr=row[a];
        if(col[b].X>=cost)
            pc=col[b];
        if(pc.X>pr.X)
            pr=pc;
        if(pr.X>=0)
        {
            tema[id]=pr.Y;
            k=pr.X-cost+c;
            if(k>row[a].X)
                row[a]=MP(k,id);
            if(k>col[b].X)
                col[b]=MP(k,id);
            out[id]=k;
        }
        else
            out[id]=-1;
    }
    stack<int> st;
    printf("%d\n",out[n]);
    i=n;
    while(i>0)
    {
        st.emplace(i);
        i=tema[i];
    }
    printf("%d\n",st.size());
    while(!st.empty())
    {
        k=st.top();
        printf("%d %d\n",x[k],y[k]);
        st.pop();
    }
}
