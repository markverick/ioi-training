#include<bits/stdc++.h>
int x[2000],n;
int highest=0;
void fx(int idx,int num,int length) //return the max of it
{
    if(idx>=n)
    {
        if(num>highest)
            highest=num;
        return;
    }
    if(x[idx]>length)
    {
        fx(idx+1,num+1,x[idx]);
    }
        fx(idx+1,num,length);
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    fx(0,0,0);
    printf("%d",highest);

}
