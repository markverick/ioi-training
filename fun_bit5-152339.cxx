#include<bits/stdc++.h>
using namespace std;
char str[400135];
int x,y,val,toAdd;
int seg[400135];
int po2[400135];
void update(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]=1;
        return;
    }
    if(toAdd<=mid)
    {
        update(idx*2,fst,mid);
    }
    else
    {
        update(idx*2+1,mid+1,lst);
    }
    seg[idx]=( seg[idx*2]*(po2[lst-mid] ) )%3+seg[idx*2+1];
    seg[idx]%=3;
    return;
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(lst<x||fst>y)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return seg[idx];
    }
    return ( (sum(idx*2,fst,mid)*(po2[max(min(y,lst)-mid,0)]) )%3+sum(idx*2+1,mid+1,lst) )%3;
}
int main()
{
    int len,q,ch,i;
    scanf("%d %s",&len,str+1);
    po2[0]=1;po2[1]=2;
    for(i=2;i<=100135;i++)
    {
        po2[i]=po2[i-1]*2;
        po2[i]%=3;
    }
//    for(i=0;i<len;i++)
//        str[i]-='0';
    for(i=1;i<=len;i++)
    {
        if(str[i]=='1')
        {
            toAdd=i;val=1;
            update(1,1,len);
        }
    }
    /*
    for(i=1;i<=len;i++)
    {
        x=i;y=i;
        printf("=%d\n",sum(1,1,len));
    }*/
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d",&ch);
        if(ch==0)
        {
            scanf("%d %d",&x,&y);
            x++;y++;
            printf("%d\n",(sum(1,1,len))%3 );
        }
        else
        {
            scanf("%d",&toAdd);
            toAdd++;
            val=1;
            update(1,1,len);
        }
    }
}
