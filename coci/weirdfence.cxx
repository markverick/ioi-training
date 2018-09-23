#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char ch[1135];
int A,B,mat[235][235],ste[235],res[235],fk=0;
pair<int,int> x[135],y[135];
inline int p2(int x)
{
    return x*x;
}
void dfs(int idx,int C)
{
    ste[idx]=1;
    int i;
    if(idx==A+B+1)
    {
        for(i=1;i<C;i++)
        {
            mat[res[i-1]][res[i]]=0;
            mat[res[i]][res[i-1]]=1;
        }
        fk=1;
        return;
    }
    for(i=0;i<=A+B+1;i++)
    {
        if(i==idx||ste[i]||mat[idx][i]==0)
            continue;
        res[C]=i;
        dfs(i,C+1);
        if(fk)return;
    }
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,T,n,m,fs,md,ls,cot,mn,a,b;
	scanf("%d",&T);
	while(T--)
    {
        A=0;B=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %s",&a,&b,ch);
            if(ch[0]=='b')
                x[++A]=MP(a,b);
            else
                y[++B]=MP(a,b);
        }
        fs=0;ls=3000;mn=3000;
        while(fs<=ls)
        {
            md=(fs+ls)/2;
            memset(mat,0,sizeof mat);
            for(i=1;i<=A;i++)
            {
                for(j=1;j<=B;j++)
                {
                    if(p2(abs(x[i].X-y[j].X))+p2(abs(x[i].Y-y[j].Y))<=md*md)
                        mat[i][A+j]=1;
                }
            }
            for(i=1;i<=A;i++)
                mat[0][i]=1;
            for(i=1;i<=B;i++)
                mat[A+i][A+B+1]=1;
            fk=1;
            while(fk)
            {
                fk=0;
                memset(ste,0,sizeof ste);
                dfs(0,1);
            }
            cot=0;
            for(i=1;i<=B;i++)
            {
                if(mat[A+B+1][A+i])
                    cot++;
            }
            if(cot>=m)
            {
                mn=min(mn,md);
                ls=md-1;
            }
            else
                fs=md+1;
        }
        if(mn==3000)
            printf("Impossible\n");
        else
            printf("%d\n",mn);
    }
}
