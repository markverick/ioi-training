#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[500135],n,L[500135],R[500135],hsh[500135];
pair<int,int> ft[500135],res[500135];
pair<int,int> Max(int idx)
{
    int mc=0,x=0;
    while(idx>0)
    {
        if(mc<ft[idx].X)
        {
            mc=ft[idx].X;
            x=ft[idx].Y;
        }
        idx-=idx&-idx;
    }
    return MP(mc,x);
}
void append(int idx,int val,int mc)
{
    while(idx<=n)
    {
        if(ft[idx].X<mc)
        {
            ft[idx].X=mc;
            ft[idx].Y=val;
        }
        idx+=idx&-idx;
    }
}
vector<int> V;
int main()
{
	int i,j,k,mc=-1,x=0,u,v,m;
	scanf("%d %d",&n,&m);
	R[0]=1;
	for(i=1;i<=n;i++)
    {
        L[i]=i-1;
        a[i]=i;
        R[i]=i+1;
    }
    L[n+1]=n;
    char ch[3];
    while(m--)
    {
        scanf("%s %d %d",ch,&u,&v);
        if(ch[0]=='A')
        {
            L[R[u]]=L[u];
            R[L[u]]=R[u];
            L[u]=L[v];
            R[u]=v;
            R[L[v]]=u;
            L[v]=u;
        }
        else
        {
            L[R[u]]=L[u];
            R[L[u]]=R[u];
            L[u]=v;
            R[u]=R[v];
            L[R[v]]=u;
            R[v]=u;
        }
    }
    k=0;
    i=0;
    while(k!=n+1)
    {
        a[i++]=k;
        k=R[k];
    }
	for(i=1;i<=n;i++)
    {
//        printf("%d ",a[i]);
        res[i]=Max(a[i]-1);///res[i]=Max(a[i]) //if "Non Decreasing!"
        append(a[i],i,res[i].X+1);
        if(mc<res[i].X)
            mc=res[i].X,x=i;
    }
//    printf("\n");
    stack<int> st;
    while(x)
    {
        st.emplace(a[x]);
        hsh[x]=1;
        x=res[x].Y;
    }
    while(!st.empty())
        V.emplace_back(st.top()),st.pop();
//    printf("%d\n",V.size());
//    for(i=V.size()-1;i>=0;i--)
//        printf("%d ",V[i]);

    printf("%d\n",n-V.size());
    vector<int> out;
    for(i=1;i<=n;i++)
    {
        if(!hsh[i])
            out.emplace_back(a[i]);
    }
    sort(out.begin(),out.end());
    for(i=0;i<out.size();i++)
    {
        k=lower_bound(V.begin(),V.end(),out[i])-V.begin();
        if(k<V.size())
        {
            printf("A %d %d\n",out[i],V[k]);
        }
        else
        {
            break;
        }
    }
    for(i=out.size()-1;i>0;i--)
    {
        k=lower_bound(V.begin(),V.end(),out[i])-V.begin();
        if(k<V.size())
        {
            break;
        }
        else
        {
            printf("B %d %d\n",out[i],V[V.size()-1]);
        }
    }
}
