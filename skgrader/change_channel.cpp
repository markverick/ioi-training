#include<bits/stdc++.h>
int change[200000];
int main()
{
    int n,a,b,c,i,j;
    int m;
    int chck=0;
    int cot=0;
    int time=0;
    int start;
    scanf("%d %d %d",&n,&m,&start);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        if(change[b]==0)
        {
            time++;
            change[b]=a;
        }

    }
    //printf("%d",time);
    c=start;
    i=0;
    while(true)
    {
        if(change[c]==0||c==0)break;
        c = change[c];
        cot++;
        //printf("%d %d\n",c,change[c]);
        if(i>time)
        {
            chck=1;
            break;
        }
        i++;
        //printf("hello");
    }
    if(chck==0)
    printf("%d",cot);
    else
        printf("%d",-1);
}
