#include<bits/stdc++.h>
int c=0;
int hsh[120];
int gen(int idx)
{
    int i;
    if(hsh[idx]>-1)
    {
        return hsh[idx];
    }
    if(idx==1)
    {
        //c++;
        return 1;
    }
    else if(idx==2)
    {
        //c++
        return 2;
    }
    else if(idx<=0)
    {
        return 0;
    }
    else
    {
        return hsh[idx]=gen(idx-1)+(idx-2);
    }
    //printf("%d ",idx);
}

int main()
{
    int n;
    int i,j,k;
    int input;
    scanf("%d",&n);
    for(i=0;i<150;i++)
    {
        hsh[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&input);
        if(input!=0){
        printf("%d\n",gen(input));
        }
        else{
            printf("1\n");
        }
    }
}
