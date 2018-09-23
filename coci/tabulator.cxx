#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[1135],sum=0;
vector<int> v;
void dfs(int fst,int lst)
{
    if(fst>lst)
        return;
    if(fst==lst)
    {
        sum+=v[fst];
        return;
    }
    int i,j,k,mn=MI;
//    printf("%d %d\n",fst,lst);
//    for(i=fst;i<=lst;i++)
//    {
//        printf("%d ",v[i]);
//    }
//    printf("\n");
    j=fst;
    for(i=fst;i<=lst+1;i++)
    {
        if((v[i]==0||i==lst+1))
        {
            if(mn==MI)
            {
                j=i+1;
                continue;
            }
//            printf("%d <-> %d\n",j,i-1);
            for(k=j;k<i;k++)
            {
                v[k]-=mn;
            }
            sum+=mn;
            dfs(j,i-1);
            j=i+1;
            mn=MI;
        }
        else
        {
            mn=min(mn,v[i]);
        }
    }
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&j),a[i]-=j;
    for(i=1;i<=n;i++)
    {
        if(a[i]>0)
            v.emplace_back(a[i]);
        else
            v.emplace_back(0);
    }
    dfs(0,v.size()-1);
//    printf("%d\n",sum);
    v.clear();
    for(i=1;i<=n;i++)
    {
        if(a[i]<0)
            v.emplace_back(-a[i]);
        else
            v.emplace_back(0);
    }
    dfs(0,v.size()-1);
    printf("%d",sum);
}
