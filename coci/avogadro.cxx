#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[5][100135],hsh[5][100135],del[100135],ndel[100135];
vector<int> pos[5][100135];
vector<int> v;
vector<int> ::iterator it;
queue<int> q;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,l,p,n;
	scanf("%d",&n);
	for(i=1;i<=3;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]),pos[i][a[i][j]].emplace_back(j),hsh[i][a[i][j]]++;
    }
    for(i=1;i<=n;i++)
    {
        k=0;
        for(j=1;j<=3;j++)
        {
            if(!pos[j][i].empty())
                k++;
        }
        if(k>0&&k<3)
        {
            q.emplace(i);
//            printf("!%d\n",i);
            ndel[i]=1;
        }
    }
    while(!q.empty())
    {
        k=q.front();
        q.pop();
        ndel[k]=1;
//        printf("%d\n",k);
        for(i=1;i<=3;i++)
        {
            for(j=0;j<pos[i][k].size();j++)
            {
                p=pos[i][k][j];
//                printf("-> %d\n",p);
                if(del[p])
                    continue;
                del[p]=1;
                for(l=1;l<=3;l++)
                {
                    hsh[l][a[l][p]]--;
                    if(hsh[l][a[l][p]]==0)
                    {
                        if(ndel[a[l][p]]==0)
                        {
//                            printf(">INSERT %d\n",a[l][p]);
                            ndel[a[l][p]]=1;
                            q.emplace(a[l][p]);
                        }
                    }
                }
            }
        }
        ndel[k]=1;
    }
    int cot=0;
    for(i=1;i<=n;i++)
    {
        if(ndel[i])
            cot++;
//            printf("%d\n",i);
    }
    printf("%d",cot);
}
