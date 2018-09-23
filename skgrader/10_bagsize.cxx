#include<bits/stdc++.h>
using namespace std;
int x[1135];
int main()
{
    int ans=0,hi=0,n,a,b,i,j,k,c,num,sum=0,mn=1000000000;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d %d %d",&n,&a,&b);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
        sum+=x[i];
        hi=max(hi,x[i]);
    }
    for(i=max(hi,a);i<=b;i++)
    {
        c=i;num=1;
        for(j=1;j<=n;j++)
        {
            if(c-x[j]<0)
            {
                c=i;num++;
            }
            c-=x[j];
        }
        //printf("%d %d %d\n",num,sum,num*i-sum);
        if(mn>num*i-sum)
        {
            mn=num*i-sum;
            ans=i;
        }
    }
    printf("%d",ans);

}
