#include<bits/stdc++.h>
using namespace std;
char str[25],len;
int ft[200135];
void add(int idx,int val)
{
    while(idx<=200135)
    {
        ft[idx]+=val;
        idx+=idx&-idx;
    }
}
int sum(int idx)
{
    int sm=0;
    while(idx>0)
    {
        sm+=ft[idx];
        idx-=idx&-idx;
    }
    return sm;
}
int main()
{
    int n,q,i,j,k;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%s",str);
        len=strlen(str);
        if(str[0]!='-')
        {
            if(str[0]==str[len-1])
                add(i,1);
        }
    }
    int ch,a,b;
    for(i=1;i<=q;i++)
    {
        scanf("%d",&ch);
        if(ch==1)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",sum(b)-sum(a-1));
        }
        else
        {
            scanf("%d %s",&a,str);
            add(a,-sum(a)+sum(a-1));
            len=strlen(str);
            if(str[0]!='-')
            {
                if(str[0]==str[len-1])
                    add(a,1);
            }
        }
    }
}
