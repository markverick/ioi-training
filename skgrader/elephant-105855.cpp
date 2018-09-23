#include<bits/stdc++.h>
int maps[120000];
int highest=0;
int n;
void omelet(int score,int idx)
{
    if(idx>=n)
    {
        //printf("%d\n",score);
        if(score>highest)
        {
            highest=score;
        }
        return;
    }
    else
    {
        omelet(score+maps[idx+2],idx+3);
        omelet(score,idx+1);
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&maps[i]);
    }
    omelet(0,0);
    printf("%d",highest);
}
