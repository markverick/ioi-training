#include<bits/stdc++.h>
using namespace std;
vector<int> seg[42000];
int val,x,y;
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(lst<x||fst>y)
    {
        return;
    }
}
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    char ch[2];
    for(i=0;i<m;i++)
    {
        scanf("%s",ch);
        if(ch=='+')
        {
            scanf("%d %d %d",&val,&x,&y);
            add(1,1,n);
        }
        if(ch=='')
        {
            scanf("%d %d %d",&val,&x,&y);
            sub(1,1,n);
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",seg[1][i]);
    }
}
