#include<bits/stdc++.h>
using namespace std;
char str[100135];
int ft[30][100135];
void add(int al,int idx,int val)
{
    while(idx<=100000)
    {
        ft[al][idx]+=val;
        idx+=idx&-idx;
    }
}
int sum(int al,int idx)
{
    int sm=0;
    while(idx>0)
    {
        sm+=ft[al][idx];
        idx-=idx&-idx;
    }
    return sm;
}
int main()
{
    int n,q,i,j,k,l,ch,a,b,odd;
    char x[3];
    scanf("%d %d %s",&n,&q,str+1);
    for(i=1;i<=n;i++)
    {
        add(str[i]-'a',i,1);
    }
    for(j=1;j<=q;j++)
    {
        scanf("%d",&ch);
        if(ch==1)
        {
            scanf("%d %s",&l,x);
            for(i=0;i<26;i++)
            {
                if(sum(i,l)-sum(i,l-1)==1)
                    add(i,l,-1);
            }
            add(x[0]-'a',l,1);
        }
        else
        {
            scanf("%d %d",&a,&b);
            odd=0;
            for(i=0;i<26;i++)
            {
                if( (sum(i,b)-sum(i,a-1) )%2==1)
                    odd++;
            }
            //printf("%d\n",odd);
            if(odd>1)
                printf("no\n");
            else
                printf("yes\n");
        }
    }
}
