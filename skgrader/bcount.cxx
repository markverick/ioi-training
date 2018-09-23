#include<bits/stdc++.h>
using namespace std;
int qs[100135],qt[100135];
int main()
{
    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);
    int n,q,i,j,k,a,b;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a==1)
            qs[i]=qs[i-1]+1,qt[i]=qt[i-1]+1;
        else if(a==2)
            qs[i]=qs[i-1],qt[i]=qt[i-1]+1;
        else
            qs[i]=qs[i-1],qt[i]=qt[i-1];

    }
    for(i=1;i<=q;i++)
    {
        scanf("%d %d",&a,&b);
//        printf("%d\n",qs[6]-qs[0]);
        printf("%d %d %d\n",qs[b]-qs[a-1],qt[b]-qt[a-1]-qs[b]+qs[a-1],b-a+1-qt[b]+qt[a-1]);
    }
}
