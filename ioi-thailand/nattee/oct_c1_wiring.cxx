#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135],b[100135],ha[100135],pos[100135],ste[100135],fk=0,C=1;
void dfs(int idx)
{
    if(a[idx]==0)
        return;
    ste[idx]=C;
    if(pos[a[idx]]==idx)
        return;
    if(ste[pos[a[idx]]])
    {
        if(ste[pos[a[idx]]]==C)
            fk=1;
        return;
    }
    dfs(pos[a[idx]]);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,T;
	scanf("%d",&T);
	while(T--)
    {
        memset(ha,0,sizeof ha);
        memset(ste,0,sizeof ste);
        scanf("%d",&n);
        fk=0;C=1;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]),pos[b[i]]=i;
        for(i=1;i<=n;i++)
        {
            if(!ste[i])
                dfs(i);
            C++;
        }
        if(fk)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
